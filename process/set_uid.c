//
// Created by xzh on 2021/7/16.
//

#include "../apue.h"

int main(int argc, char *argv[]) {
    uid_t uid=getuid();
    gid_t gid=getgid();
    gid_t euid=geteuid();
    gid_t egid=getegid();
    long hostid=gethostid();
    char * login=getlogin();
    printf("uid %d\n",uid);
    printf("gid %d\n",gid);
    printf("euid %d\n",euid);
    printf("egid %d\n",egid);
    printf("login %s\n",login);
    printf("hostid %ld\n",hostid);


    return 0;
}