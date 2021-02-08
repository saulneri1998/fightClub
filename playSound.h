#include <stdlib.h>
#include <stdio.h>

void playExplosion(){
    system("omxplayer --adev hdmi /home/pi/Desktop/PlaySOund/explosion.mp3");
}

void playSave(){
    system("omxplayer --adev hdmi /home/pi/Desktop/PlaySOund/correct.wav");
}