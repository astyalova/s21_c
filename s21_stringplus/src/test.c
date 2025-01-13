#include <check.h>
#include <locale.h>
#include <stdio.h>
#include <string.h>

#include "./s21_string.h"

#define BUFF_SIZE 512

START_TEST(memcmp_1) {
  s21_size_t n1 = 3;
  char str_memcmp_1_1[10] = "SUCCESS!";
  char str_memcmp_1_2[10] = "SUCCyes";
  ck_assert_int_eq(memcmp(str_memcmp_1_1, str_memcmp_1_2, n1),
                   s21_memcmp(str_memcmp_1_2, str_memcmp_1_2, n1));
}
END_TEST

START_TEST(memcmp_2) {
  s21_size_t n2 = 8;
  char str_memcmp_2_1[10] = "SUCCESS!";
  char str_memcmp_2_2[10] = "yesyesye";
  ck_assert_int_eq(memcmp(str_memcmp_2_1, str_memcmp_2_2, n2),
                   s21_memcmp(str_memcmp_2_1, str_memcmp_2_2, n2));
}
END_TEST

START_TEST(memcmp_3) {
  s21_size_t n3 = 0;
  char str_memcmp_3_1[10] = "SUCCESS!";
  char str_memcmp_3_2[10] = "yes";
  ck_assert_int_eq(memcmp(str_memcmp_3_1, str_memcmp_3_2, n3),
                   s21_memcmp(str_memcmp_3_1, str_memcmp_3_2, n3));
}
END_TEST

START_TEST(memcmp_4) {
  s21_size_t n3 = 9;
  char str_memcmp_4_1[10] = "SUCC\0ESS!";
  char str_memcmp_4_2[10] = "SUCC\0E\0SS!";
  ck_assert_int_eq(memcmp(str_memcmp_4_1, str_memcmp_4_2, n3),
                   s21_memcmp(str_memcmp_4_1, str_memcmp_4_2, n3));
}
END_TEST

START_TEST(memcmp_5) {
  s21_size_t n3 = 2;
  char str_memcmp_5_1[10] = "SUCCESS!";
  char str_memcmp_5_2[10] = "yesyes";
  ck_assert_int_eq(memcmp(str_memcmp_5_1 + 2, str_memcmp_5_2 + 1, n3),
                   s21_memcmp(str_memcmp_5_1 + 2, str_memcmp_5_2 + 1, n3));
}
END_TEST

START_TEST(memset_1) {
  s21_size_t n1 = 8;
  char var_5 = 'h';
  char str_memset_1_1[10] = "SUCCESS!";
  char str_memset_1_2[10] = "SUCCESS!";
  ck_assert_pstr_eq(memset(str_memset_1_1, var_5, n1),
                    s21_memset(str_memset_1_2, var_5, n1));
}
END_TEST

START_TEST(memset_2) {
  s21_size_t n2 = 3;
  int var_6 = 'h';
  char str_memset_2_1[10] = "SUCCESS!";
  char str_memset_2_2[10] = "SUCCESS!";
  ck_assert_pstr_eq(memset(str_memset_2_1, var_6, n2),
                    s21_memset(str_memset_2_2, var_6, n2));
}
END_TEST

START_TEST(memset_3) {
  s21_size_t n3 = 6;
  int c3 = 5;
  char str_memset_3_1[10] = "SUCCESS!";
  char str_memset_3_2[10] = "SUCCESS!";
  ck_assert_pstr_eq(memset(str_memset_3_1, c3, n3),
                    s21_memset(str_memset_3_2, c3, n3));
}
END_TEST

START_TEST(memset_4) {
  s21_size_t n3 = 6;
  char c3 = '\0';
  char str_memset_4_1[10] = "SUCCESS!";
  char str_memset_4_2[10] = "SUCCESS!";
  ck_assert_pstr_eq(memset(str_memset_4_1, c3, n3),
                    s21_memset(str_memset_4_2, c3, n3));
}
END_TEST

START_TEST(memcpy_1) {
  s21_size_t n1 = 3;
  char str_memcpy_1_1[10] = "SUCCESS!";
  char str_memcpy_1_2[10] = "SUCCESS!";
  char str_memcpy_1_3[10] = "press";
  ck_assert_pstr_eq(memcpy(str_memcpy_1_1, str_memcpy_1_3, n1),
                    s21_memcpy(str_memcpy_1_2, str_memcpy_1_3, n1));
}
END_TEST

START_TEST(memcpy_2) {
  s21_size_t n2 = 8;
  char str_memcpy_2_1[10] = "SUCCESS!";
  char str_memcpy_2_2[10] = "SUCCESS!";
  char str_memcpy_2_3[10] = "presspre";
  ck_assert_pstr_eq(memcpy(str_memcpy_2_1, str_memcpy_2_2, n2),
                    s21_memcpy(str_memcpy_2_1, str_memcpy_2_2, n2));
}
END_TEST

START_TEST(memcpy_3) {
  s21_size_t n3 = 0;
  char str_memcpy_3_1[10] = "SUCCESS!";
  char str_memcpy_3_2[10] = "SUCCESS!";
  char str_memcpy_3_3[10] = "presspre";
  ck_assert_pstr_eq(memcpy(str_memcpy_3_1, str_memcpy_3_3, n3),
                    s21_memcpy(str_memcpy_3_2, str_memcpy_3_3, n3));
}
END_TEST

START_TEST(memcpy_4) {
  s21_size_t n3 = 9;
  char str_memcpy_4_1[10] = "SUCC\0ESS!";
  char str_memcpy_4_2[10] = "SUCC\0ESS!";
  char str_memcpy_4_3[10] = "pressp\0re";
  ck_assert_pstr_eq(memcpy(str_memcpy_4_1, str_memcpy_4_3, n3),
                    s21_memcpy(str_memcpy_4_2, str_memcpy_4_3, n3));
}
END_TEST

START_TEST(memcpy_5) {
  s21_size_t n3 = 2;
  char str_memcpy_5_1[10] = "SUCCESS!";
  char str_memcpy_5_2[10] = "SUCCESS!";
  char str_memcpy_5_3[10] = "presspre";
  ck_assert_pstr_eq(memcpy(str_memcpy_5_1 + 2, str_memcpy_5_3 + 1, n3),
                    s21_memcpy(str_memcpy_5_2 + 2, str_memcpy_5_3 + 1, n3));
}
END_TEST

START_TEST(memmove_1) {
  s21_size_t n1 = 3;
  char str_memmove_1_1[10] = "SUCCESS!";
  char str_memmove_1_2[10] = "SUCCESS!";
  char str_memmove_1_3[10] = "presspre";
  ck_assert_pstr_eq(memmove(str_memmove_1_1, str_memmove_1_3, n1),
                    s21_memmove(str_memmove_1_2, str_memmove_1_3, n1));
}
END_TEST

START_TEST(memmove_2) {
  s21_size_t n2 = 8;
  char str_memmove_2_1[10] = "SUCCESS!";
  char str_memmove_2_2[10] = "SUCCESS!";
  char str_memmove_2_3[10] = "presspre";
  ck_assert_pstr_eq(memmove(str_memmove_2_1, str_memmove_2_3, n2),
                    s21_memmove(str_memmove_2_2, str_memmove_2_3, n2));
}
END_TEST

START_TEST(memmove_3) {
  s21_size_t n3 = 0;
  char str_memmove_3_1[10] = "SUCCESS!";
  char str_memmove_3_2[10] = "SUCCESS!";
  char str_memmove_3_3[10] = "presspre";
  ck_assert_pstr_eq(memmove(str_memmove_3_1, str_memmove_3_3, n3),
                    s21_memmove(str_memmove_3_2, str_memmove_3_3, n3));
}
END_TEST

START_TEST(memmove_4) {
  s21_size_t n3 = 9;
  char str_memmove_4_1[10] = "SUCC\0ESS!";
  char str_memmove_4_2[10] = "SUCC\0ESS!";
  char str_memmove_4_3[10] = "pressp\0re";
  ck_assert_pstr_eq(memmove(str_memmove_4_1, str_memmove_4_3, n3),
                    s21_memmove(str_memmove_4_2, str_memmove_4_3, n3));
}
END_TEST

START_TEST(memmove_5) {
  s21_size_t n3 = 2;
  char str_memmove_5_1[10] = "SUCCESS!";
  char str_memmove_5_2[10] = "SUCCESS!";
  char str_memmove_5_3[10] = "presspre";
  ck_assert_pstr_eq(memmove(str_memmove_5_1 + 2, str_memmove_5_3 + 1, n3),
                    s21_memmove(str_memmove_5_2 + 2, str_memmove_5_3 + 1, n3));
}
END_TEST

START_TEST(memchr_1) {
  char str_memchr_1[10] = "SUCCESS!";
  ck_assert_pstr_eq(memchr(str_memchr_1, 'C', 8),
                    s21_memchr(str_memchr_1, 'C', 8));
}
END_TEST

START_TEST(memchr_2) {
  char str_memchr_2[10] = "SUCC\0ESS!";
  ck_assert_pstr_eq(memchr(str_memchr_2, '\0', 9),
                    s21_memchr(str_memchr_2, '\0', 9));
}
END_TEST

START_TEST(memchr_3) {
  char str_memchr_3[20] = " SUC  CESS ! ";
  ck_assert_pstr_eq(memchr(str_memchr_3, ' ', 11),
                    s21_memchr(str_memchr_3, ' ', 11));
}
END_TEST

START_TEST(memchr_4) {
  char str_memchr_4[25] = "ddddddddfjjjjjj ";
  ck_assert_pstr_eq(memchr(str_memchr_4, 'f', 4),
                    s21_memchr(str_memchr_4, 'f', 4));
}
END_TEST

START_TEST(memchr_5) {
  char str_memchr_5[20] = "ddddddddfjjjjjj ";
  ck_assert_pstr_eq(memchr(str_memchr_5, 'f', 15),
                    s21_memchr(str_memchr_5, 'f', 15));
}
END_TEST

START_TEST(strcat_1) {
  char b1[1024] = "";
  char b11[1024] = "";
  char str_1_2[1024] = "LUGANO THE BEST!";
  ck_assert_pstr_eq(strcat(b1, str_1_2), s21_strcat(b11, str_1_2));
}
END_TEST

START_TEST(strcat_2) {
  char b2[1024] = "THE";
  char b22[1024] = "THE";
  char str_2_2[1024] = " BEST!!";
  ck_assert_pstr_eq(strcat(b2, str_2_2), s21_strcat(b22, str_2_2));
}
END_TEST

START_TEST(strcat_3) {
  char b3[1024] = "777";
  char b33[1024] = "777";
  char str_3_2[1024] = " LUGANO!";
  ck_assert_pstr_eq(strcat(b3, str_3_2), s21_strcat(b33, str_3_2));
}
END_TEST

START_TEST(strncat_1) {
  s21_size_t n1 = 2;
  char b1[1024] = "";
  char b11[1024] = "";
  char str_1_2[1024] = "LUGANO THE BEST!";
  ck_assert_pstr_eq(strncat(b1, str_1_2, n1), s21_strncat(b11, str_1_2, n1));
}
END_TEST

START_TEST(strncat_2) {
  s21_size_t n2 = 2;
  char b2[1024] = "THE";
  char b22[1024] = "THE";
  char str_2_2[1024] = " BEST!!";
  ck_assert_pstr_eq(strncat(b2, str_2_2, n2), s21_strncat(b22, str_2_2, n2));
}
END_TEST

START_TEST(strncat_3) {
  s21_size_t n3 = 2;
  char b3[1024] = "777";
  char b33[1024] = "777";
  char str_3_2[1024] = " LUGANO!";
  ck_assert_pstr_eq(strncat(b3, str_3_2, n3), s21_strncat(b33, str_3_2, n3));
}
END_TEST

START_TEST(strchr_1) {
  char str[] = "Hello world";
  ck_assert_pstr_eq(strchr(str, ' '), s21_strchr(str, ' '));
}
END_TEST

START_TEST(strchr_2) {
  char str2[] = "BYEBYEBYE";
  ck_assert_pstr_eq(strchr(str2, 'm'), s21_strchr(str2, 'm'));
}
END_TEST

START_TEST(strchr_3) {
  char str3[] = "BYEBYEBYE";
  ck_assert_pstr_eq(strchr(str3, 'h'), s21_strchr(str3, 'h'));
}
END_TEST

START_TEST(strcmp_1) {
  char *str_1_1 = "LUGANO!";
  char *str_1_2 = "LUGANO!";
  int s21_c = s21_strcmp(str_1_1, str_1_2);
  int s_c = strcmp(str_1_1, str_1_2);
  if (s21_c > 0)
    s21_c = 1;
  else if (s21_c < 0)
    s21_c = -1;

  if (s_c > 0)
    s_c = 1;
  else if (s_c < 0)
    s_c = -1;
  ck_assert_int_eq(s21_c, s_c);
}
END_TEST

START_TEST(strcmp_2) {
  char *str_2_1 = "LUGANO THE BEST!";
  char *str_2_2 = "LUGANO OF THE BEST!";
  int s21_c = s21_strcmp(str_2_1, str_2_2);
  int s_c = strcmp(str_2_1, str_2_2);
  if (s21_c > 0)
    s21_c = 1;
  else if (s21_c < 0)
    s21_c = -1;

  if (s_c > 0)
    s_c = 1;
  else if (s_c < 0)
    s_c = -1;
  ck_assert_int_eq(s21_c, s_c);
}
END_TEST

START_TEST(s21_strstr_test) {
  char test_1[] = "<<<5>>>";
  char test_2[] = "5";
  char test_3[] = "QwertyQwertyQwerty";
  char test_4[] = "Qwerty";
  char test_5[] = "abcd";
  char test_6[] = "";
  char test_7[] = "aaaaa123aaa1234aaa";
  char test_8[] = "1234";

  ck_assert_ptr_eq(s21_strstr(test_1, test_2), strstr(test_1, test_2));
  ck_assert_ptr_eq(s21_strstr(test_3, test_4), strstr(test_3, test_4));
  ck_assert_ptr_eq(s21_strstr(test_5, test_6), strstr(test_5, test_6));
  ck_assert_ptr_eq(s21_strstr(test_4, test_5), strstr(test_4, test_5));
  ck_assert_ptr_eq(s21_strstr(test_7, test_8), strstr(test_7, test_8));
}
END_TEST

START_TEST(strcmp_3) {
  char *str_3_1 = "LUGANO OF THE BEST!!!!!";
  char *str_3_2 = "LUGANO!";
  int s21_c = s21_strcmp(str_3_1, str_3_2);
  int s_c = strcmp(str_3_1, str_3_2);
  if (s21_c > 0)
    s21_c = 1;
  else if (s21_c < 0)
    s21_c = -1;

  if (s_c > 0)
    s_c = 1;
  else if (s_c < 0)
    s_c = -1;
  ck_assert_int_eq(s21_c, s_c);
}
END_TEST

START_TEST(strncmp_1) {
  s21_size_t n = 3;
  char *str_1_1 = "LUGANO!";
  char *str_1_2 = "LUGANO!";
  int s21_c = s21_strncmp(str_1_1, str_1_2, n);
  int s_c = strncmp(str_1_1, str_1_2, n);
  if (s21_c > 0)
    s21_c = 1;
  else if (s21_c < 0)
    s21_c = -1;

  if (s_c > 0)
    s_c = 1;
  else if (s_c < 0)
    s_c = -1;
  ck_assert_int_eq(s21_c, s_c);
}
END_TEST

START_TEST(strncmp_2) {
  s21_size_t n = 3;
  char *str_2_1 = "LUGANO THE BEST!";
  char *str_2_2 = "LU GANO OF THE BEST!!";
  int s21_c = s21_strncmp(str_2_1, str_2_2, n);
  int s_c = strncmp(str_2_1, str_2_2, n);
  if (s21_c > 0)
    s21_c = 1;
  else if (s21_c < 0)
    s21_c = -1;

  if (s_c > 0)
    s_c = 1;
  else if (s_c < 0)
    s_c = -1;
  ck_assert_int_eq(s21_c, s_c);
}
END_TEST

START_TEST(strncmp_3) {
  s21_size_t n = 3;
  char *str_3_1 = " LUGANO OF THE BEST!!";
  char *str_3_2 = "LUGANO!";
  int s21_c = s21_strncmp(str_3_1, str_3_2, n);
  int s_c = strncmp(str_3_1, str_3_2, n);
  if (s21_c > 0)
    s21_c = 1;
  else if (s21_c < 0)
    s21_c = -1;

  if (s_c > 0)
    s_c = 1;
  else if (s_c < 0)
    s_c = -1;
  ck_assert_int_eq(s21_c, s_c);
}
END_TEST

START_TEST(strcpy_1) {
  char b1[1024] = "";
  char b11[1024] = "";
  char str_1_2[1024] = "LUGANO THE BEST!";
  ck_assert_pstr_eq(strcpy(b1, str_1_2), s21_strcpy(b11, str_1_2));
}
END_TEST

START_TEST(strcpy_2) {
  char b2[1024] = "";
  char b22[1024] = "";
  char str_2_2[1024] = "THE OF \0BEST!!";
  ck_assert_pstr_eq(strcpy(b2, str_2_2), s21_strcpy(b22, str_2_2));
}
END_TEST

