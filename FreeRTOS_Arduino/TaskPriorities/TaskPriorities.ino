#include<Arduino_FreeRTOS.h>

#define RED 6
#define YELLOW 7
#define BLUE 8

void setup() {
  // put your setup code here, to run once:

  /*
    In the following setup only the highest proirity task will run. Therefore only BLUE and YELLOW LED task will be shared and RED LED will not toggle.
  */

  xTaskCreate(redLedCrontrollerTask, "RED LED Task", 128, NULL, 1, NULL); //Init Red LED task
  xTaskCreate(blueLedCrontrollerTask, "BLUE LED Task", 128, NULL, 2, NULL); //Init Blue LED task
  xTaskCreate(yellowLedCrontrollerTask, "YELLOW LED Task", 128, NULL, 2, NULL); //Init Yellow LED task

}

void redLedCrontrollerTask( void *pvParameters)
{
  pinMode(RED, OUTPUT);
  while(1)
  {
    digitalWrite(RED,digitalRead(RED)^1);
  }
}

void blueLedCrontrollerTask( void *pvParameters)
{
  pinMode(BLUE, OUTPUT);
  while(1)
  {
    digitalWrite(BLUE,digitalRead(BLUE)^1);
  }
}

void yellowLedCrontrollerTask( void *pvParameters)
{
  pinMode(YELLOW, OUTPUT);
  while(1)
  {
    digitalWrite(YELLOW,digitalRead(YELLOW)^1);
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}