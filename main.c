#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "screen.h"

int main(void) {
    clrscr();
    gotoxy(10, 10);
    color("cyan");
    printf("Hola\n");
    gotoxy(20, 20);
    color("yellow");
    printf("222\n");
    // system("clear");
    return 0;
}