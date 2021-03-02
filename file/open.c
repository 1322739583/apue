#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
// #include <sys/stat.h>
// #include <sys/types.h>
int main(){
  int fd,size;
  char words[]="Linux Programmer!\n",buffer[80];
  //char path[]="wordy";
  fd= open("/tmp/temp",O_RDWR);//不存在不会创建，返回-1
  write(fd,words,sizeof(words));
  close(fd);
  printf("%d",fd);
}