/*
 * =====================================================================================
 *
 *       Filename:  scanf.c
 *
 *    Description:  scanf的返回值问题。
 *
 *        Version:  1.0
 *        Created:  2014年07月28日 11时12分37秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Sweetheart502, liyingxiao502@gmail.com
 *        Company:  Class 1304 of Software Engineering
 *
 * =====================================================================================
 */

#include <stdio.h>

int main(void)
{
	int i, j, k;

	printf ( "%d\n", scanf ( "%d % d %d", &i, &j, &k ) );

	/* 
	 * scanf的返回值是给几个变量赋了值
	 * 运行结果：3
	 */
	
	return 0;
}
