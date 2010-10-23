// WindowSkinner.cpp : Implementation of CWindowSkinner

#include "stdafx.h"
#include "WickedWidgets.h"
#include "WindowSkinner.h"

/////////////////////////////////////////////////////////////////////////////
// CWindowSkinner

CWindowSkinner* CWindowSkinner::m_pThis = NULL;

STDMETHODIMP CWindowSkinner::get_TransparentColor(OLE_COLOR *pVal)
{
    *pVal = m_clrBorderColor;

	return S_OK;
}

STDMETHODIMP CWindowSkinner::put_TransparentColor(OLE_COLOR newVal)
{
	m_clrBorderColor = newVal;

	return S_OK;
}

STDMETHODIMP CWindowSkinner::putref_Picture(IPictureDisp* newVal)
{
    if(FireOnRequestEdit(DISPID_BACKPICTURE) == S_FALSE)
        return S_FALSE;
    
    m_pictureDisp = newVal;
    m_picture = NULL;

    if (m_pictureDisp != NULL)
        m_pictureDisp->QueryInterface(IID_IPicture,(void**)&m_picture);

	m_bRequiresSave = TRUE;
    FireOnChanged(DISPID_BPICTURE);
    SendOnDataChange(NULL);
    
    LoadPicture();

	return S_OK;
}

STDMETHODIMP CWindowSkinner::get_Picture(IPictureDisp **pVal)
{
	m_pictureDisp.CopyTo(pVal);

	return S_OK;
}

STDMETHODIMP CWindowSkinner::put_Picture(IPictureDisp *newVal)
{
    if(FireOnRequestEdit(DISPID_BPICTURE) == S_FALSE)
        return S_FALSE;
    
    m_pictureDisp = NULL;
    m_picture = NULL;

    CComPtr<IPictureDisp> pPicture = newVal;

    if(pPicture)
    { 
        CComQIPtr<IPersistStream, &IID_IPersistStream>p(pPicture);
        
        if (p)
        { 
            ULARGE_INTEGER l;
            p->GetSizeMax(&l);
            HGLOBAL hGlob = GlobalAlloc(GHND, l.LowPart);
            if (hGlob)
            { 
                CComPtr<IStream> spStream;
                CreateStreamOnHGlobal(hGlob, TRUE, &spStream);
                
                if (spStream)
                { 
                    if (SUCCEEDED(p->Save(spStream, FALSE)))
                    {
                        LARGE_INTEGER l;
                        l.QuadPart = 0;
                        spStream->Seek(l, STREAM_SEEK_SET, NULL);
                        OleLoadPicture(spStream, l.LowPart, FALSE,IID_IPictureDisp, (void**)&m_pictureDisp.p);
                        m_pictureDisp->QueryInterface(IID_IPicture,(void**)&m_picture);
                    }
                    spStream.Release();
                }
                
                GlobalFree(hGlob);
            }
        }
    }
    
    m_bRequiresSave = TRUE;
    FireOnChanged(DISPID_BPICTURE);
    SendOnDataChange(NULL);
    
    LoadPicture();

	return S_OK;
}

STDMETHODIMP CWindowSkinner::InfoForResize(long nHorLineTop, long nHorLineBottom, long nVerLineLeft, long nVerLineRight)
{
	if (m_hdc == NULL)
    {
        _ASSERT(FALSE);
        return S_OK;
    }
    
    
    m_resizeInfo.rcResizeLinesPos.top = nHorLineTop;
    m_resizeInfo.rcResizeLinesPos.bottom = nHorLineBottom;
    m_resizeInfo.rcResizeLinesPos.left = nVerLineLeft;
    m_resizeInfo.rcResizeLinesPos.right = nVerLineRight;

    CreatePanelRegions();

	return S_OK;
}

void CWindowSkinner::LoadPicture()
{
    try
    {
        m_nPicHeight = 0;
        m_nPicWidth = 0;
    
        // Store the original window proc
        HWND hwndAx = m_hwndParent;

        if (m_picture)
        {
            OLE_XSIZE_HIMETRIC w;
            OLE_YSIZE_HIMETRIC h;
    
            m_picture->get_Width(&w);
            m_picture->get_Height(&h);

            SIZEL szlPixels;
            SIZEL szlMetric = { w, h };
    
            AtlHiMetricToPixel(&szlMetric, &szlPixels);

            m_nPicHeight = szlPixels.cy;
            m_nPicWidth = szlPixels.cx;
        }

        if (m_hdc)
        {
            DeleteDC(m_hdc);
            m_hdc = NULL;
        }

        // Select the bitmap into a dc
        if (hwndAx && m_picture)
        {
            HDC hDC = ::GetDC(hwndAx);
	        m_hdc = CreateCompatibleDC(hDC);
         
            // Select the bitmap unto our hdc
            HDC hdcOld;
            m_picture->SelectPicture(m_hdc, &hdcOld, NULL);

            ::ReleaseDC(hwndAx, hDC);
            
            COLORREF cr = RGB(254, 0, 254);
	        OleTranslateColor(m_clrTransparent, 0, &cr);

            m_hrgnBase = HDCToRegion(m_hdc, cr, m_nPicWidth, m_nPicHeight);
            m_hrgnBaseCopy = HDCToRegion(m_hdc, cr, m_nPicWidth, m_nPicHeight);

            ResizeWindowRegionToDefault();
           // ResizeWindowRegion();

            if (::IsWindow(hwndAx))
                ::RedrawWindow(hwndAx, 0, 0, 0);
        }

        //SnapToDefaultPosition();

        //else
         //   _ASSERT(FALSE);
    }
    catch(...)
    {
    }
}

