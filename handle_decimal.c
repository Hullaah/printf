#include <format_specifier.h>
#include <handlers.h>
#include <limits.h>
#include <stdarg.h>
#include <stdbool.h>
#include <utils.h>
/**
 * write_ll - Writes an number to the buffer
 * @num: The number to write
 * @buf: Buffer where the number will be written
 * @bufsize: Pointer to an integer that keeps track of the current length of the
 * buffer
 *
 * Description: This function writes the digits of the number in
 * to the buffer, flushing it when necessary.
 */
static int write_ll(long long num, char buf[], int *bufsize)
{
	int start = *bufsize;
	bool is_ll_min = num == LLONG_MIN;

	if (num < 0)
		num = is_ll_min ? LLONG_MAX : -num;
	do
	{
		if (*bufsize == LENGTH)
			flush(buf, bufsize);
		buf[(*bufsize)] =
		    '0' + ((is_ll_min && *bufsize == start) ? num % 10 + 1
							    : num % 10);
		(*bufsize)++;
		num /= 10;
	} while (num > 0);
	reverse(buf, start, *bufsize - 1);
	return *bufsize - start;
}

/**
 * get_num - Retrieves a number from the va_list based on the length modifier
 * @length: The length modifier that indicates how to interpret the argument
 * @args: Pointer to the va_list containing the arguments
 * Description: This function retrieves a number from the va_list based on the
 * specified length modifier.
 * It handles different length modifiers such as hh, h, l, ll, and none.
 * Returns: The number as a long long integer.
 */
static long long get_num(enum LengthModifier length, va_list *args)
{
	switch (length)
	{
	case LEN_HH:
		return (long long)(char)va_arg(*args, int);
	case LEN_H:
		return (long long)(short)va_arg(*args, int);
	case LEN_L:
		return (long long)(long)va_arg(*args, long);
	case LEN_LL:
		return (long long)va_arg(*args, long long);
	default:
		return (long long)(int)va_arg(*args, int);
	}
}

/**
 * numlen - Calculates the number of digits in a long long integer
 * @num: The number for which to calculate the length
 * Description: This function calculates the number of digits in a long long
 * integer, handling special cases such as LLONG_MIN.
 * Returns: The number of digits in the number.
 */
static int numlen(long long num)
{
	int len = 0;

	if (num == LLONG_MIN)
		return 20;
	if (num < 0)
		num = -num;
	do
	{
		len++;
		num /= 10;
	} while (num > 0);
	return len;
}
/**
 * write_sign - Writes the sign of the number to the buffer
 * @flags: The flags indicating how to format the sign
 * @is_negative: A boolean indicating if the number is negative
 * @buf: Buffer where the sign will be written
 * @bufsize: Pointer to an integer that keeps track of the current length of the
 * buffer
 * Description: This function writes the sign of the number to the buffer
 * based on the flags and whether the number is negative.
 */
static int write_sign(unsigned flags, bool is_negative, char buf[],
		      int *bufsize)
{
	if (is_negative)
	{
		if (*bufsize == LENGTH)
			flush(buf, bufsize);
		buf[(*bufsize)++] = '-';
		return 1;
	}
	else if ((flags & FLAG_PLUS) || (flags & FLAG_SPACE))
	{
		if (*bufsize == LENGTH)
			flush(buf, bufsize);
		buf[(*bufsize)++] = flags & FLAG_PLUS ? '+' : ' ';
		return 1;
	}
	return 0;
}

/**
 * handle_decimal - Handles the decimal format specifier
 * @fs: Pointer to the FormatSpecifier structure
 * @args: Pointer to the va_list containing the arguments
 * @buf: Buffer where the formatted output will be stored
 * @bufsize: Pointer to an integer that keeps track of the current length of the
 * buffer
 * Description: This function retrieves a decimal argument from the va_list and
 * appends it to the buffer, flushing it when necessary.
 */
int handle_decimal(struct FormatSpecifier *fs, va_list *args, char *buf,
		   int *bufsize)
{
	long long num = get_num(fs->length, args);
	int num_len = numlen(num);
	int zero_padding, space_padding;
	int bytes_written = 0;

	space_padding = max(fs->width - num_len, 0);
	zero_padding = 0;
	if ((fs->flags & FLAG_ZERO) && !(fs->flags & FLAG_LEFT))
	{
		zero_padding = space_padding;
		space_padding = 0;
		if (num < 0 || fs->flags & FLAG_SPACE || fs->flags & FLAG_PLUS)
			zero_padding--;
	}
	if (fs->precision >= 0)
	{
		zero_padding = max(fs->precision - num_len, 0);
		space_padding = max(fs->width - (num_len + zero_padding), 0);
		if (num < 0 || fs->flags & FLAG_SPACE || fs->flags & FLAG_PLUS)
			space_padding--;
	}
	bytes_written += space_padding + zero_padding;
	if (fs->flags & FLAG_LEFT)
	{
		bytes_written += write_sign(fs->flags, num < 0, buf, bufsize);
		write_zero(buf, bufsize, zero_padding);
		bytes_written += write_ll(num, buf, bufsize);
		write_space(buf, bufsize, space_padding);
	}
	else
	{
		write_space(buf, bufsize, space_padding);
		bytes_written += write_sign(fs->flags, num < 0, buf, bufsize);
		write_zero(buf, bufsize, zero_padding);
		bytes_written += write_ll(num, buf, bufsize);
	}
	return bytes_written;
}
