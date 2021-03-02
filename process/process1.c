#include<unistd.h>
#include<stdio.h>
int main(){
pid_t pid=getpid();
printf("pid=%d\n",pid);
pid_t ppid=getppid();
printf("ppid=%d\n",ppid);
uid_t uid=getuid();
printf("uid=%d\n",uid);
uid_t euid=geteuid();
printf("euid=%d\n",euid);
gid_t gid=getgid();
printf("gid=%d\n",gid);
gid_t egid=getegid();
printf("egid=%d\n",egid);
pid_t fpid=fork();
printf("fpid=%d\n",fpid);
}
