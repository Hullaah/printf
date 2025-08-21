#ifndef HANDLERS_H
#define HANDLERS_H

#include <stdarg.h>
#include "format_specifier.h"
/**
 * struct FormatHandlerEntry - Associates a format specifier character with its
 * handler function.
 *
 * @c:      The format specifier character (e.g., 'd', 's', 'x', etc.).
 * @handler: Pointer to the handler function responsible for processing the
 *          corresponding format specifier. The handler function should match
 *          the format_handler_fn signature and is called to produce the
 *          formatted output for the given specifier.
 *
 * Description:
 *   This structure is used to map each supported format specifier character to
 *   its corresponding handler function in a printf-like implementation. It
 *   enables efficient lookup and dispatch of handler functions during format
 *   string parsing and output generation.
 */
struct FormatHandlerEntry
{
	char c;
	format_handler_fn handler;
};

int handle_decimal(struct FormatSpecifier *, va_list *, char[], int *);
int handle_binary(struct FormatSpecifier *, va_list *, char[], int *);
int handle_octal(struct FormatSpecifier *, va_list *, char[], int *);
int handle_hexadecimal(struct FormatSpecifier *, va_list *, char[], int *);
int handle_unsigned(struct FormatSpecifier *, va_list *, char[], int *);
int handle_pointer(struct FormatSpecifier *, va_list *, char[], int *);
int handle_string(struct FormatSpecifier *, va_list *, char[], int *);
int handle_char(struct FormatSpecifier *, va_list *, char[], int *);
int handle_percent(struct FormatSpecifier *, va_list *, char[], int *);
int handle_unprintable(struct FormatSpecifier *, va_list *, char[], int *);
int handle_reverse(struct FormatSpecifier *, va_list *, char[], int *);
int handle_rot13(struct FormatSpecifier *, va_list *, char[], int *);

#endif
