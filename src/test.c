#include <check.h>
#include <stdio.h>
#include <string.h>
#include "s21_string.h"
#include <stdarg.h>
#include <stdlib.h>

START_TEST(check_memcmp) {
    char str01[50] = "Hello";
    char str02[50] = "Hello";
    char str11[50] = "wollov";
    char str12[50] = "World";
    char str21[50] = "125";
    char str22[50] = "123";
    s21_size_t m = 5;

    ck_assert(((s21_memcmp(str01, str02, m) > 0) && (memcmp(str01, str02, m) > 0)) ||
               ((s21_memcmp(str01, str02, m) < 0) && (memcmp(str01, str02, m) < 0)) ||
               ((s21_memcmp(str01, str02, m) == 0) && (memcmp(str01, str02, m) == 0)));
    ck_assert(((s21_memcmp(str11, str12, m) > 0) && (memcmp(str11, str12, m) > 0)) ||
               ((s21_memcmp(str11, str12, m) < 0) && (memcmp(str11, str12, m) < 0)) ||
               ((s21_memcmp(str11, str12, m) == 0) && (memcmp(str11, str12, m) == 0)));
    ck_assert(((s21_memcmp(str21, str22, m) > 0) && (memcmp(str21, str22, m) > 0)) ||
               ((s21_memcmp(str21, str22, m) < 0) && (memcmp(str21, str22, m) < 0)) ||
              ((s21_memcmp(str21, str22, m) == 0) && (memcmp(str21, str22, m) == 0)));
}
END_TEST

START_TEST(check_strcat) {
    char str01[50] = "Hello";
    char str02[50] = "Hello";
    char dest1[50] = "-3";
    char src1[50] = "Ok";
    char dest2[50] = "";
    char src2[50] = "Ok";

    ck_assert(s21_strcat(str01, str02) == strcat(str01, str02));
    ck_assert(s21_strcat(dest1, src1) == strcat(dest1, src1));
    ck_assert(s21_strcat(dest2, src2) == strcat(dest2, src2));
}
END_TEST

START_TEST(check_strcspn) {
    char str111[50] = "123456789";
    char str121[50] = "123456";
    char str211[50] = " ";
    char str221[50] = "World";
    char str01[50] = "Hello";
    char str02[50] = "Hello";

    ck_assert_uint_eq(s21_strcspn(str01, str02), strcspn(str01, str02));
    ck_assert_uint_eq(s21_strcspn(str111, str121), strcspn(str111, str121));
    ck_assert_uint_eq(s21_strcspn(str211, str221), strcspn(str211, str221));
}
END_TEST

START_TEST(check_strspn) {
    char str111[50] = "123456789";
    char str121[50] = "123456";
    char str211[50] = " ";
    char str221[50] = "World";
    char str01[50] = "Hello";
    char str02[50] = "Hello";

    ck_assert_uint_eq(strspn(str01, str02), s21_strspn(str01, str02));
    ck_assert_uint_eq(strspn(str111, str121), s21_strspn(str111, str121));
    ck_assert_uint_eq(strspn(str211, str221), s21_strspn(str211, str221));
}
END_TEST

START_TEST(check_strlen) {
    char str0[50] = "test_string";
    char str1[50] = "";
    char str2[50] = "test\nstring";

    ck_assert_uint_eq(strlen(str0), s21_strlen(str0));
    ck_assert_uint_eq(strlen(str1), s21_strlen(str1));
    ck_assert_uint_eq(strlen(str2), s21_strlen(str2));
}
END_TEST

START_TEST(check_strcpy) {
    char dest[100];
    char str30[22] = "test_string";
    char str31[10] = "";
    char str32[22] = "test\nstring";

    ck_assert(strcpy(dest, str30) == s21_strcpy(dest, str30));
    ck_assert(strcpy(dest, str31) == s21_strcpy(dest, str31));
    ck_assert(strcpy(dest, str32) == s21_strcpy(dest, str32));
}
END_TEST

START_TEST(check_strncpy) {
    char dest[100];
    char dest3[100];
    char str33[22] = "test_string";
    char str34[10] = "";
    char str35[6] = "test\ns";

    ck_assert(strncpy(dest, str33, 15) == s21_strncpy(dest, str33, 15));
    ck_assert(strncpy(dest, str34, 16) == s21_strncpy(dest, str34, 16));
    ck_assert(strncpy(dest3, str35, 6) == s21_strncpy(dest3, str35, 6));
}
END_TEST

