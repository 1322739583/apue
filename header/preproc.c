/*预处理案例*/
#include<stdio.h>
#define TWO 2 //宏定义
#define OW "Consistency is the last refuge of the unimagina\
tive" //反斜杠把定义延续到下一行
#define FOUR TWO*TWO
#define PX printf("X is %d.\n",x)
#define FMT "X is %d.\n"

#define HAL 'Z'
#define HAP "Z"

#define LIMIT 20

#define EIGHT 4 * 8
#define EIGHT 4 * 8

#define name ccc
#define name ccc

 #define c c
 #define c c
 #define v 10
 #define v 20

int main(){
    int x=TWO;
    PX;//print:X is 2.
    x=FOUR;
    printf(FMT,x);//print:X is 4
    printf("%s\n",OW);//print: Consistency is the last refuge of the unimaginative
    printf("TWO:OW\n");//TWO:OW

    printf("HAL value is %c\n",HAL);
    printf("HAP value is %c\n",HAP);//这里故意写错，输出为d,如果的%s,则输出为Z.

    const int LIM=50;
    static int data1[LIMIT];
    //static int data2[LIM];//c语言是不允许的，非常的奇怪
    const int LIM2=2*LIMIT;
    const int LIM3=2*LIM;
    printf("LIM2=%d\n",LIM2);
    printf("LIM3=%d\n",LIM3);

   // printf("EIGHT =%s",EIGHT);
  // printf("name is %s",name);
  int c=v;
  printf("c is %d",c);
    return 0;
}
