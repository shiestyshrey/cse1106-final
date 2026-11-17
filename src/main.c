#include <stdio.h>
#include <unistd.h>
#include <pigpio.h>

#define LED 17

int peopleCount = 0;

void printError(){
      printf("Error: Invalid Input\n");
      }
      
void printPeopleCount(){
      printf("Current Occupancy: ");
      printf("%d\n", peopleCount);
}

int main(int argc, char* argv[]) {
      gpioInitialise();
      gpioSetMode(LED, PI_OUTPUT);
      
      int menuSelect = 0;
      int tempValue = 0;
      int MAX_OCC = 5;
      
      while (1){
      printf("\n1.Enter \n2.Leave\n3.Change Max Occpuancy\n4.View Occupancy\n5.Quit\n");
      scanf("%d", &menuSelect);
      
      if (menuSelect == 1 && peopleCount == MAX_OCC){
            printError();
            }
      else if (menuSelect == 2 && peopleCount == 0){
            printError();
            }
      else if (menuSelect == 1){
            peopleCount++;
            printPeopleCount();
            }
      else if (menuSelect == 2){
            peopleCount--;
            printPeopleCount();
            }
      else if (menuSelect == 3){
            printf("What is the new maximum occupancy?\n");
            scanf("%d", &tempValue);
            if (tempValue >= 0){
                  MAX_OCC = tempValue;
                  printPeopleCount();
                  }
            else {
                  printError();
                  printPeopleCount();
                  }
            }
      else if(menuSelect == 4){
            printPeopleCount();
            }
      else if(menuSelect == 5){
            gpioWrite(LED, 0);
            break;
            }
      else {
            printError();
            } 
      if (peopleCount == MAX_OCC){
            gpioWrite(LED, 1);
            }
      else {
            gpioWrite(LED, 0);
            }
      }      
}

