#ifndef FORMAT_SPECIFIER_H
#define FORMAT_SPECIFIER_H

#include <stdarg.h>
#include <stdbool.h>
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
 * @buf:  Buffer where the formatted output will be written.
 * @len:  Pointer to an integer that keeps track of the current length of the
 *        buffer. This value is updated as characters are written to the buffer.
 * Description:
 *   This function pointer type defines the interface for handler functions
 *   responsible for processing specific format specifiers (such as 'd', 's',
 *   'x', etc.) in a printf-like implementation. Each handler receives the
 *   parsed format specifier and the argument list, and is expected to produce
 *   the formatted output accordingly.
 */
typedef void (*format_handler_fn)(struct FormatSpecifier *fs, va_list *args,
				  char buf[], int *len);

#endif
