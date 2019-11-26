#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <time.h>
#include "headers/screen.h"
#include "headers/sound.h"
#include "headers/board.h"



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

    server.sin_addr.s_addr = inet_addr("192.168.1.139");
    server.sin_family = AF_INET;
    server.sin_port = htons( 8007 );

    /*
    Conexión con el server
    */
    if (connect(descriptor_socket , (struct sockaddr *)&server , sizeof(server)) < 0) {
        puts("ERROR de conexión con el server");
        return 1;
    }

    // puts("CONNECTADO... PUM!\n");

    /*
    Enviar datos al server
    */
    mensaje = "ClientReady";
    if (send(descriptor_socket , mensaje, strlen(mensaje) , 0) < 0) {
        printf("FALLA AL ENVIAR\n");
        return 1;
    }

    /*
    RECEPCION de DATOS del SERVER
    */
    char b[307];
    if (recv(descriptor_socket, b, 307 , 0) < 0) {
        printf("FALLA EN LA RECEPCION");
    }
    printf("DATOS RECIBIDOS\n");
    printf("%s\n", b);
    decodeBoard(b);
    printSettingBoard(0,0,0);

    // while (gameIsFinished() == 0) {
    //     //scanf("%c", &c);
    //     mensaje = "ClientReady";
    //     if (send(descriptor_socket , mensaje, strlen(mensaje) , 0) < 0) {
    //         printf("FALLA AL ENVIAR\n");
    //         return 1;
    //     }
    //     printf("DATOS ENVIADOS\n");

    //     /*
    //     RECEPCIOn de DATOS del SERVER
    //     */
    //     if (recv(descriptor_socket, respuesta_server , 2000 , 0) < 0) {
    //         printf("FALLA EN LA RECEPCION");
    //     }
    //     printf("DATOS RECIBIDOS\n");
    //     printf("%s\n", respuesta_server);
    // }

    return 0;
}