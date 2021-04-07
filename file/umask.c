#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#define RWRWRW (S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH)
int main(int argc, char const *argv[])
{
    umask(0);
    if(creat("foo",RWRWRW)<0)
    printf("create error for foo\n");
    umask(S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH);
    if (creat("bar",RWRWRW)<0)
    {
      printf("create error for foo\n");
    }
    
    return 0;
}