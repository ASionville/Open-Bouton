#ifndef NEOLED_H
#define NEOLED_H 0

class Neoled{
private :
  int ledNb;
public :
  Neoled(int bright);
  void actLed(int nb);
};


#endif
