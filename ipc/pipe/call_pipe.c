#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
/**
 * 父进程通过管道传输两个数据给子进程，由子进程负责从管道中读取并输出 
 */
int main(void)
{
    int fd[2]; //fd[0]读取数据，fd[1]写入数据
    //创建管道
    if (pipe(fd) < 0)
    {
        perror("pipe error");
    }
    __pid_t pid;
    if ((pid = fork()) < 0)
    {
        perror("fork error");
    }
    else if (pid > 0) //大于0表示fork的是父进程
    {
        close(fd[0]); //父进程用来写入数据，所有用不到fd[0]
        int start = 1, end = 100;
        if (write(fd[1], &start, sizeof(int)) != sizeof(int))
        {
            perror("write error");
            exit(1);
        }
        if (write(fd[1], &end, sizeof(int))!=sizeof(int)){
            perror("write error");
            exit(1);
        }
        close(fd[1]);
       
    }
    else //等于0运行子进程
    {
        close(fd[1]);//子进程用不到写入操作，所以关闭fd[1]
        int start,end;
        //读取是从头开始读的，写入是从尾部写入，这里要特别注意
        if (read(fd[0],&start,sizeof(int))!=sizeof(int))
        {
            perror("read error");
        }
         if (read(fd[0],&end,sizeof(int))!=sizeof(int))
        {
            perror("read error");
        }

     printf("child process read start:%d,end:%d",start,end);
        close(fd[0]);
        
    }

    exit(0);
}