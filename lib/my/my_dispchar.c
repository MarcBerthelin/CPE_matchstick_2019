/*
** EPITECH PROJECT, 2019
** my_dispchar.c
** File description:
** write char
*/

#include <unistd.h>
#include <stdarg.h>

int my_dispchar(va_list *va)
{
    char c = va_arg(*va, int);
    write (1, &c, 1);
    return (1);
}
