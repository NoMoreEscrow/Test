

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


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

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 500
#endif

/* verify that the <rpcsal.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCSAL_H_VERSION__
#define __REQUIRED_RPCSAL_H_VERSION__ 100
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__


#ifndef __WFPSamplerRPC_h__
#define __WFPSamplerRPC_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

/* header files for imported files */
#include "wtypes.h"
#include "fwpmtypes.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IWFPSampler_INTERFACE_DEFINED__
#define __IWFPSampler_INTERFACE_DEFINED__

/* interface IWFPSampler */
/* [implicit_handle][type_strict_context_handle][ref][endpoint][version][uuid][helpstring] */ 

#ifdef __midl
typedef /* [public] */ 
enum __MIDL_IWFPSampler_0001
    {
        IPV4	= 4,
        IPV6	= 6
    } 	IPVERSION;

typedef /* [public] */ 
enum __MIDL_IWFPSampler_0002
    {
        IPPROTO_HOPOPTS	= 0,
        IPPROTO_ICMP	= 1,
        IPPROTO_IGMP	= 2,
        IPPROTO_GGP	= 3,
        IPPROTO_IPV4	= 4,
        IPPROTO_ST	= 5,
        IPPROTO_TCP	= 6,
        IPPROTO_CBT	= 7,
        IPPROTO_EGP	= 8,
        IPPROTO_IGP	= 9,
        IPPROTO_PUP	= 12,
        IPPROTO_UDP	= 17,
        IPPROTO_IDP	= 22,
        IPPROTO_RDP	= 27,
        IPPROTO_IPV6	= 41,
        IPPROTO_ROUTING	= 43,
        IPPROTO_FRAGMENT	= 44,
        IPPROTO_ESP	= 50,
        IPPROTO_AH	= 51,
        IPPROTO_ICMPV6	= 58,
        IPPROTO_NONE	= 59,
        IPPROTO_DSTOPTS	= 60,
        IPPROTO_ND	= 77,
        IPPROTO_ICLFXBM	= 78,
        IPPROTO_PIM	= 103,
        IPPROTO_PGM	= 113,
        IPPROTO_L2TP	= 115,
        IPPROTO_SCTP	= 132,
        IPPROTO_RAW	= 255,
        IPPROTO_MAX	= 256
    } 	IPPROTO;

#endif
typedef 
enum WFPSAMPLER_SCENARIO_
    {
        SCENARIO_UNDEFINED	= 0,
        SCENARIO_APP_CONTAINER	= 1,
        SCENARIO_BASIC_ACTION_BLOCK	= 2,
        SCENARIO_BASIC_ACTION_CONTINUE	= 3,
        SCENARIO_BASIC_ACTION_PERMIT	= 4,
        SCENARIO_BASIC_ACTION_RANDOM	= 5,
        SCENARIO_BASIC_PACKET_EXAMINATION	= 6,
        SCENARIO_BASIC_PACKET_INJECTION	= 7,
        SCENARIO_BASIC_PACKET_MODIFICATION	= 8,
        SCENARIO_BASIC_STREAM_INJECTION	= 9,
        SCENARIO_FAST_PACKET_INJECTION	= 10,
        SCENARIO_FAST_STREAM_INJECTION	= 11,
        SCENARIO_PEND_AUTHORIZATION	= 12,
        SCENARIO_PROXY	= 13,
        SCENARIO_MAX	= ( SCENARIO_PROXY + 1 ) 
    } 	WFPSAMPLER_SCENARIO;

typedef struct MAC_DATA_
    {
    UINT32 flags;
    BYTE pReserved[ 4 ];
    BYTE pSourceMACAddress[ 8 ];
    BYTE pDestinationMACAddress[ 8 ];
    } 	MAC_DATA;

typedef struct IP_DATA_
    {
    UINT32 flags;
    BYTE pReserved[ 3 ];
    UINT8 ipVersion;
    /* [switch_is][switch_type] */ union 
        {
        /* [case()] */ BYTE pIPv4[ 4 ];
        /* [case()] */ BYTE pIPv6[ 16 ];
        } 	sourceAddress;
    /* [switch_is][switch_type] */ union 
        {
        /* [case()] */ BYTE pIPv4[ 4 ];
        /* [case()] */ BYTE pIPv6[ 16 ];
        } 	destinationAddress;
    } 	IP_DATA;

typedef struct TRANSPORT_DATA_
    {
    UINT32 flags;
    BYTE pReserved[ 3 ];
    UINT8 protocol;
    /* [switch_is][switch_type] */ union 
        {
        /* [case()] */ UINT8 type;
        /* [case()] */ UINT16 port;
        /* [case()] */ UINT16 data;
        } 	source;
    /* [switch_is][switch_type] */ union 
        {
        /* [case()] */ UINT8 code;
        /* [case()] */ UINT16 port;
        /* [case()] */ UINT16 data;
        } 	destination;
    BYTE pPadding[ 4 ];
    } 	TRANSPORT_DATA;

