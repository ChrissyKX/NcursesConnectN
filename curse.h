//
// Created by Chrissy on 2019-01-31.
//

#ifndef NCURSESCONNECTN_CURSE_H
#define NCURSESCONNECTN_CURSE_H
#include <ncurses.h>
typedef struct CurseWin_struct{
    WINDOW* cursewin;
    WINDOW* r;
    int crow;
    int ccol;
}CurseWin;
CurseWin makecursewin(int row, int col);
void filwindow(CurseWin* win, int row, int col);
#endif //NCURSESCONNECTN_CURSE_H
