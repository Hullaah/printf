#include <format_specifier.h>
#include <handlers.h>
#include <stdarg.h>
#include <stdio.h>
#include <utils.h>

/*
 * handle_char - Handles the character format specifier
 * @fs: Pointer to the FormatSpecifier structure
 * @args: Pointer to the va_list containing the arguments
 * @buf: Buffer where the formatted output will be stored
 * @bufsize: Pointer to an integer that keeps track of the current length of the
 * buffer
 * Description: This function retrieves a character argument from the va_list
 * and appends it to the buffer, flushing it when necessary.
 */
int handle_char(struct FormatSpecifier *fs, va_list *args, char *buf, int *bufsize)
{
	int num_pad;
	char c = (char)va_arg(*args, int);

	if (*bufsize == LENGTH)
		flush(buf, bufsize);

	num_pad = max(fs->width - 1, 0);
	if (fs->flags & FLAG_LEFT)
	{
		buf[(*bufsize)++] = c;
		write_space(buf, bufsize, num_pad);
	}
	else
	{
		write_space(buf, bufsize, num_pad);
		buf[(*bufsize)++] = c;
	}
	return 1 + num_pad;
}
