#include<stdio.h>
int main(){
    char ch;
    // while ((ch=getchar())!='#')//#号结束
    // {
    //     putchar(ch);
    // }

    // while ((ch=getchar())!=EOF)//ctrl-z结束
    // {
    //     putchar(ch);
    // }
    

     while ((ch=getchar())!='\n')//回车结束
    {
        putchar(ch);
    }
}