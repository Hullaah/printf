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

	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			FormatSpecifier fs;
			parse_format_specifier(&format, &fs);
			format_handler_fn handler =
			    dispatch_handler(fs.specifier);
			if (handler)
			{
				len += handler(&fs, &args);
			}
			else
			{
				buf[len++] = '%';
				if (fs.specifier != '\0')
					buf[len++] = fs.specifier;
			}
		}
		else
		{
			format++;
			buf[len++] = *format;
		}
	}
	va_end(args);
	return (len);
}
