#include <stdlib.h>
#include <stdio.h>

void* playExplosion(void *vargp){
    system("omxplayer --adev hdmi sounds/explosion.mp3");
    return NULL;
}

void playSave(){
    system("omxplayer --adev hdmi .sounds/correct.wav");
}

void playLevelComplete(){
    system("omxplayer --adev hdmi .sounds/levelComplete.wav");
}
