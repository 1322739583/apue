//
// Created by xzh on 2021/7/15.
//

#include "../apue.h"

int main(int argc, char *argv[]) {
    char *buf = "this is the text\n";
    //  read(STDIN_FILENO,buf,10);
    //最后一个参数可以写buf中的n个大小，这个设定非常的奇怪
    write(STDOUT_FILENO, buf, 5);
    int a;
    sizeof(a);

    buf = malloc(sizeof(char) * 10);
    write(STDOUT_FILENO, buf, strlen(buf) - 1);
    malloc()
    return 0;
}