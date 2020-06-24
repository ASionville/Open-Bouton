#include "rotary.h"

int lastState = 0;

Rotary leCodeur(13, 12, 14);

void setup(){
  Serial.begin(9600);
  Serial.println(F("Initialize System"));
}

void loop(){
  if(leCodeur.readRotary() != lastState){
    lastState = leCodeur.readRotary();
    Serial.println(lastState);
  }
  if(!leCodeur.readSwitch()){
    Serial.println("switch");
  }
}
