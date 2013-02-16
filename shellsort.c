// system header
#include<stdio.h>

// original header
#include"dbg_print.h"
#include "shellsort.h"

/*
 *  get intarval
 *   @argv  [in]    size    配列のサイズ
 *   @return    interval
 */
STATIC unsigned int
getIntervalMax( unsigned int size )
{
    unsigned int h = 1;
    while( h < size )
    {
        h = 3*h + 1;        // nより小さい範囲で最大のhを決める
    }

    return h;
}

/*
 *  insert
 *   @argv  [in]        j       挿入法開始位置
 *          [in]        ival    間隔
 *          [in]        tmp     挿入対象
 *          [in/out]    *ary    ソート対象の配列
 */
STATIC void
_shiftAndInsert( int j, int ival, int tmp, int *ary )
{

    dbg_print( "j = %d, ival = %d, tmp = %d, ary = %p\n", j, ival, tmp, ary );

    while( tmp < ary[j] )
    {
        ary[j+ival] = ary[j];   // 要素をシフトする
        j = j - ival;           // ソート間隔分移動
        if( j <= 0 )
        {
            // 番兵(ary[0])を含め、ソート範囲外のとき、ループを抜ける
            break ;
        }
    }
    ary[j+ival] = tmp;         // 挿入する

    return ;
}

/*
 *  
 */
STATIC void
__shellsort( int ival, int *ary, int size )
{
    int _i = 0;          // カウンタ
    int _j = 0;          // 挿入法開始位置
    int _tmp = 0;        // 挿入対象の一時格納領域

    dbg_print( "ival = %d, ary = %p, size = %d\n", ival, ary, size );

    for( _i = ival+1; _i < size; _i++ )
    {
        _tmp = ary[_i];         // 挿入対象
        _j    = _i - ival;      // 挿入法開始位置
        _shiftAndInsert( _j, ival, _tmp, ary );
    }

    return ;
}

/*
 * shellsort body
 *  @argv   [in]        ival    ソート間隔
 *          [in/out]    *ary    ソート対象
 *          [in]        size    ソート対象の配列サイズ
 */
STATIC void
_shellsort( unsigned int ival, int *ary, int size )
{
    dbg_print( "ival = %d, ary = %p, size = %d\n", ival, ary, size );

    while( ival > 1 )
    {
        ival = ival / 3;                      // 比較対象の間隔を縮小する
        __shellsort( ival, ary, size );
    }

    return ;
}

/*
 * shellsort
 *  @argv   [in/out]    *ary    ソート対象の配列の先頭ポインタ
 *          [in]        size    ソート対象の配列サイズ
 */
void
shellsort( int *ary, unsigned int size )
{
    unsigned int _ival = 1;          // ソート間隔

    dbg_print( "ary = %p, size = %d\n", ary, size );

    _ival = getIntervalMax( size );

    _shellsort( _ival, ary, size );

    return ;
}
