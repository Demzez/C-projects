#include "s21_math_test.h"

int suite_fails(Suite *s) {
    SRunner *srun = srunner_create(s);
    srunner_run_all(srun, CK_NORMAL);
    int fails = srunner_ntests_failed(srun);
    srunner_free(srun);
    return fails;
}

int set_fails (Suite* (*tests[])(), int n) {
    int summary = 0;
    for (int i = 0; i < n; i++)
        summary += suite_fails(tests[i]());
    return summary;
}


int main(void) {
    Suite* (*tests[])() = {suite_s21_abs, suite_s21_acos, suite_s21_asin, suite_s21_atan,
      suite_s21_ceil, suite_s21_cos, suite_s21_exp, suite_s21_fabs,
      suite_s21_floor, suite_s21_fmod, suite_s21_log,  suite_s21_pow,
      suite_s21_sin, suite_s21_sqrt, suite_s21_tan};
    if (set_fails(tests, 15) != 0) {
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

