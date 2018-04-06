//              Copyright Sybase, Inc. 1996
//
//      Sybase, Inc. ("Sybase") claims copyright in this
//      program and documentation as an unpublished work, versions of
//      which were first licensed on the date indicated in the foregoing
//      notice.  Claim of copyright does not imply waiver of Sybase's
//      other rights.
//-----------------------------------------------------------------------------
//      pbgtypif.h
//	PB Generator interface-based basic type declarations.
//	wrlane 6/13/97
//-----------------------------------------------------------------------------

#ifndef PBGTYPIF_H
#define PBGTYPIF_H

#ifndef PBGIUNIF_H
#include "pbgiunif.h"
#endif

 
extern "C"
{
extern PBIID PBIString_IID;
extern PBIID PBIStringList_IID;
extern PBIID PBIDateTime_IID;
extern PBIID PBIDate_IID;
extern PBIID PBITime_IID;
extern PBIID PBIDecimal_IID;
extern PBIID PBIBlob_IID;

extern PBIID PBIStringToBlob_IID;
extern PBIID PBIDateTimeToBlob_IID;
extern PBIID PBIDateToBlob_IID;
extern PBIID PBITimeToBlob_IID;
extern PBIID PBIDecimalToBlob_IID;

extern PBIID PBIDateTimeToString_IID;
extern PBIID PBIDateToString_IID;
extern PBIID PBITimeToString_IID;
extern PBIID PBIDecimalToString_IID;
};

//	Forward declarations for convenience.

class PBIString;
class PBIStringList;
class PBIDateTime;
class PBIDate;
class PBITime;
class PBIDecimal;
class PBIBlob;

class PBIStringToBlob;
class PBIDateTimeToBlob;
class PBIDateToBlob;
class PBITimeToBlob;
class PBIDecimalToBlob;

class PBIDateTimeToString;
class PBIDateToString;
class PBITimeToString;
class PBIDecimalToString;


//-----------------------------------------------------------------------------
//      String
//-----------------------------------------------------------------------------

class PBIString : public PBIUnknown
{
  public:

    virtual PBWINAPI_(PBRESULT)    GetValue( PBCHAR ** pValue ) = 0;
    virtual PBWINAPI_(PBRESULT)    GetLength( PBULONG * pcLength ) = 0;
    virtual PBWINAPI_(PBRESULT)    GetValueAt( PBULONG ulOffset, PBCHAR * pChar ) = 0;

	virtual PBWINAPI_(PBRESULT)	Append( PBIString * pString ) = 0;	
	virtual PBWINAPI_(PBRESULT)	InsertAt( PBULONG ulOffset, PBIString * pString ) = 0;
    virtual PBWINAPI_(PBRESULT)    SubString( 
		PBULONG         ulFrom, 
		PBULONG         ulTo, 
		PBIString **    ppSubString ) = 0;

    virtual PBWINAPI_(PBRESULT)    Clone( PBIString ** ppString ) = 0;
    virtual PBWINAPI_(PBRESULT)    IsNull( PBBOOL * pBool ) = 0;
    virtual PBWINAPI_(PBRESULT)    CompareTo( 
		PBIString *     pString, 
		PBINT *         piComparison ) = 0;
};

class PBIStringList	:	public PBIUnknown
{
  public:

	virtual PBWINAPI_(PBRESULT)	Add( PBIString * ) = 0;
	virtual PBWINAPI_(PBRESULT)	Remove( PBIString * ) = 0;

	virtual PBWINAPI_(PBRESULT)	GetCount( PBINDEX * pCount ) = 0;

	virtual PBWINAPI_(PBRESULT)	GetFirst( PBIString ** pFirst ) = 0;
	virtual PBWINAPI_(PBRESULT)	GetNext( PBIString ** pNext ) = 0;

	virtual PBWINAPI_(PBRESULT)	GetLast( PBIString ** pLast ) = 0;
	virtual PBWINAPI_(PBRESULT)	GetPrevious( PBIString ** pPrevious ) = 0;
};

class PBIStringToBlob	: 	public PBIUnknown
{
  public:

	virtual PBWINAPI_(PBRESULT)	GetAsBlob( PBIBlob ** ppBlob ) = 0;
	virtual PBWINAPI_(PBRESULT)	ReadFromBlob( PBIBlob * pBlob ) = 0;
};

