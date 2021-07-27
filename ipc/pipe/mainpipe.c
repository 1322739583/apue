//
// Created by xzh on 2021/7/21.
//

#include "../unpipc.h"

void client(int readfd, int writefd);

int main(int argc, char *argv[]) {
    int pipe1[2], pipe2[2];
    pid_t pid;

    if (pipe(pipe1) < 0) {
        perror("pipe1 error");
        exit(1);
    }
    if (pipe(pipe2) < 0) {
        perror("pipe2 error");
        exit(1);
    }

    if ((pid = fork()) < 0) {
        perror("fork error");
        exit(1);
    } else if (pid == 0) {
        if (close(pipe1[1])) {
            perror("close error");
            exit(1);
        }
        if (close(pipe2[0])) {
            perror("close error");
            exit(1);
        }
    } else {

    }

    //写到外面会调用两次
    client(0, 0);


    return 0;
}

#define MAXLINE 10


void client(int readfd, int writefd) {

    size_t len;//unsign long int
    ssize_t n;//sign long int
    //  printf("len size_t %ld\n",sizeof(len));//8
    //  printf("n size_t %ld\n",sizeof(n));//8
    char buff[MAXLINE];

    if (fgets(buff, MAXLINE, stdin) == NULL && ferror(stdin)) {
        perror("fgets error");
        exit(1);
    }
    len = strlen(buff);
    if (buff[len - 1] == '\n') {
        len--;
    }
    //write pathname to ipc channel
    if (write(writefd, buff, len) < 0) {
        perror("write error");
        exit(1);
    }

    if ((n = read(readfd, buff, MAXLINE)) < 0) {
        perror("read error");
        exit(1);
    }

    while ((n = read(readfd, buff, MAXLINE)) > 0) {
        writefd
    }

}