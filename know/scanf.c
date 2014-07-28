//scanf 的返回值问题

#include <stdio.h>

int main(void)
{
	int i, j, k;
	printf("%d\n", scanf("%d%d%d",&i,&j,&k));

	//scanf的返回值是给几个变量赋了值
	//运行结果：3
	
	return 0;
}
