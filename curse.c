//
// Created by Chrissy on 2019-01-31.
//
#include "curse.h"
CurseWin makecursewin(int row, int col){
    CurseWin cw;
    cw.cursewin = newwin(row+1,col,0,0);
    cw.r = newwin(1, 13, row+1,0);
    cw.crow = 0;
    cw.ccol = 0;
    return cw;
}
void filwindow(CurseWin* win, int row, int col){
    for (int i = 1;i<row+1; i++){
        for (int k = 0; k<col; k++){
            mvwaddch(win->cursewin, i, k, '*');
        }
    }
    mvwaddch(win->cursewin,0,0,'X');
    wmove(win->cursewin, 0, 0);
}
