//              Copyright Sybase, Inc. 1996
//
//      Sybase, Inc. ("Sybase") claims copyright in this
//      program and documentation as an unpublished work, versions of
//      which were first licensed on the date indicated in the foregoing
//      notice.  Claim of copyright does not imply waiver of Sybase's
//      other rights.
//-----------------------------------------------------------------------------
//      pbggenif.h
//      PowerBuilder component generator interfaces.
//      wrlane  3/11/97
//
//      This file contains declarations for the interfaces which must be
//      implemented by any component technology generator.  
//
//-----------------------------------------------------------------------------

#ifndef PBGGENIF_H
#define PBGGENIF_H

#ifndef PBGTYPES_H
#include "pbgtypes.h"
#endif
#ifndef PBGIUNIF_H
#include "pbgiunif.h"
#endif
#ifndef PBGRUNIF_H
#include "pbgrunif.h"
#endif
#ifndef PBGCLSIF_H
#include "pbgclsif.h"
#endif
#include "obthis.h"

extern "C"
{
extern PBIID PBIGeneratorFactory_IID;
extern PBIID PBIGenerator_IID;
extern PBIID PBIGenerator2_IID;
extern PBIID PBIGeneratorDef_IID;
extern PBIID PBISessionHost_IID;
};

class PBIGeneratorFactory;
class PBIGenerator;
class PBIGeneratorDef;
class PBISessionHost;


//-----------------------------------------------------------------------------
//                      PBIGeneratorFactory 
//
//      PBIGeneratorFactory is an interface provided by component generators
//      to PowerBuilder.  It is used as a "bootstrap" interface, and provides
//      access to the other interfaces supported by the generator.
//
//      An instance of PBIGeneratorFactory is created by a call to 
//      CreatePBIGeneratorFactory( ).  Once a factory has been created,
//      other interfaces supported by the generator can be obtained by
//      calls to the factory's Create( ) method.  At a minimum, the 
//      following interfaces can be obtained through Create( ):
//
//              PBIGenerator            the primary generator interface
//              PBIGeneratorDef         information about the generator
//              PBISessionHost          other services provided by the 
//                                      generator
//
//      PBIGeneratorFactory must be implemented by all component generators.
//
//-----------------------------------------------------------------------------

class PBIGenerator;

class PBIGeneratorFactory : public PBIUnknown
{
  public:

    virtual PBRESULT CreateGenerator( 
		PBCLSIDREF      idGenereatorID,
		PBIGenerator **	ppGenerator ) = 0;
    virtual PBRESULT LockServer( PBBOOL ) = 0;
};


extern "C"
{
PBWINAPI_(PBRESULT) CreatePBIGeneratorFactory(
		PBIGeneratorFactory **  ppFactory );
};



//-----------------------------------------------------------------------------
//                      PBIGenerator 
//
//      PBIGenerator is the primary interface provided to PowerBuilder by
//      any non PowerBuilder component technology or environment.  It is
//      used by PowerBuilder during application development to create 
//      non PowerBuilder components which correspond to selected PowerBuilder
//      objects, and which can be used to create, manipulate, and destroy
//      those PowerBuilder objects during runtime.
//
//      Generation is based on the PowerBuilder class definitions of the
//      selected PowerBuilder objects, as captured in instances of interface
//      PBClassDefinition.  The details of how component generation is 
//      achieved are completely transparent to PowerBuilder itself.
//
//-----------------------------------------------------------------------------

 
class PBIGeneratorPersist;
class PBIGeneratorHost3;


class PBIGenerator : public PBIUnknown
{
  public:

    virtual PBRESULT    Reset( ) = 0;
    virtual PBRESULT    LoadFrom( PBIGeneratorPersist * pGenPersist ) = 0;
    virtual PBRESULT    SaveTo( PBIGeneratorPersist * pGenPersist ) = 0;
    virtual PBRESULT    IsDirty( PBBOOL * pbBool ) = 0;

    virtual PBRESULT    SetObjects( 
		PBIClassDef **          ppObjects,
		PBINDEX                 iObjectCount ) = 0;

    virtual PBRESULT    Generate( ) = 0;
 
    virtual PBRESULT    GetGenerationStatus( 
		PBIString **			pGenerationStatus ) = 0;
    virtual PBRESULT    GetGeneratorStatus(
		PBIString **            pResultString ) = 0;
 
