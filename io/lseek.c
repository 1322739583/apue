//
// Created by xzh on 2021/7/10.
//

#include "../apue.h"

int main(){
    if (lseek(STDIN_FILENO,0,SEEK_CUR)==-1){
        printf("cannot seek\n");
    } else{
        printf("seek OK\n");
    }
    exit(0);
}