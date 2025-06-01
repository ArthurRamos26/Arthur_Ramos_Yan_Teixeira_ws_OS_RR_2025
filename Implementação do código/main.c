#include "jogodavelha.h"
#include <time.h>
#include <pthread.h>
#include <unistd.h>
#include <stdio.h>   // Para printf()
#include <stdlib.h>  // Para rand(), srand()
#include <time.h>    // Para time()dcdcd
typedef struct {
    GameBoard* board;
    char symbol;
} PlayerData;

pthread_mutex_t game_mutex = PTHREAD_MUTEX_INITIALIZER;
int current_turn = 0;
const char players[2] = {'x', 'o'};

void* player_behavior(void* arg) {
    PlayerData* data = (PlayerData*)arg;
    
    while (1) {
        pthread_mutex_lock(&game_mutex);
        
        if (game_ended(data->board)) {
            pthread_mutex_unlock(&game_mutex);
            break;
        }
        
        if (current_turn == (data->symbol == 'x' ? 0 : 1)) {
            int row, col;
            do {
                row = rand() % 3;
                col = rand() % 3;
            } while (!is_valid_move(data->board, row, col) && !game_ended(data->board));
            
            if (!game_ended(data->board)) {
                make_move(data->board, row, col, data->symbol);
                printf("\n%c plays at (%d,%d)\n", data->symbol, row, col);
                display_board(data->board);
                
                if (check_winner(data->board, data->symbol)) {
                    data->board->game_over = true;
                } else if (is_board_full(data->board)) {
                    data->board->game_over = true;
                }
                
                current_turn = !current_turn;
            }
        }
        
        pthread_mutex_unlock(&game_mutex);
        usleep(100000); // Small delay to prevent busy waiting
    }
    
    return NULL;
}

int main() {
    srand(time(NULL));
    
    GameBoard* board = create_board();
    PlayerData player1 = {board, 'x'};
    PlayerData player2 = {board, 'o'};
    
    pthread_t thread1, thread2;
    pthread_create(&thread1, NULL, player_behavior, &player1);
    pthread_create(&thread2, NULL, player_behavior, &player2);
    
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    
    printf("\nFinal Board:\n");
    display_board(board);
    
    if (check_winner(board, 'x')) {
        printf("x WINS!\n");
    } else if (check_winner(board, 'o')) {
        printf("o WINS!\n");
    } else {
        printf("DRAW!\n");
    }
    
    free_board(board);
    return 0;
}