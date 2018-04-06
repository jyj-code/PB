//-----------------------------------------------------------------------------
//      pbgerslt.h
//
//      PowerBuilder generator error codes.
//-----------------------------------------------------------------------------

#ifndef PBRESULT_H
#define PBRESULT_H

//      TODO:
//      This stuff duplicates what's already found in ./include/pbresult.h.
//      It's repeated here because this header will be used outside of 
//      PowerBuilder, where pbresult.h will not be available.  
//      These headers should be integrated into a single header which
//      is published in a "customer" header area.
//      wrlane 3/11/97

//-----------------------------------------------------------------------------
//
// PBRESULTs are merely a 32-bit value with several fields encoded
// in the value.  The parts of a PBRESULT are shown below.
//
//   3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1 1 1
//   1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0
//  +-+-+-+-+-+---------------------+-----------+-------------------+
//  |S|R|C|N|r|    Facility         | PB Module |       Code        |
//  +-+-+-+-+-+---------------------+-----------+-------------------+
//
//  where
//
//  S - Severity - indicates success (0) or failure (1)
//  R, C, N, r - unused by PowerBuilder, defined for HRESULT in winerror.h
//  Facility - facility code. For PB APIs and functions, always FACILITY_ITF.
//  PB Module - Identifies the PowerBuilder module that created the error.
//  Code - is the module's return code
//
//  Other useful macros -
//
//  SUCCEEDED(result) - Returns true if a given PBRESULT indicates success
//  FAILED(result)    - Returns true if a given PBRESULT indicates failure
//
//-----------------------------------------------------------------------------


#ifndef PBRESULT
#define PBRESULT                PBLONG
#endif
#ifndef FACILITY_ITF
#define FACILITY_ITF            4
#endif
#ifndef SEVERITY_SUCCESS
#define SEVERITY_SUCCESS        0
#endif
#ifndef SEVERITY_ERROR  
#define SEVERITY_ERROR          1
#endif
#ifndef SUCCEEDED
#define SUCCEEDED(result)       ((result) >= 0)
#endif
#ifndef FAILED
#define FAILED(result)          ((result) < 0)
#endif
#ifndef MAKE_SCODE
#define MAKE_SCODE(sev, fac, code) \
	((long)(((unsigned long)(sev)<<31) | \
	((unsigned long)(fac)<<16) | \
	((unsigned long)(code))))
#endif
#ifndef MAKE_PBRESULT
#define MAKE_PBRESULT(sev, module, code) \
	(MAKE_SCODE(sev, FACILITY_ITF, \
	((((unsigned long)(module))<<10) | (((unsigned long)(code))&0x03FF))))
#endif
#ifndef PBRESULT_CODE
#define PBRESULT_CODE(result)   ((result) & 0x03FF)
#endif
#ifndef PBRESULT_MODULE
#define PBRESULT_MODULE(result) (((result)>>10) & 0x003F)
#endif
 
#endif  //  PBRESULT_H

//  Generator specific stuff

#ifndef PBGRESLT_H
#define PBGRESLT_H

#include "pbgtypes.h"

#ifndef PBMODULE_GENERATOR
#define PBMODULE_GENERATOR      15
#endif

#define PBRESULT_OK             0
#define PBRESULT_FAIL \
	MAKE_PBRESULT(SEVERITY_ERROR, PBMODULE_GENERATOR, 0)
 
#endif  //  PBGRESLT_H


