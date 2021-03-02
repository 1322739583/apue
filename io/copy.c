#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <time.h>
#define BUFFSIZE 17
#define PERM 0755
int main()
{
    int n;
    char buf[1024]="this is line one";

    int fd=open("cowsay.txt",O_CREAT+O_RDWR);
    printf("fd=%d\n",fd);
    int buff_size=strlen(buf);
    size_t num=write(fd,buf,buff_size);
    
    //fsync(fd);
    //int fd2=open("cowsay.txt",O_CREAT+O_RDWR);
    
     printf("num=%d\n",num);
     char buf2[2];
     lseek(fd,0,SEEK_SET);
      
     int num2=read(fd,buf2,2);
     printf("num2=%d\n",num2);
    // while ((n = read(STDIN_FILENO, buf, BUFFSIZE)) > 0)
    //     if (write(STDOUT_FILENO, buf, n) != n)
    //         perror("write error");
    // if(n<0)
    // perror("read error");
    exit(0);
}