//              Copyright Sybase, Inc. 1996
//
//      Sybase, Inc. ("Sybase") claims copyright in this
//      program and documentation as an unpublished work, versions of
//      which were first licensed on the date indicated in the foregoing
//      notice.  Claim of copyright does not imply waiver of Sybase's
//      other rights.
//-----------------------------------------------------------------------------
//	These interfaces encapsulate the C++ compiler that is used by 
//	PowerBuilder to build generated code.  The particular toolset will
//	vary by platform.  These interfaces may be queried from an instance
//	of PBIBuildServices that is created with PBICPPBuildServices_CLSID.
//-----------------------------------------------------------------------------


#ifndef PBGCBSIF_H
#define PBGCBSIF_H

#ifndef PBGDEVIF_H
#include "pbgdevif.h"
#endif
 
//	GUID for the C++ BuildServices

extern "C"
{
extern PBCLSID	PBICPPBuildServices_CLSID;
extern PBIID	PBICPPSourceCompiler_IID;
extern PBIID	PBICPPResourceCompiler_IID;
extern PBIID	PBICPPLinker_IID;
};

//      forward declarations for convenience.

class PBICPPSourceCompiler;
class PBICPPResourceCompiler;
class PBICPPLinker;


//-----------------------------------------------------------------------------
//                     PBISourceCompiler
//-----------------------------------------------------------------------------

enum PBCPPSourceCompilerOptimization
{
	PBCPPSourceCompilerOptimizationNone = 0,
	PBCPPSourceCompilerOptimizationSize,
	PBCPPSourceCompilerOptimizationSpeed,
	PBCPPSourceCompilerOptimizationCount 
};

class PBICPPSourceCompiler         :       public PBIUnknown
{
  public:
 
	virtual PBRESULT        GetSourcePath( PBIString ** ppPath ) = 0;
	virtual PBRESULT        SetSourcePath( PBIString * pPath ) = 0;

    	virtual PBRESULT	GetCompilerOptions( PBIString ** ppPath ) =0;
	virtual PBRESULT	SetCompilerOptions( PBIString * pPath ) =0;
    
	virtual PBRESULT        GetOptimization( PBCPPSourceCompilerOptimization * ) = 0;
	virtual PBRESULT        SetOptimization( PBCPPSourceCompilerOptimization ) = 0;

	virtual PBRESULT        IsDebugOn( PBBOOL * pDebug ) = 0;
	virtual PBRESULT        SetDebugOn( PBBOOL bDebug ) = 0;

	virtual PBRESULT        AddIncludePath( PBIString * ) = 0;
	virtual PBRESULT        RemoveIncludePath( PBIString * ) = 0;
	virtual PBRESULT        GetIncludePaths( PBIStringList ** ) = 0;

	virtual PBRESULT        AddDefineSymbol( PBIString * ) = 0;
	virtual PBRESULT        RemoveDefineSymbol( PBIString * ) = 0;
	virtual PBRESULT        GetDefineSymbols( PBIStringList ** ) = 0;

	virtual PBRESULT        Compile( PBIString *, PBIBuildError ** ) = 0;
};

//-----------------------------------------------------------------------------
//                          PBIResourceCompiler
//-----------------------------------------------------------------------------

class PBICPPResourceCompiler       :       public PBIUnknown
{
  public:

	virtual PBRESULT        GetResourcePath( PBIString ** ppPath ) = 0;
	virtual PBRESULT        SetResourcePath( PBIString * pPath ) = 0;
 
	virtual PBRESULT        CompileResource( PBIString *, PBIBuildError ** ) = 0;
};

//-----------------------------------------------------------------------------
//                          PBILinker
//-----------------------------------------------------------------------------

enum PBCPPBuildServicesTargetType
{
	PBCPPBuildServicesTargetTypeExecutable = 0,
	PBCPPBuildServicesTargetTypeSharedLibrary,
	PBCPPBuildServicesTargetTypeStaticLibrary,
	PBCPPBuildServicesTargetTypeCount
};

enum PBCPPBuildServicesPlatform
{
	PBCPPBuildServicesPlatformNative = 0,
	PBCPPBuildServicesPlatform16Bit,
	PBCPPBuildServicesPlatform32Bit,
	PBCPPBuildServicesPlatformPowerMac,
	PBCPPBuildServicesPlatform68KMac,
	PBCPPBuildServicesPlatformFATMac,
	PBCPPBuildServicesPlatformCount
};

class PBICPPLinker :       public PBIUnknown
{
  public:
	
	virtual PBRESULT	GetTargetName( PBIString ** ) = 0;
	virtual PBRESULT	SetTargetName( PBIString * ) = 0;
 
	virtual PBRESULT	GetTargetPath( PBIString ** ) = 0;
	virtual PBRESULT	SetTargetPath( PBIString * ) = 0;

	virtual PBRESULT	GetTargetType( PBCPPBuildServicesTargetType * ) = 0;
	virtual PBRESULT	SetTargetType( PBCPPBuildServicesTargetType ) = 0;

	virtual PBRESULT	GetTargetPlatform( PBCPPBuildServicesPlatform * ) = 0;
	virtual PBRESULT	SetTargetPlatform( PBCPPBuildServicesPlatform ) = 0;

	virtual PBRESULT	GetResourceFileName( PBIString ** ) = 0;
	virtual PBRESULT	SetResourceFileName( PBIString * ) = 0;
    
	virtual PBRESULT	GetExportFileName( PBIString ** ) = 0;
	virtual PBRESULT	SetExportFileName( PBIString * ) = 0;

	virtual PBRESULT	AddLinkLibrary( PBIString * ) = 0;
	virtual PBRESULT	RemoveLinkLibrary( PBIString * ) = 0;
	virtual PBRESULT	GetLinkLibraries( PBIStringList ** ) = 0;

   	virtual PBRESULT	AddExport( PBIString * ) = 0;
	virtual PBRESULT	RemoveExport( PBIString * ) = 0;
	virtual PBRESULT	GetExports( PBIStringList ** ) = 0;
    
	virtual PBRESULT	GetIsOpenServer( PBBOOL * ) = 0;
	virtual PBRESULT	SetIsOpenServer( PBBOOL ) = 0;

	virtual PBRESULT	GetLogFileName( PBIString ** ) = 0;
	virtual PBRESULT	SetLogFileName( PBIString * ) = 0;

	virtual PBRESULT	BuildTarget( PBIBuildError ** ) = 0;
};

#endif	//	PBGCBSIF_H




