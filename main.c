/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** main.c
*/

#include "my.h"

void print_map(game_t *game)
{
    int i = 0;

    while (game->board[i] != NULL) {
        for (int j = 0; game->board[i][j] != '\0'; j++)
            my_printf("%c", game->board[i][j]);
        my_printf("\n");
        i++;
    }
}

int check_int(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] > '9' || str[i] < '0')
            return (84);
    return (0);
}

int main(int ac, char **av)
{
    game_t game;
    if (ac == 3 && (my_getnbr(av[1]) > 1 && my_getnbr(av[1]) < 100)) {
    	if (check_int(av[1]) == 84 || check_int(av[2]) == 84)
            return (84);
        game.maxm = my_getnbr(av[2]);
        make_board(&game, my_getnbr(av[1]));
        play(&game, my_getnbr(av[1]));
        free(game.board);
    } else
        return (84);
    return (0);
}
