cmake_minimum_required(VERSION 3.1)
project(rclibc C)
set(CMAKE_C_STANDARD 90)
if (MSVC)
    add_compile_options(/X)
else ()
    add_compile_options(-fno-builtin -nostdinc)
endif ()
if (CMAKE_BUILD_TYPE STREQUAL Debug)
    if (MSVC)
        add_compile_options(/Wall)
    else ()
        add_compile_options(-Wall -Wextra -pedantic)
    endif ()
endif ()

include_directories(BEFORE SYSTEM include)

list(APPEND SRCS
        libc/assert/_wassert.c
        libc/ctype/_plmap.c
        libc/ctype/_ptype.c
        libc/ctype/_pumap.c
        libc/ctype/isalnum.c
        libc/ctype/isalpha.c
        libc/ctype/iscntrl.c
        libc/ctype/isdigit.c
        libc/ctype/isgraph.c
        libc/ctype/islower.c
        libc/ctype/isprint.c
        libc/ctype/ispunct.c
        libc/ctype/isspace.c
        libc/ctype/isupper.c
        libc/ctype/isxdigit.c
        libc/ctype/tolower.c
        libc/ctype/toupper.c
        libc/errno/errno.c
        libc/locale/_getlocaleinfo.c
        libc/locale/localeconv.c
        libc/locale/setlocale.c
        libc/stdio/_allocbuf.c
        libc/stdio/_allocfile.c
        libc/stdio/_fclose.c
        libc/stdio/_fflush.c
        libc/stdio/_finit.c
        libc/stdio/_fopen.c
        libc/stdio/_freebuf.c
        libc/stdio/_freefile.c
        libc/stdio/_piob.c
        libc/stdio/_stderr.c
        libc/stdio/_stdin.c
        libc/stdio/_stdout.c
        libc/stdio/_tmpnam.c
        libc/stdio/clearerr.c
        libc/stdio/fclose.c
        libc/stdio/feof.c
        libc/stdio/ferror.c
        libc/stdio/fflush.c
        libc/stdio/fgetc.c
        libc/stdio/fgets.c
        libc/stdio/fopen.c
        libc/stdio/fprintf.c
        libc/stdio/fputc.c
        libc/stdio/fputs.c
        libc/stdio/fread.c
        libc/stdio/freopen.c
        libc/stdio/fwrite.c
        libc/stdio/getc.c
        libc/stdio/getchar.c
        libc/stdio/gets.c
        libc/stdio/perror.c
        libc/stdio/printf.c
        libc/stdio/putc.c
        libc/stdio/putchar.c
        libc/stdio/puts.c
        libc/stdio/remove.c
        libc/stdio/setbuf.c
        libc/stdio/setvbuf.c
        libc/stdio/sprintf.c
        libc/stdio/tmpfile.c
        libc/stdio/tmpnam.c
        libc/stdio/ungetc.c
        libc/stdio/vfprintf.c
        libc/stdio/vprintf.c
        libc/stdio/vsprintf.c
        libc/stdlib/_rand.c
        libc/stdlib/_rseed.c
        libc/stdlib/_ultoa.c
        libc/stdlib/abort.c
        libc/stdlib/abs.c
        libc/stdlib/atof.c
        libc/stdlib/atoi.c
        libc/stdlib/atol.c
        libc/stdlib/div.c
        libc/stdlib/labs.c
        libc/stdlib/ldiv.c
        libc/stdlib/rand.c
        libc/stdlib/srand.c
        libc/string/memchr.c
        libc/string/memcmp.c
        libc/string/memcpy.c
        libc/string/memmove.c
        libc/string/memset.c
        libc/string/strcat.c
        libc/string/strchr.c
        libc/string/strcmp.c
        libc/string/strcpy.c
        libc/string/strcspn.c
        libc/string/strerror.c
        libc/string/strlen.c
        libc/string/strncat.c
        libc/string/strncmp.c
        libc/string/strncpy.c
        libc/string/strpbrk.c
        libc/string/strrchr.c
        libc/string/strspn.c
        libc/string/strstr.c
        libc/string/strtok.c
        libc/time/asctime.c
        libc/time/clock.c
        libc/time/ctime.c
        libc/time/time.c)
if (CMAKE_SYSTEM_NAME STREQUAL Windows)
    list(APPEND SRCS
            libc/sysdeps/win32/getpid.c
            libc/sysdeps/win32/rename.c
            libc/sysdeps/win32/unlink.c)
elseif (CMAKE_SYSTEM_NAME STREQUAL Linux OR CMAKE_SYSTEM_NAME STREQUAL Darwin)
    enable_language(ASM)
    list(APPEND SRCS
            libc/sysdeps/unix/_exit.S
            libc/sysdeps/unix/_tmpdir.c
            libc/sysdeps/unix/access.S
            libc/sysdeps/unix/close.S
            libc/sysdeps/unix/getpid.S
            libc/sysdeps/unix/gettimeofday.S
            libc/sysdeps/unix/open.S
            libc/sysdeps/unix/read.S
            libc/sysdeps/unix/rename.S
            libc/sysdeps/unix/rmdir.S
            libc/sysdeps/unix/stat.S
            libc/sysdeps/unix/unlink.S
            libc/sysdeps/unix/write.S)
else ()
    message(FATAL_ERROR "${CMAKE_SYSTEM_NAME} system is not supported.")
endif ()
add_library(c STATIC ${SRCS})

#add_executable(tassert test/tassert.c)
#target_link_libraries(tassert c)
#
#add_executable(tctype test/tctype.c)
#target_link_libraries(tctype c)
#
#add_executable(terrno test/terrno.c)
#target_link_libraries(terrno c)
#
#add_executable(tfloat test/tfloat.c)
#target_link_libraries(tfloat c m)
#
#add_executable(tlimits test/tlimits.c)
#target_link_libraries(tlimits c)
#
#add_executable(tstdarg test/tstdarg.c)
#target_link_libraries(tstdarg c)
#
#add_executable(tstddef test/tstddef.c)
#target_link_libraries(tstddef c)
#
#enable_testing()
#add_test(NAME tassert COMMAND tassert)
#add_test(NAME tctype COMMAND tctype)
#add_test(NAME terrno COMMAND terrno)
#add_test(NAME tfloat COMMAND tfloat)
#add_test(NAME tlimits COMMAND tlimits)
#add_test(NAME tstdarg COMMAND tstdarg)
#add_test(NAME tstddef COMMAND tstddef)
