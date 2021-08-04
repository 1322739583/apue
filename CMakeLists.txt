cmake_minimum_required(VERSION 3.6.3)
project(linux VERSION 0.1.0)
set(CMAKE_CXX_STANDARD )

include(CTest)
enable_testing()



 add_executable(linux main.cpp type/program2.c type/program1.c apue.h )
#add_executable(atexit process/atexit.c process/atexit_man.c process/echoargs.c)
#add_executable(echoargs process/echoargs.c )

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

# 遍历项目根目录下所有的 .cpp 文件
#file (GLOB_RECURSE files *.c)
#foreach (file ${files})
#    string(REGEX REPLACE ".+/(.+)\\..*" "\\1" exe ${file})
#    add_executable (${exe} ${file})
#    message (\ \ \ \ --\ src/${exe}.c\ will\ be\ compiled\ to\ bin/${exe})
#endforeach ()

 

 
add_executable(system system/system.c)
add_executable(echoargs process/echoargs.c)
add_executable(echoenv process/echoenv.c)

add_executable(malloc memery/malloc.c)
add_executable(setjmp process/setjmp.c)
add_executable(goto process/goto.c)
add_executable(lseek io/lseek.c)
add_executable(lseek2 io/lseek2.c)
add_executable(create_hole io/create_hole.c)
add_executable(dup io/dup.c)
add_executable(copy io/copy.c)
add_executable(fcntl io/fcntl.c)
add_executable(ls file/ls.c)

add_executable(cpu_mem_info unix_standard/cpu_mem_info.c)
add_executable(print_sysconf unix_standard/print_sysconf.c)

add_executable(path_alloc unix_standard/path_alloc.c)
add_executable(resource_limit process/resource_limit.c)
add_executable(fork process/fork.c)
add_executable(iowrite io/write.c)
add_executable(test2 process/test.cpp)
add_executable(wait process/wait.c)
add_executable(race_condition process/race_condition.c)
add_executable(exec process/exec.c)
add_executable(set_uid process/set_uid.c)
add_executable(testinterp process/testinterp.c)
add_executable(echoarg process/echoarg.c)
add_executable(process_time process/process_time.c)
add_executable(signal signal/signal.c)
add_executable(errno error/errno.c)

add_executable(sigcld signal/sigcld.c)
add_executable(signal_test signal/signal_test.c)
add_executable(alarm signal/alarm.c)
add_executable(signal_set signal/signal_set.c)
add_executable(create_thread thread/create_thread.c)
add_executable(thread_exit thread/thread_exit.c)
add_executable(thread_exit_errway thread/thread_exit_errway.c)
add_executable(mainpipe ipc/pipe/mainpipe.c)

add_executable(test_stdargs args/test_stdargs.c)
add_executable(printf io/printf.c)
add_executable(sprintf args/sprintf.c)
add_executable(print_error args/print_error.c)
add_executable(reg reg/reg.c)

add_executable(write ipc/pipe/write.c)

add_executable(create_array memery/create_array.c)
add_executable(getopt args/getopt.c)