#include "rotary.h"


Rotary leCodeur(13, 12, 14);

void setup(){
  Serial.begin(9600);
  Serial.println(F("Initialize System"));
}

void loop(){
  if (leCodeur.readSwitch()) {
    Serial.println(leCodeur.readSwitch());
  }
  leCodeur.readRotary();
  //Serial.println(leCodeur.readRotary());
}
