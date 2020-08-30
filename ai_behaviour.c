/*
** EPITECH PROJECT, 2019
** ai_behaviour.c
** File description:
** the ai's behaviour
*/

#include "my.h"

int count_matches(game_t *game, int line)
{
    int i = 0;
    for (int j = 0; game->board[line][j] != '\0'; j++) {
        if (game->board[line][j] == '|')
            i++;
    }
    return (i);
}

int ai_line(game_t *game)
{
    int line = 0;
    for (; game->board[line] != NULL; line++)
        for (int i = 0; game->board[line][i] != '\0'; i++)
            if (game->board[line][i] == '|')
                return (line);
    return (line);
}

int ai_matches(game_t *game, int line)
{
    int matches = count_matches(game, line) / 2 + 1;

    while (matches > game->maxm)
    	matches--;
    return (matches);
}

int win(game_t *game)
{
    for (int i = 0; game->board[i] != NULL; i++){
        for (int j = 0; game->board[i][j] != '\0'; j++) {
            if (game->board[i][j] == '|')
                return (0);
        }
    }
    return (1);
}
