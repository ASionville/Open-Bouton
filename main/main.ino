#include "rotary.h"

const int clkPin  = 13;
const int dtPin  = 12;
const int swPin  = 14;


int rotVal  = 0;
bool clkState  = LOW;
bool clkLast  = HIGH;
bool swState  = HIGH;
bool swLast  = HIGH;


void setup(){
  Serial.begin(9600);
  Serial.println(F("Initialize System"));
  pinMode(clkPin,INPUT);
  pinMode(dtPin,INPUT);
  pinMode(swPin,INPUT);
}

void loop(){
  readRotary();
  readSwitch();
}

void readRotary(){
  clkState = digitalRead(clkPin);
  if ((clkLast == LOW) && (clkState == HIGH)) {
    Serial.print("Rotary position ");
     if (digitalRead(dtPin) == HIGH) {
       rotVal=rotVal-1;
       if ( rotVal < 0 ) {
        rotVal = 0;
        }
     }else{
       rotVal++;
       if ( rotVal > 10 ){
        rotVal = 10;
       }
     }
     Serial.println(rotVal);
     delay(100);
   }
  clkLast = clkState;
}

void readSwitch(){
  swState=digitalRead(swPin);
  if (swState==LOW && swLast==HIGH) {
    Serial.println("Rotary pressed");
    delay(80);
  }
  swLast=swState;
}
