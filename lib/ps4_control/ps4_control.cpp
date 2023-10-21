#include <Arduino.h>
#include <PS4Controller.h>
#include <HardwareSerial.h>
#include <PS4_control.h>

HardwareSerial SerialPort2(2);

int8_t joystickValue[3];

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
  SerialPort2.begin(115200, SERIAL_8N1, 16, 17);
}

// UART_sentMessage joystick_sentData;

// void send(const UART_sentMessage* joystickvalue)
// {
//   SerialPort2.write((const char*)joystickvalue, sizeof(UART_sentMessage));  // 2 bytes.
// }

// void joystickUART() /*     SENDING JOYSTICK VALUES TO MIDDLE ESP32 THROUGH UART COMMUNICATION     */
// {
//   send(&joystick_sentData);
//   Serial.println();
//   delay(1000);
// }
void send()
{
  SerialPort2.write(joystickValue[0]);
  delay(10);
  SerialPort2.write(joystickValue[1]);
  delay(10);
  SerialPort2.write(joystickValue[2]);
  delay(10);
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

    // if (PS4.L1()) Serial.println("L1 Button");
    // if (PS4.R1()) Serial.println("R1 Button");

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
    //   int8_t LSX = PS4.LStickX();
    //   joystick_sentData.joystick = LSX;
    //   joystickUART();
    // }

    if (PS4.LStickY())
    {
      Serial.printf("Left Stick y at %d\n", PS4.LStickY());
      joystickValue[0] = PS4.LStickY();
      // int8_t LSY = PS4.LStickY();
      // joystick_sentData.LJSY = LSY;
      // joystickUART();
    }

    if (PS4.RStickX())
    {
      Serial.printf("Right Stick x at %d\n", PS4.RStickX());
      joystickValue[1] = PS4.RStickX();
      // int8_t RSX = PS4.RStickX();
      // joystick_sentData.RJSX = RSX;
      // joystickUART();
    }

    if (PS4.RStickY())
    {
      Serial.printf("Right Stick y at %d\n", PS4.RStickY());
      joystickValue[2] = PS4.RStickY();
      // int8_t RSY = PS4.RStickY();
      // joystick_sentData.RJSY = RSY;
      // joystickUART();
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