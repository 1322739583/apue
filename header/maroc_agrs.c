#include<stdio.h>
#define SQUR(X) X*X
#define SUM(X,Y) X+Y
#define printd(DESC,X) printf(DESC"%d\n",X)
int main(){
    int a=SQUR(2);
    int a2=SQUR(2+5);
    int x=5;
    int a3=SQUR(++x);
    printf("result is %d\n",a);
    printf("result is %d\n",a2);//2+5*2+5
    printf("result is %d\n",a3);//被替换成++x*++x,gcc这里的结果是7*7=49,别的编译器结果可能是6*7=42。
    int sum=SUM(3,6);
    printf("SUM is %d\n",sum);
    printd("the result is ",sum);
    printd("the result is ",SUM(3,5));
}