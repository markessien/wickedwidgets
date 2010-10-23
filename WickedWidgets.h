/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 5.01.0164 */
/* at Tue Nov 12 22:17:55 2002
 */
/* Compiler settings for X:\Dev\Code\x86Win32\WickedWidgets\WickedWidgets.idl:
    Oicf (OptLev=i2), W1, Zp8, env=Win32, ms_ext, c_ext
    error checks: allocation ref bounds_check enum stub_data 
*/
//@@MIDL_FILE_HEADING(  )


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 440
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __WickedWidgets_h__
#define __WickedWidgets_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __ISlider_FWD_DEFINED__
#define __ISlider_FWD_DEFINED__
typedef interface ISlider ISlider;
#endif 	/* __ISlider_FWD_DEFINED__ */


#ifndef ___ISliderEvents_FWD_DEFINED__
#define ___ISliderEvents_FWD_DEFINED__
typedef interface _ISliderEvents _ISliderEvents;
#endif 	/* ___ISliderEvents_FWD_DEFINED__ */


#ifndef __ILabel_FWD_DEFINED__
#define __ILabel_FWD_DEFINED__
typedef interface ILabel ILabel;
#endif 	/* __ILabel_FWD_DEFINED__ */


#ifndef __Slider_FWD_DEFINED__
#define __Slider_FWD_DEFINED__

#ifdef __cplusplus
typedef class Slider Slider;
#else
typedef struct Slider Slider;
#endif /* __cplusplus */

#endif 	/* __Slider_FWD_DEFINED__ */


#ifndef ___ILabelEvents_FWD_DEFINED__
#define ___ILabelEvents_FWD_DEFINED__
typedef interface _ILabelEvents _ILabelEvents;
#endif 	/* ___ILabelEvents_FWD_DEFINED__ */


#ifndef __IBitmapButton_FWD_DEFINED__
#define __IBitmapButton_FWD_DEFINED__
typedef interface IBitmapButton IBitmapButton;
#endif 	/* __IBitmapButton_FWD_DEFINED__ */


#ifndef __Label_FWD_DEFINED__
#define __Label_FWD_DEFINED__

#ifdef __cplusplus
typedef class Label Label;
#else
typedef struct Label Label;
#endif /* __cplusplus */

#endif 	/* __Label_FWD_DEFINED__ */


#ifndef ___IBitmapButtonEvents_FWD_DEFINED__
#define ___IBitmapButtonEvents_FWD_DEFINED__
typedef interface _IBitmapButtonEvents _IBitmapButtonEvents;
#endif 	/* ___IBitmapButtonEvents_FWD_DEFINED__ */


#ifndef __IWindowSkinner_FWD_DEFINED__
#define __IWindowSkinner_FWD_DEFINED__
typedef interface IWindowSkinner IWindowSkinner;
#endif 	/* __IWindowSkinner_FWD_DEFINED__ */


#ifndef __BitmapButtonBar_FWD_DEFINED__
#define __BitmapButtonBar_FWD_DEFINED__

#ifdef __cplusplus
typedef class BitmapButtonBar BitmapButtonBar;
#else
typedef struct BitmapButtonBar BitmapButtonBar;
#endif /* __cplusplus */

#endif 	/* __BitmapButtonBar_FWD_DEFINED__ */


#ifndef __WindowSkinner_FWD_DEFINED__
#define __WindowSkinner_FWD_DEFINED__

#ifdef __cplusplus
typedef class WindowSkinner WindowSkinner;
#else
typedef struct WindowSkinner WindowSkinner;
#endif /* __cplusplus */

#endif 	/* __WindowSkinner_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * ); 


#ifndef __WICKEDWIDGETSLib_LIBRARY_DEFINED__
#define __WICKEDWIDGETSLib_LIBRARY_DEFINED__

/* library WICKEDWIDGETSLib */
/* [helpstring][version][uuid] */ 

typedef 
enum tagSliderOrientation
    {	Vertical	= 0,
	Horizontal	= Vertical + 1
    }	enumSliderOrientation;

typedef 
enum tagBitmapDigitFormat
    {	Alphabets	= 0,
	Numbers	= Alphabets + 1
    }	enumBitmapDigitFormat;


EXTERN_C const IID LIBID_WICKEDWIDGETSLib;

#ifndef __ISlider_INTERFACE_DEFINED__
#define __ISlider_INTERFACE_DEFINED__

/* interface ISlider */
/* [unique][helpstring][dual][uuid][object] */ 

#define	DISPID_SLIDERMAX	( 1 )

#define	DISPID_SLIDERMIN	( 2 )

#define	DISPID_SLIDERVALUE	( 3 )

#define	DISPID_SLIDERENABLED	( 4 )

#define	DISPID_PATHPICTURE	( 5 )

#define	DISPID_BALLPICTURE	( 6 )

#define	DISPID_BALLPICTUREPRESSED	( 7 )

#define	DISPID_TRANSPARENTCLR	( 8 )