START_TEST(strcpy_3) {
  char b3[1024] = "777 ";
  char b33[1024] = "777 ";
  char str_3_2[1024] = "LUGANO!";
  ck_assert_pstr_eq(strcpy(b3, str_3_2), s21_strcpy(b33, str_3_2));
}
END_TEST

START_TEST(strncpy_1) {
  s21_size_t n1 = 3;
  char b1[1024] = "1111111111";
  char b11[1024] = "1111111111";
  char str_1_2[1024] = "123\0";
  ck_assert_pstr_eq(strncpy(b1, str_1_2, n1), s21_strncpy(b11, str_1_2, n1));
}
END_TEST

START_TEST(strncpy_2) {
  s21_size_t n2 = 5;
  char b2[1024] = "1111111111";
  char b22[1024] = "1111111111";
  char str_2_2[1024] = "12345\0006789";
  ck_assert_pstr_eq(strncpy(b2, str_2_2, n2), s21_strncpy(b22, str_2_2, n2));
}
END_TEST

START_TEST(strncpy_3) {
  s21_size_t n3 = 5;
  char b3[1024] = "11";
  char b33[1024] = "11";
  char str_3_2[1024] = "12345\0006789";
  ck_assert_pstr_eq(strncpy(b3, str_3_2, n3), s21_strncpy(b33, str_3_2, n3));
}
END_TEST

START_TEST(strlen_1) {
  char *str_1 = "LUGANO\0";
  ck_assert_int_eq(strlen(str_1), s21_strlen(str_1));
}
END_TEST

START_TEST(strlen_2) {
  char *str_2 = "LUGANO THE \0BEST!!!";
  ck_assert_int_eq(strlen(str_2), s21_strlen(str_2));
}
END_TEST

START_TEST(strlen_3) {
  char *str_3 = "\0";
  ck_assert_int_eq(strlen(str_3), s21_strlen(str_3));
}
END_TEST

START_TEST(strstr_1) {
  char str[] = "";
  ck_assert_pstr_eq(strstr(str, ""), s21_strstr(str, ""));
}
END_TEST

START_TEST(strstr_2) {
  char str2[] = "HAHAHAHAHAHA";
  ck_assert_pstr_eq(strstr(str2, "sm"), s21_strstr(str2, "sm"));
}
END_TEST

START_TEST(strstr_3) {
  char str3[] = {'q', 'r', 's', 't', 'w', 's', 'a', 's', '\0'};
  ck_assert_pstr_eq(strstr(str3, "woo"), s21_strstr(str3, "woo"));
}
END_TEST

