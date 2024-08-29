#include "s21_math.h"

#include <check.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "s21_math_test.h"

int main(void) {
  Suite *s;
  SRunner *sr;
  s = lib_suite();
  sr = srunner_create(s);
  srunner_run_all(sr, CK_VERBOSE);
  srunner_free(sr);
  return 0;
}

START_TEST(s21_abs_func) {
  int a = -6;
  ck_assert_int_eq(s21_abs(a), abs(a));
  int b = -13;
  ck_assert_int_eq(s21_abs(b), abs(b));
  for (int i = 10000; i > -10000; i -= 5) {
    ck_assert_int_eq(s21_abs(i), abs(i));
  }
}
END_TEST

START_TEST(s21_fabs_func) {
  double a = -6.4567;
  ck_assert_float_eq_tol(s21_fabs(a), fabs(a), 0.000001);
  double b = 0.987;
  ck_assert_float_eq_tol(s21_fabs(b), fabs(b), 0.000001);
  double c = -567.6;
  ck_assert_float_eq_tol(s21_fabs(c), fabs(c), 0.000001);
  ck_assert_float_eq_tol(s21_fabs(c), fabs(c), 0.000001);
}
END_TEST

START_TEST(s21_ceil_func) {
  double a = 0.999;
  ck_assert_float_eq_tol(s21_ceil(a), ceil(a), 0.000001);
  double b = 2.56;
  ck_assert_float_eq_tol(s21_ceil(b), ceil(b), 0.000001);
  double c = -3.45;
  ck_assert_float_eq_tol(s21_ceil(c), ceil(c), 0.000001);
  double d = -0;
  ck_assert_float_eq_tol(s21_ceil(d), ceil(d), 0.000001);
  double e = NAN;
  ck_assert_uint_eq(s21_ceil(e), ceil(e));
  double f = DBL_MAX;
  ck_assert_uint_eq(s21_ceil(f), ceil(f));
  double g = DBL_MIN;
  ck_assert_uint_eq(s21_ceil(g), ceil(g));
}
END_TEST

START_TEST(s21_floor_func) {
  double a = 0.999;
  ck_assert_float_eq_tol(s21_floor(a), floor(a), 0.000001);
  double b = 2.56;
  ck_assert_float_eq_tol(s21_floor(b), floor(b), 0.000001);
  double c = -3.45;
  ck_assert_float_eq_tol(s21_floor(c), floor(c), 0.000001);
  double d = -0;
  ck_assert_float_eq_tol(s21_floor(d), floor(d), 0.000001);
  double e = NAN;
  ck_assert_uint_eq(s21_floor(e), floor(e));
  double f = DBL_MAX;
  ck_assert_uint_eq(s21_floor(f), floor(f));
  double g = DBL_MIN;
  ck_assert_uint_eq(s21_floor(g), floor(g));
}
END_TEST

START_TEST(s21_tan_func) {
  double a = 0.23;
  ck_assert_float_eq_tol(s21_tan(a), tan(a), 0.000001);
  double b = 45;
  ck_assert_float_eq_tol(s21_tan(b), tan(b), 0.000001);
  double c = -4.5;
  ck_assert_float_eq_tol(s21_tan(c), tan(c), 0.000001);
  double d = NAN;
  ck_assert_int_eq(s21_tan(d), tan(d));
  double e = INFINITY;
  ck_assert_int_eq(s21_tan(e), tan(e));
  for (double i = 50; i > -50; i -= 2) {
    ck_assert_float_eq_tol(s21_tan(i), tan(i), 0.000001);
  }
  for (double i = 50.345; i > -50.345; i -= 2.4) {
    ck_assert_float_eq_tol(s21_tan(i), tan(i), 0.000001);
  }
  for (double i = S21_PI; i > -S21_PI; i -= 0.01) {
    ck_assert_float_eq_tol(s21_tan(i), tan(i), 0.000001);
  }
}
END_TEST

START_TEST(s21_cos_func) {
  double a = 0;
  ck_assert_float_eq_tol(s21_cos(a), cos(a), 0.000001);
  double b = -1.3;
  ck_assert_float_eq_tol(s21_cos(b), cos(b), 0.000001);
  double c = 45;
  ck_assert_float_eq_tol(s21_cos(c), cos(c), 0.000001);
  double d = NAN;
  ck_assert_int_eq(s21_cos(d), cos(d));
  double e = INFINITY;
  ck_assert_int_eq(s21_cos(e), cos(e));
  for (double i = S21_PI; i > -S21_PI; i -= 0.01) {
    ck_assert_float_eq_tol(s21_cos(i), cos(i), 0.000001);
  }
}
END_TEST

