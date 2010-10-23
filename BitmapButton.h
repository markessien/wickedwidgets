// BitmapButton.h : Declaration of the CBitmapButton

#ifndef __BITMAPBUTTON_H_
#define __BITMAPBUTTON_H_

#include "resource.h"       // main symbols
#include <atlctl.h>
#include "gdimonster.h"
#include "WickedWidgetsCP.h"
#include "ObjectTable.h"
#include "tooltip.h"

#define WM_REQUIRE_RELEASE WM_APP + 13

/////////////////////////////////////////////////////////////////////////////
// CBitmapButton
class ATL_NO_VTABLE CBitmapButton : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public IDispatchImpl<IBitmapButton, &IID_IBitmapButton, &LIBID_WICKEDWIDGETSLib>,
	public CComControl<CBitmapButton>,
	public IPersistStreamInitImpl<CBitmapButton>,
	public IOleControlImpl<CBitmapButton>,
	public IOleObjectImpl<CBitmapButton>,
	public IOleInPlaceActiveObjectImpl<CBitmapButton>,
	public IViewObjectExImpl<CBitmapButton>,
	public IOleInPlaceObjectWindowlessImpl<CBitmapButton>,
	public IConnectionPointContainerImpl<CBitmapButton>,
	public IPersistStorageImpl<CBitmapButton>,
	public ISpecifyPropertyPagesImpl<CBitmapButton>,
	public IQuickActivateImpl<CBitmapButton>,
	public IDataObjectImpl<CBitmapButton>,
	public IProvideClassInfo2Impl<&CLSID_BitmapButtonBar, &DIID__IBitmapButtonEvents, &LIBID_WICKEDWIDGETSLib>,
	public IPropertyNotifySinkCP<CBitmapButton>,
	public CComCoClass<CBitmapButton, &CLSID_BitmapButtonBar>,
	public CProxy_IBitmapButtonEvents< CBitmapButton >,
    public CObjectTable<CBitmapButton>
{
public:
	STDMETHOD(AddTooltips)(/*[in]*/ BSTR strTips);
	STDMETHOD(get_ToggleButton)(/*[out, retval]*/ VARIANT_BOOL *pVal);
	STDMETHOD(put_ToggleButton)(/*[in]*/ VARIANT_BOOL newVal);
	STDMETHOD(get_LeftOffset)(/*[out, retval]*/ long *pVal);
	STDMETHOD(put_LeftOffset)(/*[in]*/ long newVal);
	STDMETHOD(get_HasHover)(/*[out, retval]*/ VARIANT_BOOL *pVal);
	STDMETHOD(put_HasHover)(/*[in]*/ VARIANT_BOOL newVal);
	STDMETHOD(get_ButtonCount)(/*[out, retval]*/ long *pVal);
	STDMETHOD(put_ButtonCount)(/*[in]*/ long newVal);
	STDMETHOD(get_ButtonWidth)(/*[out, retval]*/ long *pVal);
	STDMETHOD(put_ButtonWidth)(/*[in]*/ long newVal);
	STDMETHOD(get_ButtonHeight)(/*[out, retval]*/ long *pVal);
	STDMETHOD(put_ButtonHeight)(/*[in]*/ long newVal);
	STDMETHOD(put_Picture)(/*[in]*/ IPictureDisp* newVal);
    STDMETHOD(putref_Picture)(/*[in]*/ IPictureDisp* newVal);
	STDMETHOD(get_Picture)(/*[out, retval]*/ IPictureDisp **pVal);
	
    CBitmapButton() : m_hdc(NULL)
	{
		m_bWindowOnly = TRUE;
        m_nWidth = 0;
        m_nHeight = 0;
        m_nButtonCount = 5;
        m_nClickedButton = -1;
        m_hdcMem = NULL;
        m_nButtonWidth = 23;
        m_bHasHover = VARIANT_FALSE;
        m_lLeftOffset = 0;
        m_hWndNotify = NULL;
        m_bIsToggle = false;
        
        ZeroMemory(m_arrTooltipOffsets, sizeof(long) * 49);
        ZeroMemory(m_szTooltips, sizeof(wchar_t) * 1023);

        CreateNotifyWnd();
	}

    void FinalRelease()
    {
      //  _ASSERT(m_hWndNotify);
        if (m_hWndNotify)
        {
            RemoveFromClassTable((long)m_hWndNotify);
            ::DestroyWindow(m_hWndNotify);
        }
    }

DECLARE_REGISTRY_RESOURCEID(IDR_BITMAPBUTTON)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CBitmapButton)
	COM_INTERFACE_ENTRY(IBitmapButton)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(IViewObjectEx)
	COM_INTERFACE_ENTRY(IViewObject2)
	COM_INTERFACE_ENTRY(IViewObject)
	COM_INTERFACE_ENTRY(IOleInPlaceObjectWindowless)
	COM_INTERFACE_ENTRY(IOleInPlaceObject)
	COM_INTERFACE_ENTRY2(IOleWindow, IOleInPlaceObjectWindowless)
	COM_INTERFACE_ENTRY(IOleInPlaceActiveObject)
	COM_INTERFACE_ENTRY(IOleControl)
	COM_INTERFACE_ENTRY(IOleObject)
	COM_INTERFACE_ENTRY(IPersistStreamInit)
	COM_INTERFACE_ENTRY2(IPersist, IPersistStreamInit)
	COM_INTERFACE_ENTRY(IConnectionPointContainer)
	COM_INTERFACE_ENTRY(ISpecifyPropertyPages)
	COM_INTERFACE_ENTRY(IQuickActivate)
	COM_INTERFACE_ENTRY(IPersistStorage)
	COM_INTERFACE_ENTRY(IDataObject)
	COM_INTERFACE_ENTRY(IProvideClassInfo)
	COM_INTERFACE_ENTRY(IProvideClassInfo2)
	COM_INTERFACE_ENTRY_IMPL(IConnectionPointContainer)
