#ifndef PARSER_H
#define PARSER_H

#include "format_specifier.h"
#include <stdarg.h>

void parse_format_specifier(const char **format, struct FormatSpecifier *out);

#endif
