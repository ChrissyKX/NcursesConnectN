//
// Created by Chrissy on 2019-01-31.
//
#include "board.h"
#include <stdlib.h>
#include <stdio.h>
Board makeboard(int row, int col){
    Board b;
    b.board = (char**)malloc(row*sizeof(char*));
    for (int i = 0; i<row; i++){
        b.board[i] = (char*)malloc(col*sizeof(char));
    }
    for (int i = 0; i<row; i++){
        for (int k = 0; k<col; k++){
            b.board[i][k] = '*';
        }
    }
    b.brow = row;
    b.bcol = col;
    return b;
}
void printboard(Board* b, char marker,int result, int col, FILE* fp){
    for (int i = 0; i<col; ++i){
        fputc(' ', fp);
    }

    fputc(marker, fp);
    fputc('\n', fp);
    for (int i = 0; i<b->brow; i++){
        for (int k = 0; k<b->bcol; k++){
            fputc(b->board[i][k], fp);
        }
        fputc('\n',fp);
    }
    if(result==0 ) {
        fputc('\n', fp);
    }else if(result == 1){
        fputs("Player 1 won!\n", fp);
    }else if (result == 2){
        fputs("Player 2 won!\n", fp);
    }else if (result == 3){
        fputs("Tie Game\n", fp);
    }
    fputc('\n', fp);

}