/*
 * =====================================================================================
 *
 *       Filename:  break_num.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年06月18日 11时00分08秒
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
#define N 10

int main(int argc, char *argv[])
{
	int num, i, j = 0;
	int s;
	int a[N];

	printf ("Please input the num:\n");
	scanf ("%d", &num);

	s = num;
	for (i = 2; num != 1;) {
		if (num % i == 0) {
			a[j++] = i;
			num /= i;
		}
		else 
		      i++;
	}

	printf ("%d = ", s);
	for (i = 0; i < j-1; i++) {
		printf ("%d * ", a[i]);
	}

	printf ("%d\n", a[j - 1]);

	return EXIT_SUCCESS;
}

