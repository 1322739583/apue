//
// Created by xzh on 2022/1/18.
//

#include "../apue.h"

/**
 * fopen就两个参数。
 * 第一个参数是文件名，这个非常好理解。
 * 第二个参数是打开模式，这个就复杂的多。
 *
 * r和r+文件不存在报错。
 *
 *
 * @return
 */
int main() {
    FILE *file = fopen("test2.txt", "r+");
    if (file == NULL) {
        perror("fopen");
        EXIT_FAILURE;
    }
    return 0;
}