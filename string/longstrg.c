#include<stdio.h>
#include<string.h>
#define DENSITY 62.4//人体密度
int main(){
   float weight,volume;//重量，体积
   int size,letters;//字节大小，字符长度
   char name[40];
   printf("你叫什么名字？\n");
   scanf("%s",name);
   printf("%s,你的体重是多少？\n",name);
   scanf("%f",&weight);
   size=sizeof name;//这里的结果是数组整体大小40，而不是有效内容的大小
   letters=strlen(name);
   volume=weight/DENSITY;
   printf("好的，%s,你的体积是%2.2f 立方英尺\n",name,volume);
   printf("你的名字占%d个字符\n",letters);
   printf("你需要%dbytes的空间来存储\n",size);
   printf("名字实际占用%dbytes的空间\n",letters*sizeof(char));
   return 0;
}