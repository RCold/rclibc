#include "limits.h"
#include "locale.h"

static struct lconv lconv = {
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
};

struct lconv *localeconv(void) {
    return &lconv;
}
