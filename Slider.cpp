// Silder.cpp : Implementation of CSlider

#include "stdafx.h"
#include "WickedWidgets.h"
#include "Slider.h"
#include "gdimonster.h"
#include "ocidl.h"	// Added by ClassView

/////////////////////////////////////////////////////////////////////////////
// CSlider


void CSlider::CreateBall()
{
    // We need the dimensions of the bitmap
	if (m_sliderBall.picture != NULL)
    {
        // Get the width and height of slider path
    
        OLE_XSIZE_HIMETRIC w;
        OLE_YSIZE_HIMETRIC h;

        m_sliderBall.picture->get_Width(&w);
        m_sliderBall.picture->get_Height(&h);

        SIZEL szlPixels;
        SIZEL szlMetric = { w, h };

        AtlHiMetricToPixel(&szlMetric, &szlPixels);
        
        m_sliderBall.nOffsetTag = 0;
        m_sliderBall.rc.top = 0;
        m_sliderPath.rc.left = 0;
        m_sliderBall.rc.bottom = szlPixels.cy;
        m_sliderBall.rc.right = szlPixels.cx;
    }
    
    if (m_sliderBall.hDC != NULL)
    {
        DeleteDC(m_sliderBall.hDC);
        m_sliderBall.hDC = NULL;
    }

    if (m_sliderBall.picture != NULL && m_hWnd)
    {
        // Select the bitmap into a dc
        HDC hDC = ::GetDC(m_hWnd);
        _ASSERT(m_sliderBall.hDC == NULL);
	    m_sliderBall.hDC = CreateCompatibleDC(hDC);

        // Select the bitmap unto our hdc
        HDC hdcOld;
        m_sliderBall.picture->SelectPicture(m_sliderBall.hDC, &hdcOld, NULL);
       
        ::ReleaseDC(m_hWnd, hDC);
        
        CenterPathAndBall();

        if (::IsWindow(m_hWnd))
            RedrawWindow();
    }
}

void CSlider::CreatePath()
{
    // Call after creating the balls

    if (m_sliderPath.picture != NULL)
    {
        // Get the width and height of slider path
    
        OLE_XSIZE_HIMETRIC w;
        OLE_YSIZE_HIMETRIC h;

        m_sliderPath.picture->get_Width(&w);
        m_sliderPath.picture->get_Height(&h);

        SIZEL szlPixels;
        SIZEL szlMetric = { w, h };

        AtlHiMetricToPixel(&szlMetric, &szlPixels);
        
        m_sliderPath.rc.top = 0;
        m_sliderPath.rc.left = 0;

        m_sliderPath.rc.bottom = szlPixels.cy;
        m_sliderPath.rc.right = szlPixels.cx;
    }

    long nBallWidth  = m_sliderBall.rc.right  - m_sliderBall.rc.left;
    long nBallHeight = m_sliderBall.rc.bottom - m_sliderBall.rc.top;
    long nPathWidth  = m_sliderPath.rc.right  - m_sliderPath.rc.left;
    long nPathHeight = m_sliderPath.rc.bottom - m_sliderPath.rc.top;

    
    // Get the height and width of slider.
    // if ball is larger than path, then we
    // use ball height or width
    
    if (m_sliderBall.hDC != NULL)
    {
        if (nBallWidth >= nPathWidth)
            m_nSliderWidth = nBallWidth;
        else
            m_nSliderWidth = nPathWidth;
    
        if (nBallHeight >= nPathHeight)
            m_nSliderHeight = nBallHeight;
        else
            m_nSliderHeight = nPathHeight;
    }
    else
    {
        // If we land here, then the ball hasn't yet
        // been set. We use the path dimensions then.

        m_nSliderHeight = nPathHeight;
        m_nSliderWidth = nPathWidth;
    }

    if (m_sliderPath.picture != NULL)
    {
        if (m_sliderPath.hDC)
        {
            DeleteDC(m_sliderPath.hDC);
            m_sliderPath.hDC = NULL;
        }

        HDC hDC = ::GetDC(m_hWnd);
	    m_sliderPath.hDC = CreateCompatibleDC(hDC);
         
        // Select the bitmap unto our hdc
        HDC hdcOld;
        m_sliderPath.picture->SelectPicture(m_sliderPath.hDC, &hdcOld, NULL);
        
        // PixelsToColor(m_sliderPath.hDC, bm.bmWidth, bm.bmHeight, RGB(255, 0, 255), GetSysColor(COLOR_BTNFACE));

          // Create memory DC for flicker free drawing
        HBITMAP hbmMem = CreateCompatibleBitmap(m_sliderPath.hDC,
									            m_nSliderWidth,
									            m_nSliderHeight);

        m_hdcMem = CreateCompatibleDC(hDC);		
	    SelectObject(m_hdcMem, hbmMem);
    
        DeleteObject(hbmMem);

        ::ReleaseDC(m_hWnd, hDC);
        
        if (::IsWindow(m_hWnd))
            RedrawWindow();
    }
}

