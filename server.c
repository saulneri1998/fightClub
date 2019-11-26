#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>   
#include "headers/screen.h"
#include "headers/sound.h"
#include "headers/board.h"

void setBoard(void);

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
    // puts("LISTO!");

    /*
    SERVER ESCUCHANDO
    */
    listen(descriptor_socket , 3);
    
    setBoard();

    while((nuevo_socket = accept(descriptor_socket, 
        (struct sockaddr *)&client, (socklen_t*)&c))) {
        /*
        ACEPTA CONEXIONES
        */
        puts("ESPERANDO nueva CONEXION: ");
        c = sizeof(struct sockaddr_in);
        
        if (nuevo_socket < 0)
        {
            perror("FALLA AL CONECTAR CON CLIENTE");
            return 1;
        }

        puts("CONEXION ACEPTADA");
        char mensaje_cliente[2000];
        if(recv(nuevo_socket, mensaje_cliente, 2000, 0) < 0){
            puts("Error en el mensaje cliente");
            return -1;
        }
        puts(mensaje_cliente);

        /*
        RESPUESTA AL CLIENTE
        */
        mensaje = "HOLA....desde el server PUM...\n";
        write(nuevo_socket , mensaje , strlen(mensaje));
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
