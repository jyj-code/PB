//-----------------------------------------------------------------------------
//	pbgutil.h
//
//	PowerBuilder generator facility utility functions.
//
//-----------------------------------------------------------------------------

#ifndef PBGUTIL_H
#define PBGUTIL_H

#ifndef  PBGTYPES_H
#include "pbgtypes.h"
#endif
#ifndef  PBGRUNIF_H
#include "pbgrunif.h"
#endif


extern "C"
{
	PBWINAPI(PBBOOL,   PBUtil_IsEqualPBIID)( PBIIDREF, PBIIDREF );
	PBWINAPI(PBBOOL,   PBUtil_IsEqualPBCLSID)( PBCLSIDREF, PBCLSIDREF );
	PBWINAPI(PBRESULT, PBUtil_DescriptionFor)(PBRESULT, PBIString ** );
	PBWINAPI(PBRESULT, PBUtil_StringForPBIID)( PBIIDREF, PBIString ** );
	PBWINAPI(PBRESULT, PBUtil_StringForPBCLSID)( PBCLSIDREF, PBIString ** );

	PBWINAPI(PBRESULT, PBUtil_PBIIDForString)( PBIString * pString, PBIDREF refID );

	PBWINAPI(PBRESULT, PBUtil_PBCLSIDForString)( PBIString *, PBCLSIDREF );
	PBWINAPI(PBRESULT, PBUtil_CopyPBIID)( PBIIDREF, PBIIDREF );
	PBWINAPI(PBRESULT, PBUtil_CopyPBCLSID)( PBCLSIDREF, PBCLSIDREF );

	PBWINAPI(PBRESULT, PBUtil_CreatePBID)(PBIDREF id);

	PBWINAPI(PBRESULT, PBUtil_ReplaceLibraryPathsIn)( 
		PBIString * pOriginalLibraryList,
		PBIString * pNewLibraryPath,
		PBIString ** ppNewLibraryList );
};

#endif	//  PBGUTIL_H

