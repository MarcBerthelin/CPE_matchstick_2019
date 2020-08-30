/*
** EPITECH PROJECT, 2020
** check_match.c
** File description:
** check_match.c
*/

#include "my.h"

int check_match2(game_t *game, int line, char *input)
{
    for (int i = 0; input[i] != '\n'; i++)
        if (input[i] > '9' || input[i] < '0') {
            my_printf("Error: invalid input (positive number expected)\n");
            player(game, line);
            return (84);
        }
    game->Matches = my_atoi(input);
    if (game->Matches < 0) {
        my_printf("Error: invalid input (positive number expected)\n");
        player(game, line);
        return (84);
    }
    return (0);
}

int check_match(game_t *game, int line, char *input)
{
    if (check_match2(game, line, input) == 84)
        return (84);
    if (game->Matches == 0) {
        my_printf("Error: you have to remove at least one match\n");
        player(game, line);
        return (84);
    }
    if (check_error(game, line) == 84)
        return (84);
    return (0);
}
