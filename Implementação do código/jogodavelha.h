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


#endif
