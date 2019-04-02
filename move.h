//
// Created by Chrissy on 2019-01-31.
//

#ifndef NCURSESCONNECTN_MOVE_H
#define NCURSESCONNECTN_MOVE_H
#include <ncurses.h>
#include "curse.h"
#include "board.h"
#include "win.h"
void change(char* a);
int mkmove(CurseWin* win, int numwin, Board* b, FILE* fp);
#endif //NCURSESCONNECTN_MOVE_H
