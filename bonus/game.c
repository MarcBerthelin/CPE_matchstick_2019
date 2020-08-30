/*
** EPITECH PROJECT, 2019
** game.c
** File description:
** game related functions
*/

#include "my.h"

char *terminal_input(void)
{
    char *buffer;
    size_t bufsiz = BUFSIZ;

    buffer = malloc(sizeof(char) * BUFSIZ);
    if (getline(&buffer, &bufsiz, stdin) == -1)
        return (0);
    return (buffer);
}

int nb_match(game_t *game)
{
    int i = game->Line;
    int j = 0;
    int c = 0;

    while (game->board[i][j] != '\0') {
        if (game->board[i][j] == '|')
            c++;
        j++;
    }
    return (c);
}

void remove_info(game_t *game)
{
    disp_c_str(" removed ");
    disp_c_nb(game->Matches);
    disp_c_str(" match(es) from line ");
    disp_c_nb(game->Line);
    my_printf("\n");
}

int player(game_t *game, int line)
{
    char *input = NULL;

    disp_c_str("Line: ");
    if ((input = terminal_input()) == 0)
        return (42);
    if (check_line(game, line, input) == 84)
        return (1);
    disp_c_str("Matches: ");
    input = terminal_input();
    if (check_match(game, line, input) == 84)
        return (2);
    if (game->player_nb == 1)
        disp_c_str(game->player_1);
    else
        disp_c_str(game->player_2);
    remove_info(game);
    move(game, game->Line, game->Matches);
    print_map(game);
    return (3);
}

void play(game_t *game, int line)
{
    print_map(game);
    while (1) {
        game->player_nb = 1;
        disp_c_str("\nYour turn ");
        disp_c_str(game->player_1);
        disp_c_str("!\n");
        if (player(game, line) == 42)
            return;
        if (win_or_lose(game, 2) == 1)
            return;
        game->player_nb = 2;
        disp_c_str("\nYour turn ");
        disp_c_str(game->player_2);
        disp_c_str("!\n");
        if (player(game, line) == 42)
            return;
        if (win_or_lose(game, 1) == 1)
            return;
    }
}