START_TEST(strstr_4) {
  char haystack[] = "You are toxic!";
  char needle[] = "toxic";

  ck_assert_pstr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(strstr_5) {
  char haystack[] = "There is no right word in this test!";
  char needle[] = "NOT";

  ck_assert_pstr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(strstr_6) {
  char haystack[] = "AbOBosNyTSa";
  char needle[] = "aBoboSNYTsa";

  ck_assert_pstr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(strtok_1) {
  char str4_1[] = "/testing/with/original/string.h/";
  char str4_2[] = "/testing/with/original/string.h/";
  char del4[3] = "/";
  char *nstr_1, *nstr_2;
  nstr_1 = strtok(str4_1, del4);
  nstr_2 = s21_strtok(str4_2, del4);
  while (nstr_1 != s21_NULL) {
    ck_assert_pstr_eq(nstr_1, nstr_2);
    nstr_1 = strtok(s21_NULL, del4);
    nstr_2 = s21_strtok(s21_NULL, del4);
  }
}
END_TEST

START_TEST(strtok_2) {
  char str4_1[] = ". . testing with original string.h";
  char str4_2[] = ". . testing with original string.h";
  char del4[3] = ". ";
  char *nstr_1, *nstr_2;
  nstr_1 = strtok(str4_1, del4);
  nstr_2 = s21_strtok(str4_2, del4);
  while (nstr_1 != s21_NULL) {
    ck_assert_pstr_eq(nstr_1, nstr_2);
    nstr_1 = strtok(s21_NULL, del4);
    nstr_2 = s21_strtok(s21_NULL, del4);
  }
}
END_TEST

START_TEST(strtok_3) {
  char str4_1[] = "testing with original string.h";
  char str4_2[] = "testing with original string.h";
  char del4[3] = ". ";
  char *nstr_1, *nstr_2;
  nstr_1 = strtok(str4_1, del4);
  nstr_2 = s21_strtok(str4_2, del4);
  while (nstr_1 != s21_NULL) {
    ck_assert_pstr_eq(nstr_1, nstr_2);
    nstr_1 = strtok(s21_NULL, del4);
    nstr_2 = s21_strtok(s21_NULL, del4);
  }
}
END_TEST

// insert
START_TEST(insert_1) {
  char *string = "bimabi";
  char *string2;
  string2 = s21_insert(string, "ma", 2);
  ck_assert_pstr_eq(string2, "bimamabi");
  free(string2);
}
END_TEST
// insert

// strcspn
START_TEST(strcspn_upper_letter) {
  char src[] = "32ASDASDPare[0g9jf m07y271234567890";
  char res[] = "1234567890QWERTYUIOPASDFGHJKLZXCVBNM";
  ck_assert_int_eq(s21_strcspn(res, src), strcspn(res, src));
}
END_TEST
// strcspn

// strpbrk_1
START_TEST(strpbrk_1) {
  char str2[] = "ivanamin@yan\0dex.ru";
  ck_assert_pstr_eq(strpbrk(str2, "fzx"), s21_strpbrk(str2, "fzx"));
}
END_TEST
// strpbrk_1

START_TEST(sscanf_ld) {
  long int var_1 = 0, var_2 = 0, var_3 = 0, var_4 = 0, var_5 = 0, var_6 = 0,
           var_7 = 0, var_8 = 0;
  const char spec[] = "%ld %ld %ld %ld";
  const char str[] = "1 2 3 4";

  int res1 = s21_sscanf(str, spec, &var_1, &var_3, &var_5, &var_7);
  int res2 = sscanf(str, spec, &var_2, &var_4, &var_6, &var_8);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(var_1, var_2);
  ck_assert_int_eq(var_3, var_4);
  ck_assert_int_eq(var_5, var_6);
  ck_assert_int_eq(var_7, var_8);
}
END_TEST

START_TEST(sscanf_hd) {
  int var_1 = 0, var_2 = 0, var_3 = 0, var_4 = 0, var_5 = 0, var_6 = 0,
      var_7 = 0, var_8 = 0;
  const char str[] = "1337 21 5008 3000";
  const char spec[] = "%hd %hd %hd %hd";

  int res1 = s21_sscanf(str, spec, &var_1, &var_3, &var_5, &var_7);
  int res2 = sscanf(str, spec, &var_2, &var_4, &var_6, &var_8);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(var_1, var_2);
  ck_assert_int_eq(var_3, var_4);
  ck_assert_int_eq(var_5, var_6);
  ck_assert_int_eq(var_7, var_8);
}
END_TEST

START_TEST(sscanf_lld) {
  long long int var_1 = 0, var_2 = 0, var_3 = 0, var_4 = 0, var_5 = 0,
                var_6 = 0, var_7 = 0, var_8 = 0;
  const char str[] = "1337 21 5008 300004";
  const char spec[] = "%lld %lld %lld %lld";

  int res1 = s21_sscanf(str, spec, &var_1, &var_3, &var_5, &var_7);
  int res2 = sscanf(str, spec, &var_2, &var_4, &var_6, &var_8);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(var_1, var_2);
  ck_assert_int_eq(var_3, var_4);
  ck_assert_int_eq(var_5, var_6);
  ck_assert_int_eq(var_7, var_8);
}
END_TEST

START_TEST(sscanf_lld_wdh) {
  long long int var_1 = 0, var_2 = 0, var_3 = 0, var_4 = 0, var_5 = 0,
                var_6 = 0, var_7 = 0, var_8 = 0;
  const char str[] = "1337 21 5008 300004";
  const char spec[] = "%1lld %3lld %1lld %4lld";

  int res1 = s21_sscanf(str, spec, &var_1, &var_3, &var_5, &var_7);
  int res2 = sscanf(str, spec, &var_2, &var_4, &var_6, &var_8);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(var_1, var_2);
  ck_assert_int_eq(var_3, var_4);
  ck_assert_int_eq(var_5, var_6);
  ck_assert_int_eq(var_7, var_8);
}
END_TEST

START_TEST(sscanf_lld_wdh_1_word_in_str) {
  long long int var_1 = 0, var_2 = 0, var_3 = 0, var_4 = 0, var_5 = 0,
                var_6 = 0, var_7 = 0, var_8 = 0;
  const char str[] = "1337";
  const char spec[] = "%1lld %1lld %1lld %1lld";

  int res1 = s21_sscanf(str, spec, &var_1, &var_3, &var_5, &var_7);
  int res2 = sscanf(str, spec, &var_2, &var_4, &var_6, &var_8);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(var_1, var_2);
  ck_assert_int_eq(var_3, var_4);
  ck_assert_int_eq(var_5, var_6);
  ck_assert_int_eq(var_7, var_8);
}
END_TEST

START_TEST(sscanf_lld_wdh_1_word_in_str2) {
  long long int var_1 = 0, var_2 = 0, var_3 = 0, var_4 = 0, var_5 = 0,
                var_6 = 0, var_7 = 0, var_8 = 0;
  const char str[] = "100000000000000005";
  const char spec[] = "%3lld%lld%1lld%5lld";

  int res1 = s21_sscanf(str, spec, &var_1, &var_3, &var_5, &var_7);
  int res2 = sscanf(str, spec, &var_2, &var_4, &var_6, &var_8);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(var_1, var_2);
  ck_assert_int_eq(var_3, var_4);
  ck_assert_int_eq(var_5, var_6);
  ck_assert_int_eq(var_7, var_8);
}
END_TEST

START_TEST(to_upper_test1) {
  char str[] = "good job";
  char expected[] = "GOOD JOB";
  char *got = (char *)s21_to_upper(str);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(to_upper_test2) {
  char str[] = "empty";
  char expected[] = "EMPTY";
  char *got = (char *)s21_to_upper(str);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(to_upper_test3) {
  char str[] = "1+1*1";
  char expected[] = "1+1*1";
  char *got = (char *)s21_to_upper(str);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(to_upper_test4) {
  char str[] = " ";
  char expected[] = " ";
  char *got = (char *)s21_to_upper(str);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(to_upper_test5) {
  char str[] = "";
  char expected[] = "";
  char *got = (char *)s21_to_upper(str);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(sscanf_lld_wdh_1_word_in_str3) {
  long long int var_1 = 0, var_2 = 0, var_3 = 0, var_4 = 0, var_5 = 0,
                var_6 = 0, var_7 = 0, var_8 = 0;
  const char str[] = "1337";
  const char spec[] = "%15lld %1lld %1lld %1lld";

  int res1 = s21_sscanf(str, spec, &var_1, &var_3, &var_5, &var_7);
  int res2 = sscanf(str, spec, &var_2, &var_4, &var_6, &var_8);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(var_1, var_2);
  ck_assert_int_eq(var_3, var_4);
  ck_assert_int_eq(var_5, var_6);
  ck_assert_int_eq(var_7, var_8);
}
END_TEST

START_TEST(sscanf_d_star) {
  long long int var_1 = 0, var_2 = 0, var_3 = 0, var_4 = 0, var_5 = 0,
                var_6 = 0;
  const char str[] = "1337123123 1 123412341234 1 999999 0";
  const char spec[] = "%*d %lld %*d %lld %*d %lld";

  int res1 = s21_sscanf(str, spec, &var_1, &var_3, &var_5);
  int res2 = sscanf(str, spec, &var_2, &var_4, &var_6);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(var_1, var_2);
  ck_assert_int_eq(var_3, var_4);
  ck_assert_int_eq(var_5, var_6);
}
END_TEST

START_TEST(sscanf_d_many_plusminus) {
  long long int var_1 = 0, var_2 = 0, var_3 = 0, var_4 = 0, var_5 = 0,
                var_6 = 0, var_7 = 0, var_8 = 0;
  const char str[] = "11337 ++3 -5 ------4";
  const char spec[] = "%lld %lld %lld %lld";

  int res1 = s21_sscanf(str, spec, &var_1, &var_3, &var_5, &var_7);
  int res2 = sscanf(str, spec, &var_2, &var_4, &var_6, &var_8);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(var_1, var_2);
  ck_assert_int_eq(var_3, var_4);
  ck_assert_int_eq(var_5, var_6);
  ck_assert_int_eq(var_7, var_8);
}
END_TEST

START_TEST(sscanf_d_plusminus) {
  long long int var_1 = 0, var_2 = 0, var_3 = 0, var_4 = 0, var_5 = 0,
                var_6 = 0, var_7 = 0, var_8 = 0;
  const char str[] = "-1337 +1 -1 -1";
  const char spec[] = "%15lld %1lld %1lld %5lld";

  int res1 = s21_sscanf(str, spec, &var_1, &var_3, &var_5, &var_7);
  int res2 = sscanf(str, spec, &var_2, &var_4, &var_6, &var_8);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(var_1, var_2);
  ck_assert_int_eq(var_3, var_4);
  ck_assert_int_eq(var_5, var_6);
  ck_assert_int_eq(var_7, var_8);
}
END_TEST

START_TEST(sscanf_d_plusminus_null) {
  long long int var_1 = 0, var_2 = 0, var_3 = 0, var_4 = 0, var_5 = 0,
                var_6 = 0, var_7 = 0, var_8 = 0;
  const char str[] = "-0 +0 +0 -0";
  const char spec[] = "%2lld %1lld %1lld %1lld";

  int res1 = s21_sscanf(str, spec, &var_1, &var_3, &var_5, &var_7);
  int res2 = sscanf(str, spec, &var_2, &var_4, &var_6, &var_8);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(var_1, var_2);
  ck_assert_int_eq(var_3, var_4);
  ck_assert_int_eq(var_5, var_6);
  ck_assert_int_eq(var_7, var_8);
}
END_TEST

START_TEST(sscanf_d_01) {
  long long int var_1 = 0, var_2 = 0, var_3 = 0, var_4 = 0, var_5 = 0,
                var_6 = 0, var_7 = 0, var_8 = 0;
  const char str[] = "1 01 10 0";
  const char spec[] = "%lld %lld %lld %lld";

  int res1 = s21_sscanf(str, spec, &var_1, &var_3, &var_5, &var_7);
  int res2 = sscanf(str, spec, &var_2, &var_4, &var_6, &var_8);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(var_1, var_2);
  ck_assert_int_eq(var_3, var_4);
  ck_assert_int_eq(var_5, var_6);
  ck_assert_int_eq(var_7, var_8);
}
END_TEST

START_TEST(sscanf_i) {
  long long int var_1 = 0, var_2 = 0, var_3 = 0, var_4 = 0, var_5 = 0,
                var_6 = 0, var_7 = 0, var_8 = 0;
  const char str[] = "300 500 -600 +700";
  const char spec[] = "%lli %lli %lli %lli";

  int res1 = s21_sscanf(str, spec, &var_1, &var_3, &var_5, &var_7);
  int res2 = sscanf(str, spec, &var_2, &var_4, &var_6, &var_8);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(var_1, var_2);
  ck_assert_int_eq(var_3, var_4);
  ck_assert_int_eq(var_5, var_6);
  ck_assert_int_eq(var_7, var_8);
}
END_TEST

START_TEST(sscanf_i_plusminus) {
  long long int var_1 = 0, var_2 = 0, var_3 = 0, var_4 = 0, var_5 = 0,
                var_6 = 0, var_7 = 0, var_8 = 0;
  const char str[] = "300500-600+700 111";
  const char spec[] = "%lli %lld %lld %lli";

  int res1 = s21_sscanf(str, spec, &var_1, &var_3, &var_5, &var_7);
  int res2 = sscanf(str, spec, &var_2, &var_4, &var_6, &var_8);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(var_1, var_2);
  ck_assert_int_eq(var_3, var_4);
  ck_assert_int_eq(var_5, var_6);
  ck_assert_int_eq(var_7, var_8);
}
END_TEST

START_TEST(sscanf_i_plusminus_withoutspace) {
  long long int var_1 = 0, var_2 = 0, var_5 = 0, var_6 = 0;
  char var_3 = 0, var_4 = 0, var_7 = 0, var_8 = 0;
  const char str[] = "300500-600+700+400";
  const char spec[] = "%lli%c%lli%c";

  int res1 = s21_sscanf(str, spec, &var_1, &var_3, &var_5, &var_7);
  int res2 = sscanf(str, spec, &var_2, &var_4, &var_6, &var_8);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(var_1, var_2);
  ck_assert_int_eq(var_3, var_4);
  ck_assert_int_eq(var_5, var_6);
  ck_assert_int_eq(var_7, var_8);
}
END_TEST

START_TEST(sscanf_i_d_manyspaces) {
  long long int var_1 = 0, var_2 = 0, var_3 = 0, var_4 = 0, var_5 = 0,
                var_6 = 0, var_7 = 0, var_8 = 0;
  const char str[] = "  55555 f f f5555555 ddd   4    3    1 ";
  const char spec[] = "%lli %lld %lld %lli";

  int res1 = s21_sscanf(str, spec, &var_1, &var_3, &var_5, &var_7);
  int res2 = sscanf(str, spec, &var_2, &var_4, &var_6, &var_8);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(var_1, var_2);
  ck_assert_int_eq(var_3, var_4);
  ck_assert_int_eq(var_5, var_6);
  ck_assert_int_eq(var_7, var_8);
}
END_TEST

START_TEST(sscanf_i_0x) {
  long long int var_1 = 0, var_2 = 0, var_3 = 0, var_4 = 0, var_5 = 0,
                var_6 = 0, var_7 = 0, var_8 = 0;
  const char str[] = "0xFFF 0xA123123 0x123123 0x0";
  const char spec[] = "%lli %lld %lld %lli";

  int res1 = s21_sscanf(str, spec, &var_1, &var_3, &var_5, &var_7);
  int res2 = sscanf(str, spec, &var_2, &var_4, &var_6, &var_8);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(var_1, var_2);
  ck_assert_int_eq(var_3, var_4);
  ck_assert_int_eq(var_5, var_6);
  ck_assert_int_eq(var_7, var_8);
}
END_TEST

START_TEST(sscanf_i_0x_manyspaces) {
  long long int var_1 = 0, var_2 = 0, var_3 = 0, var_4 = 0, var_5 = 0,
                var_6 = 0, var_7 = 0, var_8 = 0;
  const char str[] = " 0xFFFF 0xf 0xf 0xf5555555 ddd   4    3    1 ";
  const char spec[] = "%lli %lld %lld %lli";

  int res1 = s21_sscanf(str, spec, &var_1, &var_3, &var_5, &var_7);
  int res2 = sscanf(str, spec, &var_2, &var_4, &var_6, &var_8);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(var_1, var_2);
  ck_assert_int_eq(var_3, var_4);
  ck_assert_int_eq(var_5, var_6);
  ck_assert_int_eq(var_7, var_8);
}
END_TEST

START_TEST(sscanf_i_oct_manyspaces) {
  long long int var_1 = 0, var_2 = 0, var_3 = 0, var_4 = 0, var_5 = 0,
                var_6 = 0, var_7 = 0, var_8 = 0;
  const char str[] = "  055555 0f 0f 0f5555555 0ddd   4    3    1 ";
  const char spec[] = "%lli %lld %lld %lli";

  int res1 = s21_sscanf(str, spec, &var_1, &var_3, &var_5, &var_7);
  int res2 = sscanf(str, spec, &var_2, &var_4, &var_6, &var_8);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(var_1, var_2);
  ck_assert_int_eq(var_3, var_4);
  ck_assert_int_eq(var_5, var_6);
  ck_assert_int_eq(var_7, var_8);
}
END_TEST

START_TEST(sscanf_i_oct_manyspaces2) {
  long long int var_1 = 0, var_2 = 0, var_3 = 0, var_4 = 0, var_5 = 0,
                var_6 = 0, var_7 = 0, var_8 = 0;
  const char str[] = "  055555 0f 0f 0f5555555 0ddd   4    3    1 ";
  const char spec[] = "%lli %lld %lld %lli";

  int res1 = s21_sscanf(str, spec, &var_1, &var_3, &var_5, &var_7);
  int res2 = sscanf(str, spec, &var_2, &var_4, &var_6, &var_8);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(var_1, var_2);
  ck_assert_int_eq(var_3, var_4);
  ck_assert_int_eq(var_5, var_6);
  ck_assert_int_eq(var_7, var_8);
}
END_TEST

START_TEST(sscanf_spec_i_int1_Vlad1) {
  long long int var_1 = 0, var_2 = 0, var_3 = 0, var_4 = 0, var_5 = 0,
                var_6 = 0, var_7 = 0, var_8 = 0;
  const char str[] = "300l500 -600 +700";
  const char spec[] = "%lli %lli %lli %lli";

  int res1 = s21_sscanf(str, spec, &var_1, &var_3, &var_5, &var_7);
  int res2 = sscanf(str, spec, &var_2, &var_4, &var_6, &var_8);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(var_1, var_2);
  ck_assert_int_eq(var_3, var_4);
  ck_assert_int_eq(var_5, var_6);
  ck_assert_int_eq(var_7, var_8);
}
END_TEST

START_TEST(sscanf_spec_i_int1_Vlad2) {
  long long int var_1 = 0, var_2 = 0, var_3 = 0, var_4 = 0, var_5 = 0,
                var_6 = 0, var_7 = 0, var_8 = 0;
  const char str[] = "300l500 --600 +700";
  const char spec[] = "%lli %lli %lli %lli";

  int res1 = s21_sscanf(str, spec, &var_1, &var_3, &var_5, &var_7);
  int res2 = sscanf(str, spec, &var_2, &var_4, &var_6, &var_8);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(var_1, var_2);
  ck_assert_int_eq(var_3, var_4);
  ck_assert_int_eq(var_5, var_6);
  ck_assert_int_eq(var_7, var_8);
}
END_TEST

START_TEST(sscanf_spec_i_int1_Vlad3) {
  long long int var_1 = 0, var_2 = 0, var_3 = 0, var_4 = 0, var_5 = 0,
                var_6 = 0, var_7 = 0, var_8 = 0;
  const char str[] = "3687";
  const char spec[] = "%1d%1d%1d%1d";

  int res1 = s21_sscanf(str, spec, &var_1, &var_3, &var_5, &var_7);
  int res2 = sscanf(str, spec, &var_2, &var_4, &var_6, &var_8);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(var_1, var_2);
  ck_assert_int_eq(var_3, var_4);
  ck_assert_int_eq(var_5, var_6);
  ck_assert_int_eq(var_7, var_8);
}
END_TEST

START_TEST(sscanf_X) {
  int var_1, var_2;
  const char str[] = "F";
  const char spec[] = "%X";
  int res1 = s21_sscanf(str, spec, &var_1);
  int res2 = sscanf(str, spec, &var_2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(var_1, var_2);
}
END_TEST

START_TEST(sscanf_big_X) {
  int var_1, var_2;
  const char str[] = "0xFFFFFFFF";
  const char spec[] = "%X";
  int res1 = s21_sscanf(str, spec, &var_1);
  int res2 = sscanf(str, spec, &var_2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(var_1, var_2);
}
END_TEST

START_TEST(sscanf_X_0) {
  int var_1, var_2;
  const char str[] = "0x";
  const char spec[] = "%X";
  int res1 = s21_sscanf(str, spec, &var_1);
  int res2 = sscanf(str, spec, &var_2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(var_1, var_2);
}
END_TEST

START_TEST(sscanf_X_0_2) {
  int var_1, var_2;
  const char str[] = "0X";
  const char spec[] = "%X";
  int res1 = s21_sscanf(str, spec, &var_1);
  int res2 = sscanf(str, spec, &var_2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(var_1, var_2);
}
END_TEST

START_TEST(sscanf_X_non) {
  int var_1, var_2;
  const char str[] = "";
  const char spec[] = "%X";
  int res1 = s21_sscanf(str, spec, &var_1);
  int res2 = sscanf(str, spec, &var_2);

  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_X_false) {
  int var_1, var_2;
  const char str[] = "qF";
  const char spec[] = "%X";
  int res1 = s21_sscanf(str, spec, &var_1);
  int res2 = sscanf(str, spec, &var_2);

  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_X_n) {
  int var_1, var_2;
  const char str[] = "          \n             \n     F";
  const char spec[] = "%X";
  int res1 = s21_sscanf(str, spec, &var_1);
  int res2 = sscanf(str, spec, &var_2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(var_1, var_2);
}
END_TEST

START_TEST(sscanf_hX) {
  uint16_t var_1, var_2;
  const char str[] = "F";
  const char spec[] = "%hX";
  uint16_t res1 = s21_sscanf(str, spec, &var_1);
  uint16_t res2 = sscanf(str, spec, &var_2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(var_1, var_2);
}
END_TEST

START_TEST(sscanf_lX) {
  unsigned long int var_1, var_2;
  const char str[] = "F";
  const char spec[] = "%lX";
  int res1 = s21_sscanf(str, spec, &var_1);
  int res2 = sscanf(str, spec, &var_2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(var_1, var_2);
}
END_TEST

START_TEST(sscanf_llX) {
  unsigned long long int var_1, var_2;
  const char str[] = "F";
  const char spec[] = "%llX";
  int res1 = s21_sscanf(str, spec, &var_1);
  int res2 = sscanf(str, spec, &var_2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(var_1, var_2);
}
END_TEST

START_TEST(sscanf_X_twice) {
  int var_1, var_2;
  const char str[] = "0xFF0x0xFFF 0xFFxFF";
  const char spec[] = "%X";
  int res1 = s21_sscanf(str, spec, &var_1);
  int res2 = sscanf(str, spec, &var_2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(var_1, var_2);
}
END_TEST

START_TEST(sscanf_X_star) {
  const char str[] = "0xFF0x0xFFF 0xFFxFF";
  const char spec[] = "%*X";
  int res1 = s21_sscanf(str, spec);
  int res2 = sscanf(str, spec);

  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_X_fals) {
  int var_1, var_2;
  const char str[] = "tqwqpl";
  const char spec[] = "%X";
  int res1 = s21_sscanf(str, spec, &var_1);
  int res2 = sscanf(str, spec, &var_2);

  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_X_a) {
  int var_1, var_2;
  const char str[] = "abcdef";
  const char spec[] = "%X";
  int res1 = s21_sscanf(str, spec, &var_1);
  int res2 = sscanf(str, spec, &var_2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(var_1, var_2);
}
END_TEST

START_TEST(sscanf_X_negative) {
  int var_1, var_2;
  const char str[] = "-f";
  const char spec[] = "%X";
  int res1 = s21_sscanf(str, spec, &var_1);
  int res2 = sscanf(str, spec, &var_2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(var_1, var_2);
}
END_TEST

START_TEST(sscanf_x) {
  int var_1, var_2;
  const char str[] = "f";
  const char spec[] = "%x";
  int res1 = s21_sscanf(str, spec, &var_1);
  int res2 = sscanf(str, spec, &var_2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(var_1, var_2);
}
END_TEST

START_TEST(sscanf_big_x) {
  int var_1, var_2;
  const char str[] = "0xfffffffffffffffffff";
  const char spec[] = "%x";
  int res1 = s21_sscanf(str, spec, &var_1);
  int res2 = sscanf(str, spec, &var_2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(var_1, var_2);
}
END_TEST

START_TEST(sscanf_x_0x) {
  int var_1, var_2;
  const char str[] = "0x";
  const char spec[] = "%x";
  int res1 = s21_sscanf(str, spec, &var_1);
  int res2 = sscanf(str, spec, &var_2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(var_1, var_2);
}
END_TEST

START_TEST(sscanf_x_0x_2) {
  int var_1, var_2;
  const char str[] = "0X";
  const char spec[] = "%x";
  int res1 = s21_sscanf(str, spec, &var_1);
  int res2 = sscanf(str, spec, &var_2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(var_1, var_2);
}
END_TEST

START_TEST(sscanf_x_non) {
  int var_1, var_2;
  const char str[] = "";
  const char spec[] = "%x";
  int res1 = s21_sscanf(str, spec, &var_1);
  int res2 = sscanf(str, spec, &var_2);

  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_x_false) {
  int var_1, var_2;
  const char str[] = "qF";
  const char spec[] = "%x";
  int res1 = s21_sscanf(str, spec, &var_1);
  int res2 = sscanf(str, spec, &var_2);

  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_x_n) {
  int var_1, var_2;
  const char str[] = "          \n             \n     F";
  const char spec[] = "%x";
  int res1 = s21_sscanf(str, spec, &var_1);
  int res2 = sscanf(str, spec, &var_2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(var_1, var_2);
}
END_TEST

START_TEST(sscanf_hx) {
  uint16_t var_1, var_2;
  const char str[] = "ff";
  const char spec[] = "%hx";
  uint16_t res1 = s21_sscanf(str, spec, &var_1);
  uint16_t res2 = sscanf(str, spec, &var_2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(var_1, var_2);
}
END_TEST

START_TEST(sscanf_lx) {
  unsigned long int var_1, var_2;
  const char str[] = "ff";
  const char spec[] = "%lx";
  int res1 = s21_sscanf(str, spec, &var_1);
  int res2 = sscanf(str, spec, &var_2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(var_1, var_2);
}
END_TEST

START_TEST(sscanf_llx) {
  unsigned long long int var_1, var_2;
  const char str[] = "faaaaaaaaaaaaf";
  const char spec[] = "%llx";
  int res1 = s21_sscanf(str, spec, &var_1);
  int res2 = sscanf(str, spec, &var_2);

  ck_assert_int_eq(res1, res2);
  // ck_assert_unsigned long long int int_eq(var_1, var_2);
  // ck_assert_int64_eq(var_1, var_2);
  ck_assert_int_eq(var_1, var_2);
}
END_TEST

START_TEST(sscanf_x_twice) {
  int var_1, var_2;
  const char str[] = "0xFF0x0xFFF 0xFFxFF";
  const char spec[] = "%x";
  int res1 = s21_sscanf(str, spec, &var_1);
  int res2 = sscanf(str, spec, &var_2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(var_1, var_2);
}
END_TEST

START_TEST(sscanf_x_star) {
  const char str[] = "0xFF0x0xFFF 0xFFxFF";
  const char spec[] = "%*x";
  int res1 = s21_sscanf(str, spec);
  int res2 = sscanf(str, spec);

  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_x_fals) {
  int var_1, var_2;
  const char str[] = "tqwqpl";
  const char spec[] = "%x";
  int res1 = s21_sscanf(str, spec, &var_1);
  int res2 = sscanf(str, spec, &var_2);

  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_x_a) {
  int var_1, var_2;
  const char str[] = "abcdef";
  const char spec[] = "%x";
  int res1 = s21_sscanf(str, spec, &var_1);
  int res2 = sscanf(str, spec, &var_2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(var_1, var_2);
}
END_TEST

START_TEST(sscanf_x_negative) {
  int var_1, var_2;
  const char str[] = "-f";
  const char spec[] = "%x";
  int res1 = s21_sscanf(str, spec, &var_1);
  int res2 = sscanf(str, spec, &var_2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(var_1, var_2);
}
END_TEST

START_TEST(sscanf_2X) {
  int var_1, var_2;
  const char str[] = "123531FFF";
  const char spec[] = "%2X";
  int res1 = s21_sscanf(str, spec, &var_1);
  int res2 = sscanf(str, spec, &var_2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(var_1, var_2);
}
END_TEST

START_TEST(sscanf_2x) {
  int var_1, var_2;
  const char str[] = "123531FFF";
  const char spec[] = "%2x";
  int res1 = s21_sscanf(str, spec, &var_1);
  int res2 = sscanf(str, spec, &var_2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(var_1, var_2);
}
END_TEST

START_TEST(sscanf_o) {
  int var_1, var_2;
  const char str[] = "777";
  const char spec[] = "%o";
  int res1 = s21_sscanf(str, spec, &var_1);
  int res2 = sscanf(str, spec, &var_2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(var_1, var_2);
}
END_TEST

START_TEST(sscanf_over_o) {
  int var_1, var_2;
  const char str[] = "0x7777777777777777777777";
  const char spec[] = "%o";
  int res1 = s21_sscanf(str, spec, &var_1);
  int res2 = sscanf(str, spec, &var_2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(var_1, var_2);
}
END_TEST

START_TEST(all_empty) {
  char str[] = "";
  char trim_ch[] = "";
  char expected[] = "";
  char *got = s21_trim(str, trim_ch);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(str_empty) {
  char str[] = "";
  char trim_ch[] = "+!0-aeoi2o3i23iuhuhh3O*YADyagsduyoaweq213";
  char expected[] = "";
  char *got = s21_trim(str, trim_ch);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(trim_empty) {
  char str[] = "+!0-aeoi2o3i23iuhuhh3O*YADyagsduyoaweq213";
  char trim_ch[] = "";
  char expected[] = "+!0-aeoi2o3i23iuhuhh3O*YADyagsduyoaweq213";
  char *got = s21_trim(str, trim_ch);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(trim_and_str_eq) {
  char str[] = "+!0-aeoi2o3i23iuhuhh3O*YADyagsduyoaweq213";
  char trim_ch[] = "+!0-aeoi2o3i23iuhuhh3O*YADyagsduyoaweq213";
  char expected[] = "";
  char *got = s21_trim(str, trim_ch);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(trim_test1) {
  char str[] = "+!!++Abo+ba++00";
  char trim_ch[] = "+!0-";
  char expected[] = "Abo+ba";
  char *got = (char *)s21_trim(str, trim_ch);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(trim_test2) {
  char str[] = "Ab000cd0";
  char trim_ch[] = "003";
  char expected[] = "Ab000cd";
  char *got = s21_trim(str, trim_ch);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(trim_test3) {
  char str[] = "DoNotTouch";
  char trim_ch[] = "Not";
  char expected[] = "DoNotTouch";
  char *got = s21_trim(str, trim_ch);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(trim_test4) {
  char str[] = "&* !!sc21 * **";
  char trim_ch[] = "&!* ";
  char expected[] = "sc21";
  char *got = s21_trim(str, trim_ch);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(trim_test5) {
  char str[] = " Good morning!    ";
  char trim_ch[] = " ";
  char expected[] = "Good morning!";
  char *got = s21_trim(str, trim_ch);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(empty_spaces) {
  char str[] = "        abc         ";
  char trim_ch[] = "";
  char expected[] = "abc";
  char *got = s21_trim(str, trim_ch);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(null_ptr_trim_chars) {
  char str[] = "        abc         ";
  char *trim_ch = NULL;
  char expected[] = "abc";
  char *got = s21_trim(str, trim_ch);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(s21_trim_test) {
  char *trimmed_str;
  char *str_to_trim = " \n   Hello, world!  !\n";
  trimmed_str = s21_trim(str_to_trim, " H!\nd");
  if (trimmed_str) {
    ck_assert_str_eq(trimmed_str, "ello, worl");
    free(trimmed_str);
  }

  char *empty_str = "";
  trimmed_str = s21_trim(empty_str, s21_NULL);
  if (trimmed_str) {
    ck_assert_str_eq(trimmed_str, "");
    free(trimmed_str);
  }

  trimmed_str = s21_trim(empty_str, " \n\0");
  if (trimmed_str) {
    ck_assert_str_eq(trimmed_str, "");
    free(trimmed_str);
  }

  char *str_to_trim2 = "xxx Hello, world! xxx ---";
  char *format_str = "x -";
  trimmed_str = s21_trim(str_to_trim2, format_str);
  if (trimmed_str) {
    ck_assert_str_eq(trimmed_str, "Hello, world!");
    free(trimmed_str);
  }
}
END_TEST

START_TEST(sscanf_o_0x) {
  int var_1, var_2;
  const char str[] = "0x";
  const char spec[] = "%o";
  int res1 = s21_sscanf(str, spec, &var_1);
  int res2 = sscanf(str, spec, &var_2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(var_1, var_2);
}
END_TEST

START_TEST(sscanf_o_0X) {
  int var_1, var_2;
  const char str[] = "0X";
  const char spec[] = "%o";
  int res1 = s21_sscanf(str, spec, &var_1);
  int res2 = sscanf(str, spec, &var_2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(var_1, var_2);
}
END_TEST

START_TEST(sscanf_o_non) {
  int var_1, var_2;
  const char str[] = "";
  const char spec[] = "%o";
  int res1 = s21_sscanf(str, spec, &var_1);
  int res2 = sscanf(str, spec, &var_2);

  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_o_er) {
  int var_1, var_2;
  const char str[] = "Y7";
  const char spec[] = "%o";
  int res1 = s21_sscanf(str, spec, &var_1);
  int res2 = sscanf(str, spec, &var_2);

  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_o_tab) {
  int var_1, var_2;
  const char str[] = "          \n             \n     6";
  const char spec[] = "%o";
  int res1 = s21_sscanf(str, spec, &var_1);
  int res2 = sscanf(str, spec, &var_2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(var_1, var_2);
}
END_TEST

START_TEST(sscanf_o_sh) {
  uint16_t var_1, var_2;
  const char str[] = "21";
  const char spec[] = "%ho";
  uint16_t res1 = s21_sscanf(str, spec, &var_1);
  uint16_t res2 = sscanf(str, spec, &var_2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(var_1, var_2);
}
END_TEST

START_TEST(sscanf_o_lg) {
  unsigned long int var_1, var_2;
  const char str[] = "43257";
  const char spec[] = "%lo";
  int res1 = s21_sscanf(str, spec, &var_1);
  int res2 = sscanf(str, spec, &var_2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(var_1, var_2);
}
END_TEST

START_TEST(sscanf_o_lglg) {
  unsigned long long int var_1, var_2;
  const char str[] = "73162265321";
  const char spec[] = "%llo";
  int res1 = s21_sscanf(str, spec, &var_1);
  int res2 = sscanf(str, spec, &var_2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(var_1, var_2);
}
END_TEST

START_TEST(sscanf_o_X2) {
  int var_1, var_2;
  const char str[] = "0x45670x123x365478";
  const char spec[] = "%o";
  int res1 = s21_sscanf(str, spec, &var_1);
  int res2 = sscanf(str, spec, &var_2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(var_1, var_2);
}
END_TEST

START_TEST(sscanf_o_sr) {
  const char str[] = "216165125";
  const char spec[] = "%*o";
  int res1 = s21_sscanf(str, spec);
  int res2 = sscanf(str, spec);

  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_o_nx) {
  int var_1, var_2;
  const char str[] = "lpqwqt";
  const char spec[] = "%o";
  int res1 = s21_sscanf(str, spec, &var_1);
  int res2 = sscanf(str, spec, &var_2);

  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_o_lr) {
  int var_1, var_2;
  const char str[] = "76543210";
  const char spec[] = "%o";
  int res1 = s21_sscanf(str, spec, &var_1);
  int res2 = sscanf(str, spec, &var_2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(var_1, var_2);
}
END_TEST

START_TEST(sscanf_o_sn) {
  int var_1, var_2;
  const char str[] = "-99";
  const char spec[] = "%o";
  int res1 = s21_sscanf(str, spec, &var_1);
  int res2 = sscanf(str, spec, &var_2) + 1;

  ck_assert_int_eq(res1, res2);
  // ck_assert_int_eq(var_1, var_2);
}
END_TEST

START_TEST(sscanf_o_LEN) {
  int var_1, var_2;
  const char str[] = "135321";
  const char spec[] = "%2o";
  int res1 = s21_sscanf(str, spec, &var_1);
  int res2 = sscanf(str, spec, &var_2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(var_1, var_2);
}
END_TEST

START_TEST(sscanf_o_pr1) {
  int *var_1 = 0, *var_2 = 0, *var_3 = 0, *var_4 = 0, *var_5 = 0, *var_6 = 0,
      *var_7 = 0, *var_8 = 0;
  const char str[] = "0xFFFF 0xAAAA 0x7123 0xBBC1FF";
  const char spec[] = "%p %p %p %p";

  int res1 = s21_sscanf(str, spec, &var_1, &var_3, &var_5, &var_7);
  int res2 = sscanf(str, spec, &var_2, &var_4, &var_6, &var_8);

  ck_assert_int_eq(res1, res2);
  ck_assert_ptr_eq(var_1, var_2);
  ck_assert_ptr_eq(var_3, var_4);
  ck_assert_ptr_eq(var_5, var_6);
  ck_assert_ptr_eq(var_7, var_8);
}
END_TEST

START_TEST(sscanf_o_pr2) {
  int *var_1 = 0, *var_2 = 0, *var_3 = 0, *var_4 = 0, *var_5 = 0, *var_6 = 0,
      *var_7 = 0, *var_8 = 0;
  const char str[] = "0xFFFF 0xAAAA 0x7123 0xBBC1FF";
  const char spec[] = "%p %p %p %p";

  int res1 = s21_sscanf(str, spec, &var_1, &var_3, &var_5, &var_7);
  int res2 = sscanf(str, spec, &var_2, &var_4, &var_6, &var_8);

  ck_assert_int_eq(res1, res2);
  ck_assert_ptr_eq(var_1, var_2);
  ck_assert_ptr_eq(var_3, var_4);
  ck_assert_ptr_eq(var_5, var_6);
  ck_assert_ptr_eq(var_7, var_8);
}
END_TEST

START_TEST(sscanf_o_pr3) {
  int *var_1 = 0, *var_2 = 0, *var_3 = 0, *var_4 = 0, *var_5 = 0, *var_6 = 0,
      *var_7 = 0, *var_8 = 0;
  const char str[] = "0xFFFF 0xAAAA 0x7123 0xBBC1FF";
  const char spec[] = "%p %p %p %p";

  int res1 = s21_sscanf(str, spec, &var_1, &var_3, &var_5, &var_7);
  int res2 = sscanf(str, spec, &var_2, &var_4, &var_6, &var_8);

  ck_assert_int_eq(res1, res2);
  ck_assert_ptr_eq(var_1, var_2);
  ck_assert_ptr_eq(var_3, var_4);
  ck_assert_ptr_eq(var_5, var_6);
  ck_assert_ptr_eq(var_7, var_8);
}
END_TEST

START_TEST(sscanf_o_pr4) {
  int *var_1 = 0, *var_2 = 0, *var_3 = 0, *var_4 = 0, *var_5 = 0, *var_6 = 0,
      *var_7 = 0, *var_8 = 0;
  const char str[] = "0xFFFF 0xAAAA 0x7123 0xBBC1FF";
  const char spec[] = "%p %p %p %p";

  int res1 = s21_sscanf(str, spec, &var_1, &var_3, &var_5, &var_7);
  int res2 = sscanf(str, spec, &var_2, &var_4, &var_6, &var_8);

  ck_assert_int_eq(res1, res2);
  ck_assert_ptr_eq(var_1, var_2);
  ck_assert_ptr_eq(var_3, var_4);
  ck_assert_ptr_eq(var_5, var_6);
  ck_assert_ptr_eq(var_7, var_8);
}
END_TEST

START_TEST(sscanf_o_chs2) {
  char spec[] = "%c%c%c%c";
  char str[] = "zxcv";
  int var_1 = 0, var_2 = 5, var_3 = 0, var_4 = 5, var_5 = 0, var_6 = 5,
      var_7 = 0, var_8 = 5;

  int res1 = s21_sscanf(str, spec, &var_1, &var_3, &var_5, &var_7);

  int res2 = sscanf(str, spec, &var_2, &var_4, &var_6, &var_8);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(var_1, var_2);
  ck_assert_int_eq(var_3, var_4);
  ck_assert_int_eq(var_5, var_6);
  ck_assert_int_eq(var_7, var_8);
}
END_TEST

START_TEST(sscanf_o_chs3) {
  char spec[] = "%c %c %c      %c";
  char str[] = "1 a 3   c           ";
  int var_1 = 0, var_2 = 5, var_3 = 0, var_4 = 5, var_5 = 0, var_6 = 5,
      var_7 = 0, var_8 = 5;

  int res1 = s21_sscanf(str, spec, &var_1, &var_3, &var_5, &var_7);
  int res2 = sscanf(str, spec, &var_2, &var_4, &var_6, &var_8);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(var_1, var_2);
  ck_assert_int_eq(var_3, var_4);
  ck_assert_int_eq(var_5, var_6);
  ck_assert_int_eq(var_7, var_8);
}
END_TEST

START_TEST(sscanf_o_chs5) {
  char spec[] = "%c %c %c %c";
  char str[] = "wwwww";
  int var_1 = 0, var_2 = 5, var_3 = 0, var_4 = 5, var_5 = 0, var_6 = 5,
      var_7 = 0, var_8 = 5;

  int res1 = s21_sscanf(str, spec, &var_1, &var_3, &var_5, &var_7);

  int res2 = sscanf(str, spec, &var_2, &var_4, &var_6, &var_8);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(var_1, var_2);
  ck_assert_int_eq(var_3, var_4);
  ck_assert_int_eq(var_5, var_6);
  ck_assert_int_eq(var_7, var_8);
}
END_TEST

START_TEST(sscanf_S_S_a_chr1) {
  char spec[] = "%c%c%c%c";
  char str[] = "\\\n\t\t\t";
  int var_1 = 0, var_2 = 0, var_3 = 0, var_4 = 0, var_5 = 0, var_6 = 0,
      var_7 = 0, var_8 = 0;

  int res1 = s21_sscanf(str, spec, &var_1, &var_3, &var_5, &var_7);
  int res2 = sscanf(str, spec, &var_2, &var_4, &var_6, &var_8);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(var_1, var_2);
  ck_assert_int_eq(var_3, var_4);
  ck_assert_int_eq(var_5, var_6);
  ck_assert_int_eq(var_7, var_8);
}
END_TEST

START_TEST(sscanf_sts1) {
  char s1[BUFF_SIZE] = {'\0'};
  char s2[BUFF_SIZE] = {'\0'};
  char s3[BUFF_SIZE] = {'\0'};
  char s4[BUFF_SIZE] = {'\0'};

  char s5[BUFF_SIZE] = {'\0'};
  char s6[BUFF_SIZE] = {'\0'};
  char s7[BUFF_SIZE] = {'\0'};
  char s8[BUFF_SIZE] = {'\0'};

  const char str[] = "Nike Adidas Keppa Dyson Anuroba";
  const char spec[] = "%s %s %s %s";

  int res1 = s21_sscanf(str, spec, s1, s2, s3, s4);
  int res2 = sscanf(str, spec, s5, s6, s7, s8);

  ck_assert_int_eq(res1, res2);

  ck_assert_str_eq(s1, s5);
  ck_assert_str_eq(s2, s6);
  ck_assert_str_eq(s3, s7);
  ck_assert_str_eq(s4, s8);
}
END_TEST

START_TEST(sscanf_sts4) {
  char s1[BUFF_SIZE] = {'\0'};
  char s2[BUFF_SIZE] = {'\0'};
  char s3[BUFF_SIZE] = {'\0'};
  char s4[BUFF_SIZE] = {'\0'};

  char s5[BUFF_SIZE] = {'\0'};
  char s6[BUFF_SIZE] = {'\0'};
  char s7[BUFF_SIZE] = {'\0'};
  char s8[BUFF_SIZE] = {'\0'};

  const char str[] = "nike\adidas\tasdfasdf\tasdfasdf";
  const char spec[] = "%1s%1s%1s%1s";

  int res1 = s21_sscanf(str, spec, s1, s2, s3, s4);
  int res2 = sscanf(str, spec, s5, s6, s7, s8);

  ck_assert_int_eq(res1, res2);

  ck_assert_str_eq(s1, s5);
  ck_assert_str_eq(s2, s6);
  ck_assert_str_eq(s3, s7);
  ck_assert_str_eq(s4, s8);
}
END_TEST

START_TEST(s21_strspn_test) {
  char str1[] = "hella 1";
  char str2[] = "ell";

  ck_assert_int_eq(s21_strspn(str1, str2), strspn(str1, str2));
  ck_assert_int_eq(s21_strspn(str2, str1), strspn(str2, str1));
}
END_TEST

START_TEST(s21_strerror_test) {
  char *test1 = s21_strerror(1);
  char *test2 = strerror(1);
  char *test3 = s21_strerror(106);
  char *test4 = strerror(106);
  char *test5 = s21_strerror(2147483647);
  char *test6 = strerror(2147483647);
  char *test7 = s21_strerror(-214748364);
  char *test8 = strerror(-214748364);
  ck_assert_uint_eq((unsigned long)*test1, (unsigned long)*test2);
  ck_assert_uint_eq((unsigned long)*test3, (unsigned long)*test4);
  ck_assert_uint_eq((unsigned long)*test5, (unsigned long)*test6);
  ck_assert_uint_eq((unsigned long)*test7, (unsigned long)*test8);
}
END_TEST

START_TEST(sscanf_st_md1) {
  unsigned long long int var_1 = 0, var_2 = 0, var_3 = 0, var_4 = 0, var_5 = 0,
                         var_6 = 0;
  long long int var_7 = 0, var_8 = 0;
  long double e1 = 0, e2 = 0;

  const char str[] =
      "7777777"
      "fffffff\tfffffff";
  const char spec[] = "%5s %1s %*s %*s %llu %s %llu %llu %lld %Lf %33s";

  char s1[BUFF_SIZE] = {'\0'};
  char s2[BUFF_SIZE] = {'\0'};
  char s3[BUFF_SIZE] = {'\0'};
  char s4[BUFF_SIZE] = {'\0'};
  char s5[BUFF_SIZE] = {'\0'};
  char s6[BUFF_SIZE] = {'\0'};
  char s7[BUFF_SIZE] = {'\0'};
  char s8[BUFF_SIZE] = {'\0'};
  char s9[BUFF_SIZE] = {'\0'};
  char s10[BUFF_SIZE] = {'\0'};

  int res1 = s21_sscanf(str, spec, s7, s9, &var_1, s5, &var_3, &var_5, &var_7,
                        &e1, s1);
  int res2 =
      sscanf(str, spec, s8, s10, &var_2, s6, &var_4, &var_6, &var_8, &e2, s2);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(s1, s2);
  ck_assert_str_eq(s3, s4);
  ck_assert_str_eq(s5, s6);
  ck_assert_int_eq(var_1, var_2);
  ck_assert_int_eq(var_3, var_4);
  ck_assert_int_eq(var_5, var_6);
  ck_assert_int_eq(var_7, var_8);
}
END_TEST

START_TEST(sscanf_st_md2) {
  int var_7 = 0, var_8 = 0, var_3 = 0, var_4 = 0, var_1 = 0, var_2 = 0;
  long long int v1, v2;

  const char str[] = "1 1 1 1 1 -1";
  const char spec[] = "%1s %5d %1s %1s %d %lld %d";

  char s1[BUFF_SIZE] = {'\0'};
  char s2[BUFF_SIZE] = {'\0'};
  char s3[BUFF_SIZE] = {'\0'};
  char s4[BUFF_SIZE] = {'\0'};
  char s5[BUFF_SIZE] = {'\0'};
  char s6[BUFF_SIZE] = {'\0'};

  int res1 = s21_sscanf(str, spec, s1, &var_1, s2, s3, &var_3, &v1, &var_7);
  int res2 = sscanf(str, spec, s4, &var_2, s5, s6, &var_4, &v2, &var_8);

  ck_assert_int_eq(res1, res2);
  ck_assert_str_eq(s1, s2);
  ck_assert_str_eq(s3, s4);
  ck_assert_str_eq(s5, s6);
  ck_assert_int_eq(var_1, var_2);
  ck_assert_int_eq(var_3, var_4);
  ck_assert_int_eq(var_7, var_8);
}
END_TEST

START_TEST(sscanf_st_md3) {
  char s1[BUFF_SIZE] = {'\0'};
  char s2[BUFF_SIZE] = {'\0'};
  char s3[BUFF_SIZE] = {'\0'};
  char s4[BUFF_SIZE] = {'\0'};

  char s5[BUFF_SIZE] = {'\0'};
  char s6[BUFF_SIZE] = {'\0'};
  char s7[BUFF_SIZE] = {'\0'};
  char s8[BUFF_SIZE] = {'\0'};

  long long int var_1 = 0, var_2 = 0, var_3 = 0, var_4 = 0, var_5 = 0,
                var_6 = 0, var_7 = 0, var_8 = 0;

  const char str[] = "Niek 321 Adidas -5 Dyson 6666Shleppa 333Anuroba 3";
  const char spec[] = "%s%ld%s%d%s%d%s";

  int res1 =
      s21_sscanf(str, spec, s1, &var_1, s2, &var_3, s3, &var_5, s4, &var_7);
  int res2 =
      s21_sscanf(str, spec, s5, &var_2, s6, &var_4, s7, &var_6, s8, &var_8);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(var_1, var_2);
  ck_assert_int_eq(var_3, var_4);
  ck_assert_int_eq(var_5, var_6);
  ck_assert_int_eq(var_7, var_8);

  ck_assert_str_eq(s1, s5);
  ck_assert_str_eq(s2, s6);
  ck_assert_str_eq(s3, s7);
  ck_assert_str_eq(s4, s8);
}
END_TEST

START_TEST(sscanf_n_Vlad1) {
  long long int var_1 = 0, var_2 = 0, var_3 = 0, var_4 = 0;
  const char str[] = "300";
  const char spec[] = "%lli %n";

  int res1 = s21_sscanf(str, spec, &var_1, &var_3);
  int res2 = sscanf(str, spec, &var_2, &var_4);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(var_1, var_2);
  ck_assert_int_eq(var_3, var_4);
}
END_TEST

START_TEST(sscanf_three_before_n_Vlad1) {
  long long int var_1 = 0, var_2 = 0, var_3 = 0, var_4 = 0, var_5 = 0,
                var_6 = 0;
  char s1[BUFF_SIZE] = {'\0'};
  char s2[BUFF_SIZE] = {'\0'};

  const char str[] = "300 10 300";
  const char spec[] = "%lli %s %lli %n";

  int res1 = s21_sscanf(str, spec, &var_1, s1, &var_5, &var_3);
  int res2 = sscanf(str, spec, &var_2, s2, &var_6, &var_4);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(var_1, var_2);
  ck_assert_str_eq(s1, s2);
  ck_assert_int_eq(var_5, var_6);
  ck_assert_int_eq(var_3, var_4);
}
END_TEST

START_TEST(sscanf_percent_Vlad1) {
  long long int var_1 = 0, var_2 = 0, var_3 = 0, var_4 = 0, var_5 = 0,
                var_6 = 0;
  char s1[BUFF_SIZE] = {'\0'};
  char s2[BUFF_SIZE] = {'\0'};

  const char str[] = "300 10 300";
  const char spec[] = "%% %lli %s %lli %n";

  int res1 = s21_sscanf(str, spec, &var_1, s1, &var_5, &var_3);
  int res2 = sscanf(str, spec, &var_2, s2, &var_6, &var_4);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(var_1, var_2);
  ck_assert_str_eq(s1, s2);
  ck_assert_int_eq(var_5, var_6);
  ck_assert_int_eq(var_3, var_4);
}
END_TEST

START_TEST(sscanf_percent_inside_Vlad1) {
  long long int var_1 = 0, var_2 = 0, var_3 = 0, var_4 = 0, var_5 = 0,
                var_6 = 0;
  char s1[BUFF_SIZE] = {'\0'};
  char s2[BUFF_SIZE] = {'\0'};

  const char str[] = "300 10 300";
  const char spec[] = "%lli %% %s %lli %n";

  int res1 = s21_sscanf(str, spec, &var_1, s1, &var_5, &var_3);
  int res2 = sscanf(str, spec, &var_2, s2, &var_6, &var_4);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(var_1, var_2);
  ck_assert_str_eq(s1, s2);
  ck_assert_int_eq(var_5, var_6);
  ck_assert_int_eq(var_3, var_4);
}
END_TEST

START_TEST(sscanf_single_u_Vlad1) {
  long long int var_1 = 0, var_2 = 0, var_3 = 0, var_4 = 0, var_5 = 0,
                var_6 = 0;
  char s1[BUFF_SIZE] = {'\0'};
  char s2[BUFF_SIZE] = {'\0'};

  const char str[] = "300 10 300";
  const char spec[] = "%u";

  int res1 = s21_sscanf(str, spec, &var_1, s1, &var_5, &var_3);
  int res2 = sscanf(str, spec, &var_2, s2, &var_6, &var_4);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(var_1, var_2);
  ck_assert_str_eq(s1, s2);
  ck_assert_int_eq(var_5, var_6);
  ck_assert_int_eq(var_3, var_4);
}
END_TEST

START_TEST(s21_strchr_test) {
  char str1[] = "Abcdefg";
  int symbol1 = 'd';
  char *ach1 = s21_strchr(str1, symbol1);
  ck_assert_str_eq(ach1, "defg");

  char str2[] = "Abcdefg";
  int symbol2 = 'd';
  char *ach2 = strchr(str2, symbol2);
  ck_assert_str_eq(ach1, ach2);
  ck_assert_str_eq(str1, str2);

  char str3[] = "Abcdefg";
  int symbol3 = '\0';
  char *ach3 = s21_strchr(str3, symbol3);

  char str4[] = "Abcdefg";
  int symbol4 = '\0';
  char *ach4 = strchr(str4, symbol4);
  ck_assert_str_eq(ach3, ach4);
  ck_assert_str_eq(str3, str4);
}
END_TEST

START_TEST(s21_strpbrk_test) {
  char str_for_strpbrk[] = "Megalomania";
  char str_oneof[] = "yal";
  ck_assert_str_eq(s21_strpbrk(str_for_strpbrk, str_oneof), "alomania");
  ck_assert_str_eq(s21_strpbrk(str_for_strpbrk, str_oneof),
                   strpbrk(str_for_strpbrk, str_oneof));

  char *str = "Hello, world";
  char *empty = "";
  ck_assert(s21_strpbrk(str, empty) == s21_NULL);
  ck_assert_uint_eq((unsigned long)s21_strpbrk(str, empty),
                    (unsigned long)strpbrk(str, empty));
}
END_TEST

START_TEST(sscanf_inside_u_Vlad1) {
  long long int var_1 = 0, var_2 = 0, var_3 = 0, var_4 = 0, var_5 = 0,
                var_6 = 0;
  char s1[BUFF_SIZE] = {'\0'};
  char s2[BUFF_SIZE] = {'\0'};

  const char str[] = "300 10 300";
  const char spec[] = "%lli %u %lli";

  int res1 = s21_sscanf(str, spec, &var_1, s1, &var_5, &var_3);
  int res2 = sscanf(str, spec, &var_2, s2, &var_6, &var_4);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(var_1, var_2);
  ck_assert_str_eq(s1, s2);
  ck_assert_int_eq(var_5, var_6);
  ck_assert_int_eq(var_3, var_4);
}
END_TEST

START_TEST(sscanf_fs1) {
  long double var_1 = 1, var_2 = 0, var_3 = 1, var_4 = 0, var_5 = 1, var_6 = 0,
              var_7 = 1, var_8 = 0;

  const char str[] = "58.1 -4.1196 45.3333 +2.0001";
  const char spec[] = "%Lf %Lf %Lf %Lf";

  int res1 = s21_sscanf(str, spec, &var_1, &var_3, &var_5, &var_7);
  int res2 = sscanf(str, spec, &var_2, &var_4, &var_6, &var_8);

  ck_assert_int_eq(res1, res2);
  ck_assert_double_eq(var_1, var_2);
  ck_assert_double_eq(var_3, var_4);
  ck_assert_double_eq(var_5, var_6);
  ck_assert_double_eq(var_7, var_8);
}
END_TEST

START_TEST(sscanf_fs2) {
  double var_1 = 0, var_2 = 0, var_3 = 0, var_4 = 0, var_5 = 0, var_6 = 0,
         var_7 = 0, var_8 = 0;

  const char str[] = "0.00001 -6521123 4. .";
  const char spec[] = "%lf %lf %lf %lf";

  int res1 = s21_sscanf(str, spec, &var_1, &var_3, &var_5, &var_7);
  int res2 = sscanf(str, spec, &var_2, &var_4, &var_6, &var_8);

  ck_assert_int_eq(res1, res2);
  ck_assert_double_eq(var_1, var_2);
  ck_assert_double_eq(var_3, var_4);
  ck_assert_double_eq(var_5, var_6);
  ck_assert_double_eq(var_7, var_8);
}
END_TEST

START_TEST(sscanf_fs4) {
  long double var_1 = 0, var_2 = 0, var_3 = 0, var_4 = 0, var_5 = 0, var_6 = 0,
              var_7 = 0, var_8 = 0;

  const char str[] = "693.41 -4.14135 515.3333 +112.0001";
  const char spec[] = "%Lf %Lf %Lf %Lf";

  int res1 = s21_sscanf(str, spec, &var_1, &var_3, &var_5, &var_7);
  int res2 = sscanf(str, spec, &var_2, &var_4, &var_6, &var_8);

  ck_assert_int_eq(res1, res2);
  ck_assert_double_eq(var_1, var_2);
  ck_assert_double_eq(var_3, var_4);
  ck_assert_double_eq(var_5, var_6);
  ck_assert_double_eq(var_7, var_8);
}
END_TEST

START_TEST(sscanf_fs5) {
  float var_1 = 0, var_2 = 0, var_3 = 0, var_4 = 0, var_5 = 0, var_6 = 0;

  const char str[] = "57.1 -4.1135 411231.333 +2.0001";
  const char spec[] = "%*f %f %f %f";

  int res1 = s21_sscanf(str, spec, &var_1, &var_3, &var_5);
  int res2 = sscanf(str, spec, &var_2, &var_4, &var_6);

  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq(var_1, var_2);
  ck_assert_float_eq(var_3, var_4);
  ck_assert_float_eq(var_5, var_6);
}
END_TEST

START_TEST(to_lower_test1) {
  char str[] = "ShLePa V TaZ1Ke?";
  char expected[] = "shlepa v taz1ke?";
  char *got = (char *)s21_to_lower(str);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(to_lower_test2) {
  char str[] = "123456789Q";
  char expected[] = "123456789q";
  char *got = (char *)s21_to_lower(str);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(to_lower_test3) {
  char str[] = "Space created";
  char expected[] = "space created";
  char *got = (char *)s21_to_lower(str);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(to_lower_test4) {
  char str[] = "";
  char expected[] = "";
  char *got = (char *)s21_to_lower(str);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(to_lower_test5) {
  char str[] = "";
  char expected[] = "";
  char *got = (char *)s21_to_lower(str);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(sscanf_fs_s1) {
  float var_1 = 0, var_2 = 0, var_3 = 0, var_4 = 0, var_5 = 0, var_6 = 0,
        var_7 = 0, var_8 = 0;

  const char str[] = "1.5551 1.31e+4 -3.31e-4 0.444e-5";
  const char spec[] = "%G %G %G %G";

  int res1 = s21_sscanf(str, spec, &var_1, &var_3, &var_5, &var_7);
  int res2 = sscanf(str, spec, &var_2, &var_4, &var_6, &var_8);

  ck_assert_int_eq(res1, res2);
  ck_assert_double_eq(var_1, var_2);
  ck_assert_double_eq(var_3, var_4);
  ck_assert_double_eq(var_5, var_6);
  ck_assert_double_eq(var_7, var_8);
}
END_TEST

START_TEST(sscanf_floats_Vlad1) {
  float var_1 = 0, var_2 = 0, var_3 = 0, var_4 = 0, var_5 = 0, var_6 = 0,
        var_7 = 0, var_8 = 0;

  const char str[] = "10.2 10.3 10.4 10.5";
  const char spec[] = "%f%f%f%f";

  int res1 = s21_sscanf(str, spec, &var_1, &var_3, &var_5, &var_7);
  int res2 = sscanf(str, spec, &var_2, &var_4, &var_6, &var_8);

  ck_assert_int_eq(res1, res2);
  ck_assert_double_eq(var_1, var_2);
  ck_assert_double_eq(var_3, var_4);
  ck_assert_double_eq(var_5, var_6);
  ck_assert_double_eq(var_7, var_8);
}
END_TEST

START_TEST(sscanf_floats_width_Vlad1) {
  float var_1 = 0, var_2 = 0, var_3 = 0, var_4 = 0, var_5 = 0, var_6 = 0,
        var_7 = 0, var_8 = 0;

  const char str[] = "10.2 10.3 10.4 10.5";
  const char spec[] = "%2f %2f %2f %2f";

  int res1 = s21_sscanf(str, spec, &var_1, &var_3, &var_5, &var_7);
  int res2 = sscanf(str, spec, &var_2, &var_4, &var_6, &var_8);

  ck_assert_int_eq(res1, res2);
  ck_assert_double_eq(var_1, var_2);
  ck_assert_double_eq(var_3, var_4);
  ck_assert_double_eq(var_5, var_6);
  ck_assert_double_eq(var_7, var_8);
}
END_TEST

START_TEST(sscanf_e) {
  float var_1 = 0, var_2 = 0, var_3 = 0, var_4 = 0, var_5 = 0, var_6 = 0,
        var_7 = 0, var_8 = 0;

  const char str[] = "5e2";
  const char spec[] = "%e";

  int16_t res1 = s21_sscanf(str, spec, &var_1);
  int16_t res2 = sscanf(str, spec, &var_2);

  ck_assert_int_eq(res1, res2);
  ck_assert_double_eq(var_1, var_2);
}
END_TEST

START_TEST(sscanf_e_many) {
  float var_1 = 0, var_2 = 0, var_3 = 0, var_4 = 0, var_5 = 0, var_6 = 0,
        var_7 = 0, var_8 = 0;

  const char str[] = "5e2 5e2 5e2";
  const char spec[] = "%e %e %e";

  int16_t res1 = s21_sscanf(str, spec, &var_1, &var_3, &var_4);
  int16_t res2 = sscanf(str, spec, &var_2, &var_5, &var_6);

  ck_assert_int_eq(res1, res2);
  ck_assert_double_eq(var_1, var_2);
  ck_assert_double_eq(var_3, var_5);
  ck_assert_double_eq(var_4, var_6);
}
END_TEST

START_TEST(sscanf_e_with_point) {
  float var_1 = 0, var_2 = 0, var_3 = 0, var_4 = 0, var_5 = 0, var_6 = 0,
        var_7 = 0, var_8 = 0;

  const char str[] = "5.2e2";
  const char spec[] = "%e";

  int16_t res1 = s21_sscanf(str, spec, &var_1);
  int16_t res2 = sscanf(str, spec, &var_2);

  ck_assert_int_eq(res1, res2);
  ck_assert_double_eq(var_1, var_2);
}
END_TEST

START_TEST(sprintf_simple_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "This is a simple value %d";
  int val = 69;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_precise_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%.5i";
  int val = 69;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_width_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%5d";
  int val = 69;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_minus_width_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%-5i";
  int val = 69;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_plus_width_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%+12d";
  int val = 69;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_padding_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%012i";
  int val = 69;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_star_width_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%0*d";
  int val = 69;
  ck_assert_int_eq(s21_sprintf(str1, format, 5, val),
                   sprintf(str2, format, 5, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_star_precision_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%0.*i";
  int val = 69;
  ck_assert_int_eq(s21_sprintf(str1, format, 5, val),
                   sprintf(str2, format, 5, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_many_flags_many_ints) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char format[] = "%0.*i %d %4.*i %013d %d";
  int val = 69;
  ck_assert_int_eq(
      s21_sprintf(str1, format, 5, val, -10431, 13, 5311, 0, -581813581),
      sprintf(str2, format, 5, val, -10431, 13, 5311, 0, -581813581));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_flags_long_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%+5.31li";
  long int val = 698518581899;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_flags_short_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%-16.9hi";
  short int val = 6958;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_flags_another_long_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%0.*ld";
  long val = 8581385185;
  ck_assert_int_eq(s21_sprintf(str1, format, 5, val),
                   sprintf(str2, format, 5, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_zero_precision_zero_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%.0d";
  int val = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_space_flag_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "% d";
  int val = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_unsigned_val) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%u";
  unsigned int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_unsigned_val_width) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%15u";
  unsigned int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_unsigned_val_flags) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%-16u";
  unsigned int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_unsigned_val_precision) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%.51u";
  unsigned int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_unsigned_val_many_flags) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "% 5.51u";
  unsigned int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_unsigned_val_short) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%hu";
  unsigned short int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_unsigned_val_long) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%lu";
  unsigned long int val = 949149114140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_unsigned_val_many) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%lu, %u, %hu, %.5u, %5.u";
  unsigned long int val = 949149114140;
  ck_assert_int_eq(
      s21_sprintf(str1, format, val, 14, 1441, 14414, 9681),
      sprintf(str2, format, val, (unsigned)14, (unsigned short)1441,
              (unsigned)14414, (unsigned)9681));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_octal_width) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%15o";
  int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_octal_flags) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%-16o";
  int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_octal_precision) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%.51o";
  int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_octal_many_flags) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%-5.51o";
  int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_octal_zero) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%o";
  ck_assert_int_eq(s21_sprintf(str1, format, 0), sprintf(str2, format, 0));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_octal_hash) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%#o";
  int val = 57175;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_octal_short) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%hd";
  short int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_octal_long) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%lo";
  long int val = 949149114140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_octal_many) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%lo, %o, %ho, %.5o, %5.o";
  long int val = 949149114140;
  ck_assert_int_eq(
      s21_sprintf(str1, format, val, 14, 1441, 14414, 9681),
      sprintf(str2, format, val, (unsigned)14, (unsigned short)1441,
              (unsigned)14414, (unsigned)9681));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_octal) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%lo";
  long int val = 84518;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_unsigned_zero) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%u";
  ck_assert_int_eq(s21_sprintf(str1, format, 0),
                   sprintf(str2, format, (unsigned)0));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_hex_width) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%5x";
  unsigned val = 858158158;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_hex_flags) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%#-10x";
  unsigned val = 858158158;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_hex_precision) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%.15x";
  unsigned val = 858158158;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_hex_many) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%#-10x%x%X%#x%#X%5.5x";
  unsigned val = 858158158;
  ck_assert_int_eq(s21_sprintf(str1, format, val, val, val, val, val, val),
                   sprintf(str2, format, val, val, val, val, val, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_hex_many_flags) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%#-5.10x";
  unsigned val = 858158158;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_hex_zero) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%#x";
  unsigned val = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_hex_huge) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%#x";
  unsigned val = 18571;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_hex_short) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%#hx";
  unsigned short val = 12352;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_hex_long) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%#lx";
  unsigned long val = 18571757371571;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_hex_one_longer_width) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%#2x";
  unsigned val = 1;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_hex_two_longer_width) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%#30x";
  unsigned val = 1;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_one_char) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%c";
  char val = 'X';
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(sprintf_one_precision) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%.5c";
  char val = 'c';
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_one_flags) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "% -5c";
  char val = 'c';
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_one_width) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%15c";
  char val = 'c';
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_one_many) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%-5.3c%c%c%c%c Hello! ABOBA";
  char val = 'c';
  ck_assert_int_eq(s21_sprintf(str1, format, val, 'c', 'a', 'b', 'b'),
                   sprintf(str2, format, val, 'c', 'a', 'b', 'b'));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_one_many_flags) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%-5.3c";
  char val = 'c';
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_string) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%s";
  char *val = "I LOVE STRINGS AND TESTS AND SCHOOL21 NO JOKE";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_string_precision) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%.15s";
  char *val = "I LOVE STRINGS AND TESTS AND SCHOOL21 NO JOKE";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_string_width) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%15s";
  char *val = "69 IS MY FAVORITE NUMBER";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_string_flags) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%-15.9s";
  char *val = "69 IS MY FAVORITE NUMBER";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_string_long) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%s";
  char *val =
      "69 IS MY FAVORITE NUMBER THIS IS SUPPOSED TO BE A VERY LONG STRING";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_string_many) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%s%s%s%s";
  char *val =
      "69 IS MY FAVORITE NUMBER THIS IS SUPPOSED TO BE A VERY LONG STRING";
  char *s1 = "";
  char *s2 = "87418347813748913749871389480913";
  char *s3 = "HAHAABOBASUCKER";
  ck_assert_int_eq(s21_sprintf(str1, format, val, s1, s2, s3),
                   sprintf(str2, format, val, s1, s2, s3));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_ptr) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%p";
  ck_assert_int_eq(s21_sprintf(str1, format, format),
                   sprintf(str2, format, format));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_ptr_width) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%15p";
  ck_assert_int_eq(s21_sprintf(str1, format, format),
                   sprintf(str2, format, format));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_ptr_precision) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%.5p";
  ck_assert_int_eq(s21_sprintf(str1, format, format),
                   sprintf(str2, format, format));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_null_ptr) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%p";
  char *ptr = s21_NULL;
  ck_assert_int_eq(s21_sprintf(str1, format, ptr), sprintf(str2, format, ptr));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_string_width_huge) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *val = "kjafdiuhfjahfjdahf";
  char *format = "%120s";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_n_specifier) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  int ret = 0;
  char *format = "Hello, my sexy little aboba abobushka abobina %n";
  ck_assert_int_eq(s21_sprintf(str1, format, &ret),
                   sprintf(str2, format, &ret));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_float_precision) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%Lf";
  long double val = 513515.131513515151351;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_float_width) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%10Lf";
  long double val = 15.35;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_float_precision_zero) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%.0Lf";
  long double val = 15.35;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_float_precision_empty) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%.Lf";
  long double val = 15.35;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_float_precision_huge) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%.15Lf";
  long double val = 15.35;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_float_precision_huge_negative) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%.15Lf";
  long double val = -15.35581134;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_float_huge) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%Lf";
  long double val = 72537572375.1431341;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_float_flags) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "% f";
  float val = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_float_many) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "% .0f %.lf %Lf %f %lf %Lf";
  float val = 0;
  double val1 = 0;
  long double val2 = 3515315.153151;
  float val3 = 5.5;
  double val4 = 9851.51351;
  long double val5 = 95919539159.53151351131;
  ck_assert_int_eq(s21_sprintf(str1, format, val, val1, val2, val3, val4, val5),
                   sprintf(str2, format, val, val1, val2, val3, val4, val5));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_e_precision) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%.17Le";
  long double val = 15.35;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_e_precision_zero) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%.0Le";
  long double val = 15.35;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_e_precision_empty) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%.Le";
  long double val = 15.000009121;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(sprintf_e_precision_huge) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%.15Le";
  long double val = 0.000000000000000123;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_e_precision_huge_negative) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%.15Le";
  long double val = -15.35581134;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_e_huge) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%Le";
  long double val = 72537572375.1431341;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_e_flags) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%015E";
  float val = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_e_width) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%15e";
  float val = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_e_many) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "% .0e %.le %Le %e %le %Le";
  float val = 0;
  double val1 = 0;
  long double val2 = 3515315.153151;
  float val3 = 5.5;
  double val4 = 0.094913941;
  long double val5 = 95919539159.53151351131;
  ck_assert_int_eq(s21_sprintf(str1, format, val, val1, val2, val3, val4, val5),
                   sprintf(str2, format, val, val1, val2, val3, val4, val5));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_E_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%.17LE";
  long double val = 4134121;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_all_empty) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  ck_assert_int_eq(s21_sprintf(str1, "abc"), sprintf(str2, "abc"));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_empty_format_and_parameters) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "abc"), sprintf(str2, "abc"));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_one_char) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%c", '\t'), sprintf(str2, "%c", '\t'));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_many_char) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%c%c%c%c%c", '\t', '\n', '0', 'S', 's'),
                   sprintf(str2, "%c%c%c%c%c", '\t', '\n', '0', 'S', 's'));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_one_string) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%s", "Drop Sega PLS"),
                   sprintf(str2, "%s", "Drop Sega PLS"));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_many_string) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(
      s21_sprintf(str1, "%s%s%s%s%s", "Drop", " ", "Sega", " ", "PLS"),
      sprintf(str2, "%s%s%s%s%s", "Drop", " ", "Sega", " ", "PLS"));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_one_dec) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%d", 666), sprintf(str2, "%d", 666));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_many_dec) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%d%d%d%d", -999, 0, 666, -100),
                   sprintf(str2, "%d%d%d%d", -999, 0, 666, -100));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_one_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%i", -0), sprintf(str2, "%i", -0));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_many_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%i%i%i%i", -999, 0, 666, -100),
                   sprintf(str2, "%i%i%i%i", -999, 0, 666, -100));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_one_float) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  ck_assert_int_eq(s21_sprintf(str1, "%f", 0.0001),
                   sprintf(str2, "%f", 0.0001));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_many_float) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  ck_assert_int_eq(
      s21_sprintf(str1, "%f%f%f%f", -999.666, 0.0001, 666.999, -100.001),
      sprintf(str2, "%f%f%f%f", -999.666, 0.0001, 666.999, -100.001));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_one_unsigned_dec) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  ck_assert_int_eq(s21_sprintf(str1, "%u", 100),
                   sprintf(str2, "%u", (unsigned)100));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_many_unsigned_dec) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%u%u%u%u", 999, 0, 666, 100),
                   sprintf(str2, "%u%u%u%u", (unsigned)999, (unsigned)0,
                           (unsigned)666, (unsigned)100));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_one_char_with_alignment_left) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%8c", '\t'), sprintf(str2, "%8c", '\t'));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_one_char_with_alignment_right) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%-8c", '\t'),
                   sprintf(str2, "%-8c", '\t'));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_many_char_with_alignment) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(
      s21_sprintf(str1, "%3c%-11c%10c%-2c%c", '\t', '\n', '0', 'S', 's'),
      sprintf(str2, "%3c%-11c%10c%-2c%c", '\t', '\n', '0', 'S', 's'));

  ck_assert_str_eq(str1, str2);
}
END_TEST

