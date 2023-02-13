/* Copyright Team */
#include "s21_string.h"
#include <stdio.h>
#include <string.h>
#include <check.h>

////////////////////////////////////// BRANDTLA
START_TEST(strcmp_test_1) {
    char a1[] = "Hello world\n\0", a2[]="Hello world\n";
    ck_assert_int_eq(s21_strcmp(a1, a2), strcmp(a1, a2));
} END_TEST

START_TEST(strcmp_test_2) {
    char a1[] = "Hello world\n\0", a2[]="Hello wor\n\0";
    ck_assert_int_eq(s21_strcmp(a1, a2), strcmp(a1, a2));
} END_TEST

START_TEST(strcmp_test_3) {
    char a1[] = "\n\0", a2[]="\n\0";
    ck_assert_int_eq(s21_strcmp(a1, a2), strcmp(a1, a2));
} END_TEST

START_TEST(strcmp_test_4) {
    char a1[] = "\0", a2[]="\n\0";
    ck_assert_int_eq(s21_strcmp(a1, a2), strcmp(a1, a2));
} END_TEST

START_TEST(strcmp_test_5) {
    char a1[] = "\0", a2[]="\0";
    ck_assert_int_eq(s21_strcmp(a1, a2), strcmp(a1, a2));
} END_TEST

Suite *strcmp_test(void) {
    Suite *suite = suite_create("strcmp_test");
    TCase *tcase_core = tcase_create("BRANDTLA");

    tcase_add_test(tcase_core, strcmp_test_1);
    tcase_add_test(tcase_core, strcmp_test_2);
    tcase_add_test(tcase_core, strcmp_test_3);
    tcase_add_test(tcase_core, strcmp_test_4);
    tcase_add_test(tcase_core, strcmp_test_5);

    suite_add_tcase(suite, tcase_core);

    return suite;
}



START_TEST(strncmp_test_1) {
    char a1[] = "Hello world\n", a2[] = "Hello wor\n";
    int n = 4;
    ck_assert_int_eq(s21_strncmp(a1, a2, n), strncmp(a1, a2, n));
} END_TEST

START_TEST(strncmp_test_2) {
    char a1[] = "Hello world\n\0", a2[] = "Hello world\n\0";
    int n = 14;
    ck_assert_int_eq(s21_strncmp(a1, a2, n), strncmp(a1, a2, n));
} END_TEST

START_TEST(strncmp_test_3) {
    char a1[] = "Hello world\n\0", a2[] = "Hello wor\n";
    int n = 10;
    ck_assert_int_eq(s21_strncmp(a1, a2, n), strncmp(a1, a2, n));
} END_TEST

START_TEST(strncmp_test_4) {
    char a1[] = "\0", a2[]="\n\0";
    int n = 0;
    ck_assert_int_eq(s21_strncmp(a1, a2, n), strncmp(a1, a2, n));
} END_TEST

START_TEST(strncmp_test_5) {
    char a1[] = "\0", a2[]="\0";
    int n = 2;
    ck_assert_int_eq(s21_strncmp(a1, a2, n), strncmp(a1, a2, n));
} END_TEST

Suite *strncmp_test(void) {
    Suite *suite = suite_create("strncmp_test");
    TCase *tcase_core = tcase_create("BRANDTLA");

    tcase_add_test(tcase_core, strncmp_test_1);
    tcase_add_test(tcase_core, strncmp_test_2);
    tcase_add_test(tcase_core, strncmp_test_3);
    tcase_add_test(tcase_core, strncmp_test_4);
    tcase_add_test(tcase_core, strncmp_test_5);

    suite_add_tcase(suite, tcase_core);

    return suite;
}



START_TEST(strcpy_test_1) {
    char a1[] = "Hello world\n\0", a2[15], a3[15];
    s21_strcpy(a2, a1);
    strcpy(a3, a1);
    ck_assert_str_eq(a2, a3);
} END_TEST

START_TEST(strcpy_test_2) {
    char str[] = "Sample string";
    char a1[40];
    char a2[40];

    s21_strcpy(a1, str);
    s21_strcpy(a1, "copy successful");

    strcpy(a2, str);
    strcpy(a2, "copy successful");

    ck_assert_str_eq(a1, a2);
} END_TEST

START_TEST(strcpy_test_3) {
    char a1[] = "\n\0", a2[5], a3[5];
    s21_strcpy(a2, a1);
    strcpy(a3, a1);
    ck_assert_str_eq(a2, a3);
} END_TEST

START_TEST(strcpy_test_4) {
    char a1[] = "\0", a2[]="\n\0", a3[] = "\n\0";
    s21_strcpy(a2, a1);
    strcpy(a3, a1);
    ck_assert_str_eq(a2, a3);
} END_TEST

START_TEST(strcpy_test_5) {
    char a1[] = "\0", a2[]=" \0", a3[] = " \0";
    s21_strcpy(a2, a1);
    strcpy(a3, a1);
    ck_assert_str_eq(a2, a3);
} END_TEST

Suite *strcpy_test(void) {
    Suite *suite = suite_create("strcpy_test");
    TCase *tcase_core = tcase_create("BRANDTLA");

    tcase_add_test(tcase_core, strcpy_test_1);
    tcase_add_test(tcase_core, strcpy_test_2);
    tcase_add_test(tcase_core, strcpy_test_3);
    tcase_add_test(tcase_core, strcpy_test_4);
    tcase_add_test(tcase_core, strcpy_test_5);

    suite_add_tcase(suite, tcase_core);

    return suite;
}



