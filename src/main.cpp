#include <Arduino.h>
#include "../lib/ps4_control/ps4_control.h"
#include <HardwareSerial.h>
#include <PS4Controller.h>

HardwareSerial SerialPort2(2);
HardwareSerial SerialPort1(1);
void setup()
{
  // Start serial with platform baudrate/monitor speed
  Serial.begin (115200);
  SerialPort1.begin(115200, SERIAL_8N1, 4, 2);
 
 // Initiate UART2 for Master EPS32
  SerialPort2.begin(115200, SERIAL_8N1, 16, 17);

  init_ps4(); // Initialize PS4 Controller
}

void loop() {
  if(PS4.LStickX()){
    Serial.printf("Left Stick x at %d\n", PS4.LStickX());
    SerialPort1.write(PS4.LStickX());
  }

  if (PS4.Square()){ //increase throttle
   Serial.println("Square Button");
    SerialPort2.write(1); 
  }
  delay(10);
  if (PS4.Cross()){ //decrease throttle
  Serial.println("Cross Button");
    SerialPort2.write(2);
  }
}

