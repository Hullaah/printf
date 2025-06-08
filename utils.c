#include "printf.h"
#include <stdbool.h>
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