LRESULT CALLBACK CWindowSkinner::SubclassedWndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	// Get the particular instance associated with this
	// handle from the class table.
	// Don't forget it is already created
	
	LRESULT result = 0;
	BOOL bHandled = FALSE;
    
    CWindowSkinner* pThis = GetClassFromClassTable((long)hwnd);
    _ASSERT(pThis);

	switch (uMsg)
	{
	case WM_PAINT:
		{
            ::CallWindowProc(pThis->m_procOld, hwnd, uMsg, wParam, lParam);     
			pThis->OnSubclassedWindowPaint(hwnd);
            bHandled = TRUE;
		}
		break;
    case WM_ERASEBKGND:
        {
           // return 0;
        }
        break;
    case WM_LBUTTONDOWN:
        
        BOOL bUserMode;
        if (FAILED(pThis->GetAmbientUserMode(bUserMode)) || bUserMode == FALSE)
        {
            // We are in design mode
            //return;
        }
        else
        {
            
            
            POINT point, ptClient;
            ::GetCursorPos(&point);
            
            RECT rc;
            ::GetWindowRect(hwnd, &rc);

            ptClient.x = LOWORD(lParam);
            ptClient.y = HIWORD(lParam);

            if (pThis->HitTestPt(ptClient, pThis->m_resizeInfo.rcResizeGripPos))
            {
                ::SetCapture(hwnd);
                SetCursor(LoadCursor(NULL, IDC_SIZENWSE));
                pThis->m_resizeInfo.bResizingWin = true;
                pThis->m_resizeInfo.ptDragOffset.x = rc.left;
                pThis->m_resizeInfo.ptDragOffset.y = rc.top;

                pThis->m_resizeInfo.rcCursorOffset.right = rc.right - point.x; //pThis->m_nPicWidth - pThis->m_resizeInfo.rcResizeGripPos.right;
                pThis->m_resizeInfo.rcCursorOffset.bottom = rc.bottom - point.y; //pThis->m_nPicHeight - pThis->m_resizeInfo.rcResizeGripPos.bot
                pThis->m_resizeInfo.rcCursorOffset.top = point.y - rc.top; //pThis->m_nPicWidth - pThis->m_resizeInfo.rcResizeGripPos.right;tom;
                pThis->m_resizeInfo.rcCursorOffset.left = point.x - rc.left;
            }
            else if (pThis->m_resizeInfo.bAllowDragMove)
            {
                ::SetCapture(hwnd);
                pThis->m_resizeInfo.bDraggingWin = true;
                pThis->m_resizeInfo.ptDragOffset.x = point.x - rc.left;
                pThis->m_resizeInfo.ptDragOffset.y = point.y - rc.top;
            }
        }
    
        break;
    case WM_LBUTTONUP:
        if (pThis->m_resizeInfo.bDraggingWin || pThis->m_resizeInfo.bResizingWin)
        {
            ::ReleaseCapture(); // if we don't capture, we don't release
            pThis->m_resizeInfo.bDraggingWin = false;
            pThis->m_resizeInfo.bResizingWin = false;

            if (pThis->m_resizeInfo.bResizingWin)
                ::RedrawWindow(pThis->m_hwndParent, 0, 0, RDW_INVALIDATE|RDW_UPDATENOW);
        }
        break;
    case WM_SIZE:
        {  
            if (pThis->m_resizeInfo.bFirstResize) // vb resizes it once after we resize it
            {
                pThis->SnapToDefaultPosition();
            }
            else
            {
                //if (
                pThis->ResizeWindowRegion();
            }
        }
        break;
    case WM_MOUSEMOVE:
        
        POINT point;
        ::GetCursorPos(&point);

        if (pThis->m_resizeInfo.bDraggingWin)
        {
            RECT rc;
            ::GetWindowRect(hwnd, &rc);
            
            ::MoveWindow(hwnd, point.x - pThis->m_resizeInfo.ptDragOffset.x,
                         point.y - pThis->m_resizeInfo.ptDragOffset.y, 
                         rc.right - rc.left,
                         rc.bottom - rc.top, true);

        }
        else if (pThis->m_resizeInfo.bResizingWin)
        {
            int nNewWidth = ((point.x + pThis->m_resizeInfo.rcCursorOffset.right) - pThis->m_resizeInfo.ptDragOffset.x);
            int nNewHeight = ((point.y + pThis->m_resizeInfo.rcCursorOffset.bottom) - pThis->m_resizeInfo.ptDragOffset.y);
            
            if (nNewWidth < pThis->m_nPicWidth + 10)
                nNewWidth = pThis->m_nPicWidth + 10;

            if (nNewHeight < pThis->m_nPicHeight)
                nNewHeight = pThis->m_nPicHeight;

             ::MoveWindow( hwnd, pThis->m_resizeInfo.ptDragOffset.x,
                           pThis->m_resizeInfo.ptDragOffset.y,
                           nNewWidth,
                           nNewHeight,
                           true );
        }
        else
        {
            
            ::ScreenToClient(hwnd, &point);
            if (pThis->HitTestPt(point, pThis->m_resizeInfo.rcResizeGripPos))
            {
                // We are in the resize grip area. We change our pointer
                SetCursor(LoadCursor(NULL, IDC_SIZENWSE));
            }
            

        }
        break;
	}
    

    if (!bHandled && ::IsWindow(hwnd) && pThis->m_procOld != NULL) // In case one of our messages kills the window
		result = CallWindowProc(pThis->m_procOld, hwnd, uMsg, wParam, lParam);

	return result;
}

