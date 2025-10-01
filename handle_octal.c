#include <format_specifier.h>
#include <handlers.h>
#include <stdarg.h>
#include <utils.h>

#define PREFIX_LENGTH 1

/**
 * write_octal - Writes an octal number to the buffer
 * @num: The number to write
 * @buf: Buffer where the number will be written
 * @bufsize: Pointer to an integer that keeps track of the current length of the
 * buffer
 *
 * Description: This function writes the digits of the octal number in
 * to the buffer, flushing it when necessary.
 */
static int write_octal(unsigned long long num, char buf[],
		       int *bufsize)
{
	int start = *bufsize;

	do {
		if (*bufsize == LENGTH)
			flush(buf, bufsize);
		buf[(*bufsize)++] = num % 8 + '0';
		num /= 8;
	} while (num > 0);
	reverse(buf, start, *bufsize - 1);
	return *bufsize - start;
}

/**
 * write_prefix - Writes the prefix for octal numbers
 * @buf: Buffer where the prefix will be written
 * @bufsize: Pointer to an integer that keeps track of the current length of the
 * buffer
 * Return: The length of the prefix written to the buffer
 */
static int write_prefix(char buf[], int *bufsize)
{
	if (*bufsize == LENGTH)
		flush(buf, bufsize);
	buf[(*bufsize)++] = '0';
	return PREFIX_LENGTH;
}

/**
 * handle_octal - Handles the octal format specifier
 * @fs: Pointer to the FormatSpecifier structure
 * @args: Pointer to the va_list containing the arguments
 * @buf: Buffer where the formatted output will be stored
 * @bufsize: Pointer to an integer that keeps track of the current length of the
 * buffer
 *
 * Description: This function retrieves an octal number from the va_list and
 * appends it to the buffer, flushing it when necessary.
 */
int handle_octal(struct FormatSpecifier *fs, va_list *args, char *buf,
		 int *bufsize)
{
	unsigned long long num = get_unum(fs->length, args);
	int num_len = unumlen(num, 8);
	int zero_padding, space_padding;
	int bytes_written = 0;

	space_padding = max(fs->width - num_len -
				    (fs->flags & FLAG_HASH ? PREFIX_LENGTH : 0),
			    0);
	zero_padding = 0;
	if ((fs->flags & FLAG_ZERO) && !(fs->flags & FLAG_LEFT)) {
		zero_padding = space_padding;
		space_padding = 0;
	}
	if (fs->precision >= 0) {
		zero_padding =
			max(fs->precision - num_len -
				    (fs->flags & FLAG_HASH ? PREFIX_LENGTH : 0),
			    0);
		space_padding = max(fs->width - (num_len + zero_padding), 0);
	}
	bytes_written += space_padding + zero_padding;
	if (fs->flags & FLAG_LEFT) {
		if ((fs->flags & FLAG_HASH) && num != 0)
			bytes_written += write_prefix(buf, bufsize);
		write_zero(buf, bufsize, zero_padding);
		bytes_written += write_octal(num, buf, bufsize);
		write_space(buf, bufsize, space_padding);
	} else {
		write_space(buf, bufsize, space_padding);
		if ((fs->flags & FLAG_HASH) && num != 0)
			bytes_written += write_prefix(buf, bufsize);
		write_zero(buf, bufsize, zero_padding);
		bytes_written += write_octal(num, buf, bufsize);
	}
	return bytes_written;
}
