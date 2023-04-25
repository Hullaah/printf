#ifndef MAIN_H
#define MAIN_H
#define BUFFER 1024

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

int _printf(char *format, ...);

int print_buf(char buf[BUFFER]);

int print_string(char *str, char c, char buf[BUFFER], int start);

int print_numbers(void *i, int base, char cap, char buf[BUFFER], int start);

int pound_plus_flag(char *str, char flag, char buf[BUFFER], int *start_string, int start_buf);

int get_flags(char *str,char buf[BUFFER], int *start_string, int start_buf);

#endif
