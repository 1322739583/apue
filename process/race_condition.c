//
// Created by xzh on 2021/7/16.
//

#include "../apue.h"
#include "wait.h"
#include "sys/wait.h"
int main(int argc, char *argv[]) {
   // printf("pid %d ppid %d\n",getpid(),getppid());
    char arr[6]={0} ;
    memset(arr,' ',6);
    arr[0]='a';
    arr[1]='b';
 //   arr[2]='c';
    arr[3]='d';
    arr[4]='n';//
    arr[5]='\0';//
    puts(arr);
   printf("%s\n",arr);
//    for (int i = 0; i <6 ; ++i) {
//        printf("%c",arr[i]);
//    }
    return 0;
}