

/* this ALWAYS GENERATED file contains the RPC client stubs */


 /* File created by MIDL compiler version 8.00.0603 */
/* Compiler settings for WFPSamplerRPC.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 8.00.0603 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

#if !defined(_M_IA64) && !defined(_M_AMD64) && !defined(_ARM_)


#pragma warning( disable: 4049 )  /* more than 64k source lines */
#if _MSC_VER >= 1200
#pragma warning(push)
#endif

#pragma warning( disable: 4211 )  /* redefine extern to static */
#pragma warning( disable: 4232 )  /* dllimport identity*/
#pragma warning( disable: 4024 )  /* array to pointer mapping*/
#pragma warning( disable: 4100 ) /* unreferenced arguments in x86 call */

#pragma optimize("", off ) 

#include <string.h>

#include "WFPSamplerRPC.h"

#define TYPE_FORMAT_STRING_SIZE   1265                              
#define PROC_FORMAT_STRING_SIZE   569                               
#define EXPR_FORMAT_STRING_SIZE   33                                
#define TRANSMIT_AS_TABLE_SIZE    0            
#define WIRE_MARSHAL_TABLE_SIZE   0            

typedef struct _WFPSamplerRPC_MIDL_TYPE_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ TYPE_FORMAT_STRING_SIZE ];
    } WFPSamplerRPC_MIDL_TYPE_FORMAT_STRING;

typedef struct _WFPSamplerRPC_MIDL_PROC_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ PROC_FORMAT_STRING_SIZE ];
    } WFPSamplerRPC_MIDL_PROC_FORMAT_STRING;

typedef struct _WFPSamplerRPC_MIDL_EXPR_FORMAT_STRING
    {
    long          Pad;
    unsigned char  Format[ EXPR_FORMAT_STRING_SIZE ];
    } WFPSamplerRPC_MIDL_EXPR_FORMAT_STRING;


static const RPC_SYNTAX_IDENTIFIER  _RpcTransferSyntax = 
{{0x8A885D04,0x1CEB,0x11C9,{0x9F,0xE8,0x08,0x00,0x2B,0x10,0x48,0x60}},{2,0}};


extern const WFPSamplerRPC_MIDL_TYPE_FORMAT_STRING WFPSamplerRPC__MIDL_TypeFormatString;
extern const WFPSamplerRPC_MIDL_PROC_FORMAT_STRING WFPSamplerRPC__MIDL_ProcFormatString;
extern const WFPSamplerRPC_MIDL_EXPR_FORMAT_STRING WFPSamplerRPC__MIDL_ExprFormatString;

#define GENERIC_BINDING_TABLE_SIZE   0            


/* Standard interface: IWFPSampler, ver. 1.0,
   GUID={0x53504657,0x6D61,0x6C70,{0x65,0x72,0x5F,0x49,0x6E,0x74,0x65,0x72}} */

handle_t wfpSamplerBindingHandle;

static const RPC_PROTSEQ_ENDPOINT __RpcProtseqEndpoint[] = 
    {
    {(unsigned char *) "ncalrpc", (unsigned char *) "WFPSampler"}
    };


static const RPC_CLIENT_INTERFACE IWFPSampler___RpcClientInterface =
    {
    sizeof(RPC_CLIENT_INTERFACE),
    {{0x53504657,0x6D61,0x6C70,{0x65,0x72,0x5F,0x49,0x6E,0x74,0x65,0x72}},{1,0}},
    {{0x8A885D04,0x1CEB,0x11C9,{0x9F,0xE8,0x08,0x00,0x2B,0x10,0x48,0x60}},{2,0}},
    0,
    1,
    (RPC_PROTSEQ_ENDPOINT *)__RpcProtseqEndpoint,
    0,
    0,
    0x00000000
    };
RPC_IF_HANDLE IWFPSampler_v1_0_c_ifspec = (RPC_IF_HANDLE)& IWFPSampler___RpcClientInterface;

extern const MIDL_STUB_DESC IWFPSampler_StubDesc;

static RPC_BINDING_HANDLE IWFPSampler__MIDL_AutoBindHandle;


/* [fault_status][comm_status] */ error_status_t RPCInvokeScenarioAppContainer( 
    /* [in] */ handle_t rpcBindingHandle,
    /* [in] */ WFPSAMPLER_SCENARIO scenario,
    /* [in] */ FWPM_CHANGE_TYPE changeType,
    /* [in] */ BOOLEAN trustWSH,
    /* [in] */ BOOLEAN persistent,
    /* [in] */ BOOLEAN bootTime)
{

    CLIENT_CALL_RETURN _RetVal;

    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&IWFPSampler_StubDesc,
                  (PFORMAT_STRING) &WFPSamplerRPC__MIDL_ProcFormatString.Format[0],
                  ( unsigned char * )&rpcBindingHandle);
    return ( error_status_t  )_RetVal.Simple;
    
}


/* [fault_status][comm_status] */ error_status_t RPCInvokeScenarioBasicAction( 
    /* [in] */ handle_t rpcBindingHandle,
    /* [in] */ WFPSAMPLER_SCENARIO scenario,
    /* [in] */ FWPM_CHANGE_TYPE changeType,
    /* [ref][in] */ __RPC__in const FWPM_FILTER0 *pFilter,
    /* [unique][in] */ __RPC__in_opt const PC_BASIC_ACTION_DATA *pPCBasicActionData)
{

    CLIENT_CALL_RETURN _RetVal;

    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&IWFPSampler_StubDesc,
                  (PFORMAT_STRING) &WFPSamplerRPC__MIDL_ProcFormatString.Format[64],
                  ( unsigned char * )&rpcBindingHandle);
    return ( error_status_t  )_RetVal.Simple;
    
}


/* [fault_status][comm_status] */ error_status_t RPCInvokeScenarioBasicPacketExamination( 
    /* [in] */ handle_t rpcBindingHandle,
    /* [in] */ WFPSAMPLER_SCENARIO scenario,
    /* [in] */ FWPM_CHANGE_TYPE changeType,
    /* [ref][in] */ __RPC__in const FWPM_FILTER0 *pFilter)
{

    CLIENT_CALL_RETURN _RetVal;

    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&IWFPSampler_StubDesc,
                  (PFORMAT_STRING) &WFPSamplerRPC__MIDL_ProcFormatString.Format[122],
                  ( unsigned char * )&rpcBindingHandle);
    return ( error_status_t  )_RetVal.Simple;
    
}


/* [fault_status][comm_status] */ error_status_t RPCInvokeScenarioBasicPacketInjection( 
    /* [in] */ handle_t rpcBindingHandle,
    /* [in] */ WFPSAMPLER_SCENARIO scenario,
    /* [in] */ FWPM_CHANGE_TYPE changeType,
    /* [ref][in] */ __RPC__in const FWPM_FILTER0 *pFilter,
    /* [unique][in] */ __RPC__in_opt const PC_BASIC_PACKET_INJECTION_DATA *pPCBasicPacketInjectionData)
{

    CLIENT_CALL_RETURN _RetVal;

    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&IWFPSampler_StubDesc,
                  (PFORMAT_STRING) &WFPSamplerRPC__MIDL_ProcFormatString.Format[174],
                  ( unsigned char * )&rpcBindingHandle);
    return ( error_status_t  )_RetVal.Simple;
    
}


/* [fault_status][comm_status] */ error_status_t RPCInvokeScenarioBasicPacketModification( 
    /* [in] */ handle_t rpcBindingHandle,
    /* [in] */ WFPSAMPLER_SCENARIO scenario,
    /* [in] */ FWPM_CHANGE_TYPE changeType,
    /* [ref][in] */ __RPC__in const FWPM_FILTER0 *pFilter,
    /* [unique][in] */ __RPC__in_opt const PC_BASIC_PACKET_MODIFICATION_DATA *pPCBasicPacketModificationData)
{

    CLIENT_CALL_RETURN _RetVal;

    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&IWFPSampler_StubDesc,
                  (PFORMAT_STRING) &WFPSamplerRPC__MIDL_ProcFormatString.Format[232],
                  ( unsigned char * )&rpcBindingHandle);
    return ( error_status_t  )_RetVal.Simple;
    
}


/* [fault_status][comm_status] */ error_status_t RPCInvokeScenarioBasicStreamInjection( 
    /* [in] */ handle_t rpcBindingHandle,
    /* [in] */ WFPSAMPLER_SCENARIO scenario,
    /* [in] */ FWPM_CHANGE_TYPE changeType,
    /* [ref][in] */ __RPC__in const FWPM_FILTER0 *pFilter,
    /* [unique][in] */ __RPC__in_opt const PC_BASIC_STREAM_INJECTION_DATA *pPCBasicStreamInjectionData)
{

    CLIENT_CALL_RETURN _RetVal;

    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&IWFPSampler_StubDesc,
                  (PFORMAT_STRING) &WFPSamplerRPC__MIDL_ProcFormatString.Format[290],
                  ( unsigned char * )&rpcBindingHandle);
    return ( error_status_t  )_RetVal.Simple;
    
}


