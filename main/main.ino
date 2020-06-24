
#include <Adafruit_NeoPixel.h>

#define PIXEL_PIN    4

#define PIXEL_COUNT 24

#include "rotary.h"

Adafruit_NeoPixel strip(PIXEL_COUNT, PIXEL_PIN, NEO_GRB + NEO_KHZ800);

int lastState = 0;

Rotary leCodeur(13, 12, 14);

void setup(){
  Serial.begin(9600);
  Serial.println(F("Initialize System"));


  strip.begin(); // Initialize NeoPixel strip object (REQUIRED)
  strip.show();  // Initialize all pixels to 'off'
}

void loop(){
  if(leCodeur.readRotary() != lastState){
    lastState = leCodeur.readRotary();
    Serial.println(lastState);
  }
  if(!leCodeur.readSwitch()){
    Serial.println("switch");
  }
  strip.setPixelColor(5, 255, 255, 255);         //  Set pixel's color (in RAM)
  strip.show();
}
