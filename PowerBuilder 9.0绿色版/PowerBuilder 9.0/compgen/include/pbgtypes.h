//----------------------------------------------------------------------------
//      pbgtypes.h
//      Basic function and type definitions.
//      "Customer" header for PowerBuilder generators.
//      wrlane  3/10/97
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
//      Basic function prototypes
//
//      This duplicates the PBWINAPI declarations found in "ospascal.h".
//----------------------------------------------------------------------------

#ifndef PBGTYPES_H
#define PBGTYPES_H

#include <stddef.h>
#include <limits.h>

#ifndef FAR
#ifdef  WIN32
#define FAR     
#else
#define FAR     _far
#endif
#endif

#ifndef NEAR
#ifdef WIN32
#define NEAR
#else
#define NEAR    _near
#endif
#endif

#ifndef PASCAL
#ifdef WIN32
#ifdef PBOS_UNIX
#define PASCAL
#else   //  PBOS_UNIX
#define PASCAL          __stdcall
#endif  //  PBOS_UNIX
#else   //      WIN32
#define PASCAL          _pascal
#endif  //  WIN32
#endif  //  defined PASCAL

#ifndef WINAPI
#ifdef  PBOS_NT
#define WINAPI          __stdcall
#else   //      PBOS_NT
#define WINAPI          FAR PASCAL
#endif  //  PBOS_NT
#endif  //  WINAPI
 
#ifndef PBWINAPI
#ifdef  PBOS_MAC
#ifdef  WIN32
#define PBWINAPI(r, n)  r (n)
#else   //      WIN32
#define PBWINAPI(r, n)  PASCAL r (n)
#endif  //  WIN32
#elif   defined(PBOS_OS2)
#define PBWINAPI(r, n)  FAR PASCAL __loadds r n
#elif   defined(__WATCOMC__) && defined(__cplusplus) && (__WATCOMC__ == 1050)
#define PBWINAPI(r, n)  __declspec(dllexport) r ( WINAPI n )
#else   //      PBOS_MAC, PBOS_OS2, WATCOM etc.
#define PBWINAPI(r, n)  r WINAPI n
#endif  //  PBOS_MAC
#endif  //  PBWINAPI

#ifndef PBWINAPI_
#ifdef  PBOS_MAC
#ifdef  WIN32
#define PBWINAPI_(r)    r
#else
#define PBWINAPI_(r)    PASCAL r
#endif  //  WIN32
#elif   defined(PBOS_OS2)
#define PBWINAPI_(r)    FAR PASCAL __loadds r
#elif   defined(__WATCOMC__) && defined(__cpluspllus) && (__WATCOMC__ == 1050)
#define PBWINAPI_(r)    __declspec(dllexport) r WINAPI
#else
#define PBWINAPI_(r)    r WINAPI
#endif  //  PBOS_MAC
#endif  //  PBWINAPI_

//----------------------------------------------------------------------------
//      Unicode string handling
//----------------------------------------------------------------------------

#ifndef PBTEXT
#ifdef RC_INVOKED
#define PBTEXT(quote)           quote
#elif defined WIN32
#ifdef UNICODE
#define PBTEXT(quote)           L##quote
#else
#define PBTEXT(quote)           quote
#endif  //  UNICODE
#else
#define PBTEXT(quote)           quote
#endif  //  RC_INVOKED
#endif  //  PBTEXT




//----------------------------------------------------------------------------
//      Basic data types
//----------------------------------------------------------------------------

#ifdef UNICODE
typedef wchar_t                 PBCHAR;
#else
typedef char                    PBCHAR;
#endif
 
#ifndef PBVOID
#define PBVOID                  void
#endif
#ifndef PBBYTE
#define PBBYTE                  unsigned char 
#endif
#ifndef PBINT
#define PBINT                   int
#endif
#ifndef PBUINT                  
#define PBUINT                  unsigned int
#endif
#ifndef PBSHORT                 
#define PBSHORT                 short
#endif
#ifndef PBUSHORT                
#define PBUSHORT                unsigned short
#endif
#ifndef PBLONG                  
#define PBLONG                  long
#endif
#ifndef PBULONG                 
#define PBULONG                 unsigned long
#endif
#ifndef PBWORD                  
#define PBWORD                  unsigned short
#endif
#ifndef PBDWORD                 
#define PBDWORD                 unsigned long
#endif
#ifndef PBFLOAT                 
#define PBFLOAT                 float
#endif
#ifndef PBDOUBLE                
#define PBDOUBLE                double
#endif
#ifndef PBPVOID                 
#define PBPVOID                 void FAR *
#endif

#ifndef PBBYTE_NULL
#define PBBYTE_NULL                             UCHAR_MAX
#endif
#ifndef PBCHAR_NULL
#define PBCHAR_NULL                             CHAR_MAX
#endif
#ifndef PBINT_NULL
#define PBINT_NULL                              INT_MAX
#endif
#ifndef PBUINT_NULL                             
#define PBUINT_NULL                             UINT_MAX
#endif
#ifndef PBSHORT_NULL
#define PBSHORT_NULL                    SHRT_MAX
#endif
#ifndef PBUSHORT_NULL           
#define PBUSHORT_NULL                   USHRT_MAX
#endif
#ifndef PBLONG_NULL
#define PBLONG_NULL                             LONG_MAX
#endif
#ifndef PBULONG_NULL
#define PBULONG_NULL                    ULONG_MAX
#endif
#ifndef PBFLOAT_NULL
#define PBFLOAT_NULL                    (PBFLOAT)1E+37
#endif
#ifndef PBDOUBLE_NULL
#define PBDOUBLE_NULL                   (PBDOUBLE)1E+37
#endif
 
