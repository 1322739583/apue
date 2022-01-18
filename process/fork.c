#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include <sys/prctl.h>


int globvar = 6;
char buf[] = "a write to stdout\n";

int main() {
    printf("start\n");
    int var;
    pid_t pid;
    //必须比实际的多一个
  //  char * const exec_argv[3]={"ls","-la"};
     char * const exec_argv[4]={"ls","fork.c" ,"-la"};
   // char * const exec_argv[6]={"ls","fork.c" ,"-la",">","/tmp/ls.txt"};

    

 
 

    if (write(STDOUT_FILENO, buf, sizeof(buf) - 1) != sizeof(buf) - 1) {//-1是因为字符串后面多了\0,后面的判断等于错误往回-1，
        printf("write error");
    }
    printf("before fork\n");
         //
        printf("pid is %d\n",getpid());


    if ((pid = fork( )) < 0) {
       
        printf("fork error");
    } else if (pid == 0) {
        prctl(PR_SET_NAME,"fork_process",NULL,NULL,NULL);
         printf("pid=%ld,glob=%d,var=%d  in child \n", pid, getpid(), var);
        execv("/bin/ls",exec_argv);
        printf("pid=%ld,glob=%d,var=%d  in child \n", pid, globvar, var);
        globvar++;
        var++;
        sleep(1000);
    } else {
         //这个pid并不是父进程的pid，而是子进程的pid
         printf("pid=%ld,glob=%d,var=%d  in parent \n", pid, getpid(), var);
        sleep(1000);
    }

  printf("pid=%ld,glob=%d,var=%d\n", (long) getpid(), globvar, var);
    printf("end\n");
    exit(0);

}