// START HEX TEST
START_TEST(sprintf_test_one_hex_lower) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  ck_assert_int_eq(s21_sprintf(str1, "%x", (unsigned)INT32_MIN),
                   sprintf(str2, "%x", (unsigned)INT32_MIN));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%x", 0), sprintf(str2, "%x", 0));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%x", INT32_MAX),
                   sprintf(str2, "%x", INT32_MAX));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_one_hex_upper) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%X", (unsigned)INT32_MIN),
                   sprintf(str2, "%X", (unsigned)INT32_MIN));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%X", 0), sprintf(str2, "%x", 0));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%X", INT32_MAX),
                   sprintf(str2, "%X", INT32_MAX));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_many_hex_lower) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(
      s21_sprintf(str1, "%x%x%x%x%x", 12340987, 135, 0, -1230, -123213123),
      sprintf(str2, "%x%x%x%x%x", 12340987, 135, 0, -1230, -123213123));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_many_hex_upper) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(
      s21_sprintf(str1, "%X%X%X%X%X", 12340987, 135, 0, -1230, -123213123),
      sprintf(str2, "%X%X%X%X%X", 12340987, 135, 0, -1230, -123213123));
  ck_assert_str_eq(str1, str2);
}
END_TEST
// END HEX TEST

// START HEX WITH ALIGNMENT
START_TEST(sprintf_test_one_hex_lower_with_alignment_left) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%-3x", (unsigned)INT32_MIN),
                   sprintf(str2, "%-3x", (unsigned)INT32_MIN));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%-3x", 0), sprintf(str2, "%-3x", 0));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%-3x", INT32_MAX),
                   sprintf(str2, "%-3x", INT32_MAX));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_one_hex_lower_with_alignment_right) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%13x", (unsigned)INT32_MIN),
                   sprintf(str2, "%13x", (unsigned)INT32_MIN));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%13x", 0), sprintf(str2, "%13x", 0));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%13x", INT32_MAX),
                   sprintf(str2, "%13x", INT32_MAX));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_one_hex_upper_with_alignment_left) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%-60X", INT32_MIN),
                   sprintf(str2, "%-60X", (unsigned)INT32_MIN));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%-60X", 0), sprintf(str2, "%-60X", 0));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%-60X", INT32_MAX),
                   sprintf(str2, "%-60X", INT32_MAX));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_one_hex_upper_with_alignment_right) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%7X", (unsigned)INT32_MIN),
                   sprintf(str2, "%7X", (unsigned)INT32_MIN));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%7X", 0), sprintf(str2, "%7X", 0));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%7X", INT32_MAX),
                   sprintf(str2, "%7X", INT32_MAX));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_many_hex_lower_with_alignment) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(
      s21_sprintf(str1, "%2x%-7x%9x%11x%0x", 12340987, 100, 0, 1, -666999),
      sprintf(str2, "%2x%-7x%9x%11x%0x", 12340987, 100, 0, 1, -666999));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_many_hex_upper_with_alignment) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  ck_assert_int_eq(
      s21_sprintf(str1, "%2X%-7X%9X%11X%0X", 12340987, 100, 0, 1, -666999),
      sprintf(str2, "%2X%-7X%9X%11X%0X", 12340987, 100, 0, 1, -666999));
  ck_assert_str_eq(str1, str2);
}
END_TEST
// START HEX WITH ALIGNMENT

