#include "printf.h"
#include <limits.h>
#include <stdarg.h>
#include <stdbool.h>
/**
 * write_ll - Writes an number to the buffer
 * @num: The number to write
 * @buf: Buffer where the number will be written
 * @len: Pointer to an integer that keeps track of the current length of the
 * buffer
 *
 * Description: This function writes the digits of the number in
 * to the buffer, flushing it when necessary.
 */
static void write_ll(long long num, char buf[], int *len)
{
	int start = *len;
	bool is_ll_min = num == LLONG_MIN;

	if (num < 0)
	{
		if (*len == LENGTH)
		{
			flush(buf, *len);
			*len = 0;
		}
		buf[(*len)++] = '-';
		start = *len;
		num = is_ll_min ? LLONG_MAX : -num;
	}
	do
	{
		if (*len == LENGTH)
		{
			flush(buf, *len);
			*len = 0;
		}
		buf[(*len)++] = '0' + (is_ll_min ? num % 10 + 1 : num % 10);
		num /= 10;
	} while (num > 0);
	reverse(buf, start, *len - 1);
}

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
		return (long long)va_arg(*args, int);
	}
}

static int numlen(long long num)
{
	int len = 0;

	if (num == LLONG_MIN)
		return 20;
	if (num < 0)
	{
		len++;
		num = -num;
	}
	do
	{
		len++;
		num /= 10;
	} while (num > 0);
	return len;
}

static void write_space_or_plus(unsigned flags, char buf[], int *len)
{
	if ((flags & FLAG_PLUS) || (flags & FLAG_SPACE))
	{
		if (*len == LENGTH)
		{
			flush(buf, *len);
			*len = 0;
		}
		buf[(*len)++] = flags & FLAG_PLUS ? '+' : ' ';
	}
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
	long long num = get_num(fs->length, args);
	int num_len = numlen(num);
	int zero_padding, space_padding;

	space_padding = max(fs->width - num_len, 0);
	zero_padding = 0;
	if ((fs->flags & FLAG_ZERO) && !(fs->flags & FLAG_LEFT))
	{
		zero_padding = space_padding;
		space_padding = 0;
	}
	if (fs->precision >= 0)
	{
		zero_padding = max(fs->precision - num_len, 0);
		space_padding = max(fs->width - (num_len + zero_padding), 0);
	}
	if (fs->flags & FLAG_LEFT)
	{
		write_space_or_plus(fs->flags, buf, len);
		write_zero(buf, len, zero_padding);
		write_ll(num, buf, len);
		write_space(buf, len, space_padding);
	}
	else
	{
		write_space(buf, len, space_padding);
		write_space_or_plus(fs->flags, buf, len);
		write_zero(buf, len, zero_padding);
		write_ll(num, buf, len);
	}
}
