#include "main.h"

int print_buf(char buf[BUFFER])
{
	int i;

	for (i = 0; buf[i] != '\0'; i++)
	{
		write(1, &buf[i], 1);
	}
	return (i);
}

int get_flags(char *str,char buf[BUFFER], int *start_string, int start_buf)
{
	while
	(
	str[*start_string] != 's' && str[*start_string] != 'p' && str[*start_string] != 'x'
	&& str[*start_string] != 'X' && str[*start_string] != 'i' && str[*start_string] != 'd' &&
	str[*start_string] != 'c'  && str[*start_string] != 'u' && str[*start_string] != 'o'
        && str[*start_string] != 'b' && str[*start_string] != 'R' && str[*start_string] != '%' &&
        str[*start_string] != 'S' && str[*start_string] != 'r'
	)
	{
		switch (str[*start_string])
		{
		case '#':
		case '+':
			start_buf = pound_plus_flag(str, str[*start_string], buf, start_string, start_buf);
			break;
		default:
			break;
		}
		*start_string = *start_string + 1;
	}
	return (start_buf);
}