START_TEST(check_strstr) {
    char str36[22] = "test_string";
    char str37[10] = "";
    char str38[22] = "test\nstring";
    char str39[22] = "t_s";
    char str40[22] = "123";
    char str41[22] = "strg";

    ck_assert(strstr(str36, str39) == s21_strstr(str36, str39));
    ck_assert(strstr(str36, str41) == s21_strstr(str36, str41));
    ck_assert(strstr(str37, str37) == s21_strstr(str37, str37));
    ck_assert(strstr(str37, str40) == s21_strstr(str37, str40));
    ck_assert(strstr(str38, str37) == s21_strstr(str38, str37));
}
END_TEST

START_TEST(check_strpbrk) {
    char str42[32] = "test_s1tri3ng";
    char str43[30] = "";
    char str44[32] = "test\n4stri2ng";
    char str45[30] = "kdjhghjnbtignkljdsg";
    char find[12] = "123456";

    ck_assert(strpbrk(str42, find) == s21_strpbrk(str42, find));
    ck_assert(strpbrk(str43, find) == s21_strpbrk(str43, find));
    ck_assert(strpbrk(str44, find) == s21_strpbrk(str44, find));
    ck_assert(strpbrk(str45, find) == s21_strpbrk(str45, find));
}
END_TEST

START_TEST(check_strtok) {
    char str46[50] = "This program works, I promise!";
    char strc46[50] = "This program works, I promise!";
    char delim[10] = "!, ";
    char str58[50] = "";

    ck_assert_str_eq(strtok(strc46, delim), s21_strtok(str46, delim));
    ck_assert_str_eq(strtok(S21_NULL, delim), s21_strtok(S21_NULL, delim));
    ck_assert_str_eq(strtok(S21_NULL, delim), s21_strtok(S21_NULL, delim));
    ck_assert_str_eq(strtok(S21_NULL, delim), s21_strtok(S21_NULL, delim));
    ck_assert_str_eq(strtok(S21_NULL, delim), s21_strtok(S21_NULL, delim));
    ck_assert_ptr_eq(strtok(S21_NULL, delim), s21_strtok(S21_NULL, delim));
    ck_assert_ptr_eq(strtok(S21_NULL, delim), s21_strtok(S21_NULL, delim));
    ck_assert_ptr_eq(strtok(str58, delim), s21_strtok(str58, delim));
}
END_TEST

START_TEST(check_memset) {
    char str53[30] = "kakdela";
    int str54 = 'l';
    char str55[30] = "123456";
    int str56 = '1';
    int str57 = ' ';
    size_t n31 = 3;
    size_t n32 = 4;
    size_t n33 = 2;

    ck_assert(memset(str53, str54, n31) == s21_memset(str53, str54, n31));
    ck_assert(memset(str55, str56, n32) == s21_memset(str55, str56, n32));
    ck_assert(memset(str55, str57, n33) == s21_memset(str55, str57, n33));
}
END_TEST

START_TEST(check_strncat) {
    char str60[30] = "chto";
    char str61[30] = "toto";
    char str62[30] = "1234567";
    char str63[30] = "8910";
    char str64[39] = "kek\n";
    size_t n31 = 3;
    size_t n32 = 4;
    size_t n34 = 10;

    ck_assert(strncat(str60, str61, n31) == s21_strncat(str60, str61, n31));
    ck_assert(strncat(str62, str63, n32) == s21_strncat(str62, str63, n32));
    ck_assert(strncat(str62, str64, n34) == s21_strncat(str62, str64, n34));
}
END_TEST

START_TEST(check_strchr) {
    char str65[N] = "2o9o6o1";
    char str66[N] = "";
    char str67[N] = "Save the world tomorrow";
    char find11 = 'o';

    ck_assert(s21_strchr(str65, find11) == strchr(str65, find11));
    ck_assert(s21_strchr(str66, find11) == strchr(str66, find11));
    ck_assert(s21_strchr(str67, find11) == strchr(str67, find11));
}
END_TEST

