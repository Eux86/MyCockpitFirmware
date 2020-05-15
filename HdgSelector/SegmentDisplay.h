#pragma once

#include <Arduino.h>
#define segD 12
#define segE 11
#define segG 10
#define segF 9
#define segA 8
#define segB 7
#define segC 6
#define segDP 5

class SegDisplay {
public:
  void write(int digit);
  void setup();
//private:
  byte getDigit(int number);
  void displayDigit(int number, int digitNumber);
  void displayNumber(int number);
  void shiftOut(int myDataPin, int myClockPin, byte myDataOut);
};
