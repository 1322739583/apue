//
// Created by xzh on 2021/6/3.
//

#include "../apue.h"
int main(int argc,char* argv[]){
    int i;
    for (int i = 0; i <argc ; ++i) {
        printf("argv[%d]: %s\n",i,argv[i]);
    }
    return 0;
}