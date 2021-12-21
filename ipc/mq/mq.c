#include <mqueue.h>

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<string.h>

int main(int argc, char **argv)
{
    int c,flags;
    mqd_t mqb;
    flags=O_RDWR|O_CREAT;
    while((c=getopt(argc,argv,"e"))!=-1){
        switch(c){
            case 'e':
             flags|=O_EXCL;
             break;
        }
    }

    if(optind!=argc-1)
    perror("usage: mqcreate [-e] <name> ");
    
    mqb=mq_open(argv[optind],flags,0,NULL);
    mq_close(mqb);
    return 0;
}