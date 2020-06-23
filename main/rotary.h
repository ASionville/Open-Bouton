#ifndef ROTARY_H
#define ROTARY_H 0


class Rotary{
private :
  const int clkPin  = 13;
  const int dtPin  = 12;
  const int swPin  = 14;

  int rotVal  = 0;
  bool clkState  = LOW;
  bool clkLast  = HIGH;
  bool swState  = HIGH;
  bool swLast  = HIGH;
public :
  Rotary(clkPin,dtPin,swPin);
}



#endif
