#include <Arduino.h>
#include <PS4Controller.h>

int8_t joystickValue[3], button1[2];

void notify()
{
  char messageString[200];
  sprintf(messageString, "%4d,%4d,%4d,%4d", PS4.LStickX(), PS4.LStickY(), PS4.RStickX(), PS4.RStickY());
}

void onConnect()
{
  Serial.println("Connected!.");
}

void onDisConnect()
{
  Serial.println("Disconnected!.");    
}

void init_ps4() /*     INITIALIZE PS4 CONNECTION WITH MASTER ESP32     */
{
  PS4.attach(notify);
  PS4.attachOnConnect(onConnect);
  PS4.attachOnDisconnect(onDisConnect);
  PS4.begin();
  Serial.println("Ready.");
}

void init_UART()
{
  // Start serial with platform baudrate/monitor speed
  Serial.begin(115200);
 
 // Initiate UART2 for Master EPS32
  Serial2.begin(115200, SERIAL_8N1, 16, 17);
}

void sendUART()
{
  Serial2.write(joystickValue[0]);
  Serial2.write(joystickValue[1]);
  Serial2.write(joystickValue[2]);
  Serial2.write(button1[0]);
  Serial2.write(button1[1]);
}

void checkInput() {
  if (PS4.isConnected())
  {
    // All accessible outputs from the controller
    // if (PS4.Right()) Serial.println("Right Button");
    // if (PS4.Down()) Serial.println("Down Button");
    // if (PS4.Up()) Serial.println("Up Button");
    // if (PS4.Left()) Serial.println("Left Button");

    // if (PS4.Square()) Serial.println("Square Button");
    // if (PS4.Cross()) Serial.println("Cross Button");
    // if (PS4.Circle()) Serial.println("Circle Button");
    // if (PS4.Triangle()) Serial.println("Triangle Button");

    // if (PS4.UpRight()) Serial.println("Up Right");
    // if (PS4.DownRight()) Serial.println("Down Right");
    // if (PS4.UpLeft()) Serial.println("Up Left");
    // if (PS4.DownLeft()) Serial.println("Down Left");

    if (PS4.L1())
    {
      Serial.println("L1 Button");
      button1[0] = 3;
    }
    else button1[0] = 0;

    if (PS4.R1())
    {
      Serial.println("R1 Button");
      button1[1] = 2;
    }
    else button1[1] = 0;

    // if (PS4.Share()) Serial.println("Share Button");
    // if (PS4.Options()) Serial.println("Options Button");
    // if (PS4.L3()) Serial.println("L3 Button");
    // if (PS4.R3()) Serial.println("R3 Button");

    // if (PS4.PSButton()) Serial.println("PS Button");
    // if (PS4.Touchpad()) Serial.println("Touch Pad Button");

    // if (PS4.L2()) Serial.printf("L2 button at %d\n", PS4.L2Value());
    // if (PS4.R2()) Serial.printf("R2 button at %d\n", PS4.R2Value());

    // if (PS4.LStickX())
    // {
    //   Serial.printf("Left Stick x at %d\n", PS4.LStickX());
    //   joystickValue[0] = PS4.LStickX();
    //   // int8_t LSX = PS4.LStickX();
    //   // joystick_sentData.joystick = LSX;
    //   // joystickUART();
    // }

    if (PS4.LStickY())
    {
      Serial.printf("Left Stick y at %d\n", PS4.LStickY());
      joystickValue[0] = PS4.LStickY();
    }

    if (PS4.RStickX())
    {
      Serial.printf("Right Stick x at %d\n", PS4.RStickX());
      joystickValue[1] = PS4.RStickX();
    }

    if (PS4.RStickY())
    {
      Serial.printf("Right Stick y at %d\n", PS4.RStickY());
      joystickValue[2] = PS4.RStickY();
    }

    // if (PS4.Charging()) Serial.println("The controller is charging");
    // if (PS4.Audio()) Serial.println("The controller has headphones attached");
    // if (PS4.Mic()) Serial.println("The controller has a mic attached");

    // Serial.printf("Battery Level : %d\n", PS4.Battery());

    // Serial.println();
    // This delay is to make the output more human readable
    // Remove it when you're not trying to see the output
    // delay(1000);
  }
}