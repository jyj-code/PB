//              Copyright Sybase, Inc. 1996
//
//      Sybase, Inc. ("Sybase") claims copyright in this
//      program and documentation as an unpublished work, versions of
//      which were first licensed on the date indicated in the foregoing
//      notice.  Claim of copyright does not imply waiver of Sybase's
//      other rights.
//-----------------------------------------------------------------------------
//      pbgrunif.h
//	Generator runtime interface declarations.
//	wrlane	6/13/97
//-----------------------------------------------------------------------------

#ifndef PBGRUNIF_H
#define PBGRUNIF_H

#ifndef PBGIUNIF_H
#include "pbgiunif.h"
#endif
#ifndef PBGTYPIF_H
#include "pbgtypif.h"
#endif

//	Interface ID's

extern "C"
{
extern PBIID PBISession_IID;
extern PBIID PBISessionSecurity_IID;
extern PBIID PBIContext_IID;
extern PBIID PBIInstance_IID;
extern PBIID PBIArgument_IID;
extern PBIID PBIValue_IID;
extern PBIID PBIArray_IID;
extern PBIID PBIArrayBounds_IID;
extern PBIID PBIArrayBoundsList_IID;
extern PBIID PBIException_IID;
extern PBIID PBInstanceValueDispatch_CLSID;
};

//	Forward declarations for convenience.

class PBISession;
class PBISessionSecurity;
class PBIContext;
class PBIInstance;
class PBIArgument;
class PBIValue;
class PBIArray;
class PBIArrayBounds;
class PBIArrayBoundsList;
class PBIException;

//	Forward declarations to avoid header include cycles.

class PBIClassDef;
class PBITypeDef;
class PBIScriptDef;

//-----------------------------------------------------------------------------
//                              PBISession
//-----------------------------------------------------------------------------

class PBISession : public PBIUnknown
{
  public:

	virtual PBWINAPI_(PBRESULT) CreateInstance(PBIString *     pInstanceName,PBIInstance **  pInstance ) = 0;
	virtual PBWINAPI_(PBRESULT) FindClassDefinition(PBIString *     pClassName,PBIClassDef **  ppClassDef ) = 0;
	virtual PBWINAPI_(PBRESULT) FindTypeDefinition(PBIString *     pTypeName,PBITypeDef **   ppTypeDef ) = 0;
	virtual PBWINAPI_(PBRESULT) FindScriptDefinition(PBIString *      pScriptName,PBIScriptDef **  ppScriptDef ) = 0;
	virtual PBWINAPI_(PBRESULT) GetContext(PBIContext ** 	ppContext ) = 0;
	virtual PBWINAPI_(PBRESULT) GetLibraryList(PBIString ** ) = 0;
	virtual PBWINAPI_(PBRESULT) GetOB_THIS(void **) =0;

};

class PBISessionSecurity	:	public PBIUnknown
{
	virtual PBWINAPI_(PBRESULT)	IsSecurityModeSet(
			PBSessionSecurityMode eSecurityMode,
			PBBOOL * bIsSet ) = 0;
	virtual PBWINAPI_(PBRESULT)	SetSecurityMode(
			PBSessionSecurityMode eSecurityMode,
			PBBOOL bSetMode ) = 0;
};

extern "C"
{
    PBWINAPI_(PBRESULT) CreatePBISession(
        PBIString *     pApplicationName,
        PBIString *     pLibraryList,
        PBLibraryType   enmLibraryType,
		PBIContext *	pContext,
        PBISession **   ppSession );
};

//-----------------------------------------------------------------------------
//							PBIContext
//-----------------------------------------------------------------------------

class PBIContext	:	public PBIUnknown
{
  public:

	virtual PBWINAPI_(PBRESULT)	GetService(
		PBISession *	pSession,
		PBIString *		pServiceName,
		PBIInstance *	pRequestor,
		PBIInstance **	ppService ) = 0;
};

//-----------------------------------------------------------------------------
//                      PBIInstance
//-----------------------------------------------------------------------------

class PBIInstance : public PBIUnknown
{
  public:

    //  Get/Set properties, invoke methods by name.

    virtual PBWINAPI_(PBRESULT)    GetProperty(
        PBIString *     pPropertyName,
        PBIValue **     ppPropertyValue ) = 0;
    virtual PBWINAPI_(PBRESULT)    SetProperty(
        PBIString *     pPropertyName,
        PBIValue *      pPropertyValue ) = 0;

