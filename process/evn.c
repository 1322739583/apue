#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
extern char **environ;
int main(){
  char **env = environ;
 
  while(*env){
    printf("%s\n",*env);
    //printf("%c\n",**env);
    env++;
  }
  // exit(1);
  return 3;
}