void CWindowSkinner::OnSubclassedWindowPaint(HWND hwnd)
{
    HDC hDC = ::GetDC(hwnd);
    
    if (m_hdc && hDC)
    {
        RECT rc;
        ::GetClientRect(hwnd, &rc);
        
        // Get the current width and height of entire area
        // we will draw on. This is just the client area.
        // Remember that our bitmap starts at client position
        // 0,0.

        int nCurrentWidth = rc.right - rc.left;
        int nCurrentHeight = rc.bottom - rc.top;
        
        // Create bitmap with these dimensions
        HBITMAP hbmMem = CreateCompatibleBitmap(hDC,
									            nCurrentWidth,
									            nCurrentHeight);
        
        // Create memory DC and select that bitmap
        // into it.

        HDC hdcMem = CreateCompatibleDC(hDC);		
	    SelectObject(hdcMem, hbmMem);
        SelectObject(hdcMem, m_hbrshBack);
        SetBkColor(hdcMem, RGB(0, 0, 0));

        Rectangle(hdcMem, 0, 0, nCurrentWidth, nCurrentHeight);

        // Draw the upper left rectangle unto our mem dc.
        // We draw up until the rectangle that indicates the
        // beginning of our resize rectangle. m_resizeInfo.rcResizeLinesPos.left
        // indicates the beginning
        
        int nLeftRectWidth = m_resizeInfo.rcResizeLinesPos.left ? m_resizeInfo.rcResizeLinesPos.left : m_nPicWidth;
        int nLeftRectBottom = m_resizeInfo.rcResizeLinesPos.top ? m_resizeInfo.rcResizeLinesPos.top : m_nPicHeight;
		
		// m_nDrawOffsetX and Y are just there for
		// a specialized purpose - our sliding window.
		// they don't play any other role, AFAIK

        BitBlt(hdcMem, 0, 0,
               nLeftRectWidth,
               nLeftRectBottom,
	           m_hdc, 
               m_nDrawOffsetX,
               m_nDrawOffsetY, SRCCOPY);
        
        int nBottomPanelHeight = m_nPicHeight - m_resizeInfo.rcResizeLinesPos.bottom;
        int nBottomPanelTop = nCurrentHeight - nBottomPanelHeight;
        int nRightPanelWidth = m_nPicWidth - m_resizeInfo.rcResizeLinesPos.right;
        int nRightPanelLeft = nCurrentWidth - nRightPanelWidth;
        //int nBottomStripWidth = 

        if (m_resizeInfo.rcResizeLinesPos.top != 0)
        {
         
            BitBlt(hdcMem, 0, nBottomPanelTop,
                   nLeftRectWidth, nBottomPanelHeight,
	               m_hdc, 
                   0,
                   m_resizeInfo.rcResizeLinesPos.bottom, SRCCOPY);

            BitBlt(hdcMem, nRightPanelLeft, nBottomPanelTop,
                   nRightPanelWidth,
                   nLeftRectBottom,
	               m_hdc, 
                   m_resizeInfo.rcResizeLinesPos.right,
                   m_resizeInfo.rcResizeLinesPos.bottom, SRCCOPY);
            
            
           // Copy the line strip unto our memdc. We 
            int nStripHeight = m_resizeInfo.rcResizeLinesPos.bottom - m_resizeInfo.rcResizeLinesPos.top;
           
            for (int i=m_resizeInfo.rcResizeLinesPos.top;i<nBottomPanelTop; i+=nStripHeight)
            {
                BitBlt(hdcMem, 0, i, m_resizeInfo.rcResizeLinesPos.left, 
                       nStripHeight, m_hdc, 
                       0, 
                       m_resizeInfo.rcResizeLinesPos.top, SRCCOPY);

                BitBlt(hdcMem, nRightPanelLeft, i, 
                       nRightPanelWidth, 
                       nStripHeight, m_hdc, 
                       m_resizeInfo.rcResizeLinesPos.right, 
                       m_resizeInfo.rcResizeLinesPos.top, SRCCOPY);
                
            }
        }

        // Get the width and left position of the upper right
        // strip.m_nPicWidth is the width of the bitmap selected
        // into m_hdc.
        
        if (m_resizeInfo.rcResizeLinesPos.right != 0) // else, not set
        {
         //   int nRightStripWidth = m_nPicWidth - m_resizeInfo.rcResizeLinesPos.right;
         //   int nRightStripLeft = nCurrentWidth - nRightStripWidth;
        
            // Draw the upper right bitmap, aligning it to the right
            // edge of our window.

            int ret = BitBlt(hdcMem, nRightPanelLeft, 0,
                   nRightPanelWidth,
                   nLeftRectBottom,
	               m_hdc, 
                   m_resizeInfo.rcResizeLinesPos.right,
                   0, SRCCOPY);
        
            _ASSERT(ret);
        
            int nStripWidth = m_resizeInfo.rcResizeLinesPos.right - m_resizeInfo.rcResizeLinesPos.left;
        
            if (nStripWidth != 0)
            {
                // Copy the line strip unto our memdc. We 
                for (int i=m_resizeInfo.rcResizeLinesPos.left;i<nRightPanelLeft; i+=nStripWidth)
                {
                    
                    BitBlt(hdcMem, i, 0, nStripWidth, 
                           nLeftRectBottom, m_hdc, 
                           m_resizeInfo.rcResizeLinesPos.left, 
                           0, SRCCOPY);

                    BitBlt(hdcMem, i, nBottomPanelTop,
                           nStripWidth, nBottomPanelHeight,
                           m_hdc, 
                           m_resizeInfo.rcResizeLinesPos.left, 
                           m_resizeInfo.rcResizeLinesPos.bottom, SRCCOPY);
                    
                }
            }
        }

        // Draw our entire memory dc unto our
        // window dc.
	//	HRGN rgnWin = HDCToRegion(hdcMem, RGB(254, 0, 254), nCurrentWidth, nCurrentHeight);
	//	SetWindowRgn(rgnWin);

        BitBlt(hDC, 0, 0,
               nCurrentWidth,
               nCurrentHeight,
	           hdcMem, 
               0,
               0, SRCCOPY);
        
        // debug line to get the position of the resize grip
      //  DrawIcon(hDC, m_resizeInfo.rcResizeGripPos.left, m_resizeInfo.rcResizeGripPos.top, m_hIcon);
        

        DeleteObject(hbmMem);
        DeleteDC(hdcMem);
    }
    else
    {
        // No picture set. We draw an icon to
        // indicate our presence
        DrawIcon(hDC, 0, 0, m_hIcon);
    }

    ::ReleaseDC(hwnd, hDC);
}

