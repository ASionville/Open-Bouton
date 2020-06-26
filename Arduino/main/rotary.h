#ifndef ROTARY_H
#define ROTARY_H 0

// Classe Rotary : Gestion du potentiomètre cliquable
// Class Rotary : Manages the clickable rotary
class Rotary{

private :

  // Branchements de l'encodeur : Horloge, Données, Bouton
  // Encoder pins : Clock, Data, Switch
  int clkPin;
  int dtPin;
  int swPin;

  // Etat du potentiomètre$
  // Rotary state
  int rotVal;

  // Données de l'horloge
  // Clock data
  bool clkState;
  bool clkLast;

  // Données du bouton
  // Switch data
  bool swState;
  bool swLast;

public :
  // Déclaration du Rotary
  // Declaration of the Rotary
  Rotary(int unClkPin, int unDtPin, int unSwPin);

// Fonction qui lit l'état du switch et agis en conséquence
// Function that reads the switch state and acts accordingly
  bool readSwitch();

// Fonction qui lit l'état du potentiomètre et agis en conséquence
// Function that reads the rotary state and acts accordingly
  int readRotary();
};

#endif