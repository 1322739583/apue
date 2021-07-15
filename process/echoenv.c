//
// Created by xzh on 2021/6/3.
//

#include "../apue.h"
int main(int argc,char* argv[],char *envp[]){
    int i;

    for (int i = 0; ; ++i) {
        if(envp[i]) {
            printf("envp[%d]: %s\n", i, envp[i]);
        } else{
            break;
        }
    }
    printf("...........\n");
    printf("JAVA_HOME=%s\n",getenv("JAVA_HOME"));
    printf("HOME=%s\n",getenv("HOME"));
    printf("USER=%s\n",getenv("USER"));
    printf("DOCUMENT=%s\n",getenv("DOCUMENT"));
    printf("DOCUMENTS=%s\n",getenv("DOCUMENTS"));
    return 0;
}