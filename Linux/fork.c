/*************************************************************************
 **	    >  Name : fork.c
 **	    > Author: LiYingXiao (Sweethreart502) 
 **	    >  Mail : liyingxiao502@gmail.com
 **	    >  Blog : http://blog.csdn.net/u013166575
 **	    > Created Time: 2015年10月27日 星期二 10时27分49秒
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>

int main ( int argc , char * argv[] )
{
    int i ;
    pid_t pid1 , pid2 ;

    printf ( "当前进程父进程ppid:%d\n" , getppid () ) ;
    printf ( "当前进程pid:%d\n" , getpid () ) ;

    printf ( "___________________________________\n\n" ) ;

    if ( ( pid1 = fork () ) > 0 ) {
        // 为当前进程,返回值为子进程pid
        printf ( "I'm the parent. a \n" ) ;
        
        pid2 = fork () ;
        if ( pid2 == 0 ) {
            // 创建的子进程2
            printf ( "I'm the son2. c \n" ) ;
        }
    } else if ( pid1 == 0 ) {
        // 创建的子进程1
        printf ( "I'm the son1. b \n" ) ;
    } else {
        printf ( "error.\n" ) ;
    }

    return 0 ;
}