    virtual PBWINAPI_(PBRESULT)    PreDoMethod() = 0;
    virtual PBWINAPI_(PBRESULT)    DoMethod(
        PBIString *     pMethodName,
        PBIArgument **  ppArgs,
        PBINDEX         cArgCount,
        PBIValue **     ppResult,
        PBIException ** ppException,
        PBINDEX *       pBadParamIndex ) = 0;
    virtual PBWINAPI_(PBRESULT)    PostDoMethod() = 0;

    //  Get/Set properties, invoke methods by ID.

    virtual PBWINAPI_(PBRESULT)    GetPropertyByID(
        PBMEMBERID      idPropertyID,
        PBIValue **     pPropertyValue ) = 0;
    virtual PBWINAPI_(PBRESULT)    SetPropertyByID(
        PBMEMBERID      idPropertyID,
        PBIValue *      pPropertyValue ) = 0;
    virtual PBWINAPI_(PBRESULT)    DoMethodByID(
        PBMEMBERID      idMethodID,
        PBIArgument **  ppArgs,
        PBINDEX         cArgCount,
        PBIValue **     ppResult,
        PBIException ** ppException,
        PBINDEX *       pBadParamIndex ) = 0;


    //  Fetch the member ids for a list of names

    virtual PBWINAPI_(PBRESULT)    GetIDsForNames(
        PBIString **    pMemberNames,
        PBINDEX         iMemberNameCount,
        PBMEMBERID *    pMemberIDs ) = 0;

    //  Fetch the session and/or class id for this instance

    virtual PBWINAPI_(PBRESULT)    GetSession(
        PBISession **   ppSession ) = 0;
    virtual PBWINAPI_(PBRESULT)    GetClassID(
        PBObjectType *  pClassType ) = 0;

	virtual PBWINAPI_(PBRESULT)	GetContext( PBIContext ** ppContext ) = 0;
	virtual PBWINAPI_(PBRESULT)	Clone( PBIInstance ** ppInstance ) = 0;
};

extern "C"
{
	PBWINAPI_(PBRESULT) CreatePBIInstanceByName(
		PBIString *	pName,
		PBISession * pSession,
		PBIInstance ** ppInstance );

	PBWINAPI_(PBRESULT) CreatePBIInstanceByID(
		void *	obInst,
		PBISession * pSession,
		PBIInstance ** ppInstance );
};

//-----------------------------------------------------------------------------
//      		PBIArgument
//-----------------------------------------------------------------------------

class PBIArgument : public PBIUnknown
{
  public:

    virtual PBWINAPI_(PBRESULT)    GetValue( PBIValue ** ppValue ) = 0;
    virtual PBWINAPI_(PBRESULT)    SetValue( PBIValue * pValue ) = 0;
    virtual PBWINAPI_(PBRESULT)    GetHowPassed( PBArgCallConvention * pHowPassed ) = 0;

	virtual PBWINAPI_(PBRESULT)	GetSession( PBISession ** ppSession ) = 0;
	virtual PBWINAPI_(PBRESULT)	Clone( PBIArgument ** ppArgument ) = 0;
};

extern "C"
{
    PBWINAPI_(PBRESULT) CreatePBIArgument(
        PBIValue *      	pValue,
        PBArgCallConvention	eHowPassed,
        PBIArgument **  	ppArgument );
};


//-----------------------------------------------------------------------------
//      		PBIValue
//-----------------------------------------------------------------------------

class PBIValue : public PBIUnknown
{
  public:

    virtual PBWINAPI_(PBRESULT)    IsNullValued( PBBOOL * pBool ) = 0;
    virtual PBWINAPI_(PBRESULT)    MakeNullValued( PBBOOL bMakeNull ) = 0;

    virtual PBWINAPI_(PBRESULT)    GetValueType( PBValueType * pType ) = 0;

