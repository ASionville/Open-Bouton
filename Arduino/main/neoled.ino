// Initialisation
// Initialization
Neoled::Neoled(int bright){
  this->ledNb = 0;

  strip.begin();
  strip.show();
  strip.setBrightness(bright);
}

// Fonction pour allumer correctement les LEDs en fonction du Rotary
// Function to manage LEDs colors according to the Rotary
void Neoled::actLed(int nb){
  this->ledNb = nb;

  // On éteint tout
  // We shut everything up
  strip.clear();

  // Allumer 0 LED ? Inutile
  // Useless to light up 0 LED
  if (nb != 0) {

    // Boucle dans les LEDs
    // Loop in LEDs
    for (int i = 0; i < nb+1; i++) {

      // Une LED sur deux est blanche : heure entière, l'autre rouge pour 30m
      // One LED out of two is white: whole hour, the other red for 30m
      if (i%2 == 0) {
        strip.setPixelColor(i-1, 255, 255, 255);
      }else{
        strip.setPixelColor(i-1, 255, 0, 0);
      }
    }
  }

  // Maintenant on allume
  // Then light everything up
  strip.show();
}

// Fonction qui renvoie le nombre de LEDs allumées
// Function that returns the number of LEDs lit
int Neoled::getledNB(){
  return this->ledNb;
}

void Neoled::okBlink(){
  int tempR;
  int tempV;
  int tempB;

  for (int i = 0; i < 3*2; i++) {
      if(i%2 == 0){
        tempR = 0;
        tempV = 0;
        tempB = 0;

      }else{
        tempR = 75;
        tempV = 181;
        tempB = 67;
      }

      for (int j = 0; j < 24; j++) {
        // On fait clignoter les LEDs pour confirmer
        // We make the LEDs blink to confirm
        strip.setPixelColor(j-1, tempR, tempV, tempB);
      }

      strip.show();
  }
}