END_COM_MAP()

BEGIN_PROP_MAP(CBitmapButton)
	PROP_DATA_ENTRY("_cx", m_sizeExtent.cx, VT_UI4)
	PROP_DATA_ENTRY("_cy", m_sizeExtent.cy, VT_UI4)
    PROP_ENTRY("Picture", DISPID_BPICTURE, CLSID_NULL)
    PROP_ENTRY("ButtonCount", DISPID_BUTTONCOUNT, CLSID_NULL)
    PROP_ENTRY("ButtonWidth", DISPID_BUTTONWIDTH, CLSID_NULL)
    PROP_ENTRY("HasHover", DISPID_HASHOVER, CLSID_NULL)
    PROP_ENTRY("LeftOffset", DISPID_LEFTOFFSET, CLSID_NULL)
    PROP_ENTRY("IsToggle", DISPID_ISTOGGLE,  CLSID_NULL)
	// Example entries
	// PROP_ENTRY("Property Description", dispid, clsid)
	// PROP_PAGE(CLSID_StockColorPage)
END_PROP_MAP()

BEGIN_CONNECTION_POINT_MAP(CBitmapButton)
	CONNECTION_POINT_ENTRY(IID_IPropertyNotifySink)
	CONNECTION_POINT_ENTRY(DIID__IBitmapButtonEvents)
END_CONNECTION_POINT_MAP()

BEGIN_MSG_MAP(CBitmapButton)
	CHAIN_MSG_MAP(CComControl<CBitmapButton>)
	DEFAULT_REFLECTION_HANDLER()
	MESSAGE_HANDLER(WM_LBUTTONDOWN, OnLButtonDown)
	MESSAGE_HANDLER(WM_LBUTTONUP, OnLButtonUP)
	MESSAGE_HANDLER(WM_MOUSEMOVE, OnMouseMove)
END_MSG_MAP()
// Handler prototypes:
//  LRESULT MessageHandler(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
//  LRESULT CommandHandler(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);
//  LRESULT NotifyHandler(int idCtrl, LPNMHDR pnmh, BOOL& bHandled);



// IViewObjectEx
	DECLARE_VIEW_STATUS(VIEWSTATUS_SOLIDBKGND | VIEWSTATUS_OPAQUE)

