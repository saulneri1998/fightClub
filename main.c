#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "headers/screen.h"
#include "headers/sound.h"
#include "headers/board.h"

int main(void) {

    int buildings = 0;
    int x = 0;
    int y = 0;
    while (buildings < 5) {
        if (getch() == '\033') { // if the first value is esc
            getch(); // skip the [
            switch(getch()) { // the real value
                case 'A':
                    // code for arrow up
                    printf("up\n");
                    if (y > 0)
                        y--;
                    break;
                case 'B':
                    // code for arrow down
                    printf("down\n");
                    if (y < 9)
                        y++;
                    break;
                case 'C':
                    // code for arrow right
                    printf("right\n");
                    if (x < 9)
                        x++;
                    break;
                case 'D':
                    // code for arrow left
                    printf("left\n");
                    if (x > 0)
                        x--;
                    break;
            }
            printSettingBoard(x, y);
        } else if (getch() == 's') {
            int e = setBuilding(x, y);
            buildings++;
        }
    }
}

    // int error = 0;
    // initBoard();
    // printBoard();
    // error = setBuilding(4, 6);
    // error = setBuilding(1, 1);
    // error = setBuilding(8, 8);
    // error = setBuilding(5, 2);
    // error = setBuilding(7, 4);
    // printBoard();


    // playExplosion();
    // sleep(1);