extern "C"
{
    PBWINAPI_(PBRESULT) CreatePBIString( 
		PBCHAR *        pValue,
		PBIString **    ppString );

	PBWINAPI_(PBRESULT) CreatePBIStringList( 
		PBIStringList ** ppStringList );
};

//-----------------------------------------------------------------------------

class PBIDateTime	:	public PBIUnknown
{
  public:

	virtual PBWINAPI_(PBRESULT)	GetDate( PBIDate ** ppDate ) = 0;
	virtual PBWINAPI_(PBRESULT)	GetTime( PBITime ** ppTime ) = 0;

	virtual PBWINAPI_(PBRESULT)	Clone( PBIDateTime ** ppDateTime ) = 0;
	virtual PBWINAPI_(PBRESULT)	IsNull( PBBOOL * pBool ) = 0;
	virtual PBWINAPI_(PBRESULT)	CompareTo(
		PBIDateTime *	pDateTime,
		PBINT *			pComparison ) = 0;
};

class PBIDateTimeToBlob	:	public PBIUnknown
{
  public:
 
    virtual PBWINAPI_(PBRESULT)    GetAsBlob( PBIBlob ** ppBlob ) = 0;
    virtual PBWINAPI_(PBRESULT)    ReadFromBlob( PBIBlob * pBlob ) = 0;
};

class PBIDateTimeToString	:	public PBIUnknown
{
  public:
 
    virtual PBWINAPI_(PBRESULT)    GetAsString( PBIString ** ppString ) = 0;
    virtual PBWINAPI_(PBRESULT)    ReadFromString( PBIString * pString ) = 0;
};

extern "C"
{
	PBWINAPI_(PBRESULT) CreatePBIDateTime( 
		PBIDate * pDate, 
		PBITime * pTime,
		PBIDateTime ** ppDateTime );
};

	
//-----------------------------------------------------------------------------

class PBIDate	:	public PBIUnknown
{
  public:
 
	virtual PBWINAPI_(PBRESULT)	GetYear( PBSHORT * pYear ) = 0;
	virtual PBWINAPI_(PBRESULT)	GetMonth( PBINT * pMonth ) = 0;
	virtual PBWINAPI_(PBRESULT)	GetDayOfMonth( PBINT * pDay ) = 0;
	virtual PBWINAPI_(PBRESULT)	GetDayOfWeek( PBINT * pDay ) = 0;

	virtual PBWINAPI_(PBRESULT)	DaysAfter( 
		PBIDate * 	pDate, 
		PBLONG * 	pDaysAfter ) = 0;
	virtual PBWINAPI_(PBRESULT)	RelativeDate( 
		PBLONG 		iDays, 
		PBIDate ** 	ppDate ) = 0;

    virtual PBWINAPI_(PBRESULT)    Clone( PBIDate ** ppDate ) = 0;
    virtual PBWINAPI_(PBRESULT)    IsNull( PBBOOL * pBool ) = 0;
    virtual PBWINAPI_(PBRESULT)    CompareTo(
        PBIDate *   	pDate,
        PBINT *         pComparison ) = 0;
};

class PBIDateToBlob	:	public PBIUnknown
{
  public:
 
    virtual PBWINAPI_(PBRESULT)    GetAsBlob( PBIBlob ** ppBlob ) = 0;
    virtual PBWINAPI_(PBRESULT)    ReadFromBlob( PBIBlob * pBlob ) = 0;
};

class PBIDateToString	:	public PBIUnknown
{
  public:

    virtual PBWINAPI_(PBRESULT)    GetAsString( PBIString ** ppString ) = 0;
    virtual PBWINAPI_(PBRESULT)    ReadFromString( PBIString * pString ) = 0;

	virtual PBWINAPI_(PBRESULT)	GetDayOfWeekName( PBIString ** ppString ) = 0;
};

extern "C"
{
	PBWINAPI_(PBRESULT) CreatePBIDateToday( PBIDate ** ppDate );
	PBWINAPI_(PBRESULT) CreatePBIDate( 
		PBSHORT		iYear,
		PBINT		iMonth,
		PBINT		iDay,
		PBIDate ** 	ppDate );
};

//-----------------------------------------------------------------------------

class PBITime 	:	public PBIUnknown
{
  public:

	virtual PBWINAPI_(PBRESULT)	GetHour( PBINT * iHour ) = 0;
	virtual PBWINAPI_(PBRESULT)	GetMinute( PBINT * iMinute) = 0;
	virtual PBWINAPI_(PBRESULT)	GetSecond( PBINT * iSecond ) = 0;

