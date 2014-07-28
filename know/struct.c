/*
 * =====================================================================================
 *
 *       Filename:  struct.c
 *
 *    Description:  结构体的内存对齐。
 *
 *        Version:  1.0
 *        Created:  2014年05月20日 18时12分27秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Sweetheart502, liyingxiao502@gmail.com
 *        Company:  Class 1304 of Software Engineering
 *
 * =====================================================================================
 */

#include <stdio.h>

struct stud {
	int 	x;
	char 	ch;
	double 	d;
};

int main(void)
{
	struct stud e;

	/*
	 * 原因: 为了高效的存取访问，造成一部分空间浪费，以追求时间的缩短。
	 * 注意: 每个成员的地址都应是4/8的倍数。
	 *       结构体成员相同而顺序不同，大小可能不同，即可能造成内存空间的浪费。
	 *       整个结构体变量的大小应是4/8的倍数。
	 */

	printf ( "%d\n", sizeof ( e ) );
	/* 输出结果：16 */

	/*
	 * x	4B
	 * ch	1B
	 * 填充	3B
	 * d	8B
	 */	

	return 0;
}