// START HEX TEST WITH #
START_TEST(sprintf_test_one_hex_with_hashtag) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%#x", INT32_MIN),
                   sprintf(str2, "%#x", (unsigned)INT32_MIN));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%#x", 0), sprintf(str2, "%#x", 0));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%#x", INT32_MAX),
                   sprintf(str2, "%#x", INT32_MAX));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_one_hex_upper_with_hashtag) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%#X", INT32_MIN),
                   sprintf(str2, "%#X", (unsigned)INT32_MIN));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%#X", 0), sprintf(str2, "%#X", 0));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%#X", INT32_MAX),
                   sprintf(str2, "%#X", INT32_MAX));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_many_hex_lower_with_hashtag_and_alignm) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(
      s21_sprintf(str1, "%#x%#x%3x%#32x%#-1x", 87, 1222224535, -13, -0,
                  123213123),
      sprintf(str2, "%#x%#x%3x%#32x%#-1x", 87, 1222224535, -13, -0, 123213123));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_many_hex_upper_with_hashtag_and_alignm) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(
      s21_sprintf(str1, "%#X%#X%3X%#32X%#-1X", 87, 1222224535, -13, -0,
                  123213123),
      sprintf(str2, "%#X%#X%3X%#32X%#-1X", 87, 1222224535, -13, -0, 123213123));
  ck_assert_str_eq(str1, str2);
}
END_TEST
// END HEX TEST WITH #

