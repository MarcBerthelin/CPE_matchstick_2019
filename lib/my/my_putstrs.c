/*
** EPITECH PROJECT, 2019
** my_putstr%S.c
** File description:
** writing the octet of non printable characters
*/
#include "my.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

int my_putchar(char);

int zeros(char c)
{
    int a = c;
    int i = 0;
    if (a < 8) {
        i += my_putchar('0');
        i += my_putchar('0');
    }
    if (a > 7 && a < 64)
        i += my_putchar('0');
    return (i);
}

int my_putstrs(va_list *va)
{
    char *str = va_arg(*va, char *);
    int counter = 0;
    int i = 0;
    while (str[counter] != '\0') {
        if (str[counter] < 32 || str[counter] >= 127) {
            i += my_putchar('\\');
            i += zeros(str[counter]);
            i += disp_nb_dec(str[counter], 8);
        } else {
            i += my_putchar(str[counter]);
        }
        counter++;
    }
    return (i);
}
