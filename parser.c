#include "printf.h"

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

static int parse_width(const char **format)
{
	int width = 0;
	int base = 1;
	char c;

	while (_isdigit(c = *(*format)++))
	{
		width *= base;
		width += c - '0';
		base *= 10;
	}
	return (width);
}

static LengthModifier parse_length(const char **format)
{
	if (**format) {
		if ((*format)[0] == 'h' && (*format)[1] == 'h')
			return LEN_HH;
		else if ((*format)[0] == 'h')
			return LEN_H;
		else if ((*format)[0] == 'l' && (*format)[1] == 'l')
			return LEN_LL;
		else if ((*format)[0] == 'l')
			return LEN_L;
		else
			return LEN_NONE;
	}
	return LEN_NONE;
}

static char parse_specifier(const char **format)
{
	char specifier = **format;
	if (specifier == 'd' || specifier == 'i' || specifier == 'b' ||
	    specifier == 'o' || specifier == 'x' || specifier == 'X' ||
	    specifier == 'u' || specifier == 'p' || specifier == 's' ||
	    specifier == 'c' || specifier == '%' || specifier == 'S' ||
	    specifier == 'r' || specifier == 'R')
	{
		(*format)++;
		return (specifier);
	}
	return (0);
}

void parse_format_specifier(const char **format, FormatSpecifier *out)
{
	out->flags = parse_flags(format);
	out->width = parse_width(format);
	out->length = parse_length(format);
	out->specifier = parse_specifier(format);
}
