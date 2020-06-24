Neoled::Neoled(int bright){
  this->ledNb = 0;

  strip.begin(); // Initialize NeoPixel strip object (REQUIRED)
  strip.show();  // Initialize all pixels to 'off'
  strip.setBrightness(bright);
}

void Neoled::actLed(int nb){
  this->ledNb = nb;
  strip.clear();
  if (nb != 0) {
    for (int i = 0; i < nb+1; i++) {
      strip.setPixelColor(i-1, 255, 255, 255);
    }
  }
  strip.show();
}
