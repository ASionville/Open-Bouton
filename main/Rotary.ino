#include "rotary.h"

Rotary::Rotary(int unClkPin, int unDtPin, int unSwPin){
  this->clkPin = unClkPin;
  this->dtPin = unDtPin;
  this->swPin = unSwPin;
  this->rotVal = 0;

  this->clkState  = LOW;
  this->clkLast  = HIGH;
  this->swState  = HIGH;
  this->swLast  = HIGH;


  pinMode(clkPin, INPUT);
  pinMode(dtPin, INPUT);
  pinMode(swPin, INPUT);
}

bool Rotary::readSwitch(){
  swState=digitalRead(swPin);
  if (swState==LOW && swLast==HIGH) {
    Serial.println("Rotary pressed");
    delay(80);
  }
  swLast=swState;
  return swState;
}

int Rotary::readRotary(){
  this->clkState = digitalRead(this->clkPin);
  if ((this->clkLast == LOW) && (this->clkState == HIGH)) {
    Serial.print("Rotary position ");
      if (digitalRead(this->dtPin) == HIGH) {
        this->rotVal=this->rotVal-1;
        if ( this->rotVal < 0 ) {
         this->rotVal = 0;
        }
      }else{
        rotVal++;
        if ( this->rotVal > 25 ){
         this->rotVal = 25;
        }
      }
      Serial.println(this->rotVal);
      delay(100);
    }
  this->clkLast = this->clkState;
  return this->rotVal;
}
