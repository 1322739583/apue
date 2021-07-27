//
// Created by xzh on 2021/7/19.
//

#include "../apue.h"
#include "pthread.h"
#include "math.h"
pthread_t ntid;
void * thr_fn1(void *arg){
    printf("thread 1 returning\n");
    for (int i = 0; i <10 ; ++i) {
        int time=(int)(drand48()*100000);
        usleep(time);//微秒
        printf("fn1 i=%d\n",i);
    }
    return ((void *)1);
}

void * thr_fn2(void *arg){
    printf("thread 2 returning\n");
    for (int i = 0; i <10 ; ++i) {
        int time=(int)(drand48()*100000);
        usleep(time);//微秒
        printf("fn2 i=%d\n",i);
    }
    pthread_exit((void *)2);
}

int main(int argc, char *argv[]) {
    int err;
    pthread_t tid1,tid2;
    void *tret;

    err=pthread_create(&tid1,NULL,thr_fn1,NULL);
    if (err!=0){
        printf("can't create thread1 err code is %d\n",err);
        exit(1);
    }
    err=pthread_create(&tid2,NULL,thr_fn2,NULL);
    if (err!=0){
        printf("can't create thread2 err code is %d\n",err);
        exit(1);
    }

    err=pthread_join(tid1,&tret);
    if (err!=0){
        printf("can't join thread1 err code is %d\n",err);
        exit(1);
    }
    printf("thread1 exit code %ld\n",(long)tret);

    err=pthread_join(tid2,&tret);
    if (err!=0){
        printf("can't join thread2 err code is %d\n",err);
        exit(1);
    }
    printf("thread2 exit code %ld\n",(long)tret);
    return 0;
}