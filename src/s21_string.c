#include <stdarg.h>
#include "s21_string.h"

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
     const unsigned char *s1 = str1;
    const unsigned char *s2 = str2;
    while (n-- > 0) {
      if (*s1++ != *s2++) {
        return s1[-1] < s2[-1] ? -1 : 1;
    }
    }
  return 0;
}

char *s21_strcat(char *dest, const char *src) {
    char *d = dest;
    while (*dest != '\0') {
        dest++;
    }
    while (*src != '\0') {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
    return d;
}

char *s21_strchr(const char* str, int c) {
    char b = (char)c;
    while ((*str != b) && (*str != '\0')) {
        ++str;
    }
return (char* )(b == *str ? str : S21_NULL);
}

s21_size_t s21_strcspn(const char *str1, const char *str2) {
    s21_size_t r = 0;
    while (*str1) {
      if (s21_strchr(str2, *str1)) {
          return r;
      } else {
          str1++;
          r++;
      }
    }
    return r;
}

s21_size_t s21_strspn(const char *str1, const char *str2) {
    s21_size_t r = 0;
    while (*str1 && s21_strchr(str2, *str1++)) {
        r++;
    }
    return r;
}

char *s21_strcpy(char *dest, const char *src) {
    s21_size_t len = 0;
    while (src[len] != '\0') {
        dest[len] = src[len];
        len++;
    }
    dest[len] = src[len];
    return dest;
}

s21_size_t s21_strlen(const char *str) {
    s21_size_t len = 0;
    for (; str[len]; len++) {}
    return len;
}

char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
    s21_size_t len = 0;
    while (len < n && src[len] != '\0') {
        dest[len] = src[len];
        len++;
    }
    while (len < n) {
        dest[len] = '\0';
        len++;
    }
    return dest;
}

char *s21_strpbrk(const char *str1, const char *str2) {
    s21_size_t s1_size = s21_strlen(str1);
    char *res = S21_NULL;
    for (s21_size_t i = 0; i < s1_size; i++) {
        res = s21_strchr(str2, str1[i]);
        if (res) {
            res = (char *)str1 + i;
            break;
        }
    }
    return res;
}

char *s21_strstr(const char *haystack, const char *needle) {
    int haystack_size = (int)s21_strlen(haystack);
    int needle_size = (int)s21_strlen(needle);
    char *res = S21_NULL;
    int check = 0;
    if (needle_size == 0) {
        res = (char *)haystack;
        haystack_size = 0;
    }
    for (int i = 0; i < haystack_size - needle_size; i++) {
        if (haystack[i] == needle[0]) {
            for (int j = 1; j < needle_size; j++) {
                if (haystack[i + j] != needle[j]) {
                    check = 1;
                    break;
                }
            }
            if (check == 0) {
                res = (char *)haystack + i;
                break;
            }
            check = 0;
        }
    }
    return res;
}

char *s21_strtok(char *str, const char *delim) {
    static char *next = S21_NULL;
    char *res = S21_NULL;
    if (str == S21_NULL) {
        str = next;
    }
    if (str != S21_NULL) {
        while (s21_strchr(delim, *str) && *str != '\0') {
            ++str;
        }
        if (*str == '\0') {
            next = S21_NULL;
            res = S21_NULL;
        } else {
            res = str;
            next = s21_strpbrk(str, delim);
            if (next) {
                *next = '\0';
                ++next;
                if (*next == '\0') {
                    next = S21_NULL;
                }
            }
        }
    }
    return res;
}

void *s21_memchr(const void *str, int c, s21_size_t n) {
    s21_size_t i = 0;
    for (; i < n; i++)
        if (*((char*)str + i) == c)
            return (char*)str+i;
    return S21_NULL;
}


void *s21_memcpy(void* dest, const void* src, s21_size_t n) {
    char *d = dest;
    const char *s = src;
    while (n--) {
      *d++ = *s++;
    }
    return (void *)dest;
}

void* s21_memmove(void* dest, const void* src, s21_size_t n) {
  char* d = dest;
  char* s = (char*)src;
    char* temp = (char*)malloc(sizeof(char)*n);
    for (s21_size_t i = 0; i < n + 1; i++) {
        *(temp + i) = *(s + i);
    }
    for (s21_size_t i = 0; i < n + 1; i++) {
        *(d + i) = *(temp + i);
    }
    free(temp);
  return (void*)d;
}


