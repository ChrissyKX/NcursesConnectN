//
// Created by Chrissy on 2019-01-31.
//
#include <ncurses.h>
#include "curse.h"
#include "move.h"
#include "board.h"
#include "win.h"
void change(char* a){
    *a = *a == 'X'? 'O': 'X';
}
int mkmove(CurseWin* win, int numwin, Board* b, FILE* fp) {
    char marker = 'X';
    char c ;
    int result = 0;
    while (result == 0) {
        c = wgetch(win->cursewin);
        if (c == 'a' || c == 'j') {
            if (win->ccol > 0) {
                waddch(win->cursewin, ' ');
                win->ccol--;
                mvwaddch(win->cursewin, win->crow, win->ccol, marker);
                wmove(win->cursewin, win->crow, win->ccol);
            } else {
                waddch(win->cursewin, ' ');
                win->ccol = getmaxx(win->cursewin)-1;
                mvwaddch(win->cursewin, win->crow, win->ccol, marker);
                wmove(win->cursewin, win->crow, win->ccol);
            }
            printboard(b, marker, result, win->ccol, fp);
        } else if (c == 's' || c == 'k') {
            if (win->ccol < getmaxx(win->cursewin) - 1) {
                waddch(win->cursewin, ' ');
                win->ccol++;
                mvwaddch(win->cursewin, win->crow, win->ccol, marker);
                wmove(win->cursewin, win->crow, win->ccol);
            } else {
                waddch(win->cursewin, ' ');
                win->ccol = 0;
                mvwaddch(win->cursewin, win->crow, win->ccol, marker);
                wmove(win->cursewin, win->crow, win->ccol);
            }
            printboard(b, marker,result, win->ccol, fp);
        } else if (c == ' ' || c == '\n') {
            for (int i = getmaxy(win->cursewin) - 1; i > 0; i--) {
                if (b->board[i - 1][win->ccol] == '*') {
                    mvwaddch(win->cursewin, i, win->ccol, marker);
                    b->board[i - 1][win->ccol] = marker;
                    wmove(win->cursewin, 0, win->ccol);
                    if (marker == 'X') {
                        result = giveresult(b, 1, numwin);
                    } else {
                        result = giveresult(b, 2, numwin);
                    }
                    if (result == 0) {
                        change(&marker);
                    }
                    mvwaddch(win->cursewin, 0, win->ccol, marker);
                    wmove(win->cursewin, 0, win->ccol);
                    break;
                }
            }
            printboard(b, marker, result, win->ccol, fp);
        }else{
            printboard(b, marker, result, win->ccol, fp);
        }

        wrefresh(win->cursewin);

    }
    return result;
}