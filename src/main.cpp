#include <Arduino.h>
#include "../lib/ps4_control/ps4_control.h"
#include <PS4Controller.h>
#include <HardwareSerial.h>

HardwareSerial SerialPort(2); // use UART2

void setup(){
  // Start serial with platform baudrate/monitor speed
  Serial.begin(115200);
  init_ps4(); // Initialize PS4 Controller

  // Initiate UART2 for Master EPS32
  SerialPort.begin(115200, SERIAL_8N1, 16, 17);
}

void loop() {
  checkInput(); // check all the input from User
  if (PS4.Square()) // Testing for Square button
  {
    SerialPort.print(1);
  }
  else
  {
    SerialPort.print(0);
  }
}

