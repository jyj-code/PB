//              Copyright Sybase, Inc. 1996
//
//      Sybase, Inc. ("Sybase") claims copyright in this
//      program and documentation as an unpublished work, versions of
//      which were first licensed on the date indicated in the foregoing
//      notice.  Claim of copyright does not imply waiver of Sybase's
//      other rights.
//----------------------------------------------------------------------------
//	pbgparfl.h
//
//	Simple filter types for iterating through the PBGClassParser type
//	list.  Each filter is dedicated to returning only a specific subset 
//	of the list contents.
//
//	wrlane
//----------------------------------------------------------------------------

#ifndef PBGPARFL_H
#define PBGPARFL_H

#ifndef PBGTYPES_H
#include "pbgtypes.h"
#endif

class PBGSimpleTypeFilter;
class PBGEnumerationFilter;
class PBGClassFilter;
class PBGClassAndDepthFilter;

class PBGLinkedList;
class PBGSimpleTypeDecl;
class PBGEnumerationDecl;
class PBGClassDecl;

class PBGSimpleTypeFilter
{
  public:

    PBGSimpleTypeFilter( PBGLinkedList & TypeList );
    ~PBGSimpleTypeFilter( );

    PBGSimpleTypeDecl *  GetFirst( );
    PBGSimpleTypeDecl *  GetNext( );
 
    PBGSimpleTypeDecl *  GetLast( );
    PBGSimpleTypeDecl *  GetPrevious( );

  private:

    PBGLinkedList &	m_TypeList;

    PBGSimpleTypeFilter( );
    PBGSimpleTypeFilter( const PBGSimpleTypeFilter & );
    PBGSimpleTypeFilter & operator = ( const PBGSimpleTypeFilter & );
};

//----------------------------------------------------------------------------

class PBGEnumerationFilter
{
  public:

    PBGEnumerationFilter( PBGLinkedList & TypeList );
    ~PBGEnumerationFilter( );

    PBGEnumerationDecl *  GetFirst( );
    PBGEnumerationDecl *  GetNext( );
 
    PBGEnumerationDecl *  GetLast( );
    PBGEnumerationDecl *  GetPrevious( );

  private:

    PBGLinkedList &	m_TypeList;

    PBGEnumerationFilter( );
    PBGEnumerationFilter( const PBGEnumerationFilter & );
    PBGEnumerationFilter & operator = ( const PBGEnumerationFilter & );
};

//----------------------------------------------------------------------------

class PBGClassFilter
{
  public:

    PBGClassFilter( PBGLinkedList & TypeList );
    ~PBGClassFilter( );

    PBGClassDecl *  GetFirst( );
    PBGClassDecl *  GetNext( );
 
    PBGClassDecl *  GetLast( );
    PBGClassDecl *  GetPrevious( );

  private:

    PBGLinkedList &	m_TypeList;

    PBGClassFilter( );
    PBGClassFilter( const PBGClassFilter & );
    PBGClassFilter & operator = ( const PBGClassFilter & );
};

//----------------------------------------------------------------------------

class PBGClassAndDepthFilter
{
  public:

    PBGClassAndDepthFilter( PBGLinkedList & TypeList, PBINDEX iDepth );
    ~PBGClassAndDepthFilter( );

    PBGClassDecl *  GetFirst( );
    PBGClassDecl *  GetNext( );
 
    PBGClassDecl *  GetLast( );
    PBGClassDecl *  GetPrevious( );

  private:

    PBGLinkedList &	m_TypeList;
	PBINDEX			m_iDepth;

    PBGClassAndDepthFilter( );
    PBGClassAndDepthFilter( const PBGClassAndDepthFilter & );
    PBGClassAndDepthFilter & operator = ( const PBGClassAndDepthFilter & );
};


#endif	//	PBGPARFL_H
