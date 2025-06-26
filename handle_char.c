#include "printf.h"

/*
 * handle_char - Handles the character format specifier
 * @fs: Pointer to the FormatSpecifier structure
 * @args: Pointer to the va_list containing the arguments
 * @buf: Buffer where the formatted output will be stored
 * @len: Pointer to an integer that keeps track of the current length of the
 * buffer
 * Description: This function retrieves a character argument from the va_list
 * and appends it to the buffer, flushing it when necessary.
 */
void handle_char(struct FormatSpecifier *fs, va_list *args, char *buf,
		 int *len)
{
	int num_pad;
	char c = (char)va_arg(*args, int);

	if (*len == LENGTH)
	{
		flush(buf, *len);
		*len = 0;
	}
	
	num_pad = max(fs->width - 1, 0);
	if (fs->flags & FLAG_LEFT){
		buf[(*len)++] = c;
		write_space(buf, len, num_pad);
	}
	else
	{
		write_space(buf, len, num_pad);
		buf[(*len)++] = c;
	}
}
