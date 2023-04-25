#include "main.h"
int print_buf(char buf[BUFFER])
{
        int i;

        for (i = 0; buf[i] != '\0'; i++)
        {
                write(1, &buf[i], 1);
        }
        return (i);
}