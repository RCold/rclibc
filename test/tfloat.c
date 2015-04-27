#include <assert.h>
#include <float.h>
#include <math.h>
#include <stdio.h>

int main(void) {
	double radlog;
	int digs;
	static int radix = FLT_RADIX;
	printf("FLT_RADIX = %i\n\n", FLT_RADIX);
	printf("DBL_DIG =         %-13i    DBL_MANT_DIG = %i\n", DBL_DIG,
	DBL_MANT_DIG);
	printf("DBL_MAX_10_EXP =  %-13i    DBL_MAX_EXP =  %i\n", DBL_MAX_10_EXP,
	DBL_MAX_EXP);
	printf("DBL_MIN_10_EXP =  %-13i    DBL_MIN_EXP =  %i\n", DBL_MIN_10_EXP,
	DBL_MIN_EXP);
	printf("DBL_EPSILON =     %le\n", DBL_EPSILON);
	printf("DBL_MAX =         %le\n", DBL_MAX);
	printf("DBL_MIN =         %le\n\n", DBL_MIN);
	printf("FLT_DIG =         %-13i    FLT_MANT_DIG = %i\n", FLT_DIG,
	FLT_MANT_DIG);
	printf("FLT_MAX_10_EXP =  %-13i    FLT_MAX_EXP =  %i\n", FLT_MAX_10_EXP,
	FLT_MAX_EXP);
	printf("FLT_MIN_10_EXP =  %-13i    FLT_MIN_EXP =  %i\n", FLT_MIN_10_EXP,
	FLT_MIN_EXP);
	printf("FLT_EPSILON =     %e\n", FLT_EPSILON);
	printf("FLT_MAX =         %e\n", FLT_MAX);
	printf("FLT_MIN =         %e\n\n", FLT_MIN);
	printf("LDBL_DIG =        %-13i    DBL_MANT_DIG = %i\n", LDBL_DIG,
	LDBL_MANT_DIG);
	printf("LDBL_MAX_10_EXP = %-13i    LDBL_MAX_EXP = %i\n", LDBL_MAX_10_EXP,
	LDBL_MAX_EXP);
	printf("LDBL_MIN_10_EXP = %-13i    LDBL_MIN_EXP = %i\n", LDBL_MIN_10_EXP,
	LDBL_MIN_EXP);
	printf("LDBL_EPSILON =    %Le\n", LDBL_EPSILON);
	printf("LDBL_MAX =        %Le\n", LDBL_MAX);
	printf("LDBL_MIN =        %Le\n\n", LDBL_MIN);
	radlog = log10(radix);
	digs = (DBL_MANT_DIG - 1) * radlog;
	assert(DBL_DIG >= 10 && DBL_DIG >= FLT_DIG);
	assert(DBL_DIG >= digs && DBL_DIG <= digs + 1);
	assert(DBL_EPSILON <= 1e-9);
	assert(DBL_MAX >= 1e37);
	assert(DBL_MAX_10_EXP >= 37);
	assert(DBL_MIN <= 1e-37);
	assert(DBL_MIN_10_EXP <= -37);
	digs = (FLT_MANT_DIG - 1) * radlog;
	assert(FLT_DIG >= 6);
	assert(FLT_DIG >= digs && FLT_DIG <= digs + 1);
	assert(FLT_EPSILON <= 1e-5F);
	assert(FLT_MAX >= 1e37F);
	assert(FLT_MAX_10_EXP >= 37);
	assert(FLT_MIN <= 1e-37F);
	assert(FLT_MIN_10_EXP <= -37);
	assert(FLT_ROUNDS >= -1 && FLT_ROUNDS <= 3);
	digs = (LDBL_MANT_DIG - 1) * radlog;
	assert(LDBL_DIG >= 10 && LDBL_DIG >= DBL_DIG);
	assert(LDBL_DIG >= digs && LDBL_DIG <= digs + 1);
	assert(LDBL_EPSILON <= 1e-9);
	assert(LDBL_MAX >= 1e37);
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
#endif
	puts("SUCCESS testing <float.h>");
	return 0;
}
