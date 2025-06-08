#include "printf.h"

/**
 * parse_flags - parses the flags from he format string into a bitmask
 * @format: pointer to format string
 * Return: The bitmask of flags in the format string
 */
static int parse_flags(const char **format)
{
	int flags = 0;

	while (**format)
	{
		switch (*(*format)++)
		{
		case '-':
			flags |= FLAG_LEFT;
			break;
		case '+':
			flags |= FLAG_PLUS;
			break;
		case ' ':
			flags |= FLAG_SPACE;
			break;
		case '0':
			flags |= FLAG_ZERO;
			break;
		case '#':
			flags |= FLAG_HASH;
			break;
		default:
			return (flags);
		}
	}
	return (flags);
}

/**
 * parse_width - parses the width from the format string
 * @format: pointer to format string
 * Return: The parsed width from the format specifier
 */
static int parse_width(const char **format) { return (_atoi(format)); }

/**
 * parse_precision - parses the precision from the format string
 * @format: pointer to format string
 * Return: The parsed precision from the format specifier
 */
static int parse_precision(const char **format)
{
	return (**format == '.' ? _atoi(format) : 0);
}

/**
 * parse_length - parses the length modifier from the format string
 * @format: pointer to format string
 * Return: An enum representing the length modifier
 */
static LengthModifier parse_length(const char **format)
{
	if (**format)
	{
		if ((*format)[0] == 'h' && (*format)[1] == 'h')
			return (LEN_HH);
		else if ((*format)[0] == 'h')
			return (LEN_H);
		else if ((*format)[0] == 'l' && (*format)[1] == 'l')
			return (LEN_LL);
		else if ((*format)[0] == 'l')
			return (LEN_L);
		else
			return (LEN_NONE);
	}
	return (LEN_NONE);
}

/**
 * parse_specifier - parses the specifier  from the format string
 * @format: pointer to format string
 * Return: The specfier as a char
 */
static char parse_specifier(const char **format) { return *(*format)++; }

/**
 * parse_format_specifier - parse format specifier from the format string into
 * the format specifier struct
 * @format: pointer to format string
 * @out: struct to output the parsed specifier into
 */
void parse_format_specifier(const char **format, FormatSpecifier *out)
{
	out->flags = parse_flags(format);
	out->width = parse_width(format);
	out->precision = parse_precision(format);
	out->length = parse_length(format);
	out->specifier = parse_specifier(format);
}