START_TEST(s21_sin_func) {
  double a = 0;
  ck_assert_float_eq_tol(s21_sin(a), sin(a), 0.000001);
  double b = -1.3;
  ck_assert_float_eq_tol(s21_sin(b), sin(b), 0.000001);
  double c = NAN;
  ck_assert_int_eq(s21_sin(c), sin(c));
  double d = INFINITY;
  ck_assert_int_eq(s21_sin(d), sin(d));
  double e = 45;
  ck_assert_float_eq_tol(s21_sin(e), sin(e), 0.000001);
  for (double i = S21_PI; i > -S21_PI; i -= 0.01) {
    ck_assert_float_eq_tol(s21_sin(i), sin(i), 0.000001);
  }
}
END_TEST

START_TEST(s21_atan_func) {
  double a = 0.43;
  ck_assert_float_eq_tol(s21_atan(a), atan(a), 0.000001);
  double b = 2.83;
  ck_assert_float_eq_tol(s21_atan(b), atan(b), 0.000001);
  double c = 1;
  ck_assert_float_eq_tol(s21_atan(c), atan(c), 0.000001);
  double d = -1;
  ck_assert_float_eq_tol(s21_atan(d), atan(d), 0.000001);
  double e = 0;
  ck_assert_float_eq_tol(s21_atan(e), atan(e), 0.000001);
  double f = NAN;
  ck_assert_int_eq(s21_atan(f), atan(f));
  double g = S21_PI;
  ck_assert_float_eq_tol(s21_atan(g), atan(g), 0.000001);
  for (double i = -1; i <= 1; i += 0.01) {
    ck_assert_float_eq_tol(s21_atan(i), atan(i), 0.000001);
  }
}
END_TEST

START_TEST(s21_acos_func) {
  double a = 0.43;
  ck_assert_float_eq_tol(s21_acos(a), acos(a), 0.000001);
  double b = -1;
  ck_assert_float_eq_tol(s21_acos(b), acos(b), 0.000001);
  double c = -0.999;
  ck_assert_float_eq_tol(s21_acos(c), acos(c), 0.000001);
  for (double i = 1; i > -1; i -= 0.01) {
    ck_assert_float_eq_tol(s21_acos(i), acos(i), 0.000001);
  }
}
END_TEST

START_TEST(s21_asin_func) {
  double a = 0.43;
  ck_assert_float_eq_tol(s21_asin(a), asin(a), 0.000001);
  double b = 1.01;
  ck_assert_int_eq(s21_asin(b), S21_NAN);
  double c = -0.999;
  ck_assert_float_eq_tol(s21_asin(c), asin(c), 0.000001);
  for (double i = 1; i > -1; i -= 0.01) {
    ck_assert_float_eq_tol(s21_asin(i), asin(i), 0.000001);
  }
}
END_TEST

START_TEST(s21_fmod_func) {
  ck_assert_float_eq_tol(s21_fmod(123.456, 7.8), fmod(123.456, 7.8), 0.000001);
  ck_assert_float_eq_tol(s21_fmod(-987.657, 5.77), fmod(-987.657, 5.77),
                         0.000001);
  ck_assert_float_eq_tol(s21_fmod(5.4, 3.2), fmod(5.4, 3.2), 0.000001);
  ck_assert_int_eq(s21_fmod(NAN, NAN), fmod(NAN, NAN));
  ck_assert_int_eq(s21_fmod(INFINITY, INFINITY), fmod(INFINITY, INFINITY));
  ck_assert_float_eq_tol(s21_fmod(-93.4, -1.23), fmod(-93.4, -1.23), 0.000001);
  ck_assert_float_eq_tol(s21_fmod(56.45, -1.23), fmod(56.45, -1.23), 0.000001);
}
END_TEST

START_TEST(s21_exp_func) {
  ck_assert_float_eq_tol(s21_exp(15), exp(15), 0.000001);
  ck_assert_float_eq_tol(s21_exp(-15), exp(-15), 0.000001);
  ck_assert_float_eq_tol(s21_exp(-2), exp(-2), 0.000001);
  ck_assert_int_eq(s21_exp(1234567), exp(1234567));
  ck_assert_float_eq_tol(s21_exp(-1234567), exp(-1234567), 0.000001);
  ck_assert_uint_eq(s21_exp(NAN), exp(NAN));
  for (double i = -10; i < 10; i++) {
    ck_assert_float_eq_tol(s21_exp(i), exp(i), 0.000001);
  }
}
END_TEST