	virtual PBWINAPI_(PBRESULT)	SecondsAfter( 
		PBITime * 		pTime, 
		PBLONG * 		pSecondsAfter ) = 0;
	virtual PBWINAPI_(PBRESULT)	RelativeTime(
		PBLONG			lSeconds,
		PBITime **		ppTime ) = 0;

    virtual PBWINAPI_(PBRESULT)    Clone( PBITime ** ppTime ) = 0;
    virtual PBWINAPI_(PBRESULT)    IsNull( PBBOOL * pBool ) = 0;
    virtual PBWINAPI_(PBRESULT)    CompareTo(
        PBITime *   	pTime,
        PBINT *         pComparison ) = 0;
};

class PBITimeToBlob	:	public PBIUnknown
{
  public:
 
    virtual PBWINAPI_(PBRESULT)    GetAsBlob( PBIBlob ** ppBlob ) = 0;
    virtual PBWINAPI_(PBRESULT)    ReadFromBlob( PBIBlob * pBlob ) = 0;
};

class PBITimeToString	:	public PBIUnknown
{
  public:

    virtual PBWINAPI_(PBRESULT)    GetAsString( PBIString ** ppString ) = 0;
    virtual PBWINAPI_(PBRESULT)    ReadFromString( PBIString * pString ) = 0;
};

extern "C"
{
	PBWINAPI_(PBRESULT) CreatePBITimeNow( PBITime ** ppTime );
	PBWINAPI_(PBRESULT) CreatePBITime( 
		PBINT iHour, 
		PBINT iMinute, 
		PBINT iSecond,
		PBITime ** ppTime );
};

//-----------------------------------------------------------------------------

class PBIDecimal	:	public PBIUnknown
{
  public:

	virtual PBWINAPI_(PBRESULT)	Clone( PBIDecimal ** ppDecimal ) = 0;
	virtual PBWINAPI_(PBRESULT)	IsNull( PBBOOL * pBool ) = 0;
	virtual PBWINAPI_(PBRESULT)	CompareTo(
		PBIDecimal *	pDecimal,
		PBINT *			pComparison ) = 0;

	virtual PBWINAPI_(PBRESULT)	GetDecimalAsDouble( PBDOUBLE * pDouble ) = 0;
	virtual PBWINAPI_(PBRESULT)	SetDecimalFromDouble( PBDOUBLE ) = 0;
};

class PBIDecimalToBlob	:	public PBIUnknown
{
  public:

    virtual PBWINAPI_(PBRESULT)    GetAsBlob( PBIBlob ** ppBlob ) = 0;
    virtual PBWINAPI_(PBRESULT)    ReadFromBlob( PBIBlob * pBlob ) = 0;
};

class PBIDecimalToString	:	public PBIUnknown
{
  public:

    virtual PBWINAPI_(PBRESULT)    GetAsString( PBIString ** ppString ) = 0;
    virtual PBWINAPI_(PBRESULT)    ReadFromString( PBIString * pString ) = 0;
};

extern "C"
{
	PBWINAPI_(PBRESULT) CreatePBIDecimal(
		PBIDecimal ** ppDecimal );
};

//-----------------------------------------------------------------------------

class PBIBlob	:	public PBIUnknown
{
  public:

	virtual PBWINAPI_(PBRESULT)	GetSize( PBULONG * pSize ) = 0;
	virtual PBWINAPI_(PBRESULT)	GetData( PBPVOID * ppData ) = 0;

	virtual PBWINAPI_(PBRESULT)	InsertData( 
		PBULONG 		lOffset, 
		PBIBlob * 		pData ) = 0;
	virtual PBWINAPI_(PBRESULT)	ExtractData( 
		PBULONG 		lStart, 
		PBULONG 		lSize, 
		PBIBlob ** 		ppExtract ) = 0;
 
	virtual PBWINAPI_(PBRESULT)	Clone( PBIBlob ** ppBlob) = 0;
	virtual PBWINAPI_(PBRESULT)	IsNull( PBBOOL * pBool ) = 0;
};

extern "C"
{
	PBWINAPI_(PBRESULT) CreatePBIBlob(
		PBULONG		lSize,
		PBPVOID		pData,
		PBIBlob ** 	ppBlob );
};

#endif  //  PBGTYPIF_H
