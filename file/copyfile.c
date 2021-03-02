#include<stdio.h>
#include<stdlib.h>
int main(int argc,char *argv[]){
    FILE *file1,*file2;
    //一般情况下写模式是不会返回空，因为如果文件不存在会创建文件
    //但是如果要写的文件存在但是没有权限，也会返回空。所以还是有必要判断返回结果是不是为空。
    file1=fopen(argv[1],"w");
    file2=fopen(argv[2],"w");

   // char * data[20]="this is data";
    puts("data");

    if (argc<3)
    {
        printf("错误：请输入正确格式 Usage copyFile [curFile] [targetFile]\n");
        exit(EXIT_FAILURE);
    }

   
    

    if (file1==NULL)
    {
        //写文件为空只有可能是没有权限，可能是文件存在但没有访问权限，也可能是文件不存在，没有创建文件的权限。
        //一般也不用做太细致的判断
        //stderr没有缓冲区，直接输出，stdout是有行缓冲区的，这是细微的差别
        fprintf(stderr,"没有权限对文件 %s.进行操作\n",argv[1]);
        exit(EXIT_FAILURE);
    }

    if (file2==NULL)
    {
        fprintf(stderr,"没有权限对文件 %s.进行操作\n",argv[2]);
        exit(EXIT_FAILURE);
    }

    fprintf(file1,"write date to file1");
    //fprintf(file2,getc(file1));
  
    // char * data[20];
    // fscanf(file1,"scan date to file1 %s",data);

     fclose(file1);
     fclose(file2);
    

}