    virtual PBRESULT    EditProperties( ) = 0;
    virtual PBRESULT    EditPropertiesFor( PBIClassDef * pbObject ) = 0;
    virtual PBRESULT    CanEditProperties( PBBOOL * pbBool ) = 0;
    virtual PBRESULT    CanEditPropertiesFor( 
		PBIClassDef *           pObject,
		PBBOOL *                pBool ) = 0;

    virtual PBRESULT    GetObjectType( PBObjectType * pClassType ) = 0;
    virtual PBRESULT    CanHandleMultipleObjects( PBBOOL * pbBool ) = 0;
	virtual PBRESULT	SetHost( PBIGeneratorHost3 * pGenHost ) = 0;

	virtual PBRESULT    HaveOwnSelectObjDialog( PBBOOL & bBool)
							{ bBool = PBFALSE; return PBRESULT_OK; }

	virtual PBRESULT    OnlyAllowSingleClick( PBBOOL & bBool)
							{ bBool = PBFALSE; return PBRESULT_OK; }

	virtual PBRESULT    SelectObjects(POB_THIS pbThis)
							{ return PBRESULT_OK; }

	virtual PBRESULT    AllowZeroSelectedObjects( PBBOOL & bBool )
							{ bBool = PBFALSE; return PBRESULT_OK; }

	virtual PBRESULT    IsObjectListViewDisabled( PBBOOL & bBool )
							{ bBool = PBFALSE; return PBRESULT_OK; }
};

//-----------------------------------------------------------------------------
//                      PBIGenerator2 
//
//      PBIGenerator2 is an interface which allows the generator host to get or
//      set generator specific build options.
//
//      The interface includes:
//
//      o       all PBIGenerator methods 
//
//      o       GetBuildOption
//              Returns the value for the specified build option.
//              Returned value string must be Released by the caller
//
//      o       SetBuildoption
//              Sets the value for the specified build option.
//
//-----------------------------------------------------------------------------

class PBIGenerator2 : public PBIGenerator
{
  public:
	virtual PBRESULT    GetBuildOption(PBIString * pOptionName,
									   PBIString ** ppOptionValue ) =0;
	virtual PBRESULT    SetBuildOption(PBIString * pOptionName,
									   PBIString * pOptionValue ) =0;
	virtual PBRESULT    GetBuildErrorMessage(PBIStringList ** ppErrMsg) =0;
		
	
};


//-----------------------------------------------------------------------------
//                      PBGeneratorDef 
//
//      PBGeneratorDef is an interface which provides information about a
//      PBGenerator.
//
//      o       GetID
//              Fetch the unique id for the generator.
//
//      o       GetDescShort
//              Get a short description of the generator.  The short 
//              description will be appropriate for use in selection
//              lists, etc.
//
//      o       GetDescLong
//              Get a long description of the generator.
//
//      o       GetIcon.        
//              Get the icon which graphically identifies the generator.
//
//      The PBGenerator interface for a given generator can be requested
//      from its PBGeneratorDef interface.
//
//-----------------------------------------------------------------------------

//      TODO:   Interface for Bitmap

class PBIGeneratorDef : public PBIUnknown
{
  public:

    virtual PBRESULT    GetID( PBCLSIDREF idGeneratorID ) = 0;
    virtual PBRESULT    GetDescShort( PBIString ** pDescription ) = 0;
    virtual PBRESULT    GetDescLong( PBIString ** pDescription ) = 0;
    virtual PBRESULT    GetIcon( PBBITMAP ** pBitMap ) = 0;
};



//-----------------------------------------------------------------------------
//                      PBSessionHost 
//
//      PBSessionHost specifies an interface which must be implemented
//      by all generators.  It is used by PowerBuilder to access context
//      information about the target environment, and to bootstrap interfaces
//      for any other services supported by the target environment.  
//
//-----------------------------------------------------------------------------


class PBISessionHost : public PBIUnknown
{
  public:

    //  What goes in PBSessionHost?
};

extern "C"
{
PBWINAPI_(PBRESULT) CreatePBISessionHost( PBISessionHost ** ppSessionHost );
};

#endif  //  PBGGENIF_H
