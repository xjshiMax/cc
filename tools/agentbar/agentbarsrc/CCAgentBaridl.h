

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.00.0603 */
/* at Tue Sep 18 14:31:48 2018
 */
/* Compiler settings for CCAgentBar.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 8.00.0603 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__


#ifndef __CCAgentBaridl_h__
#define __CCAgentBaridl_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef ___DCCAgentBar_FWD_DEFINED__
#define ___DCCAgentBar_FWD_DEFINED__
typedef interface _DCCAgentBar _DCCAgentBar;

#endif 	/* ___DCCAgentBar_FWD_DEFINED__ */


#ifndef ___DCCAgentBarEvents_FWD_DEFINED__
#define ___DCCAgentBarEvents_FWD_DEFINED__
typedef interface _DCCAgentBarEvents _DCCAgentBarEvents;

#endif 	/* ___DCCAgentBarEvents_FWD_DEFINED__ */


#ifndef __CCAgentBar_FWD_DEFINED__
#define __CCAgentBar_FWD_DEFINED__

#ifdef __cplusplus
typedef class CCAgentBar CCAgentBar;
#else
typedef struct CCAgentBar CCAgentBar;
#endif /* __cplusplus */

#endif 	/* __CCAgentBar_FWD_DEFINED__ */


#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_CCAgentBar_0000_0000 */
/* [local] */ 

#pragma once
#pragma region Desktop Family
#pragma endregion


extern RPC_IF_HANDLE __MIDL_itf_CCAgentBar_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_CCAgentBar_0000_0000_v0_0_s_ifspec;


#ifndef __CCAgentBarLib_LIBRARY_DEFINED__
#define __CCAgentBarLib_LIBRARY_DEFINED__

/* library CCAgentBarLib */
/* [control][helpstring][helpfile][version][uuid] */ 


EXTERN_C const IID LIBID_CCAgentBarLib;

#ifndef ___DCCAgentBar_DISPINTERFACE_DEFINED__
#define ___DCCAgentBar_DISPINTERFACE_DEFINED__

/* dispinterface _DCCAgentBar */
/* [helpstring][uuid] */ 


EXTERN_C const IID DIID__DCCAgentBar;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("72EA8ED1-D4EE-4FE9-9313-BB7257EC19B8")
    _DCCAgentBar : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _DCCAgentBarVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _DCCAgentBar * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _DCCAgentBar * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _DCCAgentBar * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _DCCAgentBar * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _DCCAgentBar * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _DCCAgentBar * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _DCCAgentBar * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        END_INTERFACE
    } _DCCAgentBarVtbl;

    interface _DCCAgentBar
    {
        CONST_VTBL struct _DCCAgentBarVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _DCCAgentBar_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _DCCAgentBar_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _DCCAgentBar_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _DCCAgentBar_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _DCCAgentBar_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _DCCAgentBar_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _DCCAgentBar_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___DCCAgentBar_DISPINTERFACE_DEFINED__ */


#ifndef ___DCCAgentBarEvents_DISPINTERFACE_DEFINED__
#define ___DCCAgentBarEvents_DISPINTERFACE_DEFINED__

/* dispinterface _DCCAgentBarEvents */
/* [helpstring][uuid] */ 


EXTERN_C const IID DIID__DCCAgentBarEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("7AE6BDA7-9F41-4C75-9F71-FF055A167DC2")
    _DCCAgentBarEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _DCCAgentBarEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _DCCAgentBarEvents * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _DCCAgentBarEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _DCCAgentBarEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _DCCAgentBarEvents * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _DCCAgentBarEvents * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _DCCAgentBarEvents * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _DCCAgentBarEvents * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        END_INTERFACE
    } _DCCAgentBarEventsVtbl;

    interface _DCCAgentBarEvents
    {
        CONST_VTBL struct _DCCAgentBarEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _DCCAgentBarEvents_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _DCCAgentBarEvents_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _DCCAgentBarEvents_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _DCCAgentBarEvents_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _DCCAgentBarEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _DCCAgentBarEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _DCCAgentBarEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___DCCAgentBarEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_CCAgentBar;

#ifdef __cplusplus

class DECLSPEC_UUID("6D4733B4-8E49-495C-9F2B-27606CEB20E3")
CCAgentBar;
#endif
#endif /* __CCAgentBarLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