void CSlider::CleanGDIObjects()
{
    if (m_sliderBall.hDC)
    {
        DeleteDC(m_sliderBall.hDC);
        m_sliderBall.hDC = NULL;
    }

    if (m_sliderPath.hDC)
    {
        DeleteDC(m_sliderPath.hDC);
        m_sliderPath.hDC = NULL;
    }
}

STDMETHODIMP CSlider::get_Max(long *pVal)
{
	*pVal = m_nMax;

	return S_OK;
}

STDMETHODIMP CSlider::put_Max(long newVal)
{
	m_nMax = newVal;
    
    if (!m_nFreezeEvents)
    {
        if (FireOnRequestEdit(DISPID_SLIDERMAX) == S_FALSE)
            return S_FALSE;
    }

    m_bRequiresSave = TRUE;

    if (!m_nFreezeEvents)
        FireOnChanged(DISPID_SLIDERMAX);

    SendOnDataChange(NULL);

	return S_OK;
}

STDMETHODIMP CSlider::get_Min(long *pVal)
{
	*pVal = m_nMin;

	return S_OK;
}

STDMETHODIMP CSlider::put_Min(long newVal)
{
	m_nMin = newVal;
    
    if (!m_nFreezeEvents)
    {
        if (FireOnRequestEdit(DISPID_SLIDERMIN) == S_FALSE)
            return S_FALSE;
    }

    m_bRequiresSave = TRUE;

    if (!m_nFreezeEvents)
        FireOnChanged(DISPID_SLIDERMIN);

    SendOnDataChange(NULL);

	return S_OK;
}

STDMETHODIMP CSlider::get_Value(long *pVal)
{
	*pVal = m_value.nCurrentValue;

	return S_OK;
}

STDMETHODIMP CSlider::put_Value(long newVal)
{
    if (m_bPressed == TRUE)
        return S_OK;

	m_value.nCurrentValue = newVal;
   
    int x,y;
    if (m_orientation == Horizontal)
    {
        y = m_sliderPath.rc.top + 5;

        long nBallWidth = m_sliderBall.rc.right - m_sliderBall.rc.left;
        m_sliderBall.nOffsetTag = nBallWidth / 2;
        
        x = m_value.GetValueLeft(m_value.nCurrentValue) + (nBallWidth / 2);

        CalculateBallPosition(x, y);
    }
    
    if (!m_nFreezeEvents)
    {
        if (FireOnRequestEdit(DISPID_SLIDERVALUE) == S_FALSE)
            return S_FALSE;
    }

    m_bRequiresSave = TRUE;

    if (!m_nFreezeEvents)
        FireOnChanged(DISPID_SLIDERVALUE);

    SendOnDataChange(NULL);

	return S_OK;
}

STDMETHODIMP CSlider::get_Enabled(VARIANT_BOOL *pVal)
{
	*pVal = bEnabled;

	return S_OK;
}

STDMETHODIMP CSlider::put_Enabled(VARIANT_BOOL newVal)
{
	bEnabled = newVal;
    
    if (!m_nFreezeEvents)
    {
        if (FireOnRequestEdit(DISPID_SLIDERENABLED) == S_FALSE)
            return S_FALSE;
    }

    m_bRequiresSave = TRUE;

    if (!m_nFreezeEvents)
        FireOnChanged(DISPID_SLIDERENABLED);

    SendOnDataChange(NULL);


	return S_OK;
}

