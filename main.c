#include <ncurses.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include "curse.h"
#include "move.h"
#include "win.h"
#include "board.h"

int main(int argc, char** argv) {
    initscr();
    noecho();
    cbreak();
    int row;
    int col;
    int numwin;
    char* file = NULL;
    sscanf(argv[1],"%d",&row);
    sscanf(argv[2],"%d",&col);
    sscanf(argv[3],"%d",&numwin);
    FILE* fp = fopen(argv[4], "w");
    Board b = makeboard(row,col);
    CurseWin cw  = makecursewin(row,col);
    filwindow(&cw,row,col);
    //let notwin, p1win, p2win, numwin>min(col,row) tie be 0, 1, 2, 3, 4;
    int result = 0;
    //let p1, p2 be 1 and 2;let the initial player be p1;
    printboard(&b, 'X',result, cw.ccol, fp);
    result = mkmove(&cw,numwin,&b, fp);
    showresult(&cw, result);
    fclose(fp);
    endwin();
    for (int i = 0; i<row; i++){
        free(b.board[i]);
    }
    free(b.board);
    return 0;

}