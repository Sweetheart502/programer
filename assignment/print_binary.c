/**
 *任意输入一个整数x，输出
 *x的二进制码及其中1的个数。
 */

#include <stdio.h>
#define N 10

int main (void)
{
	int x, count = 0;
	int a[N], i;

	printf ("输入一个整数x：\n");
	scanf ("%d", &x);

	i = 0;
	while (x) {
		count = count + x % 2;
		a[i++] = x % 2;
		x /= 2;
	}

	for (i-- ; i >= 0; i--) {
		printf ("%d", a[i]);
	}

	printf ("\n");

	printf ("x的二进制码及其中1的个数：\n");
	printf ("%d\n", count);

	return 0;
}
