// Slider.h : Declaration of the CSlider

#ifndef __Slider_H_
#define __Slider_H_

#include "resource.h"       // main symbols
#include <atlctl.h>
#include "WickedWidgetsCP.h"


/////////////////////////////////////////////////////////////////////////////
// CSlider
class ATL_NO_VTABLE CSlider : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public IDispatchImpl<ISlider, &IID_ISlider, &LIBID_WICKEDWIDGETSLib>,
	public CComControl<CSlider>,
	public IPersistStreamInitImpl<CSlider>,
	public IOleControlImpl<CSlider>,
	public IOleObjectImpl<CSlider>,
	public IOleInPlaceActiveObjectImpl<CSlider>,
	public IViewObjectExImpl<CSlider>,
	public IOleInPlaceObjectWindowlessImpl<CSlider>,
	public IConnectionPointContainerImpl<CSlider>,
	public IPersistStorageImpl<CSlider>,
	public ISpecifyPropertyPagesImpl<CSlider>,
	public IQuickActivateImpl<CSlider>,
	public IDataObjectImpl<CSlider>,
	public IProvideClassInfo2Impl<&CLSID_Slider, &DIID__ISliderEvents, &LIBID_WICKEDWIDGETSLib>,
	public IPropertyNotifySinkCP<CSlider>,
	public CComCoClass<CSlider, &CLSID_Slider>,
	public CProxy_ISliderEvents< CSlider >
{
public:

    typedef struct tagPathValue
    {
        long nValuePathWidth;
        long nOffsetLeft;
        long nOffsetRight;
        float nStepWidth;
        long nCurrentValue;
        long nStepCount;

        void Initialize(long nPathWidth, long nBallWidth, long nStepCount)
        {
            nOffsetLeft = nBallWidth / 2;
            nOffsetRight = nBallWidth / 2;
            
            nValuePathWidth = nPathWidth - (nOffsetRight + nOffsetLeft);
            nStepWidth = (float)nValuePathWidth / (float)nStepCount;
            this->nStepCount = nStepCount;
        };

        bool HitTest(POINT pt, long nValue)
        {
            float nValueLeft = (float)GetValueLeft(nValue);
            float nValueRight = (float)nValueLeft + nStepWidth;

            if ((float)pt.x >= nValueLeft && (float)pt.x <= nValueRight)
                return true;

            return false;
        };
        
        long GetValueLeft(long nValue)
        {
            return (long)(nValue * nStepWidth);
        }

        long ValueFromPoint(POINT pt)
        {
            float nValue = ((float)pt.x / (float)nValuePathWidth) * (float)nStepCount;
            
            if (nValue > nStepCount)
                nValue = (float)nStepCount;

            if (nValue < 0)
                nValue = 0;

            return ((long)nValue);
        }

    } PathValue;

	CSlider()
	{
        m_bWindowOnly = TRUE;
        m_orientation = Horizontal;
	}

    HRESULT FinalConstruct( )
	{
        m_sliderBall.hDC = NULL;
        m_sliderBall.hDCPressed = NULL;
        m_sliderPath.hDC = NULL;
        m_sliderPath.hDCPressed = NULL;
        m_hdcMem = NULL;
        
        m_sliderPath.rc.left  = 0;
        m_sliderPath.rc.right = 0;
        m_sliderPath.rc.top = 0;
        m_sliderPath.rc.bottom = 0;

        m_sliderBall.rc.left  = 0;
        m_sliderBall.rc.right = 0;
        m_sliderBall.rc.top = 0;
        m_sliderBall.rc.bottom = 0;

        m_nSliderWidth = 0;
        m_nSliderHeight = 0;

        m_nMax = 100;
        m_nMin = 0;
//        m_nValue = 0;

        m_bPressed = FALSE;
        
        bEnabled = VARIANT_TRUE;

		return S_OK;
	}

    void FinalRelease()
    {
       CleanGDIObjects();
    }

DECLARE_REGISTRY_RESOURCEID(IDR_SLIDER)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CSlider)
	COM_INTERFACE_ENTRY(ISlider)
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

BEGIN_PROP_MAP(CSlider)
	PROP_DATA_ENTRY("_cx", m_sizeExtent.cx, VT_UI4)
	PROP_DATA_ENTRY("_cy", m_sizeExtent.cy, VT_UI4)
    PROP_ENTRY("SliderMax", DISPID_SLIDERMAX, CLSID_NULL)
    PROP_ENTRY("SliderMin", DISPID_SLIDERMIN, CLSID_NULL)
    PROP_ENTRY("SliderValue", DISPID_SLIDERVALUE, CLSID_NULL)
    PROP_ENTRY("SliderEnabled", DISPID_SLIDERENABLED, CLSID_NULL)
    PROP_ENTRY("SliderPathPicture", DISPID_PATHPICTURE, CLSID_NULL)
    PROP_ENTRY("SliderBallPicture", DISPID_BALLPICTURE, CLSID_NULL)
    PROP_ENTRY("SliderBallPicturePressed", DISPID_BALLPICTUREPRESSED, CLSID_NULL)

    
	// Example entries
	// PROP_ENTRY("Property Description", dispid, clsid)
	// PROP_PAGE(CLSID_StockColorPage)
