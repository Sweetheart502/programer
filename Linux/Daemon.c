/*************************************************************************
	> File Name: daemon.c
	> Author: 
	> Mail: 守护进程 
	> Created Time: 2015年11月04日 星期三 15时57分41秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>

/* 创建守护进程函数 */
void init_daemon () {
    pid_t pid ;
    int i ;

    if ( ( pid = fork() ) > 0 ) {
        // pid>0即父进程，故结束父进程
        exit (0) ;
    }else if ( pid < 0 ) {
        // pid<0即创建进程失败，故直接exit
        perror ( "fork error" ) ;
        exit (-1) ;
    } else {
        // pid=0即子进程,为区分称其为第一子进程
        // setsid函数使得当前子进程称为会话组长
        setsid () ;  

        if ( (pid = fork() ) > 0 ) {
            // 结束父进程
            exit (0) ;
        } else if ( pid < 0 ) {
            // 创建进程失败
            perror ( "fork" ) ;
            exit (-1) ;
        } else {
            // 第二子进程
            // 关闭打开的文件描述符
            for ( i = 0 ; i < getdtablesize () ; i++ ) {
                close ( i ) ;
            }
            // 文件创建掩码清除
            umask ( 0 ) ;
        }
    }
}

int main()
{
    // 定义字符串指针
    char * buf = "hello world\n" ;
    // 创建文件描述符
    int fd ;

    // 调用函数
    init_daemon () ;

    while ( 1 ) {
        // 打开文件（可读写，追加方式）
        if ( ( fd = open ( "hello.txt" , O_CREAT | O_WRONLY | O_APPEND , 0600 ) ) < 0 ) {
            perror ( "open" ) ;
            exit ( -1 ) ;
        }

        // 写入字符串buf
        write ( fd , buf , strlen ( buf ) ) ;
        close ( fd ) ;
        sleep ( 1 ) ;
    }

    return 0;
}
