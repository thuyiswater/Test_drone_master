#include <Arduino.h>
#include <PS4_control.h>

void setup()
{
  // Initializing connection between PS4 and Master ESP32
  init_ps4();

  // Initializing UART communication between Master and Middle ESP32
  init_UART();
}

void loop()
{
  // Checking for user inputs through PS4
  checkInput();

  // Sending UART signals from Master to Middle ESP32
  sendUART();
}