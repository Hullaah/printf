#include "../main.h"
#include <limits.h>
#include <stdio.h>

int main(void)
{
	char c, *s = "peter,how are you doing.";
	int i, j;
	unsigned int k;

	j = _printf("Hello %s\n", s);
	_printf("%d\n", j);
	j = printf("Hello %s\n", s);
	printf("%d\n", j);

	c = '\\';
	j =_printf("%c\n", c);
	_printf("%d\n", j);
	j = printf("%c\n", c);
	printf("%d\n", j);

	s = "'m coming.";
	c = 'i';
	j = _printf("I have told you. %c%s\n", c, s);
	_printf("%d\n", j);
	j = printf("I have told you. %c%s\n", c, s);
	printf("%d\n", j);

	j = _printf("He scored 50%% in his test.\n");
	_printf("%d\n", j);
	j = printf("He scored 50%% in his test.\n");
	printf("%d\n", j);


	i = INT_MAX;
	j = _printf("%d is the int max in c.\n", i);
	_printf("%d\n", j);
	j = printf("%d is the int max in c.\n", i);
	printf("%d\n", j);

	i = INT_MIN;
	j = _printf("%d is the int min in c.\n", i);
	_printf("%d\n", j);
	j = printf("%d is the int min in c.\n", i);
	printf("%d\n", j);

	j = _printf("%b\n", 0xf);
	_printf("%d\n", j);

	j = _printf("24 in octal: %o\n", 24);
	_printf("%d\n", j);
	j = printf("24 in octal: %o\n", 24);
	printf("%d\n", j);

	k = 4000000000;
	j = _printf("int max in hex is: %x\n", k);
	_printf("%d\n", j);
	j = _printf("int max in hex is: %X\n", k);
	_printf("%d\n", j);
	j = printf("int max in hex is: %x\n", k);
	printf("%d\n", j);
	j = printf("int max in hex is: %X\n", k);
	printf("%d\n", j);

        k = 0x2F;
        _printf("%u\n", s);
        printf("%u\n", s);

        k = (unsigned int)INT_MAX + 1024;
        j = _printf("%u is int max + 24\n", k);
        _printf("%d\n", j);
        j = printf("%u is int max + 24\n", k);
        printf("%d\n", j);

         j = _printf("%S\n", "Best\n\a\21School");
         _printf("%d\n", j);

	j = _printf("The addresses of all these variables are:\n\ts: %p\n\tc: %p\n\ti: %p\n", s, &c, &i);
        _printf("%d\n", j);
	j = printf("The addresses of all these variables are:\n\ts: %p\n\tc: %p\n\ti: %p\n", s, &c, &i);
        printf("%d\n", j);

        j = _printf("%#x\n%#o\n%#d\n%#X\n", 8192, 8192, 8192, 8192);
        _printf("%d\n", j);
        j = printf("%#x\n%#o\n%#d\n%#X\n", 8192, 8192, 8192, 8192);
        printf("%d\n", j);
        _printf("%b\n", 46);

        _printf("%+d\n%+%, %+i %+x\n%+X\n", 9830, 930,292, 8191);
        printf("%i\n", 8920);

        printf("%u\n", UINT_MAX);
        printf("%x\n", UINT_MAX);
        printf("%hx\n", UINT_MAX);
        printf("%hx\n", -1234);
        printf("%hu\n", -1234);

        _printf("%r\n", "Hello, World");
        _printf("%R\n", s);



        /*_printf("\n%d\n%x\n%o\n%X\n", 8192);
        printf("\n%d\n%x\n%o\n%X\n", 8192);*/


	return (0);
}