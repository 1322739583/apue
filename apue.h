//
// Created by xzh on 2021/6/3.
//

#ifndef LINUX_APUE_H
#define LINUX_APUE_H

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<string.h>

void err_sys(char *info){
    perror(info);
    exit(1);
}


#endif //LINUX_APUE_H
