##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## t1
##

SRC	=	my_compute_power_rec.c	\
		my_putstr.c	\
		my_strcpy.c	\
		my_strncmp.c	\
		my_compute_square_root.c	\
		my_revstr.c	\
		my_str_isalpha.c	\
		my_strncpy.c	\
		my_find_prime_sup.c	\
		my_showmem.c	\
		my_str_islower.c	\
		my_str_printable.c	\
		my_getnbr.c	\
		my_showstr.c	\
		my_str_isnum.c	\
		my_strstr.c	\
		my_isneg.c	\
		my_sort_int_array.c	\
		my_str_isupper.c	\
		my_strupcase.c	\
		my_is_prime.c	\
		my_strcapitalize.c	\
		my_strlen.c	\
		my_swap.c	\
		my_putchar.c	\
		my_strcat.c	\
		my_strlowcase.c	\
		my_put_nbr.c	\
		my_strcmp.c	\
		my_strncat.c	\
		my_put_nbr_dec.c	\
		dec_to_hex.c	\
		itox.c	\
		intsize.c	\
		my_putstrs.c	\
		my_put_nbr_oct.c	\
		my_dispchar.c	\
		my_dispstr.c	\
		my_put_nbr_bi.c	\
		my_put_nbr_dec_u.c	\
		my_printf.c	\
		my_print_p.c	\
		my_put_percent.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

MY_H	=	my.h
all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc libmy.a *.o

clean:	clean
	rm -f $(OBJ)
	rm -f $(NAME)

fclean: clean
	rm -f $(NAME)

re:	fclean all