START_TEST(check_strrchr) {
    char str65[N] = "2o9o6o1";
    char str66[N] = "";
    char str67[N] = "Save the world tomorrow";
    char find11 = 'o';

    ck_assert(s21_strrchr(str65, find11) == strrchr(str65, find11));
    ck_assert(s21_strrchr(str66, find11) == strrchr(str66, find11));
    ck_assert(s21_strrchr(str67, find11) == strrchr(str67, find11));
}
END_TEST

START_TEST(check_memcpy) {
    char dest08[N] = "     more";
    char srcq0[N] = "Never";
    size_t n01 = 5;
    char dest18[N] = "-32567.32";
    char srcq1[N] = "";
    size_t n11 = 0;
    char dest28[N] = "One of\nus";
    char srcq2[N] = "Two of ";
    size_t n21 = 7;

  ck_assert(s21_memcpy(dest08, srcq0, n01) == memcpy(dest08, srcq0, n01));
  ck_assert(s21_memcpy(dest18, srcq1, n11) == memcpy(dest18, srcq1, n11));
  ck_assert(s21_memcpy(dest28, srcq2, n21) == memcpy(dest28, srcq2, n21));
}
END_TEST

START_TEST(check_strcmp) {
    char strk01[N] = "Sity of stars";
    char strk02[N] = "Sity of s";
    char strk11[N] = "123456";
    char strk12[N] = "123456789";
    char strk21[N] = "Unshaken";
    char strk22[N] = "Unshaken";

  ck_assert_int_eq(s21_strcmp(strk01, strk02), strcmp(strk01, strk02));
  ck_assert_int_eq(s21_strcmp(strk11, strk12), strcmp(strk11, strk12));
  ck_assert_int_eq(s21_strcmp(strk21, strk22), strcmp(strk21, strk22));
}
END_TEST

START_TEST(check_strncmp) {
    char strl01[N] = "Sweet dreams";
    char strl02[N] = "Sweet dreams";
    size_t n50 = 20;
    char strl11[N] = "561";
    char strl12[N] = "567";
    size_t n51 = 3;
    char strl21[N] = "Otherwise";
    char strl22[N] = "";
    size_t n52 = 1;

  ck_assert_int_eq(s21_strncmp(strl01, strl02, n50), strncmp(strl01, strl02, n50));
  ck_assert_int_eq(s21_strncmp(strl11, strl12, n51), strncmp(strl11, strl12, n51));
  ck_assert_int_eq(s21_strncmp(strl21, strl22, n52), strncmp(strl21, strl22, n52));
}
END_TEST

START_TEST(check_memmove) {
    char sdest0[N] = "     more";
    char ssrc0[N] = "Never";
    size_t n08 = 5;
    char sdest1[N] = "-32567.32";
    char ssrc1[N] = "qweqwe";
    size_t n18 = 4;
    char ssrc2[N] = "Parov Stelar";
    size_t n28 = 5;

  ck_assert(s21_memmove(sdest0 + 5, ssrc0, n08) == memmove(sdest0 + 5, ssrc0, n08));
  ck_assert(s21_memmove(sdest1, ssrc1, n18) == memmove(sdest1, ssrc1, n18));
  ck_assert(s21_memmove(ssrc2 + 4, ssrc2 + 5, n28) == memmove(ssrc2 + 4, ssrc2 + 5, n28));
}
END_TEST

START_TEST(check_strerror) {
    double ii = 1;
    char a = 'a';

    ck_assert_str_eq(s21_strerror(a), strerror(a));
    while (1) {
        ck_assert_str_eq(s21_strerror(ii), strerror(ii));
        ii = ii + 1;
        if (ii == 110)
            break;
    }
}
END_TEST

START_TEST(check_memchr) {
     unsigned char src99[15]="12345674490";
    int test1 = '4';
    int test2 = '8';

    ck_assert(s21_memchr(src99, test1, sizeof(char)) == memchr(src99, test1, sizeof(char)));
    ck_assert(s21_memchr(src99, test2, sizeof(char)) == memchr(src99, test2, sizeof(char)));
    ck_assert(s21_memchr(src99, test1, 0) == memchr(src99, test1, 0));
    ck_assert(s21_memchr(src99, test1, 0) == memchr(src99, test1, 0));
}
END_TEST

