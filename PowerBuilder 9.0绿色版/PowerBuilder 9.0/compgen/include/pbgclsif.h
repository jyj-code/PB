/* *********************************************************************** */
/*                                                                         */
/*             COPYRIGHT POWERSOFT CORPORATION 1996                        */
/*                                                                         */
/*        POWERSOFT CORPORATION ("POWERSOFT") CLAIMS COPYRIGHT IN THIS     */
/*   PROGRAM AND DOCUMENTATION AS AN UNPUBLISHED WORK, VERSIONS OF         */
/*   WHICH WERE FIRST LICENSED ON THE DATE INDICATED IN THE FOREGOING      */
/*   NOTICE.   CLAIM OF COPYRIGHT DOES NOT IMPLY WAIVER OF POWERSOFT'S     */
/*   OTHER RIGHTS.                                                         */
/*                                                                         */
/* ----------------------------------------------------------------------- */
/*                                                                         */
/*   Filename  : pbgclsif.h                                                */
/*                                                                         */
/*   Author    : David Sotkowitz                                           */
/*                                                                         */
/*   Purpose   : Class Information routines.                               */
/*                                                                         */
/* *********************************************************************** */

#ifndef PBGCLSIF_H
#define PBGCLSIF_H

#ifndef PBGTYPES_H
#include "pbgtypes.h"
#endif
#ifndef PBGTYPIF_H
#include "pbgtypif.h"
#endif
#ifndef PBGRUNIF_H
#include "pbgrunif.h"
#endif

extern "C"
{
extern PBIID PBIClassDef_IID;
extern PBIID PBIClassDefList_IID;
extern PBIID PBIEnumerationDef_IID;
extern PBIID PBISimpleTypeDef_IID;
extern PBIID PBIVariableDef_IID;
extern PBIID PBIVariableDefList_IID;
extern PBIID PBIScriptDef_IID;
extern PBIID PBIScriptDefList_IID;
extern PBIID PBITypeDef_IID;
extern PBIID PBIVariableCardinalityDef_IID;
extern PBIID PBIEnumerationItemDef_IID;
};

//      Skip over these C++ definitions if we are compiling C code.

#ifdef __cplusplus         

class PBIScriptDef;
class PBIScriptDefList;
typedef PBIScriptDef FAR * PPBIScriptDef;
typedef PPBIScriptDef FAR * PPPBIScriptDef;
class PBIVariableDef;
class PBIVariableDefList;
typedef PBIVariableDef FAR * PPBIVariableDef;
typedef PPBIVariableDef FAR * PPPBIVariableDef;
class PBIClassDef;
class PBIClassDefList;
typedef PBIClassDef FAR * PPBIClassDef;
typedef PPBIClassDef FAR * PPPBIClassDef;
class PBITypeDef;
typedef PBITypeDef FAR * PPBITypeDef;
typedef PPBITypeDef FAR * PPPBITypeDef;
class PBISimpleTypeDef;
typedef PBISimpleTypeDef FAR * PPBISimpleTypeDef;
typedef PPBISimpleTypeDef FAR * PPPBISimpleTypeDef;
class PBIEnumerationDef;
typedef PBIEnumerationDef FAR * PPBIEnumerationDef;
typedef PPBIEnumerationDef FAR * PPPBIEnumerationDef;
class PBIVariableCardinalityDef;
typedef PBIVariableCardinalityDef FAR * PPBIVariableCardinalityDef;
class PBArgDef;
typedef PBArgDef FAR * PPBArgDef;
typedef PPBArgDef FAR * PPPBArgDef;
class PBIEnumerationItemDef;
typedef PBIEnumerationItemDef FAR * PPBIEnumerationItemDef;
typedef PPBIEnumerationItemDef FAR * PPPBIEnumerationItemDef;

//***************************************************************************
//
//    Name:             Class PBITypeDef
//
//    Synopsis: C++ PBITypeDef which is associated with a Powerscript 
//                              TypeDefinition
//
//    Notes:    
//
//***************************************************************************

class PBITypeDef : public PBIUnknown
{
  public: 

	//
	// Public advertised External Interface which matches the PB MetaClass API
	//
	virtual PBRESULT	GetName(PBIString ** ppName) = 0;
	virtual PBRESULT	GetLibraryName(PBIString ** ppName) = 0;
	virtual PBRESULT	GetDataTypeOf(PBIString ** ppType) = 0;
    virtual PBRESULT	GetCategory (PBTypeCategory * pCategory) = 0;
    virtual PBRESULT	GetIsVariableLength(PBBOOL * pIsVariableLength) = 0;
	virtual PBRESULT	GetIsSystemType(PBBOOL * pIsSystemType) = 0;
	virtual PBRESULT	GetIsVisualType(PBBOOL * pIsVisual ) = 0;
	virtual PBRESULT	GetIsStructure(PBBOOL * pIsStructure) = 0;
};