START_TEST(strncpy_test_1) {
    char* str1 = malloc(11);
    char* str2 = malloc(11);
    for (int i = 0; i < 11; i++) {
        str1[i] = '\0';
        str2[i] = '\0';
    }
    ck_assert_str_eq(s21_strncpy(str1, "", 10), strncpy(str2, "", 10));
    free(str1);
    free(str2);
} END_TEST

START_TEST(strncpy_test_2) {
    char* str1 = malloc(11);
    char* str2 = malloc(11);
    for (int i = 0; i < 11; i++) {
        str1[i] = '\0';
        str2[i] = '\0';
    }
    ck_assert_str_eq(s21_strncpy(str1, "01234567890", 10), strncpy(str2, "01234567890", 10));
    free(str1);
    free(str2);
} END_TEST

START_TEST(strncpy_test_3) {
    char* str1 = malloc(1);
    char* str2 = malloc(1);
    for (int i = 0; i < 1; i++) {
        str1[i] = '\0';
        str2[i] = '\0';
    }
    ck_assert_str_eq(s21_strncpy(str1, "Hello world", 0), strncpy(str2, "Hello world", 0));
    free(str1);
    free(str2);
} END_TEST

START_TEST(strncpy_test_4) {
    char* str1 = malloc(12);
    char* str2 = malloc(12);
    for (int i = 0; i < 12; i++) {
        str1[i] = '\0';
        str2[i] = '\0';
    }
    ck_assert_str_eq(s21_strncpy(str1, "Hello\nworld", 11), strncpy(str2, "Hello\nworld", 11));
    free(str1);
    free(str2);
} END_TEST

START_TEST(strncpy_test_5) {
    char* str1 = malloc(11);
    char* str2 = malloc(11);
    for (int i = 0; i < 11; i++) {
        str1[i] = '\0';
        str2[i] = '\0';
    }
    ck_assert_str_eq(s21_strncpy(str1, "012345678", 10), strncpy(str2, "012345678", 10));
    free(str1);
    free(str2);
} END_TEST

Suite *strncpy_test(void) {
    Suite *suite = suite_create("strncpy_test");
    TCase *tcase_core = tcase_create("BRANDTLA");

    tcase_add_test(tcase_core, strncpy_test_1);
    tcase_add_test(tcase_core, strncpy_test_2);
    tcase_add_test(tcase_core, strncpy_test_3);
    tcase_add_test(tcase_core, strncpy_test_4);
    tcase_add_test(tcase_core, strncpy_test_5);

    suite_add_tcase(suite, tcase_core);

    return suite;
}
////////////////////////////////////// BRANDTLA


////////////////////////////////////// SIOBHANS
START_TEST(strlen_test_1) {
    char str[] = "Hello world\n";
    ck_assert_uint_eq(s21_strlen(str), strlen(str));
} END_TEST

START_TEST(strlen_test_2) {
    char str[] = "Hello world\0";
    ck_assert_uint_eq(s21_strlen(str), strlen(str));
} END_TEST

START_TEST(strlen_test_3) {
    char str[] = "";
    ck_assert_uint_eq(s21_strlen(str), strlen(str));
} END_TEST

START_TEST(strlen_test_4) {
    char str[] = "\0";
    ck_assert_uint_eq(s21_strlen(str), strlen(str));
} END_TEST

START_TEST(strlen_test_5) {
    char str[] = "hello! \n hi!";
    ck_assert_uint_eq(s21_strlen(str), strlen(str));
} END_TEST

Suite *strlen_test(void) {
    Suite *suite = suite_create("strlen_test");
    TCase *tcase_core = tcase_create("SIOBHANS");

    tcase_add_test(tcase_core, strlen_test_1);
    tcase_add_test(tcase_core, strlen_test_2);
    tcase_add_test(tcase_core, strlen_test_3);
    tcase_add_test(tcase_core, strlen_test_4);
    tcase_add_test(tcase_core, strlen_test_5);

    suite_add_tcase(suite, tcase_core);

    return suite;
}