STDMETHODIMP CSlider::get_PathPicture(IPictureDisp **pVal)
{
	m_sliderPath.pictureDisp.CopyTo(pVal);

	return S_OK;
}


STDMETHODIMP CSlider::putref_PathPicture(IPictureDisp* newVal)
{
    if(FireOnRequestEdit(DISPID_PATHPICTURE) == S_FALSE)
        return S_FALSE;
    
    m_sliderPath.pictureDisp = newVal;
    m_sliderPath.picture = NULL;

    if (m_sliderPath.pictureDisp != NULL)
        m_sliderPath.pictureDisp->QueryInterface(IID_IPicture,(void**)&m_sliderPath.picture);

	m_bRequiresSave = TRUE;
    FireOnChanged(DISPID_PATHPICTURE);
    SendOnDataChange(NULL);
    
    CreatePath();

    return S_OK;
}

STDMETHODIMP CSlider::put_PathPicture(IPictureDisp *newVal)
{
	if(FireOnRequestEdit(DISPID_PATHPICTURE) == S_FALSE)
        return S_FALSE;
    
    m_sliderPath.pictureDisp = NULL;
    m_sliderPath.picture = NULL;

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
                        OleLoadPicture(spStream, l.LowPart, FALSE, IID_IPictureDisp, (void**)&m_sliderPath.pictureDisp.p);
                        m_sliderPath.pictureDisp->QueryInterface(IID_IPicture, (void**)&m_sliderPath.picture);
                    }
                    spStream.Release();
                }
                
                GlobalFree(hGlob);
            }
        }
    }
    
    m_bRequiresSave = TRUE;
    FireOnChanged(DISPID_PATHPICTURE);
    SendOnDataChange(NULL);
    
    CreatePath();

	return S_OK;
}

STDMETHODIMP CSlider::get_BallPicture(IPictureDisp **pVal)
{
	m_sliderBall.pictureDisp.CopyTo(pVal);

	return S_OK;
}

STDMETHODIMP CSlider::putref_BallPicture(IPictureDisp* newVal)
{
   if(FireOnRequestEdit(DISPID_BALLPICTURE) == S_FALSE)
        return S_FALSE;
    
    m_sliderBall.pictureDisp = newVal;
    m_sliderBall.picture = NULL;

    if (m_sliderBall.pictureDisp != NULL)
        m_sliderBall.pictureDisp->QueryInterface(IID_IPicture,(void**)&m_sliderBall.picture);

	m_bRequiresSave = TRUE;
    FireOnChanged(DISPID_BALLPICTURE);
    SendOnDataChange(NULL);
    
    CreateBall();

    return S_OK;
}


STDMETHODIMP CSlider::put_BallPicture(IPictureDisp *newVal)
{
    if(FireOnRequestEdit(DISPID_BALLPICTURE) == S_FALSE)
        return S_FALSE;
    
    m_sliderBall.pictureDisp = NULL;
    m_sliderBall.picture = NULL;

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
                        OleLoadPicture(spStream, l.LowPart, FALSE, IID_IPictureDisp, (void**)&m_sliderBall.pictureDisp.p);
                        m_sliderBall.pictureDisp->QueryInterface(IID_IPicture, (void**)&m_sliderBall.picture);
                    }
                    spStream.Release();
                }
                
                GlobalFree(hGlob);
            }
        }
    }
    
    m_bRequiresSave = TRUE;
    FireOnChanged(DISPID_BALLPICTURE);
    SendOnDataChange(NULL);
    
    CreateBall();

	return S_OK;
}


