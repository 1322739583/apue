//
// Created by xzh on 2021/7/10.
//

#include "../apue.h"

int main(int argc, char *argv[]) {
    int fd;
    fd=open("dup.txt",O_CREAT);
    int fd_dup=dup(fd);
    printf("fd=%d\n",fd);
    printf("fd=%d\n",fd_dup);
    return 0;
}