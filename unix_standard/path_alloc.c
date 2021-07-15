//
// Created by xzh on 2021/7/14.
//

#include "../apue.h"
#include "limits.h"
#include "errno.h"

#ifdef PATH_MAX  //PATH_MAX在limits.h是有定义的值为4096
static long pathmax = PATH_MAX;
#else
static long pathmax=0;
#endif

static long posix_version = 0;
static long xsi_version = 0;

#define PATH_MAX_GUESS 1024

char *path_alloc(size_t *sizep) {
    char *ptr;
    size_t size;

    if (posix_version == 0) {
        posix_version = sysconf(_SC_VERSION);
        printf("posix_version=%ld\n",posix_version);
    }

    if (xsi_version == 0) {
        xsi_version = sysconf(_SC_XOPEN_VERSION);
        printf("xsi_version=%ld\n",xsi_version);
    }

    if (pathmax == 0) {
        errno = 0;
        //pathmax = pathconf("/", _PC_PATH_MAX);
        if ((pathmax = pathconf("/", _PC_PATH_MAX)) < 0) {
            printf("pathmax=%ld",pathmax);
            if (errno == 0) {
                pathmax = PATH_MAX_GUESS;
            } else {
                perror("pathconf error for _PC_PATH_MAX");
                exit(1);
            }
        } else {
            pathmax++;
        }

    }

    if ((posix_version < 200112L) && (xsi_version < 4)) {
        size = pathmax + 1;
    } else {
        size = pathmax;
    }

    if ((ptr = malloc(size)) == NULL) {
        perror("malloc error for pathname");
        exit(1);
    }

    if (sizep != NULL) {
        *sizep = size;
    }
    return (ptr);

}


int main(int argc, char *argv[]) {
    size_t path;
    //char *str = path_alloc(&path);
    printf("%s", *path_alloc(&path));

    char *str="abc";
    printf("%s",str);
    return 0;
}