#include "printf.h"

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
