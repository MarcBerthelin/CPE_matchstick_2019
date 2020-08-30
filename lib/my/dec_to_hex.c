/*
** EPITECH PROJECT, 2019
** itoX.c
** File description:
** decimal to hexa
*/

#include <stdlib.h>
#include <stdio.h>
#include "my.h"

int disp_nb_hexa(int nb, int base)
{
    int i = 0;
    if (nb < 0) {
        i += my_putchar('-');
        nb *= -1;
    }
    while (nb >= 0) {
        if (nb >= 16)
            i += disp_nb_hexa(nb / 16, 10);
        if (nb % 16 + 48 > 57)
            i += my_putchar((nb % 16) + 87);
        else
            i += my_putchar(nb % 16 + 48);
        return (i);
    }
    return (i);
}

int itoh(va_list *va)
{
    int i = 0;
    int nb = va_arg(*va, int);
    i = disp_nb_hexa(nb, 10);
    return (i);
}