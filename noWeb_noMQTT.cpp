#include <WiFi.h>
#include <WakeOnLan.h>
#include <WiFiUdp.h>

// WiFi SSID passwd
const char* ssid = "aa";
const char* password = "aabbccdd";
const char *MACAddress = "aa:bb:cc:dd:ee";

#define LED 22
#define Button 18

int a;
int button = 0;
int lastbutton = 0;

WiFiUDP UDP;
WakeOnLan WOL(UDP);

void setup() {
  Serial.begin(115200);
  pinMode(LED, OUTPUT);
  digitalWrite(LED,HIGH);
  a = !digitalRead(LED);
  pinMode(Button, INPUT_PULLUP);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  button = digitalRead(Button);
  if(button != lastbutton){
   if(button == LOW){
    digitalWrite(LED,LOW);
    WOL.sendMagicPacket(MACAddress);
    delay(100);
    digitalWrite(LED,HIGH);
    }
   lastbutton = button;
  }
}
