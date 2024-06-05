#include <WiFi.h>
#include <WakeOnLan.h>
#include <WiFiUdp.h>

// WiFi SSID passwd
const char* ssid = "aa";
const char* password = "aabbccdd";
const char *MACAddress = "aa:bb:cc:dd:ee:ff";

#define LED 22

WiFiUDP UDP;
WakeOnLan WOL(UDP);

void setup() {
  pinMode(LED, OUTPUT);
  //LED on
  digitalWrite(LED,LOW);
  // WiFi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(100);
  }
  //LED off
  digitalWrite(LED,HIGH);
  WOL.sendMagicPacket(MACAddress);
  delay(50);
  //LED on
  digitalWrite(LED,LOW);
  WiFi.disconnect();
  delay(100);
  //LED off
  digitalWrite(LED,HIGH);
  esp_deep_sleep_start();
}

void loop() {}

void wakeUp() {}
