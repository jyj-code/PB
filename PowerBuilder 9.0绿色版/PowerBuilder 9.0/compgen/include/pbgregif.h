//-----------------------------------------------------------------------------
//      pbgregif.h
//      PowerBuilder generator registry interfaces.
//      wrlane  3/4/97
//
//      The interfaces declared here are provided by PowerBuilder for
//      use by both component technology generators and for the PowerBuilder
//      development environment.
//-----------------------------------------------------------------------------

#ifndef PBGREGIF_H
#define PBGREGIF_H

#ifndef PBGTYPES_H
#include "pbgtypes.h"
#endif
#ifndef PBGRUNIF_H
#include "pbgrunif.h"
#endif


extern "C"
{
extern PBIID PBIGeneratorRegistry_IID;
extern PBIID PBIGeneratorDefIterator_IID;
};


//-----------------------------------------------------------------------------
//                      PBIGeneratorRegistry 
//
//      PBIGeneratorRegistry is an interface provided by PowerBuilder for use
//      by component technology generators, and by the project painter during
//      application development.
//
//      Generators should call method Register to register themselves with
//      PowerBuilder when they are installed.  They should call Unregister
//      if they wish to uninstall themselves from the PowerBuilder environment.
//      Generators can get the registry interface itself by calling function
//      CreateRegistry.
//
//      The PowerBuilder project painter will use the registry at development
//      time to see what generators are available, and to instantiate any
//      available generator.  
//
//-----------------------------------------------------------------------------

class PBIGeneratorDefIterator;
class PBIGenerator;


class PBIGeneratorRegistry : public PBIUnknown
{
  public:

    //  Add a generator to the generator registry

    virtual PBRESULT    Register( 
		PBCLSIDREF      idInterfaceID,
		PBObjectType    pbObjectType,
		PBIString *     pDLLName ) = 0;

    virtual PBRESULT    Unregister( PBCLSIDREF idGeneratorID ) = 0;
 
    virtual PBRESULT    GetGeneratorDefIteratorFor(
		PBObjectType               pbClassType,
		PBIGeneratorDefIterator ** pGeneratorIterator ) = 0;

    virtual PBRESULT    GetGeneratorFor(
		PBCLSIDREF              idGeneratorID,
		PBIGenerator **         ppGenerator ) = 0;
};


extern "C"
{
    PBWINAPI_(PBRESULT) CreatePBIGeneratorRegistry(
		PBIGeneratorRegistry ** ppRegistry );
};



//-----------------------------------------------------------------------------
//                      PBIGeneratorDefIterator 
//
//      PBIGeneratorDefIterator is an iterator type for component technology
//      generator definitions.  It supports a simple iteration interface:
//
//      o       First
//              Sets the current item pointer to the first generator
//              definition and returns it.
//
//      o       Next
//              Fetches the next generator definition. 
//
//      These functions are declared here as pure virtual functions.  They
//      must be implemented by derived iterator types.
//      
//-----------------------------------------------------------------------------

//      TODO:   Convert to IEnumXXX style interface

class PBIGeneratorDef;

class PBIGeneratorDefIterator : public PBIUnknown
{
  public:

    virtual PBRESULT    GetFirst( PBIGeneratorDef ** ppGeneratorDef ) = 0;
    virtual PBRESULT    GetNext( PBIGeneratorDef ** ppGeneratorDef ) = 0;
    virtual PBRESULT    GetCount( PBULONG * pCount ) = 0;
};


#endif  //  PBGREGIF_H
