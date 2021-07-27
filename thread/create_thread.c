//
// Created by xzh on 2021/7/19.
//

#include "../apue.h"
#include "pthread.h"

pthread_t ntid;

void printids(const char *s){
    pid_t pid;
    pthread_t tid;

    pid=getpid();
    tid=pthread_self();
    printf("%s pid %d tid %lu (Ox%lx) \n",s,pid,tid,tid);
}

void *thr_fn(void *arg){
    printids("new thread:");
    return ((void *)0);
}


int main(int argc, char *argv[]) {
    pthread_t tid=pthread_self();
    printf("tid=%ld\n",tid);

    int err;
    err=pthread_create(&ntid,NULL,thr_fn,NULL);
    printf("ntid= %lu\n",ntid);//ntid的值就是新线程的tid
    if (err!=0){
        printf("can't create thread err code is %d\n",err);
        exit(1);
    }
    printids("main thread");
    sleep(1);
    return 0;
}