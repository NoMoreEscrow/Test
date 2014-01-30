///////////////////////////////////////////////////////////////////////////////////////////////////
///
/// Copyright (c) 2012 Microsoft Corporation.  All Rights Reserved.
///
///   Module Name:
///      Framework_WFPSamplerService_Msg.mc
///
///   Abstract:
///      Message text for WFPSampler service (WFPSamplerService.exe)
///
///   Author:
///      Dusty Harper      (DHarper)
///
///   Revision History:
///
///      [ Month ][Day] [Year] - [Revision]-[ Comments ]
///      May       01,   2010  -     1.0   -  Creation
///
///   Notes:
///      A .mc file is compiled by the MC tool to generate a .h file and
///      a .rc (resource compiler script) file.
///
///      Comments in .mc files start with a ";".
///      Comment lines are generated directly in the .h file, without the leading ";"
///
///      See mc.hlp for more help on .mc files and the MC tool.
///
///////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef  FRAMEWORK_WFP_SAMPLER_SERVICE_MESSAGES
#define FRAMEWORK_WFP_SAMPLER_SERVICE_MESSAGES
/// HEADER SECTION
/// CATEGORY EVENTS
//
//  Values are 32 bit values laid out as follows:
//
//   3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1 1 1
//   1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0
//  +---+-+-+-----------------------+-------------------------------+
//  |Sev|C|R|     Facility          |               Code            |
//  +---+-+-+-----------------------+-------------------------------+
//
//  where
//
//      Sev - is the severity code
//
//          00 - Success
//          01 - Informational
//          10 - Warning
//          11 - Error
//
//      C - is the Customer code flag
//
//      R - is a reserved bit
//
//      Facility - is the facility code
//
//      Code - is the facility's status code
//
//
// Define the facility codes
//
#define FACILITY_SYSTEM                  0x0
#define FACILITY_STUBS                   0x3
#define FACILITY_RUNTIME                 0x2
#define FACILITY_IO_ERROR_CODE           0x4


//
// Define the severity codes
//
#define STATUS_SEVERITY_WARNING          0x2
#define STATUS_SEVERITY_SUCCESS          0x0
#define STATUS_SEVERITY_INFORMATIONAL    0x1
#define STATUS_SEVERITY_ERROR            0x3


//
// MessageId: NETWORK_CATEGORY
//
// MessageText:
//
// Network Events
//
#define NETWORK_CATEGORY                 ((UINT16)0x00000001L)

/// MESSAGE DEFINITIONS
//
// MessageId: SVC_ERROR
//
// MessageText:
//
// An error has occurred (%2)
//
#define SVC_ERROR                        ((UINT32)0xC0020001L)

#endif /// FRAMEWORK_WFP_SAMPLER_SERVICE_MESSAGES