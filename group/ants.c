/*
 * =====================================================================================
 *
 *       Filename:  ant.c
 *
 *    Description:  n只蚂蚁以每秒一厘米的速度在长为l厘米的竿子上爬行。
 *    		    当它爬到竿子的端点时就会掉落下来，由于竿子太细，两
 *    		    只蚂蚁相遇时，他们不能交错通过，只能各自反向爬回去
 *    		    ，对于每只蚂蚁，我们知道它距离竿子最左端的距离Xi，
 *    		    但不知道它当前朝向，请计算所有蚂蚁落下竿子所需最短
 *    		    时间和最长时间，蚂蚁可能向左爬，也可能向右爬。
 *
 *        Version:  1.0
 *        Created:  2014年06月12日 01时58分58秒
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


//自定义函数
void solve(int l, int n, int x[])
{
	int minT = 0, maxT = 0;           //计算最短时间&最长时间
	int i;

	//
	for (i = 0; i < n; i++) {
		minT = max(minT, min(x[i], l - x[i]));
	}

	for (i = 0; i < n; i++) {
		maxT = max (maxT, max(x[i], l - x[i]));
	}

	printf("%4d,%4d\n", minT, maxT);
}


//求较小值函数
int min (int a, int b)
{
	if (a < b)
	      return a;
	else 
	      return b;
}


//求较大值函数
int max (int a, int b)
{
	if (a > b)
	      return a;
	else 
	      return b;
}


//主函数
int main(int argc, char *argv[])
{
	int x[3] = {2, 6, 7};             //x数组存储蚂蚁距离
	int l;                            //竿子长度
	//输入竿子长度l						
	printf("please input the length:\n");
	scanf("%d", &l);

	//调用函数实现
	solve (l, 3, x);

	return EXIT_SUCCESS;
}