void *s21_memset(void *str, int c, s21_size_t n) {
    char *str1 = (char*)str;
    for (s21_size_t i = 0; i < n; i++) {
        str1[i] = c;
    }
    return str1;
}

int s21_strcmp(const char* str1, const char* str2) {
  int ind = 0;
  while ((*str1 != '\0') || (*str2 != '\0')) {
    if (*str1 != *str2) {
      ind = (*(unsigned char*)str1 - *(unsigned char*)str2);
        break;
    }
      ++str1;
      ++str2;
  }
  return ind;
}

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
    char *d = dest;
    while (*dest != '\0') {
        dest++;
    }
    for (s21_size_t i = 0; i < n; i++) {
        *dest = src[i];
        dest++;
    }
    *dest = '\0';
    return d;
}

int s21_strncmp(char* str1, char* str2, s21_size_t n) {
    while (n && *str1 && (*str1 == *str2)) {
        ++str1;
        ++str2;
        --n;
    }
    return (*(unsigned char*)str1 - *(unsigned char*)str2);
}

char* s21_strrchr(const char* str, int c) {
  char b = c;
  int i = 1;
  while (*str != '\0') {
    str++;
    i++;
  }
  for (;; str--) {
    i--;
    if ((*str == b) || (i == 0)) {
      break;
    }
  }
  return (char*)(b == *str ? str : S21_NULL);
}

