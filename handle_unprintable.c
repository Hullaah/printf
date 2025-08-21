#include <format_specifier.h>
#include <handlers.h>
#include <stdarg.h>
#include <utils.h>

int handle_unprintable(struct FormatSpecifier *fs, va_list *args, char *buf,
			int *bufsize)
{
	UNUSED(fs);
	UNUSED(args);
	UNUSED(buf);
	UNUSED(bufsize);
	return 0;
}
