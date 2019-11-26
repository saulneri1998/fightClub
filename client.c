#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <time.h>
#include "headers/screen.h"
#include "headers/sound.h"
#include "headers/board.h"

void setBoard(void);
void explosionArt(){
	clrscr();
	int c;
	FILE *file;
	file = fopen("asciiart/explosion.txt", "r");
	if (file) {
		while ((c = getc(file)) != EOF)
			putchar(c);
		fclose(file);
	}
	sleep(1);
}

int main(void) {
    int descriptor_socket;
    struct sockaddr_in server;
    char * mensaje , respuesta_server[2000];

    /*
    CREA un socket
    */
    descriptor_socket = socket(AF_INET , SOCK_STREAM , 0);
    if (descriptor_socket == -1) {
        printf("NO SE CREA EL SOCKET");
        return 1;
    }

    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_family = AF_INET;
    server.sin_port = htons( 8007 );

    /*
    Conexión con el server
    */
    if (connect(descriptor_socket , (struct sockaddr *)&server , sizeof(server)) < 0) {
        puts("ERROR de conexión con el server");
        return 1;
    }

    puts("CONNECTADO... PUM!\n");
    
    setBoard();
    char b[307];
    encodeBoard(b);

    /*
    Enviar datos al server
    */

    if (send(descriptor_socket , b, 307, 0) < 0) {
        printf("FALLA AL ENVIAR\n");
        return 1;
    }
    
    printSettingBoard(0,0,0);

    /*
    RECEPCION de DATOS del SERVER
    */
    if (recv(descriptor_socket, respuesta_server, strlen(respuesta_server), 0) < 0) {
        printf("FALLA EN LA RECEPCION");
    }
    //printf("DATOS RECIBIDOS\n");
    if (strcmp(respuesta_server, "G") == 0) {
        printf("Ganaste\n");
    } else {
        printf("Perdiste\n");
        playExplosion();
        explosionArt();
    }

    return 0;
}

void setBoard(void) {
    int buildings = 0;
    int x = 0;
    int y = 0;
    while (buildings < 5) {
        printSettingBoard(x, y, 5-buildings);
        if (getch() == '\033') { // if the first value is esc
            getch(); // skip the [
            switch(getch()) { // the real value
                case 'A':
                    // code for arrow up
                    if (y > 0)
                        y--;
                    break;
                case 'B':
                    // code for arrow down
                    if (y < 8)
                        y++;
                    break;
                case 'C':
                    // code for arrow right
                    if (x < 8)
                        x++;
                    break;
                case 'D':
                    // code for arrow left
                    if (x > 0)
                        x--;
                    break;
            }
        } else if (getch() == 's') {
            int e = setBuilding(x, y);
            if (e > 0) {
                x = 0;
                y = 0;
                buildings++;
            }
        }
    }
    printSettingBoard(x, y, 5-buildings);
    return;
}

void setPos(int* mx, int* my) {
    int x = 0;
    int y = 0;
    int set = 0;
    while (set == 0) {
        printClientBoard(x, y);
        if (getch() == '\033') { // if the first value is esc
            getch(); // skip the [
            switch(getch()) { // the real value
                case 'A':
                    // code for arrow up
                    if (y > 0)
                        y--;
                    break;
                case 'B':
                    // code for arrow down
                    if (y < 8)
                        y++;
                    break;
                case 'C':
                    // code for arrow right
                    if (x < 8)
                        x++;
                    break;
                case 'D':
                    // code for arrow left
                    if (x > 0)
                        x--;
                    break;
            }
        } else if (getch() == 's') {
            set = 1;
            *mx = x;
            *my = y;
        }
    }
    return;
}
