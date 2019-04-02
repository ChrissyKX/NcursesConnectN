//
// Created by Chrissy on 2019-01-31.
//

#ifndef NCURSESCONNECTN_WIN_H
#define NCURSESCONNECTN_WIN_H
#include "board.h"
#include <stdbool.h>
#include "curse.h"
bool horiwin(Board* b, char marker, int numwin);
bool vertwin(Board* b, char marker, int numwin);
bool diagwin1(Board* b, char marker, int numwin);
bool diagwin2(Board* b, char marker, int numwin);
bool full(Board* b);
int giveresult(Board* b, int player, int numwin);
void showresult(CurseWin* win,int result);
#endif //NCURSESCONNECTN_WIN_H
