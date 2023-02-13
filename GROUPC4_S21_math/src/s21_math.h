#ifndef SRC_S21_MATH_H_
#define SRC_S21_MATH_H_
#define S21_PI 3.14159265358979323846264338327950288
#define S21_EXP 2.7182818284590452353602874713526624
#define S21_EPS 1e-9
#define S21_LN2 0.6931471805599453L
#define S21_LN10 2.30258509299
#define ACC 1e-25l


#define S21_INF 1.0 / 0.0
#define S21_NAN 0.0 / 0.0

#include <stdio.h>
#include <float.h>
#include <stdlib.h>

int s21_abs(int x);
long double s21_acos(double x);
long double s21_asin(double x);
long double s21_atan(double x);
long double s21_ceil(double x);
long double s21_cos(double x);
long double s21_exp(double x);
long double s21_fabs(double x);
long double s21_floor(double x);
long double s21_fmod(double x, double y);
long double s21_log(double x);
long double s21_pow(double base, double exp);
long double s21_sin(double x);
long double s21_sqrt(double x);
long double s21_tan(double x);


#endif  // SRC_S21_MATH_H_