#ifdef __APPLE__
#define ARR_MAC "Undefined error: 0", \
"Operation not permitted", \
"No such file or directory", \
"No such process", \
"Interrupted system call", \
"Input/output error", \
"Device not configured", \
"Argument list too long", \
"Exec format error", \
"Bad file descriptor", \
"No child processes", \
"Resource deadlock avoided", \
"Cannot allocate memory", \
"Permission denied", \
"Bad address", \
"Block device required", \
"Resource busy", \
"File exists", \
"Cross-device link", \
"Operation not supported by device", \
"Not a directory", \
"Is a directory", \
"Invalid argument", \
"Too many open files in system", \
"Too many open files", \
"Inappropriate ioctl for device", \
"Text file busy", \
"File too large", \
"No space left on device", \
"Illegal seek", \
"Read-only file system", \
"Too many links", \
"Broken pipe", \
"Numerical argument out of domain", \
"Result too large", \
"Resource temporarily unavailable", \
"Operation now in progress", \
"Operation already in progress", \
"Socket operation on non-socket", \
"Destination address required", \
"Message too long", \
"Protocol wrong type for socket", \
"Protocol not available", \
"Protocol not supported", \
"Socket type not supported", \
"Operation not supported", \
"Protocol family not supported", \
"Address family not supported by protocol family", \
"Address already in use", \
"Can't assign requested address", \
"Network is down", \
"Network is unreachable", \
"Network dropped connection on reset", \
"Software caused connection abort", \
"Connection reset by peer", \
"No buffer space available", \
"Socket is already connected", \
"Socket is not connected", \
"Can't send after socket shutdown", \
"Too many references: can't splice", \
"Operation timed out", \
"Connection refused", \
"Too many levels of symbolic links", \
"File name too long", \
"Host is down", \
"No route to host", \
"Directory not empty", \
"Too many processes", \
"Too many users", \
"Disc quota exceeded", \
"Stale NFS file handle", \
"Too many levels of remote in path", \
"RPC struct is bad", \
"RPC version wrong", \
"RPC prog. not avail", \
"Program version wrong", \
"Bad procedure for program", \
"No locks available", \
"Function not implemented", \
"Inappropriate file type or format", \
"Authentication error", \
"Need authenticator", \
"Device power is off", \
"Device error", \
"Value too large to be stored in data type", \
"Bad executable (or shared library)", \
"Bad CPU type in executable", \
"Shared library version mismatch", \
"Malformed Mach-o file", \
"Operation canceled", \
"Identifier removed", \
"No message of desired type", \
"Illegal byte sequence", \
"Attribute not found", \
"Bad message", \
"EMULTIHOP (Reserved)", \
"No message available on STREAM", \
"ENOLINK (Reserved)", \
"No STREAM resources", \
"Not a STREAM", \
"Protocol error", \
"STREAM ioctl timeout", \
"Operation not supported on socket", \
"Policy not found", \
"State not recoverable", \
"Previous owner died", \
"Interface output queue is full"
#else
#define ARR_LIN "Success", \
"Operation not permitted", \
"No such file or directory", \
"No such process", \
"Interrupted system call", \
"Input/output error", \
"No such device or address", \
"Argument list too long", \
"Exec format error", \
"Bad file descriptor", \
"No child processes", \
"Resource temporarily unavailable", \
"Cannot allocate memory", \
"Permission denied", \
"Bad address", \
"Block device required", \
"Device or resource busy", \
"File exists", \
"Invalid cross-device link", \
"No such device", \
"Not a directory", \
"Is a directory", \
"Invalid argument", \
"Too many open files in system", \
"Too many open files", \
"Inappropriate ioctl for device", \
"Text file busy", \
"File too large", \
"No space left on device", \
"Illegal seek", \
"Read-only file system", \
"Too many links", \
"Broken pipe", \
"Numerical argument out of domain", \
"Numerical result out of range", \
"Resource deadlock avoided", \
"File name too long", \
"No locks available", \
"Function not implemented", \
"Directory not empty", \
"Too many levels of symbolic links", \
"Unknown error 41", \
"No message of desired type", \
"Identifier removed", \
"Channel number out of range", \
"Level 2 not synchronized", \
"Level 3 halted", \
"Level 3 reset", \
"Link number out of range", \
"Protocol driver not attached", \
"No CSI structure available", \
"Level 2 halted", \
"Invalid exchange", \
"Invalid request descriptor", \
"Exchange full", \
"No anode", \
"Invalid request code", \
"Invalid slot", \
"Unknown error 58", \
"Bad font file format", \
"Device not a stream", \
"No data available", \
"Timer expired", \
"Out of streams resources", \
"Machine is not on the network", \
"Package not installed", \
"Object is remote", \
"Link has been severed", \
"Advertise error", \
"Srmount error", \
"Communication error on send", \
"Protocol error", \
"Multihop attempted", \
"RFS specific error", \
"Bad message", \
"Value too large for defined data type", \
"Name not unique on network", \
"File descriptor in bad state", \
"Remote address changed", \
"Can not access a needed shared library", \
"Accessing a corrupted shared library", \
".lib section in a.out corrupted", \
"Attempting to link in too many shared libraries", \
"Cannot exec a shared library directly", \
"Invalid or incomplete multibyte or wide character", \
"Interrupted system call should be restarted", \
"Streams pipe error", \
"Too many users", \
"Socket operation on non-socket", \
"Destination address required", \
"Message too long", \
"Protocol wrong type for socket", \
"Protocol not available", \
"Protocol not supported", \
"Socket type not supported", \
"Operation not supported", \
"Protocol family not supported", \
"Address family not supported by protocol", \
"Address already in use", \
"Cannot assign requested address", \
"Network is down", \
"Network is unreachable", \
"Network dropped connection on reset", \
"Software caused connection abort", \
"Connection reset by peer", \
"No buffer space available", \
"Transport endpoint is already connected", \
"Transport endpoint is not connected", \
"Cannot send after transport endpoint shutdown", \
"Too many references: cannot splice", \
"Connection timed out", \
"Connection refused", \
"Host is down", \
"No route to host", \
"Operation already in progress", \
"Operation now in progress", \
"Stale file handle", \
"Structure needs cleaning", \
"Not a XENIX named type file", \
"No XENIX semaphores available", \
"Is a named type file", \
"Remote I/O error", \
"Disk quota exceeded", \
"No medium found", \
"Wrong medium type", \
"Operation canceled", \
"Required key not available", \
"Key has expired", \
"Key has been revoked", \
"Key was rejected by service", \
"Owner died", \
"State not recoverable", \
"Operation not possible due to RF-kill", \
"Memory page has hardware error"
#endif

char *s21_strerror(int errnum) {
#ifdef __APPLE__
    static char buf[256];
    if (errnum >= 0 && errnum <= 106) {
        char *errarr[] = {ARR_MAC};
        s21_sprintf(buf, "%s", errarr[errnum]);
    } else {
        s21_sprintf(buf, "Unknown error: %d", errnum);
    }
#else
    static char buf[256];
    if (errnum >= 0 && errnum <= 133) {
        char *errarr[] = {ARR_LIN};
        s21_sprintf(buf, "%s", errarr[errnum]);
    } else {
        s21_sprintf(buf, "Unknown error %d", errnum);
    }
#endif
    return buf;
}