    virtual PBWINAPI_(PBRESULT)    GetValueAsChar( PBCHAR * pChar ) = 0;
    virtual PBWINAPI_(PBRESULT)    GetValueAsInt( PBINT * pInt ) = 0;
    virtual PBWINAPI_(PBRESULT)    GetValueAsUInt( PBUINT * pUInt ) = 0;
    virtual PBWINAPI_(PBRESULT)    GetValueAsShort( PBSHORT * pShort ) = 0;
    virtual PBWINAPI_(PBRESULT)    GetValueAsUShort( PBUSHORT * pUShort ) = 0;
    virtual PBWINAPI_(PBRESULT)    GetValueAsLong( PBLONG * pLong ) = 0;
    virtual PBWINAPI_(PBRESULT)    GetValueAsULong( PBULONG * pULong ) = 0;
    virtual PBWINAPI_(PBRESULT)    GetValueAsDecimal( PBIDecimal ** pDecimal ) = 0;
    virtual PBWINAPI_(PBRESULT)    GetValueAsFloat( PBFLOAT * pFloat ) = 0;
    virtual PBWINAPI_(PBRESULT)    GetValueAsDouble( PBDOUBLE * pDouble ) = 0;
    virtual PBWINAPI_(PBRESULT)    GetValueAsBoolean( PBBOOL * pBool ) = 0;
    virtual PBWINAPI_(PBRESULT)    GetValueAsDate( PBIDate ** pDate ) = 0;
    virtual PBWINAPI_(PBRESULT)    GetValueAsTime( PBITime ** pTime ) = 0;
    virtual PBWINAPI_(PBRESULT)    GetValueAsDateTime( PBIDateTime ** pDateTime ) = 0;
    virtual PBWINAPI_(PBRESULT)    GetValueAsString( PBIString ** pString ) = 0;
    virtual PBWINAPI_(PBRESULT)    GetValueAsBlob( PBIBlob ** pBlob ) = 0;
    virtual PBWINAPI_(PBRESULT)    GetValueAsInstance( PBIInstance ** pInstance ) = 0;
    virtual PBWINAPI_(PBRESULT)    GetValueAsArray( PBIArray **  pArray ) = 0;

    virtual PBWINAPI_(PBRESULT)    SetValueFromChar( PBCHAR cValue ) = 0;
    virtual PBWINAPI_(PBRESULT)    SetValueFromInt( PBINT iValue ) = 0;
    virtual PBWINAPI_(PBRESULT)    SetValueFromUInt( PBUINT uiValue ) = 0;
    virtual PBWINAPI_(PBRESULT)    SetValueFromShort( PBSHORT iValue ) = 0;
    virtual PBWINAPI_(PBRESULT)    SetValueFromUShort( PBUSHORT uiValue ) = 0;
    virtual PBWINAPI_(PBRESULT)    SetValueFromLong( PBLONG lValue ) = 0;
    virtual PBWINAPI_(PBRESULT)    SetValueFromULong( PBULONG ulValue ) = 0;
    virtual PBWINAPI_(PBRESULT)    SetValueFromDecimal( PBIDecimal * pDecimal ) = 0;
    virtual PBWINAPI_(PBRESULT)    SetValueFromFloat( PBFLOAT fValue ) = 0;
    virtual PBWINAPI_(PBRESULT)    SetValueFromDouble( PBDOUBLE dValue ) = 0;
    virtual PBWINAPI_(PBRESULT)    SetValueFromBoolean( PBBOOL bValue ) = 0;
    virtual PBWINAPI_(PBRESULT)    SetValueFromDate( PBIDate * pDate ) = 0;
    virtual PBWINAPI_(PBRESULT)    SetValueFromTime( PBITime * pTime ) = 0;
    virtual PBWINAPI_(PBRESULT)    SetValueFromDateTime( PBIDateTime * pDateTime ) = 0;
    virtual PBWINAPI_(PBRESULT)    SetValueFromString( PBIString * pString ) = 0;
    virtual PBWINAPI_(PBRESULT)    SetValueFromBlob( PBIBlob * pBlob ) = 0;
    virtual PBWINAPI_(PBRESULT)    SetValueFromInstance( PBIInstance * pInstance ) = 0;
    virtual PBWINAPI_(PBRESULT)    SetValueFromArray( PBIArray * pArray ) = 0;

	virtual PBWINAPI_(PBRESULT)	SetValueFromValue( PBIValue * pValue ) = 0;

	virtual PBWINAPI_(PBRESULT)	GetSession( PBISession ** ppSession ) = 0;

	virtual PBWINAPI_(PBRESULT)	Clone( PBIValue ** ppValue ) = 0;
};

extern "C"
{
PBWINAPI_(PBRESULT) CreatePBIValue(
	PBValueType 	enmValueType,
	PBISession * 	pSession,
	PBIValue ** 	ppValue );
};


//-----------------------------------------------------------------------------
//                      PBIArray
//-----------------------------------------------------------------------------

