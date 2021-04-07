#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<string.h>

 void my_exit1(void);
 void my_exit2(void);

int main(int argc, char const *argv[])
{
    if(atexit(my_exit2)!=0)
    perror("can't register my_exit2\n");

    if (atexit(my_exit1)!=0)
    {
        perror("can't register my_exit1");
    }

    if(atexit(my_exit1)!=0){
        perror("can't register my_exit1");
    }
    
    printf("main is done\n");
   // return 0;
   exit(0);
}

 void my_exit1(void){
    printf("first exit handler\n");
}

 void my_exit2(void){
    printf("second exit handler\n");
}