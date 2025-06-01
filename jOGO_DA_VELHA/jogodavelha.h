#ifndef _JOGODAVELHA_H_
#define _JOGODAVELHA_H_

#include <stdbool.h>

typedef struct {
    char grid[3][3];
    bool game_over;
} GameBoard;

GameBoard* create_board();
void free_board(GameBoard* board);
void display_board(const GameBoard* board);


#endif