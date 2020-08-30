/*
** EPITECH PROJECT, 2019
** my_putstr.c
** File description:
** t1
*/

#include <stdarg.h>

int my_putchar(char);

int my_dispstr(va_list *va)
{
    char *str = va_arg(*va, char *);
    int counter = 0;
    while (str[counter] != '\0')
    {
        my_putchar(str[counter]);
        counter++;
    }
    return (counter);
}
