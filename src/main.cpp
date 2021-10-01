#include <Arduino.h>

#define PUSHED LOW
#define RELEASED HIGH

const int delayON = 1500;
const int delayOFF = 20000;
bool engineOff;

#define DAC1 25
#define DAC2 26

#define ANALOG_A1 34
#define ANALOG_A2 35
#define ANALOG_A3 32
#define ANALOG_A4 33

const int Relay1 =2;
const int Relay2 =15;
const int Relay3 =5;
const int Relay4 =4;

const int DI1 =36;
const int DI2 =39;
const int DI3 =27;
const int DI4 =14;

const int BEEP =18;

byte lastState;
unsigned long startMillis;


void setup() {
  // put your setup code here, to run once:
  pinMode(Relay1, OUTPUT);
  pinMode(Relay2, OUTPUT);
  pinMode(Relay3, OUTPUT);
  pinMode(Relay4, OUTPUT);

  pinMode(BEEP, OUTPUT);

  pinMode(DI1, INPUT_PULLUP);
  pinMode(DI2, INPUT_PULLUP);
  pinMode(DI3, INPUT_PULLUP);
  pinMode(DI4, INPUT_PULLUP);

  digitalWrite(Relay1,LOW);
  digitalWrite(Relay2,LOW);
  digitalWrite(Relay3,LOW);
  digitalWrite(Relay4,LOW);

  engineOff = true;
}

void loop() {
  // put your main code here, to run repeatedly:
  byte thisState = digitalRead(DI1);
  

  //button changed state?
  if (lastState != thisState)
  {
    //update to the new state
    lastState = thisState;
    //record time
    startMillis = millis();
  }

  //Button pushed for more >= 1 seconds
  if (lastState == PUSHED && millis() - startMillis >= 1000UL)
  {
    if (engineOff) {
      digitalWrite(Relay3, HIGH); //Give power to batt
      digitalWrite(Relay1, HIGH); //start START relay
      delay(delayON);
      digitalWrite(Relay1, LOW); //stop START relay
      engineOff = false;
    }
  }

  //Button released for more >= 1 seconds
  if (lastState == RELEASED && millis() - startMillis >= 1000UL)
  {
    if (!engineOff) {
      digitalWrite(Relay3, LOW); //Remove power from batt
      digitalWrite(Relay2, HIGH); //start STOP relay
      delay(delayOFF);
      digitalWrite(Relay2, LOW); //stop STOP relay
      engineOff = true;
    }
  }
  delay(1000);
}