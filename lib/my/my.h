/*
** EPITECH PROJECT, 2020
** my.h
** File description:
** my.h
*/

#include <stdarg.h>

int my_strlen(char *);
int my_putchar(char);
int my_put_nbr_dec(va_list *);
int my_dispstr(va_list *);
int itoh(va_list *);
int itox(va_list *);
int my_putstrs(va_list *);
int my_put_nbr_oct(va_list *);
int my_put_nbr_bi(va_list *);
int my_dispchar(va_list *);
int my_putstr(char const *str);
int disp_nb_bi(unsigned int, int);
int disp_nb_dec(int, int);
int disp_nb_oct(unsigned int, int);
int disp_nb_dec_u(unsigned int, int);
int my_put_nbr_dec_u(unsigned int, int);
int disp_nb_hex(int, int);
int disp_nb_hexa(int, int);
int my_printf(char *, ...);
int my_put_p(va_list *);
int disp_p(int);
int my_put_percent(va_list *);
int zeros(char);
int intsize(int);
char *get_next_line(const int);
int my_getnbr(char *);