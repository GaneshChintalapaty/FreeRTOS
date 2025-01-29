#include<Arduino_FreeRTOS.h>

#define RED 6
#define YELLOW 7
#define BLUE 8

void setup() {
  // put your setup code here, to run once:

  xTaskCreate(redLedCrontrollerTask, "RED LED Task", 128, NULL, 1, NULL);           //Init tak to blink Red LED
  xTaskCreate(blueLedCrontrollerTask, "BLUE LED Task", 128, NULL, 1, NULL);         //Init tak to blink Blue LED
  xTaskCreate(yellowLedCrontrollerTask, "YELLOW LED Task", 128, NULL, 1, NULL);     //Init tak to blink Yellow LED

}

void redLedCrontrollerTask( void *pvParameters)
{
  pinMode(RED, OUTPUT);
  while(1)
  {
      digitalWrite(RED,digitalRead(RED)^1);     //Toggle Red LED
  }
}

void blueLedCrontrollerTask( void *pvParameters)
{
  pinMode(BLUE, OUTPUT);
  while(1)
  {
      digitalWrite(BLUE,digitalRead(BLUE)^1);     //Toggle Blue LED
  }
}

void yellowLedCrontrollerTask( void *pvParameters)
{
  pinMode(YELLOW, OUTPUT);
  while(1)
  {
      digitalWrite(YELLOW,digitalRead(YELLOW)^1);     //Toggle Yellow LED
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}