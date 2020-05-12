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
  static void write(int digit);
};
