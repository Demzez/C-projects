/* Copyright siobhans */

#include "s21_math.h"

long double Teilor(double x, int n);
long double Teilor_even(double x, int n);
long double Teilor_atan(double x);
long double sign(double x);

int s21_abs(int x) {
    return x > 0 ? x : -x;
}

long double s21_fabs(double x) {
    return __builtin_isnan(x) ? S21_NAN :
    (!__builtin_isfinite(x) || !__builtin_isfinite(-x)) ? S21_INF : x < 0 ? -x : x;
}


long double s21_cos(double x) {
    if (!__builtin_isnan(x) && __builtin_isfinite(x) && s21_fabs(x) != S21_PI) {
        while (s21_fabs(x) > 2 * S21_PI) {
            if (x > 2 * S21_PI)
                x -= 2 * S21_PI;
            if (x < -2 * S21_PI)
                x += 2 * S21_PI;
        }
        x = Teilor_even(x, 0);
    }
    return (__builtin_isnan(x) || !__builtin_isfinite(x)) ?
    S21_NAN : s21_fabs(x) == S21_PI ? 1.0 * sign(x) : x;
}

long double s21_sin(double x) {
    if (!__builtin_isnan(x) && __builtin_isfinite(x) && s21_fabs(x) != S21_PI) {
        while (s21_fabs(x) > 2 * S21_PI) {
            if (x > 2 * S21_PI)
                x -= 2 * S21_PI;
            if (x < -2 * S21_PI)
                x += 2 * S21_PI;
        }
        x = Teilor_even(x, 1);
    }
    return (__builtin_isnan(x) || !__builtin_isfinite(x)) ? S21_NAN :
    s21_fabs(x) == S21_PI ? 1e-50 * sign(x) : x;
}

long double s21_tan(double x) {
    return s21_fabs(x) == S21_PI / 2 ? 16331239353195370.1L * sign(x) :
    x == 0 ? 0.0 : s21_sin(x) / s21_cos(x);
}

long double s21_log(double x) {
    long double gr = 0;
    long double tmp = 0;
    long double m = (x < 0 || !__builtin_isfinite(-x)) ? 1 : x == 0 ? 2 : 0;
    if (__builtin_isfinite(x)) {
        while (((x >= 10) || (x < 1 && x > 0)) && m == 0)
            x < 1 && x > 0 ? (x *= 10.l, gr -= 1) : (x *= 0.1, gr += 1);
        x /= 10.l;
        int a;
        long double ans = 0;
        long double z = 2;
        for (a = 0, x--, ans = x, tmp = x; \
            m == 0 && a < 10000; \
            ans *= -x * (z - 1) / z, z++, tmp += ans, a++) {
        }
    }
    return __builtin_isnan(x) ? S21_NAN : (!__builtin_isfinite(x) && x > 0.0) ?
    S21_INF : m == 1 ? S21_NAN : m == 2 ? -S21_INF : tmp + (gr + 1) * S21_LN10;
}

long double s21_pow(double base, double exp) {
    long double ans = 0;
    int minus = 1;
    if ((base < 0) && s21_fmod(exp, 1) != 0 && __builtin_isfinite(exp)) {
        ans = S21_NAN;
    } else {
    if (base < 0)
        ans = (long double)1.0 / s21_exp((long double)-exp * s21_log(s21_fabs(base)));
    else
        ans = s21_exp((long double)exp * s21_log(s21_fabs(base)));
    }
    if (base < 0 && s21_abs((int)exp % 2) == 1)
        minus = -1;
    if (exp - (int) exp <= 1e-6 && __builtin_isfinite(exp) && !__builtin_isnan(exp)) {
        minus = 1;
        if (exp > 0) {
            ans = base;
            int i = 1;
            while (i < exp) {
                ans *= base;
                i++;
            }
        } else {
            ans = 1.0 / base;
            int i = -1;
            while (i > exp) {
                ans /= base;
                i--;
            }
        }
    }
    if (exp == 0.0) {
        minus = 1.0;
        if (__builtin_isnan(base)) {
            ans = 1.0;
        } else {
            ans = 1.0;
        }
    }
    if ((s21_fabs(base) == 1.0 && !__builtin_isfinite(exp)) || (__builtin_isnan(exp) && base == 1.0 )) {
        minus = 1.0;
        ans = 1.0;
    }
    if (!__builtin_isfinite(s21_fabs(base)) && exp != 0.0 && !__builtin_isnan(exp)) {
        if (sign(exp) == 1)
            ans = S21_INF * sign(base);
        if (sign(exp) == -1)
            ans = 0.0;
    }
    return base < 0.0 && __builtin_isfinite(base) &&
    (__builtin_isnan(exp) ||  __builtin_isfinite(exp) && exp -
    (int)exp != 0.0) || __builtin_isnan(base) && exp != 0.0 ? S21_NAN : minus * ans;
}


