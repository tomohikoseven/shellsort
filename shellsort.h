#ifndef __SHELLSORT_H_
#define __SHELLSORT_H_

#ifdef _DEBUG
#define STATIC
#else
#define STATIC static
#endif

/*
 * shellsort
 *  @argv   [in/out]    *ary    ソート対象の配列の先頭ポインタ
 *          [in]        size    ソート対象の配列サイズ
 */
extern void shellsort( int *ary, unsigned int size );

#endif  // __SHELLSORT_H_
