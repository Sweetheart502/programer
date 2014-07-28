/**
 *          结构体的内存对齐
 *原因：为了高效的存取访问，造成一部分空间浪费，以追求时间的缩短。
 *注意：每个成员的地址都应是4/8的倍数。
 *      结构体成员相同而顺序不同，大小可能不同，即可能造成内存空间的浪费。
 *      整个结构体变量的大小应是4/8的倍数。
 */

#include <stdio.h>
struct stud {
	int x;
	char ch;
	double d;
};
int main(void)
{
	struct stud e;

	printf("%d\n", sizeof(e));
	//输出结果：16

	/**
	 *x	4B
	 *ch	1B
	 *填充	3B
	 *d	8B
	 */	

	return 0;
}

