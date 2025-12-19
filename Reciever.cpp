#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <Servo.h>

RF24 radio(9, 10);   // CE, CSN
const byte address[6] = "SKY01";

Servo esc, servoRoll, servoPitch, servoYaw;

struct DataPacket {
  int roll;
  int pitch;
  int throttle;
  int yaw;
};

DataPacket data;

void setup() {
  esc.attach(3);
  servoRoll.attach(5);
  servoPitch.attach(6);
  servoYaw.attach(7);

  esc.writeMicroseconds(1000); // ESC arming
  delay(3000);

  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_LOW);
  radio.setDataRate(RF24_250KBPS);
  radio.startListening();
}

void loop() {
  if (radio.available()) {
    radio.read(&data, sizeof(DataPacket));

    int throttle = map(data.throttle, 0, 1023, 1000, 2000);
    int roll     = map(data.roll, 0, 1023, 0, 180);
    int pitch    = map(data.pitch, 0, 1023, 0, 180);
    int yaw      = map(data.yaw, 0, 1023, 0, 180);

    esc.writeMicroseconds(throttle);
    servoRoll.write(roll);
    servoPitch.write(pitch);
    servoYaw.write(yaw);
  }
}
