#include <format_specifier.h>
#include <handlers.h>
#include <stdarg.h>
#include <utils.h>

/**
 * handle_pointer - Handles the pointer format specifier
 * @fs: Pointer to the FormatSpecifier structure
 * @args: Pointer to the va_list containing the arguments
 * @buf: Buffer where the formatted output will be stored
 * @bufsize: Pointer to an integer that keeps track of the current length of the
 * buffer
 *
 * Description: This function retrieves a pointer argument from the va_list and
 * formats it as a hexadecimal number, writing it to the buffer.
 */
int handle_pointer(struct FormatSpecifier *fs, va_list *args, char *buf,
		    int *bufsize)
{
	fs->flags &= ~(FLAG_ZERO | FLAG_PLUS | FLAG_SPACE);
	fs->precision = -1;
	fs->flags |= FLAG_HASH;
	fs->length = LEN_L;
	return handle_hexadecimal(fs, args, buf, bufsize);
}
