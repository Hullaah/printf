#ifndef MAIN_H
#define MAIN_H

#include <stdbool.h>

#define LENGTH 1024
#define FLAG_LEFT (1 << 0)
#define FLAG_PLUS (1 << 1)
#define FLAG_SPACE (1 << 2)
#define FLAG_ZERO (1 << 3)
#define FLAG_HASH (1 << 4)

/**
 *
 */
typedef enum
{
	LEN_NONE,
	LEN_HH,
	LEN_H,
	LEN_LL,
	LEN_L
} LengthModifier;

/**
 *
 */
typedef struct
{
	int flags;
	int width;
	LengthModifier length;
	char specifier;
} FormatSpecifier;

int _printf(char *format, ...);

bool _isdigit(int c);

void parse_format_specifier(const char **format, FormatSpecifier *out);

#endif
