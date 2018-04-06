//              Copyright Sybase, Inc. 1996
//
//      Sybase, Inc. ("Sybase") claims copyright in this
//      program and documentation as an unpublished work, versions of
//      which were first licensed on the date indicated in the foregoing
//      notice.  Claim of copyright does not imply waiver of Sybase's
//      other rights.
//-----------------------------------------------------------------------------
//	Generator registration utility functions.
//-----------------------------------------------------------------------------

#ifndef PBGENREG_H
#define PBGENREG_H

#ifndef PBGTYPES_H
#include "pbgtypes.h"
#endif
#ifndef PBGRESLT_H
#include "pbgreslt.h"
#endif
#ifndef PBGRUNIF_H
#include "pbgrunif.h"
#endif


//	Register a generator with PowerBuilder.  You must provide the following
//	information:
//
//		1.	The GUID that identifies your generator.
//		2.	The kind of PowerBuilder object your generator can handle
//		3.	The name of the DLL that implements your generator.
//
//	To unregister, just provide the GUID.

PBRESULT 	Register( 	PBCLSIDREF idGeneratorClassID,
						PBObjectType eObjectType,
						PBIString * pDLLName );

PBRESULT	Unregister(	PBCLSIDREF	idGeneratorClassID );


#endif	//	PBGENREG_H
