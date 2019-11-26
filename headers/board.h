int board[10][10];
int attempts;
int foundPalces;

void initBoard(void) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            board[i][j] = 0;
        }
    }
    attempts = 50;
    foundPalces = 0;
}

int gameIsFinished() {
    if (attempts <= 0) {
        // perido el cliente
        return 1;
    } else if (foundPalces == 20) {
        // perido el server
        return 2;
    } else {
        // El juego sigue
        return 0;
    }
}

void encodeBoard(char * m) {
    char message[307] = "";
    strcat(message, "Tablero");
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            char temp[3];
            snprintf(temp, 3, ",%d", board[i][j]);
            strcat(message, temp);
        }
    }
    strcpy(m, message);
}

void decodeBoard(char * message) {
    char *ptr = strtok(message, ",");
    int i = 0;
    int j = 0;
    int cont = 0;

    if (strcmp(ptr, "Tablero") == 0) {
        ptr = strtok(NULL, ",");
        while(ptr != NULL)
        {
            if (strcmp(ptr, "0") == 0) {
                board[i][j] = 0;
            } else if (strcmp(ptr, "1") == 0) {
                board[i][j] = 1;
            } else if (strcmp(ptr, "2") == 0) {
                board[i][j] = 2;
            } else if (strcmp(ptr, "3") == 0) {
                board[i][j] = 3;
            }
            ptr = strtok(NULL, ",");
            cont++;
            i = cont / 10;
            j = cont % 10;
        }
    }
}

void printClientBoard(void) {
    clrscr();
    gotoxy(50, 10);
    color("blue");
    printf("Intentos: %d", attempts);

    gotoxy(0, 0);
    color("reset");
    for (int i = 0; i < 10; i++) {
        printf("-----------------------------------------\n");
        for (int j = 0; j < 10; j++) {
            color("reset");
            printf("| ");
            if (board[i][j] == 0 || board[i][j] == 1) {
                color("reset");
                printf(" ");
            } else if (board[i][j] == 2) {
                color("red");
                printf("+");
            } else if (board[i][j] == 3) {
                color("cyan");
                printf("-");
            }
            printf(" ");
            color("reset");
            if (j == 9) {
                printf("|\n");
            }
        }
    }
    printf("-----------------------------------------\n");
}

void printSettingBoard(int x, int y, int b) {
    clrscr();

    if (b > 0) {
        gotoxy(50, 9);
        color("blue");
        printf("Use arrow keys to move the buildings");
        gotoxy(50, 10);
        printf("Type 's' twiceto set the location");
        gotoxy(50, 12);
        color("magenta");
        printf("You need to set %d more buildings", b);
    } else {
        gotoxy(50, 9);
        color("blue");
        printf("You've set all buildings");
        gotoxy(50, 12);
        color("magenta");
        printf("Waiting for oponent");
    }

    gotoxy(0, 0);
    color("reset");
    for (int i = 0; i < 10; i++) {
        printf("-----------------------------------------\n");
        for (int j = 0; j < 10; j++) {
            color("reset");
            printf("| ");
            if (x == j && y == i && b > 0) {
                color("yellow");
                printf("-");
            } else if (x+1 == j && y == i && b > 0) {
                color("yellow");
                printf("-");
            } else if (x == j && y+1 == i && b > 0) {
                color("yellow");
                printf("-");
            } else if (x+1 == j && y+1 == i && b > 0) {
                color("yellow");
                printf("-");
            } else {
                if (board[i][j] == 0) {
                    color("reset");
                    printf(" ");
                } else if (board[i][j] == 1) {
                    color("green");
                    printf("+");
                }
            }
            printf(" ");
            color("reset");
            if (j == 9) {
                printf("|\n");
            }
        }
    }
    printf("-----------------------------------------\n");
}

int setBuilding(int y, int x) {
    if (x < 9 && y < 9) {
        if (board[x][y] == 0 && board[x+1][y] == 0 && 
        board[x][y+1] == 0 && board[x+1][y+1] == 0) {
            board[x][y] = 1;
            board[x+1][y] = 1;
            board[x][y+1] = 1;
            board[x+1][y+1] = 1;
            return 1;
        } else {
            return -1;
        }
    } else {
        return -1;
    }
}

int tryPos(int x, int y) {
    if (attempts > 0 && x < 10 && y < 10) {
        attempts--;
        if (board[x][y] == 1) {
            board[x][y] = 2;
            return 1;
        } else {
            return 0;
        }
    } else {
        return -1;
    }
}