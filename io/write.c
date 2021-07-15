//
// Created by xzh on 2021/7/15.
//

#include "../apue.h"

int main(int argc, char *argv[]) {
    char buf[]="this is the text\n";
    read(STDIN_FILENO,buf,10);
    write(STDOUT_FILENO,buf,sizeof(buf)-1);
    write(STDOUT_FILENO,buf,sizeof(buf)-1);
    return 0;
}