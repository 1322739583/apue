cmake_minimum_required(VERSION 3.0.0)
project(linux VERSION 0.1.0)

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

add_executable(malloc process/malloc.c)
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
add_executable(write io/write.c)
add_executable(test2 process/test.cpp)
add_executable(wait process/wait.c)