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

unsigned int localUdpPort = 8000;//port de comunication
const char* IPCible = "192.168.241.113";//Ip Server

WiFiUDP Udp;

Adafruit_NeoPixel strip(PIXEL_COUNT, PIXEL_PIN, NEO_GRB + NEO_KHZ800);

int lastState = 0;

Rotary leCodeur(13, 12, 14);

Neoled ledContoleur(64);

void setup(){
  Serial.begin(9600);
  Serial.println(F("Initialize System"));

  WiFiManager wifiManager;
  wifiManager.autoConnect();

}

void loop(){
  if(leCodeur.readRotary() != lastState){
    lastState = leCodeur.readRotary();
    Serial.println(lastState);
    ledContoleur.actLed(lastState);
  }
  if(!leCodeur.readSwitch()){
    Serial.println("switch");
    Udp.beginPacket(IPCible, localUdpPort);
    Udp.print("open");
    Udp.print(ledContoleur.getledNB());
    Udp.endPacket();
    ledContoleur.actLed(0);
    delay(1000);
  }
}
