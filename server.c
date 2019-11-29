#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>   
#include <time.h>
#include <pthread.h> 
#include "headers/screen.h"
#include "headers/sound.h"
#include "headers/board.h"

void setBoard(void);
void* explosionArt(void *vargp);
void* prendeleds(void *vargp);

int main(void) {
    int descriptor_socket , nuevo_socket , c;
    struct sockaddr_in server , client;
    char * mensaje;

    /*
    Creaun socket
    */
    descriptor_socket = 
    socket(AF_INET , SOCK_STREAM , 0);
    if (descriptor_socket == -1)
    {
        puts("NO SE CREA SOCKET");
        return -1;
    }

    /*
    Estructura para el SOCKET
    */
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons( 8007 );

    /*
    Ligado
    */
    if( bind(descriptor_socket,
    (struct sockaddr *)&server , sizeof(server)) < 0)
    {
        puts("FALLA AL ASOCIAR EL SERVER");
        return 1;
    }

    /*
    SERVER ESCUCHANDO
    */
    listen(descriptor_socket , 3);
    
    setBoard();

    c = sizeof(struct sockaddr_in);
    while((nuevo_socket = accept(descriptor_socket, 
        (struct sockaddr *)&client, (socklen_t*)&c))) {
        printSettingBoard(0,0,0);
        /*
        ACEPTA CONEXIONES
        */
        
        if (nuevo_socket < 0)
        {
            perror("FALLA AL CONECTAR CON CLIENTE");
            return 1;
        }


        char mensaje_cliente[2000];
        char b[307];
            
        if(recv(nuevo_socket, b, 307, 0) < 0){
            puts("Error en el mensaje cliente");
            return -1;
        }
        decodeBoard2(b);
        int i = compareBoards();
        if (i == 0) {
            write(nuevo_socket , "P" , 1);
            printf("Ganaste\n");
            return 0;
        } else {
            write(nuevo_socket , "G" , 1);
            printf("Perdiste\n");

            pthread_t hilo_leds, hilo_ascii, hilo_sound;
            pthread_create(&hilo_leds, NULL, prendeleds, NULL);
            pthread_create(&hilo_ascii, NULL, explosionArt, NULL);
            pthread_create(&hilo_sound, NULL, playExplosion, NULL);
            pthread_join(hilo_leds, NULL);
            pthread_join(hilo_ascii, NULL);
            pthread_join(hilo_sound, NULL);
            return 0;
        }
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

void* explosionArt(void* vargp) {
	clrscr();
	int c;
	FILE *file;
	file = fopen("asciiart/explosion.txt", "r");
	if (file) {
		while ((c = getc(file)) != EOF)
			putchar(c);
		fclose(file);
	}
	sleep(3);

    return NULL;
}

void* prendeleds(void* vargp) {
    digitalWrite(0, HIGH);
    digitalWrite(1, HIGH);
    digitalWrite(6, HIGH);
    delay(200);
    digitalWrite(0, LOW);
    digitalWrite(1, LOW);
    digitalWrite(6, LOW);
    delay(200);
    digitalWrite(0, HIGH);
    digitalWrite(1, HIGH);
    digitalWrite(6, HIGH);
    delay(200);
    digitalWrite(0, LOW);
    digitalWrite(1, LOW);
    digitalWrite(6, LOW);
    delay(200);
    digitalWrite(0, HIGH);
    digitalWrite(1, HIGH);
    digitalWrite(6, HIGH);
    delay(200);
    digitalWrite(0, LOW);
    digitalWrite(1, LOW);
    digitalWrite(6, LOW);
    delay(200);
    digitalWrite(0, HIGH);
    digitalWrite(1, HIGH);
    digitalWrite(6, HIGH);
    delay(200);
    digitalWrite(0, LOW);
    digitalWrite(1, LOW);
    digitalWrite(6, LOW);
    delay(200);

    return NULL;
}