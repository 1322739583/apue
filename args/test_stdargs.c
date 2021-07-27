//
// Created by xzh on 2021/7/21.
//

#include "../apue.h"
#include "stdarg.h"

double sum(int lim, ...);

int main(void) {
    double s, t;
    s = sum(3, 1.1, 2.5, 13.3);
    // t = sum(6, 1.1, 2.1, 13.1, 4.1, 5.1, 6.1);
    printf("return value for "
           "sum(3, 1.1, 2.5, 13.3): %g\n", s);
//    printf("return value for "
//           "sum(6, 1.1, 2.1, 13.1, 4.1, 5.1, 6.1): %g\n", t);

    return 0;
}

double sum(int lim, ...) {
    va_list ap; // 声明一个对象储存参数
    double tot = 0;
    int i;
    va_start(ap, lim); // 把ap初始化为参数列表
    char buff[50];//如果数组的值太小会报*** stack smashing detected ***: terminated
    vsprintf(buff, "result:------%g %g %g\n", ap);
    //   printf("buff %s\n",buff);
    for (i = 0; i < lim; i++) {
        //为什么在调用vsprintf后这个值就不对了
        tot += va_arg(ap, double); // 访问参数列表中的每一项
    }
    va_end(ap); // 清理工作
    return tot;
}