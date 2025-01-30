#include <Arduino_FreeRTOS.h>

#define RED 6
#define BLUE 7
#define YELLOW 8

typedef int TaskProfiler;

TaskProfiler RedLEDProfiler;
TaskProfiler BlueLEDProfiler;
TaskProfiler YellowLEDProfiler;

const uint16_t *redLed = (uint16_t *) RED;
const uint16_t *blueLed = (uint16_t *) BLUE;
const uint16_t *yellowLed = (uint16_t *) YELLOW;

void setup()
{
  xTaskCreate(ledControllerTask, "RED LED TASK", 100, (void *) redLed, 1, NULL);
  xTaskCreate(ledControllerTask, "BLUE LED TASK", 100, (void *) blueLed, 1, NULL);
  xTaskCreate(ledControllerTask, "YELLOW LED TASK", 100, (void *) yellowLed, 1, NULL);
}

//Using Single task function to toggle all three LEDs depending upon the pvParameters passed
void ledControllerTask(void *pvParameters)
{
  pinMode(RED, OUTPUT);
  pinMode(BLUE, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  while(1)
  {
    digitalWrite(pvParameters, digitalRead(pvParameters)^1);
  }
}

void loop()
{

}