/*************************************************************************
 **	    >  Name : my_sigaction.c
 **	    > Author: LiYingXiao (Sweethreart502) 
 **	    >  Mail : liyingxiao502@gmail.com
 **	    >  Blog : http://blog.csdn.net/u013166575
 **	    > Created Time: 2015年12月17日 星期四 15时45分04秒
 **     > Description: 
 ************************************************************************/
#include <stdio.h>
#include <unistd.h>
#include <signal.h>

int temp = 0 ;

void handler_sigint ( int signo )
{
    printf ( "function.\n" ) ;
    sleep (5) ;
    temp++ ;
    printf ( "the value is %d.\n" , temp ) ;
    printf ( "in hander_sigint , after sleep.\n " ) ;
}

int main ( int argc , char * argv[] )
{
    struct sigaction act ;

    act.sa_handler = handler_sigint ;
    act.sa_flags = SA_NOMASK ;          // 在结束此信号前允许此信号再次递送，相当于中断嵌套


    // 信号安装函数
    sigaction ( SIGINT , &act , NULL ) ;

    while (1) ;

    return 0 ;
}
