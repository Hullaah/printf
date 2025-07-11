#ifndef UTILS_H
#define UTILS_H

#include "format_specifier.h"
#include <stdarg.h>
#include <stdbool.h>

#define LENGTH 1024
#define FLAG_LEFT (1 << 0)
#define FLAG_PLUS (1 << 1)
#define FLAG_SPACE (1 << 2)
#define FLAG_ZERO (1 << 3)
#define FLAG_HASH (1 << 4)

#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define UNUSED(x) ((void)(x))

bool _isdigit(int c);
int _atoi(const char **str);
int _strlen(const char *str);
void flush(char *buf, int len);
void write_zero(char *buf, int *len, int count);
void write_space(char *buf, int *len, int count);
void reverse(char *buf, int start, int end);
int unumlen(unsigned long long num, int base);
unsigned long long get_unum(enum LengthModifier length, va_list *args);

#endif
