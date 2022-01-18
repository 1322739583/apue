//
// Created by xzh on 2022/1/18.
//

/**
 * 文件操作工具类
 */

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "memory.h"
#include "unistd.h"
#include "error.h"
#include "errno.h"
#include "time.h"
#include<fcntl.h>

/**
 * 如果文件不存在，则新建文件并写入，如果文件已经存在，则直接写入
 * @param context 需要写入的内容
 * @param fileName 文件名
 * @param mode 创建模式，插入，覆盖
 *
 * return 返回fd
 */
int writeToFile(char *context, char *fileName, char* mode) {
    FILE *file = fopen(fileName, mode);
    if (file == NULL) {
        perror("open file error");
        exit(1);
    }

   // fwrite(context,5,,file);

    fprintf(file, "%s", context);
}

struct Person{
    char *name;
    int age;
};

struct Person p1 = {"关羽", 33};
struct Person p2 = {"刘备", 35};
struct Person p3 = {"曹操", 35};
struct Person p4 = {"诸葛亮", 27};
struct Person p5 = {"张飞", 32};
struct Person p6 = {"赵云", 25};
struct Person p7 = {"袁绍", 40};

int main() {

    writeToFile("test", "haha.txt", "w");
    writeToFile(p1.name, "haha.txt", "w");
    writeToFile("test", "haha.txt", "w");
}
