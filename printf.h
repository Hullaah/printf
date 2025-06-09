#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdbool.h>

#define LENGTH 1024
#define FLAG_LEFT (1 << 0)
#define FLAG_PLUS (1 << 1)
#define FLAG_SPACE (1 << 2)
#define FLAG_ZERO (1 << 3)
#define FLAG_HASH (1 << 4)

/**
 * enum LengthModifier - Represents the length modifiers used in format
 * specifiers for printf-like functions.
 *
 * Description: This enumeration defines the possible length modifiers that can
 * be used to alter the interpretation of the corresponding argument in a format
 * specifier. These modifiers are typically used to specify the size of the
 * argument (such as short, long, etc.).
 *
 * - LEN_NONE: No length modifier specified.
 * - LEN_HH:   'hh' length modifier (e.g., for signed char or unsigned char).
 * - LEN_H:    'h' length modifier (e.g., for short int or unsigned short int).
 * - LEN_LL:   'll' length modifier (e.g., for long long int or unsigned long
 * long int).
 * - LEN_L:    'l' length modifier (e.g., for long int or unsigned long int).
 */
typedef enum
{
	LEN_NONE,
	LEN_HH,
	LEN_H,
	LEN_LL,
	LEN_L
} LengthModifier;

/**
 * struct FormatSpecifier - Represents a parsed format specifier
 *
 * @flags:      Bitwise OR of formatting flags (e.g., FLAG_LEFT, FLAG_PLUS,
 * etc.).
 * @width:      Minimum field width for the output, or 0 if not specified.
 * @length:     Length modifier for the argument (see enum LengthModifier).
 * @specifier:  Conversion specifier character (e.g., 'd', 's', 'x', etc.).
 *
 * Description:
 *   This structure encapsulates all the components of a format specifier as
 * parsed from a printf-style format string. It is used to pass formatting
 * information to handler functions responsible for producing the formatted
 * output.
 */
typedef struct
{
	int flags;
	int width;
	int precision;
	LengthModifier length;
	char specifier;
} FormatSpecifier;

/**
 * format_handler_fn - Function pointer type for handling format specifiers.
 *
 * @fs:   Pointer to a FormatSpecifier structure containing the parsed
 *        formatting information for the current specifier.
 * @args: Pointer to a va_list containing the variable arguments to be
 *        formatted and printed.
 *
 * Return: The number of characters written by the handler, or a negative value
 *         on error.
 *
 * Description:
 *   This function pointer type defines the interface for handler functions
 *   responsible for processing specific format specifiers (such as 'd', 's',
 *   'x', etc.) in a printf-like implementation. Each handler receives the
 *   parsed format specifier and the argument list, and is expected to produce
 *   the formatted output accordingly.
 */
typedef void (*format_handler_fn)(FormatSpecifier *fs, va_list *args, char buf[], int *len);

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

typedef struct
{
	char c;
	format_handler_fn handler;
} FormatHandlerEntry;

int _printf(const char *format, ...);

bool _isdigit(int c);

int _atoi(const char **string);

void parse_format_specifier(const char **format, FormatSpecifier *out);

format_handler_fn dispatch_handler(char c);

void dispatch(FormatSpecifier *fs, va_list *args, char buf[], int *len);

void flush(char buf[], int len);

void handle_decimal(FormatSpecifier *fs, va_list *args, char buf[], int *len);

void handle_binary(FormatSpecifier *fs, va_list *args, char buf[], int *len);

void handle_octal(FormatSpecifier *fs, va_list *args, char buf[], int *len);

void handle_hexadecimal(FormatSpecifier *fs, va_list *args, char buf[], int *len);

void handle_unsigned(FormatSpecifier *fs, va_list *args, char buf[], int *len);

void handle_pointer(FormatSpecifier *fs, va_list *args, char buf[], int *len);

void handle_string(FormatSpecifier *fs, va_list *args, char buf[], int *len);

void handle_char(FormatSpecifier *fs, va_list *args, char buf[], int *len);

void handle_percent(FormatSpecifier *fs, va_list *args, char buf[], int *len);

void handle_unprintable(FormatSpecifier *fs, va_list *args, char buf[], int *len);

void handle_reverse(FormatSpecifier *fs, va_list *args, char buf[], int *len);

void handle_rot13(FormatSpecifier *fs, va_list *args, char buf[], int *len);

#endif