class PBIArray : public PBIUnknown
{
  public:

    virtual PBWINAPI_(PBRESULT)    GetValueAt(
        PBLONG *    pSubs,
        PBINDEX     cDimension,
        PBIValue ** ppValue ) = 0;
    virtual PBWINAPI_(PBRESULT)    SetValueAt(
        PBLONG *    pSubs,
        PBINDEX     cDimension,
        PBIValue *  pValue ) = 0;

    virtual PBWINAPI_(PBRESULT)    GetDimensions( PBINDEX * pDimensions ) = 0;
    virtual PBWINAPI_(PBRESULT)    GetBounds( PBIArrayBoundsList ** ppArrayBounds ) = 0;

    virtual PBWINAPI_(PBRESULT)    GetSession( PBISession ** ppSession ) = 0;
	virtual PBWINAPI_(PBRESULT)	Clone( PBIArray ** ppArray ) = 0;
};

extern "C"    PBWINAPI_(PBRESULT) CreatePBIArray(
    PBIArrayBoundsList *	pBoundsList,
	PBValueType				eValueType,
    PBISession *        	pSession,
    PBIArray **         	ppArray );

extern "C"	PBWINAPI_(PBRESULT) CreatePBIArrayOfObject(
    PBIArrayBoundsList *	pBoundsList,
	PBIString *				pObjectName,
	PBISession *			pSession,
	PBIArray **				ppArray );

extern "C"    PBWINAPI_(PBRESULT) CreatePBIUnboundedArray(
    PBIArrayBoundsList *	pBoundsList,
	PBValueType				eValueType,
    PBISession *        	pSession,
    PBIArray **         	ppArray );

extern "C"	PBWINAPI_(PBRESULT) CreatePBIUnboundedArrayOfObject(
    PBIArrayBoundsList *	pBoundsList,
	PBIString *				pObjectName,
	PBISession *			pSession,
	PBIArray **				ppArray );

//-----------------------------------------------------------------------------

class PBIArrayBounds	:	public PBIUnknown
{
  public:

	virtual PBWINAPI_(PBRESULT)	GetLowerBound( PBLONG * pLower ) = 0;
	virtual PBWINAPI_(PBRESULT)	SetLowerBound( PBLONG lLower ) = 0;

	virtual PBWINAPI_(PBRESULT)	GetUpperBound( PBLONG * pUpper ) = 0;
	virtual PBWINAPI_(PBRESULT)	SetUpperBound( PBLONG lUpper ) = 0;
};


class PBIArrayBoundsList     :       public PBIUnknown
{
  public:

        virtual PBWINAPI_(PBRESULT)        Add( PBIArrayBounds * ) = 0;
        virtual PBWINAPI_(PBRESULT)        Remove( PBIArrayBounds * ) = 0;

        virtual PBWINAPI_(PBRESULT)        GetCount( PBINDEX * pCount ) = 0;

        virtual PBWINAPI_(PBRESULT)        GetFirst( PBIArrayBounds ** pFirst ) = 0;
        virtual PBWINAPI_(PBRESULT)        GetNext( PBIArrayBounds ** pNext ) = 0;

        virtual PBWINAPI_(PBRESULT)        GetLast( PBIArrayBounds ** pLast ) = 0;
        virtual PBWINAPI_(PBRESULT)        GetPrevious( PBIArrayBounds ** pPrevious ) = 0;
};

extern "C"
{
	PBWINAPI_(PBRESULT) CreatePBIArrayBounds(
		PBLONG  lLower,
		PBLONG  lUpper,
		PBISession * pSession,
		PBIArrayBounds ** ppBounds );

	PBWINAPI_(PBRESULT) CreatePBIArrayBoundsList(
		PBIArrayBoundsList ** ppArrayBoundsList );
};


//-----------------------------------------------------------------------------
//      IException
//-----------------------------------------------------------------------------

class PBIException : public PBIUnknown
{
  public:

    virtual PBWINAPI_(PBRESULT)    GetDescription( PBIString ** ppString ) = 0;
    virtual PBWINAPI_(PBRESULT)    SetDescription( PBIString * pString ) = 0;

	virtual PBWINAPI_(PBRESULT)	Clone( PBIException ** ppException ) = 0;
};

extern "C"
{
    PBWINAPI_(PBRESULT) CreatePBIException(
		PBIString *	pDescription,
		PBIException ** ppException );
};


#endif  //  PBRUNIFX_H
