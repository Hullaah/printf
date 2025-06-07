#include "printf.h"
#include <stdlib.h>

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
	FormatHandlerEntry handler_table[] = {
	    {'d', handle_decimal},     {'i', handle_decimal},
	    {'b', handle_binary},      {'o', handle_octal},
	    {'x', handle_hexadecimal}, {'X', handle_hexadecimal},
	    {'u', handle_unsigned},    {'p', handle_pointer},
	    {'s', handle_string},      {'c', handle_char},
	    {'%', handle_percent},     {'S', handle_unprintable},
	    {'r', handle_reverse},     {'R', handle_rot13},
	};
	for (i = 0; i < 14; i++)
	{
		if (c == handler_table[i].c)
			return (handler_table[i].handler);
	}
	return (NULL);
}
