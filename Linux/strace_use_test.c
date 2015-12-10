/*************************************************************************
 **	    >  Name : strace_use_test.c
 **	    > Author: LiYingXiao (Sweethreart502) 
 **	    >  Mail : liyingxiao502@gmail.com
 **	    >  Blog : http://blog.csdn.net/u013166575
 **	    > Created Time: 2015年11月02日 星期一 21时58分10秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>

int main ( int argc , char * argv[] )
{
    int fd , i = 0 ;

    fd = open ( "/tmp/non_file" , O_RDONLY ) ;

    if ( fd < 0 ) {
        i = 2 ;
    } else {
        i = 1 ;
    }
    return i ;
}

