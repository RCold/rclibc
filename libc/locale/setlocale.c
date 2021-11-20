#include "_locale.h"
#include "ctype.h"

static char *cur_locale[] = {"C", "C", "C", "C", "C", "C"};

char *setlocale(int category, const char *locale) {
    char *ret;
    struct _linfo *linfo;
    struct lconv *lconv = localeconv();
    if (category < LC_ALL || category > LC_TIME)
        return NULL;
    ret = cur_locale[category];
    if (locale == NULL)
        return ret;
    linfo = _getlocaleinfo(locale);
    if (linfo == NULL)
        return NULL;
    cur_locale[category] = linfo->_name;
    if (category == LC_CTYPE || category == LC_ALL) {
        _ptype = linfo->_ptype;
        _plmap = linfo->_plmap;
        _pumap = linfo->_pumap;
    }
    if (category == LC_MONETARY || category == LC_ALL) {
        lconv->int_curr_symbol = linfo->_lconv.int_curr_symbol;
        lconv->currency_symbol = linfo->_lconv.currency_symbol;
        lconv->mon_decimal_point = linfo->_lconv.mon_decimal_point;
        lconv->mon_thousands_sep = linfo->_lconv.mon_thousands_sep;
        lconv->mon_grouping = linfo->_lconv.mon_grouping;
        lconv->positive_sign = linfo->_lconv.positive_sign;
        lconv->negative_sign = linfo->_lconv.negative_sign;
        lconv->int_frac_digits = linfo->_lconv.int_frac_digits;
        lconv->frac_digits = linfo->_lconv.frac_digits;
        lconv->p_cs_precedes = linfo->_lconv.p_cs_precedes;
        lconv->p_sep_by_space = linfo->_lconv.p_sep_by_space;
        lconv->n_cs_precedes = linfo->_lconv.n_cs_precedes;
        lconv->n_sep_by_space = linfo->_lconv.n_sep_by_space;
        lconv->p_sign_posn = linfo->_lconv.p_sign_posn;
        lconv->n_sign_posn = linfo->_lconv.n_sign_posn;
    }
    if (category == LC_NUMERIC || category == LC_ALL) {
        lconv->decimal_point = linfo->_lconv.decimal_point;
        lconv->thousands_sep = linfo->_lconv.thousands_sep;
        lconv->grouping = linfo->_lconv.grouping;
    }
    return ret;
}
