#include <assert.h>
#include <float.h>
#include <math.h>
#include <stdio.h>

int main(void) {
    double radlog = log10(FLT_RADIX);
    int digs = (DBL_MANT_DIG - 1) * radlog;
    assert(DBL_DIG >= 10 && DBL_DIG >= FLT_DIG);
    assert(DBL_DIG >= digs && DBL_DIG <= digs + 1);
    assert(DBL_EPSILON <= 1e-9);
    assert(DBL_MAX >= 1e+37);
    assert(DBL_MAX_10_EXP >= 37);
    assert(DBL_MIN <= 1e-37);
    assert(DBL_MIN_10_EXP <= -37);
    digs = (FLT_MANT_DIG - 1) * radlog;
    assert(FLT_DIG >= 6);
    assert(FLT_DIG >= digs && FLT_DIG <= digs + 1);
    assert(FLT_EPSILON <= 1e-5F);
    assert(FLT_MAX >= 1e+37F);
    assert(FLT_MAX_10_EXP >= 37);
    assert(FLT_MIN <= 1e-37F);
    assert(FLT_MIN_10_EXP <= -37);
    assert(FLT_ROUNDS >= -1 && FLT_ROUNDS <= 3);
    digs = (LDBL_MANT_DIG - 1) * radlog;
    assert(LDBL_DIG >= 10 && LDBL_DIG >= DBL_DIG);
    assert(LDBL_DIG >= digs && LDBL_DIG <= digs + 1);
    assert(LDBL_EPSILON <= 1e-9);
    assert(LDBL_MAX >= 1e+37);
    assert(LDBL_MAX_10_EXP >= 37);
    assert(LDBL_MIN <= 1e-37);
    assert(LDBL_MIN_10_EXP <= -37);
#if FLT_RADIX == 2
    assert(DBL_MAX > ldexp(1.0, DBL_MAX_EXP - 1));
    assert(DBL_MIN == ldexp(1.0, DBL_MIN_EXP - 1));
    assert(FLT_MAX > ldexp(1.0, FLT_MAX_EXP - 1));
    assert(FLT_MIN == ldexp(1.0, FLT_MIN_EXP - 1));
    assert(LDBL_MAX_EXP > DBL_MAX_EXP
           || LDBL_MAX > ldexp(1.0, LDBL_MAX_EXP - 1));
    assert(LDBL_MIN_EXP < DBL_MIN_EXP
           || LDBL_MIN == ldexp(1.0, LDBL_MIN_EXP - 1));
#endif /* FLT_RADIX == 2 */
    puts("SUCCESS testing <float.h>");
    return 0;
}
