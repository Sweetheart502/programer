/**
 *一个递增有序的数组，插入一个元素，
 *使其依然递增有序，再逆置。（指针）
 */

/*2014.5.8---assignment*/

#include <stdio.h>
#define N 5

int main(void)
{
	int a[N], i, j, k;
	int num, t;

	for (i = 0; i < N; i++) {
		scanf("%d", a + i);
	}

	//冒泡法排序，使数组升序
	for (i = 0; i  <N - 1; i++) {
		for (j = 0; j < N; j++) {
			if (a[j] > a[j + 1]) {
				t = a[j];
				a[j] = a[j + 1];
				a[j + 1] = t;
			}
		}
	}

	//输入插入数字
	printf("input the number:\n");
	scanf("%d", &num);

	return 0;
}

