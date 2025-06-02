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
bool is_valid_move(const GameBoard* board, int row, int col) {
    return (row >= 0 && row < 3 && col >= 0 && col < 3 && 
            board->grid[row][col] == EMPTY);
}

bool make_move(GameBoard* board, int row, int col, char player) {
    if (!is_valid_move(board, row, col)) return false;
    board->grid[row][col] = player;
    return true;
}

bool check_line(const char line[3], char player) {
    return (line[0] == player && line[1] == player && line[2] == player);
}

bool check_winner(const GameBoard* board, char player) {
    // Check rows and columns
    for (int i = 0; i < 3; i++) {
        // Check row
        if (check_line(board->grid[i], player)) return true;
        
        // Check column
        char column[3] = {board->grid[0][i], board->grid[1][i], board->grid[2][i]};
        if (check_line(column, player)) return true;
    }
    
    // Check diagonals
    char diag1[3] = {board->grid[0][0], board->grid[1][1], board->grid[2][2]};
    char diag2[3] = {board->grid[0][2], board->grid[1][1], board->grid[2][0]};
    
    return check_line(diag1, player) || check_line(diag2, player);
}

bool is_board_full(const GameBoard* board) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board->grid[i][j] == EMPTY) return false;
        }
    }
    return true;
}

bool game_ended(const GameBoard* board) {
    return board->game_over || is_board_full(board) || 
           check_winner(board, 'x') || check_winner(board, 'o');
}
