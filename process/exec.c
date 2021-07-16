//
// Created by xzh on 2021/7/16.
//

#include "../apue.h"
#include "wait.h"

#define cmd_cat "/bin/cat"
#define cmd_ls "/bin/ls"
#define argv_cat "/etc/passwd"
#define argv_ls "-la"
#define argv_ls2 "/etc/vimrc"
int main(int argc, char *argv[]) {
    int pid;
    if ((pid=fork())<0){
        perror("fork error");
        exit(1);
    } else if (pid==0){//child

        //第二个/bin/ls也属于arg而不是path.第一个/bin/ls才是path.并不是重复写了两个命令，概念和shell的命令+参数是不一样的。
        //if (execl("/bin/ls","/bin/ls","-la","/etc",NULL)<0){//前面的cmd要写两遍，不然不会执行参数，只是单纯执行命令
        if(execl("/bin/cat","cat","/etc/vimrc",NULL)<0){
            perror("exec error");
            exit(1);
        }

        //在这个判断内，这后面的代码都不会执行
        printf(".............after exec...........");

    } else{//parent
        //父进程等待子进程结束回收，不然子进程结束变成僵尸进程
        wait(NULL);//或者wait(0),因为不需要通过status判断子进程exit的情况.
    }
    printf(".........exec success..............");
    //也可以在这里写wait(NULL),是一样的
    return 0;
}