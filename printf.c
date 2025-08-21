#include <dispatcher.h>
#include <format_specifier.h>
#include <parser.h>
#include <printf.h>
#include <stdarg.h>
#include <utils.h>

/**
 * _printf - works just like the standard library printf
 * @format: format specifier
 * Return: number of bytes written to standard output
 */
int _printf(const char *format, ...)
{

	int len = 0, bufsize = 0;
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
			len += dispatch(&fs, &args, buf, &bufsize);
		}
		else
		{
			if (bufsize == LENGTH)
				flush(buf, &bufsize);
			buf[bufsize++] = *format;
			format++;
			len++;
		}
	}
	flush(buf, &bufsize);
	va_end(args);
	return (len);
}