STDMETHODIMP CWindowSkinner::IndicateContainerChanged()
{
    HRESULT hr = S_OK;
    HWND hwnd = NULL;
    if (!m_bWindowManuallySet)
    {
	    if (m_spClientSite == NULL)
        {
            UnsubclassWindow();
            return hr;
        }

        CComPtr<IOleContainer> pContainer;
        if (FAILED(m_spClientSite->GetContainer(&pContainer)))
        {
            UnsubclassWindow();
            return hr;
        }

        CComPtr<IOleWindow> pOleWindow;
        CComPtr<IOleInPlaceFrame> pOleFrame;
        if (FAILED(pContainer->QueryInterface(&pOleWindow)))
        {
            if (FAILED(pContainer->QueryInterface(&pOleFrame)))
            {
                UnsubclassWindow();
                return hr;
            }
        }
        
        if (pOleWindow)
            pOleWindow->GetWindow(&hwnd);
        else if (pOleFrame)
            pOleFrame->GetWindow(&hwnd); // for mfc containers
        else
        {
            UnsubclassWindow();
            return hr;
        }
        
    }
    else
        hwnd = m_hwndParent;
    
    if (hwnd == NULL && m_procOld != NULL && m_hwndParent != NULL)
    {
        // We don't have any container anymore. Unsubclass
        UnsubclassWindow();
        m_hwndParent = NULL;
        return S_OK;
    }

    if (m_procOld && (m_hwndParent == hwnd))
    {
        // The window is still the same, and we have a winproc
        // handle. This implies the window is already subclassed
        return S_OK;
    }
    
    if (m_procOld == NULL)
    {
        // Subclass the window
        SetLastError(0);
        m_procOld = (WNDPROC)::GetWindowLong(hwnd, GWL_WNDPROC);

        if (GetLastError() == 0)
            ::SetWindowLong(hwnd, GWL_WNDPROC, (long)(WNDPROC)SubclassedWndProc);
        else
        {
            _ASSERT(FALSE);
            m_procOld = NULL;
        }
    }
    else
    {
        // We are changning the window we subclass

        // replace the old winproc on the old window
        //::SetWindowLong(m_hwndParent, GWL_WNDPROC, (long)(WNDPROC)m_procOld);
        UnsubclassWindow();

        // get winproc from new window
        SetLastError(0);
        m_procOld = (WNDPROC)::GetWindowLong(hwnd, GWL_WNDPROC);

        // set our proc on the new window
         if (GetLastError() == 0)
            ::SetWindowLong(hwnd, GWL_WNDPROC, (long)(WNDPROC)SubclassedWndProc);
         else
         {
            _ASSERT(FALSE);
            m_procOld = NULL;
         }
    }
    
    m_hwndParent = hwnd;
    
    if (m_hwndParent != NULL)
        AddToClassTable(this, (long)m_hwndParent);
    
//    LoadPicture();
 //   SnapToDefaultPosition();

	return S_OK;
}


void CWindowSkinner::ResizeWindowRegionToDefault()
{
    BOOL bUserMode = FALSE;
    if (FAILED(GetAmbientUserMode(bUserMode)) || bUserMode == FALSE)
    {
        // We are in design mode
        return;
    }
    
    // We get the nonclient area, and remove it
    RECT rcWin, rcClient;
    ::GetWindowRect(m_hwndParent, &rcWin);
    ::GetClientRect(m_hwndParent, &rcClient);

    POINT ptUL = {0, 0};
    ::ClientToScreen(m_hwndParent, &ptUL);
    
    int nNcOffsetLeft = ptUL.x - rcWin.left;
    int nNcOffsetTop  = ptUL.y - rcWin.top;
    int nCurrentWidth = rcClient.right - rcClient.left;
    int nCurrentHeight = rcClient.bottom - rcClient.top;

    if (m_hwndParent && m_hrgnBase)
    {
        // We size window to fit in perfectly to our region
        //::GetClientRect(m_hwndParent, &rcClient);
        //::MoveWindow(m_hwndParent, rcWin.left, rcWin.top, m_nPicWidth, m_nPicHeight, true);
        //::GetClientRect(m_hwndParent, &rcClient);
        
        m_resizeInfo.bFirstResize = true;

        ::OffsetRgn(m_hrgnBaseCopy, nNcOffsetLeft, nNcOffsetTop);
        ::OffsetRgn(m_hrgnBase, nNcOffsetLeft, nNcOffsetTop);

		::GetRgnBox(m_hrgnBase, &m_rcRgnBox);
    
        ::SetWindowRgn(m_hwndParent, m_hrgnBase, TRUE);

        CreatePanelRegions();
    }

}