START_TEST(check_sprintf) {
    char c[N] = "%- 5coj  %lc;lk% 6%";
    char str_c_s21[N];
    char str_c_orig[N];
    char d[256] = "bb% 1.2d %+8.5ldmnn%-12.11hd  %#*.*d %03.0d% %-20d %03.4d %05.8d % 05.6d %-07d %07d";
    char str_d_s21[256];
    char str_d_orig[256];
    char i[256] = "bb% 1.2i %+8.5limnn%-12.11hi  %#*.*i %03.0i% %-20i %03.4i %05.8i % 05.6i %-07i %07d";
    char str_i_s21[256];
    char str_i_orig[256];
    char f[N] = "u%- .6fh% +5fnn % 0f % 10.3f %-5.2f";
    char str_f_s21[300];
    char str_f_orig[300];
    char s[N] = "-%-4sj%2s   %-11sj%.3s";
    char str_s_s21[100];
    char str_s_orig[100];
    char u[N] = "%-.4ubh%6u%5.5lu%-.3hu%-5u %05u";
    char str_u_s21[N];
    char str_u_orig[N];

    ck_assert_int_eq(s21_sprintf(str_c_s21, c, 'a', 'b'), sprintf(str_c_orig, c, 'a', 'b'));
    ck_assert_str_eq(str_c_s21, str_c_orig);
    ck_assert_int_eq(s21_sprintf(str_f_s21, f, -58585.9595959959595959, 1212121212.121212,
    123.456, 12.3, 1.3),
    sprintf(str_f_orig, f, -58585.9595959959595959, 1212121212.121212,
    123.456, 12.3, 1.3));
    ck_assert_str_eq(str_f_s21, str_f_orig);
    ck_assert_int_eq(s21_sprintf(str_s_s21, s, "Palladio", "One", "-2911", "1234"),
    sprintf(str_s_orig, s, "Palladio", "One", "-2911", "1234"));
    ck_assert_str_eq(str_s_s21, str_s_orig);
    ck_assert_int_eq(s21_sprintf(str_u_s21, u, 5, 23, (unsigned long)6, (unsigned short)7, 44, 33),
    sprintf(str_u_orig, u, 5, 23, (unsigned long)6, (unsigned short)7, 44, 33));
    ck_assert_str_eq(str_u_s21, str_u_orig);
    ck_assert_int_eq(s21_sprintf(str_d_s21, d, 5, 23, -6, 8, 7, -228, 0, 0 , 69, 1, 12, 7, 7),
    sprintf(str_d_orig, d, 5, 23, -6, 8, 7, -228, 0, 0, 69, 1, 12, 7));
    ck_assert_str_eq(str_d_s21, str_d_orig);
    ck_assert_int_eq(s21_sprintf(str_i_s21, i, 5, 23, -6, 8, 7, -228, 0, 0, 69, 1, 12, 7, 7),
    sprintf(str_i_orig, i, 5, 23, -6, 8, 7, -228, 0, 0, 69, 1, 12, 7));
    ck_assert_str_eq(str_i_s21, str_i_orig);
}
END_TEST

START_TEST(to_upper_test) {
  char pstr01[N] = "YesterdAy";
  char pstr11[N] = "a1 B2 3z3 *";
  char pstr21[N] = "123";
    char res1[N] = "YESTERDAY";
    char res2[N] = "A1 B2 3Z3 *";
    char res3[N] = "123";
  char *up1 = s21_to_upper(pstr01);
  char *up2 = s21_to_upper(pstr11);
  char *up3 = s21_to_upper(pstr21);

    ck_assert_str_eq(up1, res1);
  if (up1 != S21_NULL) {free(up1); }
    ck_assert_str_eq(up2, res2);
  if (up2 != S21_NULL) {free(up2); }
    ck_assert_str_eq(up3, res3);
  if (up3 != S21_NULL) {free(up3); }
}
END_TEST

