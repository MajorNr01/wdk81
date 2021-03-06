////////////////////////////////////////////////////////////////////////////////////////////////////
//
//   Copyright (c) 2012 Microsoft Corporation.  All Rights Reserved.
//
//   Module Name:
//      ClassifyFunctions_FastStreamInjectionCallouts.h
//
//   Abstract:
//      This module contains prototypes for WFP Classify functions that inject data back into the
//         stream using the clone / block / inject method.  This method is inline only, no 
//         modification, and uses as little validation and error checking as possible.  These 
//         functions are meant for test performance purposes only.
//
//   Author:
//      Dusty Harper      (DHarper)
//
//   Revision History:
//
//      [ Month ][Day] [Year] - [Revision]-[ Comments ]
//      May       01,   2010  -     1.0   -  Creation
//
////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef CLASSIFY_FAST_STREAM_INJECTION_H
#define CLASSIFY_FAST_STREAM_INJECTION_H

#if(NTDDI_VERSION >= NTDDI_WIN7)

_IRQL_requires_min_(PASSIVE_LEVEL)
_IRQL_requires_max_(DISPATCH_LEVEL)
_IRQL_requires_same_
VOID ClassifyFastStreamInjection(_In_ const FWPS_INCOMING_VALUES* pClassifyValues,
                                 _In_ const FWPS_INCOMING_METADATA_VALUES* pMetadata,
                                 _Inout_opt_ VOID* pLayerData,
                                 _In_opt_ const VOID* pClassifyContext,
                                 _In_ const FWPS_FILTER* pFilter,
                                 _In_ UINT64 flowContext,
                                 _Inout_ FWPS_CLASSIFY_OUT* pClassifyOut);

#else

_IRQL_requires_min_(PASSIVE_LEVEL)
_IRQL_requires_max_(DISPATCH_LEVEL)
_IRQL_requires_same_
VOID ClassifyFastStreamInjection(_In_ const FWPS_INCOMING_VALUES* pClassifyValues,
                                 _In_ const FWPS_INCOMING_METADATA_VALUES* pMetadata,
                                 _Inout_opt_ VOID* pLayerData,
                                 _In_ const FWPS_FILTER* pFilter,
                                 _In_ UINT64 flowContext,
                                 _Inout_ FWPS_CLASSIFY_OUT* pClassifyOut);

#endif /// (NTDDI_VERSION >= NTDDI_WIN7)

#endif /// CLASSIFY_FAST_STREAM_INJECTION_H