/* [fault_status][comm_status] */ error_status_t RPCInvokeScenarioFastPacketInjection( 
    /* [in] */ handle_t rpcBindingHandle,
    /* [in] */ WFPSAMPLER_SCENARIO scenario,
    /* [in] */ FWPM_CHANGE_TYPE changeType,
    /* [ref][in] */ __RPC__in const FWPM_FILTER0 *pFilter)
{

    CLIENT_CALL_RETURN _RetVal;

    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&IWFPSampler_StubDesc,
                  (PFORMAT_STRING) &WFPSamplerRPC__MIDL_ProcFormatString.Format[348],
                  ( unsigned char * )&rpcBindingHandle);
    return ( error_status_t  )_RetVal.Simple;
    
}


/* [fault_status][comm_status] */ error_status_t RPCInvokeScenarioFastStreamInjection( 
    /* [in] */ handle_t rpcBindingHandle,
    /* [in] */ WFPSAMPLER_SCENARIO scenario,
    /* [in] */ FWPM_CHANGE_TYPE changeType,
    /* [ref][in] */ __RPC__in const FWPM_FILTER0 *pFilter)
{

    CLIENT_CALL_RETURN _RetVal;

    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&IWFPSampler_StubDesc,
                  (PFORMAT_STRING) &WFPSamplerRPC__MIDL_ProcFormatString.Format[400],
                  ( unsigned char * )&rpcBindingHandle);
    return ( error_status_t  )_RetVal.Simple;
    
}


/* [fault_status][comm_status] */ error_status_t RPCInvokeScenarioPendAuthorization( 
    /* [in] */ handle_t rpcBindingHandle,
    /* [in] */ WFPSAMPLER_SCENARIO scenario,
    /* [in] */ FWPM_CHANGE_TYPE changeType,
    /* [ref][in] */ __RPC__in const FWPM_FILTER0 *pFilter,
    /* [unique][in] */ __RPC__in_opt const PC_PEND_AUTHORIZATION_DATA *pPCPendAuthorizationData)
{

    CLIENT_CALL_RETURN _RetVal;

    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&IWFPSampler_StubDesc,
                  (PFORMAT_STRING) &WFPSamplerRPC__MIDL_ProcFormatString.Format[452],
                  ( unsigned char * )&rpcBindingHandle);
    return ( error_status_t  )_RetVal.Simple;
    
}


/* [fault_status][comm_status] */ error_status_t RPCInvokeScenarioProxy( 
    /* [in] */ handle_t rpcBindingHandle,
    /* [in] */ WFPSAMPLER_SCENARIO scenario,
    /* [in] */ FWPM_CHANGE_TYPE changeType,
    /* [ref][in] */ __RPC__in const FWPM_FILTER0 *pFilter,
    /* [unique][in] */ __RPC__in_opt const PC_PROXY_DATA *pPCProxyData)
{

    CLIENT_CALL_RETURN _RetVal;

    _RetVal = NdrClientCall2(
                  ( PMIDL_STUB_DESC  )&IWFPSampler_StubDesc,
                  (PFORMAT_STRING) &WFPSamplerRPC__MIDL_ProcFormatString.Format[510],
                  ( unsigned char * )&rpcBindingHandle);
    return ( error_status_t  )_RetVal.Simple;
    
}


#if !defined(__RPC_WIN32__)
#error  Invalid build platform for this stub.
#endif
#if !(TARGET_IS_NT60_OR_LATER)
#error You need Windows Vista or later to run this stub because it uses these features:
#error   forced complex structure or array, uses type_strict_context_handle, compiled for Windows Vista.
#error However, your C/C++ compilation flags indicate you intend to run this app on earlier systems.
#error This app will fail with the RPC_X_WRONG_STUB_VERSION error.
#endif