void CSlider::CalculateBallPosition(int iManualX, int iManualY)
{
    RECT rcOldPos = m_sliderBall.rc;
    
    DWORD xPos = iManualX;  // horizontal position of cursor 
    DWORD yPos = iManualY;  // vertical position of cursor 
    
    if (m_sliderBall.hDC == NULL)
        return;

    if (iManualX == -1)
    {
        POINT point;
        ::GetCursorPos(&point);

        ScreenToClient(&point);

        xPos = point.x;  // horizontal position of cursor 
        yPos = point.y;  // vertical position of cursor
    }

    if (m_orientation == Horizontal)
    {
        long nBallWidth = m_sliderBall.rc.right - m_sliderBall.rc.left;
        long nLeft = xPos - m_sliderBall.nOffsetTag;
        long nRight = xPos + (nBallWidth - m_sliderBall.nOffsetTag);

        if (nLeft <= 0)
        {
            m_sliderBall.rc.left = 0;
            m_sliderBall.rc.right = m_sliderBall.rc.left + nBallWidth;
        }
        else if (nRight > m_sliderPath.rc.right)
        {
            m_sliderBall.rc.left = m_sliderPath.rc.right - nBallWidth;
            m_sliderBall.rc.right = m_sliderBall.rc.left + nBallWidth;
        }
        else
        {
            m_sliderBall.rc.left = xPos - m_sliderBall.nOffsetTag;
            m_sliderBall.rc.right = m_sliderBall.rc.left + nBallWidth;
        }
    }
    else
    {
        long nBallHeight = m_sliderBall.rc.bottom - m_sliderBall.rc.top;
        long nBallBottom = yPos + m_sliderBall.nOffsetTag;
        long nBallTop = nBallBottom - nBallHeight;

        if (nBallTop <= 0)
        {
            m_sliderBall.rc.top = 0;
            m_sliderBall.rc.bottom = nBallHeight;
        }
        else if (nBallBottom >= m_sliderPath.rc.bottom)
        {
            m_sliderBall.rc.bottom = m_sliderPath.rc.bottom;
            m_sliderBall.rc.top = m_sliderPath.rc.bottom - nBallHeight;
        }
        else
        {
            m_sliderBall.rc.top = yPos - m_sliderBall.nOffsetTag;
            m_sliderBall.rc.bottom = m_sliderBall.rc.top + nBallHeight;
        }
    }

    // Calculate the new value. If the value moves into
    // abother discrete value, we fire an event.
    
    if (iManualX == -1)
    {
        POINT pt = {xPos, yPos};
        long nCurrentValue = m_value.ValueFromPoint(pt);

        if (nCurrentValue != m_value.nCurrentValue)
        {
            m_value.nCurrentValue = nCurrentValue;
            Fire_Change();
        }
    }

    RECT rcUpdate = m_sliderBall.rc;
    HRGN hrgnPos = CreateRectRgnIndirect(&rcOldPos);
    HRGN hrgnUpdate = CreateRectRgnIndirect(&rcUpdate);
    HRGN hrgnCombined = CreateRectRgnIndirect(&rcUpdate);
    CombineRgn(hrgnCombined, hrgnPos, hrgnUpdate, RGN_OR);

    RedrawWindow(NULL, hrgnCombined, RDW_INVALIDATE|RDW_UPDATENOW);

    DeleteObject(hrgnUpdate);
    DeleteObject(hrgnCombined);
    DeleteObject(hrgnPos);
}

STDMETHODIMP CSlider::get_BallPicturePressed(IPictureDisp **pVal)
{
	m_sliderBall.pictureDispPressed.CopyTo(pVal);

	return S_OK;
}

STDMETHODIMP CSlider::putref_BallPicturePressed(IPictureDisp* newVal)
{
    if(FireOnRequestEdit(DISPID_BALLPICTUREPRESSED) == S_FALSE)
        return S_FALSE;
    
    m_sliderBall.pictureDispPressed = newVal;
    m_sliderBall.picturePressed = NULL;

    if (m_sliderBall.pictureDispPressed != NULL)
        m_sliderBall.pictureDispPressed->QueryInterface(IID_IPicture,(void**)&m_sliderBall.picturePressed);

	m_bRequiresSave = TRUE;
    FireOnChanged(DISPID_BALLPICTUREPRESSED);
    SendOnDataChange(NULL);
    
    CreatePressedBall();

    return S_OK;
}


