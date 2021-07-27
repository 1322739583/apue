//
// Created by xzh on 2021/7/21.
//

#include "../apue.h"

int main(int argc, char *argv[]) {
    char buff[15];
    int a=10;
    sprintf(buff,"sprintf %d\n",a);
    printf("buff size %ld\n",strlen(buff));
    printf("buff %s\n",buff);
    vsprintf()
    return 0;
}