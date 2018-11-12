

/* this ALWAYS GENERATED file contains the IIDs and CLSIDs */

/* link this file in with the server and any clients */


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


#ifdef __cplusplus
extern "C"{
#endif 


#include <rpc.h>
#include <rpcndr.h>

#ifdef _MIDL_USE_GUIDDEF_

#ifndef INITGUID
#define INITGUID
#include <guiddef.h>
#undef INITGUID
#else
#include <guiddef.h>
#endif

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        DEFINE_GUID(name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8)

#else // !_MIDL_USE_GUIDDEF_

#ifndef __IID_DEFINED__
#define __IID_DEFINED__

typedef struct _IID
{
    unsigned long x;
    unsigned short s1;
    unsigned short s2;
    unsigned char  c[8];
} IID;

#endif // __IID_DEFINED__

#ifndef CLSID_DEFINED
#define CLSID_DEFINED
typedef IID CLSID;
#endif // CLSID_DEFINED

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        const type name = {l,w1,w2,{b1,b2,b3,b4,b5,b6,b7,b8}}

#endif !_MIDL_USE_GUIDDEF_

MIDL_DEFINE_GUID(IID, LIBID_CCAgentBarLib,0x0C996584,0x8882,0x4D08,0x9D,0x29,0x24,0xF1,0x8B,0x99,0x28,0xBA);


MIDL_DEFINE_GUID(IID, DIID__DCCAgentBar,0x72EA8ED1,0xD4EE,0x4FE9,0x93,0x13,0xBB,0x72,0x57,0xEC,0x19,0xB8);


MIDL_DEFINE_GUID(IID, DIID__DCCAgentBarEvents,0x7AE6BDA7,0x9F41,0x4C75,0x9F,0x71,0xFF,0x05,0x5A,0x16,0x7D,0xC2);


MIDL_DEFINE_GUID(CLSID, CLSID_CCAgentBar,0x6D4733B4,0x8E49,0x495C,0x9F,0x2B,0x27,0x60,0x6C,0xEB,0x20,0xE3);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif



