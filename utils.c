#include "printf.h"
#include <unistd.h>

/**
 * _isdigit - checks if a given character is a digit
 * @c: character to check whether is digit
 * Return: true if character is a digit false otherwise
 */
bool _isdigit(int c) { return (c >= '0' && c <= '9'); }

/**
 * _atoi - converts a string pointed to by ptr to an integer
 * @ptr: pointer to string to convert to integer
 * Return: The converted integer
 */
int _atoi(const char **ptr)
{
	int num = 0, base = 1;

	while (_isdigit(**ptr))
	{
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
 * @len: length of the buffer
 */
void flush(char *buf, int len) { write(STDOUT_FILENO, buf, len); }


/**
 * _strlen - calculates the length of a string
 * @str: string to calculate length of
 * Return: The length of the string
 */
int _strlen(const char *str)
{
	int len = 0;

	while (str[len])
		len++;
	return (len);
}

/**
 * write_zero - writes zeroes to the buffer
 * @buf: buffer to write zeroes to
 * @len: current length of the buffer
 * @count: number of zeroes to write
 */
void write_zero(char *buf, int *len, int count)
{
	int i;

	for (i = 0; i < count; i++)
	{
		if (*len == LENGTH)
		{
			flush(buf, *len);
			*len = 0;
		}
		buf[(*len)++] = '0';
	}
}
/**
 * write_space - writes spaces to the buffer
 * @buf: buffer to write spaces to
 * @len: current length of the buffer
 * @count: number of spaces to write
 */
void write_space(char *buf, int *len, int count)
{
	int i;

	for (i = 0; i < count; i++)
	{
		if (*len == LENGTH)
		{
			flush(buf, *len);
			*len = 0;
		}
		buf[(*len)++] = ' ';
	}
}

void reverse(char *buf, int start, int end)
{
	char temp;

	while (start < end)
	{
		temp = buf[start];
		buf[start] = buf[end];
		buf[end] = temp;
		start++;
		end--;
	}
}
