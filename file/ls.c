//
// Created by xzh on 2021/7/11.
//

#include "../apue.h"
#include "dirent.h"
#include "limits.h"
int main(int argc, char *argv[]) {
    if (argc<2){

    }
    char buf[1024];
    char * files=getcwd(buf,sizeof(buf));
    printf("%s",buf);

    //DIR *dir;

    //readdir(dir);

    return 0;
}