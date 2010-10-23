// Tooltip.cpp: implementation of the CTooltip class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Tooltip.h"
#include <windows.h>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CTooltip::CTooltip()
{
    m_hWnd = NULL;
    m_hwndParent = NULL;
}

CTooltip::~CTooltip()
{

}

void CTooltip::NotifyTooltip(UINT uMsg, long lParam, long wParam)
{
    // call during WM_MOUSEMOVE, WM_LBUTTONDOWN, WM_LBUTTONUP

	MSG msg;
	msg.lParam = lParam; 
	msg.wParam = wParam; 
	msg.message = uMsg; 
	msg.hwnd = m_hwndParent;

	SendMessage(m_hWnd, TTM_RELAYEVENT, 0, 
				(LPARAM) (LPMSG) &msg);
}

void CTooltip::CreateTooltip(POINT pt, TCHAR* pszTxt, HWND hwndParent)
{
    TOOLINFO ti;
	HINSTANCE hInst = _Module.m_hInst;

    m_hWnd = CreateWindow(TOOLTIPS_CLASS, (LPSTR) NULL, TTS_ALWAYSTIP, 
							CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
							CW_USEDEFAULT, NULL, (HMENU) NULL, hInst, NULL); 
 
    if (m_hWnd == NULL) 
        return; 
	
    m_hwndParent = hwndParent;
//	ScreenToClient(hwndParent, &pt);

    ti.cbSize = sizeof(TOOLINFO); 
    ti.uFlags = 0; 
    ti.hwnd = m_hwndParent; 
    ti.hinst = hInst; 
    ti.uId = (UINT) 0; 
    ti.lpszText = pszTxt; 
    ti.rect.left = pt.x - 1; 
    ti.rect.top = pt.y - 1; 
    ti.rect.right = pt.x + 1; 
    ti.rect.bottom = pt.y + 1; 

    BOOL bResult = SendMessage(m_hWnd, TTM_ADDTOOL, 0, (LPARAM) (LPTOOLINFO) &ti);
    _ASSERT(bResult);
}