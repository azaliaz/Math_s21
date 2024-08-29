#include "s21_math.h"

#include <stdio.h>
#include <stdlib.h>

/**
cosine
@param x
double number
*/
long double s21_cos(double x) {
  long double result;
  if (s21_is_nan(x) || s21_is_inf(x))
    result = S21_NAN;
  else {
    int rg = 1;
    if (x < 0) x *= -1;
    while (x >= S21_PI) {
      x -= S21_PI;
      rg *= -1;
    }
    if (x >= S21_PI / 2) {
      x = S21_PI - x;
      rg *= -1;
    }
    result = 1;
    double xx = x * x;
    double xd = 1;

    for (int i = 1; i < 100; i++) {
      xd = (-1) * xd * xx / ((2 * i) * (2 * i - 1));
      result += xd;
    }

    result *= rg;
  }
  return result;
}

/**
sine
@param x
double number
*/
long double s21_sin(double x) {
  long double result;
  if (s21_is_nan(x) || s21_is_inf(x))
    result = S21_NAN;
  else {
    int rg = 1;
    if (x < 0) {
      x *= -1;
      rg *= -1;
    }
    while (x >= S21_PI) {
      x -= S21_PI;
      rg *= -1;
    }
    if (x >= S21_PI / 2) {
      x = S21_PI - x;
    }
    result = x;
    double xx = x * x;
    long double xd = x;
    for (int i = 1; i < 100; i++) {
      xd = -1 * xd * xx / ((2 * i) * (2 * i + 1));
      result += xd;
    }
    result *= rg;
  }
  return result;
}

/**
square root of num
@param x
double number
*/
long double s21_sqrt(double x) {
  double lo, hi, mid;
  long double result;
  if (s21_is_nan(x) || x < 0)
    result = S21_NAN;
  else if (s21_is_inf(x))
    result = S21_INF;
  else {
    lo = s21_min(x, 1);
    hi = s21_max(x, 1);
    while (100 * lo * lo < x) lo *= 10;
    while (0.01 * hi * hi > x) hi *= 0.1;

    for (int i = 0; i < 100; i++) {
      mid = (lo + hi) / 2;
      if (mid * mid == x)
        break;
      else if (mid * mid > x)
        hi = mid;
      else
        lo = mid;
    }
    result = mid;
  }
  return result;
}

/**
 * compute module
 * @param x
 * kek
 * @param y
 * lol
 */
long double s21_fmod(double x, double y) {
  long double result = S21_NAN;
  int flag = 1;
  if (x < 0) flag = -1;
  result = s21_fabs(x);
  x = s21_fabs(x);
  y = s21_fabs(y);
  if (s21_is_nan(x) == 0 && s21_is_nan(y) == 0) {
    while (result > y) {
      result = x - y;
      x = result;
    }
  }
  return result * flag;
}

/**
 * compute eexponential function in this X
 * @param x X
 */
long double s21_exp(double x) {
  long double result;
  if (s21_is_nan(x) || s21_is_inf(x))
    result = x;
  else {
    int neg = 0;
    if (x < 0) {
      neg = 1;
      x *= -1;
    }
    result = 0;
    long double prev = 1;
    for (int i = 1; i < 5000; i++) {
      result += prev;
      prev = prev * x / i;
    }
    if (neg) result = 1 / result;
  }
  return result;
}

/**
power
@param x
double number
*/
long double s21_log(double x) {
  long double result;
  if (s21_is_nan(x) || x <= 0)
    result = S21_NAN;
  else if (s21_is_inf(x))
    result = S21_INF;
  else if (x < 2) {
    long double x1 = x - 1;
    long double xd = x1;
    result = 0;
    for (int i = 1; i < 5000; i++) {
      int m;
      if (i % 2 == 0)
        m = -1;
      else
        m = 1;
      result += m * xd / i;
      xd *= x1;
    }
  } else {
    long double xd = (x - 1) / (x + 1);
    long double x1 = xd * xd;
    result = 0;
    for (int i = 0; i < 5000; i++) {
      result += xd / (2 * i + 1);
      xd *= x1;
    }
    result *= 2;
  }
  return result;
}

/**
power
@param x
double number
*/
long double s21_pow(double base, double exp) {
  long double result = S21_NAN;
  if (s21_is_nan(base) == 0 && s21_is_nan(exp) == 0) {
    result = s21_exp(exp * s21_log(base));
  }
  return result;
}

/**
tangent
@param x
double number
*/

long double s21_tan(double x) {
  long double result;
  if (s21_is_nan(x) || s21_is_inf(x))
    result = x;
  else {
    long double xcos = s21_cos(x);
    long double xsin = s21_sin(x);
    result = xsin / xcos;
  }
  return result;
}

double s21_max(double x, double y) {
  double result = S21_NAN;
  if (s21_is_nan(x) == 0 && s21_is_nan(y) == 0) {
    if (x > y)
      result = x;
    else
      result = y;
  }
  return result;
}

double s21_min(double x, double y) {
  double result = S21_NAN;
  if (s21_is_nan(x) == 0 && s21_is_nan(y) == 0) {
    if (x < y)
      result = x;
    else
      result = y;
  }
  return result;
}

int s21_abs(int x) {
  if (x < 0) {
    x *= -1;
  }
  return x;
}

long double s21_fabs(double x) {
  if (s21_is_nan(x)) {
    x = S21_NAN;
  } else if (x < 0) {
    x *= -1;
  }
  return x;
}

long double s21_ceil(double x) {
  long double x21 = (long long int)x;  //
  if (x21 < x) {
    x21 = x21 + 1;
  }
  if (s21_is_nan(x) || s21_is_inf(x) || x == DBL_MAX) x21 = x;
  return x21;
}

long double s21_floor(double x) {
  long double x21 = (long long int)x;
  if (x21 > x) {
    x21 = x21 - 1;
  }
  if (s21_is_nan(x) || s21_is_inf(x) || x == DBL_MAX) x21 = x;
  return x21;
}

long double s21_asin(double x) {
  long double x21 = x, y = x;
  int n = 1;
  if (x > -1 && x < 1) {
    while (s21_fabs(y) > 1e-17) {
      y *= (x * x * (2 * n - 1) * (2 * n - 1)) / ((2 * n + 1) * 2 * n);
      n += 1;
      x21 += y;
    }
  }
  if (x == -1) x21 = (-1) * S21_PI / 2;
  if (x == 1) x21 = S21_PI / 2;
  if (x < -1 || x > 1) x21 = S21_NAN;
  return x21;
}

long double s21_acos(double x) {
  long double x21 = (S21_PI / 2) - s21_asin(x);
  return x21;
}

long double s21_atan(double x) {
  long double x21 = s21_asin(x / (s21_sqrt(1 + x * x)));
  return x21;
}