END_PROP_MAP()

BEGIN_CONNECTION_POINT_MAP(CSlider)
	CONNECTION_POINT_ENTRY(IID_IPropertyNotifySink)
	CONNECTION_POINT_ENTRY(DIID__ISliderEvents)
END_CONNECTION_POINT_MAP()

BEGIN_MSG_MAP(CSlider)
	CHAIN_MSG_MAP(CComControl<CSlider>)
	DEFAULT_REFLECTION_HANDLER()
	MESSAGE_HANDLER(WM_LBUTTONDOWN, OnLButtonDown)
	MESSAGE_HANDLER(WM_LBUTTONUP, OnLButtonUP)
    MESSAGE_HANDLER(WM_CREATE, OnCreate)
    MESSAGE_HANDLER(WM_MOUSEMOVE, OnMouseMove)
    MESSAGE_HANDLER(WM_ERASEBKGND, OnEraseBkgnd)
END_MSG_MAP()
// Handler prototypes:
//  LRESULT MessageHandler(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
//  LRESULT CommandHandler(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);
//  LRESULT NotifyHandler(int idCtrl, LPNMHDR pnmh, BOOL& bHandled);



// IViewObjectEx
	DECLARE_VIEW_STATUS(VIEWSTATUS_SOLIDBKGND | VIEWSTATUS_OPAQUE)

// ISlider
public:
	void CenterPathAndBall();
	void CreatePressedBall();
	STDMETHOD(get_TransparentColor)(/*[out, retval]*/ OLE_COLOR *pVal);
	STDMETHOD(put_TransparentColor)(/*[in]*/ OLE_COLOR newVal);
	STDMETHOD(get_BallPicturePressed)(/*[out, retval]*/ IPictureDisp* *pVal);
	STDMETHOD(put_BallPicturePressed)(/*[in]*/ IPictureDisp* newVal);
	STDMETHOD(putref_BallPicturePressed)(/*[in]*/ IPictureDisp* newVal);

	STDMETHOD(get_BallPicture)(/*[out, retval]*/ IPictureDisp* *pVal);
	STDMETHOD(put_BallPicture)(/*[in]*/ IPictureDisp* newVal);
	STDMETHOD(putref_BallPicture)(/*[in]*/ IPictureDisp* newVal);

    STDMETHOD(get_PathPicture)(/*[out, retval]*/ IPictureDisp* *pVal);
	STDMETHOD(put_PathPicture)(/*[in]*/ IPictureDisp* newVal);
    STDMETHOD(putref_PathPicture)(/*[in]*/ IPictureDisp* newVal);
	
    STDMETHOD(get_Enabled)(/*[out, retval]*/ VARIANT_BOOL *pVal);
	STDMETHOD(put_Enabled)(/*[in]*/ VARIANT_BOOL newVal);
	STDMETHOD(get_Value)(/*[out, retval]*/ long *pVal);
	STDMETHOD(put_Value)(/*[in]*/ long newVal);
	STDMETHOD(get_Min)(/*[out, retval]*/ long *pVal);
	STDMETHOD(put_Min)(/*[in]*/ long newVal);
	STDMETHOD(get_Max)(/*[out, retval]*/ long *pVal);
	STDMETHOD(put_Max)(/*[in]*/ long newVal);
	
    STDMETHOD(InPlaceActivate)( LONG iVerb, const RECT* prcPosRect = NULL )
    {
        HRESULT hr = CComControl<CSlider>::InPlaceActivate( iVerb, prcPosRect );
        
        return hr;
    }
    
   
