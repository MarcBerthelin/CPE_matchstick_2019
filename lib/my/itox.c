/*
** EPITECH PROJECT, 2019
** itox.c
** File description:
** itox.c
*/

#include <stdlib.h>
#include <stdio.h>
#include "my.h"
#include <stdarg.h>

int disp_nb_hex(int nb, int base)
{
    int i = 0;
    if (nb < 0) {
        i += my_putchar('-');
        nb *= -1;
    }
    while (nb >= 0) {
        if (nb >= 16)
            i += disp_nb_hex(nb / 16, 10);
        if (nb % 16 + 48 > 57)
            i += my_putchar((nb % 16) + 55);
        else
            i += my_putchar(nb % 16 + 48);
        return (i);
    }
    return (i);
}

int itox(va_list *va)
{
    int i = 0;
    int nb = va_arg(*va, int);
    i = disp_nb_hex(nb, 10);
    return (i);
}
