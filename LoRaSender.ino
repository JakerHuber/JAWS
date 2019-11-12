#include <SPI.h>
#include <LoRa.h>

/*********
 Pre-setup
*********/
// LoRa transceiver pins
// Used to override default pins
#define ss 5
#define rst 14
#define dio0 2

int counter = 0;

/*********
 Setup
*********/
void setup() {
  // Start the Serial Monitor 
  Serial.begin(115200); // sets baud rate to 115200

  // Override default pins before initializing LoRa module
  LoRa.setPins(ss, rst, dio0);
  
  // Start LoRa at 915MHz frequency //915E6
  while (!LoRa.begin(915E6)) {
    LoRa.begin(915E6);
    // Print dots until it begins
    Serial.print(".");
    delay(1000);
  }
  
  Serial.println("LoRa Initializing OK!");
}

/*********
 Loop
 Put your main code here, to run repeatedly
*********/
void loop() {
  // LoRa sender code
  Serial.print("Sending packet: ");
  Serial.println(counter);
  
  // send packet
  LoRa.beginPacket();
  LoRa.print("hello ");
  LoRa.print(counter);
  LoRa.endPacket();
  counter++;

  // Print confirmation to serial
  Serial.println("");
  Serial.print("LoRa packet ");
  Serial.print(counter);
  Serial.println(" sent!");
  delay(10000);
}