class PBISimpleTypeDef : public PBITypeDef 
{ 
};

class PBIEnumerationDef  : public PBITypeDef
{
  public: 
 
    virtual PBRESULT    GetEnumerationValue(PBLONG nIndex, PBLONG * pValue) = 0;
    virtual PBRESULT    GetEnumerationName(PBLONG nIndex, PBIString ** ppName) = 0;
    virtual PBRESULT    GetNumEnumerations(PBINDEX * pNumEnumerations) = 0;
};

//***************************************************************************
//
//    Name:             Class PBIClassDef
//
//    Synopsis: C++ PBIClassDef which is associated with a Powerscript ClassDef
//
//    Notes:
//
//***************************************************************************

class PBIClassDef : public PBITypeDef
{
public: 
	//
	// Public advertised External Interface which matches the PB MetaClass API
	//
	
	virtual PBRESULT        GetAncestorClass(PBIClassDef ** ppAncestor) = 0;
	virtual PBRESULT    GetParentClass(PBIClassDef ** ppParent) = 0;
	virtual PBRESULT    GetIsAutoinstantiate(PBBOOL * pIsAutoInstantiate) = 0;
 
	virtual PBRESULT    GetNestedClass(PBLONG nIndex, PBIClassDef ** ppNested) = 0;
	virtual PBRESULT        GetNestedClassList(PBIClassDefList ** ppNestedList ) = 0;	

	virtual PBRESULT        GetVariable(PBLONG nIndex, PBIVariableDef ** ppVariable) = 0;
	virtual PBRESULT        GetVariableList(PBIVariableDefList ** ppVariableList) = 0;

	virtual PBRESULT        GetScript(PBLONG nIndex, PBIScriptDef ** pScript) = 0;
	virtual PBRESULT        GetScriptList (PBIScriptDefList ** ppScriptList) = 0;
 
	virtual PBRESULT        FindMatchingFunction (
		PBIString *     pname, 
		PBIString **    ppArgs, 
		PBULONG         cArgCount, 
		PBIScriptDef **  ppScriptDef) = 0;
	virtual PBRESULT   GetBinaryHexAscii (PBIString ** ppString) = 0;

	//      Note, we really don't call UpperBound on the arrays, 
	//      use these to find out sizes
 
	virtual PBRESULT        GetNumNestedClasses(PBINDEX * pNumClasses) = 0;
	virtual PBRESULT        GetNumVariables(PBINDEX * pNumVariables) = 0;
	virtual PBRESULT        GetNumScripts(PBINDEX * pNumScripts) = 0;
 
	// PropertyList Accessors
 
	virtual PBRESULT        GetPropertyName (PBLONG n, PBIString ** ppName) = 0;
	virtual PBRESULT        GetPropertyValue(PBLONG n, PBIString ** ppValue) = 0;
	virtual PBRESULT        FindPropertyValue(PBLONG * pN, PBIString * pName, PBIString ** ppValue) = 0;
	virtual PBRESULT        GetNumProperties(PBINDEX * pNumProperties) = 0;
};

extern "C"
{
PBWINAPI(PBRESULT, CreatePBITypeDef)(
	PBIString *             pName,
	PBIString *             pLibraryList,
	PBITypeDef **           ppTypeDef);

PBWINAPI(PBRESULT, CreatePBIClassDef)(
	PBIString *             pName,
	PBIString *             pLibraryList,
	PBIClassDef **          ppClassDef );

PBWINAPI(PBRESULT, CreatePBIScriptDef)(
	PBIString *             pName,
	PBIString *             pLibraryList,
	PBIScriptDef **         ppScriptDef);
};

//***************************************************************************
//	Name:		Class PBIClassDefList
//	Synopsis:	List of PBIClassDefs
//	Notes:
//***************************************************************************

class PBIClassDefList	:	public PBIUnknown
{
  public:

    virtual PBRESULT    Add( PBIClassDef * ) = 0;
    virtual PBRESULT    Remove( PBIClassDef * ) = 0;

    virtual PBRESULT    GetCount( PBINDEX * pCount ) = 0;

    virtual PBRESULT    GetFirst( PBIClassDef ** pFirst ) = 0;
    virtual PBRESULT    GetNext( PBIClassDef ** pNext ) = 0;

    virtual PBRESULT    GetLast( PBIClassDef ** pLast ) = 0;
    virtual PBRESULT    GetPrevious( PBIClassDef ** pPrevious ) = 0;
};

