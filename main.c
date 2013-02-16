#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"shellsort.h"
#include"common.h"
#include"dbg_print.h"

static inline int*
myAlloc( int size )
{
    int *ary = NULL;
    ary = (int *)malloc( sizeof(int) * size );
    if( NULL == ary )
    {
        printf("malloc error.\n");
        exit(EXIT_FAILURE);
    }
    memset( ary, 0x00, sizeof(int) * size );

    return ary;
}

int
main( int argc, char **argv )
{
    int *ary = NULL;    // sort target
    int size = 0;       // array size

    dbg_print("argc = %d, argv = %p\n", argc, argv );

    size = argc;

    // allocate
    ary = myAlloc( size );

    // convert string(argv) to int(ary)
    cnvToInt( size, (const char **)argv, ary );

    // shell sort
    shellsort( ary, size );

    // print
    aryPrint( ary, size );

    // post
    free( ary );

    return 0;
}