//
//	BitmapToRegion :	Create a region from the "non-transparent" pixels of a bitma
//	Author :		Jean-Edouard Lachand-Robert (http://www.geocities.com/Paris/LeftBank/1160/resume.htm), June 1998
//
//	hBmp :			Source bitma
//	cTransparentColor :	Color base for the "transparent" pixels (default is black
//	cTolerance :		Color tolerance for the "transparent" pixels
//
//	A pixel is assumed to be transparent if the value of each of its 3 components (blue, green and red) is
//	greater or equal to the corresponding value in cTransparentColor and is lower or equal to the
//	corresponding value in cTransparentColor + cTolerance
//
HRGN CWindowSkinner::HDCToRegion (HDC hdcBmp, COLORREF cTransparentColor, int dwWidth, int dwHeight)
{
	HRGN hRgn = NULL;
	
	// We invert the transparent color. A hack to solve
	// a bug (don't know the cause!)
	cTransparentColor = RGB(GetBValue(cTransparentColor),
							GetGValue(cTransparentColor),
							GetRValue(cTransparentColor));

	COLORREF cTolerance = cTransparentColor;

	_ASSERT(hdcBmp);
	if (hdcBmp)
	{
		// Create a memory DC inside which we will scan the bitmap conten
		HDC hMemDC = CreateCompatibleDC(NULL);
		_ASSERT(hMemDC);
		if (hMemDC)
		{
			// Get bitmap siz
//			BITMAP bm;
//			GetObject(hBmp, sizeof(bm), &bm);

			// Create a 32 bits depth bitmap and select it into the memory DC
			BITMAPINFOHEADER RGB32BITSBITMAPINFO = {	
					sizeof(BITMAPINFOHEADER),	// biSize
					dwWidth,					// biWidth;
					dwHeight,				// biHeight;
					1,							// biPlanes;
					32,							// biBitCount
					BI_RGB,						// biCompression;
					0,							// biSizeImage;
					0,							// biXPelsPerMeter;
					0,							// biYPelsPerMeter;
					0,							// biClrUsed;
					0							// biClrImportant;
			};
			VOID * pbits32; 
			HBITMAP hbm32 = CreateDIBSection(hMemDC, (BITMAPINFO *)&RGB32BITSBITMAPINFO, DIB_RGB_COLORS, &pbits32, NULL, 0);
			_ASSERT(hbm32);
			if (hbm32)
			{
				HBITMAP holdBmp = (HBITMAP)SelectObject(hMemDC, hbm32);

				// Create a DC just to copy the bitmap into the memory D
				HDC hDC = CreateCompatibleDC(hMemDC);
				_ASSERT(hDC);
				if (hDC)
				{
					// Get how many bytes per row we have for the bitmap bits (rounded up to 32 bits
					BITMAP bm32;
					GetObject(hbm32, sizeof(bm32), &bm32);
					while (bm32.bmWidthBytes % 4)
						bm32.bmWidthBytes++;

					// Copy the bitmap into the memory D
//					HBITMAP holdBmp = (HBITMAP)SelectObject(hDC, hBmp);
//                    BitBlt(hDC, 0, 0, dwWidth, dwHeight, hdcBmp, 0, 0, SRCCOPY);

//					BitBlt(hMemDC, 0, 0, dwWidth, dwHeight, hDC, 0, 0, SRCCOPY);
                    BitBlt(hMemDC, 0, 0, dwWidth, dwHeight, hdcBmp, 0, 0, SRCCOPY);

					// For better performances, we will use the ExtCreateRegion() function to create th
					// region. This function take a RGNDATA structure on entry. We will add rectangles b
					// amount of ALLOC_UNIT number in this structure
					#define ALLOC_UNIT	100
					DWORD maxRects = ALLOC_UNIT;
					HANDLE hData = GlobalAlloc(GMEM_MOVEABLE, sizeof(RGNDATAHEADER) + (sizeof(RECT) * maxRects));
					RGNDATA *pData = (RGNDATA *)GlobalLock(hData);
					pData->rdh.dwSize = sizeof(RGNDATAHEADER);
					pData->rdh.iType = RDH_RECTANGLES;
					pData->rdh.nCount = pData->rdh.nRgnSize = 0;
					SetRect(&pData->rdh.rcBound, MAXLONG, MAXLONG, 0, 0);

					// Keep on hand highest and lowest values for the "transparent" pixel
					BYTE lr = GetRValue(cTransparentColor);
					BYTE lg = GetGValue(cTransparentColor);
					BYTE lb = GetBValue(cTransparentColor);
					BYTE hr = min(0xff, lr + GetRValue(cTolerance));
					BYTE hg = min(0xff, lg + GetGValue(cTolerance));
					BYTE hb = min(0xff, lb + GetBValue(cTolerance));

					// Scan each bitmap row from bottom to top (the bitmap is inverted vertically
					BYTE *p32 = (BYTE *)bm32.bmBits + (bm32.bmHeight - 1) * bm32.bmWidthBytes;
					for (int y = 0; y < (int)dwHeight; y++)
					{
						// Scan each bitmap pixel from left to righ
						for (int x = 0; x < (int)dwWidth; x++)
						{
							// Search for a continuous range of "non transparent pixels"
							int x0 = x;
							LONG *p = (LONG *)p32 + x;
							while (x < (int)dwWidth)
							{
								BYTE b = GetRValue(*p);
								if (b >= lr && b <= hr)
								{
									b = GetGValue(*p);
									if (b >= lg && b <= hg)
									{
										b = GetBValue(*p);
										if (b >= lb && b <= hb)
											// This pixel is "transparent"
											break;
									}
								}
								p++;
								x++;
							}

							if (x > x0)
							{
								// Add the pixels (x0, y) to (x, y+1) as a new rectangle in the regio
								if (pData->rdh.nCount >= maxRects)
								{
									GlobalUnlock(hData);
									maxRects += ALLOC_UNIT;
									hData = GlobalReAlloc(hData, sizeof(RGNDATAHEADER) + (sizeof(RECT) * maxRects), GMEM_MOVEABLE);
									pData = (RGNDATA *)GlobalLock(hData);
									_ASSERT(pData);
								}
								RECT *pr = (RECT *)&pData->Buffer;
								SetRect(&pr[pData->rdh.nCount], x0, y, x, y+1);
								if (x0 < pData->rdh.rcBound.left)
									pData->rdh.rcBound.left = x0;
								if (y < pData->rdh.rcBound.top)
									pData->rdh.rcBound.top = y;
								if (x > pData->rdh.rcBound.right)
									pData->rdh.rcBound.right = x;
								if (y+1 > pData->rdh.rcBound.bottom)
									pData->rdh.rcBound.bottom = y+1;
								pData->rdh.nCount++;

								// On Windows98, ExtCreateRegion() may fail if the number of rectangles is to
								// large (ie: > 4000). Therefore, we have to create the region by multiple steps
								if (pData->rdh.nCount == 2000)
								{
									HRGN h = ExtCreateRegion(NULL, sizeof(RGNDATAHEADER) + (sizeof(RECT) * maxRects), pData);
									_ASSERT(h);
									if (hRgn)
									{
										CombineRgn(hRgn, hRgn, h, RGN_OR);
										DeleteObject(h);
									}
									else
										hRgn = h;
									pData->rdh.nCount = 0;
									SetRect(&pData->rdh.rcBound, MAXLONG, MAXLONG, 0, 0);
								}
							}
						}

						// Go to next row (remember, the bitmap is inverted vertically
						p32 -= bm32.bmWidthBytes;
					}

					// Create or extend the region with the remaining rectangle
					HRGN h = ExtCreateRegion(NULL, sizeof(RGNDATAHEADER) + (sizeof(RECT) * maxRects), pData);
					_ASSERT(h);
					if (hRgn)
					{
						CombineRgn(hRgn, hRgn, h, RGN_OR);
						DeleteObject(h);
					}
					else
						hRgn = h;

					// Clean up
					GlobalFree(hData);
					SelectObject(hDC, holdBmp);
					DeleteDC(hDC);

				}

				DeleteObject(SelectObject(hMemDC, holdBmp));
			}

			DeleteDC(hMemDC);
		}	
	}

	return hRgn;
}

