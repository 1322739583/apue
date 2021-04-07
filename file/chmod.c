#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<string.h>

int main(int argc, char const *argv[])
{
    struct stat statbuf;
    /* 关闭组执行权限，打开setGid权限*/
    if(stat("foo",&statbuf)<0)
    perror("stat error for foo\n");
    if(chmod("foo",(statbuf.st_mode& ~S_IXGRP)|S_ISGID)<0)
    perror("chmod error for foo\n");
    /*设置模式为“rw-r--r--”*/
    if (chmod("bar",S_IRUSR|S_IWUSR|S_IRGRP|S_IROTH)<0)
    perror("chmod error for bar\n"); 

    
    return 0;
}