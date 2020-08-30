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
            disp_c_char(game->board[i][j]);
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

char *init_name(char *str)
{
    char *dest;
    int i = 0;

    for (; str[i] != '\n'; i++);
    dest = malloc(sizeof(char) * (i + 1));
    for (int j = 0; str[j] != '\n'; j++)
        dest[j] = str[j];
    return (dest);
}

void init_game(game_t *game)
{
    disp_c_str("What's your name Player 1?\n");
    game->player_1 = init_name(terminal_input());
    disp_c_str("What's your name Player 2?\n");
    game->player_2 = init_name(terminal_input());
}

int main(int ac, char **av)
{
    game_t game;
    if (ac == 3 && (my_getnbr(av[1]) > 1 && my_getnbr(av[1]) < 100)) {
    	if (check_int(av[1]) == 84 || check_int(av[2]) == 84)
            return (84);
        init_game(&game);
        game.maxm = my_getnbr(av[2]);
        make_board(&game, my_getnbr(av[1]));
        play(&game, my_getnbr(av[1]));
        free(game.board);
    } else
        return (84);
    return (0);
}
