/*
 * =====================================================================================
 *
 *       Filename:  char.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年06月18日 12时46分39秒
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

int main(int argc, char *argv[])
{
	char a = 88, b = 48;

	printf ("%c%c%c%c%c\n", b, a, a, a, b);
	printf ("%c%c%c%c%c\n", a, b, a, b, a);
	printf ("%c%c%c%c%c\n", a, a, b, a, a);
	printf ("%c%c%c%c%c\n", a, b, a, b, a);
	printf ("%c%c%c%c%c\n", b, a, a, a, b);

	return EXIT_SUCCESS;
}

