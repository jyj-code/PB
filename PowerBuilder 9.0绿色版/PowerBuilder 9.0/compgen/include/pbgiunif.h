//-----------------------------------------------------------------------------
//      pbgiunif.h
//      PBIUnknown interface definition
//      wrlane 3/10/97
//
//      PBIUnkown is the base class for all PowerBuilder interfaces.
//      It defines a minimal, common interface that all other interfaces
//      must support:
//
//      o       QueryInterface
//              Allows a user to see if a particular interface is 
//              supported by an object.
//
//      o       AddRef
//              Increment the internal count of how many other objects 
//              are currently using a given instance.
//
//      o       Release
//              Decrement the internal current user count.
//
//      These functions are declared here as pure virtual functions.  They
//      must be implemented by derived generator interface types.
//      
//      PBIUnknown is based on, and is semantically consistent with, the 
//      OLE IUnknown interface.
//
//-----------------------------------------------------------------------------

#ifndef PBGIUNIF_H
#define PBGIUNIF_H

#ifndef PBGTYPES_H
#include "pbgtypes.h"
#endif
#ifndef PBGRESLT_H 
#include "pbgreslt.h"
#endif


extern "C"
{
extern PBIID PBIUnknown_IID;
};


class PBIUnknown
{
  public:

    virtual PBWINAPI_(PBRESULT) QueryInterface(
		PBIIDREF        idInterfaceID, 
		PBIUnknown **   ppGeneratorInterface ) = 0;

    virtual PBWINAPI_(PBULONG) AddRef( ) = 0;
    virtual PBWINAPI_(PBULONG) Release( ) = 0;
};


#endif //  PBGIUIF_H
 
