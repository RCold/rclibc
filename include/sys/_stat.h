#ifndef _SYS__STAT_H
#define _SYS__STAT_H

#include <_time.h>

#define S_IFMT      0170000
#define S_IFDIR     0040000

#define S_ISDIR(m)  (((m) & S_IFMT) == S_IFDIR)

#include <sys/cdefs.h>

__BEGIN_DECLS

#if defined(__linux__) && defined(__x86_64__)

typedef unsigned long int dev_t;
typedef unsigned long int ino_t;
typedef unsigned long int nlink_t;
typedef unsigned int mode_t;
typedef unsigned int uid_t;
typedef unsigned int gid_t;
typedef long int off_t;
typedef long int blksize_t;
typedef long int blkcnt_t;

struct stat {
    dev_t st_dev;
    ino_t st_ino;
    nlink_t st_nlink;
    mode_t st_mode;
    uid_t st_uid;
    gid_t st_gid;
    int __pad0;
    dev_t st_rdev;
    off_t st_size;
    blksize_t st_blksize;
    blkcnt_t st_blocks;
    struct timespec st_atim;
    struct timespec st_mtim;
    struct timespec st_ctim;
    long int __unused[3];
#define st_atime st_atim.tv_sec
#define st_mtime st_mtim.tv_sec
#define st_ctime st_ctim.tv_sec
};

#elif defined(__APPLE__) && defined(__x86_64__)

typedef __int32 dev_t;
typedef unsigned __int16 mode_t;
typedef unsigned __int16 nlink_t;
__extension__ typedef unsigned __int64 ino_t;
typedef unsigned __int32 uid_t;
typedef unsigned __int32 gid_t;
__extension__ typedef __int64 off_t;
__extension__ typedef __int64 blkcnt_t;
typedef __int32 blksize_t;

__extension__ struct stat {
    dev_t st_dev;
    mode_t st_mode;
    nlink_t st_nlink;
    ino_t st_ino;
    uid_t st_uid;
    gid_t st_gid;
    dev_t st_rdev;
    struct timespec st_atimespec;
    struct timespec st_mtimespec;
    struct timespec st_ctimespec;
    struct timespec st_birthtimespec;
    off_t st_size;
    blkcnt_t st_blocks;
    blksize_t st_blksize;
    unsigned __int32 st_flags;
    unsigned __int32 st_gen;
    __int32 st_lspare;
    __int64 st_qspare[2];
#define st_atime st_atimespec.tv_sec
#define st_mtime st_mtimespec.tv_sec
#define st_ctime st_ctimespec.tv_sec
#define st_birthtime st_birthtimespec.tv_sec
};

#elif defined(_WIN32)

typedef unsigned __int16 mode_t;

struct stat {
    mode_t st_mode;
};

#else
#error Undefined platform for stat
#endif /* defined(__linux__) && defined(__x86_64__) */

int stat(const char *, struct stat *);

__END_DECLS

#endif /* _SYS__STAT_H */
