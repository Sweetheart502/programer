/*************************************************************************
 **	    >  Name : my_signal.c
 **	    > Author: LiYingXiao (Sweethreart502) 
 **	    >  Mail : liyingxiao502@gmail.com
 **	    >  Blog : http://blog.csdn.net/u013166575
 **	    > Created Time: 2015年12月17日 星期四 15时17分46秒
 **     > Description: 
 ************************************************************************/
#include <stdio.h>
#include <signal.h>

void handler_sigint ( int signo )
{
    printf ("function.\n") ;
}

int main ( int argc , char * argv[] )
{
    signal ( SIGINT , handler_sigint ) ;

    while ( 1 ) ;

    return 0 ;
}