START_TEST(to_lower_test) {
  char pstr01[N] = "YESTERdAY";
  char pstr11[N] = "A1 B2 3Z3 *";
  char pstr21[N] = "123";

  char *up1 = s21_to_lower(pstr01);
  char *up2 = s21_to_lower(pstr11);
  char *up3 = s21_to_lower(pstr21);

    char ress1[N] = "yesterday";
    char ress2[N] = "a1 b2 3z3 *";
    char ress3[N] = "123";
    ck_assert_str_eq(up1, ress1);
  if (up1 != S21_NULL) {free(up1); }
    ck_assert_str_eq(up2, ress2);
  if (up2 != S21_NULL) {free(up2); }
    ck_assert_str_eq(up3, ress3);
  if (up3 != S21_NULL) {free(up3); }
}
END_TEST

START_TEST(insert_test) {
  char psrc0[N] = "MamaSaid";
  char pstr0[N] = " ";
  size_t pn0 = 4;
  char psrc2[N] = "chlorine";
  char pstr2[N] = "";
  size_t pn2 = 7;
  char *up1 = s21_insert(psrc0, pstr0, pn0);
  char *up3 = s21_insert(psrc2, pstr2, pn2);
    char resss1[N] = "Mama Said";
    char resss2[N] = "chlorine";
    ck_assert_str_eq(up1, resss1);
  if (up1 != S21_NULL) {free(up1); }
    ck_assert_str_eq(up3, resss2);
  if (up3 != S21_NULL) {free(up3); }
}
END_TEST

START_TEST(trim_test) {
  char psrc0[N] = "*Save Tonight*";
  char pc0[N] = "*";
  char psrc1[N] = "";
  char pc1[N] = "123";
  char pc5[N] = "";
  char psrc2[N] = "creep";
  char pc2[N] = " ";
  char psrc3[N] = " creep ";
  char pc3[N] = " ";
  char *up1 = s21_trim(psrc0, pc0);
  char *up2 = s21_trim(psrc1, pc1);
  char *up3 = s21_trim(psrc2, pc2);
  char *up4 = s21_trim(psrc3, pc3);
    char ressss1[N] = "Save Tonight";
    char ressss2[N] = "creep";
    ck_assert_str_eq(up1, ressss1);
  if (up1 != S21_NULL) {free(up1); }
    ck_assert_str_eq(up2, pc5);
  if (up2 != S21_NULL) {free(up2); }
    ck_assert_str_eq(up3, ressss2);
  if (up3 != S21_NULL) {free(up3); }
    ck_assert_str_eq(up4, ressss2);
  if (up4 != S21_NULL) {free(up4); }
}
END_TEST

int main(void) {
    Suite *s1 = suite_create("Core");
    TCase *tc1_1 = tcase_create("Core");
    SRunner *sr = srunner_create(s1);
    int nf;

    suite_add_tcase(s1, tc1_1);
    tcase_add_test(tc1_1, check_memcmp);
    tcase_add_test(tc1_1, check_strcat);
    tcase_add_test(tc1_1, check_strcspn);
    tcase_add_test(tc1_1, check_strspn);
    tcase_add_test(tc1_1, check_strlen);
    tcase_add_test(tc1_1, check_strcpy);
    tcase_add_test(tc1_1, check_strncpy);
    tcase_add_test(tc1_1, check_strstr);
    tcase_add_test(tc1_1, check_strpbrk);
    tcase_add_test(tc1_1, check_strtok);
    tcase_add_test(tc1_1, check_memset);
    tcase_add_test(tc1_1, check_strncat);
    tcase_add_test(tc1_1, check_strchr);
    tcase_add_test(tc1_1, check_strrchr);
    tcase_add_test(tc1_1, check_memcpy);
    tcase_add_test(tc1_1, check_strcmp);
    tcase_add_test(tc1_1, check_strncmp);
    tcase_add_test(tc1_1, check_memmove);
    tcase_add_test(tc1_1, check_strerror);
    tcase_add_test(tc1_1, check_memchr);
    tcase_add_test(tc1_1, check_sprintf);
    tcase_add_test(tc1_1, to_upper_test);
    tcase_add_test(tc1_1, to_lower_test);
    tcase_add_test(tc1_1, insert_test);
    tcase_add_test(tc1_1, trim_test);

    srunner_run_all(sr, CK_ENV);
    nf = srunner_ntests_failed(sr);
    srunner_free(sr);

    return nf == 0 ? 0 : 1;
}