STDMETHODIMP CSlider::put_BallPicturePressed(IPictureDisp *newVal)
{
    if(FireOnRequestEdit(DISPID_BALLPICTUREPRESSED) == S_FALSE)
        return S_FALSE;
    
    m_sliderBall.pictureDispPressed = NULL;
    m_sliderBall.picturePressed = NULL;

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
                        OleLoadPicture(spStream, l.LowPart, FALSE, IID_IPictureDisp, (void**)&m_sliderBall.pictureDispPressed.p);
                        m_sliderBall.pictureDispPressed->QueryInterface(IID_IPicture, (void**)&m_sliderBall.picturePressed);
                    }
                    spStream.Release();
                }
                
                GlobalFree(hGlob);
            }
        }
    }
    
    m_bRequiresSave = TRUE;
    FireOnChanged(DISPID_BALLPICTUREPRESSED);
    SendOnDataChange(NULL);
    
    CreatePressedBall();


	return S_OK;
}

STDMETHODIMP CSlider::get_TransparentColor(OLE_COLOR *pVal)
{
	*pVal = m_clrTransparent;

	return S_OK;
}

STDMETHODIMP CSlider::put_TransparentColor(OLE_COLOR newVal)
{
	m_clrTransparent= newVal;
    
	return S_OK;
}

void CSlider::CreatePressedBall()
{
    // We need the dimensions of the bitmap
	if (m_sliderBall.picturePressed != NULL)
    {
        // Get the width and height of slider path
    
        OLE_XSIZE_HIMETRIC w;
        OLE_YSIZE_HIMETRIC h;

        m_sliderBall.picturePressed->get_Width(&w);
        m_sliderBall.picturePressed->get_Height(&h);

        SIZEL szlPixels;
        SIZEL szlMetric = { w, h };

        AtlHiMetricToPixel(&szlMetric, &szlPixels);
        
        m_sliderBall.nOffsetTag = 0;
        m_sliderBall.rc.top = 0;
        m_sliderPath.rc.left = 0;
        m_sliderBall.rc.bottom = szlPixels.cy;
        m_sliderBall.rc.right = szlPixels.cx;
    }
    
    if (m_sliderBall.hDCPressed != NULL)
    {
        DeleteDC(m_sliderBall.hDCPressed);
        m_sliderBall.hDCPressed = NULL;
    }

    if (m_sliderBall.picturePressed != NULL && m_hWnd)
    {
        // Select the bitmap into a dc
        HDC hDC = ::GetDC(m_hWnd);
        _ASSERT(m_sliderBall.hDCPressed == NULL);
	    m_sliderBall.hDCPressed = CreateCompatibleDC(hDC);

        // Select the bitmap unto our hdc
        HDC hdcOld;
        m_sliderBall.picturePressed->SelectPicture(m_sliderBall.hDCPressed, &hdcOld, NULL);
       

        ::ReleaseDC(m_hWnd, hDC);
        
        CenterPathAndBall();

        if (::IsWindow(m_hWnd))
            RedrawWindow();
    }
}

void CSlider::CenterPathAndBall()
{
    // This function aligns either the path
    // or the ball to the center of the other
    // depending on which is larger. Call whenever
    // either the ball or the path might have changed.

    if (m_sliderPath.hDC && m_sliderBall.hDC) // we need both
    {
        if (m_nSliderWidth >= m_nSliderHeight)
        {
            // horizontally aligned. We center the ball vertically
            long m_nBallHeight = m_sliderBall.rc.bottom - m_sliderBall.rc.top;
            long m_nPathHeight = m_sliderPath.rc.bottom -  m_sliderPath.rc.top;

            if (m_nPathHeight > m_nBallHeight)
            {
                // the path is larger than the ball. Align ball in the middle
                m_sliderBall.rc.top = (m_nPathHeight/2) - (m_nBallHeight/2);
                m_sliderBall.rc.bottom = m_sliderBall.rc.top + m_nBallHeight;
            }
            else if (m_nPathHeight < m_nBallHeight)
            {

            }
        }
        else
        {
            // vertically aligned
        }
    }
}
