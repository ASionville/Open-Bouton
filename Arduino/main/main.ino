#include <ESP8266WiFi.h>          //ESP8266 Core WiFi Library (you most likely already have this in your sketch)
#include <DNSServer.h>            //Local DNS Server used for redirecting all requests to the configuration portal
#include <ESP8266WebServer.h>     //Local WebServer used to serve the configuration portal
#include <WiFiManager.h>          //https://github.com/tzapu/WiFiManager WiFi Configuration Magic
#include <WiFiUdp.h>

#include <Adafruit_NeoPixel.h>
#define PIXEL_PIN 4
#define PIXEL_COUNT 24

#include "rotary.h"
#include "neoled.h"

// Modifier le port UDP ici (même que config.py)
// Change UDP port here (same as config.py)
unsigned int localUdpPort = 8000;

// Mettre l'IP du Raspberry (même que config.py)
// Put the Raspberry IP adress here (same as config.py)
const char* IPCible = "192.168.241.113";

// Initialisation de la liaison wifi
// Initializing the wifi connexion
WiFiUDP Udp;

// Initialisation de la bande de LEDs
// Initializing the LED strip
Adafruit_NeoPixel strip(PIXEL_COUNT, PIXEL_PIN, NEO_GRB + NEO_KHZ800);

int lastState = 0;

// Initialisation des contrôleurs  pour les LEDs et le Rotary
// Initializing the LEDs and Rotary managers
Rotary leCodeur(13, 12, 14);

Neoled ledContoleur(64);

// Fonction d'initialisation
// Initialization function
void setup(){

  // Port série
  // Serial Port
  Serial.begin(9600);
  Serial.println(F("Initialize System"));

  // Contrôleur Wifi
  // Wifi Manager
  WiFiManager wifiManager;
  wifiManager.autoConnect();

}

// Boucle principale
// Main Loop
void loop(){

  // Si le Rotary change de position
  // If the position of the Rotary has changed
  if(leCodeur.readRotary() != lastState){

    // Actualisation de l'état du Rotary
    // Rotary status update
    lastState = leCodeur.readRotary();
    Serial.println(lastState);

    // Allumage des  LEDs
    // Light LEDs up
    ledContoleur.actLed(lastState);
  }

  // Si le bouton change de position
  // If the state of the switch has changed
  if(!leCodeur.readSwitch()){

    Serial.println("switch");

    // Envoi du paquet UDP sous la forme "open-{nombre de demi heures}"
    // Sending the UDP packet as "open-{amount of half hours}"
    Udp.beginPacket(IPCible, localUdpPort);

    Udp.print("open-");
    Udp.print(ledContoleur.getledNB());

    Udp.endPacket();

    ledContoleur.okBlink();

    // Délai de sécurité
    // Security delay
    delay(1000);
  }
}
