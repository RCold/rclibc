#ifndef _MATH_H
#define _MATH_H

#define HUGE_VAL _hugeval

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

extern double _hugeval;

double acos(double);
double asin(double);
double atan(double);
double atan2(double, double);
double ceil(double);
double cos(double);
double cosh(double);
double exp(double);
double fabs(double);
double floor(double);
double fmod(double, double);
double frexp(double, int *);
double ldexp(double, int);
double log(double);
double log10(double);
double modf(double, double *);
double pow(double, double);
double sin(double);
double sinh(double);
double sqrt(double);
double tan(double);
double tanh(double);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _MATH_H */
