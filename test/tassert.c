#include <setjmp.h>
#include <signal.h>
#include <stdio.h>
#include <string.h>

jmp_buf rec;

static void sigabrt(void) {
    longjmp(rec, 1);
}

#define NDEBUG

#include <assert.h>

static void test1(void) {
    assert(1 == 2);
    return;
}

#undef NDEBUG

#include <assert.h>

static void test2(void) {
    assert(1 == 1);
    return;
}

static void test3(void) {
    assert(2 == 3);
    return;
}

int main(void) {
    volatile int failed = 1;
    char buf[160];
    fclose(stderr);
    stderr = tmpfile();
    if (stderr == NULL)
        return failed;
    if (signal(SIGABRT, &sigabrt) == SIG_ERR)
        return failed;
    if (setjmp(rec) == 0)
        test1();
    else
        failed = 1;
    if (setjmp(rec) == 0)
        test2();
    else
        failed = 1;
    if (setjmp(rec) == 0)
        test3();
    else
        failed = 0;
    rewind(stderr);
    while (fgets(buf, 160, stderr) != NULL) {
        if (strstr(buf, "1 == 2") != NULL)
            failed = 1;
        if (strstr(buf, "1 == 1") != NULL)
            failed = 1;
        if (strstr(buf, "2 == 3") == NULL)
            failed = 1;
    }
    fclose(stderr);
    if (failed == 0)
        puts("SUCCESS testing <assert.h>");
    else
        puts("FAILURE testing <assert.h>");
    return failed;
}