void *s21_to_upper(const char *str) {
    char* s = S21_NULL;
    if (str != S21_NULL) {
        s = malloc(s21_strlen(str));
        char *k = s;
        if (s != S21_NULL) {
            while (*str != '\0') {
                if (*str >= 97 && *str <=122) {
                    *k++ = *str++ - 32;
                } else {
                    *k++ = *str++;
                }
            }
        *k = '\0';
        }
    }
    return s;
}

void *s21_to_lower(const char *str) {
    char* s = S21_NULL;
    if (str != S21_NULL) {
        s = malloc(s21_strlen(str));
        char *k = s;
        if (s != S21_NULL) {
            while (*str != '\0') {
                if (*str >= 65 && *str <= 90) {
                    *k++ = *str++ + 32;
                } else {
                    *k++ = *str++;
                }
            }
        *k = '\0';
        }
    }
    return s;
}

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
    char* s = S21_NULL;
    if (start_index <= s21_strlen(src)) {
    char *sr = (char*)src;
    char *st = (char*)str;
    s = (char*)malloc(s21_strlen(src) + s21_strlen(str) +1);
    char *t = (char *)s;
        if (s != S21_NULL) {
            s21_size_t i = 0;
            while (i++ < start_index) {
                *t++ = *sr++;
                }
            while (*st != '\0') {
                *t++ = *st++;
                }
            while (i++ < s21_strlen(src) + 1) {
                *t++ = *sr++;
                }
        }
     *t = '\0';
    }
    return s;
}

void *s21_trim(const char *src, const char *trim_chars) {
    char *sr = (char *)src;
    char *tr = (char *)trim_chars;
    char* s = S21_NULL;
    if (tr == S21_NULL) {
        trim_chars = " ";
        tr = (char *)trim_chars;
    }
    s = malloc(s21_strlen(src) + 1);
        if (s != S21_NULL) {
            int m = 0;
        int nachalo = s21_first(sr, tr, src, trim_chars);
        int konets = s21_second(sr, tr, src, trim_chars);
                for (int i = nachalo; i < konets; i++) {
                    s[m] = src[i];
                    m++;
                    nachalo++;
                }
                s[m] = '\0';
        }
    return s;
}

int s21_first(const char *sr, const char *tr, const char *src, const char *trim_chars) {
    int nachalo = 0;
    for (s21_size_t i = 0; i < s21_strlen(src); i++) {
        int start = 0;
        for (s21_size_t j = 0; j < s21_strlen(trim_chars); j++) {
            if (sr[i] == tr[j]) {
                start = 1;
                break;
            }
        }
        if (start == 1) {
            nachalo++;
        } else {
            break;
        }
    }
    return nachalo;
}

int s21_second(const char *sr, const char *tr, const char *src, const char *trim_chars) {
    int konets = s21_strlen(src);
    for (int i = s21_strlen(src) - 1; i > -1; i--) {
        int end = 0;
        for (s21_size_t j = 0; j < s21_strlen(trim_chars); j++) {
            if (sr[i] == tr[j]) {
                end = 1;
                break;
            }
        }
        if (end == 1) {
            konets--;
        } else {
            break;
        }
    }
    return konets;
}

char *s21_format_to_struct(char *ptr_format, s21_format_struct_tok *s21_format, va_list ap) {
    ptr_format++;
    while (*ptr_format == '-' || *ptr_format == '+' || *ptr_format == ' '
          || *ptr_format == '#' || *ptr_format == '0') {
       if (*ptr_format == '-') s21_format -> flag[S21_FLAG_MINUS] = 1;
       if (*ptr_format == '+') s21_format -> flag[S21_FLAG_PLUS] = 1;
       if (*ptr_format == ' ') s21_format -> flag[S21_FLAG_SPACE] = 1;
       if (*ptr_format == '#') s21_format -> flag[S21_FLAG_HASH] = 1;
       if (*ptr_format == '0') s21_format -> flag[S21_FLAG_ZERO] = 1;
       ptr_format++;
    }
    if (BRUTE_FORCE_0_9) {
        int buf = *ptr_format - '0';
        ptr_format++;
        while (BRUTE_FORCE_0_9) {
            buf = buf * 10 + (*ptr_format - '0');
            ptr_format++;
        }
        s21_format -> width = buf;
    } else if (*ptr_format == '*') {
        s21_format -> width = va_arg(ap, int);
        ptr_format++;
    }
    if (*ptr_format == '.') {
        ptr_format++;
        if (BRUTE_FORCE_0_9) {
            int buf = *ptr_format - '0';
            ptr_format++;
            while (BRUTE_FORCE_0_9) {
                buf = buf * 10 + (*ptr_format - '0');
                ptr_format++;
            }
            s21_format -> precision = buf;
        } else if (*ptr_format == '*') {
            s21_format -> precision = va_arg(ap, int);
            ptr_format++;
        } else {
            s21_format -> precision = 0;
        }
    }
    if (*ptr_format == 'h' || *ptr_format == 'l' || *ptr_format == 'L') {
        s21_format -> len = *ptr_format++;
    }
    if (BRUTE_FORCE_SPEC) {
        s21_format -> specificator = *ptr_format;
    }
    if (s21_format -> precision == -1) {
        char tmp = s21_format -> specificator;
        if (tmp == 'e' || tmp == 'E' || tmp == 'f' || tmp == 'g' || tmp == 'G') {
            s21_format -> precision = 6;
        } else if (tmp != 's' && tmp != 'd' && tmp != 'i') {
            s21_format -> precision = 1;
        }
    }
    return ptr_format;
}

