#include "main.h"

int pound_plus_flag(char *str, char flag, char buf[BUFFER], int *start_string, int start_buf)
{
	int i = *start_string;
	if (flag == '#')
	{
		while (str[i] != 'x' && str[i] != 'X' && str[i] != 'o' && str[i] != '\0')
		{

			if (
				str[i] == 's' || str[i] == 'p' || str[i] == 'R' || str[i] == 'i'
				|| str[i] == 'd' || str[i] == 'r' || str[i] == 'c' || str[i] == 'S'
				|| str[i] == 'u' || str[i] == '%' || str[i] == 'b'
			)
				return (start_buf);
			i++;
		}
		if (str[i] == '\0')
			return (start_buf);
		if (str[i] == 'x' || str[i] == 'X')
		{
			buf[start_buf] = '0';
			buf[++start_buf] = str[i];
		}
		else
			buf[start_buf] = '0';

	}
	else if (flag == '+')
	{
		while (str[i] != 'd' && str[i] != 'i' && str[i] != '\0')
		{
			if (
				str[i] == 's' || str[i] == 'p' || str[i] == 'R' || str[i] == 'x'
				|| str[i] == 'X' || str[i] == 'r' || str[i] == 'c' || str[i] == 'S'
				|| str[i] == 'u' || str[i] == '%' || str[i] == 'b' || str[i] == 'o'
			)
				return (start_buf);
			i++;
		}
		if (str[i] == '\0')
			return (start_buf);
		if (str[i] == 'd' || str[i] == 'i')
			buf[start_buf] = '+';
	}
	return (start_buf + 1);
}