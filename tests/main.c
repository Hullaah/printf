#include "printf.h"
#include <limits.h>
#include <stdio.h>

int main(void)
{
	int std_len, my_len;

	std_len = printf("STD: |%10s|\n", "hello");
	my_len = _printf("MY : |%10s|\n", "hello");
	printf("Lengths - STD: %d, MY: %d\n\n", std_len, my_len);

	std_len = printf("STD: |%-10s|\n", "left");
	my_len = _printf("MY : |%-10s|\n", "left");
	printf("Lengths - STD: %d, MY: %d\n\n", std_len, my_len);

	std_len = printf("STD: |%.3s|\n", "truncate");
	my_len = _printf("MY : |%.3s|\n", "truncate");
	printf("Lengths - STD: %d, MY: %d\n\n", std_len, my_len);

	std_len = printf("STD: |%10.4s|\n", "width+prec");
	my_len = _printf("MY : |%10.4s|\n", "width+prec");
	printf("Lengths - STD: %d, MY: %d\n\n", std_len, my_len);

	std_len = printf("STD: |%+d|\n", 42);
	my_len = _printf("MY : |%+d|\n", 42);
	printf("Lengths - STD: %d, MY: %d\n\n", std_len, my_len);

	std_len = printf("STD: |% d|\n", 42);
	my_len = _printf("MY : |% d|\n", 42);
	printf("Lengths - STD: %d, MY: %d\n\n", std_len, my_len);

	std_len = printf("STD: |%05d|\n", 7);
	my_len = _printf("MY : |%05d|\n", 7);
	printf("Lengths - STD: %d, MY: %d\n\n", std_len, my_len);

	std_len = printf("STD: |%-5d|\n", 7);
	my_len = _printf("MY : |%-5d|\n", 7);
	printf("Lengths - STD: %d, MY: %d\n\n", std_len, my_len);

	std_len = printf("STD: |%.4d|\n", 42);
	my_len = _printf("MY : |%.4d|\n", 42);
	printf("Lengths - STD: %d, MY: %d\n\n", std_len, my_len);

	std_len = printf("STD: |%8.4d|\n", 42);
	my_len = _printf("MY : |%8.4d|\n", 42);
	printf("Lengths - STD: %d, MY: %d\n\n", std_len, my_len);

	std_len = printf("STD: |%c|\n", 'A');
	my_len = _printf("MY : |%c|\n", 'A');
	printf("Lengths - STD: %d, MY: %d\n\n", std_len, my_len);

	std_len = printf("STD: |%5c|\n", 'B');
	my_len = _printf("MY : |%5c|\n", 'B');
	printf("Lengths - STD: %d, MY: %d\n\n", std_len, my_len);

	std_len = printf("STD: |%-5c|\n", 'C');
	my_len = _printf("MY : |%-5c|\n", 'C');
	printf("Lengths - STD: %d, MY: %d\n\n", std_len, my_len);

	std_len = printf("STD: |Name: %10s | Score: %+05d | Grade: %c|\n",
			 "Alice", 93, 'A');
	my_len = _printf("MY : |Name: %10s | Score: %+05d | Grade: %c|\n",
			 "Alice", 93, 'A');
	printf("Lengths - STD: %d, MY: %d\n\n", std_len, my_len);

	signed char sch = CHAR_MAX;
	std_len = printf("STD: %%hhd -> |%hhd|\n", sch);
	my_len = _printf("MY : %%hhd -> |%hhd|\n", sch);
	printf("Lengths - STD: %d, MY: %d\n\n", std_len, my_len);

	short sh = SHRT_MIN;
	std_len = printf("STD: %%hd -> |%hd|\n", sh);
	my_len = _printf("MY : %%hd -> |%hd|\n", sh);
	printf("Lengths - STD: %d, MY: %d\n\n", std_len, my_len);

	long lg = LONG_MAX;
	std_len = printf("STD: %%ld -> |%ld|\n", lg);
	my_len = _printf("MY : %%ld -> |%ld|\n", lg);
	printf("Lengths - STD: %d, MY: %d\n\n", std_len, my_len);

	long long llg = LLONG_MIN;
	std_len = printf("STD: %%lld -> |%lld|\n", llg);
	my_len = _printf("MY : %%lld -> |%lld|\n", llg);
	printf("Lengths - STD: %d, MY: %d\n\n", std_len, my_len);

	std_len = printf("STD: |%+10.5hhd|\n", (signed char)127);
	my_len = _printf("MY : |%+10.5hhd|\n", (signed char)127);
	printf("Lengths - STD: %d, MY: %d\n\n", std_len, my_len);

	std_len = printf("STD: |%-8.4hd|\n", (short)-32);
	my_len = _printf("MY : |%-8.4hd|\n", (short)-32);
	printf("Lengths - STD: %d, MY: %d\n\n", std_len, my_len);

	std_len = printf("STD: |% 12.6ld|\n", (long)123456);
	my_len = _printf("MY : |% 12.6ld|\n", (long)123456);
	printf("Lengths - STD: %d, MY: %d\n\n", std_len, my_len);

	std_len = printf("STD: |%0+15.7lld|\n", (long long)-9999999);
	my_len = _printf("MY : |%0+15.7lld|\n", (long long)-9999999);
	printf("Lengths - STD: %d, MY: %d\n\n", std_len, my_len);

	std_len = printf("STD: |%hhi|\n", (signed char)-128);
	my_len = _printf("MY : |%hhi|\n", (signed char)-128);
	printf("Lengths - STD: %d, MY: %d\n\n", std_len, my_len);

	std_len = printf("STD: |%c|\n", 'Z');
	my_len = _printf("MY : |%c|\n", 'Z');
	printf("Lengths - STD: %d, MY: %d\n\n", std_len, my_len);

	std_len = printf("STD: |% u|\n", 42);
	my_len = _printf("MY : |% u|\n", 42);
	printf("Lengths - STD: %d, MY: %d\n\n", std_len, my_len);

	std_len = printf("STD: |%05u|\n", 7);
	my_len = _printf("MY : |%05u|\n", 7);
	printf("Lengths - STD: %d, MY: %d\n\n", std_len, my_len);

	std_len = printf("STD: |%-5u|\n", 7);
	my_len = _printf("MY : |%-5u|\n", 7);
	printf("Lengths - STD: %d, MY: %d\n\n", std_len, my_len);

	std_len = printf("STD: |%.4u|\n", 42);
	my_len = _printf("MY : |%.4u|\n", 42);
	printf("Lengths - STD: %d, MY: %d\n\n", std_len, my_len);

	std_len = printf("STD: |%8.4u|\n", 42);
	my_len = _printf("MY : |%8.4u|\n", 42);
	printf("Lengths - STD: %d, MY: %d\n\n", std_len, my_len);

	std_len = printf("STD: |Name: %10s | Score: %+05u | Grade: %c|\n",
			 "Alice", 93, 'A');
	my_len = _printf("MY : |Name: %10s | Score: %+05u | Grade: %c|\n",
			 "Alice", 93, 'A');
	printf("Lengths - STD: %d, MY: %d\n\n", std_len, my_len);

	unsigned short ush = USHRT_MAX;
	std_len = printf("STD: %%hu -> |%hu|\n", ush);
	my_len = _printf("MY : %%hu -> |%hu|\n", ush);
	printf("Lengths - STD: %d, MY: %d\n\n", std_len, my_len);

	unsigned long ulg = ULONG_MAX;
	std_len = printf("STD: %%lu -> |%lu|\n", ulg);
	my_len = _printf("MY : %%lu -> |%lu|\n", ulg);
	printf("Lengths - STD: %d, MY: %d\n\n", std_len, my_len);

	long long ullg = LLONG_MIN;
	std_len = printf("STD: %%llu -> |%llu|\n", ullg);
	my_len = _printf("MY : %%llu -> |%llu|\n", ullg);
	printf("Lengths - STD: %d, MY: %d\n\n", std_len, my_len);

	std_len = printf("STD: |%+10.5hhu|\n", (unsigned char)-127);
	my_len = _printf("MY : |%+10.5hhu|\n", (unsigned char)-127);
	printf("Lengths - STD: %d, MY: %d\n\n", std_len, my_len);

	std_len = printf("STD: |%-8.4hu|\n", (unsigned short)-32);
	my_len = _printf("MY : |%-8.4hu|\n", (unsigned short)-32);
	printf("Lengths - STD: %d, MY: %d\n\n", std_len, my_len);

	std_len = printf("STD: |% 12.6lu|\n", (long)123456);
	my_len = _printf("MY : |% 12.6lu|\n", (long)123456);
	printf("Lengths - STD: %d, MY: %d\n\n", std_len, my_len);

	std_len = printf("STD: |%025.7llu|\n", (unsigned long long)-9999999);
	my_len = _printf("MY : |%025.7llu|\n", (unsigned long long)-9999999);
	printf("Lengths - STD: %d, MY: %d\n\n", std_len, my_len);

	std_len = printf("STD: |%hhu|\n", (unsigned char)255);
	my_len = _printf("MY : |%hhu|\n", (unsigned char)255);
	printf("Lengths - STD: %d, MY: %d\n\n", std_len, my_len);

	unsigned int uval = 0xBEEF;

	/* Basic lowercase and uppercase hex */
	std_len = printf("STD: |%x|\n", uval);
	my_len = _printf("MY : |%x|\n", uval);
	printf("Lengths - STD: %d, MY: %d\n\n", std_len, my_len);

	std_len = printf("STD: |%X|\n", uval);
	my_len = _printf("MY : |%X|\n", uval);
	printf("Lengths - STD: %d, MY: %d\n\n", std_len, my_len);

	/* Width and left-justify */
	std_len = printf("STD: |%10x|\n", uval);
	my_len = _printf("MY : |%10x|\n", uval);
	printf("Lengths - STD: %d, MY: %d\n\n", std_len, my_len);

	std_len = printf("STD: |%-10X|\n", uval);
	my_len = _printf("MY : |%-10X|\n", uval);
	printf("Lengths - STD: %d, MY: %d\n\n", std_len, my_len);

	/* Zero padding */
	std_len = printf("STD: |%08x|\n", uval);
	my_len = _printf("MY : |%08x|\n", uval);
	printf("Lengths - STD: %d, MY: %d\n\n", std_len, my_len);

	/* Alternate form (#) */
	std_len = printf("STD: |%#x|\n", uval);
	my_len = _printf("MY : |%#x|\n", uval);
	printf("Lengths - STD: %d, MY: %d\n\n", std_len, my_len);

	std_len = printf("STD: |%#X|\n", uval);
	my_len = _printf("MY : |%#X|\n", uval);
	printf("Lengths - STD: %d, MY: %d\n\n", std_len, my_len);

	/* Precision */
	std_len = printf("STD: |%.6x|\n", uval);
	my_len = _printf("MY : |%.6x|\n", uval);
	printf("Lengths - STD: %d, MY: %d\n\n", std_len, my_len);

	std_len = printf("STD: |%.2X|\n", uval);
	my_len = _printf("MY : |%.2X|\n", uval);
	printf("Lengths - STD: %d, MY: %d\n\n", std_len, my_len);

	/* Width + precision */
	std_len = printf("STD: |%12.6x|\n", uval);
	my_len = _printf("MY : |%12.6x|\n", uval);
	printf("Lengths - STD: %d, MY: %d\n\n", std_len, my_len);


	/* Length modifiers */
	unsigned char uch = 0xAB;
	std_len = printf("STD: %%hhx -> |%hhx|\n", uch);
	my_len = _printf("MY : %%hhx -> |%hhx|\n", uch);
	printf("Lengths - STD: %d, MY: %d\n\n", std_len, my_len);

	ush = 0xBEEF;
	std_len = printf("STD: %%hx -> |%hx|\n", ush);
	my_len = _printf("MY : %%hx -> |%hx|\n", ush);
	printf("Lengths - STD: %d, MY: %d\n\n", std_len, my_len);

	ulg = 0xDEADBEEF;
	std_len = printf("STD: %%lx -> |%lx|\n", ulg);
	my_len = _printf("MY : %%lx -> |%lx|\n", ulg);
	printf("Lengths - STD: %d, MY: %d\n\n", std_len, my_len);

	ullg = 0x123456789ABCDEFULL;
	std_len = printf("STD: %%llX -> |%llX|\n", ullg);
	my_len = _printf("MY : %%llX -> |%llX|\n", ullg);
	printf("Lengths - STD: %d, MY: %d\n\n", std_len, my_len);

	/* Mixed formatting */
	std_len = printf("STD: |Value: %#08x | Upper: %-12X|\n", 48879, 48879);
	my_len = _printf("MY : |Value: %#08x | Upper: %-12X|\n", 48879, 48879);
	printf("Lengths - STD: %d, MY: %d\n\n", std_len, my_len);

	int a = 42;
	int *ptr = &a;
	void *null_ptr = NULL;

	/* Basic pointer */
	std_len = printf("STD: %%p -> |%p|\n", ptr);
	my_len = _printf("MY : %%p -> |%p|\n", ptr);
	printf("Lengths - STD: %d, MY: %d\n\n", std_len, my_len);

	/* NULL pointer */
	std_len = printf("STD: %%p -> |%p|\n", null_ptr);
	my_len = _printf("MY : %%p -> |%p|\n", null_ptr);
	printf("Lengths - STD: %d, MY: %d\n\n", std_len, my_len);

	/* Width */
	std_len = printf("STD: |%20p|\n", ptr);
	my_len = _printf("MY : |%20p|\n", ptr);
	printf("Lengths - STD: %d, MY: %d\n\n", std_len, my_len);

	/* Left align */
	std_len = printf("STD: |%-20p|\n", ptr);
	my_len = _printf("MY : |%-20p|\n", ptr);
	printf("Lengths - STD: %d, MY: %d\n\n", std_len, my_len);

	unsigned int u = 48879; // 0xBEEF
	unsigned int zero = 0;

	/* Basic octal */
	std_len = printf("STD: %%o -> |%o|\n", u);
	my_len = _printf("MY : %%o -> |%o|\n", u);
	printf("Lengths - STD: %d, MY: %d\n\n", std_len, my_len);

	/* Alternate form (#) */
	std_len = printf("STD: %%#o -> |%#o|\n", u);
	my_len = _printf("MY : %%#o -> |%#o|\n", u);
	printf("Lengths - STD: %d, MY: %d\n\n", std_len, my_len);

	/* Width */
	std_len = printf("STD: |%8o|\n", u);
	my_len = _printf("MY : |%8o|\n", u);
	printf("Lengths - STD: %d, MY: %d\n\n", std_len, my_len);

	/* Zero-padding */
	std_len = printf("STD: |%08o|\n", u);
	my_len = _printf("MY : |%08o|\n", u);
	printf("Lengths - STD: %d, MY: %d\n\n", std_len, my_len);

	/* Precision */
	std_len = printf("STD: |%.6o|\n", u);
	my_len = _printf("MY : |%.6o|\n", u);
	printf("Lengths - STD: %d, MY: %d\n\n", std_len, my_len);

	/* Zero value with # and precision = 0 */
	std_len = printf("STD: |%#.0o|\n", zero);
	my_len = _printf("MY : |%#.0o|\n", zero);
	printf("Lengths - STD: %d, MY: %d\n\n", std_len, my_len);

	return 0;
}
