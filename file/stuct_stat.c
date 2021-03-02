#include<sys/types.h>
struct stat{
    mode_t st_mode;//文件类型和模式
    ino_t st_ino;//i结点编号
    dev_t st_dev;//设备编号（文件系统）
    dev_t st_rdev;//特殊文件设备编号
    nlink_t st_nlink;//链接数量
    uid_t st_uid;//uid
    gid_t st_gid;//gid
    off_t st_size;//普通文件的二进制大小
    struct timespec st_atime;//最后访问时间
    struct timespec st_mtime;//最后修改时间
    struct timespec st_ctime;//最后状态改变时间
    blksize_t st_blksize;//最好的I/O块大小
    blkcnt_t st_blocks;//已经分配的磁盘块数量
};