// Label.cpp : Implementation of CLabel

#include "stdafx.h"
#include "WickedWidgets.h"
#include "Label.h"

/////////////////////////////////////////////////////////////////////////////
// CLabel


STDMETHODIMP CLabel::get_BitmapDigitFormat(enumBitmapDigitFormat *pVal)
{
    if (pVal == NULL) return E_POINTER;

	*pVal = m_digitFormat;

	return S_OK;
}

STDMETHODIMP CLabel::put_BitmapDigitFormat(enumBitmapDigitFormat newVal)
{
	m_digitFormat = newVal;

    if (m_digitFormat == Alphabets)
    {
        m_nLetterWidth = 5;
        m_nLetterHeight = 6;    
    }
    else
    {
        // 9 x 12
        m_nLetterWidth = 9;
        m_nLetterHeight = 12;  
    }
    
    LoadTextBitmap();

    if (m_bBooting == false)
    {
        put_Caption(m_strCaption);

        if (!m_nFreezeEvents)
        {
            if (FireOnRequestEdit(DISPID_DIGITFORMAT) == S_FALSE)
                return S_FALSE;
        }

        m_bRequiresSave = TRUE;         // Set dirty flag

        if (!m_nFreezeEvents)
            FireOnChanged(DISPID_DIGITFORMAT); // Notify container of change

        SendOnDataChange(NULL);         // Notify advise sinks of change
    }

	return S_OK;
}

void CLabel::LoadTextBitmap(WCHAR *pszPath)
{
    HBITMAP hbm;

    if (m_digitFormat == Alphabets)
    {
        hbm = (HBITMAP)LoadImage(_Module.m_hInstResource, (LPCTSTR)IDB_LABEL_ALPHABET, IMAGE_BITMAP, 0, 0, LR_LOADMAP3DCOLORS|LR_LOADTRANSPARENT);
    }
    else
    {
        hbm = (HBITMAP)LoadImage(_Module.m_hInstResource, (LPCTSTR)IDB_LABEL_NUMBERS, IMAGE_BITMAP, 0, 0, LR_LOADMAP3DCOLORS|LR_LOADTRANSPARENT);
    }

     // We need the dimensions of the bitmap
	BITMAP bm;
	GetObject(hbm, sizeof(BITMAP), &bm);
    
    if (m_hdcText)
    {
        DeleteDC(m_hdcText);
        m_hdcText = NULL;
    }

    // Select the bitmap into a dc
    HDC hDC = ::GetDC(m_hWnd);
	m_hdcText = CreateCompatibleDC(hDC);
	SelectObject(m_hdcText, hbm);
    
    // Create memory DC for flicker free drawing
    HBITMAP hbmMem = CreateCompatibleBitmap(m_hdcText,
									        bm.bmWidth,
									        bm.bmHeight);
    
    if (m_hdcMem)
    {
        DeleteDC(m_hdcMem);
        m_hdcMem = NULL;
    }

    m_hdcMem = CreateCompatibleDC(hDC);		
	SelectObject(m_hdcMem, hbmMem);
    
    ::ReleaseDC(m_hWnd, hDC);

    DeleteObject(hbmMem);
	DeleteObject(hbm);
}

STDMETHODIMP CLabel::get_Caption(BSTR *pVal)
{
	m_strCaption.CopyTo(pVal);

	return S_OK;
}

STDMETHODIMP CLabel::put_Caption(BSTR newVal)
{
    if (m_hdcText == NULL)
	    LoadTextBitmap();

    m_strCaption = newVal;
    
    m_nLetterCount = m_strCaption.Length();
    
     // Notify property change
    if (!m_nFreezeEvents)
    {
        FireOnRequestEdit(DISPID_LABCAPTION);
    }

    m_bRequiresSave = TRUE;         // Set dirty flag

    if (!m_nFreezeEvents)
        FireOnChanged(DISPID_LABCAPTION); // Notify container of change

    SendOnDataChange(NULL);         // Notify advise sinks of change
    // ---------------

    if (m_nLetterCount == 0)
        return S_OK;
    
    FillRect(m_hdcMem, &m_rcPos, (HBRUSH) (COLOR_BTNFACE+1));

    for (int i=0;i<m_nLetterCount;i++)
    {
        WCHAR szChar[2] = {m_strCaption.m_str[i], '\0'};
        
        int iLetterIndex = 0;

        if (m_digitFormat == Numbers)
        {
            if (szChar[0] == ':')
                iLetterIndex = 11;
            else
            {
                iLetterIndex = szChar[0] - 48;

                if (_wtoi(szChar) == 0)
                {
                    iLetterIndex = 0;
                }
            }
        }
        else
        {
            if (islower(szChar[0]))
                iLetterIndex = szChar[0] - 97;
            else
                iLetterIndex = szChar[0] - 65;

            if (_wtoi(szChar) != 0)
            {
                iLetterIndex = 27;
            }
        }

        RECT rcLetter = GetLetterRect(iLetterIndex);

        // Draw letter onto the memory DC
        BitBlt(m_hdcMem, i * m_nLetterWidth, 0,
               m_nLetterWidth,
               m_nLetterHeight,
			   m_hdcText, 
               rcLetter.left,
               0,
               SRCCOPY);
    }
    
    if (IsWindow())
    {
        RedrawWindow();
//        FireViewChange();
    }

	return S_OK;
}

RECT CLabel::GetLetterRect(long nIndex)
{
    // 31 or 32 per row. All alphabets in first row
    
    if (nIndex > 28 || nIndex < 0)
        return GetLetterRect(28); // space

    long nLetterLeft = nIndex * m_nLetterWidth;

    RECT rc;
    rc.left  = nLetterLeft;
    rc.top = 0;
    rc.right = nLetterLeft + m_nLetterWidth;
    rc.bottom = rc.top + m_nLetterHeight;

    return rc;
}

//DEL RECT CLabel::GetNumberRect(int iNumber)
//DEL {
//DEL     RECT rc;
//DEL 
//DEL     rc.left 
//DEL }
