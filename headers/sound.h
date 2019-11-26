#include <stdlib.h>
#include <stdio.h>

void playExplosion(){
    system("omxplayer --adev hdmi .sounds/explosion.mp3");
}

void playSave(){
    system("omxplayer --adev hdmi .sounds/correct.wav");
}