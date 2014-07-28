/*
 * =====================================================================================
 *
 *       Filename:  perfect_num.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年06月18日 11时19分09秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Sweetheart502, liyingxiao502@gmail.com
 *        Company:  Class 1304 of Software Engineering
 *
 * =====================================================================================
 */

#include <unistd.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 1000

int main(int argc, char *argv[])
{
	int num, a[N], sum = 0;
	int i, j, k = 0;

	for (num = 2; num < 1000; num++) {
		k = 0;
		sum = 0;
		//记录num的约数
		for (j = 1; j < num; j++) {
			//判断是否是约数
			if (num % j == 0) {
				a[k++] = j;
			}
		}
		//求约数之和
		for (j = 0; j < k; j++) {
			sum += a[j];
		}
		//判断是否相等，即是否是完数
		if (sum == num) {
			printf ("%4d", num);
		}
	}

	printf ("\n");

	return EXIT_SUCCESS;
}

