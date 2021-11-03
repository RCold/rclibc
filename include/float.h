#ifndef _FLOAT_H
#define _FLOAT_H

#if __GNUC__ > 3 || (__GNUC__ == 3 && __GNUC_MINOR__ >= 3)

#define FLT_ROUNDS          1
#define FLT_RADIX           __FLT_RADIX__

#define FLT_MANT_DIG        __FLT_MANT_DIG__
#define DBL_MANT_DIG        __DBL_MANT_DIG__
#define LDBL_MANT_DIG       __LDBL_MANT_DIG__

#define FLT_DIG             __FLT_DIG__
#define DBL_DIG             __DBL_DIG__
#define LDBL_DIG            __LDBL_DIG__

#define FLT_MIN_EXP         __FLT_MIN_EXP__
#define DBL_MIN_EXP         __DBL_MIN_EXP__
#define LDBL_MIN_EXP        __LDBL_MIN_EXP__

#define FLT_MIN_10_EXP      __FLT_MIN_10_EXP__
#define DBL_MIN_10_EXP      __DBL_MIN_10_EXP__
#define LDBL_MIN_10_EXP     __LDBL_MIN_10_EXP__

#define FLT_MAX_EXP         __FLT_MAX_EXP__
#define DBL_MAX_EXP         __DBL_MAX_EXP__
#define LDBL_MAX_EXP        __LDBL_MAX_EXP__

#define FLT_MAX_10_EXP      __FLT_MAX_10_EXP__
#define DBL_MAX_10_EXP      __DBL_MAX_10_EXP__
#define LDBL_MAX_10_EXP     __LDBL_MAX_10_EXP__

#define FLT_MAX             __FLT_MAX__
#define DBL_MAX             __DBL_MAX__
#define LDBL_MAX            __LDBL_MAX__

#define FLT_EPSILON         __FLT_EPSILON__
#define DBL_EPSILON         __DBL_EPSILON__
#define LDBL_EPSILON        __LDBL_EPSILON__

#define FLT_MIN             __FLT_MIN__
#define DBL_MIN             __DBL_MIN__
#define LDBL_MIN            __LDBL_MIN__

#else

#define FLT_ROUNDS          1
#define FLT_RADIX           2

#define FLT_MANT_DIG        24
#define DBL_MANT_DIG        53
#define LDBL_MANT_DIG       53

#define FLT_DIG             6
#define DBL_DIG             15
#define LDBL_DIG            15

#define FLT_MIN_EXP         (-125)
#define DBL_MIN_EXP         (-1021)
#define LDBL_MIN_EXP        (-1021)

#define FLT_MIN_10_EXP      (-37)
#define DBL_MIN_10_EXP      (-307)
#define LDBL_MIN_10_EXP     (-307)

#define FLT_MAX_EXP         128
#define DBL_MAX_EXP         1024
#define LDBL_MAX_EXP        1024

#define FLT_MAX_10_EXP      38
#define DBL_MAX_10_EXP      308
#define LDBL_MAX_10_EXP     308

#define FLT_MAX             3.4028235e+38F
#define DBL_MAX             1.7976931348623157e+308
#define LDBL_MAX            1.7976931348623157e+308L

#define FLT_EPSILON         1.1920929e-07F
#define DBL_EPSILON         2.2204460492503131e-016
#define LDBL_EPSILON        2.2204460492503131e-016L

#define FLT_MIN             1.1754944e-38F
#define DBL_MIN             2.2250738585072014e-308
#define LDBL_MIN            2.2250738585072014e-308L

#endif /* __GNUC__ > 3 || (__GNUC__ == 3 && __GNUC_MINOR__ >= 3) */

#endif /* _FLOAT_H */
