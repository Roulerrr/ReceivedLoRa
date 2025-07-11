#include <Arduino.h>
#include <SPI.h>
#include <LoRa.h>
#include <WiFi.h>


#define SS 5
#define RST 14
#define DIO0 26



// === COFIGURATION === //
// const
// #define PIN_CSPIN = 13;

const char* ssid ="";
const char* password = "";
// #define 

void data_received() {


}


void setup() {
  Serial.begin(115200);
  while (!Serial);

  Serial.println("LoRa Receiver");

  LoRa.setPins(SS, RST, DIO0);

  if (!LoRa.begin(915E6)) {
    Serial.println("Starting LoRa failed!");
    while (1);
  }
}

void loop() {
  int packetSize = LoRa.parsePacket();
  if (packetSize) {
    Serial.print("Received packet: ");
    while (LoRa.available()) {
      Serial.print((char)LoRa.read());
    }
    Serial.println();
  }
}
