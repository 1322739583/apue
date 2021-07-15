//
// Created by xzh on 2021/6/3.
//

#include "../tlpi.h"
#include "get"
#define MAX_ALLOCS 1000000
int main(int argc, char *argv[]) {

    char *prt[MAX_ALLOCS];
    int freeStep,freeMin,freeMax,blockSize,numAllocs,j;
    printf("\n");
    if (argc<3||strcmp(argv[1],"--help")==0){
        printf("");
    }
    numAllocs=getInt();
    return 0;
}