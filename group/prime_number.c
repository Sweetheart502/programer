/*
 * =====================================================================================
 *
 *       Filename:  4.c
 *
 *    Description:  给定整数，输出n以内的素数个数。
 *
 *        Version:  1.0
 *        Created:  2014年06月11日 15时37分48秒
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
#include <math.h>
#include <time.h>
#define N 1000000

int prime (int x) 
{
	int i;

	for (i = 2; i <= sqrt(x); i++) {
		if (x % i == 0)
		      return 0;
	}

	return 1;
}


int main(int argc, char *argv[])
{
	int number, i, sum = 1;
	int a[N] = {2,0}, flag;

	printf ("input the number:\n");
	scanf ("%d", &number);

	for (i = 3; i <= number; i += 2) {
		flag = prime (i);

		if (flag) {
			a[sum++] = i;
		}
	}

	printf("总数为:\n");
	printf("%d\n", sum);
/*
	printf("分别为：\n");
	for (i = 0; i < sum; i++) {
		printf("%3d", a[i]);
	}

	printf("\n");
*/
	printf("Time used = %.21f\n", (double)clock() / CLOCKS_PER_SEC);
	return EXIT_SUCCESS;
}

