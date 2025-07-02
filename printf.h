#ifndef PRINTF_H
#define PRINTF_H

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
#define UNUSED(x) ((void) (x))

/**
 * enum LengthModifier - Represents the length modifiers used in format
 * specifiers for printf-like functions.
 *
 * Description: This enumeration defines the possible length modifiers that can
 * be used to alter the interpretation of the corresponding argument in a
 * format specifier. These modifiers are typically used to specify the size of
 * the argument (such as short, long, etc.).
 *
 * @LEN_NONE: No length modifier specified.
 * @LEN_HH:   'hh' length modifier (e.g., for signed char or unsigned char).
 * @LEN_H:    'h' length modifier (e.g., for short int or unsigned short int).
 * @LEN_LL:   'll' length modifier (e.g., for long long int or unsigned long
 * long int).
 * @LEN_L:    'l' length modifier (e.g., for long int or unsigned long int).
 */
enum LengthModifier
{
	LEN_NONE,
	LEN_HH,
	LEN_H,
	LEN_LL,
	LEN_L
};

/**
 * struct FormatSpecifier - Represents a parsed format specifier
 *
 * @flags:      Bitwise OR of formatting flags (e.g., FLAG_LEFT, FLAG_PLUS,
 * etc.).
 * @width:      Minimum field width for the output, or 0 if not specified.
 * @precision:  Precision for the output, or -1 if not specified. For strings,
 * it indicates the maximum number of characters to print. For integers, it
 * indicates the minimum number of digits to print (padded with zeros if
 * necessary)
 * @length:     Length modifier for the argument (see enum LengthModifier).
 * @specifier:  Conversion specifier character (e.g., 'd', 's', 'x', etc.).
 *
 * Description:
 *   This structure encapsulates all the components of a format specifier as
 * parsed from a printf-style format string. It is used to pass formatting
 * information to handler functions responsible for producing the formatted
 * output.
 */
struct FormatSpecifier
{
	unsigned int flags;
	int width;
	int precision;
	enum LengthModifier length;
	char specifier;
};

/**
 * format_handler_fn - Function pointer type for handling format specifiers.
 *
 * @fs:   Pointer to a struct FormatSpecifier structure containing the parsed
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
typedef void (*format_handler_fn)(struct FormatSpecifier *fs, va_list *args,
				  char buf[], int *len);

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

int _printf(const char *format, ...);

bool _isdigit(int c);

int _atoi(const char **string);

int _strlen(const char *str);

void write_zero(char *buf, int *len, int count);

void write_space(char *buf, int *len, int count);

void reverse(char *buf, int start, int end);

void parse_format_specifier(const char **format, struct FormatSpecifier *out);

format_handler_fn dispatch_handler(char c);

void dispatch(struct FormatSpecifier *fs, va_list *args, char buf[], int *len);

void flush(char buf[], int len);

void handle_decimal(struct FormatSpecifier *fs, va_list *args, char buf[],
		    int *len);

void handle_binary(struct FormatSpecifier *fs, va_list *args, char buf[],
		   int *len);

void handle_octal(struct FormatSpecifier *fs, va_list *args, char buf[],
		  int *len);

void handle_hexadecimal(struct FormatSpecifier *fs, va_list *args, char buf[],
			int *len);

void handle_unsigned(struct FormatSpecifier *fs, va_list *args, char buf[],
		     int *len);

void handle_pointer(struct FormatSpecifier *fs, va_list *args, char buf[],
		    int *len);

void handle_string(struct FormatSpecifier *fs, va_list *args, char buf[],
		   int *len);

void handle_char(struct FormatSpecifier *fs, va_list *args, char buf[],
		 int *len);

void handle_percent(struct FormatSpecifier *fs, va_list *args, char buf[],
		    int *len);

void handle_unprintable(struct FormatSpecifier *fs, va_list *args, char buf[],
			int *len);

void handle_reverse(struct FormatSpecifier *fs, va_list *args, char buf[],
		    int *len);

void handle_rot13(struct FormatSpecifier *fs, va_list *args, char buf[],
		  int *len);

#endif
