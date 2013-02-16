#ifndef __DBG_PRINT__
#define __DBG_PRINT__

// header
#include<stdio.h>

// macro
#ifdef _DEBUG
#define dbg_print( fmt, ... )   printf( "[DEBUG] %s:%d %s() " fmt, __FILE__, __LINE__, __func__, __VA_ARGS__ );
#else
#define dbg_print( fmt, ... )
#endif

#endif  // __DBG_PRINT__
