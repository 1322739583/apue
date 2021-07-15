//
// Created by xzh on 2021/7/15.
//

#include "../apue.h"
#include "wait.h"

void pr_exit_status();

int main(int argc, char *argv[]) {
    int status;
    int pid;
    /*normal exit*/
    if ((pid=fork())<0){
        perror("fork error");
        exit(1);
    } else if (pid==0){
        printf("pid is %d,ppid is %d\n",getpid(),getppid());
        exit(3);
    }

    if (wait(&status)!=pid){
        perror("wait error");
    }
     //printf("the status number is %d\n",status);
    pr_exit_status(status);

    /*abnormal exit abort*/
    if ((pid=fork())<0){
        perror("fork error");
        exit(1);
    } else if (pid==0){
       printf("pid is %d,ppid is %d\n",getpid(),getppid());
        abort();
    }

    if (wait(&status)!=pid){
        perror("wait error");
    }
   // printf("the status number is %d\n",status);
    pr_exit_status(status);

    /*abnormal exit divide by zero*/
    if ((pid=fork())<0){
        perror("fork error");
        exit(1);
    } else if (pid==0){
         printf("pid is %d,ppid is %d\n",getpid(),getppid());
        int a=1/0;
    }

    if (wait(&status)!=pid){
        perror("wait error");
    }
    // printf("the status number is %d\n",status);
    pr_exit_status(status);


    /*abnormal exit divide by zero*/
    if ((pid=fork())<0){
        perror("fork error");
        exit(1);
    } else if (pid==0){
         printf("pid is %d,ppid is %d\n",getpid(),getppid());
          pause();//pause并不是stop,只是为了让程序停住好发送sigstop 19信号

    }

//    if (wait(&status)!=pid){
//        perror("wait error");
//    }
    do {
      pid=waitpid(pid,&status,WNOHANG|WUNTRACED);//WNOHANG 是不是阻塞都可以
        if (pid==0) sleep(1);
    } while (pid==0);
    // printf("the status number is %d\n",status);
    pr_exit_status(status);

    exit(0);
}

void pr_exit_status(int status) {
   // printf("invoke");
    if (WIFEXITED(status)){
        printf("normal termination,exit status is %d\n",WEXITSTATUS(status));
    } else if (WIFSIGNALED(status)){
        printf("abnormal termination,exit status is %d%s\n",WTERMSIG(status),
#ifdef WCOREDUMP
               WCOREDUMP(status) ? " (core file generated)" : "");
#else
        "");
#endif
    } else if (WIFSTOPPED(status)){

        printf("stopped,exit status is %d\n",WSTOPSIG(status));
    }
}
