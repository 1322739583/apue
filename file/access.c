#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

int main(int argc, char const *argv[])
{
    //char path[]="/etc/passwd";
    if(argc<2){
        perror("usage access [pathname]\n");
    }
    if(access(argv[1],R_OK)){
        printf("read ok\n");
    }else{
        printf("read faild %s permission deny\n ",argv[1]);
    }
    if(access(argv[1],W_OK)){
        printf("write ok\n");
    }else{
        printf("write faild %s permission deny\n",argv[1]);
    }
    if(access(argv[1],X_OK)){
        printf("exec ok\n");
    }else{
        printf("exec faild %s permission deny\n",argv[1]);
    }
    return 0;
}