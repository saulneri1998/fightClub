#include <wiringPi.h>

void explosionLed(){
    //en main: 
    /*
    wiringPiSetup();
    pinMode(0, OUTPUT);
    digitalWrite(0, LOW);
    pinMode(1, OUTPUT);
    digitalWrite(1, LOW);
    pinMode(2, OUTPUT);
    digitalWrite(2, LOW);
    pinMode(3, OUTPUT);
    digitalWrite(3, LOW);
    */
    digitalWrite(0, HIGH);
    digitalWrite(1, HIGH);
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    delay(800);
}