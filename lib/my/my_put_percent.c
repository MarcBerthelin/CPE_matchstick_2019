/*
** EPITECH PROJECT, 2019
** my_put_percent.c
** File description:
** write a %
*/

#include <stdarg.h>
#include "my.h"

int my_put_percent(va_list *va)
{
    int i = my_putchar('%');
    return (i);
}
