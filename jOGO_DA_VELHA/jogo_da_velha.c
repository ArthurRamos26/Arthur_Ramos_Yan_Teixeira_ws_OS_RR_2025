#include "jogodavelha.h"
#include <stdio.h>
#include <stdlib.h>

#define EMPTY '-'

GameBoard* create_board() {
    GameBoard* new_board = (GameBoard*)malloc(sizeof(GameBoard));
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            new_board->grid[i][j] = EMPTY;
        }
    }
    new_board->game_over = false;
    return new_board;
}

void free_board(GameBoard* board) {
    free(board);
}

void display_board(const GameBoard* board) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%c ", board->grid[i][j]);
        }
        printf("\n");
    }
}

