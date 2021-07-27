//
// Created by xzh on 2021/7/19.
//

#include "../apue.h"
#include "signal.h"
#include "errno.h"
int sigaddset(sigset_t *set,int signo){
    if (signo<=0||signo>=NSIG){
        errno=EINVAL;//Invalid argument
        sigdelset()
        printf("");
        exit()
    }
}


int main(int argc, char *argv[]) {

    return 0;
}