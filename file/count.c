#include<stdio.h>
#include<stdlib.h>
#include <string.h>
/**
 * 
 * */
int main(int argc,char *argv[]){
    int ch;
    FILE *fp;
    unsigned long count=0;

   // printf("argc:%d argv[0]:%c",argc,argv[0]);

    if (argc!=2)
    {
      printf("Usage:%s filename!",argv[0]);
      exit(EXIT_FAILURE);
    }

    if ((fp=fopen(argv[1],"r"))==NULL)
    {
        printf("Can't open %s\n",argv[1]);
        exit(EXIT_FAILURE);
    }

    while ((ch=getc(fp))!=EOF)
    {
        putc(ch,stdout);
        count++;
    }

    fclose(fp);
    printf("File %s has %lu characters\n",argv[1],count);
    return 0;

}