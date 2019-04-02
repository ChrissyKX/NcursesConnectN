//
// Created by Chrissy on 2019-01-31.
//
#include "board.h"
#include <stdbool.h>
#include "win.h"
#include "curse.h"
bool horiwin(Board* b, char marker, int numwin){
    int count = 0;
    bool result = false;
    if(numwin>b->bcol){
        return result;
    }
    for (int i = b->brow-1; i>= 0; i--){
        count = 0;
        for (int k = 0; k < b->bcol; k++) {
            if(count == numwin){
                break;
            }else if (b->board[i][k] == marker) {
                count++;
            }else{
                count = 0;
            }
        }
        if (count == numwin){
            result = true;
            break;
        }
    }
    return result;
}

bool vertwin(Board* b, char marker, int numwin){
    int count = 0;
    bool result = false;
    if (numwin>b->brow){
        return result;
    }
    for (int i = 0; i<b->bcol; i++){

        count = 0;
        for (int k = b->brow-1; k >= 0; k--) {
            if (count == numwin){
                break;
            }else if (b->board[k][i] == marker ) {
                count++;
            }else{
                count = 0;
            }
        }
        if (count == numwin){
            result = true;
            break;
        }
    }
    return result;
}
//from downleft to upright
bool diagwin1(Board* b, char marker, int numwin){
    int count = 0;
    int c = 0;
    int r = 0;
    bool result = false;
    int min = b->brow;
    if(b->bcol<b->brow){
        min = b->bcol;
    }
    if (numwin>min){
        return result;
    }
    //this int i tracks rows
    for (int i = b->brow-1;i>=0;i--) {
        count = 0;
        c = 0;
        r = i;
        while(c<b->bcol && r>=0){
            if(count == numwin){
                break;
            }else if(b->board[r][c] == marker){
                count++;
            }else{
                count = 0;
            }
            c++;
            r--;
        }
        if (count == numwin) {
            result = true;
            break;
        }

    }
    //the downright triangle
    //this int i tracks columns.
    count = 0;
    for (int i = 1; i<b->bcol;i++){
        count = 0;
        c = i;
        r = b->brow-1;
        while (c<b->bcol && r>=0){
            if(count == numwin){
                break;
            }else if(b->board[r][c] == marker){
                count++;
            }else{
                count = 0;
            }
            c++;
            r--;
        }
        if (count == numwin){
            result = true;
            break;
        }

    }
    return result;
}

//from downright to upleft
bool diagwin2(Board* b, char marker, int numwin){
    int count = 0;
    int c;
    int r;
    bool result = false;
    int min = b->brow;
    if(b->bcol<b->brow){
        min = b->bcol;
    }
    if (numwin>min){
        return result;
    }
    //this int i tracks rows
    for (int i = b->brow-1;i>=0;i--) {
        count = 0;
        c = b->bcol-1;
        r = i;
        while(c>=0 && r>=0){
            if(count == numwin){
                break;
            }else if(b->board[r][c] == marker){
                count++;
            }else{
                count = 0;
            }
            c--;
            r--;
        }
        if (count == numwin) {
            result = true;
            break;
        }

    }
    //the downleft triangle
    //this int i tracks columns.
    count = 0;
    for (int i = b->bcol-1; i>=1;i--){
        count = 0;
        c = i;
        r = b->brow-1;
        while (c>=0 && r>=0){
            if(count == numwin){
                break;
            }else if(b->board[r][c] == marker){
                count++;
            }else{
                count = 0;
            }
            c--;
            r--;
        }
        if (count == numwin){
            result = true;
            break;
        }

    }
    return result;
}

bool full(Board* b){
    for (int i = 0; i<b->brow; i++){
        for (int k = 0; k<b->bcol; k++){
            if(b->board[i][k]=='*'){
                return false;
            }
        }
    }
    return true;
}

int giveresult(Board* b, int player, int numwin){
    char marker;
    if (player==1){
        marker = 'X';
    }else{
        marker = 'O';
    }
    if(horiwin(b, marker, numwin)||vertwin(b, marker, numwin)||diagwin1(b, marker, numwin)||diagwin2(b, marker, numwin)){
        return player;
    }else if(full(b)){

            return 3;
    }else{
        return 0;
    }
}

void showresult(CurseWin* win, int result){
    if (result == 1){
        mvwprintw(win->r, 0, 0, "Player 1 won!");
    }else if (result == 2){
        mvwprintw(win->r, 0, 0, "Player 2 won!");
    }else if (result == 3) {
        mvwprintw(win->r, 0, 0, "Tie Game");
    }
    wrefresh(win->r);
}