extern "C"
{
	PBWINAPI_(PBRESULT) CreatePBIClassDefList( 
		PBIClassDefList ** ppClassDefList );
};

//***************************************************************************
//
//    Name:             Class PBIVariableDef
//
//    Synopsis: Class associated with a Powerscript VariableDef
//
//    Notes:    
//
//***************************************************************************

class PBIVariableDef : public PBIUnknown
{
  public:

	//
	// Public advertised External Interface which matches the PB MetaClass API
	//

	virtual PBRESULT        GetName(PBIString ** ppName)  = 0;
	virtual PBRESULT        GetTypeInfo(PBITypeDef ** ppTypeInfo) = 0;
    virtual PBRESULT    GetCardinality(PBIVariableCardinalityDef ** ppCardinality) = 0;
	virtual PBRESULT        GetInitialValue (PBIValue ** ppValue) = 0;
	virtual PBRESULT        GetOverridesAncestorValue (PBBOOL * pOverrides ) = 0;
	virtual PBRESULT        GetReadAccess(PBVariableAccess * pReadAccess)   = 0;
	virtual PBRESULT        GetWriteAccess(PBVariableAccess * pWriteAccess)  = 0;
	virtual PBRESULT        GetIsConstant(PBBOOL * pIsConstant ) = 0;
	virtual PBRESULT        GetArgumentKind(PBLONG * pKind) = 0;
	virtual PBRESULT        GetCardinality(PBVariableCardinalityType * pType) = 0;
	virtual PBRESULT        GetKind(PBVariableKind * pKind) = 0;
	virtual PBRESULT        GetIsLocallyDefined(PBBOOL * pLocal) = 0;
	virtual PBRESULT        GetIsUserDefined(PBBOOL * pIsUserDefined ) = 0;
 
	// The functions for upperbounds
 
	virtual PBRESULT        GetNumArrayBounds(PBINDEX * pNumBounds) = 0;
	virtual PBRESULT        GetBoundAt(PBLONG dim, PBLONG bounds[2])  = 0;
 
	// PropertyList Accessors
 
	virtual PBRESULT        GetPropertyName (PBLONG n, PBIString ** ppName) = 0;
	virtual PBRESULT        GetPropertyValue(PBLONG n, PBIString ** ppValue) = 0;
	virtual PBRESULT        FindPropertyValue(PBLONG * pN, PBIString * pName, PBIString ** ppValue) = 0;
	virtual PBRESULT        GetNumProperties(PBINDEX * pProperties) = 0;
};


//***************************************************************************
//	Name:			PBIVariableDefList
//	Synopsis:		List of PBIVariableDefs
//	Notes:
//***************************************************************************

class PBIVariableDefList :   public PBIUnknown
{
  public:

    virtual PBRESULT    Add( PBIVariableDef * ) = 0;
    virtual PBRESULT    Remove( PBIVariableDef * ) = 0;

    virtual PBRESULT    GetCount( PBINDEX * pCount ) = 0;

    virtual PBRESULT    GetFirst( PBIVariableDef ** pFirst ) = 0;
    virtual PBRESULT    GetNext( PBIVariableDef ** pNext ) = 0;

    virtual PBRESULT    GetLast( PBIVariableDef ** pLast ) = 0;
    virtual PBRESULT    GetPrevious( PBIVariableDef ** pPrevious ) = 0;
};

extern "C"
{
	PBWINAPI_(PBRESULT)	CreatePBIVariableDefList(
		PBIVariableDefList ** ppVariableDefList );
};

//***************************************************************************
//
//    Name:             Class PBIScriptDef
//
//    Synopsis: C++ PBIScriptDef which is associated with a Powerscript ScriptDef
//
//    Notes:    
//
//***************************************************************************

class PBIScriptDef : public PBIUnknown
{
  public:
 
	//
	// Public advertised External Interface which matches the PB MetaClass API
	//

	virtual PBRESULT    GetName(PBIString ** ppName) = 0;
	virtual PBRESULT    GetSignature(PBIString ** ppSignature) = 0;
	virtual PBRESULT    GetKind(PBScriptKind * pKind) = 0;
	virtual PBRESULT    GetReturnType(PBITypeDef ** pType) = 0;
	virtual PBRESULT    GetCardinality (PBIVariableCardinalityDef ** ppCardinality) = 0;
	virtual PBRESULT    GetVtableId (PBUSHORT * pID) = 0;
	virtual PBRESULT    GetSource(PBIString ** ppSource) = 0;
	virtual PBRESULT    GetIsScripted(PBBOOL * pIsScripted) = 0;
	virtual PBRESULT    GetIsLocallyDefined(PBBOOL * pIsLocal) = 0;
	virtual PBRESULT    GetIsLocallyScripted(PBBOOL * pIsScripted) = 0;

