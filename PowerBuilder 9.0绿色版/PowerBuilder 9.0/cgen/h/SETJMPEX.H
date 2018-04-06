/*
 *  setjmp.h
 *
 *  Copyright by WATCOM International Corp. 1988-1996.  All rights reserved.
 */
#ifndef _SETJMPEX_H_INCLUDED
#define _SETJMPEX_H_INCLUDED
#if !defined(_ENABLE_AUTODEPEND)
  #pragma read_only_file;
#endif

#ifdef __cplusplus
extern "C" {
#endif

#ifndef _COMDEF_H_INCLUDED
 #include <_comdef.h>
#endif
 
#if !defined(_SETJMP_H_INCLUDED_)
 #include <setjmp.h>
#endif

#if defined(__AXP__)
 _WCRTLINK extern int _setjmpex(jmp_buf __env);
 
 #undef setjmp
 #define setjmp(__env)  _setjmpex(__env)
#endif

#ifdef __cplusplus
};
#endif

#endif
