#include <string.h>

void gotoxy(int x, int y) {
    printf("%c[%d;%df", 0x1B, y, x);
}

void clrscr(void) {
    system("clear");
}

void color(char* color) {
    if (strcmp(color, "red") == 0) {
        printf("\033[1;31m");
    } else if (strcmp(color, "green") == 0) {
        printf("\033[1;32m");
    } else if (strcmp(color, "yellow") == 0) {
        printf("\033[1;33m");
    } else if (strcmp(color, "blue") == 0) {
        printf("\033[1;34m");
    } else if (strcmp(color, "magenta") == 0) {
        printf("\033[1;35m");
    } else if (strcmp(color, "cyan") == 0) {
        printf("\033[1;36m");
    } else if (strcmp(color, "reset") == 0) {
        printf("\033[0m");
    }
}