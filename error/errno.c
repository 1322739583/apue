//
// Created by xzh on 2021/7/18.
//

#include "../apue.h"
#include "errno.h"
int main(int argc, char *argv[]) {
    fprintf(stderr,"EACCES:%s\n",strerror(EACCES));
    errno=ENOENT;
    perror(argv[0]);

    return 0;
}