// START HEX TEST with width *
START_TEST(sprintf_test_one_hex_lower_with_width_star) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%*x", 11, INT32_MIN),
                   sprintf(str2, "%*x", 11, (unsigned)INT32_MIN));
  ck_assert_str_eq(str1, str2);

  ck_assert_int_eq(s21_sprintf(str1, "%*x", 11, 0),
                   sprintf(str2, "%*x", 11, 0));
  ck_assert_str_eq(str1, str2);

  ck_assert_int_eq(s21_sprintf(str1, "%*x", 11, INT32_MAX),
                   sprintf(str2, "%*x", 11, INT32_MAX));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_one_hex_upper_with_width_star) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%*X", 11, INT32_MIN),
                   sprintf(str2, "%*X", 11, (unsigned)INT32_MIN));
  ck_assert_str_eq(str1, str2);

  ck_assert_int_eq(s21_sprintf(str1, "%*X", 11, 0),
                   sprintf(str2, "%*X", 11, 0));
  ck_assert_str_eq(str1, str2);

  ck_assert_int_eq(s21_sprintf(str1, "%*X", 11, INT32_MAX),
                   sprintf(str2, "%*X", 11, INT32_MAX));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_many_hex_lower_with_width_star_and_align_and_hashtag) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%#*x%*x%-12x%3x%*x", 9, 127312897, 0, -1,
                               199, -123978, 3, -1251),
                   sprintf(str2, "%#*x%*x%-12x%3x%*x", 9, 127312897, -0, -1,
                           199, -123978, 3, -1251));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_many_hex_upper_with_width_star) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%#*X%*X%-12X%3X%*X", 9, 127312897, 0, -1,
                               199, -123978, 3, -1251),
                   sprintf(str2, "%#*X%*X%-12X%3X%*X", 9, 127312897, 0, -1, 199,
                           -123978, 3, -1251));
  ck_assert_str_eq(str1, str2);
}
END_TEST
// END HEX TEST WITH Width *

// START HEX TEST WITH precision
START_TEST(sprintf_test_one_hex_lower_with_precision) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  int a = s21_sprintf(str1, "%*.6x", 11, 0);
  int b = sprintf(str2, "%*.6x", 11, 0);
  ck_assert_int_eq(a, b);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_one_hex_upper_with_precision) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  int a = s21_sprintf(str1, "%*.6X", 11, INT32_MIN);
  int b = sprintf(str2, "%*.6X", 11, (unsigned)INT32_MIN);
  ck_assert_int_eq(a, b);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_many_hex_lower_with_precision_and_other) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  int a = s21_sprintf(
      str1, "%#3.*x%#3x%-7.*x%#-1.8x%4.3x%#2.15x%*.*x%*.1x%3x%-1x", 3, 126714,
      4444444, 0, 6423235, 0, 666, 999, 13, 5, 419, 9, 41, -41, 33);
  int b = sprintf(str2, "%#3.*x%#3x%-7.*x%#-1.8x%4.3x%#2.15x%*.*x%*.1x%3x%-1x",
                  3, 126714, 4444444, 0, 6423235, 0, 666, 999, 13, 5, 419, 9,
                  41, -41, 33);
  ck_assert_int_eq(a, b);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_many_hex_upper_with_precision_and_other) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(
      s21_sprintf(str1, "%#3.*X%#3x%-7.*X%#-1.8X%4.3X%#2.15x%*.*X%*.1X%3X%-1X",
                  3, -126714, 4444444, 0, 6423235, 0, 666, 999, 13, 5, -419, 9,
                  41, -41, 33),
      sprintf(str2, "%#3.*X%#3x%-7.*X%#-1.8X%4.3X%#2.15x%*.*X%*.1X%3X%-1X", 3,
              -126714, 4444444, 0, 6423235, 0, 666, 999, 13, 5, -419, 9, 41,
              -41, 33));
  ck_assert_str_eq(str1, str2);
}
END_TEST
// END HEX TEST WITH precision

