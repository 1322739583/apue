//
// Created by xzh on 2022/1/18.
//

#include "../apue.h"

/**
 * fwrite有四个参数，但源码取的名字非常的难理解。需要解释一下
 * 第1个参数：const void *类型的指针，其实是要写的内容，可能是任意类型，不一定是字符串。
 * 而且是可以写int类型的，但是几乎是不可以用的，因为会把int当成4个char来写入。
 * 而且没有用慢的地方写入nul这是不能接受的。
 * 第2个参数：size 表示的是一个单位的大小，比如类型可能int,那么size就是4
 * 第3个参数：n表示数量  计算方式是 总长度/单位大小
 * 在官方例子中有个这么的宏定义
 * #define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))
 * 第4个参数：file 这个好理解，需要操作的文件
 * @return
 */
struct Person {
    char *name;
    int age;
};

struct Person p1 = {"shame", 28};


int main() {
    FILE *file = fopen("test2.txt", "r+");
    if (file == NULL) {
        perror("fopen");
        EXIT_FAILURE;
    }


    char buf[] = "abcd";
    char buf2[] = "1234";
    char buf3[] = "456";
    //这种几乎是不可行的
    // int buf[]={666666,67,68,69};

    //因为要传递的类型是void *,所以长度和单位都是不知道的。
    size_t ret = fwrite(buf, sizeof(buf) - 1, 1, file);
    fwrite(buf2, sizeof(buf2) - 1, 1, file);
    fprintf(file,"%s",buf3);
    if (ret != sizeof(buf)) {
        perror("fwrite");
        EXIT_FAILURE;
    }

    return 0;
}