EXTERN_C const IID IID_ISlider;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("919CD83E-8C26-4225-82FA-155271A83FD9")
    ISlider : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Max( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Max( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Min( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Min( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Value( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Value( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Enabled( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Enabled( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [requestedit][bindable][helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_PathPicture( 
            /* [retval][out] */ IPictureDisp __RPC_FAR *__RPC_FAR *pVal) = 0;
        
        virtual /* [requestedit][bindable][helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_PathPicture( 
            /* [in] */ IPictureDisp __RPC_FAR *newVal) = 0;
        
        virtual /* [requestedit][bindable][helpstring][id][propputref] */ HRESULT STDMETHODCALLTYPE putref_PathPicture( 
            /* [in] */ IPictureDisp __RPC_FAR *newVal) = 0;
        
        virtual /* [requestedit][bindable][helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_BallPicture( 
            /* [retval][out] */ IPictureDisp __RPC_FAR *__RPC_FAR *pVal) = 0;
        
        virtual /* [requestedit][bindable][helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_BallPicture( 
            /* [in] */ IPictureDisp __RPC_FAR *newVal) = 0;
        
        virtual /* [requestedit][bindable][helpstring][id][propputref] */ HRESULT STDMETHODCALLTYPE putref_BallPicture( 
            /* [in] */ IPictureDisp __RPC_FAR *newVal) = 0;
        
        virtual /* [requestedit][bindable][helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_BallPicturePressed( 
            /* [retval][out] */ IPictureDisp __RPC_FAR *__RPC_FAR *pVal) = 0;
        
        virtual /* [requestedit][bindable][helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_BallPicturePressed( 
            /* [in] */ IPictureDisp __RPC_FAR *newVal) = 0;
        
        virtual /* [requestedit][bindable][helpstring][id][propputref] */ HRESULT STDMETHODCALLTYPE putref_BallPicturePressed( 
            /* [in] */ IPictureDisp __RPC_FAR *newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_TransparentColor( 
            /* [retval][out] */ OLE_COLOR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_TransparentColor( 
            /* [in] */ OLE_COLOR newVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ISliderVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            ISlider __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            ISlider __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            ISlider __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            ISlider __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            ISlider __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            ISlider __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            ISlider __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Max )( 
            ISlider __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Max )( 
            ISlider __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Min )( 
            ISlider __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Min )( 
            ISlider __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Value )( 
            ISlider __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Value )( 
            ISlider __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Enabled )( 
            ISlider __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Enabled )( 
            ISlider __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [requestedit][bindable][helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_PathPicture )( 
            ISlider __RPC_FAR * This,
            /* [retval][out] */ IPictureDisp __RPC_FAR *__RPC_FAR *pVal);
        
        /* [requestedit][bindable][helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_PathPicture )( 
            ISlider __RPC_FAR * This,
            /* [in] */ IPictureDisp __RPC_FAR *newVal);
        
        /* [requestedit][bindable][helpstring][id][propputref] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *putref_PathPicture )( 
            ISlider __RPC_FAR * This,
            /* [in] */ IPictureDisp __RPC_FAR *newVal);
        
        /* [requestedit][bindable][helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_BallPicture )( 
            ISlider __RPC_FAR * This,
            /* [retval][out] */ IPictureDisp __RPC_FAR *__RPC_FAR *pVal);
        
        /* [requestedit][bindable][helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_BallPicture )( 
            ISlider __RPC_FAR * This,
            /* [in] */ IPictureDisp __RPC_FAR *newVal);
        
        /* [requestedit][bindable][helpstring][id][propputref] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *putref_BallPicture )( 
            ISlider __RPC_FAR * This,
            /* [in] */ IPictureDisp __RPC_FAR *newVal);
        
        /* [requestedit][bindable][helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_BallPicturePressed )( 
            ISlider __RPC_FAR * This,
            /* [retval][out] */ IPictureDisp __RPC_FAR *__RPC_FAR *pVal);
        
        /* [requestedit][bindable][helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_BallPicturePressed )( 
            ISlider __RPC_FAR * This,
            /* [in] */ IPictureDisp __RPC_FAR *newVal);
        
        /* [requestedit][bindable][helpstring][id][propputref] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *putref_BallPicturePressed )( 
            ISlider __RPC_FAR * This,
            /* [in] */ IPictureDisp __RPC_FAR *newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_TransparentColor )( 
            ISlider __RPC_FAR * This,
            /* [retval][out] */ OLE_COLOR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_TransparentColor )( 
            ISlider __RPC_FAR * This,
            /* [in] */ OLE_COLOR newVal);
        
        END_INTERFACE
    } ISliderVtbl;

    interface ISlider
    {
        CONST_VTBL struct ISliderVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISlider_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ISlider_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ISlider_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ISlider_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define ISlider_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define ISlider_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define ISlider_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define ISlider_get_Max(This,pVal)	\
    (This)->lpVtbl -> get_Max(This,pVal)

#define ISlider_put_Max(This,newVal)	\
    (This)->lpVtbl -> put_Max(This,newVal)

#define ISlider_get_Min(This,pVal)	\
    (This)->lpVtbl -> get_Min(This,pVal)

#define ISlider_put_Min(This,newVal)	\
    (This)->lpVtbl -> put_Min(This,newVal)

#define ISlider_get_Value(This,pVal)	\
    (This)->lpVtbl -> get_Value(This,pVal)

#define ISlider_put_Value(This,newVal)	\
    (This)->lpVtbl -> put_Value(This,newVal)

#define ISlider_get_Enabled(This,pVal)	\
    (This)->lpVtbl -> get_Enabled(This,pVal)

#define ISlider_put_Enabled(This,newVal)	\
    (This)->lpVtbl -> put_Enabled(This,newVal)

#define ISlider_get_PathPicture(This,pVal)	\
    (This)->lpVtbl -> get_PathPicture(This,pVal)

#define ISlider_put_PathPicture(This,newVal)	\
    (This)->lpVtbl -> put_PathPicture(This,newVal)

#define ISlider_putref_PathPicture(This,newVal)	\
    (This)->lpVtbl -> putref_PathPicture(This,newVal)

#define ISlider_get_BallPicture(This,pVal)	\
    (This)->lpVtbl -> get_BallPicture(This,pVal)

#define ISlider_put_BallPicture(This,newVal)	\
    (This)->lpVtbl -> put_BallPicture(This,newVal)

#define ISlider_putref_BallPicture(This,newVal)	\
    (This)->lpVtbl -> putref_BallPicture(This,newVal)

#define ISlider_get_BallPicturePressed(This,pVal)	\
    (This)->lpVtbl -> get_BallPicturePressed(This,pVal)

#define ISlider_put_BallPicturePressed(This,newVal)	\
    (This)->lpVtbl -> put_BallPicturePressed(This,newVal)

#define ISlider_putref_BallPicturePressed(This,newVal)	\
    (This)->lpVtbl -> putref_BallPicturePressed(This,newVal)

#define ISlider_get_TransparentColor(This,pVal)	\
    (This)->lpVtbl -> get_TransparentColor(This,pVal)

#define ISlider_put_TransparentColor(This,newVal)	\
    (This)->lpVtbl -> put_TransparentColor(This,newVal)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ISlider_get_Max_Proxy( 
    ISlider __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB ISlider_get_Max_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ISlider_put_Max_Proxy( 
    ISlider __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB ISlider_put_Max_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ISlider_get_Min_Proxy( 
    ISlider __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB ISlider_get_Min_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ISlider_put_Min_Proxy( 
    ISlider __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB ISlider_put_Min_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ISlider_get_Value_Proxy( 
    ISlider __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB ISlider_get_Value_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ISlider_put_Value_Proxy( 
    ISlider __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB ISlider_put_Value_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ISlider_get_Enabled_Proxy( 
    ISlider __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);


void __RPC_STUB ISlider_get_Enabled_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ISlider_put_Enabled_Proxy( 
    ISlider __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL newVal);


void __RPC_STUB ISlider_put_Enabled_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [requestedit][bindable][helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ISlider_get_PathPicture_Proxy( 
    ISlider __RPC_FAR * This,
    /* [retval][out] */ IPictureDisp __RPC_FAR *__RPC_FAR *pVal);


void __RPC_STUB ISlider_get_PathPicture_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [requestedit][bindable][helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ISlider_put_PathPicture_Proxy( 
    ISlider __RPC_FAR * This,
    /* [in] */ IPictureDisp __RPC_FAR *newVal);


void __RPC_STUB ISlider_put_PathPicture_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [requestedit][bindable][helpstring][id][propputref] */ HRESULT STDMETHODCALLTYPE ISlider_putref_PathPicture_Proxy( 
    ISlider __RPC_FAR * This,
    /* [in] */ IPictureDisp __RPC_FAR *newVal);


void __RPC_STUB ISlider_putref_PathPicture_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [requestedit][bindable][helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ISlider_get_BallPicture_Proxy( 
    ISlider __RPC_FAR * This,
    /* [retval][out] */ IPictureDisp __RPC_FAR *__RPC_FAR *pVal);


void __RPC_STUB ISlider_get_BallPicture_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [requestedit][bindable][helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ISlider_put_BallPicture_Proxy( 
    ISlider __RPC_FAR * This,
    /* [in] */ IPictureDisp __RPC_FAR *newVal);


void __RPC_STUB ISlider_put_BallPicture_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [requestedit][bindable][helpstring][id][propputref] */ HRESULT STDMETHODCALLTYPE ISlider_putref_BallPicture_Proxy( 
    ISlider __RPC_FAR * This,
    /* [in] */ IPictureDisp __RPC_FAR *newVal);


void __RPC_STUB ISlider_putref_BallPicture_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [requestedit][bindable][helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ISlider_get_BallPicturePressed_Proxy( 
    ISlider __RPC_FAR * This,
    /* [retval][out] */ IPictureDisp __RPC_FAR *__RPC_FAR *pVal);


void __RPC_STUB ISlider_get_BallPicturePressed_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [requestedit][bindable][helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ISlider_put_BallPicturePressed_Proxy( 
    ISlider __RPC_FAR * This,
    /* [in] */ IPictureDisp __RPC_FAR *newVal);


void __RPC_STUB ISlider_put_BallPicturePressed_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [requestedit][bindable][helpstring][id][propputref] */ HRESULT STDMETHODCALLTYPE ISlider_putref_BallPicturePressed_Proxy( 
    ISlider __RPC_FAR * This,
    /* [in] */ IPictureDisp __RPC_FAR *newVal);


void __RPC_STUB ISlider_putref_BallPicturePressed_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ISlider_get_TransparentColor_Proxy( 
    ISlider __RPC_FAR * This,
    /* [retval][out] */ OLE_COLOR __RPC_FAR *pVal);


void __RPC_STUB ISlider_get_TransparentColor_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ISlider_put_TransparentColor_Proxy( 
    ISlider __RPC_FAR * This,
    /* [in] */ OLE_COLOR newVal);


void __RPC_STUB ISlider_put_TransparentColor_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ISlider_INTERFACE_DEFINED__ */


#ifndef ___ISliderEvents_DISPINTERFACE_DEFINED__
#define ___ISliderEvents_DISPINTERFACE_DEFINED__

/* dispinterface _ISliderEvents */
/* [helpstring][uuid] */ 


EXTERN_C const IID DIID__ISliderEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("2E21633E-ABCF-4721-8D24-FB91E078B900")
    _ISliderEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _ISliderEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            _ISliderEvents __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            _ISliderEvents __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            _ISliderEvents __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            _ISliderEvents __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            _ISliderEvents __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            _ISliderEvents __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            _ISliderEvents __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        END_INTERFACE
    } _ISliderEventsVtbl;

    interface _ISliderEvents
    {
        CONST_VTBL struct _ISliderEventsVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _ISliderEvents_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define _ISliderEvents_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define _ISliderEvents_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define _ISliderEvents_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define _ISliderEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define _ISliderEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define _ISliderEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___ISliderEvents_DISPINTERFACE_DEFINED__ */


#ifndef __ILabel_INTERFACE_DEFINED__
#define __ILabel_INTERFACE_DEFINED__

/* interface ILabel */
/* [unique][helpstring][dual][uuid][object] */ 

#define	DISPID_LABCAPTION	( 2 )

#define	DISPID_DIGITFORMAT	( 1 )


EXTERN_C const IID IID_ILabel;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("A25C9525-B0F6-4592-9EC3-7E2546BB104F")
    ILabel : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_BitmapDigitFormat( 
            /* [retval][out] */ enumBitmapDigitFormat __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_BitmapDigitFormat( 
            /* [in] */ enumBitmapDigitFormat newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Caption( 
            /* [retval][out] */ BSTR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Caption( 
            /* [in] */ BSTR newVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ILabelVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            ILabel __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            ILabel __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            ILabel __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            ILabel __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            ILabel __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            ILabel __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            ILabel __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_BitmapDigitFormat )( 
            ILabel __RPC_FAR * This,
            /* [retval][out] */ enumBitmapDigitFormat __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_BitmapDigitFormat )( 
            ILabel __RPC_FAR * This,
            /* [in] */ enumBitmapDigitFormat newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Caption )( 
            ILabel __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Caption )( 
            ILabel __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        END_INTERFACE
    } ILabelVtbl;

    interface ILabel
    {
        CONST_VTBL struct ILabelVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ILabel_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ILabel_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ILabel_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ILabel_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define ILabel_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define ILabel_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define ILabel_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define ILabel_get_BitmapDigitFormat(This,pVal)	\
    (This)->lpVtbl -> get_BitmapDigitFormat(This,pVal)

#define ILabel_put_BitmapDigitFormat(This,newVal)	\
    (This)->lpVtbl -> put_BitmapDigitFormat(This,newVal)

#define ILabel_get_Caption(This,pVal)	\
    (This)->lpVtbl -> get_Caption(This,pVal)

#define ILabel_put_Caption(This,newVal)	\
    (This)->lpVtbl -> put_Caption(This,newVal)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ILabel_get_BitmapDigitFormat_Proxy( 
    ILabel __RPC_FAR * This,
    /* [retval][out] */ enumBitmapDigitFormat __RPC_FAR *pVal);


void __RPC_STUB ILabel_get_BitmapDigitFormat_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ILabel_put_BitmapDigitFormat_Proxy( 
    ILabel __RPC_FAR * This,
    /* [in] */ enumBitmapDigitFormat newVal);


void __RPC_STUB ILabel_put_BitmapDigitFormat_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ILabel_get_Caption_Proxy( 
    ILabel __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB ILabel_get_Caption_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ILabel_put_Caption_Proxy( 
    ILabel __RPC_FAR * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB ILabel_put_Caption_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ILabel_INTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_Slider;

#ifdef __cplusplus

class DECLSPEC_UUID("0786F8E0-B105-4325-B937-6ABC696CC84E")
Slider;
#endif

#ifndef ___ILabelEvents_DISPINTERFACE_DEFINED__
#define ___ILabelEvents_DISPINTERFACE_DEFINED__

/* dispinterface _ILabelEvents */
/* [helpstring][uuid] */ 


EXTERN_C const IID DIID__ILabelEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("B5A91EC1-54BE-4D9A-99BC-6712E0C9962D")
    _ILabelEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _ILabelEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            _ILabelEvents __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            _ILabelEvents __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            _ILabelEvents __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            _ILabelEvents __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            _ILabelEvents __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            _ILabelEvents __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            _ILabelEvents __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        END_INTERFACE
    } _ILabelEventsVtbl;

    interface _ILabelEvents
    {
        CONST_VTBL struct _ILabelEventsVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _ILabelEvents_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define _ILabelEvents_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define _ILabelEvents_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define _ILabelEvents_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define _ILabelEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define _ILabelEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define _ILabelEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___ILabelEvents_DISPINTERFACE_DEFINED__ */


#ifndef __IBitmapButton_INTERFACE_DEFINED__
#define __IBitmapButton_INTERFACE_DEFINED__

/* interface IBitmapButton */
/* [unique][helpstring][dual][uuid][object] */ 

#define	DISPID_BPICTURE	( 1 )

#define	DISPID_BUTTONHEIGHT	( 2 )

#define	DISPID_BUTTONWIDTH	( 3 )

#define	DISPID_BUTTONCOUNT	( 4 )

#define	DISPID_HASHOVER	( 5 )

#define	DISPID_LEFTOFFSET	( 6 )

#define	DISPID_ISTOGGLE	( 7 )


EXTERN_C const IID IID_IBitmapButton;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("6B4C25EA-25C9-4EA9-8579-CE47738D68DC")
    IBitmapButton : public IDispatch
    {
    public:
        virtual /* [requestedit][bindable][helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Picture( 
            /* [retval][out] */ IPictureDisp __RPC_FAR *__RPC_FAR *pVal) = 0;
        
        virtual /* [requestedit][bindable][helpstring][id][propputref] */ HRESULT STDMETHODCALLTYPE putref_Picture( 
            /* [in] */ IPictureDisp __RPC_FAR *newVal) = 0;
        
        virtual /* [requestedit][bindable][helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Picture( 
            /* [in] */ IPictureDisp __RPC_FAR *newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ButtonHeight( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ButtonHeight( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ButtonWidth( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ButtonWidth( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ButtonCount( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ButtonCount( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_HasHover( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_HasHover( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_LeftOffset( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_LeftOffset( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ToggleButton( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ToggleButton( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE AddTooltips( 
            /* [in] */ BSTR strTips) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IBitmapButtonVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IBitmapButton __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IBitmapButton __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IBitmapButton __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IBitmapButton __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IBitmapButton __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IBitmapButton __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IBitmapButton __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [requestedit][bindable][helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Picture )( 
            IBitmapButton __RPC_FAR * This,
            /* [retval][out] */ IPictureDisp __RPC_FAR *__RPC_FAR *pVal);
        
        /* [requestedit][bindable][helpstring][id][propputref] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *putref_Picture )( 
            IBitmapButton __RPC_FAR * This,
            /* [in] */ IPictureDisp __RPC_FAR *newVal);
        
        /* [requestedit][bindable][helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Picture )( 
            IBitmapButton __RPC_FAR * This,
            /* [in] */ IPictureDisp __RPC_FAR *newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ButtonHeight )( 
            IBitmapButton __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ButtonHeight )( 
            IBitmapButton __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ButtonWidth )( 
            IBitmapButton __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ButtonWidth )( 
            IBitmapButton __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ButtonCount )( 
            IBitmapButton __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ButtonCount )( 
            IBitmapButton __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_HasHover )( 
            IBitmapButton __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_HasHover )( 
            IBitmapButton __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_LeftOffset )( 
            IBitmapButton __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_LeftOffset )( 
            IBitmapButton __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ToggleButton )( 
            IBitmapButton __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ToggleButton )( 
            IBitmapButton __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *AddTooltips )( 
            IBitmapButton __RPC_FAR * This,
            /* [in] */ BSTR strTips);
        
        END_INTERFACE
    } IBitmapButtonVtbl;

    interface IBitmapButton
    {
        CONST_VTBL struct IBitmapButtonVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IBitmapButton_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IBitmapButton_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IBitmapButton_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IBitmapButton_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IBitmapButton_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IBitmapButton_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IBitmapButton_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IBitmapButton_get_Picture(This,pVal)	\
    (This)->lpVtbl -> get_Picture(This,pVal)

#define IBitmapButton_putref_Picture(This,newVal)	\
    (This)->lpVtbl -> putref_Picture(This,newVal)

#define IBitmapButton_put_Picture(This,newVal)	\
    (This)->lpVtbl -> put_Picture(This,newVal)

#define IBitmapButton_get_ButtonHeight(This,pVal)	\
    (This)->lpVtbl -> get_ButtonHeight(This,pVal)

#define IBitmapButton_put_ButtonHeight(This,newVal)	\
    (This)->lpVtbl -> put_ButtonHeight(This,newVal)

#define IBitmapButton_get_ButtonWidth(This,pVal)	\
    (This)->lpVtbl -> get_ButtonWidth(This,pVal)

#define IBitmapButton_put_ButtonWidth(This,newVal)	\
    (This)->lpVtbl -> put_ButtonWidth(This,newVal)

#define IBitmapButton_get_ButtonCount(This,pVal)	\
    (This)->lpVtbl -> get_ButtonCount(This,pVal)

#define IBitmapButton_put_ButtonCount(This,newVal)	\
    (This)->lpVtbl -> put_ButtonCount(This,newVal)

#define IBitmapButton_get_HasHover(This,pVal)	\
    (This)->lpVtbl -> get_HasHover(This,pVal)

#define IBitmapButton_put_HasHover(This,newVal)	\
    (This)->lpVtbl -> put_HasHover(This,newVal)

#define IBitmapButton_get_LeftOffset(This,pVal)	\
    (This)->lpVtbl -> get_LeftOffset(This,pVal)

#define IBitmapButton_put_LeftOffset(This,newVal)	\
    (This)->lpVtbl -> put_LeftOffset(This,newVal)

#define IBitmapButton_get_ToggleButton(This,pVal)	\
    (This)->lpVtbl -> get_ToggleButton(This,pVal)

#define IBitmapButton_put_ToggleButton(This,newVal)	\
    (This)->lpVtbl -> put_ToggleButton(This,newVal)

#define IBitmapButton_AddTooltips(This,strTips)	\
    (This)->lpVtbl -> AddTooltips(This,strTips)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [requestedit][bindable][helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IBitmapButton_get_Picture_Proxy( 
    IBitmapButton __RPC_FAR * This,
    /* [retval][out] */ IPictureDisp __RPC_FAR *__RPC_FAR *pVal);


void __RPC_STUB IBitmapButton_get_Picture_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [requestedit][bindable][helpstring][id][propputref] */ HRESULT STDMETHODCALLTYPE IBitmapButton_putref_Picture_Proxy( 
    IBitmapButton __RPC_FAR * This,
    /* [in] */ IPictureDisp __RPC_FAR *newVal);


void __RPC_STUB IBitmapButton_putref_Picture_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [requestedit][bindable][helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IBitmapButton_put_Picture_Proxy( 
    IBitmapButton __RPC_FAR * This,
    /* [in] */ IPictureDisp __RPC_FAR *newVal);


void __RPC_STUB IBitmapButton_put_Picture_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IBitmapButton_get_ButtonHeight_Proxy( 
    IBitmapButton __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IBitmapButton_get_ButtonHeight_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IBitmapButton_put_ButtonHeight_Proxy( 
    IBitmapButton __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IBitmapButton_put_ButtonHeight_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IBitmapButton_get_ButtonWidth_Proxy( 
    IBitmapButton __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IBitmapButton_get_ButtonWidth_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IBitmapButton_put_ButtonWidth_Proxy( 
    IBitmapButton __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IBitmapButton_put_ButtonWidth_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IBitmapButton_get_ButtonCount_Proxy( 
    IBitmapButton __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IBitmapButton_get_ButtonCount_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IBitmapButton_put_ButtonCount_Proxy( 
    IBitmapButton __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IBitmapButton_put_ButtonCount_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IBitmapButton_get_HasHover_Proxy( 
    IBitmapButton __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);


void __RPC_STUB IBitmapButton_get_HasHover_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IBitmapButton_put_HasHover_Proxy( 
    IBitmapButton __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL newVal);


void __RPC_STUB IBitmapButton_put_HasHover_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IBitmapButton_get_LeftOffset_Proxy( 
    IBitmapButton __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IBitmapButton_get_LeftOffset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IBitmapButton_put_LeftOffset_Proxy( 
    IBitmapButton __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IBitmapButton_put_LeftOffset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IBitmapButton_get_ToggleButton_Proxy( 
    IBitmapButton __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);


void __RPC_STUB IBitmapButton_get_ToggleButton_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IBitmapButton_put_ToggleButton_Proxy( 
    IBitmapButton __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL newVal);


void __RPC_STUB IBitmapButton_put_ToggleButton_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IBitmapButton_AddTooltips_Proxy( 
    IBitmapButton __RPC_FAR * This,
    /* [in] */ BSTR strTips);


void __RPC_STUB IBitmapButton_AddTooltips_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IBitmapButton_INTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_Label;

#ifdef __cplusplus

class DECLSPEC_UUID("9169C532-E257-42AD-8090-F004C186D69B")
Label;
#endif

#ifndef ___IBitmapButtonEvents_DISPINTERFACE_DEFINED__
#define ___IBitmapButtonEvents_DISPINTERFACE_DEFINED__

/* dispinterface _IBitmapButtonEvents */
/* [helpstring][uuid] */ 


EXTERN_C const IID DIID__IBitmapButtonEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("4AAEF167-CA19-4FEF-B81B-0008190D5CC0")
    _IBitmapButtonEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _IBitmapButtonEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            _IBitmapButtonEvents __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            _IBitmapButtonEvents __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            _IBitmapButtonEvents __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            _IBitmapButtonEvents __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            _IBitmapButtonEvents __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            _IBitmapButtonEvents __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            _IBitmapButtonEvents __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        END_INTERFACE
    } _IBitmapButtonEventsVtbl;

    interface _IBitmapButtonEvents
    {
        CONST_VTBL struct _IBitmapButtonEventsVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _IBitmapButtonEvents_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define _IBitmapButtonEvents_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define _IBitmapButtonEvents_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define _IBitmapButtonEvents_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define _IBitmapButtonEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define _IBitmapButtonEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define _IBitmapButtonEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___IBitmapButtonEvents_DISPINTERFACE_DEFINED__ */


#ifndef __IWindowSkinner_INTERFACE_DEFINED__
#define __IWindowSkinner_INTERFACE_DEFINED__

/* interface IWindowSkinner */
/* [unique][helpstring][dual][uuid][object] */ 

#define	DISPID_TRANSPARENTCOLOR	( 1 )

#define	DISPID_BACKPICTURE	( 2 )

#define	DISPID_ALLOWDRAGMOVE	( 7 )


EXTERN_C const IID IID_IWindowSkinner;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E38DBFF6-D23F-4BC3-8C91-23D346544D00")
    IWindowSkinner : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_TransparentColor( 
            /* [retval][out] */ OLE_COLOR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_TransparentColor( 
            /* [in] */ OLE_COLOR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Picture( 
            /* [retval][out] */ IPictureDisp __RPC_FAR *__RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Picture( 
            /* [in] */ IPictureDisp __RPC_FAR *newVal) = 0;
        
        virtual /* [requestedit][bindable][helpstring][id][propputref] */ HRESULT STDMETHODCALLTYPE putref_Picture( 
            /* [in] */ IPictureDisp __RPC_FAR *newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE InfoForResize( 
            /* [in] */ long nHorLineTop,
            /* [in] */ long nHorLineBottom,
            /* [in] */ long nVerLineLeft,
            /* [in] */ long nVerLineRight) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IndicateContainerChanged( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE InfoForResizeGrip( 
            /* [in] */ long nLeft,
            /* [in] */ long nTop,
            /* [in] */ long nRight,
            /* [in] */ long nBottom) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Dragging( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_AllowDragMove( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_AllowDragMove( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ParentHwnd( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_MinimumHeight( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_MinimumWidth( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetRgnBox( 
            /* [out] */ long __RPC_FAR *pLeft,
            /* [out] */ long __RPC_FAR *pTop,
            /* [out] */ long __RPC_FAR *pWidth,
            /* [out] */ long __RPC_FAR *pHeight) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_BitmapDrawOffsetX( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_BitmapDrawOffsetX( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_BitmapDrawOffsetY( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_BitmapDrawOffsetY( 
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Resizing( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IWindowSkinnerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IWindowSkinner __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IWindowSkinner __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IWindowSkinner __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IWindowSkinner __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IWindowSkinner __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IWindowSkinner __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IWindowSkinner __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_TransparentColor )( 
            IWindowSkinner __RPC_FAR * This,
            /* [retval][out] */ OLE_COLOR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_TransparentColor )( 
            IWindowSkinner __RPC_FAR * This,
            /* [in] */ OLE_COLOR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Picture )( 
            IWindowSkinner __RPC_FAR * This,
            /* [retval][out] */ IPictureDisp __RPC_FAR *__RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Picture )( 
            IWindowSkinner __RPC_FAR * This,
            /* [in] */ IPictureDisp __RPC_FAR *newVal);
        
        /* [requestedit][bindable][helpstring][id][propputref] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *putref_Picture )( 
            IWindowSkinner __RPC_FAR * This,
            /* [in] */ IPictureDisp __RPC_FAR *newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *InfoForResize )( 
            IWindowSkinner __RPC_FAR * This,
            /* [in] */ long nHorLineTop,
            /* [in] */ long nHorLineBottom,
            /* [in] */ long nVerLineLeft,
            /* [in] */ long nVerLineRight);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *IndicateContainerChanged )( 
            IWindowSkinner __RPC_FAR * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *InfoForResizeGrip )( 
            IWindowSkinner __RPC_FAR * This,
            /* [in] */ long nLeft,
            /* [in] */ long nTop,
            /* [in] */ long nRight,
            /* [in] */ long nBottom);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Dragging )( 
            IWindowSkinner __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_AllowDragMove )( 
            IWindowSkinner __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_AllowDragMove )( 
            IWindowSkinner __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ParentHwnd )( 
            IWindowSkinner __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_MinimumHeight )( 
            IWindowSkinner __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_MinimumWidth )( 
            IWindowSkinner __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetRgnBox )( 
            IWindowSkinner __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *pLeft,
            /* [out] */ long __RPC_FAR *pTop,
            /* [out] */ long __RPC_FAR *pWidth,
            /* [out] */ long __RPC_FAR *pHeight);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_BitmapDrawOffsetX )( 
            IWindowSkinner __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_BitmapDrawOffsetX )( 
            IWindowSkinner __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_BitmapDrawOffsetY )( 
            IWindowSkinner __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_BitmapDrawOffsetY )( 
            IWindowSkinner __RPC_FAR * This,
            /* [in] */ long newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Resizing )( 
            IWindowSkinner __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);
        
        END_INTERFACE
    } IWindowSkinnerVtbl;

    interface IWindowSkinner
    {
        CONST_VTBL struct IWindowSkinnerVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWindowSkinner_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IWindowSkinner_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IWindowSkinner_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IWindowSkinner_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IWindowSkinner_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IWindowSkinner_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IWindowSkinner_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IWindowSkinner_get_TransparentColor(This,pVal)	\
    (This)->lpVtbl -> get_TransparentColor(This,pVal)

#define IWindowSkinner_put_TransparentColor(This,newVal)	\
    (This)->lpVtbl -> put_TransparentColor(This,newVal)

#define IWindowSkinner_get_Picture(This,pVal)	\
    (This)->lpVtbl -> get_Picture(This,pVal)

#define IWindowSkinner_put_Picture(This,newVal)	\
    (This)->lpVtbl -> put_Picture(This,newVal)

#define IWindowSkinner_putref_Picture(This,newVal)	\
    (This)->lpVtbl -> putref_Picture(This,newVal)

#define IWindowSkinner_InfoForResize(This,nHorLineTop,nHorLineBottom,nVerLineLeft,nVerLineRight)	\
    (This)->lpVtbl -> InfoForResize(This,nHorLineTop,nHorLineBottom,nVerLineLeft,nVerLineRight)

#define IWindowSkinner_IndicateContainerChanged(This)	\
    (This)->lpVtbl -> IndicateContainerChanged(This)

#define IWindowSkinner_InfoForResizeGrip(This,nLeft,nTop,nRight,nBottom)	\
    (This)->lpVtbl -> InfoForResizeGrip(This,nLeft,nTop,nRight,nBottom)

#define IWindowSkinner_get_Dragging(This,pVal)	\
    (This)->lpVtbl -> get_Dragging(This,pVal)

#define IWindowSkinner_get_AllowDragMove(This,pVal)	\
    (This)->lpVtbl -> get_AllowDragMove(This,pVal)

#define IWindowSkinner_put_AllowDragMove(This,newVal)	\
    (This)->lpVtbl -> put_AllowDragMove(This,newVal)

#define IWindowSkinner_put_ParentHwnd(This,newVal)	\
    (This)->lpVtbl -> put_ParentHwnd(This,newVal)

#define IWindowSkinner_get_MinimumHeight(This,pVal)	\
    (This)->lpVtbl -> get_MinimumHeight(This,pVal)

#define IWindowSkinner_get_MinimumWidth(This,pVal)	\
    (This)->lpVtbl -> get_MinimumWidth(This,pVal)

#define IWindowSkinner_GetRgnBox(This,pLeft,pTop,pWidth,pHeight)	\
    (This)->lpVtbl -> GetRgnBox(This,pLeft,pTop,pWidth,pHeight)

#define IWindowSkinner_get_BitmapDrawOffsetX(This,pVal)	\
    (This)->lpVtbl -> get_BitmapDrawOffsetX(This,pVal)

#define IWindowSkinner_put_BitmapDrawOffsetX(This,newVal)	\
    (This)->lpVtbl -> put_BitmapDrawOffsetX(This,newVal)

#define IWindowSkinner_get_BitmapDrawOffsetY(This,pVal)	\
    (This)->lpVtbl -> get_BitmapDrawOffsetY(This,pVal)

#define IWindowSkinner_put_BitmapDrawOffsetY(This,newVal)	\
    (This)->lpVtbl -> put_BitmapDrawOffsetY(This,newVal)

#define IWindowSkinner_get_Resizing(This,pVal)	\
    (This)->lpVtbl -> get_Resizing(This,pVal)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IWindowSkinner_get_TransparentColor_Proxy( 
    IWindowSkinner __RPC_FAR * This,
    /* [retval][out] */ OLE_COLOR __RPC_FAR *pVal);


void __RPC_STUB IWindowSkinner_get_TransparentColor_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IWindowSkinner_put_TransparentColor_Proxy( 
    IWindowSkinner __RPC_FAR * This,
    /* [in] */ OLE_COLOR newVal);


void __RPC_STUB IWindowSkinner_put_TransparentColor_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IWindowSkinner_get_Picture_Proxy( 
    IWindowSkinner __RPC_FAR * This,
    /* [retval][out] */ IPictureDisp __RPC_FAR *__RPC_FAR *pVal);


void __RPC_STUB IWindowSkinner_get_Picture_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IWindowSkinner_put_Picture_Proxy( 
    IWindowSkinner __RPC_FAR * This,
    /* [in] */ IPictureDisp __RPC_FAR *newVal);


void __RPC_STUB IWindowSkinner_put_Picture_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [requestedit][bindable][helpstring][id][propputref] */ HRESULT STDMETHODCALLTYPE IWindowSkinner_putref_Picture_Proxy( 
    IWindowSkinner __RPC_FAR * This,
    /* [in] */ IPictureDisp __RPC_FAR *newVal);


void __RPC_STUB IWindowSkinner_putref_Picture_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IWindowSkinner_InfoForResize_Proxy( 
    IWindowSkinner __RPC_FAR * This,
    /* [in] */ long nHorLineTop,
    /* [in] */ long nHorLineBottom,
    /* [in] */ long nVerLineLeft,
    /* [in] */ long nVerLineRight);


void __RPC_STUB IWindowSkinner_InfoForResize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IWindowSkinner_IndicateContainerChanged_Proxy( 
    IWindowSkinner __RPC_FAR * This);


void __RPC_STUB IWindowSkinner_IndicateContainerChanged_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IWindowSkinner_InfoForResizeGrip_Proxy( 
    IWindowSkinner __RPC_FAR * This,
    /* [in] */ long nLeft,
    /* [in] */ long nTop,
    /* [in] */ long nRight,
    /* [in] */ long nBottom);


void __RPC_STUB IWindowSkinner_InfoForResizeGrip_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IWindowSkinner_get_Dragging_Proxy( 
    IWindowSkinner __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);


void __RPC_STUB IWindowSkinner_get_Dragging_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IWindowSkinner_get_AllowDragMove_Proxy( 
    IWindowSkinner __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);


void __RPC_STUB IWindowSkinner_get_AllowDragMove_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IWindowSkinner_put_AllowDragMove_Proxy( 
    IWindowSkinner __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL newVal);


void __RPC_STUB IWindowSkinner_put_AllowDragMove_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IWindowSkinner_put_ParentHwnd_Proxy( 
    IWindowSkinner __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IWindowSkinner_put_ParentHwnd_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IWindowSkinner_get_MinimumHeight_Proxy( 
    IWindowSkinner __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IWindowSkinner_get_MinimumHeight_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IWindowSkinner_get_MinimumWidth_Proxy( 
    IWindowSkinner __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IWindowSkinner_get_MinimumWidth_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IWindowSkinner_GetRgnBox_Proxy( 
    IWindowSkinner __RPC_FAR * This,
    /* [out] */ long __RPC_FAR *pLeft,
    /* [out] */ long __RPC_FAR *pTop,
    /* [out] */ long __RPC_FAR *pWidth,
    /* [out] */ long __RPC_FAR *pHeight);


void __RPC_STUB IWindowSkinner_GetRgnBox_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IWindowSkinner_get_BitmapDrawOffsetX_Proxy( 
    IWindowSkinner __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IWindowSkinner_get_BitmapDrawOffsetX_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IWindowSkinner_put_BitmapDrawOffsetX_Proxy( 
    IWindowSkinner __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IWindowSkinner_put_BitmapDrawOffsetX_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IWindowSkinner_get_BitmapDrawOffsetY_Proxy( 
    IWindowSkinner __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IWindowSkinner_get_BitmapDrawOffsetY_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IWindowSkinner_put_BitmapDrawOffsetY_Proxy( 
    IWindowSkinner __RPC_FAR * This,
    /* [in] */ long newVal);


void __RPC_STUB IWindowSkinner_put_BitmapDrawOffsetY_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IWindowSkinner_get_Resizing_Proxy( 
    IWindowSkinner __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);


void __RPC_STUB IWindowSkinner_get_Resizing_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IWindowSkinner_INTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_BitmapButtonBar;

#ifdef __cplusplus

class DECLSPEC_UUID("F00E1EF5-83A8-4DAC-B99E-82AE138EA959")
BitmapButtonBar;
#endif

EXTERN_C const CLSID CLSID_WindowSkinner;

#ifdef __cplusplus

class DECLSPEC_UUID("F4D720E4-AF5D-431A-8E14-44496792F0FB")
WindowSkinner;
#endif
#endif /* __WICKEDWIDGETSLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
