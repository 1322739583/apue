//
// Created by xzh on 2021/7/10.
//

#include "../apue.h"

int main(int argc, char *argv[]) {
    if (argc!=2){
        perror("usage: a.out[OPTION]");
        exit(1);
    }
    int val;
    printf("%s",atoi(argv[1]));
    if ((val=fcntl(atoi(argv[1]),F_GETFL,0))<0){

    }

    return 0;
}