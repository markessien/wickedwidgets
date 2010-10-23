// Label.h : Declaration of the CLabel

#ifndef __LABEL_H_
#define __LABEL_H_

#include "resource.h"       // main symbols
#include <atlctl.h>


/////////////////////////////////////////////////////////////////////////////
// CLabel
class ATL_NO_VTABLE CLabel : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public CStockPropImpl<CLabel, ILabel, &IID_ILabel, &LIBID_WICKEDWIDGETSLib>,
	public CComControl<CLabel>,
	public IPersistStreamInitImpl<CLabel>,
	public IOleControlImpl<CLabel>,
	public IOleObjectImpl<CLabel>,
	public IOleInPlaceActiveObjectImpl<CLabel>,
	public IViewObjectExImpl<CLabel>,
	public IOleInPlaceObjectWindowlessImpl<CLabel>,
	public IConnectionPointContainerImpl<CLabel>,
	public IPersistStorageImpl<CLabel>,
	public ISpecifyPropertyPagesImpl<CLabel>,
	public IQuickActivateImpl<CLabel>,
	public IDataObjectImpl<CLabel>,
	public IProvideClassInfo2Impl<&CLSID_Label, &DIID__ILabelEvents, &LIBID_WICKEDWIDGETSLib>,
	public IPropertyNotifySinkCP<CLabel>,
	public CComCoClass<CLabel, &CLSID_Label>
{
public:
//	CContainedWindow m_ctlStatic;
	

	CLabel()
	{
		m_bWindowOnly = TRUE;
        m_hdcText = NULL;
        m_hdcMem = NULL;
        m_nLetterCount = 0;
        
        m_bBooting = true;
        put_BitmapDigitFormat(Alphabets);
        m_bBooting = false;
	}
    
    void FinalRelease()
    {
        if (m_hdcText)
        {
            DeleteDC(m_hdcText);
            m_hdcText = NULL;
        }

        if (m_hdcMem)
        {
            DeleteDC(m_hdcMem);
            m_hdcMem = NULL;
        }
    }

DECLARE_REGISTRY_RESOURCEID(IDR_LABEL)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CLabel)
	COM_INTERFACE_ENTRY(ILabel)
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
END_COM_MAP()

BEGIN_PROP_MAP(CLabel)
	PROP_DATA_ENTRY("_cx", m_sizeExtent.cx, VT_UI4)
	PROP_DATA_ENTRY("_cy", m_sizeExtent.cy, VT_UI4)
    PROP_ENTRY("DigitFormat", DISPID_DIGITFORMAT, CLSID_NULL)
    PROP_ENTRY("LabCaption", DISPID_LABCAPTION, CLSID_NULL)
    
	// Example entries
	// PROP_ENTRY("Property Description", dispid, clsid)
	// PROP_PAGE(CLSID_StockColorPage)
END_PROP_MAP()

BEGIN_CONNECTION_POINT_MAP(CLabel)
	CONNECTION_POINT_ENTRY(IID_IPropertyNotifySink)
END_CONNECTION_POINT_MAP()

BEGIN_MSG_MAP(CLabel)
	MESSAGE_HANDLER(WM_CREATE, OnCreate)
	MESSAGE_HANDLER(WM_SETFOCUS, OnSetFocus)
	CHAIN_MSG_MAP(CComControl<CLabel>)
ALT_MSG_MAP(1)
	// Replace this with message map entries for superclassed Static
END_MSG_MAP()
// Handler prototypes:
//  LRESULT MessageHandler(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
//  LRESULT CommandHandler(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);
//  LRESULT NotifyHandler(int idCtrl, LPNMHDR pnmh, BOOL& bHandled);

    HRESULT OnDraw(ATL_DRAWINFO& di)
	{
		RECT& rc = *(RECT*)di.prcBounds;
        FillRect(di.hdcDraw, &rc, (HBRUSH) GetStockObject(WHITE_BRUSH));
        
        if (m_hdcText)
        {
            // Copy memdc to window dc
            BitBlt(di.hdcDraw, 0, 0,
                   m_nLetterCount * m_nLetterWidth,
                   m_nLetterHeight,
			       m_hdcMem, 
                   0,
                   0, SRCCOPY);
        }
        

        return S_OK;
    }

	LRESULT OnSetFocus(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
	{
		LRESULT lRes = CComControl<CLabel>::OnSetFocus(uMsg, wParam, lParam, bHandled);
		if (m_bInPlaceActive)
		{
			DoVerbUIActivate(&m_rcPos,  NULL);
//			if(!IsChild(::GetFocus()))
//				m_ctlStatic.SetFocus();
		}
		return lRes;
	}

	LRESULT OnCreate(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/)
	{
        /*
		RECT rc;
		GetWindowRect(&rc);
		rc.right -= rc.left;
		rc.bottom -= rc.top;
		rc.top = rc.left = 0;
		m_ctlStatic.Create(m_hWnd, rc);
        */
		return 0;
	}
	STDMETHOD(SetObjectRects)(LPCRECT prcPos,LPCRECT prcClip)
	{
		IOleInPlaceObjectWindowlessImpl<CLabel>::SetObjectRects(prcPos, prcClip);
        /*
		int cx, cy;
		cx = prcPos->right - prcPos->left;
		cy = prcPos->bottom - prcPos->top;
		::SetWindowPos(m_ctlStatic.m_hWnd, NULL, 0,
			0, cx, cy, SWP_NOZORDER | SWP_NOACTIVATE);
            */
		return S_OK;
	}

// IViewObjectEx
	DECLARE_VIEW_STATUS(VIEWSTATUS_SOLIDBKGND | VIEWSTATUS_OPAQUE)

// ILabel
public:
	RECT GetLetterRect(long nIndex);
    void LoadTextBitmap(WCHAR* pszPath = NULL);

	STDMETHOD(get_Caption)(/*[out, retval]*/ BSTR *pVal);
	STDMETHOD(put_Caption)(/*[in]*/ BSTR newVal);
	STDMETHOD(get_BitmapDigitFormat)(/*[out, retval]*/ enumBitmapDigitFormat *pVal);
	STDMETHOD(put_BitmapDigitFormat)(/*[in]*/ enumBitmapDigitFormat newVal);

private:
    bool m_bBooting;
    enumBitmapDigitFormat m_digitFormat;
    HDC m_hdcText;
    HDC m_hdcMem;
    CComBSTR m_strCaption;
    long m_nLetterCount;
    long m_nLetterWidth;
    long m_nLetterHeight;
};

#endif //__LABEL_H_
