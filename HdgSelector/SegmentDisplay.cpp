#include "SegmentDisplay.h"

byte d1 = 0b01000100;
byte d2 = 0b10101101;
byte d3 = 0b11101100;
byte d4 = 0b01110100;
byte d5 = 0b11111000;
byte d6 = 0b11111001;
byte d7 = 0b01001100;
byte d8 = 0b11111101;
byte d9 = 0b11111100;
byte d0 = 0b11011101;

//Pin connected to ST_CP of 74HC595
int latchPin = 8;
//Pin connected to SH_CP of 74HC595
int clockPin = 12;
////Pin connected to DS of 74HC595
int dataPin = 11;

int digit1Pin = 7;
int digit2Pin = 6;
int digit3Pin = 5;

int refreshDelay = 1;

void SegDisplay::setup() {
  pinMode(latchPin, OUTPUT);
  pinMode(digit1Pin, OUTPUT);
  pinMode(digit2Pin, OUTPUT);
  pinMode(digit3Pin, OUTPUT);
}

byte SegDisplay::getDigit(int number)
{
  if (number == 1)
    return d1;
  if (number == 2)
    return d2;
  if (number == 3)
    return d3;
  if (number == 4)
    return d4;
  if (number == 5)
    return d5;
  if (number == 6)
    return d6;
  if (number == 7)
    return d7;
  if (number == 8)
    return d8;
  if (number == 9)
    return d9;
  if (number == 0)
    return d0;
  return 0b11111111;
}

void SegDisplay::displayDigit(int number, int digitNumber)
{
  //load the light sequence you want from array
  const int data = getDigit(number);
  //ground latchPin and hold low for as long as you are transmitting
  digitalWrite(latchPin, 0);
  //move 'em out
  shiftOut(dataPin, clockPin, data);
  //return the latch pin high to signal chip that it
  //no longer needs to listen for information
  digitalWrite(latchPin, 1);
  digitalWrite(digit1Pin, digitNumber == 1 ? 1 : 0);
  digitalWrite(digit2Pin, digitNumber == 2 ? 1 : 0);
  digitalWrite(digit3Pin, digitNumber == 3 ? 1 : 0);
  delay(refreshDelay);
}

void SegDisplay::displayNumber(int number)
{
  int d1 = number % 10;
  int d2 = number % 100 / 10;
  int d3 = number % 1000 / 100;
  int d4 = number % 10000 / 1000;
  int d5 = number % 100000 / 10000;

  displayDigit(d1, 1);
  displayDigit(d2, 2);
  displayDigit(d3, 3);
  displayDigit(d4, 4);
  displayDigit(d5, 5);
}

// the heart of the program
void SegDisplay::shiftOut(int myDataPin, int myClockPin, byte myDataOut) {
  // This shifts 8 bits out MSB first,
  //on the rising edge of the clock,
  //clock idles low

  //internal function setup
  int i = 0;
  int pinState;
  pinMode(myClockPin, OUTPUT);
  pinMode(myDataPin, OUTPUT);

  //clear everything out just in case to
  //prepare shift register for bit shifting
  digitalWrite(myDataPin, 0);
  digitalWrite(myClockPin, 0);

  //for each bit in the byte myDataOut�
  //NOTICE THAT WE ARE COUNTING DOWN in our for loop
  //This means that %00000001 or "1" will go through such
  //that it will be pin Q0 that lights.
  for (i = 7; i >= 0; i--)  {
    digitalWrite(myClockPin, 0);

    //if the value passed to myDataOut and a bitmask result
    // true then... so if we are at i=6 and our value is
    // %11010100 it would the code compares it to %01000000
    // and proceeds to set pinState to 1.
    if ( myDataOut & (1 << i) ) {
      pinState = 1;
    }
    else {
      pinState = 0;
    }

    //Sets the pin to HIGH or LOW depending on pinState
    digitalWrite(myDataPin, pinState);
    //register shifts bits on upstroke of clock pin
    digitalWrite(myClockPin, 1);
    //zero the data pin after shift to prevent bleed through
    digitalWrite(myDataPin, 0);
  }

  //stop shifting
  digitalWrite(myClockPin, 0);
}

void SegDisplay::write(int COUNT)
{
  this->displayNumber(COUNT);
}
