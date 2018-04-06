//              Copyright Sybase, Inc. 1996
//
//      Sybase, Inc. ("Sybase") claims copyright in this
//      program and documentation as an unpublished work, versions of
//      which were first licensed on the date indicated in the foregoing
//      notice.  Claim of copyright does not imply waiver of Sybase's
//      other rights.
//-----------------------------------------------------------------------------
//
//	pbgparfr.h
//	
//	"Helper" object used to format type names, perform other useful
//	operations on class definition elements.
//
//	wrlane	7/9/97
//
//-----------------------------------------------------------------------------

#ifndef PBGPARFR_H
#define PBGPARFR_H

#ifndef PBGTYPES_H
#include "pbgtypes.h"
#endif
#ifndef PBGRESLT_H
#include "pbgreslt.h"
#endif
#ifndef PBGCLSIF_H
#include "pbgclsif.h"
#endif

class PBGFormatter
{
  public:
	
	PBGFormatter( );
	PBGFormatter( const PBGFormatter & );

	virtual ~PBGFormatter( );

	PBGFormatter & operator = ( const PBGFormatter & );

	virtual PBRESULT	ClassNameFor( PBIClassDef *, PBIString ** );

	virtual	PBRESULT	NativeNameFor( PBIVariableDef *, PBIString ** );
	virtual	PBRESULT	NativeNameFor( PBITypeDef *, PBIString ** );
 
	virtual	PBRESULT	PBNameFor( PBIVariableDef *, PBIString ** );
	virtual	PBRESULT	PBNameFor( PBITypeDef *, PBIString ** );
 
	virtual	PBRESULT	ValueNameFor( PBIVariableDef *, PBIString ** );
	virtual	PBRESULT	ValueNameFor( PBITypeDef *, PBIString ** );

	virtual PBRESULT	IsAnInterface( PBIVariableDef *, PBBOOL & );
	virtual PBRESULT	IsAnInterface( PBITypeDef *, PBBOOL & );
};

#endif	//	PBGPARFR_H


