/*
 *  wsample.h	WATCOM Execution Sampler include file
 *
 *  Copyright by WATCOM International Corp. 1988-1996.  All rights reserved.
 */
#ifndef _WSAMPLE_H_INCLUDED
#define _WSAMPLE_H_INCLUDED
#if !defined(_ENABLE_AUTODEPEND)
  #pragma read_only_file;
#endif
#ifdef __cplusplus
extern "C" {
#endif
#ifdef _MARK_ON
  #if defined(__386__)
    extern void __mark( char __far * );
    #pragma aux __mark = 0xcc __parm __nomemory [__dx __eax] __modify __exact __nomemory [];
  #elif defined(M_I86)
    extern void __mark( char __far * );
    #pragma aux __mark = 0xcc __parm __nomemory [__dx __ax] __modify __exact __nomemory [];
  #else
    #error __mark not defined for this platform
  #endif
  #define _MARK_( x )	__mark( x )
#else
  #define _MARK_( x )
#endif
#ifdef __cplusplus
};
#endif
#endif