int s21_sprintf(char *str, const char *format, ...) {
    va_list ap;
    int len = 0;
    char *ptr_format = (char*)format;
    va_start(ap, format);
    while (ptr_format != S21_NULL && *ptr_format != '\0') {
        if (*ptr_format != '%') {
            str[len++] = *ptr_format;
        } else {
            s21_format_struct_tok s21_format = {{0, 0, 0, 0, 0}, 1, -1, 'q', 'q'};
            ptr_format = s21_format_to_struct(ptr_format, &s21_format, ap);
            if (s21_format.specificator != 'q') {
                str[len] = '\0';
                len += s21_func_init_format(str, &s21_format, ap);
                str[len] = '\0';
            }
        }
        if (*ptr_format !='\0') {
            ptr_format++;
        }
    }
    if (ptr_format == S21_NULL) {
        len = -1;
    } else {
        str[len] = '\0';
    }
    va_end(ap);
    return len;
}

int s21_func_init_format(char *str, s21_format_struct_tok *s21_format, va_list ap) {
    int res;
    if (s21_format->specificator == 'u') {
        if (s21_format->len == 'l') {
            res = s21_uint_sprint(str, *s21_format, va_arg(ap, unsigned long));
        } else {
            res = s21_uint_sprint(str, *s21_format, va_arg(ap, unsigned));
        }
    }
    if (s21_format->specificator == 'f') {
        res = s21_float_sprintf(str, *s21_format, va_arg(ap, double));
    }
    if (s21_format->specificator == 'c') {
        res = s21_c(str, *s21_format, va_arg(ap, int));
    }
    if (s21_format->specificator == '%') {
        res = s21_c(str, *s21_format, (int)'%');
    }
    if (s21_format->specificator == 's') {
        res = s21_string_sprintf(str, *s21_format, va_arg(ap, char*));
    }
    if (s21_format->specificator == 'd' ||
        s21_format->specificator == 'i') {
        int len = s21_strlen(str);
        res = s21_d(str, s21_format, ap, len);
    }

    return res;
}

int itoa(long num, char *s, s21_format_struct_tok *s21_format) {
    long tmp;
    if (num == 0) {
        *s = '0';
        s21_format -> width--;
        return 0;
    }
    if (num < 0) {
        num = -num;
    }
    for (tmp = num; tmp > 0; tmp /= 10, s++) {
        *s ='\0';
    }
    for (tmp = num; tmp > 0; tmp /= 10) {
        *--s = tmp % 10 + '0';
        s21_format -> width--;
    }
    return 0;
}
int lenght(long n) {
    int count = 0;
    do {
        n/= 10;
        ++count;
    } while (n !=0);
    return count;
}


int s21_c(char *str, s21_format_struct_tok s21_format, int tmp) {
    int i = 0;
    int len = s21_strlen(str);
    char temp = (char)tmp;
#ifndef __APPLE__
    if (s21_format.specificator == '%') {
        s21_format.width = 1;
    }
#endif
    if (s21_format.flag[0] == 1) {
        str[len++] = temp;
        s21_format.width--;
        i++;
        while (s21_format.width > 0) {
            str[len++] = ' ';
            s21_format.width--;
            i++;
        }
    }
    while (s21_format.width > 0) {
        if (s21_format.width == 1) {
            str[len++] = temp;
            i++;
            break;
        }
        str[len++] = ' ';
        i++;
        s21_format.width--;
    }
    return i;
}