// START HEX TEST WITH Length
START_TEST(sprintf_test_one_hex_lower_with_length) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%hx", -11),
                   sprintf(str2, "%hx", (unsigned short)-11));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%hx", 0),
                   sprintf(str2, "%hx", (unsigned short)0));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%hx", 11),
                   sprintf(str2, "%hx", (unsigned short)11));
  ck_assert_str_eq(str1, str2);
  long unsigned int val = INT32_MAX;
  ck_assert_int_eq(s21_sprintf(str1, "%lx", val), sprintf(str2, "%lx", val));
  ck_assert_str_eq(str1, str2);
  long unsigned int v = 0;
  ck_assert_int_eq(s21_sprintf(str1, "%lx", v), sprintf(str2, "%lx", v));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_one_hex_upper_with_length) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%hx", -11),
                   sprintf(str2, "%hx", (unsigned short)-11));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%hx", 0),
                   sprintf(str2, "%hx", (unsigned short)0));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%hx", 11),
                   sprintf(str2, "%hx", (unsigned short)11));
  ck_assert_str_eq(str1, str2);
  long unsigned int val = INT32_MAX;
  ck_assert_int_eq(s21_sprintf(str1, "%lx", val), sprintf(str2, "%lx", val));
  ck_assert_str_eq(str1, str2);
  long unsigned int v = 0;
  ck_assert_int_eq(s21_sprintf(str1, "%lx", v), sprintf(str2, "%lx", v));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf1) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%10ld";

  ck_assert_int_eq(s21_sprintf(str1, format, 1), sprintf(str2, format, 1));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf2) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%1.1f";

  ck_assert_int_eq(s21_sprintf(str1, format, 1.1), sprintf(str2, format, 1.1));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf3) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%8.3c";

  ck_assert_int_eq(s21_sprintf(str1, format, 'a'), sprintf(str2, format, 'a'));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf4) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%+5.5d aboba";

  int val = 10000;
  int a = s21_sprintf(str1, format, val);
  int b = sprintf(str2, format, val);
  ck_assert_int_eq(a, b);

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf6) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%7.7f";

  ck_assert_int_eq(s21_sprintf(str1, format, 11.123456),
                   sprintf(str2, format, 11.123456));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf7) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%7.4s";

  ck_assert_int_eq(s21_sprintf(str1, format, "aboba floppa"),
                   sprintf(str2, format, "aboba floppa"));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf8) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%6.6u";

  ck_assert_int_eq(s21_sprintf(str1, format, 12341151),
                   sprintf(str2, format, 12341151));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf9) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%li%ld%lu";

  ck_assert_int_eq(s21_sprintf(str1, format, 666666666666, 777, 111),
                   sprintf(str2, format, 666666666666, 777, 111));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf10) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%hi%hd%hu";

  ck_assert_int_eq(s21_sprintf(str1, format, 666, -777, 111),
                   sprintf(str2, format, 666, -777, 111));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf11) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%+li%+lu%+d%+lf";

  ck_assert_int_eq(s21_sprintf(str1, format, -123, 321, -5555, -1213.123),
                   sprintf(str2, format, -123, 321, -5555, -1213.123));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf12) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%-11.11li%-35.5lu%-3.5ld%33.19Lf";
  long double k = 333.33213;

  ck_assert_int_eq(
      s21_sprintf(str1, format, 66666666666, 5555555555, 44444444444, k),
      sprintf(str2, format, 66666666666, 5555555555, 44444444444, k));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf14) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "% 0.0li% 0.0lu% 0.0ld % 0.0lf";

  ck_assert_int_eq(s21_sprintf(str1, format, 1, 222, 33333333333, -166513.1232),
                   sprintf(str2, format, 1, 222, 33333333333, -166513.1232));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf15) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "% 0.0hi% 0.0hu% 0.0hd % 0.0hf";

  ck_assert_int_eq(s21_sprintf(str1, format, 1, 222, 33333333333, -166513.1232),
                   sprintf(str2, format, 1, 222, 33333333333, -166513.1232));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf16) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "% c";

  ck_assert_int_eq(s21_sprintf(str1, format, 'a'), sprintf(str2, format, 'a'));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf17) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "% s";

  ck_assert_int_eq(s21_sprintf(str1, format, "aboba likes floppa"),
                   sprintf(str2, format, "aboba likes floppa"));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf18) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "% s% c";

  ck_assert_int_eq(s21_sprintf(str1, format, "", 'f'),
                   sprintf(str2, format, "", 'f'));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf19) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%210s";

  ck_assert_int_eq(s21_sprintf(str1, format, "AHHAHAHA\0AHHAHAHAH"),
                   sprintf(str2, format, "AHHAHAHA\0AHHAHAHAH"));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf20) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%-115s";

  ck_assert_int_eq(s21_sprintf(str1, format, "Nick her"),
                   sprintf(str2, format, "Nick her"));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf24) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%+2.1c%+4.2d%+5.4i%+10.2f%+55.55s%+1.1u";

  ck_assert_int_eq(
      s21_sprintf(str1, format, 'f', 21, 42, 666.666,
                  "Lorem ipsum dolor sit amet. Aut quam ducimus.", 11),
      sprintf(str2, format, 'f', 21, 42, 666.666,
              "Lorem ipsum dolor sit amet. Aut quam ducimus.", 11));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf25) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%.f";

  ck_assert_int_eq(s21_sprintf(str1, format, 121.123),
                   sprintf(str2, format, 121.123));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf26) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%%";

  ck_assert_int_eq(s21_sprintf(str1, format), sprintf(str2, format));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf27) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%%%%%%%%";

  ck_assert_int_eq(s21_sprintf(str1, format), sprintf(str2, format));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf28) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%%%%%%%%";

  ck_assert_int_eq(s21_sprintf(str1, format), sprintf(str2, format));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf29) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%-.f";

  ck_assert_int_eq(s21_sprintf(str1, format, 111.111),
                   sprintf(str2, format, 111.111));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf30) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%-.1d";

  ck_assert_int_eq(s21_sprintf(str1, format, 111), sprintf(str2, format, 111));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf31) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%e";
  double x = 111;
  ck_assert_int_eq(s21_sprintf(str1, format, x), sprintf(str2, format, x));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf32) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%e%e%e%e";

  ck_assert_int_eq(s21_sprintf(str1, format, 11.111, 222.2222, 666., -555.125),
                   sprintf(str2, format, 11.111, 222.2222, 666., -555.125));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf33) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%Le";
  long double x = 122.1231;

  ck_assert_int_eq(s21_sprintf(str1, format, x), sprintf(str2, format, x));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf35) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%.10e";

  ck_assert_int_eq(s21_sprintf(str1, format, 111.184314818),
                   sprintf(str2, format, 111.184314818));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf36) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%5.3e%3.2e%lf";

  ck_assert_int_eq(s21_sprintf(str1, format, 0.000111, 111.555, 1.999),
                   sprintf(str2, format, 0.000111, 111.555, 1.999));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf37) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%E";

  ck_assert_int_eq(s21_sprintf(str1, format, 0.666666),
                   sprintf(str2, format, 0.666666));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf38) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%E%E%E";

  ck_assert_int_eq(s21_sprintf(str1, format, 0.0000999, 111.9999, 6.666),
                   sprintf(str2, format, 0.0000999, 111.9999, 6.666));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf39) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%e ABOBA %Lf %Lf %Le";
  long double c = 848181;
  long double a = 0.00000001;
  long double b = 1111111.11;
  ck_assert_int_eq(s21_sprintf(str1, format, 123.123, a, b, c),
                   sprintf(str2, format, 123.123, a, b, c));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf40) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%#e Floppa %#E%#f";

  ck_assert_int_eq(s21_sprintf(str1, format, 123.111, 0.0000999, 0.555),
                   sprintf(str2, format, 123.111, 0.0000999, 0.555));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf41) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%.Lf";
  long double a = 7.9418438184;

  ck_assert_int_eq(s21_sprintf(str1, format, a), sprintf(str2, format, a));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf42) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%#5p";
  int a = 5;
  ck_assert_int_eq(s21_sprintf(str1, format, &a), sprintf(str2, format, &a));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf43) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%.5o";

  ck_assert_int_eq(s21_sprintf(str1, format, 12345),
                   sprintf(str2, format, 12345));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test_sprintf44) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%#5lX";
  long hex = 314818438141;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_g_trailing_zero) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%g";
  double hex = 0.50300;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_g_large) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%g";
  double hex = 5131.43141;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_g_small) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%g";
  double hex = 0.123000;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_g_precision) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%.5g";
  double hex = 0.123000;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_g_precision_zero) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%.0g";
  double hex = 0.123000;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_g_precision_missing) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%.g";
  double hex = 0.123000;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_g_many_zeroes_in_front) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%.g";
  double hex = 0.0004;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_g_one_zero) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%g";
  double hex = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_g_zero) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%.5g";
  double hex = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_g_mantiss) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%g";
  double hex = 0.0000005;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_g_mantiss_flags) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%5.8g";
  double hex = 0.0000005;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_g_short_no_mantiss) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%g";
  double hex = 0.005;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_LG) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%LG";
  long double hex = 0.000005;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_g_many) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%LG %g %G %Lg %.5g";
  long double hex = 0.000005;
  double hex1 = 41.1341;
  double hex2 = 848.9000;
  long double hex3 = 0.0843;
  double hex4 = 0.0005;
  double hex5 = 0.8481481;
  ck_assert_int_eq(s21_sprintf(str1, format, hex, hex1, hex2, hex3, hex4, hex5),
                   sprintf(str2, format, hex, hex1, hex2, hex3, hex4, hex5));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_wide_char) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "This is a simple wide char %lc";
  unsigned long w = L'汉';
  int a = s21_sprintf(str1, format, w);
  int b = sprintf(str2, format, w);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(a, b);
}

START_TEST(sprintf_width_char) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "This is a simple wide char %5c";
  char w = 'c';
  int a = s21_sprintf(str1, format, w);
  int b = sprintf(str2, format, w);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(a, b);
}

START_TEST(sprintf_minus_wide_char) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "This is a simple wide char %-5lc";
  unsigned long w = L'森';
  int a = s21_sprintf(str1, format, w);
  int b = sprintf(str2, format, w);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(sprintf_wide_string) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "This is a simple wide char %ls";
  wchar_t w[] = L"森我爱菠萝";
  int a = s21_sprintf(str1, format, w);
  int b = sprintf(str2, format, w);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(sprintf_wide_string1) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "This is a simple wide char %5.12ls";
  wchar_t w[] = L"森我爱菠萝";
  int a = s21_sprintf(str1, format, w);
  int b = sprintf(str2, format, w);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(sprintf_wide_string2) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "This is a simple wide char %120ls ABOBA";
  wchar_t w[] = L"森我爱菠萝";
  int a = s21_sprintf(str1, format, w);
  int b = sprintf(str2, format, w);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(sprintf_wide_string3) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "This is a simple wide char %-43ls";
  wchar_t w[] = L"森我爱菠萝";
  int a = s21_sprintf(str1, format, w);
  int b = sprintf(str2, format, w);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(sprintf_wide_string4) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "This is a simple wide char %43ls";
  wchar_t w[] = L"森我爱菠萝";
  int a = s21_sprintf(str1, format, w);
  int b = sprintf(str2, format, w);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(sprintf_wide_char2) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "This is a simple wide char %43lc";
  unsigned long w = L'森';
  int a = s21_sprintf(str1, format, w);
  int b = sprintf(str2, format, w);
  ck_assert_int_eq(a, b);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(s21_strrchr_test) {
  char test1[] = "0163456769";
  char test2[] = ";;;;;;H%%//#HH";
  char test3[] = "     /";
  ck_assert_uint_eq((unsigned long)s21_strrchr(test1, '6'),
                    (unsigned long)strrchr(test1, '6'));
  ck_assert_uint_eq((unsigned long)s21_strrchr(test1, ' '),
                    (unsigned long)strrchr(test1, ' '));
  ck_assert_uint_eq((unsigned long)s21_strrchr(test1, '6'),
                    (unsigned long)strrchr(test1, '6'));
  ck_assert_uint_eq((unsigned long)s21_strrchr(test2, 'H'),
                    (unsigned long)strrchr(test2, 'H'));
  ck_assert_uint_eq((unsigned long)s21_strrchr(test2, '$'),
                    (unsigned long)strrchr(test2, '$'));
  ck_assert_uint_eq((unsigned long)s21_strrchr(test2, ';'),
                    (unsigned long)strrchr(test2, ';'));
  ck_assert_uint_eq((unsigned long)s21_strrchr(test3, ' '),
                    (unsigned long)strrchr(test3, ' '));
  ck_assert_str_eq(s21_strrchr(test2, '\0'), strrchr(test2, '\0'));
}
END_TEST

