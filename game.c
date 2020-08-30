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
        return (NULL);
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

int player(game_t *game, int line)
{
    char *input = NULL;
    my_printf("Line: ");
    if ((input = terminal_input()) == NULL)
        return (42);
    if (check_line(game, line, input) == 84)
      return (1);
    my_printf("Matches: ");
    if ((input = terminal_input()) == NULL)
        return (42);
    if (check_match(game, line, input) == 84)
      return (2);
    my_printf("Player removed %d", game->Matches);
    my_printf(" match(es) from line %d\n", game->Line);
    move(game, game->Line, game->Matches);
    print_map(game);
    return (3);
}

void ai(game_t *game)
{
    int line_ai = ai_line(game);
    int matches = ai_matches(game, line_ai);
    my_printf("AI removed %d", matches);
    my_printf(" match(es) from line %d\n", line_ai);
    move(game, line_ai, matches);
    print_map(game);
}

void play(game_t *game, int line)
{
    print_map(game);
    while (1) {
        my_printf("\nYour turn:\n");
        if (player(game, line) == 42)
            return;
        if (win(game) == 1) {
            my_printf("You lost, too bad...\n");
            return;
        }
        my_printf("\nAI's turn...\n");
        ai(game);
        if (win(game) == 1) {
            my_printf("I lost... snif... but I'll get you next time!!\n");
            return;
        }
    }
}