int s21_d(char *str, s21_format_struct_tok *s21_format, va_list ap, int len1) {
    // printf("%d\n", s21_format -> precision);
    int tmp = len1;
    long temp;
    if (s21_format -> len == 'h') {
        short test = va_arg(ap, int);
        temp = test;
    } else if (s21_format -> len == 'l') {
        temp = va_arg(ap, long);
    } else {
        temp = va_arg(ap, int);}
    if (temp < 0 || s21_format -> flag[1] == 1 || s21_format -> flag[2] == 1) {
        s21_format -> width--;
    }
    if (s21_format -> width > lenght(temp) && s21_format -> flag[0] != 1) {
        while (s21_format -> width > s21_format -> precision &&s21_format -> width > lenght(temp)) {
            if (s21_format -> flag[4] == 1 && s21_format -> precision == -1) {
            str[tmp] = '0';
            } else {
                str[tmp] = ' ';}
            s21_format -> width--;
            tmp++;
        }
    }
    if (temp < 0) {
        str[tmp] = '-';
        tmp++;
    }
    if (s21_format -> flag[1] == 1 && temp >= 0) {
        str[tmp] = '+';
        s21_format -> width--;
        tmp++;
    } else if (s21_format -> flag[2] == 1 && temp >= 0) {
        str[tmp] = ' ';
        s21_format -> width--;
        tmp++;
    }
    if (0 < s21_format -> precision) {
        while (s21_format -> precision > lenght(temp)) {
            str[tmp] = '0';
            tmp++;
            s21_format -> precision--;
            s21_format -> width--;
        }
    }
    if (s21_format -> precision == 0 && temp == 0) {
        str[tmp] = ' ';
        tmp++;
    } else {
        itoa(temp, &str[tmp], s21_format);
        tmp = tmp + lenght(temp);}
    if (s21_format -> width > 0 && s21_format -> flag[0] == 1) {
        while (s21_format -> width > 0) {
            str[tmp] = ' ';
            s21_format -> width--;
            tmp++;
        }
    }
    return tmp - len1;
}

typedef struct s21_float_sizes {
    int pre_spaces;
    int sign_pos;
    int cnt;
    int dot;
    char sign;
    char space;
} float_sizes;

int get_float_sizes(float_sizes *cur_sizes, s21_format_struct_tok tok, double var) {
    cur_sizes->sign = var < 0 ? '-' : '+';
    if (var >= 0 && tok.flag[S21_FLAG_SPACE] &&
        !tok.flag[S21_FLAG_PLUS]) {
        cur_sizes->sign = ' ';
    }
    if (var < 0) {
        var = - var;
    }
    int ivar = (int)var;
    cur_sizes->cnt = 0;
    for (; ivar > 0; ivar = ivar / 10) {
        cur_sizes->cnt++;
    }
    cur_sizes->dot = 0;
    if (tok.precision > 0 || tok.flag[S21_FLAG_HASH]) {
        cur_sizes->dot = 1;
    }
    cur_sizes->pre_spaces = (cur_sizes->cnt + tok.precision + cur_sizes->dot) > tok.width ?
                        0 : (tok.width - cur_sizes->cnt - tok.precision - cur_sizes->dot);
    cur_sizes->space = ' ';
    if (tok.flag[S21_FLAG_ZERO] && !tok.flag[S21_FLAG_MINUS]) {
        cur_sizes->space = '0';
    }
    cur_sizes->sign_pos = 0;
    if (cur_sizes->sign == '-' ||
        tok.flag[S21_FLAG_PLUS] ||
        tok.flag[S21_FLAG_SPACE]) {
        if (cur_sizes->space == '0') {
            cur_sizes->sign_pos--;
        } else {
            cur_sizes->sign_pos++;
        }
        if (cur_sizes->pre_spaces > 0) {
            cur_sizes->pre_spaces -= 1;
        }
    }
    return cur_sizes->cnt + cur_sizes->pre_spaces +
            cur_sizes->dot + tok.precision +
            ((cur_sizes->sign_pos == 0) ? 0 : 1);
}

