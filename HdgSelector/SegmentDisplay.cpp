#include "SegmentDisplay.h"

void SegDisplay::write(int COUNT)
{
  switch (COUNT)
  {

  case 0: //when count value is zero show”0” on disp

    digitalWrite(segA, HIGH);

    digitalWrite(segB, HIGH);

    digitalWrite(segC, HIGH);

    digitalWrite(segD, HIGH);

    digitalWrite(segE, HIGH);

    digitalWrite(segF, HIGH);

    digitalWrite(segG, LOW);

    break;

  case 1: // when count value is 1 show”1” on disp

    digitalWrite(segA, LOW);

    digitalWrite(segB, HIGH);

    digitalWrite(segC, HIGH);

    digitalWrite(segD, LOW);

    digitalWrite(segE, LOW);

    digitalWrite(segF, LOW);

    digitalWrite(segG, LOW);

    break;

  case 2: // when count value is 2 show”2” on disp

    digitalWrite(segA, HIGH);

    digitalWrite(segB, HIGH);

    digitalWrite(segC, LOW);

    digitalWrite(segD, HIGH);

    digitalWrite(segE, HIGH);

    digitalWrite(segF, LOW);

    digitalWrite(segG, HIGH);

    break;

  case 3: // when count value is 3 show”3” on disp

    digitalWrite(segA, HIGH);

    digitalWrite(segB, HIGH);

    digitalWrite(segC, HIGH);

    digitalWrite(segD, HIGH);

    digitalWrite(segE, LOW);

    digitalWrite(segF, LOW);

    digitalWrite(segG, HIGH);

    break;

  case 4: // when count value is 4 show”4” on disp

    digitalWrite(segA, LOW);

    digitalWrite(segB, HIGH);

    digitalWrite(segC, HIGH);

    digitalWrite(segD, LOW);

    digitalWrite(segE, LOW);

    digitalWrite(segF, HIGH);

    digitalWrite(segG, HIGH);

    break;

  case 5: // when count value is 5 show”5” on disp

    digitalWrite(segA, HIGH);

    digitalWrite(segB, LOW);

    digitalWrite(segC, HIGH);

    digitalWrite(segD, HIGH);

    digitalWrite(segE, LOW);

    digitalWrite(segF, HIGH);

    digitalWrite(segG, HIGH);

    break;

  case 6: // when count value is 6 show”6” on disp

    digitalWrite(segA, HIGH);

    digitalWrite(segB, LOW);

    digitalWrite(segC, HIGH);

    digitalWrite(segD, HIGH);

    digitalWrite(segE, HIGH);

    digitalWrite(segF, HIGH);

    digitalWrite(segG, HIGH);

    break;

  case 7: // when count value is 7 show”7” on disp

    digitalWrite(segA, HIGH);

    digitalWrite(segB, HIGH);

    digitalWrite(segC, HIGH);

    digitalWrite(segD, LOW);

    digitalWrite(segE, LOW);

    digitalWrite(segF, LOW);

    digitalWrite(segG, LOW);

    break;

  case 8: // when count value is 8 show”8” on disp

    digitalWrite(segA, HIGH);

    digitalWrite(segB, HIGH);

    digitalWrite(segC, HIGH);

    digitalWrite(segD, HIGH);

    digitalWrite(segE, HIGH);

    digitalWrite(segF, HIGH);

    digitalWrite(segG, HIGH);

    break;

  case 9: // when count value is 9 show”9” on disp

    digitalWrite(segA, HIGH);

    digitalWrite(segB, HIGH);

    digitalWrite(segC, HIGH);

    digitalWrite(segD, HIGH);

    digitalWrite(segE, LOW);

    digitalWrite(segF, HIGH);

    digitalWrite(segG, HIGH);

    break;
  }
}