static const WFPSamplerRPC_MIDL_PROC_FORMAT_STRING WFPSamplerRPC__MIDL_ProcFormatString =
    {
        0,
        {

	/* Procedure RPCInvokeScenarioAppContainer */

			0x0,		/* 0 */
			0x68,		/* Old Flags:  comm or fault/decode */
/*  2 */	NdrFcLong( 0x0 ),	/* 0 */
/*  6 */	NdrFcShort( 0x0 ),	/* 0 */
/*  8 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 10 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 12 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 14 */	NdrFcShort( 0x1d ),	/* 29 */
/* 16 */	NdrFcShort( 0x8 ),	/* 8 */
/* 18 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x6,		/* 6 */
/* 20 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 22 */	NdrFcShort( 0x0 ),	/* 0 */
/* 24 */	NdrFcShort( 0x0 ),	/* 0 */
/* 26 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter rpcBindingHandle */

/* 28 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 30 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 32 */	0xd,		/* FC_ENUM16 */
			0x0,		/* 0 */

	/* Parameter scenario */

/* 34 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 36 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 38 */	0xe,		/* FC_ENUM32 */
			0x0,		/* 0 */

	/* Parameter changeType */

/* 40 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 42 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 44 */	0x3,		/* FC_SMALL */
			0x0,		/* 0 */

	/* Parameter trustWSH */

/* 46 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 48 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 50 */	0x3,		/* FC_SMALL */
			0x0,		/* 0 */

	/* Parameter persistent */

/* 52 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 54 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 56 */	0x3,		/* FC_SMALL */
			0x0,		/* 0 */

	/* Parameter bootTime */

/* 58 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 60 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 62 */	0x10,		/* FC_ERROR_STATUS_T */
			0x0,		/* 0 */

	/* Procedure RPCInvokeScenarioBasicAction */


	/* Return value */

/* 64 */	0x0,		/* 0 */
			0x68,		/* Old Flags:  comm or fault/decode */
/* 66 */	NdrFcLong( 0x0 ),	/* 0 */
/* 70 */	NdrFcShort( 0x1 ),	/* 1 */
/* 72 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 74 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 76 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 78 */	NdrFcShort( 0x4a ),	/* 74 */
/* 80 */	NdrFcShort( 0x8 ),	/* 8 */
/* 82 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 84 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 86 */	NdrFcShort( 0x0 ),	/* 0 */
/* 88 */	NdrFcShort( 0x1 ),	/* 1 */
/* 90 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter rpcBindingHandle */

/* 92 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 94 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 96 */	0xd,		/* FC_ENUM16 */
			0x0,		/* 0 */

	/* Parameter scenario */

/* 98 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 100 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 102 */	0xe,		/* FC_ENUM32 */
			0x0,		/* 0 */

	/* Parameter changeType */

/* 104 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 106 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 108 */	NdrFcShort( 0x2f8 ),	/* Type Offset=760 */

	/* Parameter pFilter */

/* 110 */	NdrFcShort( 0xa ),	/* Flags:  must free, in, */
/* 112 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 114 */	NdrFcShort( 0x33a ),	/* Type Offset=826 */

	/* Parameter pPCBasicActionData */

/* 116 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 118 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 120 */	0x10,		/* FC_ERROR_STATUS_T */
			0x0,		/* 0 */

	/* Procedure RPCInvokeScenarioBasicPacketExamination */


	/* Return value */

/* 122 */	0x0,		/* 0 */
			0x68,		/* Old Flags:  comm or fault/decode */
/* 124 */	NdrFcLong( 0x0 ),	/* 0 */
/* 128 */	NdrFcShort( 0x2 ),	/* 2 */
/* 130 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 132 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 134 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 136 */	NdrFcShort( 0xe ),	/* 14 */
/* 138 */	NdrFcShort( 0x8 ),	/* 8 */
/* 140 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 142 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 144 */	NdrFcShort( 0x0 ),	/* 0 */
/* 146 */	NdrFcShort( 0x1 ),	/* 1 */
/* 148 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter rpcBindingHandle */

/* 150 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 152 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 154 */	0xd,		/* FC_ENUM16 */
			0x0,		/* 0 */

	/* Parameter scenario */

/* 156 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 158 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 160 */	0xe,		/* FC_ENUM32 */
			0x0,		/* 0 */

	/* Parameter changeType */

/* 162 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 164 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 166 */	NdrFcShort( 0x2f8 ),	/* Type Offset=760 */

	/* Parameter pFilter */

/* 168 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 170 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 172 */	0x10,		/* FC_ERROR_STATUS_T */
			0x0,		/* 0 */

	/* Procedure RPCInvokeScenarioBasicPacketInjection */


	/* Return value */

/* 174 */	0x0,		/* 0 */
			0x68,		/* Old Flags:  comm or fault/decode */
/* 176 */	NdrFcLong( 0x0 ),	/* 0 */
/* 180 */	NdrFcShort( 0x3 ),	/* 3 */
/* 182 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 184 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 186 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 188 */	NdrFcShort( 0x4a ),	/* 74 */
/* 190 */	NdrFcShort( 0x8 ),	/* 8 */
/* 192 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 194 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 196 */	NdrFcShort( 0x0 ),	/* 0 */
/* 198 */	NdrFcShort( 0x1 ),	/* 1 */
/* 200 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter rpcBindingHandle */

/* 202 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 204 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 206 */	0xd,		/* FC_ENUM16 */
			0x0,		/* 0 */

	/* Parameter scenario */

/* 208 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 210 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 212 */	0xe,		/* FC_ENUM32 */
			0x0,		/* 0 */

	/* Parameter changeType */

/* 214 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 216 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 218 */	NdrFcShort( 0x2f8 ),	/* Type Offset=760 */

	/* Parameter pFilter */

/* 220 */	NdrFcShort( 0xa ),	/* Flags:  must free, in, */
/* 222 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 224 */	NdrFcShort( 0x350 ),	/* Type Offset=848 */

	/* Parameter pPCBasicPacketInjectionData */

/* 226 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 228 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 230 */	0x10,		/* FC_ERROR_STATUS_T */
			0x0,		/* 0 */

	/* Procedure RPCInvokeScenarioBasicPacketModification */


	/* Return value */

/* 232 */	0x0,		/* 0 */
			0x68,		/* Old Flags:  comm or fault/decode */
/* 234 */	NdrFcLong( 0x0 ),	/* 0 */
/* 238 */	NdrFcShort( 0x4 ),	/* 4 */
/* 240 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 242 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 244 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 246 */	NdrFcShort( 0xe ),	/* 14 */
/* 248 */	NdrFcShort( 0x8 ),	/* 8 */
/* 250 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 252 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 254 */	NdrFcShort( 0x0 ),	/* 0 */
/* 256 */	NdrFcShort( 0x1 ),	/* 1 */
/* 258 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter rpcBindingHandle */

/* 260 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 262 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 264 */	0xd,		/* FC_ENUM16 */
			0x0,		/* 0 */

	/* Parameter scenario */

/* 266 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 268 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 270 */	0xe,		/* FC_ENUM32 */
			0x0,		/* 0 */

	/* Parameter changeType */

/* 272 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 274 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 276 */	NdrFcShort( 0x2f8 ),	/* Type Offset=760 */

	/* Parameter pFilter */

/* 278 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 280 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 282 */	NdrFcShort( 0x360 ),	/* Type Offset=864 */

	/* Parameter pPCBasicPacketModificationData */

/* 284 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 286 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 288 */	0x10,		/* FC_ERROR_STATUS_T */
			0x0,		/* 0 */

	/* Procedure RPCInvokeScenarioBasicStreamInjection */


	/* Return value */

/* 290 */	0x0,		/* 0 */
			0x68,		/* Old Flags:  comm or fault/decode */
/* 292 */	NdrFcLong( 0x0 ),	/* 0 */
/* 296 */	NdrFcShort( 0x5 ),	/* 5 */
/* 298 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 300 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 302 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 304 */	NdrFcShort( 0x4a ),	/* 74 */
/* 306 */	NdrFcShort( 0x8 ),	/* 8 */
/* 308 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 310 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 312 */	NdrFcShort( 0x0 ),	/* 0 */
/* 314 */	NdrFcShort( 0x1 ),	/* 1 */
/* 316 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter rpcBindingHandle */

/* 318 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 320 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 322 */	0xd,		/* FC_ENUM16 */
			0x0,		/* 0 */

	/* Parameter scenario */

/* 324 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 326 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 328 */	0xe,		/* FC_ENUM32 */
			0x0,		/* 0 */

	/* Parameter changeType */

/* 330 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 332 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 334 */	NdrFcShort( 0x2f8 ),	/* Type Offset=760 */

	/* Parameter pFilter */

/* 336 */	NdrFcShort( 0xa ),	/* Flags:  must free, in, */
/* 338 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 340 */	NdrFcShort( 0x350 ),	/* Type Offset=848 */

	/* Parameter pPCBasicStreamInjectionData */

/* 342 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 344 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 346 */	0x10,		/* FC_ERROR_STATUS_T */
			0x0,		/* 0 */

	/* Procedure RPCInvokeScenarioFastPacketInjection */


	/* Return value */

/* 348 */	0x0,		/* 0 */
			0x68,		/* Old Flags:  comm or fault/decode */
/* 350 */	NdrFcLong( 0x0 ),	/* 0 */
/* 354 */	NdrFcShort( 0x6 ),	/* 6 */
/* 356 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 358 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 360 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 362 */	NdrFcShort( 0xe ),	/* 14 */
/* 364 */	NdrFcShort( 0x8 ),	/* 8 */
/* 366 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 368 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 370 */	NdrFcShort( 0x0 ),	/* 0 */
/* 372 */	NdrFcShort( 0x1 ),	/* 1 */
/* 374 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter rpcBindingHandle */

/* 376 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 378 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 380 */	0xd,		/* FC_ENUM16 */
			0x0,		/* 0 */

	/* Parameter scenario */

/* 382 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 384 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 386 */	0xe,		/* FC_ENUM32 */
			0x0,		/* 0 */

	/* Parameter changeType */

/* 388 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 390 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 392 */	NdrFcShort( 0x2f8 ),	/* Type Offset=760 */

	/* Parameter pFilter */

/* 394 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 396 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 398 */	0x10,		/* FC_ERROR_STATUS_T */
			0x0,		/* 0 */

	/* Procedure RPCInvokeScenarioFastStreamInjection */


	/* Return value */

/* 400 */	0x0,		/* 0 */
			0x68,		/* Old Flags:  comm or fault/decode */
/* 402 */	NdrFcLong( 0x0 ),	/* 0 */
/* 406 */	NdrFcShort( 0x7 ),	/* 7 */
/* 408 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 410 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 412 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 414 */	NdrFcShort( 0xe ),	/* 14 */
/* 416 */	NdrFcShort( 0x8 ),	/* 8 */
/* 418 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 420 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 422 */	NdrFcShort( 0x0 ),	/* 0 */
/* 424 */	NdrFcShort( 0x1 ),	/* 1 */
/* 426 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter rpcBindingHandle */

/* 428 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 430 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 432 */	0xd,		/* FC_ENUM16 */
			0x0,		/* 0 */

	/* Parameter scenario */

/* 434 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 436 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 438 */	0xe,		/* FC_ENUM32 */
			0x0,		/* 0 */

	/* Parameter changeType */

/* 440 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 442 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 444 */	NdrFcShort( 0x2f8 ),	/* Type Offset=760 */

	/* Parameter pFilter */

/* 446 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 448 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 450 */	0x10,		/* FC_ERROR_STATUS_T */
			0x0,		/* 0 */

	/* Procedure RPCInvokeScenarioPendAuthorization */


	/* Return value */

/* 452 */	0x0,		/* 0 */
			0x68,		/* Old Flags:  comm or fault/decode */
/* 454 */	NdrFcLong( 0x0 ),	/* 0 */
/* 458 */	NdrFcShort( 0x8 ),	/* 8 */
/* 460 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 462 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 464 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 466 */	NdrFcShort( 0x52 ),	/* 82 */
/* 468 */	NdrFcShort( 0x8 ),	/* 8 */
/* 470 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 472 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 474 */	NdrFcShort( 0x0 ),	/* 0 */
/* 476 */	NdrFcShort( 0x1 ),	/* 1 */
/* 478 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter rpcBindingHandle */

/* 480 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 482 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 484 */	0xd,		/* FC_ENUM16 */
			0x0,		/* 0 */

	/* Parameter scenario */

/* 486 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 488 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 490 */	0xe,		/* FC_ENUM32 */
			0x0,		/* 0 */

	/* Parameter changeType */

/* 492 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 494 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 496 */	NdrFcShort( 0x2f8 ),	/* Type Offset=760 */

	/* Parameter pFilter */

/* 498 */	NdrFcShort( 0xa ),	/* Flags:  must free, in, */
/* 500 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 502 */	NdrFcShort( 0x474 ),	/* Type Offset=1140 */

	/* Parameter pPCPendAuthorizationData */

/* 504 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 506 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 508 */	0x10,		/* FC_ERROR_STATUS_T */
			0x0,		/* 0 */

	/* Procedure RPCInvokeScenarioProxy */


	/* Return value */

/* 510 */	0x0,		/* 0 */
			0x68,		/* Old Flags:  comm or fault/decode */
/* 512 */	NdrFcLong( 0x0 ),	/* 0 */
/* 516 */	NdrFcShort( 0x9 ),	/* 9 */
/* 518 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 520 */	0x32,		/* FC_BIND_PRIMITIVE */
			0x0,		/* 0 */
/* 522 */	NdrFcShort( 0x0 ),	/* x86 Stack size/offset = 0 */
/* 524 */	NdrFcShort( 0xe ),	/* 14 */
/* 526 */	NdrFcShort( 0x8 ),	/* 8 */
/* 528 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 530 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 532 */	NdrFcShort( 0x0 ),	/* 0 */
/* 534 */	NdrFcShort( 0x1 ),	/* 1 */
/* 536 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter rpcBindingHandle */

/* 538 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 540 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 542 */	0xd,		/* FC_ENUM16 */
			0x0,		/* 0 */

	/* Parameter scenario */

/* 544 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 546 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 548 */	0xe,		/* FC_ENUM32 */
			0x0,		/* 0 */

	/* Parameter changeType */

/* 550 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 552 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 554 */	NdrFcShort( 0x2f8 ),	/* Type Offset=760 */

	/* Parameter pFilter */

/* 556 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 558 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 560 */	NdrFcShort( 0x48c ),	/* Type Offset=1164 */

	/* Parameter pPCProxyData */

/* 562 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 564 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 566 */	0x10,		/* FC_ERROR_STATUS_T */
			0x0,		/* 0 */

			0x0
        }
    };

