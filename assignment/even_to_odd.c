/**
 *设数据集合无序无重复值，都存储正
 *整数，将所有的奇数放在偶数之前。
 *要求：用三段不同的代码来实现。
 */

/*2014.5.8----assignment*/

#include <stdio.h>
#define N 10

void sort(int *p, int b[])
{
	int *start = p, *q, temp;

	for ()

}


int main(void)
{
	int a[N], b[N], i;                    //b数组存放改编后的数组元素

	//输入数据
	printf("input the array:\n");
	for (i = 0; i < N; i++) {
		printf("input the %d number:\n", i+1);
		scanf("%d", a + i);
	}

	//调用函数实现交换位置
	sort(a);

	//输出结果
	printf("output the array:\n");
	for(i = 0; i < N; i++) {
		printf("%4d", a[i]);
	}

	printf("\n");

	return 0;
}
