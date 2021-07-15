//
// Created by xzh on 2021/6/3.
//
#include "../apue.h"

void func(){
    lable2:
    printf("func\n");
}

int main(int argc, char *argv[]) {
    int i;
    lable1:
    if (i<10){
        i++;
        printf("i=%d\n",i);
        goto lable1;
    }




    return 0;
}

