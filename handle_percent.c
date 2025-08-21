#include <format_specifier.h>
#include <handlers.h>
#include <stdarg.h>
#include <utils.h>

/**
 * handle_percent - Handles the percent format specifier
 * @fs: Pointer to the FormatSpecifier structure
 * @args: Pointer to the va_list containing the arguments
 * @buf: Buffer where the formatted output will be stored
 * @bufsize: Pointer to an integer that keeps track of the current length of the
 * buffer
 *
 * Description: This function handles the percent format specifier by writing a
 * single percent character to the buffer.
 */
int handle_percent(struct FormatSpecifier *fs, va_list *args, char *buf,
		   int *bufsize)
{
	UNUSED(fs);
	UNUSED(args);
	if (*bufsize == LENGTH)
		flush(buf, bufsize);
	buf[(*bufsize)++] = '%';
	return 1;
}
