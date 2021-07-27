//
// Created by xzh on 2021/7/16.
//

#include "../apue.h"
#include "wait.h"

int main(int argc, char *argv[]) {

    pid_t pid;
    if ((pid = fork()) < 0) {
        perror("fork error");
        exit(x1);
    } else if (pid == 0) {
        if(execl("/home/xzh/linux/cmake-build-debug/testinterp",
                 "testinterp","myarg1","My arg2",NULL)<0){
            perror("exec error");
            exit(1);
        }
    }

    if (waitpid(pid, NULL, 0) < 0) {
        perror("waitpid error");
        exit(0);
    }


    return 0;
}