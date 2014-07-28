/*
 * =====================================================================================
 *
 *       Filename:  year.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年06月18日 12时20分51秒
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
	int i, flag, sum = 0;
	int a[N] = {31,0,31,30,31,30,31,31,30,31,30,31};

	printf ("\t\t\tPlease input the data:\n\n\t\t\t");
	scanf ("%d %d %d", &year, &month, &day);

	if (year % 4 == 0) {
	      flag = 1;
	      a[1] = 29;
	}
	else {
	      flag = 0;
	      a[1] = 28;
	}
	
	for (i = 0; i < month - 1; i++) {
		sum += a[i];
	}
	sum += day;

	printf ("\n\n\t\t\tToday is the %d day of the year!\n", sum);

	return EXIT_SUCCESS;
}

