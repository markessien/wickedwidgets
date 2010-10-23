// WindowSkinner.h : Declaration of the CWindowSkinner

#ifndef __WINDOWSKINNER_H_
#define __WINDOWSKINNER_H_

#include "resource.h"       // main symbols
#include <atlctl.h>
#include "ObjectTable.h"

//#define BITMAPSTRIP_DISCRETE 20

/////////////////////////////////////////////////////////////////////////////
// CWindowSkinner
class ATL_NO_VTABLE CWindowSkinner : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public IDispatchImpl<IWindowSkinner, &IID_IWindowSkinner, &LIBID_WICKEDWIDGETSLib>,
	public CComControl<CWindowSkinner>,
	public IPersistStreamInitImpl<CWindowSkinner>,
	public IOleControlImpl<CWindowSkinner>,
	public IOleObjectImpl<CWindowSkinner>,
	public IOleInPlaceActiveObjectImpl<CWindowSkinner>,
	public IViewObjectExImpl<CWindowSkinner>,
	public IOleInPlaceObjectWindowlessImpl<CWindowSkinner>,
	public IPersistStorageImpl<CWindowSkinner>,
	public ISpecifyPropertyPagesImpl<CWindowSkinner>,
	public IQuickActivateImpl<CWindowSkinner>,
	public IDataObjectImpl<CWindowSkinner>,
	public IProvideClassInfo2Impl<&CLSID_WindowSkinner, NULL, &LIBID_WICKEDWIDGETSLib>,
	public CComCoClass<CWindowSkinner, &CLSID_WindowSkinner>,
    public CObjectTable<CWindowSkinner>
{
public:
	CWindowSkinner()
	{
        m_bWindowOnly = TRUE;
        m_hIcon = LoadIcon(_Module.m_hInstResource, (LPCTSTR) IDI_SKINNER);
        m_clrTransparent = RGB(254, 0, 254); // OLECOLOR = BGR, not RGB
        m_nPicHeight = 0;
        m_nPicWidth = 0;
        m_hdc = NULL;
        m_pThis = this;
        m_procOld = NULL;
        m_hrgnBase = NULL;
        m_bWindowManuallySet = false;
        m_hwndParent = NULL;
        m_hbrshBack = CreateSolidBrush(RGB(0, 0, 0));

		m_nDrawOffsetX = 0;
		m_nDrawOffsetY = 0;

        ZeroMemory(&m_rcRgnBox, sizeof(m_rcRgnBox));
        ZeroMemory(&m_panelRegions, sizeof(m_panelRegions));
        ZeroMemory(&m_resizeInfo, sizeof(m_resizeInfo));

    //    m_bFirstResize = false;
	}

    HRESULT FinalConstruct( )
	{
		SIZEL size = {32, 32};
		AtlPixelToHiMetric( &size, &m_sizeExtent );
		m_sizeNatural = m_sizeExtent;

		SIZEL szlPixels, szlMetric;
		szlPixels.cx = 32;
		szlPixels.cy = 32;

		AtlPixelToHiMetric(&szlPixels, &szlMetric);

		// IOleObjectImpl
		SetExtent(DVASPECT_CONTENT, &szlMetric);

		// update control sizing...
		m_rcPos.right= m_rcPos.left + 32;
		m_rcPos.bottom= m_rcPos.top + 32;

		m_bAutoSize = TRUE;

		return S_OK;
	}

    void FinalRelease()
    {
        DeleteObject(m_hbrshBack);
        UnsubclassWindow();
    }
    
DECLARE_REGISTRY_RESOURCEID(IDR_WINDOWSKINNER)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CWindowSkinner)
	COM_INTERFACE_ENTRY(IWindowSkinner)
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
	COM_INTERFACE_ENTRY(ISpecifyPropertyPages)
	COM_INTERFACE_ENTRY(IQuickActivate)
	COM_INTERFACE_ENTRY(IPersistStorage)
	COM_INTERFACE_ENTRY(IDataObject)
	COM_INTERFACE_ENTRY(IProvideClassInfo)
	COM_INTERFACE_ENTRY(IProvideClassInfo2)
END_COM_MAP()

BEGIN_PROP_MAP(CWindowSkinner)
	PROP_DATA_ENTRY("_cx", m_sizeExtent.cx, VT_UI4)
	PROP_DATA_ENTRY("_cy", m_sizeExtent.cy, VT_UI4)

    PROP_ENTRY("BackPicture", DISPID_BACKPICTURE, CLSID_NULL)
    PROP_ENTRY("TransparentColor", DISPID_TRANSPARENTCOLOR, CLSID_NULL)
    PROP_ENTRY("AllowDragMove", DISPID_ALLOWDRAGMOVE, CLSID_NULL)
    

	// Example entries
	// PROP_ENTRY("Property Description", dispid, clsid)
	// PROP_PAGE(CLSID_StockColorPage)
END_PROP_MAP()

BEGIN_MSG_MAP(CWindowSkinner)
	CHAIN_MSG_MAP(CComControl<CWindowSkinner>)
	DEFAULT_REFLECTION_HANDLER()
	MESSAGE_HANDLER(WM_DESTROY, OnDestroy)