protected:

    LRESULT OnCreate(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
	{
         
 	    if (m_sliderBall.hDC == NULL)
             CreateBall();
         
        if (m_sliderBall.hDCPressed == NULL)
            CreatePressedBall();

        if (m_sliderPath.hDC == NULL)
             CreatePath();
        
        m_value.Initialize(m_nSliderWidth, 
                       m_sliderBall.rc.right - m_sliderBall.rc.left,
                       m_nMax - m_nMin);
    
        put_Value(m_value.nCurrentValue);
		return 0;
 	}

    LRESULT OnLButtonDown(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
	{
		m_bPressed = TRUE;
        
        HWND hwndAx;
	    m_spInPlaceSite->GetWindow(&hwndAx);
        
        SetCapture();

        DWORD xPos = LOWORD(lParam);  // horizontal position of cursor 
        DWORD yPos = HIWORD(lParam);  // vertical position of cursor 
        
        long nBallWidth = m_sliderBall.rc.right - m_sliderBall.rc.left;
        long nBallHeight = m_sliderBall.rc.bottom - m_sliderBall.rc.top;

        if (m_orientation == Horizontal)
        {
            m_sliderBall.nOffsetTag = xPos - m_sliderBall.rc.left;

            if (m_sliderBall.nOffsetTag > nBallWidth || m_sliderBall.nOffsetTag < 0)
            {
                m_sliderBall.nOffsetTag = nBallWidth / 2;
            }
        }
        else
        {
            m_sliderBall.nOffsetTag = m_sliderBall.rc.bottom - yPos;

            if (m_sliderBall.nOffsetTag > nBallHeight || m_sliderBall.nOffsetTag < 0)
            {
                m_sliderBall.nOffsetTag = nBallHeight / 2;
            }
        }
        
        CalculateBallPosition(-1, -1);

		return 0;
	}

	LRESULT OnLButtonUP(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
	{
		m_bPressed = FALSE;
        
        ReleaseCapture();

        RedrawWindow(NULL, NULL, RDW_INVALIDATE|RDW_UPDATENOW);
        
        Fire_Click();
        
        return 0;
	}
    
    LRESULT OnMouseMove(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
	{
        if (m_bPressed)
            CalculateBallPosition(-1, -1);

		return 0;
	}

	HRESULT OnDraw(ATL_DRAWINFO& di)
	{
		RECT& rc = *(RECT*)di.prcBounds;
        
        if (m_sliderPath.picture != NULL && m_hdcMem)
        {
            FillRect(m_hdcMem, &rc, (HBRUSH) (COLOR_BTNFACE+1));
            
            if (m_sliderPath.hDC)
            {
                BitBlt(m_hdcMem, m_sliderPath.rc.left,
                       m_sliderPath.rc.top, 
		               m_sliderPath.rc.right  - m_sliderPath.rc.left,
		               m_sliderPath.rc.bottom - m_sliderPath.rc.top,
		               m_sliderPath.hDC, 
		               0, 0, SRCCOPY);
            }
        
            HDC hDCBall = m_bPressed ? m_sliderBall.hDCPressed : m_sliderBall.hDC;
            
            if (!hDCBall && m_bPressed && m_sliderBall.hDC)
                hDCBall = m_sliderBall.hDC;

            if (hDCBall)
            {
       	        BitBlt(m_hdcMem, m_sliderBall.rc.left, 
                       m_sliderBall.rc.top, 
		               m_sliderBall.rc.right  - m_sliderBall.rc.left,
		               m_sliderBall.rc.bottom - m_sliderBall.rc.top,
		               hDCBall, 
		               0, 0, SRCCOPY);
            }
        
            // Copy memdc to window dc
            BitBlt(di.hdcDraw, 0, 0,
                   m_nSliderWidth,
                   m_nSliderHeight,
			       m_hdcMem, 
                   0, 0, SRCCOPY);
        }
        else
        {
            FillRect(di.hdcDraw, &rc, (HBRUSH) (COLOR_3DSHADOW+1));
        }

		return S_OK;
	}
    
    LRESULT OnEraseBkgnd(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
	{
        /*
		HDC hdc  =(HDC)wParam;

        if (hdc && m_sliderPath.hDC)
        {
            BitBlt(hdc, m_sliderPath.rc.left,
                   m_sliderPath.rc.top, 
		           m_sliderPath.rc.right  - m_sliderPath.rc.left,
		           m_sliderPath.rc.bottom - m_sliderPath.rc.top,
		           m_sliderPath.hDC, 
		           0, 0, SRCCOPY);
        }
        */

        //bHandled = TRUE;
		return 0;
	}

private:	
    void CreatePath();
	void CreateBall();
    void CalculateBallPosition(int iManualX, int iManualY);
    void CleanGDIObjects();
private:

    struct SliderElement
    {
        HDC hDC;
        RECT rc;
        HDC hDCPressed;
        long nOffsetTag;
        CComPtr<IPictureDisp> pictureDisp;
        CComPtr<IPicture> picture;
        
        CComPtr<IPictureDisp> pictureDispPressed;
        CComPtr<IPicture> picturePressed;
    };
    
    VARIANT_BOOL bEnabled;
    long m_nMax;
    long m_nMin;
   // long m_nValue;
    
    long m_nSliderWidth;
    long m_nSliderHeight;

    HDC m_hdcMem;
    BOOL m_bPressed;
    SliderElement m_sliderPath;
    SliderElement m_sliderBall;
    enumSliderOrientation m_orientation;
    OLE_COLOR m_clrTransparent;
    
    tagPathValue m_value;
};

#endif //__Slider_H_
