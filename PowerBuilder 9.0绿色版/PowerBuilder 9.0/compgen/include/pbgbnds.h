//              Copyright Sybase, Inc. 1998
//
//      Sybase, Inc. ("Sybase") claims copyright in this
//      program and documentation as an unpublished work, versions of
//      which were first licensed on the date indicated in the foregoing
//      notice.  Claim of copyright does not imply waiver of Sybase's
//      other rights.
//-----------------------------------------------------------------------------
//
//  pbgbnds.h
//
//class PBGArrayBounds;
#ifndef PBGBNDS_H
#define PBGBNDS_H

#include "oswindow.h"
#include "pbstg.h"
#include "ottypes.h"
#include "pbcom.h"
#include "pbgtypes.h"

class PBGArrayBounds {
	public:
		PBGArrayBounds ();
		PBGArrayBounds (PBINT);
		~PBGArrayBounds();

		PBRESULT setDims   (PBINT);
		PBRESULT setBounds (PBINT, PBLONG *);
		PBRESULT setUpper  (PBINDEX, PBLONG);
		PBRESULT setLower  (PBINDEX, PBLONG);
		PBLONG   getUpper  (PBINDEX);
		PBLONG   getLower  (PBINDEX);

		PBINT    getDims () { return m_cDims; }
		PBLONG * getBounds () { return m_pBounds; }
		PBCHAR * getszUpper(PBINDEX idx) {
			pbstg_sprintf(szBound, PBTEXT("%d"), getUpper(idx)); return szBound; }
		PBCHAR * getszLower(PBINDEX idx) {
			pbstg_sprintf(szBound, PBTEXT("%d"), getLower(idx)); return szBound; }

	private:
		void freeBounds()
				{ if (!m_bExternal && m_pBounds) free(m_pBounds); m_pBounds = NULL; }

		PBLONG *m_pBounds;
		PBINT   m_cDims;
		PBBOOL  m_bExternal;

		PBCHAR  szBound[20];
};
#endif
