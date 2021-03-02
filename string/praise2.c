#include<stdio.h>
#include<string.h>
#define PRAISE "你真是了不起的人"
int main(){
    char name[40];
    printf("你叫什么名字？\n");
    scanf("%s",name);
    printf("Hello,%s.%s\n",name,PRAISE);
    printf("你的名字有%u个字符占用了%u个字节\n",strlen(name),sizeof name);
    printf("PRAISE字符串占用了%u个字符,占用了%u个字节空间",strlen(PRAISE),sizeof PRAISE);//8个中文字符，每个中文字符占用3个字节，加上\0,共25.
}