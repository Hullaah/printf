#include <stdarg.h>
#include "printf.h"
/**
 * _printf - works just like the standard library printf
 * @format: format specifier
 * Return: number of bytes written to standard output
 */
int _printf(const char *format, ...)
{

	int len = 0, i = 0;
	char buf[LENGTH];

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			FormatSpecifier fs;
			parse_format_specifier(&format, &fs);
		}
		buf[i++] = *format;
		len++;
		format++;
	}
	return (0);
}
