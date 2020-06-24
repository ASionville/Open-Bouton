
#include <Adafruit_NeoPixel.h>

#define PIXEL_PIN    4

#define PIXEL_COUNT 24

#include "rotary.h"
#include "neoled.h"

Adafruit_NeoPixel strip(PIXEL_COUNT, PIXEL_PIN, NEO_GRB + NEO_KHZ800);

int lastState = 0;

Rotary leCodeur(13, 12, 14);

Neoled ledContoleur(64);

void setup(){
  Serial.begin(9600);
  Serial.println(F("Initialize System"));



}

void loop(){
  if(leCodeur.readRotary() != lastState){
    lastState = leCodeur.readRotary();
    Serial.println(lastState);
    ledContoleur.actLed(lastState);
  }
  if(!leCodeur.readSwitch()){
    Serial.println("switch");
    ledContoleur.actLed(0);
  }
}
