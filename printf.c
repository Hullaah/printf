#include "printf.h"
#include <stdarg.h>
/**
 * _printf - works just like the standard library printf
 * @format: format specifier
 * Return: number of bytes written to standard output
 */
int _printf(const char *format, ...)
{

	int len = 0;
	char buf[LENGTH];
	va_list args;
	struct FormatSpecifier fs;

	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			parse_format_specifier(&format, &fs);
			dispatch(&fs, &args, buf, &len);
		}
		else
		{
			if (len == LENGTH)
			{
				flush(buf, len);
				len = 0;
			}
			buf[len++] = *format;
			format++;
		}
	}
	flush(buf, len);
	va_end(args);
	return (len);
}
