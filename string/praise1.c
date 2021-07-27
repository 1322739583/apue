#include<stdio.h>
#include "signal.h"
#define PRAISE "你真是了不起的人"
int main(){
    char name[40];
    printf("What's your name?\n");
    scanf("%s",name);//输入mike j,遇到第一个空格就会终止，只会读取mike
    printf("Hello,%s%s\n",name,PRAISE);
    sigemptyset();
}