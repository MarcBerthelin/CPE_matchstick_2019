/*
** EPITECH PROJECT, 2019
** struct.h
** File description:
** struct.h
*/

typedef struct game
{
    char **board;
    int Line;
    int Matches;
    int maxm;
    char *player_1;
    char *player_2;
    int player_nb;
} game_t;
