#ifndef S21_MATH
#define S21_MATH

#include <float.h>
#include <stdio.h>

#define S21_PI 3.1415926535897932
#define S21_INF 1.0 / 0.0
#define S21_NAN 0.0 / 0.0
#define s21_is_inf __builtin_isinf
#define s21_is_nan __builtin_isnan

double s21_max(double x, double y);
double s21_min(double x, double y);

int s21_abs(int x);
long double s21_fabs(double x);
long double s21_floor(double x);
long double s21_acos(double x);
long double s21_atan(double x);
long double s21_ceil(double x);
long double s21_asin(double x);

long double s21_exp(double x);
long double s21_fmod(double x, double y);
long double s21_cos(double x);
long double s21_sin(double x);
long double s21_log(double x);
long double s21_pow(double base, double exp);
long double s21_sqrt(double x);
long double s21_tan(double x);

#endif
