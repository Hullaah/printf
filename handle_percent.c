#include <format_specifier.h>
#include <handlers.h>
#include <stdarg.h>
#include <utils.h>

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