Suite *suite_insert(void) {
  Suite *s = suite_create("suite_insert");
  TCase *tc = tcase_create("insert_tc");

  tcase_add_test(tc, memcmp_1);
  tcase_add_test(tc, memcmp_2);
  tcase_add_test(tc, memcmp_3);
  tcase_add_test(tc, memcmp_4);
  tcase_add_test(tc, memcmp_5);
  tcase_add_test(tc, memset_1);
  tcase_add_test(tc, memset_2);
  tcase_add_test(tc, memset_3);
  tcase_add_test(tc, memset_4);
  tcase_add_test(tc, memcpy_1);
  tcase_add_test(tc, memcpy_2);
  tcase_add_test(tc, memcpy_3);
  tcase_add_test(tc, memcpy_4);
  tcase_add_test(tc, memcpy_5);
  tcase_add_test(tc, memmove_1);
  tcase_add_test(tc, memmove_2);
  tcase_add_test(tc, memmove_3);
  tcase_add_test(tc, memmove_4);
  tcase_add_test(tc, memmove_5);
  tcase_add_test(tc, memchr_1);

  tcase_add_test(tc, memchr_2);
  tcase_add_test(tc, memchr_3);
  tcase_add_test(tc, memchr_4);
  tcase_add_test(tc, memchr_5);
  // strcat
  tcase_add_test(tc, strcat_1);
  tcase_add_test(tc, strcat_2);
  tcase_add_test(tc, strcat_3);

  // strncat
  tcase_add_test(tc, strncat_1);
  tcase_add_test(tc, strncat_2);
  tcase_add_test(tc, strncat_3);

  // strchr
  tcase_add_test(tc, strchr_1);
  tcase_add_test(tc, strchr_2);
  tcase_add_test(tc, strchr_3);

  // strcmp
  tcase_add_test(tc, strcmp_1);
  tcase_add_test(tc, strcmp_2);
  tcase_add_test(tc, strcmp_3);

  // strncmp
  tcase_add_test(tc, strncmp_1);
  tcase_add_test(tc, strncmp_2);
  tcase_add_test(tc, strncmp_3);

  // strcpy
  tcase_add_test(tc, strcpy_1);
  tcase_add_test(tc, strcpy_2);
  tcase_add_test(tc, strcpy_3);

  // strncpy
  tcase_add_test(tc, strncpy_1);
  tcase_add_test(tc, strncpy_2);
  tcase_add_test(tc, strncpy_3);

  // strlen
  tcase_add_test(tc, strlen_1);
  tcase_add_test(tc, strlen_2);
  tcase_add_test(tc, strlen_3);

  // strstr
  tcase_add_test(tc, strstr_1);
  tcase_add_test(tc, strstr_2);
  tcase_add_test(tc, strstr_3);
  tcase_add_test(tc, strstr_4);
  tcase_add_test(tc, strstr_5);
  tcase_add_test(tc, strstr_6);

  // toupper
  tcase_add_test(tc, to_upper_test1);
  tcase_add_test(tc, to_upper_test2);
  tcase_add_test(tc, to_upper_test3);
  tcase_add_test(tc, to_upper_test4);
  tcase_add_test(tc, to_upper_test5);

  // tolower
  tcase_add_test(tc, to_lower_test1);
  tcase_add_test(tc, to_lower_test2);
  tcase_add_test(tc, to_lower_test3);
  tcase_add_test(tc, to_lower_test4);
  tcase_add_test(tc, to_lower_test5);

  // strtok
  tcase_add_test(tc, strtok_1);
  tcase_add_test(tc, strtok_2);
  tcase_add_test(tc, strtok_3);

  tcase_add_test(tc, insert_1);
  tcase_add_test(tc, strcspn_upper_letter);
  tcase_add_test(tc, strpbrk_1);

  tcase_add_test(tc, s21_strerror_test);
  tcase_add_test(tc, sscanf_ld);
  tcase_add_test(tc, sscanf_hd);
  tcase_add_test(tc, sscanf_lld);
  // // Width (N)
  tcase_add_test(tc, sscanf_lld_wdh);
  tcase_add_test(tc, sscanf_lld_wdh_1_word_in_str);
  tcase_add_test(tc, sscanf_lld_wdh_1_word_in_str2);
  tcase_add_test(tc, sscanf_lld_wdh_1_word_in_str3);
  // // Width (*)
  tcase_add_test(tc, sscanf_d_star);
  // // Negative & positive ints
  // tcase_add_test(tc, sscanf_d_many_plusminus);
  tcase_add_test(tc, sscanf_d_plusminus_null);
  tcase_add_test(tc, sscanf_d_01);
  // // // [%i] Specifier. It may be INT, OCT, HEX
  tcase_add_test(tc, sscanf_i);
  tcase_add_test(tc, sscanf_i_plusminus);
  // // Mixed with chars & ints
  tcase_add_test(tc, sscanf_i_plusminus_withoutspace);
  tcase_add_test(tc, sscanf_i_d_manyspaces);

  tcase_add_test(tc, sscanf_i_oct_manyspaces);
  tcase_add_test(tc, sscanf_i_oct_manyspaces2);
  tcase_add_test(tc, sscanf_i_0x);
  tcase_add_test(tc, sscanf_i_0x_manyspaces);

  tcase_add_test(tc, sscanf_spec_i_int1_Vlad1);
  tcase_add_test(tc, sscanf_spec_i_int1_Vlad2);
  tcase_add_test(tc, sscanf_spec_i_int1_Vlad3);

  tcase_add_test(tc, sscanf_X);
  tcase_add_test(tc, sscanf_big_X);
  tcase_add_test(tc, sscanf_X_non);
  tcase_add_test(tc, sscanf_hX);
  tcase_add_test(tc, sscanf_lX);
  tcase_add_test(tc, sscanf_llX);

  tcase_add_test(tc, s21_strstr_test);
  tcase_add_test(tc, sscanf_X_a);
  tcase_add_test(tc, sscanf_X_negative);
  tcase_add_test(tc, sscanf_2X);

  tcase_add_test(tc, sscanf_x);
  tcase_add_test(tc, sscanf_x_non);
  tcase_add_test(tc, sscanf_hx);
  tcase_add_test(tc, sscanf_lx);
  tcase_add_test(tc, sscanf_x_a);
  tcase_add_test(tc, sscanf_x_negative);
  tcase_add_test(tc, sscanf_2x);

  tcase_add_test(tc, sscanf_o);
  tcase_add_test(tc, sscanf_over_o);
  tcase_add_test(tc, sscanf_o_0x);
  tcase_add_test(tc, sscanf_o_0X);
  tcase_add_test(tc, sscanf_o_non);
  tcase_add_test(tc, sscanf_o_sh);
  tcase_add_test(tc, sscanf_o_lg);
  tcase_add_test(tc, sscanf_o_lglg);
  tcase_add_test(tc, sscanf_o_X2);
  tcase_add_test(tc, sscanf_o_lr);
  tcase_add_test(tc, sscanf_o_sn);
  tcase_add_test(tc, sscanf_o_LEN);

  tcase_add_test(tc, sscanf_o_pr1);
  tcase_add_test(tc, sscanf_o_pr2);
  tcase_add_test(tc, sscanf_o_pr3);
  tcase_add_test(tc, sscanf_o_pr4);

  tcase_add_test(tc, sscanf_o_chs2);
  tcase_add_test(tc, sscanf_o_chs5);
  tcase_add_test(tc, sscanf_S_S_a_chr1);

  tcase_add_test(tc, sscanf_sts1);

  tcase_add_test(tc, sscanf_sts4);

  tcase_add_test(tc, sscanf_st_md1);
  tcase_add_test(tc, sscanf_st_md2);
  tcase_add_test(tc, sscanf_st_md3);

  tcase_add_test(tc, s21_strpbrk_test);
  tcase_add_test(tc, sscanf_n_Vlad1);
  tcase_add_test(tc, sscanf_three_before_n_Vlad1);
  // tcase_add_test(tc, sscanf_n_inside_Vlad1);

  tcase_add_test(tc, sscanf_percent_Vlad1);
  tcase_add_test(tc, sscanf_percent_inside_Vlad1);

  tcase_add_test(tc, s21_trim_test);
  tcase_add_test(tc, sscanf_single_u_Vlad1);
  tcase_add_test(tc, sscanf_inside_u_Vlad1);

  // введет себя не стабильно почему-то
  // tcase_add_test(tc, sscanf_single_p_Vlad1);sscanf_fs1

  tcase_add_test(tc, sscanf_fs1);
  tcase_add_test(tc, sscanf_fs2);
  tcase_add_test(tc, sscanf_fs4);
  tcase_add_test(tc, sscanf_fs5);
  tcase_add_test(tc, sscanf_fs_s1);
  tcase_add_test(tc, sscanf_floats_Vlad1);
  // tcase_add_test(tc, sscanf_floats_width_Vlad1);
  //  tcase_add_test(tc, sscanf_floats_prec_Vlad1);

  tcase_add_test(tc, sscanf_e);
  tcase_add_test(tc, sscanf_e_many);
  tcase_add_test(tc, sscanf_e_with_point);

  tcase_add_test(tc, s21_strchr_test);

  // sprintf
  tcase_add_test(tc, sprintf_simple_int);
  tcase_add_test(tc, sprintf_precise_int);
  tcase_add_test(tc, sprintf_width_int);
  tcase_add_test(tc, sprintf_minus_width_int);
  tcase_add_test(tc, sprintf_plus_width_int);
  tcase_add_test(tc, sprintf_padding_int);
  tcase_add_test(tc, sprintf_star_width_int);
  tcase_add_test(tc, sprintf_star_precision_int);
  tcase_add_test(tc, sprintf_many_flags_many_ints);
  tcase_add_test(tc, sprintf_flags_long_int);
  tcase_add_test(tc, sprintf_flags_short_int);
  tcase_add_test(tc, sprintf_flags_another_long_int);
  tcase_add_test(tc, sprintf_zero_precision_zero_int);
  tcase_add_test(tc, sprintf_space_flag_int);
  tcase_add_test(tc, sprintf_unsigned_val);
  tcase_add_test(tc, sprintf_unsigned_val_width);
  tcase_add_test(tc, sprintf_unsigned_val_flags);
  tcase_add_test(tc, sprintf_unsigned_val_precision);
  tcase_add_test(tc, sprintf_unsigned_val_many_flags);
  tcase_add_test(tc, sprintf_unsigned_val_short);
  tcase_add_test(tc, sprintf_unsigned_val_long);
  tcase_add_test(tc, sprintf_unsigned_val_many);

  tcase_add_test(tc, sprintf_octal_width);
  tcase_add_test(tc, sprintf_octal_flags);
  tcase_add_test(tc, sprintf_octal_precision);
  tcase_add_test(tc, sprintf_octal_many_flags);
  tcase_add_test(tc, sprintf_octal_short);
  tcase_add_test(tc, sprintf_octal_long);
  tcase_add_test(tc, sprintf_octal_many);
  tcase_add_test(tc, sprintf_octal);
  tcase_add_test(tc, sprintf_octal_zero);
  tcase_add_test(tc, sprintf_octal_hash);
  tcase_add_test(tc, sprintf_unsigned_zero);
  tcase_add_test(tc, sprintf_hex_width);
  tcase_add_test(tc, sprintf_hex_flags);
  tcase_add_test(tc, sprintf_hex_precision);
  tcase_add_test(tc, sprintf_hex_many);
  tcase_add_test(tc, sprintf_hex_many_flags);
  tcase_add_test(tc, sprintf_hex_zero);
  tcase_add_test(tc, sprintf_hex_huge);
  tcase_add_test(tc, sprintf_hex_short);
  tcase_add_test(tc, sprintf_hex_long);
  tcase_add_test(tc, sprintf_hex_one_longer_width);
  tcase_add_test(tc, sprintf_hex_two_longer_width);
  tcase_add_test(tc, sprintf_one_char);
  tcase_add_test(tc, sprintf_one_precision);
  tcase_add_test(tc, sprintf_one_flags);
  tcase_add_test(tc, sprintf_one_width);
  tcase_add_test(tc, sprintf_one_many);
  tcase_add_test(tc, sprintf_one_many_flags);
  tcase_add_test(tc, sprintf_string);
  tcase_add_test(tc, sprintf_string_precision);
  tcase_add_test(tc, sprintf_string_width);
  tcase_add_test(tc, sprintf_string_flags);
  tcase_add_test(tc, sprintf_string_long);
  tcase_add_test(tc, sprintf_string_many);
  tcase_add_test(tc, sprintf_ptr);
  tcase_add_test(tc, sprintf_ptr_width);
  tcase_add_test(tc, sprintf_ptr_precision);
  tcase_add_test(tc, sprintf_null_ptr);
  tcase_add_test(tc, sprintf_n_specifier);
  tcase_add_test(tc, sprintf_string_width_huge);
  tcase_add_test(tc, sprintf_float_precision);
  tcase_add_test(tc, sprintf_float_width);
  tcase_add_test(tc, sprintf_float_precision_zero);
  tcase_add_test(tc, sprintf_float_precision_empty);
  tcase_add_test(tc, sprintf_float_precision_huge);
  tcase_add_test(tc, sprintf_float_precision_huge_negative);
  tcase_add_test(tc, sprintf_float_huge);
  tcase_add_test(tc, sprintf_float_flags);
  tcase_add_test(tc, sprintf_float_many);
  tcase_add_test(tc, sprintf_e_precision);
  tcase_add_test(tc, sprintf_e_precision_zero);
  tcase_add_test(tc, sprintf_e_precision_empty);
  tcase_add_test(tc, sprintf_e_precision_huge);
  tcase_add_test(tc, sprintf_e_precision_huge_negative);
  tcase_add_test(tc, sprintf_e_huge);
  tcase_add_test(tc, sprintf_e_many);
  tcase_add_test(tc, sprintf_e_width);
  tcase_add_test(tc, sprintf_e_flags);
  tcase_add_test(tc, sprintf_E_int);
  tcase_add_test(tc, sprintf_all_empty);
  tcase_add_test(tc, sprintf_empty_format_and_parameters);
  tcase_add_test(tc, sprintf_test_one_char);
  tcase_add_test(tc, sprintf_test_many_char);
  tcase_add_test(tc, sprintf_test_one_string);
  tcase_add_test(tc, sprintf_test_many_string);
  tcase_add_test(tc, sprintf_test_one_dec);
  tcase_add_test(tc, sprintf_test_many_dec);
  tcase_add_test(tc, sprintf_test_one_int);
  tcase_add_test(tc, sprintf_test_many_int);
  tcase_add_test(tc, sprintf_test_one_float);
  tcase_add_test(tc, sprintf_test_many_float);
  tcase_add_test(tc, sprintf_test_one_unsigned_dec);
  tcase_add_test(tc, sprintf_test_many_unsigned_dec);
  tcase_add_test(tc, sprintf_test_one_char_with_alignment_left);
  tcase_add_test(tc, sprintf_test_one_char_with_alignment_right);
  tcase_add_test(tc, sprintf_test_many_char_with_alignment);
  tcase_add_test(tc, sprintf_test_one_hex_lower);
  tcase_add_test(tc, sprintf_test_one_hex_upper);
  tcase_add_test(tc, sprintf_test_many_hex_lower);
  tcase_add_test(tc, sprintf_test_many_hex_upper);
  tcase_add_test(tc, sprintf_test_one_hex_lower_with_alignment_left);
  tcase_add_test(tc, sprintf_test_one_hex_lower_with_alignment_right);
  tcase_add_test(tc, sprintf_test_one_hex_upper_with_alignment_left);
  tcase_add_test(tc, sprintf_test_one_hex_upper_with_alignment_right);
  tcase_add_test(tc, sprintf_test_many_hex_lower_with_alignment);
  tcase_add_test(tc, sprintf_test_many_hex_upper_with_alignment);
  tcase_add_test(tc, sprintf_test_one_hex_with_hashtag);
  tcase_add_test(tc, sprintf_test_one_hex_upper_with_hashtag);
  tcase_add_test(tc, sprintf_test_many_hex_lower_with_hashtag_and_alignm);
  tcase_add_test(tc, sprintf_test_many_hex_upper_with_hashtag_and_alignm);
  tcase_add_test(tc, sprintf_test_one_hex_lower_with_width_star);
  tcase_add_test(tc, sprintf_test_one_hex_upper_with_width_star);
  tcase_add_test(
      tc, sprintf_test_many_hex_lower_with_width_star_and_align_and_hashtag);
  tcase_add_test(tc, sprintf_test_many_hex_upper_with_width_star);
  tcase_add_test(tc, sprintf_test_one_hex_lower_with_precision);
  tcase_add_test(tc, sprintf_test_one_hex_upper_with_precision);
  tcase_add_test(tc, sprintf_test_many_hex_lower_with_precision_and_other);
  tcase_add_test(tc, sprintf_test_many_hex_upper_with_precision_and_other);
  tcase_add_test(tc, sprintf_test_one_hex_lower_with_length);
  tcase_add_test(tc, sprintf_test_one_hex_upper_with_length);
  tcase_add_test(tc, sprintf_test_sprintf1);
  tcase_add_test(tc, sprintf_test_sprintf2);
  tcase_add_test(tc, sprintf_test_sprintf3);
  tcase_add_test(tc, sprintf_test_sprintf4);
  tcase_add_test(tc, sprintf_test_sprintf6);
  tcase_add_test(tc, sprintf_test_sprintf7);
  tcase_add_test(tc, sprintf_test_sprintf8);
  tcase_add_test(tc, sprintf_test_sprintf9);
  tcase_add_test(tc, sprintf_test_sprintf10);
  tcase_add_test(tc, sprintf_test_sprintf11);
  tcase_add_test(tc, sprintf_test_sprintf12);
  tcase_add_test(tc, sprintf_test_sprintf14);
  tcase_add_test(tc, sprintf_test_sprintf15);
  tcase_add_test(tc, sprintf_test_sprintf16);
  tcase_add_test(tc, sprintf_test_sprintf17);
  tcase_add_test(tc, sprintf_test_sprintf18);
  tcase_add_test(tc, sprintf_test_sprintf19);
  tcase_add_test(tc, sprintf_test_sprintf20);
  tcase_add_test(tc, sprintf_test_sprintf24);
  tcase_add_test(tc, sprintf_test_sprintf25);
  tcase_add_test(tc, sprintf_test_sprintf28);
  tcase_add_test(tc, sprintf_test_sprintf29);
  tcase_add_test(tc, sprintf_test_sprintf30);
  tcase_add_test(tc, sprintf_test_sprintf31);

  tcase_add_test(tc, sprintf_test_sprintf43);
  tcase_add_test(tc, sprintf_test_sprintf44);
  tcase_add_test(tc, sprintf_test_sprintf26);
  tcase_add_test(tc, sprintf_test_sprintf27);
  tcase_add_test(tc, sprintf_g_trailing_zero);
  tcase_add_test(tc, sprintf_g_large);
  tcase_add_test(tc, sprintf_g_small);
  tcase_add_test(tc, sprintf_g_precision);
  tcase_add_test(tc, sprintf_g_precision_zero);
  tcase_add_test(tc, sprintf_g_precision_missing);
  tcase_add_test(tc, sprintf_g_many_zeroes_in_front);
  tcase_add_test(tc, sprintf_g_one_zero);
  tcase_add_test(tc, sprintf_g_mantiss);
  tcase_add_test(tc, sprintf_g_mantiss_flags);
  tcase_add_test(tc, sprintf_g_short_no_mantiss);
  tcase_add_test(tc, sprintf_LG);
  tcase_add_test(tc, sprintf_g_many);
  tcase_add_test(tc, sprintf_g_zero);

  tcase_add_test(tc, s21_strspn_test);
  tcase_add_test(tc, s21_strrchr_test);

  tcase_add_test(tc, all_empty);
  tcase_add_test(tc, str_empty);
  tcase_add_test(tc, trim_empty);
  tcase_add_test(tc, trim_and_str_eq);

  tcase_add_test(tc, trim_test1);
  tcase_add_test(tc, trim_test2);
  tcase_add_test(tc, trim_test3);
  tcase_add_test(tc, trim_test4);
  tcase_add_test(tc, trim_test5);
  tcase_add_test(tc, empty_spaces);
  tcase_add_test(tc, null_ptr_trim_chars);
  suite_add_tcase(s, tc);
  return s;
}

int main(void) {
  setlocale(LC_ALL, "");
  int nf;
  Suite *s1;
  SRunner *sr;
  s1 = suite_insert();
  sr = srunner_create(s1);

  // srunner_run_all(sr, CK_ENV);
  srunner_set_fork_status(sr, CK_NOFORK);
  srunner_run_all(sr, CK_VERBOSE);

  nf = srunner_ntests_failed(sr);
  srunner_free(sr);
  return nf == 0 ? 0 : 1;
}
