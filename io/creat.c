#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<fcntl.h>
#define PERM 0755
int main(int argc, char const *argv[])
{
    int fd=creat("cowsay.txt",PERM);
    printf("fd=%d",fd);
    return 0;
}