static const WFPSamplerRPC_MIDL_TYPE_FORMAT_STRING WFPSamplerRPC__MIDL_TypeFormatString =
    {
        0,
        {
			NdrFcShort( 0x0 ),	/* 0 */
/*  2 */	
			0x11, 0x0,	/* FC_RP */
/*  4 */	NdrFcShort( 0x2f4 ),	/* Offset= 756 (760) */
/*  6 */	
			0x1d,		/* FC_SMFARRAY */
			0x0,		/* 0 */
/*  8 */	NdrFcShort( 0x8 ),	/* 8 */
/* 10 */	0x1,		/* FC_BYTE */
			0x5b,		/* FC_END */
/* 12 */	
			0x15,		/* FC_STRUCT */
			0x3,		/* 3 */
/* 14 */	NdrFcShort( 0x10 ),	/* 16 */
/* 16 */	0x8,		/* FC_LONG */
			0x6,		/* FC_SHORT */
/* 18 */	0x6,		/* FC_SHORT */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 20 */	0x0,		/* 0 */
			NdrFcShort( 0xfff1 ),	/* Offset= -15 (6) */
			0x5b,		/* FC_END */
/* 24 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 26 */	NdrFcShort( 0x8 ),	/* 8 */
/* 28 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 30 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 32 */	NdrFcShort( 0x0 ),	/* 0 */
/* 34 */	NdrFcShort( 0x0 ),	/* 0 */
/* 36 */	0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 38 */	
			0x25,		/* FC_C_WSTRING */
			0x5c,		/* FC_PAD */
/* 40 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 42 */	NdrFcShort( 0x4 ),	/* 4 */
/* 44 */	NdrFcShort( 0x4 ),	/* 4 */
/* 46 */	0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 48 */	
			0x25,		/* FC_C_WSTRING */
			0x5c,		/* FC_PAD */
/* 50 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 52 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 54 */	
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 56 */	NdrFcShort( 0x1 ),	/* 1 */
/* 58 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 60 */	NdrFcShort( 0x0 ),	/* 0 */
/* 62 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 64 */	0x2,		/* FC_CHAR */
			0x5b,		/* FC_END */
/* 66 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 68 */	NdrFcShort( 0x8 ),	/* 8 */
/* 70 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 72 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 74 */	NdrFcShort( 0x4 ),	/* 4 */
/* 76 */	NdrFcShort( 0x4 ),	/* 4 */
/* 78 */	0x12, 0x20,	/* FC_UP [maybenull_sizeis] */
/* 80 */	NdrFcShort( 0xffe6 ),	/* Offset= -26 (54) */
/* 82 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 84 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 86 */	
			0x2b,		/* FC_NON_ENCAPSULATED_UNION */
			0x8,		/* FC_LONG */
/* 88 */	0x8,		/* Corr desc: FC_LONG */
			0x0,		/*  */
/* 90 */	NdrFcShort( 0xfffc ),	/* -4 */
/* 92 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 94 */	NdrFcShort( 0x2 ),	/* Offset= 2 (96) */
/* 96 */	NdrFcShort( 0x4 ),	/* 4 */
/* 98 */	NdrFcShort( 0x13 ),	/* 19 */
/* 100 */	NdrFcLong( 0x0 ),	/* 0 */
/* 104 */	NdrFcShort( 0x0 ),	/* Offset= 0 (104) */
/* 106 */	NdrFcLong( 0x1 ),	/* 1 */
/* 110 */	NdrFcShort( 0x8002 ),	/* Simple arm type: FC_CHAR */
/* 112 */	NdrFcLong( 0x2 ),	/* 2 */
/* 116 */	NdrFcShort( 0x8006 ),	/* Simple arm type: FC_SHORT */
/* 118 */	NdrFcLong( 0x3 ),	/* 3 */
/* 122 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 124 */	NdrFcLong( 0x4 ),	/* 4 */
/* 128 */	NdrFcShort( 0x58 ),	/* Offset= 88 (216) */
/* 130 */	NdrFcLong( 0x5 ),	/* 5 */
/* 134 */	NdrFcShort( 0x8002 ),	/* Simple arm type: FC_CHAR */
/* 136 */	NdrFcLong( 0x6 ),	/* 6 */
/* 140 */	NdrFcShort( 0x8006 ),	/* Simple arm type: FC_SHORT */
/* 142 */	NdrFcLong( 0x7 ),	/* 7 */
/* 146 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 148 */	NdrFcLong( 0x8 ),	/* 8 */
/* 152 */	NdrFcShort( 0x40 ),	/* Offset= 64 (216) */
/* 154 */	NdrFcLong( 0x9 ),	/* 9 */
/* 158 */	NdrFcShort( 0x800a ),	/* Simple arm type: FC_FLOAT */
/* 160 */	NdrFcLong( 0xa ),	/* 10 */
/* 164 */	NdrFcShort( 0x38 ),	/* Offset= 56 (220) */
/* 166 */	NdrFcLong( 0xb ),	/* 11 */
/* 170 */	NdrFcShort( 0x36 ),	/* Offset= 54 (224) */
/* 172 */	NdrFcLong( 0xc ),	/* 12 */
/* 176 */	NdrFcShort( 0x44 ),	/* Offset= 68 (244) */
/* 178 */	NdrFcLong( 0xd ),	/* 13 */
/* 182 */	NdrFcShort( 0x42 ),	/* Offset= 66 (248) */
/* 184 */	NdrFcLong( 0xe ),	/* 14 */
/* 188 */	NdrFcShort( 0x38 ),	/* Offset= 56 (244) */
/* 190 */	NdrFcLong( 0xf ),	/* 15 */
/* 194 */	NdrFcShort( 0x64 ),	/* Offset= 100 (294) */
/* 196 */	NdrFcLong( 0x10 ),	/* 16 */
/* 200 */	NdrFcShort( 0x2c ),	/* Offset= 44 (244) */
/* 202 */	NdrFcLong( 0x11 ),	/* 17 */
/* 206 */	NdrFcShort( 0xd4 ),	/* Offset= 212 (418) */
/* 208 */	NdrFcLong( 0x12 ),	/* 18 */
/* 212 */	NdrFcShort( 0xd2 ),	/* Offset= 210 (422) */
/* 214 */	NdrFcShort( 0xffff ),	/* Offset= -1 (213) */
/* 216 */	
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 218 */	0xb,		/* FC_HYPER */
			0x5c,		/* FC_PAD */
/* 220 */	
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 222 */	0xc,		/* FC_DOUBLE */
			0x5c,		/* FC_PAD */
/* 224 */	
			0x12, 0x0,	/* FC_UP */
/* 226 */	NdrFcShort( 0x8 ),	/* Offset= 8 (234) */
/* 228 */	
			0x1d,		/* FC_SMFARRAY */
			0x0,		/* 0 */
/* 230 */	NdrFcShort( 0x10 ),	/* 16 */
/* 232 */	0x2,		/* FC_CHAR */
			0x5b,		/* FC_END */
/* 234 */	
			0x15,		/* FC_STRUCT */
			0x0,		/* 0 */
/* 236 */	NdrFcShort( 0x10 ),	/* 16 */
/* 238 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 240 */	NdrFcShort( 0xfff4 ),	/* Offset= -12 (228) */
/* 242 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 244 */	
			0x12, 0x0,	/* FC_UP */
/* 246 */	NdrFcShort( 0xff4c ),	/* Offset= -180 (66) */
/* 248 */	
			0x12, 0x0,	/* FC_UP */
/* 250 */	NdrFcShort( 0x1e ),	/* Offset= 30 (280) */
/* 252 */	
			0x1d,		/* FC_SMFARRAY */
			0x0,		/* 0 */
/* 254 */	NdrFcShort( 0x6 ),	/* 6 */
/* 256 */	0x2,		/* FC_CHAR */
			0x5b,		/* FC_END */
/* 258 */	
			0x15,		/* FC_STRUCT */
			0x0,		/* 0 */
/* 260 */	NdrFcShort( 0x6 ),	/* 6 */
/* 262 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 264 */	NdrFcShort( 0xfff4 ),	/* Offset= -12 (252) */
/* 266 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 268 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 270 */	NdrFcShort( 0x4 ),	/* 4 */
/* 272 */	0x3,		/* Corr desc: FC_SMALL */
			0x0,		/*  */
/* 274 */	NdrFcShort( 0xfff9 ),	/* -7 */
/* 276 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 278 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 280 */	
			0x17,		/* FC_CSTRUCT */
			0x3,		/* 3 */
/* 282 */	NdrFcShort( 0x8 ),	/* 8 */
/* 284 */	NdrFcShort( 0xfff0 ),	/* Offset= -16 (268) */
/* 286 */	0x1,		/* FC_BYTE */
			0x1,		/* FC_BYTE */
/* 288 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 290 */	NdrFcShort( 0xffe0 ),	/* Offset= -32 (258) */
/* 292 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 294 */	
			0x12, 0x0,	/* FC_UP */
/* 296 */	NdrFcShort( 0x5a ),	/* Offset= 90 (386) */
/* 298 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 300 */	NdrFcShort( 0x8 ),	/* 8 */
/* 302 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 304 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 306 */	NdrFcShort( 0x0 ),	/* 0 */
/* 308 */	NdrFcShort( 0x0 ),	/* 0 */
/* 310 */	0x11, 0x0,	/* FC_RP */
/* 312 */	NdrFcShort( 0xffe0 ),	/* Offset= -32 (280) */
/* 314 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 316 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 318 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 320 */	NdrFcShort( 0x8 ),	/* 8 */
/* 322 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 324 */	NdrFcShort( 0x0 ),	/* 0 */
/* 326 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 328 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 330 */	
			0x48,		/* FC_VARIABLE_REPEAT */
			0x49,		/* FC_FIXED_OFFSET */
/* 332 */	NdrFcShort( 0x8 ),	/* 8 */
/* 334 */	NdrFcShort( 0x0 ),	/* 0 */
/* 336 */	NdrFcShort( 0x1 ),	/* 1 */
/* 338 */	NdrFcShort( 0x0 ),	/* 0 */
/* 340 */	NdrFcShort( 0x0 ),	/* 0 */
/* 342 */	0x11, 0x0,	/* FC_RP */
/* 344 */	NdrFcShort( 0xffc0 ),	/* Offset= -64 (280) */
/* 346 */	
			0x5b,		/* FC_END */

			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 348 */	0x0,		/* 0 */
			NdrFcShort( 0xffcd ),	/* Offset= -51 (298) */
			0x5b,		/* FC_END */
/* 352 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 354 */	NdrFcShort( 0x8 ),	/* 8 */
/* 356 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 358 */	NdrFcShort( 0x8 ),	/* 8 */
/* 360 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 362 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 364 */	
			0x48,		/* FC_VARIABLE_REPEAT */
			0x49,		/* FC_FIXED_OFFSET */
/* 366 */	NdrFcShort( 0x8 ),	/* 8 */
/* 368 */	NdrFcShort( 0x0 ),	/* 0 */
/* 370 */	NdrFcShort( 0x1 ),	/* 1 */
/* 372 */	NdrFcShort( 0x0 ),	/* 0 */
/* 374 */	NdrFcShort( 0x0 ),	/* 0 */
/* 376 */	0x11, 0x0,	/* FC_RP */
/* 378 */	NdrFcShort( 0xff9e ),	/* Offset= -98 (280) */
/* 380 */	
			0x5b,		/* FC_END */

			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 382 */	0x0,		/* 0 */
			NdrFcShort( 0xffab ),	/* Offset= -85 (298) */
			0x5b,		/* FC_END */
/* 386 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 388 */	NdrFcShort( 0x10 ),	/* 16 */
/* 390 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 392 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 394 */	NdrFcShort( 0x4 ),	/* 4 */
/* 396 */	NdrFcShort( 0x4 ),	/* 4 */
/* 398 */	0x11, 0x0,	/* FC_RP */
/* 400 */	NdrFcShort( 0xffae ),	/* Offset= -82 (318) */
/* 402 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 404 */	NdrFcShort( 0xc ),	/* 12 */
/* 406 */	NdrFcShort( 0xc ),	/* 12 */
/* 408 */	0x11, 0x0,	/* FC_RP */
/* 410 */	NdrFcShort( 0xffc6 ),	/* Offset= -58 (352) */
/* 412 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 414 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 416 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 418 */	
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 420 */	
			0x25,		/* FC_C_WSTRING */
			0x5c,		/* FC_PAD */
/* 422 */	
			0x12, 0x0,	/* FC_UP */
/* 424 */	NdrFcShort( 0xff5a ),	/* Offset= -166 (258) */
/* 426 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 428 */	NdrFcShort( 0x8 ),	/* 8 */
/* 430 */	NdrFcShort( 0x0 ),	/* 0 */
/* 432 */	NdrFcShort( 0x0 ),	/* Offset= 0 (432) */
/* 434 */	0xe,		/* FC_ENUM32 */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 436 */	0x0,		/* 0 */
			NdrFcShort( 0xfea1 ),	/* Offset= -351 (86) */
			0x5b,		/* FC_END */
/* 440 */	
			0x2b,		/* FC_NON_ENCAPSULATED_UNION */
			0x9,		/* FC_ULONG */
/* 442 */	0x0,		/* Corr desc:  field,  */
			0x5d,		/* FC_EXPR */
/* 444 */	NdrFcShort( 0x0 ),	/* 0 */
/* 446 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 448 */	NdrFcShort( 0x2 ),	/* Offset= 2 (450) */
/* 450 */	NdrFcShort( 0x10 ),	/* 16 */
/* 452 */	NdrFcShort( 0x2 ),	/* 2 */
/* 454 */	NdrFcLong( 0x0 ),	/* 0 */
/* 458 */	NdrFcShort( 0xfe42 ),	/* Offset= -446 (12) */
/* 460 */	NdrFcLong( 0x4000 ),	/* 16384 */
/* 464 */	NdrFcShort( 0xfe3c ),	/* Offset= -452 (12) */
/* 466 */	NdrFcShort( 0xffff ),	/* Offset= -1 (465) */
/* 468 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 470 */	NdrFcShort( 0x14 ),	/* 20 */
/* 472 */	NdrFcShort( 0x0 ),	/* 0 */
/* 474 */	NdrFcShort( 0x0 ),	/* Offset= 0 (474) */
/* 476 */	0x8,		/* FC_LONG */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 478 */	0x0,		/* 0 */
			NdrFcShort( 0xffd9 ),	/* Offset= -39 (440) */
			0x5b,		/* FC_END */
/* 482 */	
			0x2b,		/* FC_NON_ENCAPSULATED_UNION */
			0x9,		/* FC_ULONG */
/* 484 */	0x0,		/* Corr desc:  field,  */
			0x5d,		/* FC_EXPR */
/* 486 */	NdrFcShort( 0x1 ),	/* 1 */
/* 488 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 490 */	NdrFcShort( 0x2 ),	/* Offset= 2 (492) */
/* 492 */	NdrFcShort( 0x10 ),	/* 16 */
/* 494 */	NdrFcShort( 0x2 ),	/* 2 */
/* 496 */	NdrFcLong( 0x0 ),	/* 0 */
/* 500 */	NdrFcShort( 0x800b ),	/* Simple arm type: FC_HYPER */
/* 502 */	NdrFcLong( 0x4 ),	/* 4 */
/* 506 */	NdrFcShort( 0xfe12 ),	/* Offset= -494 (12) */
/* 508 */	NdrFcShort( 0xffff ),	/* Offset= -1 (507) */
/* 510 */	
			0x2b,		/* FC_NON_ENCAPSULATED_UNION */
			0x8,		/* FC_LONG */
/* 512 */	0x8,		/* Corr desc: FC_LONG */
			0x0,		/*  */
/* 514 */	NdrFcShort( 0xfffc ),	/* -4 */
/* 516 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 518 */	NdrFcShort( 0x2 ),	/* Offset= 2 (520) */
/* 520 */	NdrFcShort( 0x4 ),	/* 4 */
/* 522 */	NdrFcShort( 0x16 ),	/* 22 */
/* 524 */	NdrFcLong( 0x0 ),	/* 0 */
/* 528 */	NdrFcShort( 0x0 ),	/* Offset= 0 (528) */
/* 530 */	NdrFcLong( 0x1 ),	/* 1 */
/* 534 */	NdrFcShort( 0x8002 ),	/* Simple arm type: FC_CHAR */
/* 536 */	NdrFcLong( 0x2 ),	/* 2 */
/* 540 */	NdrFcShort( 0x8006 ),	/* Simple arm type: FC_SHORT */
/* 542 */	NdrFcLong( 0x3 ),	/* 3 */
/* 546 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 548 */	NdrFcLong( 0x4 ),	/* 4 */
/* 552 */	NdrFcShort( 0xfeb0 ),	/* Offset= -336 (216) */
/* 554 */	NdrFcLong( 0x5 ),	/* 5 */
/* 558 */	NdrFcShort( 0x8002 ),	/* Simple arm type: FC_CHAR */
/* 560 */	NdrFcLong( 0x6 ),	/* 6 */
/* 564 */	NdrFcShort( 0x8006 ),	/* Simple arm type: FC_SHORT */
/* 566 */	NdrFcLong( 0x7 ),	/* 7 */
/* 570 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 572 */	NdrFcLong( 0x8 ),	/* 8 */
/* 576 */	NdrFcShort( 0xfe98 ),	/* Offset= -360 (216) */
/* 578 */	NdrFcLong( 0x9 ),	/* 9 */
/* 582 */	NdrFcShort( 0x800a ),	/* Simple arm type: FC_FLOAT */
/* 584 */	NdrFcLong( 0xa ),	/* 10 */
/* 588 */	NdrFcShort( 0xfe90 ),	/* Offset= -368 (220) */
/* 590 */	NdrFcLong( 0xb ),	/* 11 */
/* 594 */	NdrFcShort( 0xfe8e ),	/* Offset= -370 (224) */
/* 596 */	NdrFcLong( 0xc ),	/* 12 */
/* 600 */	NdrFcShort( 0xfe9c ),	/* Offset= -356 (244) */
/* 602 */	NdrFcLong( 0xd ),	/* 13 */
/* 606 */	NdrFcShort( 0xfe9a ),	/* Offset= -358 (248) */
/* 608 */	NdrFcLong( 0xe ),	/* 14 */
/* 612 */	NdrFcShort( 0xfe90 ),	/* Offset= -368 (244) */
/* 614 */	NdrFcLong( 0xf ),	/* 15 */
/* 618 */	NdrFcShort( 0xfebc ),	/* Offset= -324 (294) */
/* 620 */	NdrFcLong( 0x10 ),	/* 16 */
/* 624 */	NdrFcShort( 0xfe84 ),	/* Offset= -380 (244) */
/* 626 */	NdrFcLong( 0x11 ),	/* 17 */
/* 630 */	NdrFcShort( 0xff2c ),	/* Offset= -212 (418) */
/* 632 */	NdrFcLong( 0x12 ),	/* 18 */
/* 636 */	NdrFcShort( 0xff2a ),	/* Offset= -214 (422) */
/* 638 */	NdrFcLong( 0x100 ),	/* 256 */
/* 642 */	NdrFcShort( 0x10 ),	/* Offset= 16 (658) */
/* 644 */	NdrFcLong( 0x101 ),	/* 257 */
/* 648 */	NdrFcShort( 0x16 ),	/* Offset= 22 (670) */
/* 650 */	NdrFcLong( 0x102 ),	/* 258 */
/* 654 */	NdrFcShort( 0x1e ),	/* Offset= 30 (684) */
/* 656 */	NdrFcShort( 0xffff ),	/* Offset= -1 (655) */
/* 658 */	
			0x12, 0x0,	/* FC_UP */
/* 660 */	NdrFcShort( 0x2 ),	/* Offset= 2 (662) */
/* 662 */	
			0x15,		/* FC_STRUCT */
			0x3,		/* 3 */
/* 664 */	NdrFcShort( 0x8 ),	/* 8 */
/* 666 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 668 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 670 */	
			0x12, 0x0,	/* FC_UP */
/* 672 */	NdrFcShort( 0x2 ),	/* Offset= 2 (674) */
/* 674 */	
			0x15,		/* FC_STRUCT */
			0x0,		/* 0 */
/* 676 */	NdrFcShort( 0x11 ),	/* 17 */
/* 678 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 680 */	NdrFcShort( 0xfe3c ),	/* Offset= -452 (228) */
/* 682 */	0x2,		/* FC_CHAR */
			0x5b,		/* FC_END */
/* 684 */	
			0x12, 0x0,	/* FC_UP */
/* 686 */	NdrFcShort( 0x2 ),	/* Offset= 2 (688) */
/* 688 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 690 */	NdrFcShort( 0x10 ),	/* 16 */
/* 692 */	NdrFcShort( 0x0 ),	/* 0 */
/* 694 */	NdrFcShort( 0x0 ),	/* Offset= 0 (694) */
/* 696 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 698 */	NdrFcShort( 0xfef0 ),	/* Offset= -272 (426) */
/* 700 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 702 */	NdrFcShort( 0xfeec ),	/* Offset= -276 (426) */
/* 704 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 706 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 708 */	NdrFcShort( 0x8 ),	/* 8 */
/* 710 */	NdrFcShort( 0x0 ),	/* 0 */
/* 712 */	NdrFcShort( 0x0 ),	/* Offset= 0 (712) */
/* 714 */	0xe,		/* FC_ENUM32 */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 716 */	0x0,		/* 0 */
			NdrFcShort( 0xff31 ),	/* Offset= -207 (510) */
			0x5b,		/* FC_END */
/* 720 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 722 */	NdrFcShort( 0x1c ),	/* 28 */
/* 724 */	NdrFcShort( 0x0 ),	/* 0 */
/* 726 */	NdrFcShort( 0x0 ),	/* Offset= 0 (726) */
/* 728 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 730 */	NdrFcShort( 0xfd32 ),	/* Offset= -718 (12) */
/* 732 */	0xe,		/* FC_ENUM32 */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 734 */	0x0,		/* 0 */
			NdrFcShort( 0xffe3 ),	/* Offset= -29 (706) */
			0x5b,		/* FC_END */
/* 738 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 740 */	NdrFcShort( 0x0 ),	/* 0 */
/* 742 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 744 */	NdrFcShort( 0x50 ),	/* 80 */
/* 746 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 748 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 752 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 754 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 756 */	NdrFcShort( 0xffdc ),	/* Offset= -36 (720) */
/* 758 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 760 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x7,		/* 7 */
/* 762 */	NdrFcShort( 0x98 ),	/* 152 */
/* 764 */	NdrFcShort( 0x0 ),	/* 0 */
/* 766 */	NdrFcShort( 0x30 ),	/* Offset= 48 (814) */
/* 768 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 770 */	NdrFcShort( 0xfd0a ),	/* Offset= -758 (12) */
/* 772 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 774 */	NdrFcShort( 0xfd12 ),	/* Offset= -750 (24) */
/* 776 */	0x8,		/* FC_LONG */
			0x36,		/* FC_POINTER */
/* 778 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 780 */	NdrFcShort( 0xfd36 ),	/* Offset= -714 (66) */
/* 782 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 784 */	NdrFcShort( 0xfcfc ),	/* Offset= -772 (12) */
/* 786 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 788 */	NdrFcShort( 0xfcf8 ),	/* Offset= -776 (12) */
/* 790 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 792 */	NdrFcShort( 0xfe92 ),	/* Offset= -366 (426) */
/* 794 */	0x8,		/* FC_LONG */
			0x36,		/* FC_POINTER */
/* 796 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 798 */	NdrFcShort( 0xfeb6 ),	/* Offset= -330 (468) */
/* 800 */	0x40,		/* FC_STRUCTPAD4 */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 802 */	0x0,		/* 0 */
			NdrFcShort( 0xfebf ),	/* Offset= -321 (482) */
			0x36,		/* FC_POINTER */
/* 806 */	0x40,		/* FC_STRUCTPAD4 */
			0xb,		/* FC_HYPER */
/* 808 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 810 */	NdrFcShort( 0xfe80 ),	/* Offset= -384 (426) */
/* 812 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 814 */	
			0x12, 0x0,	/* FC_UP */
/* 816 */	NdrFcShort( 0xfcdc ),	/* Offset= -804 (12) */
/* 818 */	
			0x12, 0x20,	/* FC_UP [maybenull_sizeis] */
/* 820 */	NdrFcShort( 0xffae ),	/* Offset= -82 (738) */
/* 822 */	
			0x12, 0x0,	/* FC_UP */
/* 824 */	NdrFcShort( 0xfcd4 ),	/* Offset= -812 (12) */
/* 826 */	
			0x12, 0x0,	/* FC_UP */
/* 828 */	NdrFcShort( 0x8 ),	/* Offset= 8 (836) */
/* 830 */	
			0x1d,		/* FC_SMFARRAY */
			0x0,		/* 0 */
/* 832 */	NdrFcShort( 0x5 ),	/* 5 */
/* 834 */	0x1,		/* FC_BYTE */
			0x5b,		/* FC_END */
/* 836 */	
			0x15,		/* FC_STRUCT */
			0x0,		/* 0 */
/* 838 */	NdrFcShort( 0x8 ),	/* 8 */
/* 840 */	0x2,		/* FC_CHAR */
			0x2,		/* FC_CHAR */
/* 842 */	0x2,		/* FC_CHAR */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 844 */	0x0,		/* 0 */
			NdrFcShort( 0xfff1 ),	/* Offset= -15 (830) */
			0x5b,		/* FC_END */
/* 848 */	
			0x12, 0x0,	/* FC_UP */
/* 850 */	NdrFcShort( 0x2 ),	/* Offset= 2 (852) */
/* 852 */	
			0x15,		/* FC_STRUCT */
			0x0,		/* 0 */
/* 854 */	NdrFcShort( 0x8 ),	/* 8 */
/* 856 */	0x3,		/* FC_SMALL */
			0x3,		/* FC_SMALL */
/* 858 */	0x3,		/* FC_SMALL */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 860 */	0x0,		/* 0 */
			NdrFcShort( 0xffe1 ),	/* Offset= -31 (830) */
			0x5b,		/* FC_END */
/* 864 */	
			0x12, 0x0,	/* FC_UP */
/* 866 */	NdrFcShort( 0xf4 ),	/* Offset= 244 (1110) */
/* 868 */	
			0x1d,		/* FC_SMFARRAY */
			0x0,		/* 0 */
/* 870 */	NdrFcShort( 0x1 ),	/* 1 */
/* 872 */	0x1,		/* FC_BYTE */
			0x5b,		/* FC_END */
/* 874 */	
			0x1d,		/* FC_SMFARRAY */
			0x0,		/* 0 */
/* 876 */	NdrFcShort( 0x4 ),	/* 4 */
/* 878 */	0x1,		/* FC_BYTE */
			0x5b,		/* FC_END */
/* 880 */	
			0x15,		/* FC_STRUCT */
			0x3,		/* 3 */
/* 882 */	NdrFcShort( 0x18 ),	/* 24 */
/* 884 */	0x8,		/* FC_LONG */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 886 */	0x0,		/* 0 */
			NdrFcShort( 0xfff3 ),	/* Offset= -13 (874) */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 890 */	0x0,		/* 0 */
			NdrFcShort( 0xfc8b ),	/* Offset= -885 (6) */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 894 */	0x0,		/* 0 */
			NdrFcShort( 0xfc87 ),	/* Offset= -889 (6) */
			0x5b,		/* FC_END */
/* 898 */	
			0x1d,		/* FC_SMFARRAY */
			0x0,		/* 0 */
/* 900 */	NdrFcShort( 0x3 ),	/* 3 */
/* 902 */	0x1,		/* FC_BYTE */
			0x5b,		/* FC_END */
/* 904 */	
			0x2b,		/* FC_NON_ENCAPSULATED_UNION */
			0xd,		/* FC_ENUM16 */
/* 906 */	0x4,		/* Corr desc: FC_USMALL */
			0x0,		/*  */
/* 908 */	NdrFcShort( 0xffff ),	/* -1 */
/* 910 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 912 */	NdrFcShort( 0x2 ),	/* Offset= 2 (914) */
/* 914 */	NdrFcShort( 0x10 ),	/* 16 */
/* 916 */	NdrFcShort( 0x2 ),	/* 2 */
/* 918 */	NdrFcLong( 0x4 ),	/* 4 */
/* 922 */	NdrFcShort( 0xffd0 ),	/* Offset= -48 (874) */
/* 924 */	NdrFcLong( 0x6 ),	/* 6 */
/* 928 */	NdrFcShort( 0x4 ),	/* Offset= 4 (932) */
/* 930 */	NdrFcShort( 0xffff ),	/* Offset= -1 (929) */
/* 932 */	
			0x1d,		/* FC_SMFARRAY */
			0x0,		/* 0 */
/* 934 */	NdrFcShort( 0x10 ),	/* 16 */
/* 936 */	0x1,		/* FC_BYTE */
			0x5b,		/* FC_END */
/* 938 */	
			0x2b,		/* FC_NON_ENCAPSULATED_UNION */
			0xd,		/* FC_ENUM16 */
/* 940 */	0x4,		/* Corr desc: FC_USMALL */
			0x0,		/*  */
/* 942 */	NdrFcShort( 0xffef ),	/* -17 */
/* 944 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 946 */	NdrFcShort( 0x2 ),	/* Offset= 2 (948) */
/* 948 */	NdrFcShort( 0x10 ),	/* 16 */
/* 950 */	NdrFcShort( 0x2 ),	/* 2 */
/* 952 */	NdrFcLong( 0x4 ),	/* 4 */
/* 956 */	NdrFcShort( 0xffae ),	/* Offset= -82 (874) */
/* 958 */	NdrFcLong( 0x6 ),	/* 6 */
/* 962 */	NdrFcShort( 0xffe2 ),	/* Offset= -30 (932) */
/* 964 */	NdrFcShort( 0xffff ),	/* Offset= -1 (963) */
/* 966 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 968 */	NdrFcShort( 0x28 ),	/* 40 */
/* 970 */	NdrFcShort( 0x0 ),	/* 0 */
/* 972 */	NdrFcShort( 0x0 ),	/* Offset= 0 (972) */
/* 974 */	0x8,		/* FC_LONG */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 976 */	0x0,		/* 0 */
			NdrFcShort( 0xffb1 ),	/* Offset= -79 (898) */
			0x2,		/* FC_CHAR */
/* 980 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 982 */	NdrFcShort( 0xffb2 ),	/* Offset= -78 (904) */
/* 984 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 986 */	NdrFcShort( 0xffd0 ),	/* Offset= -48 (938) */
/* 988 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 990 */	
			0x2b,		/* FC_NON_ENCAPSULATED_UNION */
			0x4,		/* FC_USMALL */
/* 992 */	0x4,		/* Corr desc: FC_USMALL */
			0x0,		/*  */
/* 994 */	NdrFcShort( 0xffff ),	/* -1 */
/* 996 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 998 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1000) */
/* 1000 */	NdrFcShort( 0x2 ),	/* 2 */
/* 1002 */	NdrFcShort( 0x5 ),	/* 5 */
/* 1004 */	NdrFcLong( 0x1 ),	/* 1 */
/* 1008 */	NdrFcShort( 0x8002 ),	/* Simple arm type: FC_CHAR */
/* 1010 */	NdrFcLong( 0x3a ),	/* 58 */
/* 1014 */	NdrFcShort( 0x8002 ),	/* Simple arm type: FC_CHAR */
/* 1016 */	NdrFcLong( 0x6 ),	/* 6 */
/* 1020 */	NdrFcShort( 0x8006 ),	/* Simple arm type: FC_SHORT */
/* 1022 */	NdrFcLong( 0x11 ),	/* 17 */
/* 1026 */	NdrFcShort( 0x8006 ),	/* Simple arm type: FC_SHORT */
/* 1028 */	NdrFcLong( 0xff ),	/* 255 */
/* 1032 */	NdrFcShort( 0x8006 ),	/* Simple arm type: FC_SHORT */
/* 1034 */	NdrFcShort( 0xffff ),	/* Offset= -1 (1033) */
/* 1036 */	
			0x2b,		/* FC_NON_ENCAPSULATED_UNION */
			0x4,		/* FC_USMALL */
/* 1038 */	0x4,		/* Corr desc: FC_USMALL */
			0x0,		/*  */
/* 1040 */	NdrFcShort( 0xfffd ),	/* -3 */
/* 1042 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 1044 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1046) */
/* 1046 */	NdrFcShort( 0x2 ),	/* 2 */
/* 1048 */	NdrFcShort( 0x5 ),	/* 5 */
/* 1050 */	NdrFcLong( 0x1 ),	/* 1 */
/* 1054 */	NdrFcShort( 0x8002 ),	/* Simple arm type: FC_CHAR */
/* 1056 */	NdrFcLong( 0x3a ),	/* 58 */
/* 1060 */	NdrFcShort( 0x8002 ),	/* Simple arm type: FC_CHAR */
/* 1062 */	NdrFcLong( 0x6 ),	/* 6 */
/* 1066 */	NdrFcShort( 0x8006 ),	/* Simple arm type: FC_SHORT */
/* 1068 */	NdrFcLong( 0x11 ),	/* 17 */
/* 1072 */	NdrFcShort( 0x8006 ),	/* Simple arm type: FC_SHORT */
/* 1074 */	NdrFcLong( 0xff ),	/* 255 */
/* 1078 */	NdrFcShort( 0x8006 ),	/* Simple arm type: FC_SHORT */
/* 1080 */	NdrFcShort( 0xffff ),	/* Offset= -1 (1079) */
/* 1082 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 1084 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1086 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1088 */	NdrFcShort( 0x0 ),	/* Offset= 0 (1088) */
/* 1090 */	0x8,		/* FC_LONG */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 1092 */	0x0,		/* 0 */
			NdrFcShort( 0xff3d ),	/* Offset= -195 (898) */
			0x2,		/* FC_CHAR */
/* 1096 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 1098 */	NdrFcShort( 0xff94 ),	/* Offset= -108 (990) */
/* 1100 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 1102 */	NdrFcShort( 0xffbe ),	/* Offset= -66 (1036) */
/* 1104 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 1106 */	NdrFcShort( 0xff18 ),	/* Offset= -232 (874) */
/* 1108 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 1110 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 1112 */	NdrFcShort( 0x58 ),	/* 88 */
/* 1114 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1116 */	NdrFcShort( 0x0 ),	/* Offset= 0 (1116) */
/* 1118 */	0x8,		/* FC_LONG */
			0x3,		/* FC_SMALL */
/* 1120 */	0x3,		/* FC_SMALL */
			0x3,		/* FC_SMALL */
/* 1122 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 1124 */	NdrFcShort( 0xff00 ),	/* Offset= -256 (868) */
/* 1126 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 1128 */	NdrFcShort( 0xff08 ),	/* Offset= -248 (880) */
/* 1130 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 1132 */	NdrFcShort( 0xff5a ),	/* Offset= -166 (966) */
/* 1134 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 1136 */	NdrFcShort( 0xffca ),	/* Offset= -54 (1082) */
/* 1138 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 1140 */	
			0x12, 0x0,	/* FC_UP */
/* 1142 */	NdrFcShort( 0x8 ),	/* Offset= 8 (1150) */
/* 1144 */	
			0x1d,		/* FC_SMFARRAY */
			0x0,		/* 0 */
/* 1146 */	NdrFcShort( 0x2 ),	/* 2 */
/* 1148 */	0x1,		/* FC_BYTE */
			0x5b,		/* FC_END */
/* 1150 */	
			0x15,		/* FC_STRUCT */
			0x3,		/* 3 */
/* 1152 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1154 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 1156 */	0x8,		/* FC_LONG */
			0x3,		/* FC_SMALL */
/* 1158 */	0x3,		/* FC_SMALL */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 1160 */	0x0,		/* 0 */
			NdrFcShort( 0xffef ),	/* Offset= -17 (1144) */
			0x5b,		/* FC_END */
/* 1164 */	
			0x12, 0x0,	/* FC_UP */
/* 1166 */	NdrFcShort( 0x40 ),	/* Offset= 64 (1230) */
/* 1168 */	
			0x1d,		/* FC_SMFARRAY */
			0x0,		/* 0 */
/* 1170 */	NdrFcShort( 0x7 ),	/* 7 */
/* 1172 */	0x1,		/* FC_BYTE */
			0x5b,		/* FC_END */
/* 1174 */	
			0x2b,		/* FC_NON_ENCAPSULATED_UNION */
			0xd,		/* FC_ENUM16 */
/* 1176 */	0x4,		/* Corr desc: FC_USMALL */
			0x0,		/*  */
/* 1178 */	NdrFcShort( 0xffff ),	/* -1 */
/* 1180 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 1182 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1184) */
/* 1184 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1186 */	NdrFcShort( 0x2 ),	/* 2 */
/* 1188 */	NdrFcLong( 0x4 ),	/* 4 */
/* 1192 */	NdrFcShort( 0xfec2 ),	/* Offset= -318 (874) */
/* 1194 */	NdrFcLong( 0x6 ),	/* 6 */
/* 1198 */	NdrFcShort( 0xfef6 ),	/* Offset= -266 (932) */
/* 1200 */	NdrFcShort( 0xffff ),	/* Offset= -1 (1199) */
/* 1202 */	
			0x2b,		/* FC_NON_ENCAPSULATED_UNION */
			0xd,		/* FC_ENUM16 */
/* 1204 */	0x4,		/* Corr desc: FC_USMALL */
			0x0,		/*  */
/* 1206 */	NdrFcShort( 0xffef ),	/* -17 */
/* 1208 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 1210 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1212) */
/* 1212 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1214 */	NdrFcShort( 0x2 ),	/* 2 */
/* 1216 */	NdrFcLong( 0x4 ),	/* 4 */
/* 1220 */	NdrFcShort( 0xfea6 ),	/* Offset= -346 (874) */
/* 1222 */	NdrFcLong( 0x6 ),	/* 6 */
/* 1226 */	NdrFcShort( 0xfeda ),	/* Offset= -294 (932) */
/* 1228 */	NdrFcShort( 0xffff ),	/* Offset= -1 (1227) */
/* 1230 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x7,		/* 7 */
/* 1232 */	NdrFcShort( 0x50 ),	/* 80 */
/* 1234 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1236 */	NdrFcShort( 0x0 ),	/* Offset= 0 (1236) */
/* 1238 */	0x8,		/* FC_LONG */
			0x3,		/* FC_SMALL */
/* 1240 */	0x3,		/* FC_SMALL */
			0x3,		/* FC_SMALL */
/* 1242 */	0x3,		/* FC_SMALL */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 1244 */	0x0,		/* 0 */
			NdrFcShort( 0xffb3 ),	/* Offset= -77 (1168) */
			0x2,		/* FC_CHAR */
/* 1248 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 1250 */	NdrFcShort( 0xffb4 ),	/* Offset= -76 (1174) */
/* 1252 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 1254 */	NdrFcShort( 0xffcc ),	/* Offset= -52 (1202) */
/* 1256 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 1258 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 1260 */	0x8,		/* FC_LONG */
			0xb,		/* FC_HYPER */
/* 1262 */	0xb,		/* FC_HYPER */
			0x5b,		/* FC_END */

			0x0
        }
    };

