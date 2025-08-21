#include <dispatcher.h>
#include <handlers.h>
#include <stdlib.h>
#include <utils.h>
/**
 * dispatch_handler - Returns the appropriate handler function for a given
 * format specifier character.
 * @c: The format specifier character (e.g., 'd', 's', 'x', etc.).
 *
 * Return: A pointer to the handler function corresponding to the format
 * specifier character. If the character does not match any known format
 * specifier, returns NULL.
 */
format_handler_fn dispatch_handler(char c)
{
	int i;
	struct FormatHandlerEntry handler_table[] = {
		{ 'd', handle_decimal },     { 'i', handle_decimal },
		{ 'b', handle_binary },	     { 'o', handle_octal },
		{ 'x', handle_hexadecimal }, { 'X', handle_hexadecimal },
		{ 'u', handle_unsigned },    { 'p', handle_pointer },
		{ 's', handle_string },	     { 'c', handle_char },
		{ '%', handle_percent },     { 'S', handle_unprintable },
		{ 'r', handle_reverse },     { 'R', handle_rot13 },
	};
	for (i = 0; i < 14; i++) {
		if (c == handler_table[i].c)
			return (handler_table[i].handler);
	}
	return (NULL);
}

/**
 * dispatch - Calls the appropriate handler function based on the format
 * specifier in the provided FormatSpecifier structure.
 * @fs: Pointer to a FormatSpecifier structure containing the format specifier
 * and other related information.
 * @args: Pointer to a va_list containing the arguments to be formatted.
 * @buf: Buffer where the formatted output will be stored.
 * @bufsize: Pointer to an integer that keeps track of the current length of the
 * buffer.
 */
int dispatch(struct FormatSpecifier *fs, va_list *args, char buf[],
	     int *bufsize)
{
	int bytes_written;
	format_handler_fn handler = dispatch_handler(fs->specifier);

	if (handler)
		bytes_written = handler(fs, args, buf, bufsize);
	else {
		if (*bufsize + 2 >= LENGTH)
			flush(buf, bufsize);
		buf[(*bufsize)++] = '%';
		bytes_written = 1;
		if (fs->specifier != '\0') {
			buf[(*bufsize)++] = fs->specifier;
			bytes_written++;
		}
	}
	return bytes_written;
}
