/**
 *设数组a有十个元素，要求：
 *输出a两遍，一个循环且只
 *调一次。
 */

#include <stdio.h>
#define N 10

int main (void)
{
	int a[N], i;

	//输入数组元素
	for (i = 0; i < N; i++) {
		scanf ("%d", a+i);
	}

	//一重循环，将数组输出两遍
	for (i = 0; i < N *2; i++) {
		printf ("%4d", a[i % 10]);
	}

	printf ("\n");

	return 0;
}
