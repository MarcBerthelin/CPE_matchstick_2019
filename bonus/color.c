/*
** EPITECH PROJECT, 2020
** color.c
** File description:
** color.c
*/

#include "my.h"

void disp_c_nb(int nb)
{
    int mod;

    if (nb < 0) {
        disp_c_char('-');
        if (nb == -2147483648) {
            disp_c_char('2');
            nb = -147483648;
        }
        nb = -nb;
    }
    if (nb < 10)
        disp_c_char(nb + 48);
    if (nb >= 10) {
        disp_c_nb(nb / 10);
        mod = nb % 10;
        disp_c_char(mod + 48);
        return;
    }
    return;
}

void disp_c_char(char c)
{
    static int i = 0;

    if (i == 0)
        my_printf("\033[1;31m");
    if (i == 1)
        my_printf("\033[1;33m");
    if (i == 2)
        my_printf("\033[1;32m");
    if (i == 3)
        my_printf("\033[1;34m");
    if (i == 4) {
        my_printf("\033[1;35m");
        i = 0;
    }
    my_printf("%c", c);
    my_printf("\033[0m");
    i++;
}

void disp_c_str(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        disp_c_char(str[i]);
}
