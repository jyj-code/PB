//              Copyright Sybase, Inc. 1996
//
//      Sybase, Inc. ("Sybase") claims copyright in this
//      program and documentation as an unpublished work, versions of
//      which were first licensed on the date indicated in the foregoing
//      notice.  Claim of copyright does not imply waiver of Sybase's
//      other rights.
//-----------------------------------------------------------------------------
//
//  pbgstdpr.h
//	wrlane 6/29/97
//
//-----------------------------------------------------------------------------

#ifndef PBGSTDPR_H
#define PBGSTDPR_H

#ifndef PBGPARPR_H
#include "pbgparpr.h"
#endif
#ifndef PBGTYPES_H
#include "pbgtypes.h"
#endif
#ifndef PBGRUNIF_H
#include "pbgrunif.h"
#endif
#ifndef PBGPARDC_H
#include "pbgpardc.h"
#endif
#include "pbgstrls.h"

class PBGParentList;

class PBGStandardClassParser	:	public PBGClassParser
{
	public:

		PBGStandardClassParser( );
		virtual ~PBGStandardClassParser( );

		virtual PBRESULT	SetOptions( PBGOptions & option );
		virtual PBRESULT	Parse( PBIClassDef * pClassDef );
		virtual PBVOID		Reset( );

		virtual PBBOOL      HasRecursiveReferences() { return m_bHasRecursion; }
		virtual void        ResetRecursiveReferenceIndicator() { m_bHasRecursion = PBFALSE; }

	protected:

		virtual PBRESULT	AddAt( PBINDEX, PBITypeDef * );
		virtual PBRESULT	AddAt( PBINDEX, PBISimpleTypeDef * );
		virtual PBRESULT	AddAt( PBINDEX,	PBIEnumerationDef * );
		virtual PBRESULT	AddAt( PBINDEX,	PBIClassDef * );

		virtual PBRESULT	CheckRootClass( PBIClassDef * );
		virtual PBRESULT	CheckAncestorClass( PBIClassDef * );
		virtual PBRESULT	CheckClass( PBIClassDef * );
		virtual PBRESULT	CheckSimpleType( PBISimpleTypeDef * );
		virtual PBRESULT	CheckEnumeration( PBIEnumerationDef * );

		virtual PBRESULT	GetCandidateVariablesFor	( PBIClassDef *,	PBIVariableDefList ** );
		virtual PBRESULT	GetCandidateScriptsFor		( PBIClassDef *,	PBIScriptDefList ** );
		virtual PBRESULT	GetCandidateNestedClassesFor( PBIClassDef *,	PBIClassDefList ** );

		virtual PBRESULT	BuildDeclFor( PBISimpleTypeDef *,	PBINDEX,	PBGSimpleTypeDecl ** );
		virtual PBRESULT	BuildDeclFor( PBIEnumerationDef *, 	PBINDEX,	PBGEnumerationDecl ** );
		virtual PBRESULT	BuildDeclFor( PBIClassDef *,		PBINDEX,	PBGClassDecl ** );
		virtual PBRESULT	BuildDeclFor( PBIVariableDef *,		PBIClassDef *,	PBINDEX,	PBGVariableDecl ** );
		virtual PBRESULT	BuildDeclFor( PBIScriptDef *,		PBIClassDef *, 	PBINDEX,	PBGScriptDecl ** );

		virtual PBRESULT	CreateDeclFor( PBISimpleTypeDef *,	PBINDEX,	PBGSimpleTypeDecl ** );
		virtual PBRESULT	CreateDeclFor( PBIEnumerationDef *,	PBINDEX,	PBGEnumerationDecl ** );
		virtual PBRESULT	CreateDeclFor( PBIClassDef *,		PBINDEX,	PBGClassDecl ** );
		virtual PBRESULT	CreateDeclFor( PBIVariableDef *,	PBIClassDef *,	PBGVariableDecl ** );
		virtual PBRESULT	CreateDeclFor( PBIScriptDef *,		PBIClassDef *,	PBGScriptDecl ** );

		PBBOOL	m_bCollapseClassHierarchy;
		PBBOOL	m_bIncludeEventsInScriptList;
	    PBBOOL  m_bAllowVisualTypes;
	

	private:
		PBGStringList * m_pTempAncestorlist;
		PBGStringList * m_pRecursivelist;	
		PBBOOL          m_bHasRecursion;

		PBGStandardClassParser( const PBGStandardClassParser & );
		PBGStandardClassParser & operator = ( const PBGStandardClassParser & );
};

#endif	//	PBGPARPR_H
