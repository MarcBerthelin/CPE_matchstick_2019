/*
** EPITECH PROJECT, 2019
** play.c
** File description:
** play.c
*/

#include "my.h"

int my_atoi(char *str)
{
    int i = 0;

    for (int j = 0; str[j] != '\n'; j++) {
        i *= 10;
        i += (str[j] - 48);
    }
    return i;
}

void move(game_t *game, int line, int matches)
{
    int i = line;
    int j = my_strlen(game->board[i]);
    int sp = matches;

    while (game->board[i][j] != '|' && j > 0)
        j--;
    while (sp > 0) {
        game->board[i][j] = ' ';
        sp--;
        j--;
    }
}

int check_line(game_t *game, int line, char *input)
{
    for (int i = 0; input[i] != '\n'; i++) {
        if (input[i] > '9' || input[i] < '0') {
            disp_c_str("Error: invalid input (positive number expected)\n");
            player(game, line);
            return (84);
        }
    }
    game->Line = my_atoi(input);
    if (game->Line > line || game->Line < 0) {
        disp_c_str("Error: this line is out of range\n");
        player(game, line);
        return (84);
    }
    return (0);
}

int check_error(game_t *game, int line)
{
    if (game->Matches > game->maxm) {
        disp_c_str("Error: you cannot remove more than ");
        disp_c_nb(game->maxm);
        disp_c_str(" matches per turn\n");
        player(game, line);
        return (84);
    }
    if (game->Matches > nb_match(game)) {
        disp_c_str("Error: not enough matches on this line\n");
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
        disp_c_str("Error: you have to remove at least one match\n");
        player(game, line);
        return (84);
    }
    if (check_error(game, line) == 84)
        return (84);
    return (0);
}
