//
// Created by xzh on 2021/7/27.
//
//例子来自 C和指针 内存分配
#include "../apue.h"

int main(int argc, char *argv[]) {
    int n;
    scanf("%d",&n);
    printf("value of n is %d\n",n);
    int arr[n];
    printf("size of arr is %ld\n",sizeof(arr));
    return 0;
}