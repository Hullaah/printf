#ifndef HANDLERS_H
#define HANDLERS_H

#include "format_specifier.h"
#include <stdarg.h>
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

void handle_decimal(struct FormatSpecifier *, va_list *, char[], int *);
void handle_binary(struct FormatSpecifier *, va_list *, char[], int *);
void handle_octal(struct FormatSpecifier *, va_list *, char[], int *);
void handle_hexadecimal(struct FormatSpecifier *, va_list *, char[], int *);
void handle_unsigned(struct FormatSpecifier *, va_list *, char[], int *);
void handle_pointer(struct FormatSpecifier *, va_list *, char[], int *);
void handle_string(struct FormatSpecifier *, va_list *, char[], int *);
void handle_char(struct FormatSpecifier *, va_list *, char[], int *);
void handle_percent(struct FormatSpecifier *, va_list *, char[], int *);
void handle_unprintable(struct FormatSpecifier *, va_list *, char[], int *);
void handle_reverse(struct FormatSpecifier *, va_list *, char[], int *);
void handle_rot13(struct FormatSpecifier *, va_list *, char[], int *);

#endif
