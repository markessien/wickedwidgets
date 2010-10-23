// BitmapButton.cpp : Implementation of CBitmapButton

#include "stdafx.h"
#include "WickedWidgets.h"
#include "BitmapButton.h"

/////////////////////////////////////////////////////////////////////////////
// CBitmapButton


void CBitmapButton::LoadBitmap(bool bOnlySizeChanged)
{
    
    m_nHeight = 0;
    m_nWidth = 0;

    if (m_picture)
    {
        OLE_XSIZE_HIMETRIC w;
        OLE_YSIZE_HIMETRIC h;
    
        m_picture->get_Width(&w);
        m_picture->get_Height(&h);

        SIZEL szlPixels;
        SIZEL szlMetric = { w, h };
    
        AtlHiMetricToPixel(&szlMetric, &szlPixels);
        
        if (m_bHasHover == VARIANT_TRUE)
            m_nHeight = (szlPixels.cy / 3);
        else
            m_nHeight = (szlPixels.cy / 2);

        m_nWidth = szlPixels.cx;
    }

    // Snap the button object to the size of bitmap
    if (m_spInPlaceSite && m_picture)
    {
        RECT rc; rc.left = m_rcPos.left; rc.top = m_rcPos.top;
        rc.bottom = rc.top + m_nHeight; 
        rc.right = rc.left + m_nWidth;
    
        m_spInPlaceSite->OnPosRectChange(&rc);
    }

    if (!bOnlySizeChanged && m_hdc)
    {
        DeleteDC(m_hdc);
        m_hdc = NULL;
    }
    
    if (!bOnlySizeChanged && m_hdcMem)
    {
        DeleteDC(m_hdcMem);
        m_hdcMem = NULL;
    }
    
  //  HWND hwndTest = NULL;
 //   IOleInPlaceActiveObjectImpl<CBitmapButton>::GetWindow(&hwndTest);

    // Select the bitmap into a dc
    if (m_hWnd && m_picture)
    {
        HDC hDC = ::GetDC(m_hWnd);

        if (!bOnlySizeChanged)
        {
	        m_hdc = CreateCompatibleDC(hDC);
         
            // Select the bitmap unto our hdc
            HDC hdcOld;
            m_picture->SelectPicture(m_hdc, &hdcOld, NULL);
        
            PixelsToColor(m_hdc, m_nWidth, m_nHeight, RGB(255, 0, 255), GetSysColor(COLOR_BTNFACE));
        }

          // Create memory DC for flicker free drawing
        HBITMAP hbmMem = CreateCompatibleBitmap(m_hdc,
									            m_nWidth,
									            m_nHeight);
        if (!bOnlySizeChanged)
            m_hdcMem = CreateCompatibleDC(hDC);		

	    SelectObject(m_hdcMem, hbmMem);
    
        DeleteObject(hbmMem);

        ::ReleaseDC(m_hWnd, hDC);
        
        InitCommonControls(); 

        RedrawWindow();
    }
}

LRESULT CALLBACK CBitmapButton::NotifyWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    CBitmapButton* pThis = GetClassFromClassTable((long)hWnd);

    switch (message)
    {
    case WM_REQUIRE_RELEASE:
        pThis->Release();
        break;
    }

    return ::DefWindowProc(hWnd, message, wParam, lParam);;
}

BOOL CBitmapButton::CreateNotifyWnd()
{
	if (m_hWndNotify)
		return TRUE;

    static int nClassCreated; // initialized to 0 because of static

    if (nClassCreated == 0)
    {
        WNDCLASS wc;

        ZeroMemory(&wc, sizeof wc);
        wc.lpfnWndProc = NotifyWndProc;
        wc.hInstance = _Module.m_hInst;
        wc.lpszClassName = "BitmapButtonNotifyWnd";
        wc.lpszMenuName  = 0;
        wc.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
        wc.hCursor       = LoadCursor(NULL, IDC_ARROW);
        wc.hIcon         = LoadIcon(_Module.m_hInst, (LPCTSTR) IDI_SKINNER);

        if(!RegisterClass(&wc))
        {
		  //  _ASSERT(FALSE);
            return FALSE;
        }

        nClassCreated = 1;
    }

    // Create the main window.  The WS_CLIPCHILDREN style is required.
    m_hWndNotify = CreateWindow("BitmapButtonNotifyWnd", "BitmapButton",
                    WS_OVERLAPPEDWINDOW | WS_CAPTION | WS_CLIPCHILDREN,
                    CW_USEDEFAULT, CW_USEDEFAULT,
                    CW_USEDEFAULT, CW_USEDEFAULT,
                    0, 0, _Module.m_hInst, 0);
	
	_ASSERT(m_hWndNotify);

    if (m_hWndNotify)
	{
		// Cool
        AddToClassTable(this, (long) m_hWndNotify);
	}
	else
	{
		return FALSE;
	}

	return TRUE;

}

