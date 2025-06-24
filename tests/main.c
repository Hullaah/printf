#include <stdio.h>
#include "../printf.h"

int main(void)
{
	printf("%5.s\n", "Hello, World");
	_printf("%5.s\n", "Hello, World");
	return (0);
}
