#ifndef __COMMON_H__
#define __COMMON_H__
/*
 *  Array print
 *  @argv   [in]    *ary    print target
 *          [in]    size    array size
 */
void aryPrint( int *ary, int size );

/*
 *  Convert string to int
 */
void cnvToInt( int size, const char **argv, int *ary );

#endif  // __COMMON_H__
