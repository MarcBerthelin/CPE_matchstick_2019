/*
** EPITECH PROJECT, 2019
** my_print_p.c
** File description:
** display the adress of any argument in hexadecimal
*/

#include "my.h"
#include <stdarg.h>

int disp_p(int var)
{
    int i = 0;
    i += my_putchar('0');
    i += my_putchar('x');
    i += disp_nb_hex(var, 10);
    return (i);
}

int my_put_p(va_list *va)
{
    int i = 0;
    i += disp_p(va_arg(*va, int));
    return (i);
}