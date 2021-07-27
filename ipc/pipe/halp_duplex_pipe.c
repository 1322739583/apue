#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <errno.h>
/*定的太小会出现异常*/
#define MAXLINE 4096

void client(int, int), server(int, int);

int main(int argc, char const *argv[])
{
    int pipe1[2], pipe2[2];
    pid_t childpid;
     pipe(pipe1); //返回0表示成功
     pipe(pipe2);
   // printf("result 1:%d\n", result1);
  //  printf("result 2:%d\n", result2);
    /*fork函数在子进程中返回0，在父进程中返回子进程id,错误返回负数*/
  //  childpid=fork();
 //   printf("childpid :%d\n",childpid);
    if ((childpid=fork()) == 0)
    { //判断是否在子进程中
        close(pipe1[1]);
        close(pipe2[0]);
        server(pipe1[0], pipe2[1]);//子进程向父进程传输数据
        exit(0);
    }

    //else
    close(pipe1[0]);
    close(pipe2[1]);
    client(pipe2[0],pipe1[1]);
    waitpid(childpid,NULL,0);
 

    exit(0);
}

void client(int readfd, int writefd)
{
    size_t len;
    ssize_t n;
    char buff[MAXLINE];
    fgets(buff, MAXLINE, stdin);
    len = strlen(buff);
    if (buff[len - 1] == '\n')
        len--;

    write(writefd, buff, len);
    while ((n = read(readfd, buff, MAXLINE)) > 0)
        write(STDOUT_FILENO, buff, n);
}

void server(int readfd,int writefd){
    int fd;
    ssize_t n;
    char buff[MAXLINE+1];

    if((n=read(readfd,buff,MAXLINE))==0)
    perror("end-of-file while reading pathname");
    buff[n]='\0';
    
    if((fd=open(buff,O_RDONLY))<0){
        snprintf(buff+n,sizeof(buff)-n,":cant't open ,%s\n",strerror(errno));
        n=strlen(buff);
        write(writefd,buff,n);
    }else{
        while((n=read(fd,buff,MAXLINE))>0)
            write(writefd,buff,n);
       close(fd);
    }
}