	virtual PBRESULT    GetExternalUserFunction(PBIString ** ppName) = 0;
	virtual PBRESULT    GetSystemFunction(PBIString ** ppName) = 0;
	virtual PBRESULT    GetAliasName(PBIString ** ppName) = 0;
	virtual PBRESULT    GetEventIdName(PBIString ** ppName) = 0;
	virtual PBRESULT    GetEventId(PBLONG * pID) = 0;
	virtual PBRESULT    GetIsRPCFunction(PBBOOL * pIsRPC) = 0;
	virtual PBRESULT    GetIsExternalEvent(PBBOOL * pIsExternal) = 0;
	virtual PBRESULT    GetNumArgs(PBINDEX * pNumArgs) = 0;
	virtual PBRESULT    GetArg(PBLONG nIndex, PBIVariableDef ** pArg) = 0;
	virtual PBRESULT    GetArgList(PBIVariableDefList ** ppArgList) = 0;
	virtual PBRESULT    GetNumLocals(PBINDEX * pNumLocals) = 0;
	virtual PBRESULT    GetLocal(PBLONG nIndex, PBIVariableDef ** ppLocal) = 0;
	virtual PBRESULT    GetLocalList(PBIVariableDefList ** ppLocalList) = 0;
	virtual PBRESULT        GetAccess(PBVariableAccess * pAccess) = 0;
 
	// PropertyList Accessors
 
	virtual PBRESULT    GetPropertyName (PBLONG n, PBIString ** ppName) = 0;
	virtual PBRESULT    GetPropertyValue(PBLONG n, PBIString ** ppValue) = 0;
	virtual PBRESULT        FindPropertyValue(PBLONG * pN, PBIString * pName, PBIString ** ppValue) = 0;
	virtual PBRESULT    GetNumProperties(PBINDEX * pNumProperties) = 0;

	// Throws Accessors
	
	virtual PBRESULT    GetThrowsType(PBLONG n, PBITypeDef ** ppType) = 0;
	virtual PBRESULT    GetNumThrows(PBINDEX * pNumThrows) = 0;
};


//***************************************************************************
//	Name:			PBIScriptDefList
//	Synopsis:		List of PBIScriptDefs
//	Notes:
//***************************************************************************

class PBIScriptDefList :   public PBIUnknown
{
  public:

    virtual PBRESULT    Add( PBIScriptDef * ) = 0;
    virtual PBRESULT    Remove( PBIScriptDef * ) = 0;

    virtual PBRESULT    GetCount( PBINDEX * pCount ) = 0;

    virtual PBRESULT    GetFirst( PBIScriptDef ** pFirst ) = 0;
    virtual PBRESULT    GetNext( PBIScriptDef ** pNext ) = 0;

    virtual PBRESULT    GetLast( PBIScriptDef ** pLast ) = 0;
    virtual PBRESULT    GetPrevious( PBIScriptDef ** pPrevious ) = 0;
};


extern "C"
{
	PBWINAPI_(PBRESULT) CreatePBIScriptDefList(
		PBIScriptDefList ** ppScriptDefList );
};


//***************************************************************************
//
//    Name:             Class  PBIVariableCardinalityDef
//
//    Synopsis: C++ PBIVariableCardinalityDef which is associated with a Powerscript 
//                              VariableCardinalityDef
//
//    Notes:    
//
//***************************************************************************

class PBIVariableCardinalityDef : public PBIUnknown
{
  public: 
 
    virtual PBRESULT    GetCardinality(PBVariableCardinalityType * pType) = 0; 

    // ArrayBounds member functions
    // Returns lower bound for nth dimension of an array.
 
    virtual PBRESULT    GetLowerbound(PBLONG n, PBLONG * pLower) = 0;
 
    // Returns upper bound for nth dimension of an array.
 
    virtual PBRESULT    GetUpperbound(PBLONG n, PBLONG * pUpper) = 0;
 
    // Returns the number of dimensions for an array
 
    virtual PBRESULT    GetNumArrayDimensions(PBINDEX * pNumDimensions) = 0;
 
};

//***************************************************************************
//
//    Name:             Class  PBIEnumerationItemDef
//
//    Synopsis:                 C++ PBIEnumerationItemDef which is associated 
//                                              with a Powerscript PBIEnumerationItemDef
//
//    Notes:    
//
//***************************************************************************

class PBIEnumerationItemDef : public PBIUnknown
{
  public:
	virtual PBRESULT    GetName (PBIString ** ppName) = 0;
	virtual PBRESULT    GetValue(PBLONG * pValue)  = 0;
};

#endif  //      __cplusplus
#endif  //      PBGCLSIF_H
