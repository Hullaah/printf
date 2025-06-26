#include "printf.h"
#include <stdarg.h>
#include <limits.h>
/**
 * write_int - Writes an integer to the buffer
 * @num: The integer to write
 * @buf: Buffer where the integer will be written
 * @len: Pointer to an integer that keeps track of the current length of the
 * buffer
 *
 * Description: This function writes the digits of the integer in
 * to the buffer, flushing it when necessary.
 */
static void write_int(int num, char buf[], int *len)
{
	int start = *len;
	int is_int_min = num == INT_MIN;

	if (num < 0)
	{
		if (*len == LENGTH)
		{
			flush(buf, *len);
			*len = 0;
		}
		buf[(*len)++] = '-';
		start = *len;
		num = is_int_min ? INT_MAX : -num;
	}
	do
	{
		if (*len == LENGTH)
		{
			flush(buf, *len);
			*len = 0;
		}
		buf[(*len)++] = '0' + (is_int_min ? num % 10 + 1 : num % 10);
		num /= 10;
	} while (num > 0);
	reverse(buf, start, *len - 1);
}

/**
 * handle_decimal - Handles the decimal format specifier
 * @fs: Pointer to the FormatSpecifier structure
 * @args: Pointer to the va_list containing the arguments
 * @buf: Buffer where the formatted output will be stored
 * @len: Pointer to an integer that keeps track of the current length of the
 * buffer
 * Description: This function retrieves a decimal argument from the va_list and
 * appends it to the buffer, flushing it when necessary.
 */
void handle_decimal(struct FormatSpecifier *fs, va_list *args, char *buf,
		    int *len)
{
}
