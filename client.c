#include "screen.h"
#include "sound.h"
#include <time.h>

void instructionsMiniGame(){
  gotoxy(18, 0);
  color("cyan");
  printf("THE GAME STARTS. \n");
  sleep(1);
  gotoxy(10, 2);
  printf("TYPE AS MANY CHARACTERS AS YOU CAN \n");
  sleep(2);
  gotoxy(10, 3);
  printf("DON'T TYPE ENTER. JUST TYPE THE CHARACTER SHOWN\n");
  sleep(2);
  gotoxy(24, 4);
  printf("3...\n");
  sleep(1);
  gotoxy(24, 5);
  printf("2...\n");
  sleep(1);
  gotoxy(24, 6);
  printf("1...\n");
  sleep(1);
}

int levelOne(){
  color("red");
  printf("=======================================================\n");
  gotoxy(24, 8);
  printf("LEVEL 1.\n");
  printf("=======================================================\n");
  sleep(1);
  clrscr();
  int combo = 0;
  int fail = 0;
  char c;

  time_t start, end;
  double elapsed;
  time(&start);
  do {
    time(&end);
    elapsed = difftime(end, start);
    char randomChar = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz1234567890"[random () % 26+26+10];
    color("green");
    gotoxy(24, 4);
    printf("TYPE: %c \n", randomChar);
    gotoxy(18, 5);
    printf("Please enter a character: ");
    c = getche();
    if(c == randomChar){
      printf("\nCorrect! \n");
      clrscr();
      combo++;
    }else{
      printf("\n Incorrect! \n");
      clrscr();
      fail++;
    }
    
  } while(elapsed < 3);
  gotoxy(18, 3);
  printf("Combo: %d \n", combo);
  gotoxy(18, 4);
  printf("Fails: %d \n", fail); 
  return combo;
}

int levelTwo(){
  color("red");
  printf("=======================================================\n");
  gotoxy(24, 8);
  printf("LEVEL 2.\n");
  printf("=======================================================\n");
  sleep(1);
  clrscr();
  int combo = 0;
  int fail = 0;
  char c;

  time_t start, end;
  double elapsed;
  time(&start);
  do {
    time(&end);
    elapsed = difftime(end, start);
    char randomChar = "ABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890"[random () % 26+10];
    color("green");
    gotoxy(24, 4);
    printf("TYPE: %c \n", randomChar);
    gotoxy(18, 5);
    printf("Please enter a character: ");
    c = getche();
    if(c == randomChar){
      printf("\nCorrect! \n");
      clrscr();
      combo++;
    }else{
      printf("\n Incorrect! \n");
      clrscr();
      fail++;
    }
    
  } while(elapsed < 5);
  gotoxy(18, 3);
  printf("Combo: %d \n", combo);
  gotoxy(18, 4);
  printf("Fails: %d \n", fail); 
  return combo;
}


int levelThree(){
  color("green");
  printf("=======================================================\n");
  gotoxy(24, 8);
  printf("LEVEL 3.\n");
  printf("=======================================================\n");
  sleep(1);
  clrscr();
  int combo = 0;
  int fail = 0;
  char c;

  time_t start, end;
  double elapsed;
  time(&start);
  do {
    time(&end);
    elapsed = difftime(end, start);
    char randomChar = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz9157"[random () % 26+26+4];
    color("green");
    gotoxy(24, 4);
    printf("TYPE: %c \n", randomChar);
    gotoxy(18, 5);
    printf("Please enter a character: ");
    c = getche();
    if(c == randomChar){
      printf("\nCorrect! \n");
      clrscr();
      combo++;
    }else{
      printf("\n Incorrect! \n");
      clrscr();
      fail++;
    }
    
  } while(elapsed < 10);
  gotoxy(18, 3);
  printf("Combo: %d \n", combo);
  gotoxy(18, 4);
  printf("Fails: %d \n", fail); 
  return combo;
}