//----------------------------------------------------------------------------
//      Simple PB types
//----------------------------------------------------------------------------

#ifndef PBINDEX
#define PBINDEX                 PBLONG
#endif
#ifndef PBMEMBERID
#define PBMEMBERID              PBLONG
#endif
#ifndef PBBOOL
#define PBBOOL                  PBINT
#endif
#ifndef PBPOINTER
#define PBPOINTER               PBPVOID
#endif 
#ifndef PBOBJECTID
#define PBOBJECTID              PBPVOID
#endif

#ifndef PBHANDLE
#ifdef  STRICT
#ifdef  WIN32
#define PBHANDLE                PBPVOID 
#else   //  WIN32
#define PBHANDLE                const void NEAR *
#endif  //  WIN32
#else   //  STRICT
#ifdef  WIN32
#define PBHANDLE                PBPVOID
#else   //  WIN32
#define PBHANDLE                PBUINT
#endif  //  WIN32
#endif  //  STRICT
#endif  //  PBHANDLE


#ifndef PBTRUE
#define PBTRUE                  1
#endif
#ifndef PBFALSE
#define PBFALSE                 0
#endif
 

//----------------------------------------------------------------------------
//      Odds and ends for compliance with Windows, OLE, etc.
//----------------------------------------------------------------------------

#ifndef NOERROR
#define NOERROR         0
#endif
#ifndef S_OK
#define S_OK            0
#endif
#ifndef E_NOINTERFACE
#define E_NOINTERFACE   0x80004002L
#endif

//----------------------------------------------------------------------------
//      PB enumerated types
//----------------------------------------------------------------------------

enum PBLibraryType
{
    PBLibraryTypeMachineCode,
    PBLibraryTypePCode,
    PBLibraryTypeCount
};

enum PBObjectType
{
    PBObjectTypeNVO,
	PBObjectTypeCustomVisual,
    PBObjectTypeWindow,
	PBObjectTypeApplication,
	PBObjectTypeCount
};

enum PBGeneratorStatus
{
    PBGeneratorStatusIdle,
    PBGeneratorStatusBusy,
    PBGeneratorStatusCount
};

enum PBValueType
{
    PBValueTypeNull,
	PBValueTypeAny,
    PBValueTypePointer,
    PBValueTypeChar,
    PBValueTypeInt,
    PBValueTypeUInt,
	PBValueTypeShort,
	PBValueTypeUShort,
    PBValueTypeLong,
    PBValueTypeULong,
    PBValueTypeDecimal,
    PBValueTypeFloat,
    PBValueTypeDouble,
    PBValueTypeBoolean,
    PBValueTypeDate,
    PBValueTypeTime,
    PBValueTypeDateTime,
    PBValueTypeString,
    PBValueTypeBlob,
    PBValueTypeInstance,
    PBValueTypeArray,
    PBValueTypeUserDefined,
    PBValueTypeCount
};

enum PBVariableKind 
{
    PBVariableKindGlobal,
    PBVariableKindShared,
    PBVariableKindInstance,
    PBVariableKindArgument,
    PBVariableKindLocal
};

enum PBVariableAccess 
{
    PBVariableAccessPrivate,
    PBVariableAccessPublic,
    PBVariablerAccessProtected,
    PBVariableAccessSystem
};

enum PBArgCallConvention 
{
    PBArgCallConventionByReference,
    PBArgCallConventionByValue,
    PBArgCallConventionReadOnly,
    PBArgCallConventionVariableList
};

enum PBVariableCardinalityType 
{
    PBVariableCardinalityTypeScalarType,
    PBVariableCardinalityTypeUnboundedArray,
    PBVariableCardinalityTypeBoundedArray
};

enum PBScriptKind 
{
    PBScriptKindEvent,
    PBScriptKindFunction
};

enum PBTypeCategory 
{
    PBTypeCategorySimpleType,
    PBTypeCategoryEnumeratedType,
    PBTypeCategoryClassOrStructureType
};

enum PBSessionSecurityMode
{
	PBSessionSecurityModeNoDBModify = 0,
	PBSessionSecurityModeNoDBStoredProc,
	PBSessionSecurityModeNoDB,
	PBSessionSecurityModeNoConnectOtherPB,
	PBSessionSecurityModeNoConnectNonsecurePB,
	PBSessionSecurityModeNoOLE,
	PBSessionSecurityModeNoPrint,
	PBSessionSecurityModeCount
};

//----------------------------------------------------------------------------
//      structures 
//----------------------------------------------------------------------------

//  Bitmap

typedef struct
{
    PBHANDLE    hIcon;
} PBBITMAP;


//  Interface ID (e.g., UUID or GUID)
 
typedef struct
{
    PBULONG             ulData1;
    PBUSHORT            usData2;
    PBUSHORT            usData3;
    PBBYTE              ucData4[8];
}   PBID;

typedef PBID            PBIID;        
typedef PBID            PBCLSID;
typedef PBID            PBMETAID;

#ifdef __cplusplus
typedef PBID &          PBIDREF;
#else
typedef PBID *          PBIDREF;
#endif
typedef PBIDREF         PBIIDREF;
typedef PBIDREF         PBCLSIDREF;
typedef PBIDREF         PBMETAIDREF;


#endif  //  PBGTYPES_H
