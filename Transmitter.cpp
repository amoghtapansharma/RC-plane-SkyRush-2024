#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(9, 10);   // CE, CSN
const byte address[6] = "SKY01";

struct DataPacket {
  int roll;
  int pitch;
  int throttle;
  int yaw;
};

DataPacket data;

void setup() {
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_LOW);
  radio.setDataRate(RF24_250KBPS);
  radio.stopListening();
}

void loop() {
  data.roll     = analogRead(A0);  // Joystick X
  data.pitch    = analogRead(A1);  // Joystick Y
  data.throttle = analogRead(A2);  // Potentiometer
  data.yaw      = analogRead(A3);  // Optional

  radio.write(&data, sizeof(DataPacket));
  delay(20); // 50 Hz update
}
