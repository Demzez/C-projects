#include "calc_tests.h"
#include <math.h>

START_TEST(test_1) {
    my_str *str_pol = NULL;
    char *str = malloc(50 * sizeof(char));
    strcpy(str, "12.2345 + (-235)");
    Notation(&str_pol, str);
    double true_res = -222.765500;
    double ans = 0.0;
    calc(str_pol, &ans, 0.0);
    ck_assert_double_eq(ans, true_res);
    free(str);
}
END_TEST

START_TEST(test_2) {
    my_str *str_pol = NULL;
    char *str = malloc(50 * sizeof(char));
    strcpy(str, "wdedwedwedwed");
    int true_res = 0;
    int ans = Notation(&str_pol, str);
    ck_assert_int_eq(ans, true_res);
    free(str);
}
END_TEST

START_TEST(test_4) {
    my_str *str_pol = NULL;
    char *str = malloc(50 * sizeof(char));
    strcpy(str, "2-*3");
    int true_res = 1;
    int ans = Notation(&str_pol, str);
    ck_assert_int_eq(ans, true_res);
    free(str);
}
END_TEST

START_TEST(test_5) {
    my_str *str_pol = NULL;
    char *str = malloc(50 * sizeof(char));
    strcpy(str, "/10");
    int true_res = 1;
    int ans = Notation(&str_pol, str);
    ck_assert_int_eq(ans, true_res);
    free(str);
}
END_TEST

START_TEST(test_6) {
    my_str *str_pol = NULL;
    char *str = malloc(50 * sizeof(char));
    strcpy(str, "5(");
    int true_res = 0;
    int ans = Notation(&str_pol, str);
    ck_assert_int_eq(ans, true_res);
    free(str);
}
END_TEST

START_TEST(test_7) {
    my_str *str_pol = NULL;
    char *str = malloc(50 * sizeof(char));
    strcpy(str, "sint(x)");
    int true_res = 0;
    int ans = Notation(&str_pol, str);
    ck_assert_int_eq(ans, true_res);
    free(str);
}
END_TEST

START_TEST(test_8) {
    my_str *str_pol = NULL;
    char *str = malloc(50 * sizeof(char));
    strcpy(str, "3.456mor234");
    int true_res = 0;
    int ans = Notation(&str_pol, str);
    ck_assert_int_eq(ans, true_res);
    free(str);
}
END_TEST

START_TEST(test_9) {
    my_str *str_pol = NULL;
    char *str = malloc(50 * sizeof(char));
    strcpy(str, "tin(x)");
    int true_res = 0;
    int ans = Notation(&str_pol, str);
    ck_assert_int_eq(ans, true_res);
    free(str);
}
END_TEST

START_TEST(test_10) {
    my_str *str_pol = NULL;
    char *str = malloc(50 * sizeof(char));
    strcpy(str, "sqvt(x)");
    int true_res = 0;
    int ans = Notation(&str_pol, str);
    ck_assert_int_eq(ans, true_res);
    free(str);
}
END_TEST

START_TEST(test_11) {
    my_str *str_pol = NULL;
    char *str = malloc(50 * sizeof(char));
    strcpy(str, "sit(x)");
    int true_res = 0;
    int ans = Notation(&str_pol, str);
    ck_assert_int_eq(ans, true_res);
    free(str);
}
END_TEST

START_TEST(test_12) {
    my_str *str_pol = NULL;
    char *str = malloc(50 * sizeof(char));
    strcpy(str, "sqrv(x)");
    int true_res = 0;
    int ans = Notation(&str_pol, str);
    ck_assert_int_eq(ans, true_res);
    free(str);
}
END_TEST

START_TEST(test_13) {
    my_str *str_pol = NULL;
    char *str = malloc(50 * sizeof(char));
    strcpy(str, "(12 + 8))");
    int true_res = 0;
    int ans = Notation(&str_pol, str);
    ck_assert_int_eq(ans, true_res);
    free(str);
}
END_TEST

START_TEST(test_14) {
    my_str *str_pol = NULL;
    char *str = malloc(50 * sizeof(char));
    strcpy(str, "tan(3.3) + cos(1)");
    Notation(&str_pol, str);
    double true_res = tan(3.3) + cos (1);//0.700048;
    double ans = 0.0;
    calc(str_pol, &ans, 0.0);
    ck_assert_double_eq(fabs(ans - true_res), 0.0);
    free(str);
}
END_TEST

START_TEST(test_15) {
    my_str *str_pol = NULL;
    char *str = malloc(50 * sizeof(char));
    strcpy(str, "atan(3.3) + sqrt(2)");
    Notation(&str_pol, str);
    double true_res = atan(3.3) + sqrt(2);
    double ans = 0.0;
    calc(str_pol, &ans, 0.0);
    ck_assert_double_eq(fabs(ans - true_res), 0.0);
    free(str);
}
END_TEST

START_TEST(test_16) {
    my_str *str_pol = NULL;
    char *str = malloc(50 * sizeof(char));
    strcpy(str, "5 * 2 / 2 - 1");
    Notation(&str_pol, str);
    double true_res = 5 * 2 / 2 - 1;
    double ans = 0.0;
    calc(str_pol, &ans, 0.0);
    ck_assert_double_eq(fabs(ans - true_res), 0.0);
    free(str);
}
END_TEST

START_TEST(test_17) {
    my_str *str_pol = NULL;
    char *str = malloc(50 * sizeof(char));
    strcpy(str, "2 ^ 10");
    Notation(&str_pol, str);
    double true_res = pow(2, 10);
    double ans = 0.0;
    calc(str_pol, &ans, 0.0);
    ck_assert_double_eq(fabs(ans - true_res), 0.0);
    free(str);
}
END_TEST

START_TEST(test_18) {
    my_str *str_pol = NULL;
    char *str = malloc(50 * sizeof(char));
    strcpy(str, "ln(10)");
    Notation(&str_pol, str);
    double true_res = log(10);
    double ans = 0.0;
    calc(str_pol, &ans, 0.0);
    ck_assert_double_eq(fabs(ans - true_res), 0.0);
    free(str);
}
END_TEST

Suite *suite_s21_calc_notation(void) {
    Suite *s = suite_create("s21_calc_notation");
    TCase *tc = tcase_create("s21_calc_notation");

    tcase_add_test(tc, test_1);
    tcase_add_test(tc, test_2);
    tcase_add_test(tc, test_4);
    tcase_add_test(tc, test_5);
    tcase_add_test(tc, test_6);
    tcase_add_test(tc, test_7);
    tcase_add_test(tc, test_8);
    tcase_add_test(tc, test_9);
    tcase_add_test(tc, test_10);
    tcase_add_test(tc, test_11);
    tcase_add_test(tc, test_12);
    tcase_add_test(tc, test_13);
    tcase_add_test(tc, test_14);
    tcase_add_test(tc, test_15);
    tcase_add_test(tc, test_16);
    tcase_add_test(tc, test_17);
    tcase_add_test(tc, test_18);

    suite_add_tcase(s, tc);
    return s;
}
