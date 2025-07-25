#include <format_specifier.h>
#include <handlers.h>
#include <stdarg.h>
#include <utils.h>

void handle_percent(struct FormatSpecifier *fs, va_list *args, char *buf,
		    int *len)
{
	UNUSED(fs);
	UNUSED(args);
	if (*len == LENGTH)
	{
		flush(buf, *len);
		*len = 0;
	}
	buf[(*len)++] = '%';
}
