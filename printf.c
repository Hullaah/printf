#include "main.h"
/**
 * _printf - works just like the standard library printf
 * @format: format specifier
 * Return: number of bytes written to standard output
*/
int _printf(char *format, ...)
{
	int write_count = 0, i, j;
	unsigned int k;
	char c, *s;
        long l;
	va_list args;
        char buf[BUFFER];


        if (format == NULL)
                return (-1);
	va_start(args, format);
	for (i = 0; format[i] != '\0'; i++)
	{
		while (format[i] != '%' && format[i] != '\0')
		{
			c = format[i];
                        buf[write_count] =  c;
			/*write(1, &c, 1);*/
			i++;
			write_count++;
		}
		if (format[i] == '\0')
		{
                        buf[write_count] = '\0';
			return (print_buf(buf));
		}
		i++;
		switch (format[i])
		{
		case 's':
                case 'S':
			s = va_arg(args, char *);
			write_count = print_string(s, format[i], buf, write_count);
			break;
		case 'c':
			c = (char) va_arg(args, int);
                        buf[write_count] = c;
			/*write(1, &c, 1);*/
			write_count++;
			break;
		case '%':
			c = '%';
			/*write(1, &c, 1);*/
                        buf[write_count] = c;
			write_count++;
			break;
		case 'd':
		case 'i':
			j = va_arg(args, int);
			write_count = print_numbers(&j, 10, 'd', buf, write_count);
			break;
		case 'b':
			k = va_arg(args, unsigned int);
			write_count = print_numbers(&k, 2, '\0', buf, write_count);
			break;
		case 'o':
			k = va_arg(args, unsigned int);
			write_count = print_numbers(&k, 8, '\0', buf, write_count);
			break;
		case 'x':
		case 'X':
			k = va_arg(args, unsigned int);
			write_count = print_numbers(&k, 16, format[i], buf, write_count);
			break;
		case 'u':
			k = va_arg(args, unsigned int);
			write_count = print_numbers(&k, 10, 'u', buf, write_count);
			break;
                case 'p':
                        l = va_arg(args, long);
                        write_count = print_numbers(&l, 16, format[i], buf, write_count);
                        break;
		default:
			break;
		}
	}
        buf[write_count] = '\0';
	va_end(args);
	return (print_buf(buf));
}
