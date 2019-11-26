#include <string.h>
#include <termios.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <term.h>
 
static struct termios old, new;
 
/* Initialize new terminal i/o settings */
void initTermios(int echo) 
{
  tcgetattr(0, &old); //grab old terminal i/o settings
  new = old; //make new settings same as old settings
  new.c_lflag &= ~ICANON; //disable buffered i/o
  new.c_lflag &= echo ? ECHO : ~ECHO; //set echo mode
  tcsetattr(0, TCSANOW, &new); //apply terminal io settings
}
 
/* Restore old terminal i/o settings */
void resetTermios(void) 
{
  tcsetattr(0, TCSANOW, &old);
}
 
/* Read 1 character - echo defines echo mode */
char getch_(int echo) 
{
  char ch;
  initTermios(echo);
  ch = getchar();
  resetTermios();
  return ch;
}
 
/* 
Read 1 character without echo 
getch() function definition.
*/
char getch(void) 
{
  return getch_(0);
}
 
/* 
Read 1 character with echo 
getche() function definition.
*/
char getche(void) 
{
  return getch_(1);
}
 
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