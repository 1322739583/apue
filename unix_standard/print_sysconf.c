//
// Created by xzh on 2021/7/14.
//

#include "../apue.h"
#include "limits.h"
#include "errno.h"

static void pr_sysconf(char *,int);
static void pr_pathconf(char *,char *,int);

int main(int argc, char *argv[]) {
    if (argc!=2){
        perror("usage: a.out [dirname]");
        exit(1);
    }
#ifdef ARG_MAX
    printf("ARG_MAX defined to be %ld\n",(long)ARG_MAX+0);
#else
    printf("no symbol for ARG_MAX\n");
#endif
#ifdef _SC_ARG_MAX
    pr_sysconf("ARG_MAX=",_SC_ARG_MAX);
#else
    printf("no sysbol for _SC_ARG_MAX\n");
#endif
/*******similar for all the sysconf symbols*************/

    pr_sysconf("SC_CLK_TCK ",_SC_CLK_TCK);
return 0;
}

static void pr_sysconf(char *mesg,int name){
    long val;
    fputs(mesg,stdout);
    errno=0;
    if ((val=sysconf(name))<0){
        if (errno!=0){
            if (errno==EINVAL){
                fputs("(not supported)\n",stdout);
            } else{
                perror("sysconf error");
                exit(1);
            }
        } else{
            fputs("(no limit)\n",stdout);
        }
    } else{
        printf("%ld\n",val);
    }
}