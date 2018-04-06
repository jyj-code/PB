//-----------------------------------------------------------------------------
//      pbgtyp.h
//-----------------------------------------------------------------------------

#ifndef PBGTYP_H
#define PBGTYP_H

#ifndef PBGTYPIF_H
#include "pbgtypif.h"
#endif
 

class PBString
{
	// No virtual functions or additional data members.
	// This class should be no bigger than sizeof(PBIString*)

  private:
 
	PBIString* m_pString;

  public:

	// CONSTRUCTORS/DESTRUCTORS

	// Create an additional reference to this string
	PBString(PBIString* pString) 
	{ m_pString = pString; m_pString->AddRef(); }

	// Duplicate the string in a new string
	PBString(const PBCHAR* pString = NULL) 
	{ CreatePBIString((PBCHAR*)pString, &m_pString); }

	// Copy constructor
	PBString(const PBString& rString) 
	{ m_pString = rString.m_pString; m_pString->AddRef(); }

	// Clean up the references to the string
	~PBString()
	{ m_pString->Release(); }

	// OPERATORS

	// Assignment operator
	PBString operator=(const PBString& rString) { 
		if (&rString != this) { 
			m_pString->Release();
			m_pString = rString.m_pString; 
			m_pString->AddRef(); 
		} 
		return *this;
	}

	PBString operator=(const PBCHAR* pString) {
		m_pString->Release();
		CreatePBIString((PBCHAR*)pString, &m_pString);
		return *this;
	}

	// String comparison
	PBBOOL operator==(const PBString& rString) const
	{ PBINT r; m_pString->CompareTo(rString, &r); return r == 0; }
	PBBOOL operator!=(const PBString& rString) const
	{ PBINT r; m_pString->CompareTo(rString, &r); return r != 0; }
	PBBOOL operator<=(const PBString& rString) const
	{ PBINT r; m_pString->CompareTo(rString, &r); return r <= 0; }
	PBBOOL operator>=(const PBString& rString) const
	{ PBINT r; m_pString->CompareTo(rString, &r); return r >= 0; }
	PBBOOL operator<(const PBString& rString) const
	{ PBINT r; m_pString->CompareTo(rString, &r); return r < 0; }
	PBBOOL operator>(const PBString& rString) const
	{ PBINT r; m_pString->CompareTo(rString, &r); return r > 0; }

	// Return a pointer to the PBIString
	operator PBIString*() const
	{ return m_pString; }

	// Return a pointer to a contstant string
	operator const PBCHAR*() const
	{ const PBCHAR* pString; m_pString->GetValue((PBCHAR**)&pString); return pString; }

	// Get a character in the string
	PBCHAR operator[](PBULONG ulOffset) const
	{ PBCHAR ch; m_pString->GetValueAt(ulOffset, &ch); return ch; }

	// METHODS

	// Get the length of the string
	PBULONG GetLength() const
	{ PBULONG ulLength; m_pString->GetLength(&ulLength); return ulLength; }

	// Return a sub string
	PBString SubString(PBULONG ulStart, PBULONG ulEnd) const
	{ PBIString* pString; m_pString->SubString(ulStart, ulEnd, &pString); return PBString(pString); }

	// Return TRUE if the string pointer is NULL
	PBBOOL IsNull() const
	{ PBBOOL b; m_pString->IsNull(&b); return b; }
};

#endif  //  PBGTYP_H