void CWindowSkinner::UnsubclassWindow()
{
    if (m_hwndParent && m_procOld)
        ::SetWindowLong(m_hwndParent, GWL_WNDPROC, (long)(WNDPROC)m_procOld);
    
    if (m_hwndParent != NULL)
        RemoveFromClassTable((long)m_hwndParent);

     m_procOld = NULL;
}

STDMETHODIMP CWindowSkinner::InfoForResizeGrip(long nLeft, long nTop, long nRight, long nBottom)
{
	m_resizeInfo.rcResizeGripPos.left = nLeft;
    m_resizeInfo.rcResizeGripPos.top = nTop;
    m_resizeInfo.rcResizeGripPos.bottom = nBottom;
    m_resizeInfo.rcResizeGripPos.right = nRight;
    
    m_resizeInfo.ptGripOffsetBottom.x = m_nPicWidth - nLeft;
    m_resizeInfo.ptGripOffsetBottom.y = m_nPicHeight - nTop;

	return S_OK;
}

BOOL CWindowSkinner::HitTestPt(POINT pt, RECT rc)
{
    if (pt.x > rc.left && pt.y > rc.top && rc.right > pt.x && rc.bottom > pt.y)
        return TRUE;

    return FALSE;
}

void CWindowSkinner::CreatePanelRegions()
{
     // We get the nonclient area, and remove it
    RECT rcWin, rcClient;
    ::GetWindowRect(m_hwndParent, &rcWin);
    ::GetClientRect(m_hwndParent, &rcClient);

    POINT ptUL = {0, 0};
    ::ClientToScreen(m_hwndParent, &ptUL);
    
    int nOffsetLeft = ptUL.x - rcWin.left;
    int nOffsetTop  = ptUL.y - rcWin.top;

    if (m_hwndParent && m_hrgnBaseCopy && m_resizeInfo.rcResizeLinesPos.right)
    {

        // a rectangle that represents the upper left corner
        m_panelRegions.hrgnUpperLeft = CreateRectRgn(nOffsetLeft, 
                                         nOffsetTop, 
                                         m_resizeInfo.rcResizeLinesPos.left,
                                         m_resizeInfo.rcResizeLinesPos.top);

        // We combine the upper left rectangle with our original shape,
        // meaning we have the upper left curves

        int res = ::CombineRgn(m_panelRegions.hrgnUpperLeft, 
                               m_panelRegions.hrgnUpperLeft,
                               m_hrgnBaseCopy, RGN_AND);
        _ASSERT(res != ERROR);
        

        // upper right rectangle
        int nRightPanelStart = nOffsetLeft + (m_nPicWidth - m_resizeInfo.rcResizeLinesPos.right);
        m_panelRegions.hrgnUpperRight = CreateRectRgn(nRightPanelStart, 
                                         nOffsetTop, 
                                         m_nPicWidth + nOffsetLeft,
                                         m_resizeInfo.rcResizeLinesPos.top);
        _ASSERT(res != ERROR);

        // upper right with curves
        res = ::CombineRgn(m_panelRegions.hrgnUpperRight, 
                           m_panelRegions.hrgnUpperRight, 
                           m_hrgnBaseCopy, RGN_AND);
        _ASSERT(res != ERROR);
        
        // lower left rectangle
        int nBottomPanelTop = nOffsetTop + (m_nPicHeight - m_resizeInfo.rcResizeLinesPos.bottom);
        m_panelRegions.hrgnLowerLeft = CreateRectRgn(nOffsetLeft, 
                                                     nBottomPanelTop, 
                                                     m_resizeInfo.rcResizeLinesPos.left,
                                                     nOffsetTop + m_nPicHeight);

        // combine lower left with curves
        res = ::CombineRgn(m_panelRegions.hrgnLowerLeft, 
                           m_panelRegions.hrgnLowerLeft, 
                           m_hrgnBaseCopy, RGN_AND);
        _ASSERT(res != ERROR);

        m_panelRegions.hrgnLowerRight = ::CreateRectRgn(nRightPanelStart, 
                                                      nBottomPanelTop + nOffsetTop, 
                                                      m_nPicWidth + nOffsetLeft,
                                                      m_nPicHeight + nOffsetTop);
        _ASSERT(res != ERROR);

        // combine lower right with curves
        res = ::CombineRgn(m_panelRegions.hrgnLowerRight, 
                           m_panelRegions.hrgnLowerRight, 
                           m_hrgnBaseCopy, RGN_AND);
        _ASSERT(res != ERROR);

		// calculate the offset of our resize rectangle from the
		// base.
		RECT rc, rcBox, rcRectBox;
		::GetRgnBox(m_hrgnBaseCopy, &rcBox);

		rc.left = m_resizeInfo.rcResizeLinesPos.left;
		rc.right = m_resizeInfo.rcResizeLinesPos.right;
		rc.top = rcBox.top;
		rc.bottom = rcBox.bottom;
		
		HRGN rgnRect = CreateRectRgnIndirect(&rc);

		CombineRgn(rgnRect, rgnRect, m_hrgnBaseCopy, RGN_AND);
		
		::GetRgnBox(rgnRect, &rcRectBox);
		m_resizeInfo.nOffsetResizeRectFromRgnBottom = rcBox.bottom - rcRectBox.bottom;

		DeleteObject(rgnRect);

    }
}

