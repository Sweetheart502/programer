/*
 * =====================================================================================
 *
 *       Filename:  sqrt.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年06月18日 10时39分48秒
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
#include <math.h>
#include <string.h>
#define N 10000

int main(int argc, char *argv[])
{
	unsigned long i;

	for (i = 0; i < N; i++) {
	//	if ((int)sqrt(i + 100) * (int)sqrt(i + 100) == (i + 100)) {
			if ((int)sqrt(i + 268) * (int)sqrt(i +268) == (i +268))
				break;
	//	}
	}

	printf ("%ld\n", i);

	return EXIT_SUCCESS;
}

