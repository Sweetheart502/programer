/**
 *某个数据集合中无重复值，输
 *出该数据集合中最大的两个值。
 *要求：一次循环，同时求出。
 */

/*2014.5.8---assignment*/

#include <stdio.h>
#define N 10

int main(void) 
{
	int a[N];
	int i;
	int first, second;

	for(i = 0; i < N; i++) {
		printf("please input the %d number:\n", i + 1);
		scanf("%d", a+i);
	}


	printf("output the first & second:\n");
	printf("first = %4d  second = %4d\n", first, second);

	return 0;
}
