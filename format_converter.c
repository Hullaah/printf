#include "main.h"
/**
 * print_string - prints a string followed by a new line
 * @str: string
 * Return: void (does not have a return value)
*/
int print_string(char *str, char c, char buf[BUFFER], int start)
{
	int i, j, power;
	char d;

	if (c == 's')
	{
		for (i = 0; str[i] != '\0'; i++)
		{
			/*write(1, &str[i], 1);*/
			buf[start + i] = str[i];
		}
	}
	else if (c == 'S')
	{
		for (i = 0; str[i] != '\0'; i++)
		{
			/*write(1, &str[i], 1);*/
			if ((str[i] > 0 && str[i] < 32) || str[i] >= 127)
			{
				buf[start + i] = '\\';
				buf[++start + i] = 'x';
				for (power = 0x1; str[i] / power; power *= 0x10)
				;
				while(power)
				{
					d = (str[i] / power) % 0x10;
					d += d < 0xa ? 48 : 55; 
					power /= 0x10;
					buf[++start + i] = d;
				}
			}
			else
				buf[start + i] = str[i];
		}
	}
	else if (c == 'r')
	{
		for (i = 0; str[i] != '\0'; i++);
		for (j = i - 1; j >= 0; j--)
		{
			buf[start + i - j - 1] = str[j];
		}
		
	}
	else if (c == 'R')
	{
		for(i = 0; str[i] != '\0'; i++)
		{
			if (str[i] > 64 && str[i] < 91)
			{
				d = ((str[i] - 65 + 13) % 26) + 65;
				buf[start + i] = d;
			}
			else if (str[i] > 96 && str[i] < 123)
			{
				d = ((str[i] - 97 + 13) % 26) + 97;
				buf[start + i] = d;
			}
			else
			{
				buf[start + i] = str[i];
			}
		}
	}
	
	return (start + i);
}

int print_numbers(void *i, int base, char cap, char buf[BUFFER], int start)
{
	int k, kcopy,/* count = 0, */power_10;
	char c;
	unsigned int j, jcopy, power_other;
	long l, lcopy, power_long;

	if (base == 10 && cap == 'd')
	{
		/*(void) j, (void) jcopy, (void) power_other, (void) cap, (void) l, (void) lcopy;*/
		k = *(int *) i, kcopy = k;
		for (power_10 = 1; kcopy / 10; kcopy /= 10, power_10 *= 10)
		;
		k < 0 ? /*write(1, "-", 1)*/ buf[start] = '-' : buf[start];
		k < 0 ? start++ : start;
		while (power_10)
		{
			c = k < 0 ? -((k / power_10) % 10) + '0' : ((k / power_10) % 10) + '0';
			/*write(1, &c, 1);*/
			buf[start] = c;
			power_10 /= 10;
			start++;
		}
	}
	else if (base == 2)
	{
		/*(void) j, (void) jcopy, (void) power_other, (void) cap, (void) l, (void) lcopy;*/
		j = *(unsigned int *) i, jcopy = j;
		for (power_other = 1; jcopy / 2; jcopy /= 2, power_other *= 2)
		;
		while (power_other)
		{
			c = ((j / power_other) % 2) + '0';
			/*write(1, &c, 1);*/
			buf[start] = c;
			power_other /= 2;
			start++;
		}
	}
	else if (base == 8)
	{
		/*(void) j, (void) jcopy, (void) power_other, (void) cap, (void) l, (void) lcopy;*/
		j = *(unsigned int *) i, jcopy = j;
		for (power_other = 001; jcopy / 0010; jcopy /= 0010, power_other *= 0010)
		;
		while (power_other)
		{
			c = ((j / power_other) % 0010) + '0';
			/*write(1, &c, 1);*/
			buf[start] = c;
			power_other /= 0010;
			start++;
		}
	}
	else if (base == 16 && cap == 'p')
	{
		/*(void) k, (void) kcopy, (void) power_10, (void) j, (void) jcopy, (void) power_other;*/
		l = *(long *) i, lcopy = l;
		buf[start] = '0';
		buf[++start] = 'x';
		for (power_long = 0x1; lcopy / 0x10; lcopy /= 0x10, power_long *= 0x10)
		;
		while (power_long)
		{
			c = ((l / power_long) % 0x10);
			if (c < 0xa)
				c += '0';
			else
				c += 87;
			buf[++start] = c;
			power_long /= 0x10;
		}
		c = l % 0x10;
		buf[++start] += c < 0xa ? 48 : 87;
	}
	else if (base == 16)
	{
		/*(void) k, (void) kcopy, (void) power_10, (void) l, (void) lcopy, (void) power_long;*/
		j = *(unsigned int *) i, jcopy = j;
		for (power_other = 0x1; jcopy / 0x10; jcopy /= 0x10, power_other *= 0x10)
		;
		while (power_other)
		{
			c = ((j / power_other) % 0x10);
			if ((cap > 64 && cap < 91))
			{
				if (c < 0xa)
					c += '0';
				else
					c += 55;
			}
			else
			{
				if (c < 0xa)
					c += '0';
				else
					c += 87;
			}
			/*write(1, &c, 1);*/
			buf[start] = c;
			power_other /= 0x10;
			start++;
		}
	}
	else
	{
		/*(void) k, (void) kcopy, (void) power_10, (void) cap, (void) lcopy, (void) power_long, (void) l;*/
		j = *(unsigned int *) i, jcopy = j;
		for (power_other = 1; jcopy / 10; jcopy /= 10, power_other *= 10)
		;
		while (power_other)
		{
			c = ((j / power_other) % 10) + '0';
			buf[start] = c;
			/*write(1, &c, 1);*/
			power_other /= 10;
			start++;
		}
	}
	
	return (start);
}
