//              Copyright Sybase, Inc. 1996
//
//      Sybase, Inc. ("Sybase") claims copyright in this
//      program and documentation as an unpublished work, versions of
//      which were first licensed on the date indicated in the foregoing
//      notice.  Claim of copyright does not imply waiver of Sybase's
//      other rights.

#ifndef PBGOPT_H
#define PBGOPT_H

#ifndef PBGLIST_H
#include "pbglist.h"
#endif

class PBIString;
class PBIValue;


class PBGOptions
{
  public:

	PBGOptions( );
	PBGOptions( PBGOptions & );
	virtual ~PBGOptions( );

	PBGOptions & operator = ( PBGOptions & );

	virtual PBRESULT	SetOption( PBIString * pName, PBIValue * pValue );
	virtual PBIValue *	GetOption( PBIString * pName );
	virtual PBVOID		Reset( );

  private:

	PBVOID	CleanUp( );
	PBVOID 	CopyFrom( PBGOptions & );

	struct Option
	{
		PBIString *	m_pName;
		PBIValue *	m_pValue;
	};

	PBGLinkedList	m_OptionList;
};

#endif
