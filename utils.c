#include <unistd.h>
#include <utils.h>

/**
 * _isdigit - checks if a given character is a digit
 * @c: character to check whether is digit
 * Return: true if character is a digit false otherwise
 */
bool _isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

/**
 * _atoi - converts a string pointed to by ptr to an integer
 * @ptr: pointer to string to convert to integer
 * Return: The converted integer
 */
int _atoi(const char **ptr)
{
	int num = 0, base = 1;

	while (_isdigit(**ptr)) {
		num *= base;
		num += **ptr - '0';
		base *= 10;
		(*ptr)++;
	}
	return (num);
}

/**
 * flush - flushes the buffer to stdout
 * @buf: buffer to flush to stdout
 * @bufsize: size of the buffer
 */
void flush(char *buf, int *bufsize)
{
	write(STDOUT_FILENO, buf, *bufsize);
	*bufsize = 0;
}

/**
 * _strlen - calculates the length of a string
 * @str: string to calculate length of
 * Return: The length of the string
 */
int _strlen(const char *str)
{
	int bufsize = 0;

	while (str[bufsize])
		bufsize++;
	return (bufsize);
}

/**
 * write_zero - writes zeroes to the buffer
 * @buf: buffer to write zeroes to
 * @bufsize: current size of the buffer
 * @count: number of zeroes to write
 */
void write_zero(char *buf, int *bufsize, int count)
{
	int i;

	for (i = 0; i < count; i++) {
		if (*bufsize == LENGTH)
			flush(buf, bufsize);
		buf[(*bufsize)++] = '0';
	}
}
/**
 * write_space - writes spaces to the buffer
 * @buf: buffer to write spaces to
 * @bufsize: current size of the buffer
 * @count: number of spaces to write
 */
void write_space(char *buf, int *bufsize, int count)
{
	int i;

	for (i = 0; i < count; i++) {
		if (*bufsize == LENGTH)
			flush(buf, bufsize);
		buf[(*bufsize)++] = ' ';
	}
}
/**
 * reverse - reverses a string in place
 * @buf: buffer containing the string to reverse
 * @start: starting index of the string to reverse
 * @end: ending index of the string to reverse
 */
void reverse(char *buf, int start, int end)
{
	char temp;

	while (start < end) {
		temp = buf[start];
		buf[start] = buf[end];
		buf[end] = temp;
		start++;
		end--;
	}
}
/**
 * unumlen - calculates the length of an unsigned number in a given base
 * @num: the unsigned number to calculate length of
 * @base: the base to use for the calculation
 * Return: The length of the number in the specified base
 */
int unumlen(unsigned long long num, int base)
{
	int bufsize = 0;

	do {
		bufsize++;
	} while ((num /= base) > 0);
	return bufsize;
}
/**
 * get_unum - retrieves an unsigned number from the va_list based on the length
 * modifier
 * @size: the length modifier that indicates how to interpret the argument
 * @args: pointer to the va_list containing the arguments
 * Return: The unsigned number as an unsigned long long integer.
 */
unsigned long long get_unum(enum LengthModifier size, va_list *args)
{
	switch (size) {
	case LEN_HH:
		return (unsigned long long)(unsigned char)va_arg(*args,
								 unsigned int);
	case LEN_H:
		return (unsigned long long)(unsigned short)va_arg(*args,
								  unsigned int);
	case LEN_L:
		return (unsigned long long)(unsigned long)va_arg(*args,
								 unsigned long);
	case LEN_LL:
		return (unsigned long long)va_arg(*args, unsigned long long);
	default:
		return (unsigned long long)va_arg(*args, unsigned int);
	}
}
