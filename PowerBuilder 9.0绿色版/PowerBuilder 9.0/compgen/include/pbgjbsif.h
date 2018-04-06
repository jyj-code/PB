//              Copyright Sybase, Inc. 1996
//
//      Sybase, Inc. ("Sybase") claims copyright in this
//      program and documentation as an unpublished work, versions of
//      which were first licensed on the date indicated in the foregoing
//      notice.  Claim of copyright does not imply waiver of Sybase's
//      other rights.
//-----------------------------------------------------------------------------
//	These interfaces encapsulate the Java compiler that is used by 
//	PowerBuilder to build java bytecode.  The particular toolset will
//	vary by platform.  These interfaces may be queried from an instance
//	of PBIBuildServices that is created with PBIJProxyBuildServices_CLSID.
//-----------------------------------------------------------------------------


#ifndef PBGJBSIF_H
#define PBGJBSIF_H

#ifndef PBGDEVIF_H
#include "pbgdevif.h"
#endif
 
//	GUID for the Java BuildServices

extern "C"
{
  extern PBCLSID  PBIJProxyBuildServices_CLSID;
  extern PBIID	  PBIJProxySourceCompiler_IID;
  extern PBIID	  PBIJProxyJarUtility_IID;
};

//      forward declarations for convenience.

class PBIHProxySourceCompiler;
class PBIJProxyJarUtility_IID;

//-----------------------------------------------------------------------------
//                     PBISourceCompiler
//-----------------------------------------------------------------------------

enum PBJProxySourceCompilerOptimization
{
  PBJProxySourceCompilerOptimizationNone = 0,
  PBJProxySourceCompilerOptimizationSize,
  PBJProxySourceCompilerOptimizationSpeed,
  PBJProxySourceCompilerOptimizationCount 
};

class PBIJProxySourceCompiler   :   public PBIUnknown
{
public:
 
  virtual PBRESULT  GetSourcePath( PBIString ** ppPath ) = 0;
  virtual PBRESULT  SetSourcePath( PBIString * pPath ) = 0;
		  
  virtual PBRESULT  GetOptimization( PBJProxySourceCompilerOptimization * ) = 0;
  virtual PBRESULT  SetOptimization( PBJProxySourceCompilerOptimization ) = 0;
		  
  virtual PBRESULT  IsDebugOn( PBBOOL * pDebug ) = 0;
  virtual PBRESULT  SetDebugOn( PBBOOL bDebug ) = 0;
		  
  virtual PBRESULT  AddClasspath( PBIString * ) = 0;
  virtual PBRESULT  RemoveClasspath( PBIString * ) = 0;
  virtual PBRESULT  GetClasspath( PBIStringList ** ) = 0;
		  
  virtual PBRESULT  AddDefineSymbol( PBIString * ) = 0;
  virtual PBRESULT  RemoveDefineSymbol( PBIString * ) = 0;
  virtual PBRESULT  GetDefineSymbols( PBIStringList ** ) = 0;
		  
  virtual PBRESULT  Compile( PBIString *, PBIBuildError ** ) = 0;
};

#endif	//	PBGJBSIF_H