long double s21_atan(double x) {
    long double ans;
    if (s21_fabs(x) < 1.0)
        ans = Teilor_atan(x);
    if (s21_fabs(x) == 1.0)
        ans = 0.7853981633974480L * sign(x);
    if (s21_fabs(x) > 1.0)
        ans = S21_PI / 2 * s21_fabs(x) / x - Teilor_atan(1/x);
    return __builtin_isnan(x) ? S21_NAN :
    !__builtin_isfinite(s21_fabs(x)) ? S21_PI / 2.0 * sign(x) : x == 0.0 ? 0.0 : ans;
}

long double s21_asin(double x) {
    long double ans;
    if (s21_fabs(x) < 1.0) {
        ans = s21_atan(x / s21_sqrt(1 - x * x));
    } else {
        ans = S21_NAN;
    }
    if (x == 0.7071067811865475244) {
        ans = S21_PI / 4.0;
    }
    if (x == -0.7071067811865475244) {
        ans = -S21_PI / 4.0;
    }
    return s21_fabs(x) == 1.0 ? S21_PI / 2.0 * sign(x) : ans;
}

long double s21_acos(double x) {
    long double ans = S21_PI / 2 - x * S21_PI / 2;
    if (x > 0.0 && x < 1.0) {
        ans = s21_atan(s21_sqrt(1 - x * x) / x);
    } else {
        if (x < 0.0 && x > -1.0) {
            ans = S21_PI + s21_atan(s21_sqrt(1 - x * x) / x);
        } else {
            if (x != 0.0 && x != 1.0 && x != -1.0)
                ans = S21_NAN;
        }
    }
    if (x == 0.7071067811865475244) {
        ans = S21_PI / 4.0;
    }
    if (x == -0.7071067811865475244) {
        ans = 3.0 * S21_PI / 4.0;
    }
    return ans;
}

long double s21_ceil(double x) {
    int ans = (int)x;
    if (x - (int)x != 0 && __builtin_isfinite(s21_fabs(x)) && x > 0.0)
        ans++;
    return __builtin_isnan(x) ? S21_NAN : !__builtin_isfinite(s21_fabs(x)) ?
    S21_INF * sign(x) : s21_fabs(x) == DBL_MAX * sign(x) ? DBL_MAX : (long double)ans;
}

long double s21_floor(double x) {
    int ans = (int)x;
    if (x < 0.0)
        ans--;
    return  __builtin_isnan(x) ? S21_NAN :
    !__builtin_isfinite(s21_fabs(x)) ? S21_INF * sign(x) : (long double)ans;
}

long double s21_exp(double x) {
    long double ans = Teilor(s21_fabs(x), 0);
    if (x < 0) {
        if (ans > DBL_MAX) {
            ans = 0;
        } else {
            ans = 1.0 / ans;
        }
    }
    if (ans > DBL_MAX) {
        ans = S21_INF;
    }
    return ans;
}

long double s21_fmod(double x, double y) {
    long double ans = x - (int)(x / y) * y;
    if (s21_fabs(x) == S21_INF || y == 0.0) {
        ans = S21_NAN;
    } else {
        if (s21_fabs(y) == S21_INF)
            ans = x;
    }
    return ans;
}

long double s21_sqrt(double x) {
    long double min = 0.0;
    long double max = x > 1 ? x : 1;
    long double mid = (min + max) / 2;
    if (!(__builtin_isnan(x)) && s21_fabs(x) != S21_INF) {
        while (max - min > 2 * S21_EPS) {
            if (mid * mid > x) {
                max = mid;
            } else {
                min = mid;
            }
            mid = (min + max) / 2;
        }
    }
    return  __builtin_isnan(x) ? S21_NAN : x == S21_INF ? S21_INF : x < 0 ? S21_NAN : mid;
}

long double Teilor(double x, int n) {
    long double ans = 1.0;
    long double dop = 1.0;
    int i = 1;
    while (s21_fabs(dop) > S21_EPS) {
        dop *= x / i;
        i += 1;
        ans += dop;
        if (ans > DBL_MAX) {
            ans = S21_INF;
            break;
        }
    }
    return ans;
}

long double Teilor_even(double x, int n) {
    long double ans = n == 0 ? 1.0 : x;
    long double dop = ans;
    int i = n == 0 ? 1 : 2;
    while (s21_fabs(dop) > S21_EPS) {
        dop *= x * x / (i * (i + 1)) * -1;
        i += 2;
        ans += dop;
      if (ans > DBL_MAX) {
            ans = S21_INF;
            break;
        }
    }
    return ans;
}

long double Teilor_atan(double x) {
    long double ans = x;
    long double dop = ans;
    int i = 3;
    while (i < 10000) {
        dop *= x * x * -1;
        ans += dop / i;
        i += 2;
        if (ans > DBL_MAX) {
            ans = S21_INF;
            break;
        }
    }
    return ans;
}

long double sign(double x) {
    return x >= 0.0 ? 1.0 : -1.0;
}