void CWindowSkinner::ResizeWindowRegion()
{
    BOOL bUserMode = FALSE;
    if (FAILED(GetAmbientUserMode(bUserMode)) || bUserMode == FALSE)
    {
        // We are in design mode
        return;
    }
    
    if (m_resizeInfo.rcResizeLinesPos.right == 0 || m_hwndParent == NULL)
        return;

     // We get the nonclient area, and remove it
    RECT rcWin, rcClient;
    ::GetWindowRect(m_hwndParent, &rcWin);
    ::GetClientRect(m_hwndParent, &rcClient);

    POINT ptUL = {0, 0};
    ::ClientToScreen(m_hwndParent, &ptUL);
    
    int nOffsetLeft = ptUL.x - rcWin.left;
    int nOffsetTop  = ptUL.y - rcWin.top;

    int nCurrentWidth = rcClient.right - rcClient.left;
    int nCurrentHeight = rcClient.bottom - rcClient.top;

 //   int nCurrentWidth = rcWin.right - rcWin.left;
 //   int nCurrentHeight = rcWin.bottom - rcWin.top;
//    int nOffsetLeft = 0;
//    int nOffsetTop = 0;

    int nRightPanelLeft = nCurrentWidth - (m_nPicWidth - m_resizeInfo.rcResizeLinesPos.right);

    // The region we will put everything in
    HRGN hrgnCombined = ::CreateRectRgn(nOffsetLeft, nOffsetTop,
                                        nCurrentWidth, nCurrentHeight);
    
    // Copy the upper left rectangle into it
    int res = ::CombineRgn(hrgnCombined, m_panelRegions.hrgnUpperLeft, NULL, RGN_COPY);
    _ASSERT(res != ERROR);

    // Offset the upperright region, combine it in, then offset it back
    // to its original position
    int nMovedX = nCurrentWidth - m_nPicWidth;
    res = ::OffsetRgn(m_panelRegions.hrgnUpperRight, nMovedX, 0);
    _ASSERT(res != ERROR);
    
    res = ::CombineRgn(hrgnCombined, hrgnCombined, m_panelRegions.hrgnUpperRight, RGN_OR);
    _ASSERT(res != ERROR);
    
    res = ::OffsetRgn(m_panelRegions.hrgnUpperRight, -nMovedX, 0);
    _ASSERT(res != ERROR);
    ///////////////////////////////////////*


    // Offset the bottom left region, and comine in
    int nMovedY = nCurrentHeight - m_nPicHeight;
    res = ::OffsetRgn(m_panelRegions.hrgnLowerLeft, 0, nMovedY);
    _ASSERT(res != ERROR);
    
    res = ::CombineRgn(hrgnCombined, hrgnCombined, m_panelRegions.hrgnLowerLeft, RGN_OR);
    _ASSERT(res != ERROR);
    
     res = ::OffsetRgn(m_panelRegions.hrgnLowerLeft, 0, -nMovedY);
    _ASSERT(res != ERROR);
    ////////////////////////////////////////*
    
    RECT rcRgnBox = {0};
    ::GetRgnBox(hrgnCombined, &rcRgnBox);
    
    m_rcRgnBox = rcRgnBox;

    // Create a rectangle for the space by which we have resized
    HRGN hrgnLeftRightRect = CreateRectRgn(m_resizeInfo.rcResizeLinesPos.left,
                                           rcRgnBox.top,
                                           nRightPanelLeft,
                                           /*nOffsetTop + nCurrentHeight - (m_nPicHeight - (*/
                                           rcRgnBox.bottom - m_resizeInfo.nOffsetResizeRectFromRgnBottom);

    // combine upper right with the union of the other two above
    res = ::CombineRgn(hrgnCombined, hrgnCombined, hrgnLeftRightRect, RGN_OR);
    _ASSERT(res != ERROR);


    //Create rectangle to region in the space between the upper
    // left panel and the lower panels.
    
    HRGN hrgnHorStrip = CreateRectRgn(rcRgnBox.left,
                                   m_resizeInfo.rcResizeLinesPos.top,
                                   rcRgnBox.right,
                                   m_resizeInfo.rcResizeLinesPos.top + nMovedY + 100);
    
     // combine in
    res = ::CombineRgn(hrgnCombined, hrgnCombined, hrgnHorStrip, RGN_OR);
    _ASSERT(res != ERROR);

    ////////////////////////////////

    // Offset the bottom right region and combine in
    res = ::OffsetRgn(m_panelRegions.hrgnLowerRight, 0, nMovedY);
    _ASSERT(res != ERROR);
    
     res = ::OffsetRgn(m_panelRegions.hrgnLowerRight, nMovedX, 0);
    _ASSERT(res != ERROR);
    
     res = ::CombineRgn(hrgnCombined, hrgnCombined, m_panelRegions.hrgnLowerRight, RGN_OR);
    _ASSERT(res != ERROR);

       res = ::OffsetRgn(m_panelRegions.hrgnLowerRight, -nMovedX, 0);
    _ASSERT(res != ERROR);
    
      res = ::OffsetRgn(m_panelRegions.hrgnLowerRight, 0, -nMovedY);
    _ASSERT(res != ERROR);

    ////////////////////////////////////////*
    ::GetRgnBox(hrgnCombined, &rcRgnBox);

    ::SetWindowRgn(m_hwndParent, hrgnCombined, TRUE);
    
    ::RedrawWindow(m_hwndParent, NULL, hrgnCombined, RDW_INVALIDATE|RDW_UPDATENOW);
    
    int nResizeGripWidth = m_resizeInfo.rcResizeGripPos.right - m_resizeInfo.rcResizeGripPos.left;
    int nResizeGripHeight = m_resizeInfo.rcResizeGripPos.bottom - m_resizeInfo.rcResizeGripPos.top;

    m_resizeInfo.rcResizeGripPos.top = rcRgnBox.bottom - m_resizeInfo.ptGripOffsetBottom.y - m_resizeInfo.ptGripOffsetBottom.y;
    m_resizeInfo.rcResizeGripPos.right = rcRgnBox.right - m_resizeInfo.ptGripOffsetBottom.x  + m_resizeInfo.ptGripOffsetBottom.x;
    m_resizeInfo.rcResizeGripPos.bottom = m_resizeInfo.rcResizeGripPos.top + nResizeGripHeight;
    m_resizeInfo.rcResizeGripPos.left = m_resizeInfo.rcResizeGripPos.right - nResizeGripWidth;
   

    DeleteObject(hrgnCombined);
    DeleteObject(hrgnLeftRightRect);
    DeleteObject(hrgnHorStrip);
}

