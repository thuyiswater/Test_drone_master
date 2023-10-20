#include <Arduino.h>
#include <PS4Controller.h>
#include <HardwareSerial.h>

HardwareSerial SerialPort2(2);

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

void init_ps4(){
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

typedef struct{
  int8_t joystick;
} UART_sentMessage;

UART_sentMessage joystick_sentData;

int size_UART = sizeof(UART_sentMessage);

void send(const UART_sentMessage* joystickvalue)
{
  SerialPort2.write((const char*)joystickvalue, size_UART);  // 2 bytes.
}

void joystickUART()
{
  send(&joystick_sentData);
  Serial.println();
  delay(40);
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

    if (PS4.LStickX())
    {
      Serial.printf("Left Stick x at %d\n", PS4.LStickX());
      int8_t LSX = PS4.LStickX();
      joystick_sentData.joystick = LSX;
      joystickUART();
    }

    if (PS4.LStickY())
    {
      Serial.printf("Left Stick y at %d\n", PS4.LStickY());
      int8_t LSY = PS4.LStickY();
      joystick_sentData.joystick = LSY;
      joystickUART();
    }

    if (PS4.RStickX())
    {
      Serial.printf("Right Stick x at %d\n", PS4.RStickX());
      int8_t RSX = PS4.RStickX();
      joystick_sentData.joystick = RSX;
      joystickUART();
    }

    if (PS4.RStickY())
    {
      Serial.printf("Right Stick y at %d\n", PS4.RStickY());
      int8_t RSY = PS4.RStickY();
      joystick_sentData.joystick = RSY;
      joystickUART();
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