#include <Arduino.h>
#include "SegmentDisplay.h"
#include "RotaryEncoder.h"

int encoderPin1 = 4;
int encoderPin2 = 3;

int debugMode = true;
int previousHdg = -1;
int currentHdg = 0;
int timer = 0;

String readString;
int incButtonState = 0;

SegDisplay *SD = new SegDisplay();
RotEncoder *RE = new RotEncoder();

void setup()
{
  // Serial.begin(9600);
  // for (int i = pinStart; i <= pinEnd; i++)
  // {
  //   pinMode(i, OUTPUT);
  // }
  // pinMode(decimalPin, OUTPUT);
  // pinMode(unitPin, OUTPUT);
  // pinMode(incrementPin, INPUT);
  Serial.println("ready");

  //set pins to output because they are addressed in the main loop

  Serial.begin(9600);
  SD->setup();
  RE->setup(encoderPin1, encoderPin2);
  Serial.println("ready");
}

void loop()
{
  timer++;

  RE->loop();

  // Read values from Rotary Encoder
  const int knobValue = RE->getValue();
  if (knobValue != -999)
  {
    debugMode = false;
    currentHdg = knobValue;
  }

  while (Serial.available())
  {
    delay(3); //delay to allow buffer to fill
    if (Serial.available() > 0)
    {
      char c = Serial.read(); //gets one byte from serial buffer
      readString += c;        //makes the string readString
    }
  }

  if (readString.length() > 0)
  {
    debugMode = false; // Disable debug mode as soon as data is available
    // Serial.println(readString);
    currentHdg = readString.toInt(); //(readString.substring(1, 3)).toInt();
    // Serial.println(number);
    readString = "";
  }

  SD->displayNumber(currentHdg);
  if (previousHdg != currentHdg)
  {
    previousHdg = currentHdg;
    Serial.println(currentHdg);
  }

  if (timer % 100 == 0)
  {
    if (debugMode)
    {
      timer = 0;
      currentHdg++;
    }
  }
}
