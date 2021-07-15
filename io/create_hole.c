//
// Created by xzh on 2021/7/10.
//

#include "../apue.h"

char buf1[]="abcdefghij123456789";
char buf2[]="ABCDEFGHIJ";

#define FILE_MODE 0755

int main(){
    int fd;
    if ((fd=creat("file.hole",FILE_MODE))<0){
        perror("creat error");
        exit(1);
    }

    if (write(fd,buf1,20)!=20){
        perror("buf1 write error");
        exit(1);
    }
    /*offset now=10*/

//    if (lseek(fd,10000,SEEK_SET)==-1){
//        perror("lseek error");
//        exit(1);
//    }
    for (int i = 0; i <26384 ; ++i) {
        if (write(fd,'0',1)!=1){
            perror("buf1 write error");
            exit(1);
        }
    }


    /*offset now=16384*/

    if (write(fd,buf2,10)!=10){
        perror("buf2 write error");
    }
    /*offset now=16384*/

    exit(0);
}