END_MSG_MAP()
// Handler prototypes:
//  LRESULT MessageHandler(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
//  LRESULT CommandHandler(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);
//  LRESULT NotifyHandler(int idCtrl, LPNMHDR pnmh, BOOL& bHandled);



// IViewObjectEx
	DECLARE_VIEW_STATUS(VIEWSTATUS_SOLIDBKGND | VIEWSTATUS_OPAQUE)

// IWindowSkinner
public:
	STDMETHOD(get_Resizing)(/*[out, retval]*/ VARIANT_BOOL *pVal);
	STDMETHOD(get_BitmapDrawOffsetY)(/*[out, retval]*/ long *pVal);
	STDMETHOD(put_BitmapDrawOffsetY)(/*[in]*/ long newVal);
	STDMETHOD(get_BitmapDrawOffsetX)(/*[out, retval]*/ long *pVal);
	STDMETHOD(put_BitmapDrawOffsetX)(/*[in]*/ long newVal);
	STDMETHOD(GetRgnBox)(/*[out]*/ long * pLeft, /*[out]*/ long * pTop, /*[out]*/ long * pWidth, /*[out]*/ long* pHeight);
	STDMETHOD(get_MinimumWidth)(/*[out, retval]*/ long *pVal);
	STDMETHOD(get_MinimumHeight)(/*[out, retval]*/ long *pVal);
	void SnapToDefaultPosition();
	STDMETHOD(put_ParentHwnd)(/*[in]*/ long newVal);
	STDMETHOD(get_AllowDragMove)(/*[out, retval]*/ VARIANT_BOOL *pVal);
	STDMETHOD(put_AllowDragMove)(/*[in]*/ VARIANT_BOOL newVal);
	STDMETHOD(get_Dragging)(/*[out, retval]*/ VARIANT_BOOL *pVal);
	
	
	BOOL HitTestPt(POINT pt, RECT rc);
	STDMETHOD(InfoForResizeGrip)(/*[in]*/ long nLeft, /*[in]*/ long nTop, /*[in]*/ long nRight, /*[in]*/ long nBottom);

	STDMETHOD(IndicateContainerChanged)();
	STDMETHOD(InfoForResize)(long nHorLineTop, long nHorLineBottom, long nVerLineLeft, long nVerLineRight);
	STDMETHOD(get_Picture)(/*[out, retval]*/ IPictureDisp* *pVal);
	STDMETHOD(put_Picture)(/*[in]*/ IPictureDisp* newVal);
    STDMETHOD(putref_Picture)(IPictureDisp* newVal);
	STDMETHOD(get_TransparentColor)(/*[out, retval]*/ OLE_COLOR *pVal);
	STDMETHOD(put_TransparentColor)(/*[in]*/ OLE_COLOR newVal);

    STDMETHOD(SetClientSite)( IOleClientSite* pClientSite )
    {
        HRESULT hr = IOleObjectImpl<CWindowSkinner>::SetClientSite(pClientSite);
        
        IndicateContainerChanged();

        return hr;
    }

protected:
	HRESULT OnDraw(ATL_DRAWINFO& di)
	{
		RECT& rc = *(RECT*)di.prcBounds;
		DrawIcon(di.hdcDraw, rc.left, rc.top, m_hIcon);
        
		return S_OK;
	}
    
    LRESULT OnDestroy(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
	{
		UnsubclassWindow();
		return 0;
	}

    static LRESULT CALLBACK SubclassedWndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
    
private:
    void LoadPicture();
    HRGN HDCToRegion (HDC hDC, COLORREF cTransparentColor, int dwWidth, int dwHeight);
    void OnSubclassedWindowPaint(HWND hwnd);
    void UnsubclassWindow();
	void ResizeWindowRegionToDefault();
    void ResizeWindowRegion();
    void CreatePanelRegions();
private:

    typedef struct tagPanelRegions
    {
        bool bValid;
        HRGN hrgnUpperLeft;
        HRGN hrgnUpperRight;
        HRGN hrgnLowerLeft;
        HRGN hrgnLowerRight;
    } PanelRegions;
    
    typedef struct tagMoveInfo
    {
        RECT rcCursorOffset;
        POINT ptDragOffset;
        RECT rcResizeGripPos;
        RECT rcResizeLinesPos;
        POINT ptGripOffsetBottom;
        bool bDraggingWin;
        bool bResizingWin;
        bool bFirstResize;
        bool bAllowDragMove;
		int  nOffsetResizeRectFromRgnBottom;
    } ResizeInfo;

    static CWindowSkinner* m_pThis;
    WNDPROC   m_procOld;
    HBRUSH  m_hbrshBack;
    ResizeInfo m_resizeInfo;
    PanelRegions m_panelRegions;
   
    HDC m_hdc;
    OLE_COLOR m_clrTransparent;
    
    HRGN m_hrgnBase;
    HRGN m_hrgnBaseCopy;

    HICON	m_hIcon;
    CComPtr<IPictureDisp> m_pictureDisp;
    CComPtr<IPicture> m_picture;
    int m_nPicHeight;
    int m_nPicWidth;
    HWND m_hwndParent;
    bool m_bWindowManuallySet;
    RECT m_rcRgnBox;

	long m_nDrawOffsetX;
	long m_nDrawOffsetY;
};

#endif //__WINDOWSKINNER_H_
