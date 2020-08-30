/*
** EPITECH PROJECT, 2019
** my_put_nbr_bi.c
** File description:
** binary number
*/

#include <unistd.h>
#include <stdarg.h>

int my_putchar(char);

int disp_nb_bi(unsigned int nb, int base)
{
    int mod;
    int i = 0;
    if (nb < 0) {
        i += my_putchar('-');
        if (nb == -2147483648) {
            i += my_putchar('2');
            nb = -147483648;
        }
        nb = -nb;
    }
    if (nb < base)
        i += my_putchar(nb + 48);
    if (nb >= base) {
        i += disp_nb_bi(nb / base, base);
        mod = nb % base;
        i += my_putchar(mod + 48);
        return (i);
    }
    return (i);
}

int my_put_nbr_bi(va_list *va)
{
    int i = 0;
    unsigned int nb = va_arg(*va, int);
    i = disp_nb_bi(nb, 2);
    return (i);
}
