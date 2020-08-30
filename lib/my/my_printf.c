/*
** EPITECH PROJECT, 2019
** my_printf.c
** File description:
** my_printf
*/

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include "my.h"
#include <stdlib.h>

int flag_check(char el)
{
    char index[13] = {'s', 'c', 'i', 'u', 'o', 'b', 'd', 'x', 'X', 'S', 'p',
        '%', 0};

    for (int i = 0; index[i] != 0; i++) {
        if (index[i] == el)
            return (i);
    }
    return (84);
}

int my_printf(char *str, ...)
{
    int (*displays[12])(va_list *) = {my_dispstr, my_dispchar, my_put_nbr_dec,
        my_put_nbr_dec, my_put_nbr_oct, my_put_nbr_bi, my_put_nbr_dec, itoh,
        itox, my_putstrs, my_put_p, my_put_percent};
    va_list list;
    int i = 0;
    int c = 0;
    int index = 0;
    va_start(list, str);
    while (str[i] != '\0') {
        if (i != 0 && str[i - 1] == '%') {
            index = flag_check(str[i]);
            if (index != 84)
                c += (displays[index])(&list);
        } else if (str[i] != '%'){
            my_putchar(str[i]);
        }
        i++;
    }
    va_end(list);
    return (c);
}
