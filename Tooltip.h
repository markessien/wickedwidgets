// Tooltip.h: interface for the CTooltip class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TOOLTIP_H__83A36574_2B83_421E_83F5_C0AEB562F11C__INCLUDED_)
#define AFX_TOOLTIP_H__83A36574_2B83_421E_83F5_C0AEB562F11C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <Commctrl.h>


class CTooltip  
{
public:
	CTooltip();
	virtual ~CTooltip();

    void CreateTooltip(POINT pt, TCHAR* pszTxt, HWND hwndParent);
    void NotifyTooltip(UINT uMsg, long lParam, long wParam);

private:
    HWND m_hWnd;
    HWND m_hwndParent;
};

#endif // !defined(AFX_TOOLTIP_H__83A36574_2B83_421E_83F5_C0AEB562F11C__INCLUDED_)
