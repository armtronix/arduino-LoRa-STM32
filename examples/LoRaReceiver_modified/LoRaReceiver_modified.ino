#include <SPI.h>
#include <LoRa_STM32.h>

void setup() {
  Serial.begin(115200);
  while (!Serial);

  Serial.println("LoRa Receiver");
  //LoRa.setTxPower(17, PA_OUTPUT_PA_BOOST_PIN);
  //LoRa.setSignalBandwidth(31.25E3); 
  //LoRa.setSpreadingFactor(7);
  //LoRa.setCodingRate4(5);
  if (!LoRa.begin(866E6)) {
    Serial.println("Stating LoRa failed!");
    while (1);
  }
}

void loop() {
  // try to parse packet
  int packetSize = LoRa.parsePacket();
  if (packetSize) {
    // received a packet
    Serial.print("Received packet '");

    // read packet
    while (LoRa.available()) {
      Serial.print((char)LoRa.read());
    }

    // print RSSI of packet
    Serial.print("' with RSSI ");
    Serial.println(LoRa.packetRssi());
  }
}