typedef struct PC_BASIC_ACTION_DATA_
    {
    UINT8 percentBlock;
    UINT8 percentPermit;
    UINT8 percentContinue;
    BYTE pReserved[ 5 ];
    } 	PC_BASIC_ACTION_DATA;

typedef struct PC_BASIC_PACKET_INJECTION_DATA_
    {
    BOOLEAN performInline;
    BOOLEAN useWorkItems;
    BOOLEAN useThreadedDPC;
    BYTE pReserved[ 5 ];
    } 	PC_BASIC_PACKET_INJECTION_DATA;

typedef struct PC_BASIC_PACKET_MODIFICATION_DATA_
    {
    UINT32 flags;
    BOOLEAN performInline;
    BOOLEAN useWorkItems;
    BOOLEAN useThreadedDPC;
    BYTE pReserved[ 1 ];
    MAC_DATA macData;
    IP_DATA ipData;
    TRANSPORT_DATA transportData;
    } 	PC_BASIC_PACKET_MODIFICATION_DATA;

typedef struct PC_BASIC_STREAM_INJECTION_DATA_
    {
    BOOLEAN performInline;
    BOOLEAN useWorkItems;
    BOOLEAN useThreadedDPC;
    BYTE pReserved[ 5 ];
    } 	PC_BASIC_STREAM_INJECTION_DATA;

typedef struct PC_PEND_AUTHORIZATION_DATA_
    {
    UINT32 flags;
    UINT32 finalAction;
    UINT32 delay;
    BOOLEAN useWorkItems;
    BOOLEAN useThreadedDPC;
    BYTE pReserved[ 2 ];
    } 	PC_PEND_AUTHORIZATION_DATA;

typedef struct PC_PROXY_DATA_
    {
    UINT32 flags;
    BOOLEAN performInline;
    BOOLEAN useWorkItems;
    BOOLEAN useThreadedDPC;
    BOOLEAN proxyToRemoteService;
    BYTE pReserved[ 7 ];
    UINT8 ipVersion;
    /* [switch_is][switch_type] */ union 
        {
        /* [case()] */ BYTE pIPv4[ 4 ];
        /* [case()] */ BYTE pIPv6[ 16 ];
        } 	proxyLocalAddress;
    /* [switch_is][switch_type] */ union 
        {
        /* [case()] */ BYTE pIPv4[ 4 ];
        /* [case()] */ BYTE pIPv6[ 16 ];
        } 	proxyRemoteAddress;
    UINT32 localScopeId;
    UINT32 remoteScopeId;
    UINT16 proxyLocalPort;
    UINT16 proxyRemotePort;
    UINT32 targetProcessID;
    UINT64 tcpPortReservationToken;
    UINT64 udpPortReservationToken;
    } 	PC_PROXY_DATA;

#define PCPDF_PROXY_LOCAL_ADDRESS  0x01
#define PCPDF_PROXY_LOCAL_PORT     0x02
#define PCPDF_PROXY_REMOTE_ADDRESS 0x04
#define PCPDF_PROXY_REMOTE_PORT    0x08
#define PCPMDF_MODIFY_MAC_HEADER                     0x10
#define PCPMDF_MODIFY_MAC_HEADER_SOURCE_ADDRESS      0x01
#define PCPMDF_MODIFY_MAC_HEADER_DESTINATION_ADDRESS 0x02
#define PCPMDF_MODIFY_IP_HEADER                     0x20
#define PCPMDF_MODIFY_IP_HEADER_SOURCE_ADDRESS      0x01
#define PCPMDF_MODIFY_IP_HEADER_DESTINATION_ADDRESS 0x02
#define PCPMDF_MODIFY_TRANSPORT_HEADER                  0x40
#define PCPMDF_MODIFY_TRANSPORT_HEADER_SOURCE_PORT      0x01
#define PCPMDF_MODIFY_TRANSPORT_HEADER_DESTINATION_PORT 0x02
#define PCPMDF_MODIFY_TRANSPORT_HEADER_ICMP_TYPE PCPMDF_MODIFY_TRANSPORT_HEADER_SOURCE_PORT
#define PCPMDF_MODIFY_TRANSPORT_HEADER_ICMP_CODE PCPMDF_MODIFY_TRANSPORT_HEADER_DESTINATION_PORT
extern handle_t wfpSamplerBindingHandle;

/* [fault_status][comm_status] */ error_status_t RPCInvokeScenarioAppContainer( 
    /* [in] */ handle_t rpcBindingHandle,
    /* [in] */ WFPSAMPLER_SCENARIO scenario,
    /* [in] */ FWPM_CHANGE_TYPE changeType,
    /* [in] */ BOOLEAN trustWSH,
    /* [in] */ BOOLEAN persistent,
    /* [in] */ BOOLEAN bootTime);

