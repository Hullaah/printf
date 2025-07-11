#include "format_specifier.h"
#include "handlers.h"
#include "utils.h"
#include <stdarg.h>
#include <stdlib.h>
/**
 * write_string - Writes a string to the buffer
 * @string: The string to write
 * @buf: Buffer where the string will be written
 * @len: Pointer to an integer that keeps track of the current length of the
 * buffer
 * @num_written: Number of characters to write from the string
 */
static void write_string(const char *string, char *buf, int *len,
			 int num_written)
{
	while (num_written-- > 0)
	{
		if (*len == LENGTH)
		{
			flush(buf, *len);
			*len = 0;
		}
		buf[(*len)++] = *string++;
	}
}

/**
 * handle_string - Handles the string format specifier
 * @fs: Pointer to the FormatSpecifier structure
 * @args: Pointer to the va_list containing the arguments
 * @buf: Buffer where the formatted output will be stored
 * @len: Pointer to an integer that keeps track of the current length of the
 * buffer
 *
 * Description: This function retrieves a string argument from the va_list and
 * appends it to the buffer, flushing it when necessary.
 */
void handle_string(struct FormatSpecifier *fs, va_list *args, char *buf,
		   int *len)
{
	int string_len, num_written, num_pad;
	char *string = (char *)va_arg(*args, char *);

	if (string == NULL)
		string = "(null)";
	string_len = _strlen(string);
	if (fs->precision >= 0)
		num_written = min(fs->precision, string_len);
	else
		num_written = string_len;
	num_pad = max(fs->width - num_written, 0);
	if (fs->flags & FLAG_LEFT)
	{
		write_string(string, buf, len, num_written);
		write_space(buf, len, num_pad);
	}
	else
	{
		write_space(buf, len, num_pad);
		write_string(string, buf, len, num_written);
	}
}
