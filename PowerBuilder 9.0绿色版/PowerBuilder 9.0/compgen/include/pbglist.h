//              Copyright Sybase, Inc. 1996
//
//      Sybase, Inc. ("Sybase") claims copyright in this
//      program and documentation as an unpublished work, versions of
//      which were first licensed on the date indicated in the foregoing
//      notice.  Claim of copyright does not imply waiver of Sybase's
//      other rights.
//-----------------------------------------------------------------------------
//	pbglist.h
//
//	Simple linked list.  Doesn't use pbstg.  Contents are managed as pointer
//	to void.
//-----------------------------------------------------------------------------

#ifndef PBGLIST_H
#define PBGLIST_H

#ifndef PBGTYPES_H
#include "pbgtypes.h"
#endif
#ifndef PBGRESLT_H
#include "pbgreslt.h"
#endif

struct PBGListNode;

class PBGLinkedList
{
  public:

	PBGLinkedList( );
	virtual ~PBGLinkedList( );

	PBRESULT	Add( PBPVOID );
	PBPVOID		Remove( PBPVOID );

	PBULONG		GetCount( ) const;

	PBPVOID		GetFirst( );
	PBPVOID 	GetNext( );

	PBPVOID		GetLast( );
	PBPVOID 	GetPrevious( );
 
  private:

	PBGListNode *	m_pHead;
	PBGListNode *	m_pTail;
	PBGListNode *	m_pCurrent;
	PBULONG			m_cCount;

	PBGLinkedList( const PBGLinkedList & );
	PBGLinkedList & operator = ( const PBGLinkedList & );
};


#endif
 
