#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>

int globvar = 6;
char buf[] = "a write to stdout\n";

int main() {
    printf("start\n");
    int var;
    pid_t pid;


    if (write(STDOUT_FILENO, buf, sizeof(buf) - 1) != sizeof(buf) - 1) {//-1是因为字符串后面多了\0,后面的判断等于错误往回-1，
        printf("write error");
    }
    printf("before fork\n");

    if ((pid = fork()) < 0) {
        printf("fork error");
    } else if (pid == 0) {
        printf("child\n");
        globvar++;
        var++;
    } else {
        printf("parent\n");
        sleep(2);
    }

    printf("pid=%ld,glob=%d,var=%d\n", (long) getpid(), globvar, var);
    printf("end\n");
    exit(0);

}