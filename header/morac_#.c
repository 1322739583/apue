#include <stdio.h>
 #define printd(X) printf("the value of "#X" is %d\n",X)
//#define printd(DESC,X) printf(DESC"%d\n",X)
int main(){
    int a=10;
    printd(a);
   // printf("the value of"#a"%d",a)
}