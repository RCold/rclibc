#ifndef _LOCALE_H
#define _LOCALE_H

#ifndef NULL
#ifdef __cplusplus
#define NULL 0
#else /* __cplusplus */
#define NULL ((void *) 0)
#endif /* __cplusplus */
#endif /* NULL */

#define LC_ALL          0
#define LC_COLLATE      1
#define LC_CTYPE        2
#define LC_MONETARY     3
#define LC_NUMERIC      4
#define LC_TIME         5

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#ifndef _LOCALE_DEFINED
#define _LOCALE_DEFINED
struct lconv {
	char *decimal_point;
	char *thousands_sep;
	char *grouping;
	char *int_curr_symbol;
	char *currency_symbol;
	char *mon_decimal_point;
	char *mon_thousands_sep;
	char *mon_grouping;
	char *positive_sign;
	char *negative_sign;
	char int_frac_digits;
	char frac_digits;
	char p_cs_precedes;
	char p_sep_by_space;
	char n_cs_precedes;
	char n_sep_by_space;
	char p_sign_posn;
	char n_sign_posn;
};
#endif /* _LOCALE_DEFINED */

struct lconv *localeconv(void);
char *setlocale(int, const char *);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _LOCALE_H */
