//
// Created by xzh on 2021/7/16.
//

#include "../apue.h"

int main(int argc, char *argv[]) {
    for (int i = 0; i < argc; ++i) {
        printf("argv[%d] :%s\n",i,argv[i]);
    }
    return 0;
}