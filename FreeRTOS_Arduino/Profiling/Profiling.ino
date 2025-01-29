#include<Arduino_FreeRTOS.h>

#define RED 6
#define YELLOW 7
#define BLUE 8

typedef int TaskProfiler;

//TaskProfilers are used to verify if a particular task is init or not
TaskProfiler RedLEDProfiler;
TaskProfiler YellowLEDProfiler;
TaskProfiler BlueLEDProfiler;

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);   //To use serial monitor

  xTaskCreate(redLedCrontrollerTask, "RED LED Task", 128, NULL, 1, NULL); //Init Red LED task
  xTaskCreate(blueLedCrontrollerTask, "BLUE LED Task", 128, NULL, 1, NULL); //Init Blue LED task
  xTaskCreate(yellowLedCrontrollerTask, "YELLOW LED Task", 128, NULL, 1, NULL); //Init Yellow LED task

}

void redLedCrontrollerTask( void *pvParameters)
{
  pinMode(RED, OUTPUT);
  while(1)
  {
    RedLEDProfiler++;  //Increment profilert value
    //Display Red profiler value
    Serial.print("RedLEDProfiler: ");
    Serial.println(RedLEDProfiler);
    digitalWrite(RED,digitalRead(RED)^1);
    delay(300);
  }
}

void blueLedCrontrollerTask( void *pvParameters)
{
  pinMode(BLUE, OUTPUT);
  while(1)
  {
    BlueLEDProfiler++;  //Increment Blue profiler
    //Display Blue profiler value
    Serial.print("Blue Profiler: ");
    Serial.println(BlueLEDProfiler);
    digitalWrite(BLUE,digitalRead(BLUE)^1);
    delay(300);
  }
}

void yellowLedCrontrollerTask( void *pvParameters)
{
  pinMode(YELLOW, OUTPUT);
  while(1)
  {
    YellowLEDProfiler++;  //Increment Yellow profiler
    //Display Yellow profiler valuie
    Serial.print("Yellow Profiler: ");
    Serial.println(YellowLEDProfiler);
    digitalWrite(YELLOW,digitalRead(YELLOW)^1);
    delay(300);
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}