#ifndef NEOLED_H
#define NEOLED_H 0

// Classe Neoled : Gestion de l'allumage des LEDs en fonction du Rotary
// Class Neoled : Manages LEDs colors according to the Rotary
class Neoled{

private :
  // Le nombre de LEDs allumées
  // Amount of LEDs lit
  int ledNb;

public :
  Neoled(int bright);

  // Fonction pour allumer correctement les LEDs en fonction du Rotary
  // Function to manage LEDs colors according to the Rotary
  void actLed(int nb);

  // Fonction qui renvoie le nombre de LEDs allumées
  // Function that returns the number of LEDs lit
  int getledNB();
};

#endif