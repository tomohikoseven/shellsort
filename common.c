#include<stdlib.h>
#include<errno.h>
#include<limits.h>
#include"dbg_print.h"

// 10進数
#define BASE 10

/*
 *  Array print
 *  @argv   [in]    *ary    print target
 *          [in]    size    array size
 */
void
aryPrint( int *ary, int size )
{
    int _i = 0;     // counter

    dbg_print( "ary = %p, size = %d\n", ary, size );

    // 番兵(ary[0])以外を出力
    for( _i = 1; _i < size; _i++ )
    {
        printf( "%d ", ary[_i] );
    }
    printf("\n");

    return ;
}

/*
 *  Convert from string to int
 *  @argv   [in]    size    array size
 *          [in]    **argv  execute argument
 *          [in]    *ary    array(int)
 */
void
cnvToInt( int size, const char **argv, int *ary )
{
    int     _i          = 0;    // counter
    char    *_endptr    = NULL;

    dbg_print("size = %d, argv = %p, ary = %p\n", size, argv, ary );

    // 使われない番兵
    ary[0] = 0;

    for( _i = 1; _i < size; _i++ )
    {
        dbg_print("===== loop = %d ===== \n", _i );
        //dbg_print("argv[%d] = %s\n", _i+1, argv[_i+1] );
        //ary[i] = atoi( argv[i+1] );
        ary[_i] = (int)strtol( argv[_i], &_endptr, BASE );
        if( ERANGE != errno )
        {
            printf("convert number = %d\n", ary[_i]);
            if( '\0' != *_endptr )
            {
                printf( "convert unable = %s\n", _endptr );
            }
        }
        else if( ary[_i] == LONG_MAX )
        {
            printf("long max over!\n");
        }
        else if( ary[_i] == LONG_MIN )
        {
            printf("long min over!\n");
        }
        dbg_print("ary[%d] = %d\n", _i, ary[_i] );
    }
    printf("%s() end\n", __func__ );

    return ;
}
