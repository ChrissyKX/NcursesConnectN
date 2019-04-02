//
// Created by Chrissy on 2019-01-31.
//

#ifndef NCURSESCONNECTN_BOARD_H
#define NCURSESCONNECTN_BOARD_H
#include <stdlib.h>
#include <stdio.h>
typedef struct Board_struct{
    char** board;
    int brow;
    int bcol;
}Board;
Board makeboard(int row, int col);
void printboard(Board* b, char marker,int result, int col, FILE* fp);
#endif //NCURSESCONNECTN_BOARD_H
