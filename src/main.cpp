#include <Arduino.h>
#include "../lib/ps4_control/ps4_control.h"
#include <PS4Controller.h>

void setup(){
  // Start serial with platform baudrate/monitor speed
  Serial.begin(115200);
  init_ps4(); // Initialize PS4 Controller
  PS4.begin();
  Serial.println("Ready.");
}

void loop() {
  checkInput(); // check all the input from User
}

