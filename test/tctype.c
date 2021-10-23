#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <stdio.h>

static void test(int c) {
    if (c >= 'A' && c <= 'Z') {
        assert(isupper(c));
        assert((isupper)(c));
        assert(tolower(c) == c - 'A' + 'a');
        assert((tolower)(c) == c - 'A' + 'a');
    } else {
        assert(!isupper(c));
        assert(!(isupper)(c));
        assert(tolower(c) == c);
        assert((tolower)(c) == c);
    }
    if (c >= 'a' && c <= 'z') {
        assert(islower(c));
        assert((islower)(c));
        assert(toupper(c) == c - 'a' + 'A');
        assert((toupper)(c) == c - 'a' + 'A');
    } else {
        assert(!islower(c));
        assert(!(islower)(c));
        assert(toupper(c) == c);
        assert((toupper)(c) == c);
    }
    if (isupper(c) || islower(c)) {
        assert(isalpha(c));
        assert((isalpha)(c));
    } else {
        assert(!isalpha(c));
        assert(!(isalpha)(c));
    }
    if (c >= '0' && c <= '9') {
        assert(isdigit(c));
        assert((isdigit)(c));
    } else {
        assert(!isdigit(c));
        assert(!(isdigit)(c));
    }
    if (isdigit(c) || (c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F')) {
        assert(isxdigit(c));
        assert((isxdigit)(c));
    } else {
        assert(!isxdigit(c));
        assert(!(isxdigit)(c));
    }
    if (isalpha(c) || isdigit(c)) {
        assert(isalnum(c));
        assert((isalnum)(c));
    } else {
        assert(!isalnum(c));
        assert(!(isalnum)(c));
    }
    if (c >= '!' && c <= '~') {
        assert(isgraph(c));
        assert((isgraph)(c));
    } else {
        assert(!isgraph(c));
        assert(!(isgraph)(c));
    }
    if (isgraph(c) && !isalnum(c)) {
        assert(ispunct(c));
        assert((ispunct)(c));
    } else {
        assert(!ispunct(c));
        assert(!(ispunct)(c));
    }
    if (isgraph(c) || c == ' ') {
        assert(isprint(c));
        assert((isprint)(c));
    } else {
        assert(!isprint(c));
        assert(!(isprint)(c));
    }
    if (c >= '\x00' && c <= '\x7f' && !isprint(c)) {
        assert(iscntrl(c));
        assert((iscntrl)(c));
    } else {
        assert(!iscntrl(c));
        assert(!(iscntrl)(c));
    }
    if ((c >= '\t' && c <= '\r') || c == ' ') {
        assert(isspace(c));
        assert((isspace)(c));
    } else {
        assert(!isspace(c));
        assert(!(isspace)(c));
    }
}

int main(void) {
    int c;
    test(EOF);
    for (c = SCHAR_MIN; c <= UCHAR_MAX; c++) {
        test(c);
    }
    puts("SUCCESS testing <ctype.h>");
    return 0;
}
