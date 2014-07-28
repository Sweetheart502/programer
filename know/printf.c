/*
 * =====================================================================================
 *
 *       Filename:  printf.c
 *
 *    Description:  printf 的返回值问题:函数返回至是整型。若成功则返回输出的字符数，输出出错则返回负值。
 *
 *        Version:  1.0
 *        Created:  2014年05月25日 10时12分37秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Sweetheart502, liyingxiao502@gmail.com
 *        Company:  Class 1304 of Software Engineering
 *
 * =====================================================================================
 */


#include <stdio.h>

int main(void)
{
	int i = 43;

	printf ( "%d\n", printf ( "%d", printf ( "%d", i ) ) );

	/*
	 * 显然从最内层侧的printf开始运行：
	 * printf("%d", i)
	 * 很显然输出的i的值：43
	 * 紧接着就是printf返回值的问题：
	 * printf返回的是打印出的字符数量，
	 * “43”显然是两个字符，所以printf返回2
	 * 此时的printf(“%d", printf(...))打印
	 * 出的就是：2
	 * 同理，这个printf打印的2仅有1个字符
	 * 所以返回值是1，则最外层的打印结果为1
	 * 最后运行结果就是：4321
	 */

	return 0;
}
