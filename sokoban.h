#ifndef __SOKOBAN_H__
#define __SOKOBAN_H__

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

char ** init_board();

void display_board(char **board);

int position(char **board, int *goal_x, int *goal_y,int *player_x, int *player_y, int *box_x, int *box_y);

void ask_player_move(char **board,int *player_x,int *player_y, int *end);

#endif