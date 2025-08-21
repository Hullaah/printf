#ifndef DISPATCHER_H
#define DISPATCHER_H

#include "format_specifier.h"
#include <stdarg.h>

format_handler_fn dispatch_handler(char c);
int dispatch(struct FormatSpecifier *fs, va_list *args, char buf[],
	     int *bufsize);

#endif