START_TEST(s21_log_func) {
  ck_assert_int_eq(s21_log(12356), log(12356));
  ck_assert_float_eq_tol(s21_log(1.1), log(1.1), 0.000001);
  ck_assert_int_eq(s21_log(NAN), log(NAN));
  ck_assert_int_eq(s21_log(0), S21_NAN);
  ck_assert_int_eq(s21_log(-1), S21_NAN);
  for (double i = 0.1; i < 10; i += 0.1) {
    ck_assert_float_eq_tol(s21_log(i), log(i), 0.000001);
  }
}
END_TEST

START_TEST(s21_sqrt_func) {
  ck_assert_float_eq_tol(s21_sqrt(16.0), sqrt(16.0), 0.000001);
  ck_assert_float_eq_tol(s21_sqrt(45.35), sqrt(45.35), 0.000001);
  ck_assert_int_eq(s21_sqrt(NAN), sqrt(NAN));
  ck_assert_int_eq(s21_sqrt(INFINITY), sqrt(INFINITY));
  for (double i = 0; i < 1; i += 0.001) {
    ck_assert_float_eq_tol(s21_sqrt(i), sqrt(i), 0.000001);
  }
}
END_TEST

START_TEST(s21_pow_func) {
  ck_assert_float_eq_tol(s21_pow(2.6, 3.45), pow(2.6, 3.45), 0.000001);
  ck_assert_float_eq_tol(s21_pow(3.0, 14.0), pow(3.0, 14.0), 0.000001);
  ck_assert_float_eq_tol(s21_pow(31.456, 4.3), pow(31.456, 4.3), 0.000001);
  ck_assert_float_eq_tol(s21_pow(31.777, 0.3), pow(31.777, 0.3), 0.000001);
  ck_assert_float_eq_tol(s21_pow(1.2, 1.2), pow(1.2, 1.2), 0.000001);
  ck_assert_int_eq(s21_pow(-1234, 7.3), pow(-1234, 7.3));
  ck_assert_int_eq(s21_pow(-12345, -4.3), pow(-12345, -4.3));
  ck_assert_int_eq(s21_pow(12345, -4.3), pow(12345, -4.3));
  ck_assert_int_eq(s21_pow(NAN, NAN), pow(NAN, NAN));
  ck_assert_int_eq(s21_pow(INFINITY, INFINITY), pow(INFINITY, INFINITY));
}
END_TEST

Suite *lib_suite(void) {
  Suite *s;
  s = suite_create("CHECK");
  TCase *ceil;
  TCase *floor;
  TCase *tan;
  TCase *cos;
  TCase *sin;
  TCase *abs;
  TCase *atan;
  TCase *acos;
  TCase *asin;
  TCase *fmod;
  TCase *exp;
  TCase *log;
  TCase *sqrt;
  TCase *pow;
  TCase *fabs;

  abs = tcase_create("ABS");
  suite_add_tcase(s, abs);
  tcase_add_test(abs, s21_abs_func);

  fabs = tcase_create("FABS");
  suite_add_tcase(s, fabs);
  tcase_add_test(fabs, s21_fabs_func);

  ceil = tcase_create("CEIL: ");
  suite_add_tcase(s, ceil);
  tcase_add_test(ceil, s21_ceil_func);

  sin = tcase_create("SIN");
  suite_add_tcase(s, sin);
  tcase_add_test(sin, s21_sin_func);

  cos = tcase_create("COS");
  suite_add_tcase(s, cos);
  tcase_add_test(cos, s21_cos_func);

  tan = tcase_create("TAN");
  suite_add_tcase(s, tan);
  tcase_add_test(tan, s21_tan_func);

  floor = tcase_create("FLOOR:");
  suite_add_tcase(s, floor);
  tcase_add_test(floor, s21_floor_func);

  fmod = tcase_create("FMOD");
  suite_add_tcase(s, fmod);
  tcase_add_test(fmod, s21_fmod_func);

  asin = tcase_create("ASIN");
  suite_add_tcase(s, asin);
  tcase_add_test(asin, s21_asin_func);

  acos = tcase_create("ACOS");
  suite_add_tcase(s, acos);
  tcase_add_test(acos, s21_acos_func);

  atan = tcase_create("ATAN");
  suite_add_tcase(s, atan);
  tcase_add_test(atan, s21_atan_func);

  pow = tcase_create("POW");
  suite_add_tcase(s, pow);
  tcase_add_test(pow, s21_pow_func);

  sqrt = tcase_create("SQRT");
  suite_add_tcase(s, sqrt);
  tcase_add_test(sqrt, s21_sqrt_func);

  log = tcase_create("LOG");
  suite_add_tcase(s, log);
  tcase_add_test(log, s21_log_func);

  exp = tcase_create("EXP");
  suite_add_tcase(s, exp);
  tcase_add_test(exp, s21_exp_func);

  return s;
}
