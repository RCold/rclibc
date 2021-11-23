#include "_stdio.h"
#include "_unistd.h"
#include "string.h"
#include "sys/_stat.h"

#ifdef _WIN32

#include "stdlib.h"

#define FILE_SEPARATOR   "\\"
#else
#define FILE_SEPARATOR   "/"
#endif /* _WIN32 */

#ifdef __APPLE__
#define P_tmpdir    "/var/tmp/"
#else
#define P_tmpdir    "/tmp"
#endif /* __APPLE__ */

static int direxists(const char *dir) {
    struct stat buf;
    return stat(dir, &buf) == 0 && S_ISDIR(buf.st_mode);
}

int _tmpdir(char *s, size_t size) {
#ifdef _WIN32
    char *dir = getenv("TMP");
#else
    char *dir = P_tmpdir;
#endif /* _WIN32 */
    size_t dlen = strlen(dir);
    while (dlen > 1 && (dir[dlen - 1] == '/' || dir[dlen - 1] == '\\'))
        dlen--;
    if (dlen + 2 > size || !direxists(dir) || access(dir, W_OK) != 0)
        return -1;
    return sprintf(s, "%.*s" FILE_SEPARATOR, (int) dlen, dir);
}
