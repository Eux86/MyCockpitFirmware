#include <Arduino.h>
#include "SegmentDisplay.h"

#define decimalPin 2
#define unitPin 3
#define incrementPin 4


const int pinStart = 5;
const int pinEnd = 12;
const int displayRefreshInterval = 10; // milliseconds
const int numberOfDigits = 2;

int debugMode = true;
int number = 0;
int timer = 0;
int loopsPerSecond = 0;

String readString;
int incButtonState = 0;

SegDisplay *SD = new SegDisplay();

void setup()
{
  Serial.begin(9600);
  for (int i = pinStart; i <= pinEnd; i++)
  {
    pinMode(i, OUTPUT);
  }
  pinMode(decimalPin, OUTPUT);
  pinMode(unitPin, OUTPUT);
  pinMode(incrementPin, INPUT);
  Serial.println("ready");
  loopsPerSecond = 1000/(displayRefreshInterval*numberOfDigits);
}

void loop()
{
  timer++;
  
  while (Serial.available()) {
    delay(3);  //delay to allow buffer to fill
    if (Serial.available() >0) {
      char c = Serial.read();  //gets one byte from serial buffer
      readString += c; //makes the string readString
    }
  }
  
  if (readString.length() > 0) {
    debugMode = false;    // Disable debug mode as soon as data is available
    // Serial.println(readString);
    number = readString.toInt();//(readString.substring(1, 3)).toInt();
    // Serial.println(number);
    readString = "";
  }

  displayNumber(number);
  
  incButtonState = digitalRead(incrementPin);
  if (incButtonState == HIGH) {
    Serial.println("inc");
  }
  
  if (timer == loopsPerSecond && debugMode) {
    timer = 0;
    number++;
    if (number > 99) number = 0;
    //Serial.println(number / 10);
  }
}

void displayNumber(int number) {
  digitalWrite(unitPin, LOW);
  SD->write(number % 10);
  delay(displayRefreshInterval);
  digitalWrite(unitPin, HIGH);

  digitalWrite(decimalPin, LOW);
  SD->write(number / 10);
  delay(displayRefreshInterval);
  digitalWrite(decimalPin, HIGH);
}

