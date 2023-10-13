#include <Arduino.h>
#include "../lib/ps4_control/ps4_control.h"
#include <HardwareSerial.h>
#include <PS4Controller.h>

 HardwareSerial SerialPort(2);
void setup()
{
  // Start serial with platform baudrate/monitor speed
  Serial.begin(115200);
 
 // Initiate UART2 for Master EPS32
  SerialPort.begin(115200, SERIAL_8N1, 16, 17);

  init_ps4(); // Initialize PS4 Controller
}

void loop() {
  // checkInput();
  if (PS4.Square()){
    SerialPort.write(1); // cai nay la stop nah :))
  
  }
  if (PS4.Triangle()){
    SerialPort.write(2); // cai nay la stop nah :))
  }
  if (PS4.Circle()){
    SerialPort.write(3); // cai nay la stop nah :))
  }
  if (PS4.Cross()){
    SerialPort.write(4); // cai nay la stop nah :))
  }
}

