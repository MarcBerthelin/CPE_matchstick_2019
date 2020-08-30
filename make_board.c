/*
** EPITECH PROJECT, 2019
** make_board.c
** File description:
** make_board.c
*/

#include "my.h"

int st_to_sp(game_t *game, int i, int j, int line)
{
    int sp_lin = line - i;
    int space = sp_lin;

    while (sp_lin != 0) {
        game->board[i][j] = ' ';
        j++;
        sp_lin--;
    }
    return (space);
}

int st_to_p(game_t *game, int i, int j)
{
    int p_lin = i * 2 - 1;
    int pipe = p_lin;

    while (p_lin != 0) {
        game->board[i][j] = '|';
        j++;
        p_lin--;
    }
    return (pipe);
}

void fill_board(game_t *game, int line)
{
    int j = 1;

    for (int i = 1; i < line + 1; i++) {
        j += st_to_sp(game, i, j, line);
        j += st_to_p(game, i, j);
        j += st_to_sp(game, i, j, line);
        j = 1;
    }
}

void make_board(game_t *game, int line)
{
    int i = 0;
    int j = 0;

    game->board = malloc(sizeof(char *) * (line + 2) + 1);
    game->board[line + 2] = NULL;
    while (i <= line + 1) {
        game->board[i] = malloc(sizeof(char) * (line * 2 + 1));
        game->board[i][line * 2 + 1] = '\0';
        i++;
    }
    for (i = 0; i <= line + 1; i++) {
        while (j <= line * 2) {
            game->board[i][j] = '*';
            j++;
        }
        j = 0;
    }
    fill_board(game, line);
}
