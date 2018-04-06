//              Copyright Sybase, Inc. 1996
//
//      Sybase, Inc. ("Sybase") claims copyright in this
//      program and documentation as an unpublished work, versions of
//      which were first licensed on the date indicated in the foregoing
//      notice.  Claim of copyright does not imply waiver of Sybase's
//      other rights.
//-----------------------------------------------------------------------------
//
//  pbgdecls.h
//
//  The PBGClassParser works by decomposing a PBIClassDef into an
//  in-memory network of related "Def" types (e.g., PBIClassDef, PBIScriptDef,
//  PBIVariableDef, etc.).  The "Decl" types defined here represent the nodes
//  in this network.  Each caches a pointer to a particular "Def" type, and
//  provides methods for generating the header (WriteDeclTo) and implementation
//  (WriteImplTo) code for the "Def" that it manages.  
//
//  wrlane  6/29/97
//
//-----------------------------------------------------------------------------

#ifndef PBGDECLS_H
#define PBGDECLS_H

#ifndef PBGTYPES_H
#include "pbgtypes.h"
#endif
#ifndef PBGRESLT_H
#include "pbgreslt.h"
#endif
#ifndef METACLSS_H
#include "metaclss.h"
#endif
#ifndef PBGLIST_H
#include "pbglist.h"
#endif
#ifndef PBGOPT_H
#include "pbgopt.h"
#endif

class PBGTypeDecl;
class PBGSimpleTypeDecl;
class PBGEnumerationDecl;
class PBGClassDecl;
class PBGVariableDecl;
class PBGScriptDecl;

class ostream;

//-----------------------------------------------------------------------------

class PBGTypeDecl
{
  public:

	virtual ~PBGTypeDecl( );

	virtual PBRESULT	WriteDeclTo( ostream & os, PBGOptions & options ) = 0;
	virtual PBRESULT	WriteImplTo( ostream & os, PBGOptions & options ) = 0;

	virtual PBITypeDef *	GetTypeDef( );
	virtual PBULONG			GetDepth( );
	virtual PBTypeCategory	GetCategory( );

  protected:

	PBGTypeDecl( PBITypeDef * pTypeDef, PBULONG ulDepth, PBTypeCategory eCategory );
	virtual PBVOID	InitTypeDecl( PBITypeDef *, PBULONG, PBTypeCategory );

	PBITypeDef *		m_pTypeDef;
	PBULONG				m_ulDepth;
	PBTypeCategory		m_eCategory;

  private:

	PBGTypeDecl( );
	PBGTypeDecl( const PBGTypeDecl & );
	PBGTypeDecl & operator = ( const PBGTypeDecl & );
};

//-----------------------------------------------------------------------------

class PBGSimpleTypeDecl	:	public PBGTypeDecl
{
  public:
	
	virtual ~PBGSimpleTypeDecl( );

	virtual PBRESULT	WriteDeclTo( ostream & os, PBGOptions & options ) = 0;
	virtual PBRESULT	WriteImplTo( ostream & os, PBGOptions & options ) = 0;
 
	virtual PBISimpleTypeDef *	GetSimpleTypeDef( );

  protected:

	PBGSimpleTypeDecl( PBISimpleTypeDef * pSimpleTypeDef, PBULONG ulDepth );
	virtual PBVOID	InitSimpleTypeDecl( PBISimpleTypeDef *, PBULONG );

  private:

	PBGSimpleTypeDecl( );
	PBGSimpleTypeDecl( const PBGSimpleTypeDecl & );
	PBGSimpleTypeDecl & operator = ( const PBGSimpleTypeDecl & );
};

//-----------------------------------------------------------------------------
 
class PBGEnumerationDecl	:	public PBGTypeDecl
{
  public:

	virtual ~PBGEnumerationDecl( );

	virtual PBRESULT	WriteDeclTo( ostream & os, PBGOptions & options ) = 0;
	virtual PBRESULT	WriteImplTo( ostream & os, PBGOptions & options ) = 0;
 
	virtual PBIEnumerationDef *	GetEnumerationDef( );
 
  protected:

	PBGEnumerationDecl( PBIEnumerationDef * pEnumerationDef, PBULONG ulDepth );
	virtual PBVOID	InitEnumerationDecl( PBIEnumerationDef *, PBULONG );

  private:

	PBGEnumerationDecl( );
	PBGEnumerationDecl( const PBGEnumerationDecl & );
	PBGEnumerationDecl & operator = ( const PBGEnumerationDecl & );
};

//-----------------------------------------------------------------------------
 
class PBGClassDecl	:	public PBGTypeDecl
{
  public:

	virtual ~PBGClassDecl( );

	virtual PBRESULT	WriteDeclTo( ostream & os, PBGOptions & options ) = 0;
	virtual PBRESULT	WriteImplTo( ostream & os, PBGOptions & options ) = 0;

	virtual PBIClassDef *	GetClassDef( );

	virtual PBRESULT	AddVariable		( PBGVariableDecl * pVariableDecl );
	virtual PBRESULT	AddScript		( PBGScriptDecl * 	pScriptDecl );
	virtual PBRESULT	AddNestedClass	( PBGClassDecl *	pNestedClassDecl );

  protected:

	PBGClassDecl( PBIClassDef * pClassDef, PBULONG ulDepth );
	virtual PBVOID	InitClassDecl( PBIClassDef *, PBULONG );

	PBGLinkedList		m_VariableList;
	PBGLinkedList		m_ScriptList;
	PBGLinkedList		m_NestedClassList;

  private:

	PBGClassDecl( );
	PBGClassDecl( const PBGClassDecl & );
	PBGClassDecl & operator = ( const PBGClassDecl & );
};

//-----------------------------------------------------------------------------

class PBGVariableDecl
{
  public:

	virtual ~PBGVariableDecl( );

	virtual PBRESULT	WriteDeclTo( ostream & os, PBGOptions & options ) = 0;
	virtual PBRESULT	WriteImplTo( ostream & os, PBGOptions & options ) = 0;
 
	virtual PBIVariableDef *	GetVariableDef( );
	virtual PBIClassDef *		GetClassDef( );

  protected:

	PBGVariableDecl( PBIVariableDef * pVariableDef, PBIClassDef * pClassDef );
	virtual PBVOID	InitVariableDecl( PBIVariableDef *, PBIClassDef * );

	PBIVariableDef *	m_pVariableDef;
	PBIClassDef *		m_pClassDef;
 
  private:

	PBGVariableDecl( );
	PBGVariableDecl( const PBGVariableDecl & );
	PBGVariableDecl & operator = ( const PBGVariableDecl & );
};

//-----------------------------------------------------------------------------

class PBGScriptDecl
{
  public:

	virtual ~PBGScriptDecl( );

	virtual PBRESULT	WriteDeclTo( ostream & os, PBGOptions & options ) = 0;
	virtual PBRESULT	WriteImplTo( ostream & os, PBGOptions & options ) = 0;

	virtual PBIScriptDef *	GetScriptDef( );
	virtual PBIClassDef *	GetClassDef( );

  protected:

	PBGScriptDecl( PBIScriptDef * pScriptDef, PBIClassDef * pClassDef );
	virtual PBVOID	InitScriptDecl( PBIScriptDef *, PBIClassDef * );

	PBIScriptDef *		m_pScriptDef;
	PBIClassDef *		m_pClassDef;

  private:

	PBGScriptDecl( );
	PBGScriptDecl( const PBGScriptDecl & );
	PBGScriptDecl & operator = ( const PBGScriptDecl & );
};

#endif	//	PBGDECLS_H
