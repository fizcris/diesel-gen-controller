/*
 * Blink
 * Turns on an LED on for one second,
 * then off for one second, repeatedly.
 */
// ledPin refers to ESP32 GPIO 23
const int ledPin = 23;

#include <Arduino.h>

void setup()
{
  // initialize LED digital pin as an output.
  pinMode(ledPin, OUTPUT);
}

void loop()
{
  // turn the LED on (HIGH is the voltage level)
  digitalWrite(ledPin, HIGH); 
  // wait for a second
  delay(1000);
  // turn the LED off by making the voltage LOW
  digitalWrite(ledPin, LOW); 
   // wait for a second
  delay(1000);
}
