#include <PS4Controller.h>
// #include <esp_bt_device.h>

unsigned long lastTimeStamp = 0;
void notify()
{
  char messageString[200];
  sprintf(messageString, "%4d,%4d,%4d,%4d",
  PS4.LStickX(),
  PS4.LStickY(),
  PS4.RStickX(),
  PS4.RStickY());
}

// void onConnect()
// {
//   Serial.println("Connected!.");
// }

// void onDisConnect()
// {
//   Serial.println("Disconnected!.");    
// }

void init_ps4(){
  PS4.attach(notify);
  // PS4.attachOnConnect(onConnect);
  // PS4.attachOnDisconnect(onDisConnect);
  PS4.begin();
  Serial.println("Ready.");
}