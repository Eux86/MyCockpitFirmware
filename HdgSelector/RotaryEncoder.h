#pragma once

#include <Arduino.h>

class RotEncoder {
public:
  int getValue();
  void setup(int encoderPin1, int encoderPin2);
  void loop();
private:
};
