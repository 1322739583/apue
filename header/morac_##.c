#include <stdio.h>
#define CREATE_VAR(n) x##n
#define printd(n) printf("x" #n " is %d\n",x##n)

int main(){
      
      
     //{
     int CREATE_VAR(1)=10;
      //int a=10;
      // int x1=10;
     printd(1);
      //int a;
     // printf("the ""value""is %d",a);
     //  printd(1);
      
   return 0;
     
}