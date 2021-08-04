//
// Created by xzh on 2021/7/21.
//

/* include writen */
#include "../unpipc.h"

ssize_t /* Write "n" bytes to a descriptor. */
writen(int fd, const void *vptr, size_t n) {
  size_t nleft;
  ssize_t nwritten;
  const char *ptr;

  ptr = vptr;
  nleft = n;//剩余的，这个非常的合理，指定的只是buf的一部分
  while (nleft > 0) {

    if ((nwritten = write(fd, ptr, nleft)) <= 0) {
      if (errno == EINTR)
        //设为0，nleft和ptr-=和+=后都没有变化，会重新进入write。
        nwritten = 0; /* and call write() again */
      else
        return (-1); /* error */
    }

    nleft -= nwritten;
    ptr += nwritten;
  }
  return (n);
}
/* end writen */

void Writen(int fd, void *ptr, size_t nbytes) {
  if (writen(fd, ptr, nbytes) != nbytes)
    err_sys("writen error");
}
