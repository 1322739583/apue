//
// Created by xzh on 2021/7/18.
//

#include "../apue.h"
#include "signal.h"
static void sig_usr(int);
int main(int argc, char *argv[]) {
    if (signal(SIGUSR1,sig_usr)==SIG_ERR) {
        perror("signal SIGUSR1 error");
        exit(1);
    }



    if (signal(SIGUSR2,sig_usr)==SIG_ERR){
        perror("signal SIGUSR2 error");
        exit(1);
    }
    if (signal(SIGTSTP,sig_usr)==SIG_ERR){
        perror("signal SIGTSTP error");
        exit(1);
    }
    if (signal(SIGINT,sig_usr)==SIG_ERR){
        perror("signal SIGINT error");
        exit(1);
    }

    printf("");

    int i=0;
    //必须有输出语句  不然信号接受到的信息是不会打印的
    while(i<100){
      printf("count %d\n",i++);
       i++;
        sleep(1);
    }
//     for(;;){
//       pause();
//     }

     return 0;
}

static void sig_usr(int signo){
    if (signo==SIGUSR1){
        printf("SIGUSR1 recieved");
    }else if (signo==SIGUSR2){
        printf("SIGUSR2 recieved");
    }else if (signo==SIGTSTP){
        printf("SIGTSTP recieved");
    } else if (signo==SIGINT){
        printf("SIGINT recieved");
    }else{
        perror("recieved error 123");
    }
}