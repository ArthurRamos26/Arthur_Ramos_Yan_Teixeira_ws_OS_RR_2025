#ifndef _JOGODAVELHA_H_
#define _JOGODAVELHA_H_

#include <stdbool.h>

typedef struct {
    char grid[3][3];
    bool game_over;
} GameBoard;

GameBoard* create_board();  // Função para criar o jogo de tabuleiro
void free_board(GameBoard* board); //Liberar a memória apos o fim da execução do código 
void display_board(const GameBoard* board); //Essa função cria visualmente a GameBoard
bool is_valid_move(const GameBoard* board, int row, int col);//checa se o movimento é valido 
bool make_move(GameBoard* board, int row, int col, char player);//faz o movimento 
bool check_winner(const GameBoard* board, char player);//verifica o vencedor
bool is_board_full(const GameBoard* board);//verifica se deu velha
bool game_ended(const GameBoard* board);//termina o jogo 




#endif
