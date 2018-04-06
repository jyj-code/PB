//              Copyright Sybase, Inc. 1996
//
//      Sybase, Inc. ("Sybase") claims copyright in this
//      program and documentation as an unpublished work, versions of
//      which were first licensed on the date indicated in the foregoing
//      notice.  Claim of copyright does not imply waiver of Sybase's
//      other rights.
//-----------------------------------------------------------------------------
//
//  pbgpardc.h
//
//  The PBGClassParser works by decomposing a PBIClassDef into an
//  in-memory network of related "Def" types (e.g., PBIClassDef, PBIScriptDef,
//  PBIVariableDef, etc.).  The "Decl" types defined here represent the nodes
//  in this network.  Each caches a pointer to a particular "Def" type.
//
//  The "Decl" types also allow you to fetch one or more emitter types.  Each
//  of these emitters are dedicated to writing a particular generator output 
//  for the type encapsulated by the declarator.
//
//  wrlane  6/29/97
//
//-----------------------------------------------------------------------------

#ifndef PBGPARDC_H
#define PBGPARDC_H

#ifndef PBGTYPES_H
#include "pbgtypes.h"
#endif
#ifndef PBGRESLT_H
#include "pbgreslt.h"
#endif
#ifndef PBGCLSIF_H
#include "pbgclsif.h"
#endif
#ifndef PBGLIST_H
#include "pbglist.h"
#endif
#ifndef PBGPAROP_H
#include "pbgparop.h"
#endif

class PBGDecl;
class PBGTypeDecl;
class PBGSimpleTypeDecl;
class PBGEnumerationDecl;
class PBGClassDecl;
class PBGVariableDecl;
class PBGScriptDecl;
class PBGEmitter;

class ostream;

//-----------------------------------------------------------------------------

class PBGEmitter
{
  public:

	virtual ~PBGEmitter( );
	virtual PBRESULT WriteTo( ostream &, PBGOptions & );

  protected:

	PBGEmitter( );

  private:

	PBGEmitter( const PBGEmitter & );
	PBGEmitter & operator = ( const PBGEmitter & );
};

//-----------------------------------------------------------------------------

class PBGDecl
{
  public:

	virtual ~PBGDecl( );
	virtual PBRESULT GetEmitterFor( PBIString *, PBGEmitter ** );

  protected:

	PBGDecl( );

  private:

	PBGDecl( const PBGDecl & );
	PBGDecl & operator = ( const PBGDecl & );
};

//-----------------------------------------------------------------------------

class PBGTypeDecl	:	public PBGDecl
{
  public:

	virtual ~PBGTypeDecl( );

	virtual PBITypeDef *	GetTypeDef( );
	virtual PBINDEX			GetDepth( );
	virtual PBTypeCategory	GetCategory( );

	virtual PBIString *	GetInternalTypeName( );
	virtual PBRESULT	SetInternalTypeName( PBIString * );
	virtual PBIString *	GetExternalTypeName( );
	virtual PBRESULT	SetExternalTypeName( PBIString * );

  protected:

	PBGTypeDecl( PBITypeDef * pTypeDef, PBINDEX ulDepth, PBTypeCategory eCategory );
	virtual PBVOID	InitTypeDecl( PBITypeDef *, PBINDEX, PBTypeCategory );

	PBITypeDef *		m_pTypeDef;
	PBINDEX				m_iDepth;
	PBTypeCategory		m_eCategory;
	PBIString *		m_pInternalTypeName;
	PBIString *		m_pExternalTypeName;

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

	virtual PBISimpleTypeDef *	GetSimpleTypeDef( );

  protected:

	PBGSimpleTypeDecl( PBISimpleTypeDef *, PBINDEX );
	virtual PBVOID	InitSimpleTypeDecl( PBISimpleTypeDef *, PBINDEX );

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

	virtual PBIEnumerationDef *	GetEnumerationDef( );
 
  protected:

	PBGEnumerationDecl( PBIEnumerationDef *, PBINDEX );
	virtual PBVOID	InitEnumerationDecl( PBIEnumerationDef *, PBINDEX );

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

	virtual PBIClassDef *	GetClassDef( );

	virtual PBRESULT	AddVariable		( PBGVariableDecl * pVariableDecl );
	virtual PBRESULT	AddScript		( PBGScriptDecl * 	pScriptDecl );
	virtual PBRESULT	AddNestedClass	( PBGClassDecl *	pNestedClassDecl );

  protected:

	PBGClassDecl( PBIClassDef *, PBINDEX );
	virtual PBVOID	InitClassDecl( PBIClassDef *, PBINDEX );

	PBGLinkedList		m_VariableList;
	PBGLinkedList		m_ScriptList;
	PBGLinkedList		m_NestedClassList;

  private:

	PBGClassDecl( );
	PBGClassDecl( const PBGClassDecl & );
	PBGClassDecl & operator = ( const PBGClassDecl & );
};

//-----------------------------------------------------------------------------

class PBGVariableDecl	:	public PBGDecl
{
  public:

	virtual ~PBGVariableDecl( );

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

class PBGScriptDecl	:	public PBGDecl
{
  public:

	virtual ~PBGScriptDecl( );

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


#endif	//	PBGPARDC_H