int CBitmapButton::ButtonHitTest(long x, long y, RECT * rcButton)
{
    long lRealRight = m_lLeftOffset + (m_nButtonWidth * m_nButtonCount);
    if (x < m_lLeftOffset || x > lRealRight || y < 0 || y > m_nHeight)
        return -1; // outside of our window

    // Default buttons are 23 x 19
    
    int k=0;
    for (int i=m_lLeftOffset;i<=lRealRight; i+=m_nButtonWidth)
    {
        k++;
        if (x < i)
        {
            if (rcButton)
            {
                // We place the button co-ordinates here
                rcButton->top = 0;
                rcButton->bottom = m_nHeight;
                rcButton->left = i - m_nButtonWidth;
                rcButton->right = rcButton->left + m_nButtonWidth;
            }

            return (k - 2);
        }
    }

    return -1;
}

STDMETHODIMP CBitmapButton::get_Picture(IPictureDisp **pVal)
{
	m_pictureDisp.CopyTo(pVal);

	return S_OK;
}

STDMETHODIMP CBitmapButton::putref_Picture(IPictureDisp* newVal)
{
    if(FireOnRequestEdit(DISPID_BPICTURE) == S_FALSE)
        return S_FALSE;
    
    m_pictureDisp = newVal;
    m_picture = NULL;

    if (m_pictureDisp != NULL)
        m_pictureDisp->QueryInterface(IID_IPicture,(void**)&m_picture);

	m_bRequiresSave = TRUE;
    FireOnChanged(DISPID_BPICTURE);
    SendOnDataChange(NULL);
    
    LoadBitmap();

	return S_OK;
}


STDMETHODIMP CBitmapButton::put_Picture(IPictureDisp *newVal)
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
    
    LoadBitmap();

	return S_OK;
}


STDMETHODIMP CBitmapButton::get_ButtonHeight(long *pVal)
{
	// Not neccesary

	return E_NOTIMPL;
}

STDMETHODIMP CBitmapButton::put_ButtonHeight(long newVal)
{
	// Not neccesary

	return E_NOTIMPL;
}

STDMETHODIMP CBitmapButton::get_ButtonWidth(long *pVal)
{
	*pVal = m_nButtonWidth;

	return S_OK;
}

STDMETHODIMP CBitmapButton::put_ButtonWidth(long newVal)
{
	m_nButtonWidth = newVal;

	return S_OK;
}

STDMETHODIMP CBitmapButton::get_ButtonCount(long *pVal)
{
	*pVal = m_nButtonCount;

	return S_OK;
}

STDMETHODIMP CBitmapButton::put_ButtonCount(long newVal)
{
	m_nButtonCount = newVal;

	return S_OK;
}

STDMETHODIMP CBitmapButton::get_HasHover(VARIANT_BOOL *pVal)
{
	*pVal = m_bHasHover;

	return S_OK;
}

STDMETHODIMP CBitmapButton::put_HasHover(VARIANT_BOOL newVal)
{
	m_bHasHover = newVal;

    LoadBitmap(true);
	return S_OK;
}

STDMETHODIMP CBitmapButton::get_LeftOffset(long *pVal)
{
	*pVal = m_lLeftOffset;

	return S_OK;
}

STDMETHODIMP CBitmapButton::put_LeftOffset(long newVal)
{
	m_lLeftOffset = newVal;

	return S_OK;
}

STDMETHODIMP CBitmapButton::get_ToggleButton(VARIANT_BOOL *pVal)
{
    *pVal = m_bIsToggle ? VARIANT_TRUE : VARIANT_FALSE;

	return S_OK;
}

STDMETHODIMP CBitmapButton::put_ToggleButton(VARIANT_BOOL newVal)
{
	m_bIsToggle = newVal == VARIANT_TRUE;

	return S_OK;
}

STDMETHODIMP CBitmapButton::AddTooltips(BSTR strTips)
{
    int nLength = wcslen(strTips);
    
    wcscpy(m_szTooltips, strTips);
    
    int nIndex = 1;
    m_arrTooltipOffsets[0] = 0;
    for (int i=0; i<nLength; i++)
    {
        if (m_szTooltips[i] == '|')
        {
            m_arrTooltipOffsets[nIndex] = i + 1;
            m_szTooltips[i] = '\0';
            nIndex++;
        }

        if (nIndex > 49)
            break;
    }

    return S_OK;
}
