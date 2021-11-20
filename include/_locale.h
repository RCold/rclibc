#ifndef __LOCALE_H
#define __LOCALE_H

#include <locale.h>
#include <sys/cdefs.h>

__BEGIN_DECLS

struct _linfo {
    char *_name;
    const unsigned short int *_ptype;
    const short int *_plmap;
    const short int *_pumap;
    const struct lconv _lconv;
};

struct _linfo *_getlocaleinfo(const char *);

__END_DECLS

#endif /* __LOCALE_H */
