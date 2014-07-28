/*
 * =====================================================================================
 *
 *       Filename:  week.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年06月18日 12时31分13秒
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
#define N 12

int main(int argc, char *argv[])
{
	int year, month, day;
	int sum = 0, i, j;
	int a[N] = {31, 0, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};


	printf ("\n\n\t\t\tPlease input the date:\n\t\t\tdata:");
	scanf ("%d %d %d", &year, &month, &day);

	for (i = 1990; i < year; i++) {
		if (i % 4 == 0) {
			a[1] = 29;
		}
		else 
			a[1] = 28;

		for (j = 0; j < 12; j++) {
			sum += a[j];
		}
	}
	if (year % 4 == 0) {
		a[1] = 29;
	}
	else 
	      a[1] = 28;

	for (j = 0; j < month - 1; j ++) {
		sum += a[j];
	}

	sum += day;

	printf ("\n\t\t\tToday is 星期 %d\n", ((sum + 3) % 7) + 1);

	return EXIT_SUCCESS;
}

