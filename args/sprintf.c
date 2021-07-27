//
// Created by xzh on 2021/7/21.
//

#include <stdio.h>
#include <stdarg.h>

char buffer[80];
int vspfunc(char *format, ...)
{
    va_list aptr;
    int ret;

    va_start(aptr, format);
    ret = vsprintf(buffer, format, aptr);
    va_end(aptr);

    return(ret);
}

int main()
{
    int i = 5;
    float f = 27.0;
    char str[50] = "runoob.com";

    vspfunc("%d %f %s", i, f, str);
    printf("%s\n", buffer);

    return(0);
}