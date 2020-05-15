#include "RotaryEncoder.h"

volatile int lastEncoded = 0;
volatile long encoderValue = 0;
long lastencoderValue = 0;
int lastMSB = 0;
int lastLSB = 0;

int encPin1;
int encPin2;

const int encoderStepsPerRevolution=24; 
int angle = 0;
int angleLast = 0;

int encoderPos = 0;
boolean encoderALast = LOW; // remembers the previous pin state
boolean encoderBLast = LOW; // remembers the previous pin state

void RotEncoder::setup(int ep1, int ep2)
{
  encPin1 = ep1;
  encPin2 = ep2;

  pinMode(encPin1, INPUT);
  pinMode(encPin2, INPUT);

  digitalWrite(encPin1, HIGH); //turn pullup resistor on
  digitalWrite(encPin2, HIGH); //turn pullup resistor on

  //call updateEncoder() when any high/low changed seen
  //on interrupt 0 (pin 2), or interrupt 1 (pin 3)
  // attachInterrupt(0, updateEncoder, CHANGE);
  // attachInterrupt(1, updateEncoder, CHANGE);
}

void RotEncoder::loop() {
  boolean encoderA = digitalRead(encPin1);
  boolean encoderB = digitalRead(encPin2);
  if ((encoderALast == HIGH) && (encoderA == LOW)) {
    if (encoderB == LOW) {
      encoderPos++;
    } else {
      encoderPos--;
    }
    angle=(encoderPos % encoderStepsPerRevolution) * 360/encoderStepsPerRevolution;
    // Serial.print (encoderPos);
    // Serial.print (" ");
    // Serial.println (angle);
  }
  // if (encoderALast!=encoderA || encoderBLast != encoderB) {
  //   Serial.print("Encoder Last: ");
  //   Serial.print(encoderALast);
  //   Serial.print(" - Current A: ");
  //   Serial.print(encoderA);
  //   Serial.print(" - B: ");
  //   Serial.println(encoderB);
  // }

  if (encoderPos > 359)
    encoderPos = 0;
  if (encoderPos < 0)
    encoderPos = 359;

  encoderALast = encoderA;
  encoderBLast = encoderB;
  angleLast = angle;
}

int RotEncoder::getValue()
{
  //Do stuff here
  return encoderPos;
}
