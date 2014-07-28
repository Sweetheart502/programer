/*
 * =====================================================================================
 *
 *       Filename:  interger_three.c
 *
 *    Description:  计算三加根号下五的N次方,输出后三位的结果。
 *
 *        Version:  1.0
 *        Created:  2014年06月8日 10时30分48秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Sweetheart502, liyingxiao502@gmail.com
 *        Company:  Class 1304 of Software Engineering
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <math.h>
#define N 3

int main(void)
{
	int 	a[N];
	int 	number, i;
	float 	result = 1;

	printf ( "input the number:\n" );
	scanf ( "%d", &number );

	//计算表达式结果
	for ( i = 0; i < number; i++ ) {
		result *= 3 + sqrt ( 5 );
	}

	//输出结果以验证自己的结果
	printf ( "%f\n", result );
	
	//存储后三位在数组a中
	for ( i = 2 ; i >= 0; i-- ) {
		a[i] = ( ( int ) result ) % 10;
		result /= 10;
	}

	//输出目标结果
	printf ( "the interger is :\n" );
	for ( i = 0; i < N; i++ ) {
		printf ( "%d", a[i] );
	}

	printf ( "\n" );

	return 0;
}
