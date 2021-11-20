#include "_ctype.h"
#include "_locale.h"
#include "limits.h"
#include "string.h"

static struct _linfo cinfo = {
        "C",
        &_ctype[128],
        &_clmap[128],
        &_cumap[128],
        {
                ".",
                "",
                "",
                "",
                "",
                "",
                "",
                "",
                "",
                "",
                CHAR_MAX,
                CHAR_MAX,
                CHAR_MAX,
                CHAR_MAX,
                CHAR_MAX,
                CHAR_MAX,
                CHAR_MAX,
                CHAR_MAX
        }
};

struct _linfo *_getlocaleinfo(const char *locale) {
    if (strcmp(locale, "C") != 0 && strcmp(locale, "") != 0)
        return NULL;
    return &cinfo;
}
