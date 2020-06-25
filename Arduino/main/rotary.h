#ifndef ROTARY_H
#define ROTARY_H 0


class Rotary{
private :
  int clkPin;
  int dtPin;
  int swPin;

  int rotVal;
  bool clkState;
  bool clkLast;
  bool swState;
  bool swLast;
public :
  Rotary(int unClkPin, int unDtPin, int unSwPin);
  bool readSwitch();
  int readRotary();
};



#endif