static const WFPSamplerRPC_MIDL_EXPR_FORMAT_STRING WFPSamplerRPC__MIDL_ExprFormatString =
    {
        0,
        {
			0x4,		/* FC_EXPR_OPER */
			0x1b,		/* OP_AND */
/*  2 */	0x0,		/*  */
			0x0,		/* 0 */
/*  4 */	0x3,		/* FC_EXPR_VAR */
			0x9,		/* FC_ULONG */
/*  6 */	NdrFcShort( 0xfffc ),	/* -4 */
/*  8 */	0x1,		/* FC_EXPR_CONST32 */
			0x8,		/* FC_LONG */
/* 10 */	NdrFcShort( 0x0 ),	/* 0 */
/* 12 */	NdrFcLong( 0x4000 ),	/* 16384 */
/* 16 */	0x4,		/* FC_EXPR_OPER */
			0x1b,		/* OP_AND */
/* 18 */	0x0,		/*  */
			0x0,		/* 0 */
/* 20 */	0x3,		/* FC_EXPR_VAR */
			0x9,		/* FC_ULONG */
/* 22 */	NdrFcShort( 0xffa8 ),	/* -88 */
/* 24 */	0x1,		/* FC_EXPR_CONST32 */
			0x8,		/* FC_LONG */
/* 26 */	NdrFcShort( 0x0 ),	/* 0 */
/* 28 */	NdrFcLong( 0x4 ),	/* 4 */

			0x0
        }
    };

