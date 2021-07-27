/**
 * perm是permission的意思，用于规定权限
 * 用户可以通过msgctl(消息控制函数)、semctl(信号量控制函数)或者shmctl（共享内存控制函数）
 * 来实现对权限和访问模式的修改，前提是必须是进程的创建者或者超级用户，这和通过chmod和chown来修改是一样的。
 **/
struct ipc_perm {
  uid_t uid;//所有者有效user id
  gid_t giu;//所有者有效group id 
  uid_t cuid;//创建者有效user id 
  gid_t cgiu;//创建者有效group id 
  mode_t mode;//访问模式
}


