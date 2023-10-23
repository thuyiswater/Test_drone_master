#include <Arduino.h>
#include <PS4_control.h>

void setup()
{
  // Initialize UART2 for Master ESP32
  init_UART();
  // Initialize PS4 Controller
  init_ps4(); 
}

void loop()
{
  // Check for user inputs
  checkInput();

  // Send joystick values to Middle ESP32
  send();
}

