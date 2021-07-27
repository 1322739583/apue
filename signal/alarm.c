//
// Created by xzh on 2021/7/19.
//

#include "../apue.h"
#include "signal.h"

static void sig_alarm(int signo) {
    printf("sig_alarm invoked");
}

unsigned int sleep1(unsigned int seconds) {
    if (signal(SIGALRM, sig_alarm)) {
        return seconds;
    }
    alarm(seconds);
    pause();
    return alarm(0);
}

int main(int argc, char *argv[]) {
    sleep1(3);
    return 0;
}
