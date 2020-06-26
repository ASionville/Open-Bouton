#include "rotary.h"

// Initialisation
// Initialization
Rotary::Rotary(int unClkPin, int unDtPin, int unSwPin){
  this->clkPin = unClkPin;
  this->dtPin = unDtPin;
  this->swPin = unSwPin;
  this->rotVal = 0;

  // L'horloge est éteinte par défaut
  // The Clock is down by default
  this->clkState  = LOW;
  this->clkLast  = HIGH;

  // Le switch est en haut (pas appuyé) par défaut
  // The Switch is up (not pressed) by default 
  this->swState  = HIGH;
  this->swLast  = HIGH;

  // Déclaration des branchements
  // Pins declaration
  pinMode(clkPin, INPUT);
  pinMode(dtPin, INPUT);
  pinMode(swPin, INPUT);
}

// Fonction qui lit l'état du switch et agis en conséquence
// Function that reads the switch state and acts accordingly
bool Rotary::readSwitch(){

  // Récupération des infos switch
  // Getting the switch data
  swState=digitalRead(swPin);

  // Si on appuie sur le bouton
  // If the button is pressed
  if (swState==LOW && swLast==HIGH) {
    Serial.println("Rotary pressed");
    delay(80);
  }

  // On réinitialise le Rotary
  // We reset the Rotary
  swLast=swState;
  if (!swState) {
      this->rotVal = 0;
  }
  return swState;
}

// Fonction qui lit l'état du potentiomètre et agis en conséquence
// Function that reads the rotary state and acts accordingly
int Rotary::readRotary(){

  // Récupération des infos switch
  // Getting the switch data
  this->clkState = digitalRead(this->clkPin);

  // Si on appuie sur le bouton
  // If the button is pressed
  if ((this->clkLast == LOW) && (this->clkState == HIGH)) {

    Serial.print("Rotary position ");

      // Lecture de l'encodeur
      // Reading the encoder data
      if (digitalRead(this->dtPin) == HIGH) {
        this->rotVal=this->rotVal-1;

        // Valeur minimale : 0
        // Minimum value is 0
        if ( this->rotVal < 0 ) {
         this->rotVal = 0;
        }

      }else{
        rotVal++;

        // Valeur maximale : 25
        // Maximum value is 25
        if ( this->rotVal > 25 ){
         this->rotVal = 25;
        }
      }

      Serial.println(this->rotVal);
      delay(150);
    }

  // On réinitialise le bouton et le potentiomètre
  // We reset the switch and the rotary
  this->clkLast = this->clkState;
  return this->rotVal;
}
