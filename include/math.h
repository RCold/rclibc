#ifndef _MATH_H
#define _MATH_H

#define HUGE_VAL    (1e+300 * 1e+300)

#include <sys/cdefs.h>

__BEGIN_DECLS

double acos(double);

double asin(double);

double atan(double);

double atan2(double, double);

double cos(double);

double sin(double);

double tan(double);

double cosh(double);

double sinh(double);

double tanh(double);

double exp(double);

double frexp(double, int *);

double ldexp(double, int);

double log(double);

double log10(double);

double modf(double, double *);

double pow(double, double);

double sqrt(double);

double ceil(double);

double fabs(double);

double floor(double);

double fmod(double, double);

__END_DECLS

#endif /* _MATH_H */
