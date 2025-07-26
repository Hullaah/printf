#include <handlers.h>
#include <utils.h>

/**
 * write_ull - Writes an number to the buffer
 * @num: The number to write
 * @buf: Buffer where the number will be written
 * @len: Pointer to an integer that keeps track of the current length of the
 * buffer
 *
 * Description: This function writes the digits of the number in
 * to the buffer, flushing it when necessary.
 */
static void write_ull(unsigned long long num, char buf[], int *len)
{
	int start = *len;

	do
	{
		if (*len == LENGTH)
		{
			flush(buf, *len);
			*len = 0;
		}
		buf[(*len)++] = '0' + num % 10;
		num /= 10;
	} while (num > 0);
	reverse(buf, start, *len - 1);
}

void handle_unsigned(struct FormatSpecifier *fs, va_list *args, char *buf,
		     int *len)
{
	unsigned long long num = get_unum(fs->length, args);
	int num_len = unumlen(num, 10);
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
		write_zero(buf, len, zero_padding);
		write_ull(num, buf, len);
		write_space(buf, len, space_padding);
	}
	else
	{
		write_space(buf, len, space_padding);
		write_zero(buf, len, zero_padding);
		write_ull(num, buf, len);
	}
}
