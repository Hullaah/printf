#include <format_specifier.h>
#include <handlers.h>
#include <stdarg.h>
#include <utils.h>

#define PREFIX_LENGTH 2

/**
 * write_hex - Writes a hexadecimal number to the buffer
 * @specifier: The format specifier character ('x' or 'X')
 * @num: The number to write
 * @buf: Buffer where the number will be written
 * @bufsize: Pointer to an integer that keeps track of the current length of the
 * buffer
 *
 * Description: This function writes the digits of the hexadecimal number in
 * to the buffer, flushing it when necessary.
 */
static int write_hex(char specifier, unsigned long long num, char buf[],
		     int *bufsize)
{
	int start = *bufsize;
	char base_char = (specifier == 'x') ? 'a' : 'A';

	do {
		if (*bufsize == LENGTH)
			flush(buf, bufsize);
		buf[(*bufsize)++] = (num % 16 < 10 ? num % 16 + '0' :
						     num % 16 - 10 + base_char);
		num /= 16;
	} while (num > 0);
	reverse(buf, start, *bufsize - 1);
	return *bufsize - start;
}

/**
 * write_prefix - Writes the prefix for hexadecimal numbers
 * @specifier: The format specifier character ('x' or 'X')
 * @buf: Buffer where the prefix will be written
 * @bufsize: Pointer to an integer that keeps track of the current length of the
 * buffer
 *
 * Description: This function writes the "0x" or "0X" prefix to the buffer if
 * the FLAG_HASH is set.
 */
static int write_prefix(char specifier, char buf[], int *bufsize)
{
	if (*bufsize + 2 == LENGTH)
		flush(buf, bufsize);
	buf[(*bufsize)++] = '0';
	buf[(*bufsize)++] = specifier;
	return PREFIX_LENGTH;
}

/**
 * handle_hexadecimal - Handles the hexadecimal format specifier
 * @fs: Pointer to the FormatSpecifier structure
 * @args: Pointer to the va_list containing the arguments
 * @buf: Buffer where the formatted output will be stored
 * @bufsize: Pointer to an integer that keeps track of the current length of the
 * buffer
 *
 * Description: This function retrieves a hexadecimal number from the va_list and
 * appends it to the buffer, flushing it when necessary.
 */
int handle_hexadecimal(struct FormatSpecifier *fs, va_list *args, char *buf,
		       int *bufsize)
{
	unsigned long long num = get_unum(fs->length, args);
	int num_len = unumlen(num, 16);
	int zero_padding, space_padding;
	int bytes_written = 0;

	if (num == 0 && fs->specifier == 'p') {
		if (*bufsize + 5 == LENGTH)
			flush(buf, bufsize);
		buf[(*bufsize)++] = '(';
		buf[(*bufsize)++] = 'n';
		buf[(*bufsize)++] = 'i';
		buf[(*bufsize)++] = 'l';
		buf[(*bufsize)++] = ')';
		return 5;
	} else if (fs->specifier == 'p')
		fs->specifier = 'x';
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
			bytes_written +=
				write_prefix(fs->specifier, buf, bufsize);
		write_zero(buf, bufsize, zero_padding);
		bytes_written += write_hex(fs->specifier, num, buf, bufsize);
		write_space(buf, bufsize, space_padding);
	} else {
		write_space(buf, bufsize, space_padding);
		if ((fs->flags & FLAG_HASH) && num != 0)
			bytes_written +=
				write_prefix(fs->specifier, buf, bufsize);
		write_zero(buf, bufsize, zero_padding);
		bytes_written += write_hex(fs->specifier, num, buf, bufsize);
	}
	return bytes_written;
}