STDMETHODIMP CWindowSkinner::get_Dragging(VARIANT_BOOL *pVal)
{
    *pVal = m_resizeInfo.bDraggingWin ? VARIANT_TRUE : VARIANT_FALSE;

	return S_OK;
}


STDMETHODIMP CWindowSkinner::get_AllowDragMove(VARIANT_BOOL *pVal)
{
    *pVal = m_resizeInfo.bAllowDragMove ? VARIANT_TRUE : VARIANT_FALSE;

	return S_OK;
}

STDMETHODIMP CWindowSkinner::put_AllowDragMove(VARIANT_BOOL newVal)
{
	m_resizeInfo.bAllowDragMove = newVal == VARIANT_TRUE;

	return S_OK;
}

STDMETHODIMP CWindowSkinner::put_ParentHwnd(long newVal)
{
    /*
	m_hwndParent = (HWND)newVal;
    m_bWindowManuallySet = true;

    IndicateContainerChanged();
    LoadPicture();
    */
    SnapToDefaultPosition();
   

	return S_OK;
}

void CWindowSkinner::SnapToDefaultPosition()
{
    m_resizeInfo.bFirstResize = false;

    RECT rcWin, rcClient;
    ::GetWindowRect(m_hwndParent, &rcWin);
    ::GetClientRect(m_hwndParent, &rcClient);

    POINT ptLR = {rcClient.right, rcClient.bottom};
    ::ClientToScreen(m_hwndParent, &ptLR);

    int nOffsetRight   = rcWin.right - ptLR.x;
    int nOffsetBottom  = rcWin.bottom - ptLR.y;

    POINT ptUL = {0, 0};
    ::ClientToScreen(m_hwndParent, &ptUL);

    int nOffsetLeft = ptUL.x - rcWin.left;
    int nOffsetTop = ptUL.y - rcWin.top;

    ::MoveWindow(m_hwndParent, rcWin.left, rcWin.top, m_nPicWidth + (nOffsetRight+nOffsetLeft), m_nPicHeight + (nOffsetBottom+nOffsetTop), true);
}

STDMETHODIMP CWindowSkinner::get_MinimumHeight(long *pVal)
{
	*pVal = m_nPicHeight;

	return S_OK;
}

STDMETHODIMP CWindowSkinner::get_MinimumWidth(long *pVal)
{
	*pVal = m_nPicWidth + 20;

	return S_OK;
}

STDMETHODIMP CWindowSkinner::GetRgnBox(long *pLeft, long *pTop, long *pWidth, long *pHeight)
{
	*pLeft = m_rcRgnBox.left;
    *pTop = m_rcRgnBox.top;
    *pWidth = m_rcRgnBox.right - m_rcRgnBox.left;
    *pHeight = m_rcRgnBox.bottom - m_rcRgnBox.top;

	return S_OK;
}

STDMETHODIMP CWindowSkinner::get_BitmapDrawOffsetX(long *pVal)
{
	*pVal = m_nDrawOffsetX;

	return S_OK;
}

STDMETHODIMP CWindowSkinner::put_BitmapDrawOffsetX(long newVal)
{
	m_nDrawOffsetX = newVal;

	return S_OK;
}

STDMETHODIMP CWindowSkinner::get_BitmapDrawOffsetY(long *pVal)
{
	*pVal = m_nDrawOffsetY;

	return S_OK;
}

STDMETHODIMP CWindowSkinner::put_BitmapDrawOffsetY(long newVal)
{
	m_nDrawOffsetX = newVal;

	return S_OK;
}

STDMETHODIMP CWindowSkinner::get_Resizing(VARIANT_BOOL *pVal)
{
	*pVal = m_resizeInfo.bResizingWin ? VARIANT_TRUE : VARIANT_FALSE;

	return S_OK;
}
