//              Copyright Sybase, Inc. 1996
//
//      Sybase, Inc. ("Sybase") claims copyright in this
//      program and documentation as an unpublished work, versions of
//      which were first licensed on the date indicated in the foregoing
//      notice.  Claim of copyright does not imply waiver of Sybase's
//      other rights.
//-----------------------------------------------------------------------------
//
//  stdparse.h
//	wrlane 6/29/97
//
//-----------------------------------------------------------------------------

#ifndef STDPARSE_H
#define STDPARSE_H

#ifndef PBGPARSE_H
#include "pbgparse.h"
#endif
#ifndef PBGTYPES_H
#include "pbgtypes.h"
#endif
#ifndef PBGRUNIF_H
#include "pbgrunif.h"
#endif
#ifndef METACLSS_H
#include "metaclss.h"
#endif
#ifndef PBGDECLS_H
#include "pbgdecls.h"
#endif
 

class PBGStandardClassParser	:	public PBGClassParser
{
  public:

	PBGStandardClassParser( );
	virtual ~PBGStandardClassParser( );

	virtual PBRESULT	Parse( PBIClassDef * pClassDef );
	virtual PBVOID		Reset( );

  protected:

	virtual PBRESULT	AddAt( PBULONG, PBITypeDef * );
	virtual PBRESULT	AddAt( PBULONG, PBISimpleTypeDef * );
	virtual PBRESULT	AddAt( PBULONG,	PBIEnumerationDef * );
	virtual PBRESULT	AddAt( PBULONG,	PBIClassDef * );

	virtual PBRESULT	CheckRootClass( PBIClassDef * );
	virtual PBRESULT	CheckClass( PBIClassDef * );
	virtual PBRESULT	CheckSimpleType( PBISimpleTypeDef * );
	virtual PBRESULT	CheckEnumeration( PBIEnumerationDef * );

	virtual PBRESULT	GetCandidateVariablesFor	( PBIClassDef *,	PBIVariableDefList ** );
	virtual PBRESULT	GetCandidateScriptsFor		( PBIClassDef *,	PBIScriptDefList ** );
	virtual PBRESULT	GetCandidateNestedClassesFor( PBIClassDef *,	PBIClassDefList ** );

	virtual PBRESULT	BuildDeclFor( PBISimpleTypeDef *,	PBULONG,	PBGSimpleTypeDecl ** );
	virtual PBRESULT	BuildDeclFor( PBIEnumerationDef *, 	PBULONG,	PBGEnumerationDecl ** );
	virtual PBRESULT	BuildDeclFor( PBIClassDef *,		PBULONG,	PBGClassDecl ** );
	virtual PBRESULT	BuildDeclFor( PBIVariableDef *,		PBIClassDef *,	PBULONG,	PBGVariableDecl ** );
	virtual PBRESULT	BuildDeclFor( PBIScriptDef *,		PBIClassDef *, 	PBULONG,	PBGScriptDecl ** );

	virtual PBRESULT	CreateDeclFor( PBISimpleTypeDef *,	PBULONG,	PBGSimpleTypeDecl ** ) = 0;
	virtual PBRESULT	CreateDeclFor( PBIEnumerationDef *,	PBULONG,	PBGEnumerationDecl ** ) = 0;
	virtual PBRESULT	CreateDeclFor( PBIClassDef *,		PBULONG,	PBGClassDecl ** ) = 0;
	virtual PBRESULT	CreateDeclFor( PBIVariableDef *,	PBIClassDef *,	PBGVariableDecl ** ) = 0;
	virtual PBRESULT	CreateDeclFor( PBIScriptDef *,		PBIClassDef *,	PBGScriptDecl ** ) = 0;

	PBBOOL	m_bCollapseClassHierarchy;

  private:

	PBGStandardClassParser( const PBGStandardClassParser & );
	PBGStandardClassParser & operator = ( const PBGStandardClassParser & );
};

#endif	//	STDPARSE_H