// IBitmapButton
protected:
	void LoadBitmap(bool bOnlySizeChanged = false);

	HRESULT OnDraw(ATL_DRAWINFO& di)
	{
		RECT& rc = *(RECT*)di.prcBounds;
        
        if (m_hdc == NULL)
            LoadBitmap();
        
        if (m_hdc && m_hdcMem)
        {
            
            // Draw entire button bar onto window
            
            BitBlt(m_hdcMem, 0, 0,
                   m_nWidth,
                   m_nHeight,
			       m_hdc, 
                   0,
                   0, SRCCOPY);
                  
             if (m_nClickedButton != -1)
             {
                // We draw the pressed bitmap
                 
                 BitBlt(m_hdcMem, 
                     m_rcClickedButton.left,
                     m_rcClickedButton.top,
                     m_nButtonWidth,
                     m_nHeight,
			         m_hdc, 
                     m_rcClickedButton.left,
                     m_nHeight, SRCCOPY);
             }
        
             BitBlt(di.hdcDraw, 0, 0,
                   m_nWidth,
                   m_nHeight,
			       m_hdcMem, 
                   0,
                   0, SRCCOPY);
                   
        }
        else if (m_picture)
        {
            OLE_XSIZE_HIMETRIC w;
            OLE_YSIZE_HIMETRIC h;
    
            m_picture->get_Width(&w);
            m_picture->get_Height(&h);

            m_picture->Render(di.hdcDraw, 0, 0, m_nWidth, -m_nHeight, 0, 0, w, h/2, NULL);
        }

		return S_OK;
	}
    
    LRESULT OnLButtonDown(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
	{
          
        DWORD xPos = LOWORD(lParam);  // horizontal position of cursor 
        DWORD yPos = HIWORD(lParam);  // vertical position of cursor 
        
        if (m_bIsToggle == FALSE || m_nClickedButton == -1)
            m_nClickedButton = ButtonHitTest(xPos, yPos, &m_rcClickedButton);
        else
        {
            // this is a toggle button, and we are clicking it to unpress it
           // m_nClickedButton = -1;
            m_bIsDown = true;
        }

		SetCapture();
        
        RedrawWindow(NULL, NULL, RDW_INVALIDATE|RDW_UPDATENOW);

		return 0;
	}

	LRESULT OnLButtonUP(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
	{
		ReleaseCapture();
        
        DWORD xPos = LOWORD(lParam);  // horizontal position of cursor 
        DWORD yPos = HIWORD(lParam);  // vertical position of cursor 

        int iIndex = ButtonHitTest(xPos, yPos);
        
        if (m_bIsToggle == FALSE)
            m_nClickedButton = -1;
        else if (m_bIsToggle == TRUE && iIndex != m_nClickedButton)
        {
            // we have dragged our cursor out of a button area
            // adn raised the mouse button. this means that our
            // click even will not be fire, so we don't toggle
            // the button state

            if (m_nClickedButton != -1 && m_bIsDown)
                m_nClickedButton = -1;

        }
     
        RedrawWindow(NULL, NULL, RDW_INVALIDATE|RDW_UPDATENOW);
        
        this->AddRef(); // in case it gets unloaded in Click. Atl bug
        
        try
        {
            if (iIndex != -1)
            {
                Fire_Click(iIndex);
                if (m_bIsToggle && m_nClickedButton != -1)
                {
                    // we are in toggle mode, and we where previously
                    // selected
                    m_nClickedButton = -1;
                    m_bIsDown = false;
                   //RedrawWindow(NULL, NULL, RDW_INVALIDATE|RDW_UPDATENOW);
                }
            }
        }
        catch (...)
        {
        }

        ::PostMessage(m_hWndNotify, WM_REQUIRE_RELEASE, 0, 0);

		return 0;
	}
    
    LRESULT OnMouseMove(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
	{
        DWORD xPos = LOWORD(lParam);  // horizontal position of cursor 
        DWORD yPos = HIWORD(lParam);  // vertical position of cursor 
        
        int nIndex = -1;
        if ((nIndex = ButtonHitTest(xPos, yPos, NULL)) != -1)
        {
            POINT pt = {xPos, yPos};
            wchar_t * pstr = &m_szTooltips[m_arrTooltipOffsets[nIndex]];
            
            USES_CONVERSION;
            m_tooltip.CreateTooltip(pt, W2A(pstr), m_hWnd);
            m_tooltip.NotifyTooltip(uMsg, lParam, wParam);
        }

		return 0;
	}
    
    int ButtonHitTest(long x, long y, RECT * rcButton = NULL);
    BOOL CreateNotifyWnd();
    static LRESULT CALLBACK NotifyWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

private:
    long m_arrTooltipOffsets[50];
    wchar_t m_szTooltips[1024];

    CTooltip m_tooltip;
    bool m_bIsToggle;
    HWND m_hWndNotify;
    long m_lLeftOffset;
    bool m_bIsDown;

    VARIANT_BOOL m_bHasHover;
    CComPtr<IPictureDisp> m_pictureDisp;
    CComPtr<IPicture> m_picture;
    RECT m_rcClickedButton;
    HDC m_hdcMem;
    HDC m_hdc;
    long m_nWidth;
    long m_nHeight;
    long m_nButtonCount;
    long m_nClickedButton;
    long m_nButtonWidth;
};

#endif //__BITMAPBUTTON_H_
