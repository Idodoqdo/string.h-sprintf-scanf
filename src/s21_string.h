#ifndef SRC_S21_STRING_H_
#define SRC_S21_STRING_H_

#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

#define S21_NULL ((void*)0)
#define N 50
#define BRUTE_FORCE_0_9 (*ptr_format == '0' || *ptr_format == '1' || *ptr_format == '2' ||\
    *ptr_format == '3' || *ptr_format == '4' || *ptr_format == '5' || *ptr_format == '6' ||\
    *ptr_format == '7' || *ptr_format == '8' || *ptr_format == '9')
#define BRUTE_FORCE_SPEC (*ptr_format == 'c' || *ptr_format == 'd' || *ptr_format == 'i' ||\
    *ptr_format == 'f' || *ptr_format == 's' || *ptr_format == 'u' || *ptr_format == '%')

#define S21_FLAG_MINUS 0
#define S21_FLAG_PLUS 1
#define S21_FLAG_SPACE 2
#define S21_FLAG_HASH 3
#define S21_FLAG_ZERO 4
#define BUFF_SIZE 256
#define S21_NULL ((void*)0)
typedef unsigned long s21_size_t;

int s21_memcmp(const void *str1, const void *str2, s21_size_t n);
char *s21_strcat(char *dest, const char *src);
s21_size_t s21_strcspn(const char *str1, const char *str2);
s21_size_t s21_strspn(const char *str1, const char *str2);
char *s21_strchr(const char* str, int c);
int s21_strcmp(const char* str1, const char* str2);
int s21_strncmp(char* str1, char* str2, s21_size_t n);
char *s21_strcpy(char *dest, const char *src);
s21_size_t s21_strlen(const char *str);
char *s21_strncpy(char *dest, const char *src, s21_size_t n);
char *s21_strpbrk(const char *str1, const char *str2);
char *s21_strstr(const char *haystack, const char *needle);
char *s21_strtok(char *str, const char *delim);
void *s21_memchr(const void *str, int c, s21_size_t n);
void *s21_memcpy(void* dest, const void* src, s21_size_t n);
void* s21_memmove(void* dest, const void* src, s21_size_t n);
void *s21_memset(void *str, int c, s21_size_t n);
int s21_strcmp(const char* str1, const char* str2);
char *s21_strncat(char *dest, const char *src, s21_size_t n);
int s21_strncmp(char* str1, char* str2, s21_size_t n);
char* s21_strrchr(const char* str, int c);
char *s21_strerror(int errnum);
void *s21_to_upper(const char *str);
void *s21_to_lower(const char *str);
void *s21_insert(const char *src, const char *str, s21_size_t start_index);
void *s21_trim(const char *src, const char *trim_chars);
int s21_first(const char *sr, const char *tr, const char *src, const char *trim_chars);
int s21_second(const char *sr, const char *tr, const char *src, const char *trim_chars);

typedef struct s21_format {
    char flag[5];
    int width;
    int precision;
    char len;
    char specificator;
} s21_format_struct_tok;


int s21_sprintf(char *str, const char *format, ...);
char *s21_format_to_struct(char *ptr_format, s21_format_struct_tok *s21_format, va_list ap);
int s21_func_init_format(char *str, s21_format_struct_tok *s21_format, va_list ap);
int itoa(long num, char *s, s21_format_struct_tok *s21_format);
int s21_uint_sprint(char *buf_str, s21_format_struct_tok tok, unsigned long var);
int s21_c(char *str, s21_format_struct_tok s21_format, int tmp);
int s21_float_sprintf(char *buf_str, s21_format_struct_tok tok, double var);
int s21_string_sprintf(char *str, s21_format_struct_tok tok, char *var);
int s21_d(char *str, s21_format_struct_tok *s21_format, va_list ap, int len1);

#endif  // SRC_S21_STRING_H_