/* [fault_status][comm_status] */ error_status_t RPCInvokeScenarioBasicAction( 
    /* [in] */ handle_t rpcBindingHandle,
    /* [in] */ WFPSAMPLER_SCENARIO scenario,
    /* [in] */ FWPM_CHANGE_TYPE changeType,
    /* [ref][in] */ __RPC__in const FWPM_FILTER0 *pFilter,
    /* [unique][in] */ __RPC__in_opt const PC_BASIC_ACTION_DATA *pPCBasicActionData);

/* [fault_status][comm_status] */ error_status_t RPCInvokeScenarioBasicPacketExamination( 
    /* [in] */ handle_t rpcBindingHandle,
    /* [in] */ WFPSAMPLER_SCENARIO scenario,
    /* [in] */ FWPM_CHANGE_TYPE changeType,
    /* [ref][in] */ __RPC__in const FWPM_FILTER0 *pFilter);

/* [fault_status][comm_status] */ error_status_t RPCInvokeScenarioBasicPacketInjection( 
    /* [in] */ handle_t rpcBindingHandle,
    /* [in] */ WFPSAMPLER_SCENARIO scenario,
    /* [in] */ FWPM_CHANGE_TYPE changeType,
    /* [ref][in] */ __RPC__in const FWPM_FILTER0 *pFilter,
    /* [unique][in] */ __RPC__in_opt const PC_BASIC_PACKET_INJECTION_DATA *pPCBasicPacketInjectionData);

/* [fault_status][comm_status] */ error_status_t RPCInvokeScenarioBasicPacketModification( 
    /* [in] */ handle_t rpcBindingHandle,
    /* [in] */ WFPSAMPLER_SCENARIO scenario,
    /* [in] */ FWPM_CHANGE_TYPE changeType,
    /* [ref][in] */ __RPC__in const FWPM_FILTER0 *pFilter,
    /* [unique][in] */ __RPC__in_opt const PC_BASIC_PACKET_MODIFICATION_DATA *pPCBasicPacketModificationData);

/* [fault_status][comm_status] */ error_status_t RPCInvokeScenarioBasicStreamInjection( 
    /* [in] */ handle_t rpcBindingHandle,
    /* [in] */ WFPSAMPLER_SCENARIO scenario,
    /* [in] */ FWPM_CHANGE_TYPE changeType,
    /* [ref][in] */ __RPC__in const FWPM_FILTER0 *pFilter,
    /* [unique][in] */ __RPC__in_opt const PC_BASIC_STREAM_INJECTION_DATA *pPCBasicStreamInjectionData);

/* [fault_status][comm_status] */ error_status_t RPCInvokeScenarioFastPacketInjection( 
    /* [in] */ handle_t rpcBindingHandle,
    /* [in] */ WFPSAMPLER_SCENARIO scenario,
    /* [in] */ FWPM_CHANGE_TYPE changeType,
    /* [ref][in] */ __RPC__in const FWPM_FILTER0 *pFilter);

/* [fault_status][comm_status] */ error_status_t RPCInvokeScenarioFastStreamInjection( 
    /* [in] */ handle_t rpcBindingHandle,
    /* [in] */ WFPSAMPLER_SCENARIO scenario,
    /* [in] */ FWPM_CHANGE_TYPE changeType,
    /* [ref][in] */ __RPC__in const FWPM_FILTER0 *pFilter);

/* [fault_status][comm_status] */ error_status_t RPCInvokeScenarioPendAuthorization( 
    /* [in] */ handle_t rpcBindingHandle,
    /* [in] */ WFPSAMPLER_SCENARIO scenario,
    /* [in] */ FWPM_CHANGE_TYPE changeType,
    /* [ref][in] */ __RPC__in const FWPM_FILTER0 *pFilter,
    /* [unique][in] */ __RPC__in_opt const PC_PEND_AUTHORIZATION_DATA *pPCPendAuthorizationData);

/* [fault_status][comm_status] */ error_status_t RPCInvokeScenarioProxy( 
    /* [in] */ handle_t rpcBindingHandle,
    /* [in] */ WFPSAMPLER_SCENARIO scenario,
    /* [in] */ FWPM_CHANGE_TYPE changeType,
    /* [ref][in] */ __RPC__in const FWPM_FILTER0 *pFilter,
    /* [unique][in] */ __RPC__in_opt const PC_PROXY_DATA *pPCProxyData);


extern handle_t wfpSamplerBindingHandle;


extern RPC_IF_HANDLE IWFPSampler_v1_0_c_ifspec;
extern RPC_IF_HANDLE IWFPSampler_v1_0_s_ifspec;
#endif /* __IWFPSampler_INTERFACE_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


