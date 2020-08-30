/*
** EPITECH PROJECT, 2020
** win.c
** File description:
** win.c
*/

#include "my.h"

int check_match2(game_t *game, int line, char *input)
{
    for (int i = 0; input[i] != '\n'; i++)
        if (input[i] > '9' || input[i] < '0') {
            disp_c_str("Error: invalid input (positive number expected)\n");
            player(game, line);
            return (84);
        }
    game->Matches = my_atoi(input);
    if (game->Matches < 0) {
        disp_c_str("Error: invalid input (positive number expected)\n");
        player(game, line);
        return (84);
    }
    return (0);
}

int win_or_lose(game_t *game, int player)
{
    if (win(game) == 1 && player == 2) {
        disp_c_str("You lost ");
        disp_c_str(game->player_2);
        disp_c_str(", you suck!!!\n");
        return (1);
    }
    if (win(game) == 1 && player == 1) {
        disp_c_str("You lost ");
        disp_c_str(game->player_1);
        disp_c_str(", you suck!!!\n");
        return (1);
    }
    return (0);
}

int win(game_t *game)
{
    int p_c = 0;

    for (int i = 0; game->board[i] != NULL; i++){
        for (int j = 0; game->board[i][j] != '\0'; j++) {
            if (game->board[i][j] == '|')
                p_c++;
            if (p_c >= 2)
                return (0);
        }
    }
    return (1);
}