static const unsigned short WFPSamplerRPC__MIDL_ExprFormatStringOffsetTable[] =
{
0,
16,
};

static const NDR_EXPR_DESC  WFPSamplerRPC_ExprDesc = 
 {
WFPSamplerRPC__MIDL_ExprFormatStringOffsetTable,
WFPSamplerRPC__MIDL_ExprFormatString.Format
};

static const unsigned short IWFPSampler_FormatStringOffsetTable[] =
    {
    0,
    64,
    122,
    174,
    232,
    290,
    348,
    400,
    452,
    510
    };


static const COMM_FAULT_OFFSETS IWFPSampler_CommFaultOffsets[] = 
{
	{ -1, -1 },	/* x86 Offsets for RPCInvokeScenarioAppContainer */
	{ -1, -1 },	/* x86 Offsets for RPCInvokeScenarioBasicAction */
	{ -1, -1 },	/* x86 Offsets for RPCInvokeScenarioBasicPacketExamination */
	{ -1, -1 },	/* x86 Offsets for RPCInvokeScenarioBasicPacketInjection */
	{ -1, -1 },	/* x86 Offsets for RPCInvokeScenarioBasicPacketModification */
	{ -1, -1 },	/* x86 Offsets for RPCInvokeScenarioBasicStreamInjection */
	{ -1, -1 },	/* x86 Offsets for RPCInvokeScenarioFastPacketInjection */
	{ -1, -1 },	/* x86 Offsets for RPCInvokeScenarioFastStreamInjection */
	{ -1, -1 },	/* x86 Offsets for RPCInvokeScenarioPendAuthorization */
	{ -1, -1 } 	/* x86 Offsets for RPCInvokeScenarioProxy */
};


static const MIDL_STUB_DESC IWFPSampler_StubDesc = 
    {
    (void *)& IWFPSampler___RpcClientInterface,
    MIDL_user_allocate,
    MIDL_user_free,
    &wfpSamplerBindingHandle,
    0,
    0,
    0,
    0,
    WFPSamplerRPC__MIDL_TypeFormatString.Format,
    1, /* -error bounds_check flag */
    0x60001, /* Ndr library version */
    0,
    0x800025b, /* MIDL Version 8.0.603 */
    IWFPSampler_CommFaultOffsets,
    0,
    0,  /* notify & notify_flag routine table */
    0x1, /* MIDL flag */
    0, /* cs routines */
    0,   /* proxy/server info */
    &WFPSamplerRPC_ExprDesc
    };
#pragma optimize("", on )
#if _MSC_VER >= 1200
#pragma warning(pop)
#endif


#endif /* !defined(_M_IA64) && !defined(_M_AMD64) && !defined(_ARM_) */