START_TEST(memset_test_1) {
    char str1[] = "Ya vas kategoricheski privetstvuu dami i gospoda";
    char str2[] = "Ya vas kategoricheski privetstvuu dami i gospoda";
    s21_memset(str1, 'A', 10);
    memset(str2, 'A', 10);
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(memset_test_2) {
    char str1[50] = "Cucumber is for programming geeks.";
    char str2[50] = "Cucumber is for programming geeks.";
    s21_memset(str1 + 13, '.', 8 * sizeof(char));
    memset(str2 + 13, '.', 8 * sizeof(char));
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(memset_test_3) {
    char arr1[] = "1234567\0";
    char arr2[] = "1234567\0";
    s21_memset(arr1, '1', 7);
    memset(arr2, '1', 7);
    ck_assert_str_eq(arr1, arr2);
} END_TEST

START_TEST(memset_test_4) {
    void* my_mem = malloc(12);
    void* mem = malloc(12);
    s21_memset(my_mem, '5', 6);
    memset(mem, '5', 6);
    ck_assert_str_eq(my_mem, mem);
    free(my_mem);
    free(mem);
} END_TEST

START_TEST(memset_test_5) {
    void* my_mem = malloc(15);
    void* mem = malloc(15);
    s21_memset(my_mem, '\0', 6);
    memset(mem, '\0', 6);
    ck_assert_str_eq(my_mem, mem);
    free(my_mem);
    free(mem);
} END_TEST

Suite *memset_test(void) {
    Suite *suite = suite_create("memset_test");
    TCase *tcase_core = tcase_create("SIOBHANS");

    tcase_add_test(tcase_core, memset_test_1);
    tcase_add_test(tcase_core, memset_test_2);
    tcase_add_test(tcase_core, memset_test_3);
    tcase_add_test(tcase_core, memset_test_4);
    tcase_add_test(tcase_core, memset_test_5);

    suite_add_tcase(suite, tcase_core);

    return suite;
}



START_TEST(strtok_test_1) {
    char s21_str[15] = "123*456*789";
    char str[15] = "123*456*789";
    char* delim = "*";

    char* s21_part = s21_strtok(s21_str, delim);
    char* part = strtok(str, delim);

    ck_assert_str_eq(s21_part, part);
} END_TEST

START_TEST(strtok_test_2) {
    char s0[][30] = { "12332132312", "123hello321", "0 hello\t  000 world", "what 43 is 12 this56 ?" };
    char s1[][30] = { "12332132312", "123hello321", "0 hello\t  000 world", "what 43 is 12 this56 ?" };
    char s2[][10] = { "123", "123", "0 \t", "123 456" };

    int i;
    char* s21_str = s21_NULL;
    char* str = s21_NULL;
    for (i = 0; i < 4; i++) {
        s21_str = s21_strtok(s0[i], s2[i]);
        str = strtok(s1[i], s2[i]);
        if (str == NULL) {
            ck_assert_ptr_eq(s21_str, s21_NULL);
        } else {
            ck_assert_str_eq(s21_str, str);
            while (str != s21_NULL) {
                s21_str = s21_strtok(s21_NULL, s2[i]);
                str = strtok(NULL, s2[i]);
                if (str == NULL)
                    ck_assert_ptr_eq(s21_str, s21_NULL);
                else
                    ck_assert_str_eq(s21_str, str);
            }
        }
    }
} END_TEST

Suite* strtok_test(void) {
    Suite* suite = suite_create("strtok_test");
    TCase* tcase_core = tcase_create("SIOBHANS");

    tcase_add_test(tcase_core, strtok_test_1);
    tcase_add_test(tcase_core, strtok_test_2);

    suite_add_tcase(suite, tcase_core);

    return suite;
}



START_TEST(strerror_tests) {
    for (int err = -3; err <= 133; err++) {
        ck_assert_str_eq(s21_strerror(err), strerror(err));
    }
} END_TEST

START_TEST(inttostr_tests) {
    char *test = malloc(num_of_digits(0) * sizeof(char));
    test = s21_intToString(test, 0);
    ck_assert_str_eq(test, "0");
    free(test);
} END_TEST

Suite* streror_test(void) {
    Suite* suite = suite_create("streror_test");
    TCase* tcase_core = tcase_create("SIOBHANS");

    tcase_add_test(tcase_core, strerror_tests);
    tcase_add_test(tcase_core, inttostr_tests);

    suite_add_tcase(suite, tcase_core);

    return suite;
}



START_TEST(to_upper_test_1) {
    char str[] = "hello! \n hi!";
    ck_assert_str_eq((char*)s21_to_upper(str), "HELLO! \n HI!");
} END_TEST

START_TEST(to_upper_test_2) {
    char str[] = "Hello, how are you?";
    ck_assert_str_eq((char*)s21_to_upper(str), "HELLO, HOW ARE YOU?");
} END_TEST

START_TEST(to_upper_test_3) {
    char str[] = "HELLO CaP";
    ck_assert_str_eq((char*)s21_to_upper(str), "HELLO CAP");
} END_TEST

START_TEST(to_upper_test_4) {
    char str[] = "Compares two pointers\0";
    ck_assert_str_eq((char*)s21_to_upper(str), "COMPARES TWO POINTERS\0");
} END_TEST

START_TEST(to_upper_test_5) {
    char str[] = "verTER))))))";
    ck_assert_str_eq((char*)s21_to_upper(str), "VERTER))))))");
} END_TEST

Suite* strtoupper_test(void) {
    Suite* suite = suite_create("str_toupper_test");
    TCase* tcase_core = tcase_create("PART 5");

    tcase_add_test(tcase_core, to_upper_test_1);
    tcase_add_test(tcase_core, to_upper_test_2);
    tcase_add_test(tcase_core, to_upper_test_3);
    tcase_add_test(tcase_core, to_upper_test_4);
    tcase_add_test(tcase_core, to_upper_test_5);

    suite_add_tcase(suite, tcase_core);

    return suite;
}



START_TEST(to_lower_test_1) {
    char str[] = "HELLO! \n HI!";
    ck_assert_str_eq((char*)s21_to_lower(str), "hello! \n hi!");
} END_TEST

START_TEST(to_lower_test_2) {
    char str[] = "HELLO, HOW ARE YOU?";
    ck_assert_str_eq((char*)s21_to_lower(str), "hello, how are you?");
} END_TEST

START_TEST(to_lower_test_3) {
    char str[] = "HELLO \0 CaP";
    ck_assert_str_eq((char*)s21_to_lower(str), "hello \0 cap");
} END_TEST

START_TEST(to_lower_test_4) {
    char str[] = "COMPARES TWO POINTERS\0";
    ck_assert_str_eq((char*)s21_to_lower(str), "compares two pointers\0");
} END_TEST

START_TEST(to_lower_test_5) {
    char str[] = "VERTER+))))))";
    ck_assert_str_eq((char*)s21_to_lower(str), "verter+))))))");
} END_TEST

Suite* strtolower_test(void) {
    Suite* suite = suite_create("str_tolower_test");
    TCase* tcase_core = tcase_create("PART 5");

    tcase_add_test(tcase_core, to_lower_test_1);
    tcase_add_test(tcase_core, to_lower_test_2);
    tcase_add_test(tcase_core, to_lower_test_3);
    tcase_add_test(tcase_core, to_lower_test_4);
    tcase_add_test(tcase_core, to_lower_test_5);

    suite_add_tcase(suite, tcase_core);

    return suite;
}


// check
START_TEST(trim_test_1) {
    char charsToTrim[] = {'*', ' ', '\''};
    char* str = "*** Much Ado About Nothing ***";
    char* s21_trim_res = s21_trim(str, charsToTrim);
    ck_assert_str_eq(s21_trim_res, "Much Ado About Nothing");
    free(s21_trim_res);
} END_TEST

START_TEST(trim_test_2) {
    char* s21_trim_res = s21_trim("  G F G", " ");
    ck_assert_str_eq(s21_trim_res, "G F G");
    free(s21_trim_res);
} END_TEST

START_TEST(trim_test_3) {
    char* s21_trim_res = s21_trim(" 1221 ", s21_NULL);
    ck_assert_ptr_eq(s21_trim_res, s21_NULL);
    free(s21_trim_res);
} END_TEST

START_TEST(trim_test_4) {
    char* s21_trim_res = s21_trim("", "7");
    ck_assert_str_eq(s21_trim_res, "");
    free(s21_trim_res);
} END_TEST

START_TEST(trim_test_5) {
    char* s21_trim_res = s21_trim(" 1221 ", " 1");
    ck_assert_str_eq(s21_trim_res, "22");
    free(s21_trim_res);
} END_TEST

Suite* trim_test(void) {
    Suite* suite = suite_create("trim_test");
    TCase* tcase_core = tcase_create("PART 5");

    tcase_add_test(tcase_core, trim_test_1);
    tcase_add_test(tcase_core, trim_test_2);
    tcase_add_test(tcase_core, trim_test_3);
    tcase_add_test(tcase_core, trim_test_4);
    tcase_add_test(tcase_core, trim_test_5);

    suite_add_tcase(suite, tcase_core);

    return suite;
}



START_TEST(insert_test_1) {
    char* s21_insert_res = s21_insert("13", "22", 1);
    ck_assert_str_eq(s21_insert_res, "1223");
    free(s21_insert_res);
} END_TEST

START_TEST(insert_test_2) {
    char* s21_insert_res = s21_insert("13", "2", 1);
    ck_assert_str_eq(s21_insert_res, "123");
    free(s21_insert_res);
} END_TEST

START_TEST(insert_test_3) {
    char* s21_insert_res = s21_insert("", "2", 2);
    ck_assert_ptr_eq(s21_insert_res, s21_NULL);
    free(s21_insert_res);
} END_TEST

START_TEST(insert_test_4) {
    char* s21_insert_res = s21_insert("hello", "", 0);
    ck_assert_str_eq(s21_insert_res, "hello");
    free(s21_insert_res);
} END_TEST

START_TEST(insert_test_5) {
    char* s21_insert_res = s21_insert("hello", "", 6);
    ck_assert_ptr_eq(s21_insert_res, s21_NULL);
    free(s21_insert_res);
} END_TEST

Suite* insert_test(void) {
    Suite* suite = suite_create("insert_test");
    TCase* tcase_core = tcase_create("PART 5");

    tcase_add_test(tcase_core, insert_test_1);
    tcase_add_test(tcase_core, insert_test_2);
    tcase_add_test(tcase_core, insert_test_3);
    tcase_add_test(tcase_core, insert_test_4);
    tcase_add_test(tcase_core, insert_test_5);

    suite_add_tcase(suite, tcase_core);

    return suite;
}
////////////////////////////////////// SIOBHANS



////////////////////////////////////// MARTYBRA
START_TEST(strrchr_test_1) {
    char str[] = "0123456789f1011";
    ck_assert_ptr_eq(s21_strrchr(str, 'f'), strrchr(str, 'f'));
} END_TEST

START_TEST(strrchr_test_2) {
    char str[] = "Hello world\n\0";
    ck_assert_ptr_eq(s21_strrchr(str, 'o'), strrchr(str, 'o'));
} END_TEST

START_TEST(strrchr_test_3) {
    char str[] = "\n\0";
    ck_assert_ptr_eq(s21_strrchr(str, 'n'), strrchr(str, 'n'));
} END_TEST

START_TEST(strrchr_test_4) {
    char str[] = "\0";
    ck_assert_ptr_eq(s21_strrchr(str, '2'), strrchr(str, '2'));
} END_TEST

START_TEST(strrchr_test_5) {
    char str[] = "NU\0LL";
    ck_assert_ptr_eq(s21_strrchr(str, 'L'), strrchr(str, 'L'));
} END_TEST

Suite *strrchr_test(void) {
    Suite *suite = suite_create("strrchr_test");
    TCase *tcase_core = tcase_create("MARTYBRA");

    tcase_add_test(tcase_core, strrchr_test_1);
    tcase_add_test(tcase_core, strrchr_test_2);
    tcase_add_test(tcase_core, strrchr_test_3);
    tcase_add_test(tcase_core, strrchr_test_4);
    tcase_add_test(tcase_core, strrchr_test_5);

    suite_add_tcase(suite, tcase_core);

    return suite;
}



START_TEST(strpbrk_test_1) {
    char str[] = "0123456789";
    char sym[] = "369";
    ck_assert_ptr_eq(s21_strpbrk(str, sym), strpbrk(str, sym));
} END_TEST

START_TEST(strpbrk_test_2) {
    char str[] = "geeksforgeeks";
    char sym[] = "app";
    ck_assert_ptr_eq(s21_strpbrk(str, sym), strpbrk(str, sym));
} END_TEST

START_TEST(strpbrk_test_3) {
    char str[] = "geeksforgeeks\0";
    char sym[] = "kite";
    ck_assert_ptr_eq(s21_strpbrk(str, sym), strpbrk(str, sym));
} END_TEST

START_TEST(strpbrk_test_4) {
    char str[] = "abcde2f\nghi3jk4l";
    char sym[] = "34";
    ck_assert_ptr_eq(s21_strpbrk(str, sym), strpbrk(str, sym));
} END_TEST

START_TEST(strpbrk_test_5) {
    char str[] = "fhdkdleirutfjdkirj rueitueriutier ertuerfudsf sgdfgd";
    char sym[] = "vbn";
    ck_assert_ptr_eq(s21_strpbrk(str, sym), strpbrk(str, sym));
} END_TEST

Suite *strpbrk_test(void) {
    Suite *suite = suite_create("strpbrk_test");
    TCase *tcase_core = tcase_create("MARTYBRA");

    tcase_add_test(tcase_core, strpbrk_test_1);
    tcase_add_test(tcase_core, strpbrk_test_2);
    tcase_add_test(tcase_core, strpbrk_test_3);
    tcase_add_test(tcase_core, strpbrk_test_4);
    tcase_add_test(tcase_core, strpbrk_test_5);

    suite_add_tcase(suite, tcase_core);

    return suite;
}



START_TEST(strspn_test_1) {
    char str[] = "0123456789";
    char sym[] = "210";
    ck_assert_uint_eq(s21_strspn(str, sym), strspn(str, sym));
} END_TEST

START_TEST(strspn_test_2) {
    char str[] = "geeks for geeks";
    char sym[] = "geek";
    ck_assert_uint_eq(s21_strspn(str, sym), strspn(str, sym));
} END_TEST

START_TEST(strspn_test_3) {
    char str[] = "i am";
    char sym[] = "xyz";
    ck_assert_uint_eq(s21_strspn(str, sym), strspn(str, sym));
} END_TEST

START_TEST(strspn_test_4) {
    char str[] = "129th";
    char sym[] = "1234567890";
    ck_assert_uint_eq(s21_strspn(str, sym), strspn(str, sym));
} END_TEST

START_TEST(strspn_test_5) {
    char str[] = "01234\056789";
    char sym[] = "190126abqs121kfew";
    ck_assert_uint_eq(s21_strspn(str, sym), strspn(str, sym));
} END_TEST

Suite *strspn_test(void) {
    Suite *suite = suite_create("strspn_test");
    TCase *tcase_core = tcase_create("MARTYBRA");

    tcase_add_test(tcase_core, strspn_test_1);
    tcase_add_test(tcase_core, strspn_test_2);
    tcase_add_test(tcase_core, strspn_test_3);
    tcase_add_test(tcase_core, strspn_test_4);
    tcase_add_test(tcase_core, strspn_test_5);

    suite_add_tcase(suite, tcase_core);

    return suite;
}


// check
START_TEST(strstr_test_1) {
    char str1[] = "0123456789";
    char str2[] = "345";
    ck_assert_ptr_eq(s21_strstr(str1, str2), strstr(str1, str2));
} END_TEST

START_TEST(strstr_test_2) {
    char str1[] = "Fun with STL";
    char str2[] = "";
    ck_assert_ptr_eq(s21_strstr(str1, str2), strstr(str1, str2));
} END_TEST

START_TEST(strstr_test_3) {
    char str1[] = "STL";
    char str2[] = "";
    ck_assert_ptr_eq(s21_strstr(str1, str2), strstr(str1, str2));
} END_TEST

START_TEST(strstr_test_4) {
    char str1[] = "TutorialsPoint";
    char str2[] = "Point";
    ck_assert_ptr_eq(s21_strstr(str1, str2), strstr(str1, str2));
} END_TEST

START_TEST(strstr_test_5) {
    char str1[] = "This is a simple string";
    char str2[] = "simple";
    ck_assert_ptr_eq(s21_strstr(str1, str2), strstr(str1, str2));
} END_TEST

Suite *strstr_test(void) {
    Suite *suite = suite_create("strstr_test");
    TCase *tcase_core = tcase_create("MARTYBRA");

    tcase_add_test(tcase_core, strstr_test_1);
    tcase_add_test(tcase_core, strstr_test_2);
    tcase_add_test(tcase_core, strstr_test_3);
    tcase_add_test(tcase_core, strstr_test_4);
    tcase_add_test(tcase_core, strstr_test_5);

    suite_add_tcase(suite, tcase_core);

    return suite;
}
////////////////////////////////////// MARTYBRA



////////////////////////////////////// VIOLINMO
START_TEST(memcpy_test_1) {
    char dst[15] = "";
    char src[15] = "1234567890";
    ck_assert_ptr_eq(s21_memcpy(dst, src, 6), memcpy(dst, src, 6));
} END_TEST

START_TEST(memcpy_test_2) {
    char src[50] = "privet vsem raz dva tri";
    char dst[50] = "Odin/Odin";
    ck_assert_ptr_eq(s21_memcpy(dst, src, s21_strlen(dst) + 1), memcpy(dst, src, strlen(src) + 1));
} END_TEST

START_TEST(memcpy_test_3) {
    char dst[10] = "";
    char src[16] = "Pierre de Fermat";
    ck_assert_ptr_eq(s21_memcpy(dst, src, 10), memcpy(dst, src, 10));
} END_TEST

START_TEST(memcpy_test_4) {
    char dst[] = "";
    char src[] = "Gao Lao Shi\0Ting Li";
    ck_assert_ptr_eq(s21_memcpy(dst, src, sizeof(dst)), memcpy(dst, src, sizeof(dst)));
} END_TEST

START_TEST(memcpy_test_5) {
    char dst[20] = "";
    char src[20] = "raz fva tri \n aga";
    ck_assert_ptr_eq(s21_memcpy(dst, src, 15), memcpy(dst, src, 15));
} END_TEST

Suite *memcpy_test(void) {
    Suite *suite = suite_create("memcpy_test");
    TCase *tcase_core = tcase_create("VIOLINMO");

    tcase_add_test(tcase_core, memcpy_test_1);
    tcase_add_test(tcase_core, memcpy_test_2);
    tcase_add_test(tcase_core, memcpy_test_3);
    tcase_add_test(tcase_core, memcpy_test_4);
    tcase_add_test(tcase_core, memcpy_test_5);

    suite_add_tcase(suite, tcase_core);

    return suite;
}



START_TEST(memcmp_test_1) {
    unsigned char str1[15] = "1234567890";
    unsigned char str2[15] = "1234567890";
    ck_assert_int_eq(s21_memcmp(str1, str2, 10), memcmp(str1, str2, 10));
} END_TEST

START_TEST(memcmp_test_2) {
    unsigned char str1[15] = "09876";
    unsigned char str2[15] = "0987654321";
    ck_assert_int_eq(s21_memcmp(str1, str2, 5), memcmp(str1, str2, 5));
} END_TEST

START_TEST(memcmp_test_3) {
    unsigned char str1[10] = "1a2b3c";
    unsigned char str2[10] = "1a2b";
    ck_assert_int_eq(s21_memcmp(str1, str2, 4), memcmp(str1, str2, 4));
} END_TEST

START_TEST(memcmp_test_4) {
    unsigned char str1[10] = "1a2b3c";
    unsigned char str2[10] = "1a2b";
    ck_assert_int_eq(s21_memcmp(str1, str2, 4), memcmp(str1, str2, 4));
} END_TEST

START_TEST(memcmp_test_5) {
    unsigned char str1[10] = "1ab2g4y";
    unsigned char str2[10] = "1ab2g4y";
    ck_assert_int_eq(s21_memcmp(str1, str2, 4), memcmp(str1, str2, 4));
} END_TEST

Suite *memcmp_test(void) {
    Suite *suite = suite_create("memcmp_test");
    TCase *tcase_core = tcase_create("VIOLINMO");

    tcase_add_test(tcase_core, memcmp_test_1);
    tcase_add_test(tcase_core, memcmp_test_2);
    tcase_add_test(tcase_core, memcmp_test_3);
    tcase_add_test(tcase_core, memcmp_test_4);
    tcase_add_test(tcase_core, memcmp_test_5);

    suite_add_tcase(suite, tcase_core);

    return suite;
}



START_TEST(memchr_test_1) {
    char str[] = "Example string";
    ck_assert_ptr_eq(s21_memchr(str, 'p', s21_strlen(str)), memchr(str, 'p', strlen(str)));
} END_TEST

START_TEST(memchr_test_2) {
    char str[] = "ABCDEFG";
    char c = 'D';
    ck_assert_ptr_eq(s21_memchr(str, c, s21_strlen(str)), memchr(str, c, strlen(str)));
} END_TEST

START_TEST(memchr_test_3) {
    char str[] = "1234567890";
    char c = '4';
    ck_assert_ptr_eq(s21_memchr(str, c, 10), memchr(str, c, 10));
} END_TEST

START_TEST(memchr_test_4) {
    char str[] = "Learn C from School 21";
    char c = 'S';
    ck_assert_ptr_eq(s21_memchr(str, c, s21_strlen(str)), memchr(str, c, strlen(str)));
} END_TEST

START_TEST(memchr_test_5) {
    char str[] = "Born to\0 code\n";
    char c = 'r';
    ck_assert_ptr_eq(s21_memchr(str, c, 5), memchr(str, c, 5));
} END_TEST

Suite *memchr_test(void) {
    Suite *suite = suite_create("memchr_test");
    TCase *tcase_core = tcase_create("VIOLINMO");

    tcase_add_test(tcase_core, memchr_test_1);
    tcase_add_test(tcase_core, memchr_test_2);
    tcase_add_test(tcase_core, memchr_test_3);
    tcase_add_test(tcase_core, memchr_test_4);
    tcase_add_test(tcase_core, memchr_test_5);

    suite_add_tcase(suite, tcase_core);

    return suite;
}



START_TEST(memmove_test_1) {
    char dest[20] = "\0";
    char src[20] = "1234567890";
    ck_assert_ptr_eq(s21_memmove(dest, src, 6), memmove(dest, src, 6));
} END_TEST

START_TEST(memmove_test_2) {
    char dest[20] = "Tests";
    char src[20] = "Fails";
    ck_assert_ptr_eq(s21_memmove(dest, src, sizeof(src)), memmove(dest, src, sizeof(src)));
} END_TEST

START_TEST(memmove_test_3) {
    char dest[50] = "memmove can be very useful......";
    char src[15] = "CAN";
    ck_assert_ptr_eq(s21_memmove(dest, src, 15), memmove(dest, src, 15));
} END_TEST

START_TEST(memmove_test_4) {
    int arr[10] = {8, 3, 11, 61, -22, 7, -6, 2, 13, 47};
    int *new_arr = &arr[5];
    ck_assert_ptr_eq(s21_memmove(new_arr, arr, sizeof(int) * 5), memmove(new_arr, arr, sizeof(int)));
} END_TEST

START_TEST(memmove_test_5) {
    char str[] = "123457890";
    ck_assert_ptr_eq(s21_memmove(str + 4, str + 3, 3), memmove(str + 4, str + 3, 3));
} END_TEST


Suite *memmove_test(void) {
    Suite *suite = suite_create("memmove_test");
    TCase *tcase_core = tcase_create("VIOLINMO");

    tcase_add_test(tcase_core, memmove_test_1);
    tcase_add_test(tcase_core, memmove_test_2);
    tcase_add_test(tcase_core, memmove_test_3);
    tcase_add_test(tcase_core, memmove_test_4);
    tcase_add_test(tcase_core, memmove_test_5);

    suite_add_tcase(suite, tcase_core);

    return suite;
}
////////////////////////////////////// VIOLINMO



////////////////////////////////////// FRANCINE
START_TEST(strchr_test_1) {
    char str[] = "1234567890";
    ck_assert_ptr_eq(s21_strchr(str, 0), strchr(str, 0));
} END_TEST

START_TEST(strchr_test_2) {
    char* empty_str = "";
    ck_assert_ptr_eq(s21_strchr(empty_str, 'b'), strchr(empty_str, 'b'));
} END_TEST

START_TEST(strchr_test_3) {
    char str[] = "This is a sample string";
    ck_assert_ptr_eq(s21_strchr(str, 's'), strchr(str, 's'));
} END_TEST

START_TEST(strchr_test_4) {
    char str[6] = "abcdbc";
    ck_assert_ptr_eq(s21_strchr(str, 'b'), strchr(str, 'b'));
} END_TEST

START_TEST(strchr_test_5) {
    char str[11] = "0123456789";
    ck_assert_ptr_eq(s21_strchr(str, '6'), strchr(str, '6'));
} END_TEST


Suite* strchr_test(void) {
    Suite* suite = suite_create("strchr_test");
    TCase* tcase_core = tcase_create("FRANCINE");

    tcase_add_test(tcase_core, strchr_test_1);
    tcase_add_test(tcase_core, strchr_test_2);
    tcase_add_test(tcase_core, strchr_test_3);
    tcase_add_test(tcase_core, strchr_test_4);
    tcase_add_test(tcase_core, strchr_test_5);

    suite_add_tcase(suite, tcase_core);

    return suite;
}



START_TEST(strcat_test_1) {
    char str1[10] = "11341";
    char str2[10] = "11341";
    char str3[5] = "34";
    s21_strcat(str1, str3);
    strcat(str2, str3);
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(strcat_test_2) {
    char str1[30] = "first string";
    char str2[30] = "first string";
    char str3[] = "second string";
    s21_strcat(str1, str3);
    strcat(str2, str3);
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(strcat_test_3) {
    char str1[50] = "Learning C is fun";
    char str2[50] = "Learning C is fun";
    char str3[] = "and\n easy";
    s21_strcat(str1, str3);
    strcat(str2, str3);
    ck_assert_str_eq(str1, str2);
} END_TEST

START_TEST(strcat_test_4) {
    char str[10], s21_str[10];
    for (int i = 0; i < 10; i++) {
        str[i] = '\0';
        s21_str[i] = '\0';
    }
    ck_assert_str_eq(s21_strcat(s21_str, ""), strcat(str, ""));
    ck_assert_str_eq(s21_strcat(s21_str, "d"), strcat(str, "d"));
} END_TEST

START_TEST(strcat_test_5) {
    char str1[80];
    char str2[80];
    s21_strcpy(str1, "these ");
    s21_strcat(str1, "strings ");
    s21_strcat(str1, "are ");
    s21_strcat(str1, "concatenated.");

    strcpy(str2, "these ");
    strcat(str2, "strings ");
    strcat(str2, "are ");
    strcat(str2, "concatenated.");

    ck_assert_str_eq(str1, str2);
} END_TEST


Suite* strcat_test(void) {
    Suite* suite = suite_create("strcat_test");
    TCase* tcase_core = tcase_create("FRANCINE");

    tcase_add_test(tcase_core, strcat_test_1);
    tcase_add_test(tcase_core, strcat_test_2);
    tcase_add_test(tcase_core, strcat_test_3);
    tcase_add_test(tcase_core, strcat_test_4);
    tcase_add_test(tcase_core, strcat_test_5);

    suite_add_tcase(suite, tcase_core);

    return suite;
}



START_TEST(strncat_tests) {
    char str1[10], str2[10];
    for (int i = 0; i < 10; i++) {
        str1[i] = '\0';
        str2[i] = '\0';
    }
    ck_assert_str_eq(s21_strncat(str1, "1z", 3), strncat(str2, "1z", 3));
    ck_assert_str_eq(s21_strncat(str1, "vv", 1), strncat(str2, "vv", 1));
    ck_assert_str_eq(s21_strncat(str1, "", 0), strncat(str2, "", 0));
} END_TEST

Suite* strncat_test(void) {
    Suite* suite = suite_create("strncat_test");
    TCase* tcase_core = tcase_create("FRANCINE");

    tcase_add_test(tcase_core, strncat_tests);

    suite_add_tcase(suite, tcase_core);

    return suite;
}


START_TEST(strcspn_test_1) {
    char str1[10] = "123456";
    char str2[10] = "7890";
    ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
} END_TEST

START_TEST(strcspn_test_2) {
    char str1[10] = "";
    char str2[10] = "";
    ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
} END_TEST

START_TEST(strcspn_test_3) {
    ck_assert_uint_eq(s21_strcspn("biba111boba", ""), strcspn("biba111boba", ""));
} END_TEST

START_TEST(strcspn_test_4) {
    ck_assert_uint_eq(s21_strcspn("", "O"), strcspn("", "O"));
} END_TEST

START_TEST(strcspn_test_5) {
    char str1[10] = "1234567890";
    char str2[10] = "7890";
    ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
} END_TEST

Suite* strcspn_test(void) {
    Suite* suite = suite_create("strcspn_test");
    TCase* tcase_core = tcase_create("FRANCINE");

    tcase_add_test(tcase_core, strcspn_test_1);
    tcase_add_test(tcase_core, strcspn_test_2);
    tcase_add_test(tcase_core, strcspn_test_3);
    tcase_add_test(tcase_core, strcspn_test_4);
    tcase_add_test(tcase_core, strcspn_test_5);

    suite_add_tcase(suite, tcase_core);

    return suite;
}
////////////////////////////////////// FRANCINE


/* SPRINTF */
START_TEST(sprintf_test_1) {
    char r[200] = "";
    char output[200] = "";
    char *a = NULL;
    sprintf(r, "\n");
    s21_sprintf(output, "\n");
    ck_assert_str_eq(output, r);
} END_TEST

START_TEST(sprintf_test_2) {
    char output[200] = "";
    char s21_output[200] = "";
    sprintf(output, "A");
    s21_sprintf(s21_output, "A");
    ck_assert_str_eq(s21_output, output);
} END_TEST

START_TEST(sprintf_test_3) {
    char output[200] = "";
    char s21_output[200] = "";
    unsigned int cout = 1000;
    sprintf(output, "%.15f %d %3u %-s", 3.765, 6, cout, "Hello");
    s21_sprintf(s21_output, "%.15f %d %3u %-s", 3.765, 6, cout, "Hello");
    ck_assert_str_eq(s21_output, output);
} END_TEST

START_TEST(printf_cTest_4) {
    short length = 100;
    char *s21_output = calloc(length, sizeof(char));
    char *output = calloc(length, sizeof(char));
    int s21_res = 0, res = 0;
    unsigned long int a = '#';
    s21_res = s21_sprintf(s21_output, "%c %c %lc %%", ' ', '@', a);
    res = sprintf(output, "%c %c %lc %%", ' ', '@', a);
    ck_assert_str_eq(s21_output, output);
    ck_assert_int_eq(s21_res, res);
    free(s21_output);
    free(output);
}
END_TEST

START_TEST(printf_dTest_5) {
    short length = 100;
    char *s21_output = calloc(length, sizeof(char));
    char *output = calloc(length, sizeof(char));
    int s21_res = 0, res = 0;
    long int n = 3;
    s21_res = s21_sprintf(s21_output, "%ld%3c  % d   %+d %d%-2.d", n, 'A', 5, 7, 3, 3);
    res = sprintf(output, "%ld%3c  % d   %+d %d%-2.d", n, 'A', 5, 7, 3, 3);
    ck_assert_str_eq(s21_output, output);
    ck_assert_int_eq(s21_res, res);
    free(s21_output);
    free(output);
}
END_TEST


START_TEST(printf_iTest_6) {
    short length = 100;
    char *s21_output = calloc(length, sizeof(char));
    char *output = calloc(length, sizeof(char));
    int s21_res = 0, res = 0;
    short int n = 11;
    s21_res = s21_sprintf(s21_output, "%hi %.5i %0i", n, -46, 57);
    res = sprintf(output, "%hi %.5i %0i", n, -46, 57);
    ck_assert_str_eq(s21_output, output);
    ck_assert_int_eq(s21_res, res);
    free(s21_output);
    free(output);
}
END_TEST


START_TEST(printf_sTest_7) {
    short length = 100;
    char *s21_output = calloc(length, sizeof(char));
    char *output = calloc(length, sizeof(char));
    int s21_res = 0, res = 0;
    s21_res = s21_sprintf(s21_output, "%-2s %.3s %s %ls", "Hello", " world", "!", "ABC");
    res = sprintf(output, "%-2s %.3s %s ", "Hello", " world", "!");
    ck_assert_str_eq(s21_output, output);
    ck_assert_int_eq(s21_res, res);
    free(s21_output);
    free(output);
}
END_TEST

START_TEST(printf_uTest_8) {
    short length = 100;
    char *s21_output = calloc(length, sizeof(char));
    char *output = calloc(length, sizeof(char));
    int s21_res = 0, res = 0;
    unsigned short n = 2;
    unsigned long m = 33;
    s21_res = s21_sprintf(s21_output, "%hu %lu %u", n, m, (unsigned)58432322);
    res = sprintf(output, "%hu %lu %u", n, m, (unsigned)58432322);
    ck_assert_str_eq(s21_output, output);
    ck_assert_int_eq(s21_res, res);
    free(s21_output);
    free(output);
}
END_TEST


Suite* sprintf_test(void) {
    Suite* suite = suite_create("sprintf_test");
    TCase* tcase_core = tcase_create("PART 3");

    tcase_add_test(tcase_core, sprintf_test_1);
    tcase_add_test(tcase_core, sprintf_test_2);
    tcase_add_test(tcase_core, sprintf_test_3);
    tcase_add_test(tcase_core, printf_cTest_4);
    tcase_add_test(tcase_core, printf_dTest_5);
    tcase_add_test(tcase_core, printf_iTest_6);
    tcase_add_test(tcase_core, printf_sTest_7);
    tcase_add_test(tcase_core, printf_uTest_8);

    suite_add_tcase(suite, tcase_core);

    return suite;
}
/* SPRINTF */



/* MAIN */
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
    Suite* (*tests[25])() = {strcmp_test, strcpy_test, strncmp_test,
        strncpy_test, strlen_test, memset_test, streror_test, strtok_test,
        strtoupper_test, strtolower_test, strrchr_test, strpbrk_test,
        strspn_test, strstr_test, memcpy_test, memcmp_test, memchr_test,
        memmove_test, trim_test, insert_test, strchr_test, strcat_test,
        strncat_test, strcspn_test, sprintf_test};
    if (set_fails(tests, 25) != 0) {
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
/* MAIN */

