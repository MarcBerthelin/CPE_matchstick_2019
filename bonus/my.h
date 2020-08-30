/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** my.h for this project
*/

#include "struct.h"
#include "../lib/my/my.h"
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#include <stdio.h>
#include <time.h>

void make_board(game_t *, int);
void fill_board(game_t *, int);
int st_to_p(game_t *, int, int);
int st_to_sp(game_t *, int, int, int);
void print_map(game_t *);
void play(game_t *, int);
char *terminal_input(void);
int nb_match(game_t *);
int player(game_t *, int);
void play(game_t *game, int line);
int my_atoi(char *);
void move(game_t *, int, int);
int check_line(game_t *, int, char *);
int check_error(game_t *, int);
int check_match(game_t *, int, char *);
int in_board(int, game_t *);
int win(game_t *);
void disp_c_str(char *);
void disp_c_char(char);
void disp_c_nb(int);
int win_or_lose(game_t *game, int player);
int check_match2(game_t *game, int line, char *input);