int levelFour(){
  color("green");
  printf("=======================================================\n");
  gotoxy(24, 8);
  printf("LEVEL 4.\n");
  printf("HARD MODE.\n");
  printf("=======================================================\n");
  sleep(1);
  clrscr();
  int combo = 0;
  int fail = 0;
  char c;

  time_t start, end;
  double elapsed;
  time(&start);
  do {
    time(&end);
    elapsed = difftime(end, start);
    char randomChar = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz1234567890'¿+}{!$/()=?¡+-.,;:_[]"[random () % 26+26+10+22];
    color("green");
    gotoxy(24, 4);
    printf("TYPE: %c \n", randomChar);
    gotoxy(18, 5);
    printf("Please enter a character: ");
    c = getche();
    if(c == randomChar){
      printf("\nCorrect! \n");
      clrscr();
      combo++;
    }else{
      printf("\n Incorrect! \n");
      clrscr();
      fail++;
    }
    
  } while(elapsed < 20);
  gotoxy(18, 3);
  printf("Combo: %d \n", combo);
  gotoxy(18, 4);
  printf("Fails: %d \n", fail); 
  return combo;
}

int main(void) {
  clrscr();
  srand(time(NULL));
  instructionsMiniGame();
  int accomplished = 0;
  int aux = 0;

  while(accomplished == 0){
    if(levelOne() > 3){
      gotoxy(18, 6);
      printf("Challenge complete! \n");
      sleep(1);
      gotoxy(7, 7);
      printf("You took Tyler a chance to attack!\n");
      sleep(2);
      clrscr();
      accomplished = 1;
    }else{
      gotoxy(4, 6);
      printf("Oops! You didn't get it. You can try again\n");
      sleep(2);
      gotoxy(15, 7);
      printf("Get ready... \n");
      sleep(1);
      clrscr();
      accomplished = 0;
    }
  }
  playLevelComplete();
  while(accomplished == 1){
    if(levelTwo() > 7){
      gotoxy(18, 6);
      printf("Challenge complete! \n");
      sleep(1);
      gotoxy(7, 7);
      printf("You took Tyler two chances to attack!\n");
      sleep(2);
      clrscr();
      accomplished = 0;
    }else{
      gotoxy(4, 6);
      printf("Oops! You didn't get it. You can try again\n");
      sleep(2);
      gotoxy(15, 7);
      printf("Get ready... \n");
      sleep(1);
      clrscr();
      accomplished = 1;
      aux++;
      //Para que no vaya tan rapido
      if(aux>2){
        gotoxy(5, 2);
        printf("You have failed 3 times in a row!\n");
        printf("Time to wait 60 seconds.\n");
        sleep(60);
        clrscr();
        aux = 0;
      }
    }
  }
  playLevelComplete();
  color("reset");
  gotoxy(15, 3);
  printf("Wait 30 seconds for the next level\n");
  sleep(30);
  aux = 0;
  while(accomplished == 0){
    if(levelThree() > 7){
      gotoxy(18, 6);
      printf("Challenge complete! \n");
      sleep(1);
      gotoxy(7, 7);
      printf("You took Tyler three chances to attack!\n");
      sleep(2);
      clrscr();
      accomplished = 1;
    }else{
      gotoxy(4, 6);
      printf("Oops! You didn't get it. You can try again\n");
      sleep(2);
      gotoxy(15, 7);
      printf("Get ready... \n");
      sleep(1);
      clrscr();
      accomplished = 0;
      aux++;
        if(aux>2){
        printf("You have failed 3 times in a row!\n");
        printf("Time to wait 60 seconds.\n");
        sleep(60);
        clrscr();
      }
    }
  }
  playLevelComplete();
  color("reset");
  gotoxy(15, 3);
  printf("Wait 30 seconds for the next level\n");
  sleep(30);
  aux = 0;
  while(accomplished == 0){
    if(levelFour() > 20){
      gotoxy(18, 6);
      printf("Challenge complete! \n");
      sleep(1);
      gotoxy(7, 7);
      printf("You took Tyler 4 chances to attack!\n");
      sleep(2);
      clrscr();
      accomplished = 1;
    }else{
      gotoxy(4, 6);
      printf("Oops! You didn't get it. You can try again\n");
      sleep(2);
      gotoxy(15, 7);
      printf("Get ready... \n");
      sleep(1);
      clrscr();
      accomplished = 0;
      aux++;
        if(aux>0){
        printf("You have failed!\n");
        printf("Time to wait 60 seconds.\n");
        sleep(60);
        clrscr();
      }
    }
  }
  playLevelComplete();
  gotoxy(9, 3);
  color("cyan");
  printf("ヽ(•‿•)ノ \n");
  color("magenta");
  gotoxy(9, 4);
  printf("Congratulations! \n");
  gotoxy(6, 5);
  printf("You have given Tyler some troubles! \n");
  sleep(1000);

  return 0;
}