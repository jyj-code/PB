//              Copyright Sybase, Inc. 1996
//
//      Sybase, Inc. ("Sybase") claims copyright in this
//      program and documentation as an unpublished work, versions of
//      which were first licensed on the date indicated in the foregoing
//      notice.  Claim of copyright does not imply waiver of Sybase's
//      other rights.
//-----------------------------------------------------------------------------
//
//  pbgparpr.h
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
//  wrlane 6/29/97
//
//-----------------------------------------------------------------------------

#ifndef PBGPARPR_H
#define PBGPARPR_H

#ifndef PBGTYPES_H
#include "pbgtypes.h"
#endif
#ifndef PBGRESLT_H
#include "pbgreslt.h"
#endif
#ifndef PBGLIST_H
#include "pbglist.h"
#endif
#ifndef PBGCLSIF_H
#include "pbgclsif.h"
#endif
#ifndef PBGPARDC_H
#include "pbgpardc.h"
#endif
#ifndef PBGPAROP_H
#include "pbgparop.h"
#endif

//	Special error codes

#define PBRESULT_ERR_PBGPARPR_VISUAL_OBJECT \
	MAKE_PBRESULT(SEVERITY_ERROR, PBMODULE_GENERATOR, 0x1002)
#define PBRESULT_ERR_PBGPARPR_SYSTEM_OBJECT \
	MAKE_PBRESULT(SEVERITY_ERROR, PBMODULE_GENERATOR, 0x1001)


class PBGClassParser
{
  public:

	virtual PBRESULT	SetOptions( PBGOptions & );
	virtual PBRESULT	Parse( PBIClassDef * pClassDef );
	virtual PBVOID		Reset( );

	PBGLinkedList &		GetTypeList( );
	PBINDEX				GetDeepestLevel( ) const;
	PBVOID				GetErrorMessage( PBIString ** );

  protected:

	PBGClassParser( );
	virtual ~PBGClassParser( );

	virtual PBBOOL		IsInTypeList( PBIString *, PBTypeCategory );

	PBGOptions			m_Options;
	PBGLinkedList 		m_TypeList;
	PBINDEX				m_iDeepest;
	PBIString *			m_pErrorMessage;

  private:

	PBGClassParser( const PBGClassParser & );
	PBGClassParser & operator = ( const PBGClassParser & );
};

//---------------------------------------------------------------------------

inline PBVOID PBGClassParser::GetErrorMessage( PBIString ** ppMessage )
{
	if (m_pErrorMessage) m_pErrorMessage->AddRef( );
	*ppMessage = m_pErrorMessage;
}


#endif	//	PBGPARPR_H
