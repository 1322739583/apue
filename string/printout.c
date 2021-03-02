#include<stdio.h>
#include<stdlib.h>
#define PI 3.141593

int main(){
    int number=15;
    float pies=12.75;
    int cost=7800;
    float  pi=3.14;
    printf("*%f*\n",pi);
    printf("*%.2f*\n",pi);
    printf("*%5.2f*\n",pi);
    printf("*%05.2f*\n",pi);
    //printf("*%#x5.2f*\n",pi);

    printf("%#o\n",number);//017 前面加一个0表示8进制。
    printf("%#x\n",number);//0xf前面加0x,表示16进制
    printf("%#X\n",number);//OXF

    for (int i = 7; i >= 0; i--)
        printf("%d", ((number>> i) & 1));//很经典的运算
        printf("\n");

    //itoa(number,2,2,2,2,3);

    printf("the number is %d,the pies is %f\n",number,pies);//12.750000
    printf("the number is %d,the pies is %.2f\n",number,pies);//12.75
    printf("the number is %d,the pies is %06.2f\n",number,pies);//同样输出12.75但是输出的字符串前面会多出3个看不见的空格
    printf("the number is %d,the pies is %+5f\n",number,pies);
    printf("the number is %d,the pies is %-5f\n",number,pies);
    printf("the number is %d,the pies is %+5.2f\n",number,pies);
    printf("the number is %d,the pies is %-5.2f\n",number,pies);
}