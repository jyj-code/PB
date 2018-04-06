//              Copyright Sybase, Inc. 1996
//
//      Sybase, Inc. ("Sybase") claims copyright in this
//      program and documentation as an unpublished work, versions of
//      which were first licensed on the date indicated in the foregoing
//      notice.  Claim of copyright does not imply waiver of Sybase's
//      other rights.
//-----------------------------------------------------------------------------
//
//  pbgparse.h
//
//  Base class for a generalized parser for PB class definitions.  This
//  object will traverse a PBIClassDef and build an in-memory network of
//  declarator types which reflects the class definition.  It also populates
//  a type list, which is a simple linked list of declarator objects for all
//  types found during the traversal.  This list of declarators can then
//  be walked by the generator in whatever order is desired, and each 
//  declarator can be asked to emit declaration and/or implementation code
//  as needed to create the generated code base.
//
//  This class is intended to act as a base class for more specialized
//  parsers.  Several of the functions have useful default implementations
//  which are documented elsewhere.  You should review that documentation
//  and the source code to see if the default implementation suits your needs.
//  It is MANDATORY to override the pure virtual functions found in the
//  private area of the interface.
//
//  wrlane 6/29/97
//
//-----------------------------------------------------------------------------

#ifndef PBGPARSE_H
#define PBGPARSE_H

#ifndef PBGTYPES_H
#include "pbgtypes.h"
#endif
#ifndef PBGRESLT_H
#include "pbgreslt.h"
#endif
#ifndef PBGLIST_H
#include "pbglist.h"
#endif
#ifndef METACLSS_H
#include "metaclss.h"
#endif
#ifndef PBGDECLS_H
#include "pbgdecls.h"
#endif
#ifndef PBGOPT_H
#include "pbgopt.h"
#endif

//	Special error codes

#define PBRESULT_ILLEGAL_OBJECT \
	MAKE_PBRESULT(SEVERITY_ERROR, PBMODULE_GENERATOR, 0x1000)


class PBGClassParser
{
  public:

	virtual PBRESULT	SetOptions( PBGOptions & );
	virtual PBRESULT	Parse( PBIClassDef * pClassDef ) = 0;
	virtual PBVOID		Reset( );

	PBGLinkedList &		GetTypeList( );

  protected:

	PBGClassParser( );
	virtual ~PBGClassParser( );

	virtual	PBVOID		FailFor( PBIClassDef * ) = 0;
	virtual PBVOID		LogErrorFor( PBIClassDef * ) = 0;
 
	virtual PBBOOL		IsInTypeList( PBITypeDef * );

	virtual PBRESULT	AddAt( PBULONG, PBITypeDef * );
	virtual PBRESULT	AddAt( PBULONG, PBISimpleTypeDef * );
	virtual PBRESULT	AddAt( PBULONG,	PBIEnumerationDef * );
	virtual PBRESULT	AddAt( PBULONG,	PBIClassDef * );

	virtual PBRESULT	CheckRootClass( PBIClassDef * );
	virtual PBRESULT	CheckClass( PBIClassDef * );
	virtual PBRESULT	CheckSimpleType( PBISimpleTypeDef * );
	virtual PBRESULT	CheckEnumeration( PBIEnumerationDef * );

	virtual PBRESULT 	GetCandidateVariablesFor	( PBIClassDef *,	PBIVariableDefList ** );
	virtual PBRESULT 	GetCandidateScriptsFor		( PBIClassDef *,	PBIScriptDefList ** );
	virtual PBRESULT 	GetCandidateNestedClassesFor( PBIClassDef *,	PBIClassDefList ** );

	virtual PBRESULT	BuildDeclFor( PBISimpleTypeDef *,	PBULONG,	PBGSimpleTypeDecl ** );
	virtual PBRESULT 	BuildDeclFor( PBIEnumerationDef *, 	PBULONG,	PBGEnumerationDecl ** );
	virtual PBRESULT	BuildDeclFor( PBIClassDef *,		PBULONG,	PBGClassDecl ** );
	virtual	PBRESULT	BuildDeclFor( PBIVariableDef *,		PBIClassDef *, 	PBULONG,	PBGVariableDecl ** );
	virtual PBRESULT	BuildDeclFor( PBIScriptDef *,		PBIClassDef *,	PBULONG,	PBGScriptDecl ** );

	virtual PBRESULT	CreateDeclFor( PBISimpleTypeDef *,	PBULONG,	PBGSimpleTypeDecl ** );
	virtual PBRESULT	CreateDeclFor( PBIEnumerationDef *,	PBULONG, 	PBGEnumerationDecl ** );
	virtual PBRESULT	CreateDeclFor( PBIClassDef *,		PBULONG,	PBGClassDecl ** );
	virtual PBRESULT	CreateDeclFor( PBIVariableDef *,	PBIClassDef *,	PBGVariableDecl ** );
	virtual PBRESULT	CreateDeclFor( PBIScriptDef *,		PBIClassDef *,	PBGScriptDecl ** );

	PBGOptions			m_Options;
	PBGLinkedList 		m_TypeList;
	PBIString *			m_pErrorMessage;

  private:

	PBGClassParser( const PBGClassParser & );
	PBGClassParser & operator = ( const PBGClassParser & );
};

#endif	//	PBGPARSE_H