int s21_float_sprintf(char *str, s21_format_struct_tok tok, double var) {
    float_sizes cur_sizes;
    int res = get_float_sizes(&cur_sizes, tok, var);
    if (var < 0) {
        var = - var;
    }
    str += s21_strlen(str);
    if (cur_sizes.sign_pos < 0) {
        *str++ = cur_sizes.sign;
    }
    if (!tok.flag[S21_FLAG_MINUS]) {
        for (; cur_sizes.pre_spaces > 0; cur_sizes.pre_spaces--) {
            *str++ = cur_sizes.space;
        }
    }
    if (cur_sizes.sign_pos > 0) {
        *str++ = cur_sizes.sign;
    }
    for (; cur_sizes.cnt > 0; cur_sizes.cnt--) {
        unsigned cntcpy = cur_sizes.cnt - 1;
        int ivar = (int)var;
        for (; cntcpy > 0; cntcpy--) {
            ivar /= 10;
        }
        ivar %= 10;
        *str++ = '0' + ivar;
    }
    var -= (int)var;
    if (cur_sizes.dot) {
        *str++ = '.';
        for (; tok.precision > 0; tok.precision--) {
            if (tok.precision == 1) {
                var += 0.05;
            }
            var *= 10;
            int digit = (int)var;
            *str++ = '0' + digit;
            var = var - digit;
        }
    }
    if (tok.flag[S21_FLAG_MINUS]) {
        for (; cur_sizes.pre_spaces > 0; cur_sizes.pre_spaces--) {
            *str++ = cur_sizes.space;
        }
    }
    return res;
}

int s21_string_sprintf(char *str, s21_format_struct_tok tok, char *var) {
    int cnt = s21_strlen(var);
    if (tok.precision == -1) {
        tok.precision = cnt;
    }
    while (cnt > tok.precision) {
        cnt--;
    }
    int spaces = tok.width - cnt > 0 ?
                tok.width - cnt : 0;
    int res = cnt + spaces;
    str += s21_strlen(str);
    if (!tok.flag[S21_FLAG_MINUS]) {
        while (spaces--) {
            *str++ = ' ';
        }
    }
    while (cnt--) {
        *str++ = *var++;
    }
    if (tok.flag[S21_FLAG_MINUS]) {
        while (spaces--) {
            *str++ = ' ';
        }
    }
    return res;
}
typedef struct s21_uint_sizes {
    int pre_zeros;
    int pre_spaces;
    int cnt;
    char space;
} uint_sizes;

int get_uint_sizes(uint_sizes *cur_sizes, s21_format_struct_tok tok, unsigned long var) {
    cur_sizes->cnt = 0;
    while (var > 0) {
        cur_sizes->cnt++;
        var /= 10;
    }
    cur_sizes->space = ' ';
    if (tok.flag[4] && !tok.flag[0]) {
        cur_sizes->space = '0';
    }
    cur_sizes->pre_zeros = cur_sizes->cnt > tok.precision ?
                        0 : (tok.precision - cur_sizes->cnt);
    cur_sizes->pre_spaces = (cur_sizes->cnt + cur_sizes->pre_zeros) > tok.width ?
                        0 : (tok.width - cur_sizes->cnt - cur_sizes->pre_zeros);
    return cur_sizes->pre_zeros + cur_sizes->pre_spaces + cur_sizes->cnt;
}

int s21_uint_sprint(char *str, s21_format_struct_tok tok, unsigned long var) {
    uint_sizes cur_sizes;
    int res = get_uint_sizes(&cur_sizes, tok, var);
    str += s21_strlen(str);
    if (!tok.flag[S21_FLAG_MINUS]) {
        for (; cur_sizes.pre_spaces > 0; cur_sizes.pre_spaces--) {
            *str++ = cur_sizes.space;
        }
    }
    for (; cur_sizes.pre_zeros > 0; cur_sizes.pre_zeros--) {
        *str++ = '0';
    }
    for (; cur_sizes.cnt > 0; cur_sizes.cnt--) {
        int cntcpy = cur_sizes.cnt - 1;
        unsigned long varcpy = var;
        for (; cntcpy > 0; cntcpy--) {
            varcpy /= 10;
        }
        varcpy %= 10;
        *str++ = '0' + varcpy;
    }
    if (tok.flag[S21_FLAG_MINUS]) {
        for (; cur_sizes.pre_spaces > 0; cur_sizes.pre_spaces--) {
            *str++ = cur_sizes.space;
        }
    }
    return res;
}
