#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<fcntl.h>

int main(int argc, char const *argv[])
{
    //int fd=open("cowsay.txt",O_WRONLY);//文件不存在的话fd返回-1
    //文件不存在则创建文件，文件的位置
    //int fd=open("cowsay.txt",O_RDWR|O_CREAT); 
    int fd=open("cowsay.txt",O_CREAT,0755);
   // int BUFF_SIZE=5;
   // char buff[BUFF_SIZE];
   // size_t data=read(fd,buff,BUFF_SIZE);
   // printf("data=%d\n",data);
    
    printf("fd=%d\n",fd);

    return 0;
}