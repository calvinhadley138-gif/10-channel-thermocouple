/*
  ============================================================
  10 Thermocouple Reader - MAX6675 (Single Shared Bus)
  ============================================================
  WIRING GUIDE:

  All 10 MAX6675 boards share the same SCK and SO lines
  (and power), but each board still has its own individual
  CS pin.

  SHARED (connect all 10 boards to these):
    - SCK -> Arduino Pin 6
    - SO  -> Arduino Pin 4
    - VCC -> Arduino 5V
    - GND -> Arduino GND

  INDIVIDUAL CS PINS:
    Thermocouple 1  -> CS -> Pin 2
    Thermocouple 2  -> CS -> Pin 3
    Thermocouple 3  -> CS -> Pin 5
    Thermocouple 4  -> CS -> Pin 7
    Thermocouple 5  -> CS -> Pin 8
    Thermocouple 6  -> CS -> Pin A2
    Thermocouple 7  -> CS -> Pin A3
    Thermocouple 8  -> CS -> Pin A4
    Thermocouple 9  -> CS -> Pin A0
    Thermocouple 10 -> CS -> Pin A1

  NOTE: Only 12 pins are used in total now (2 shared + 10 CS).
  Pins 9, 10, and 13 are now free for other use.

  IF READINGS ARE INVERTED (temp goes up in ice water, down on
  a hot surface): swap the two thermocouple wire leads at the
  MAX6675 input terminals. This is a thermocouple polarity
  issue, not a code/wiring-of-the-board issue.
  ============================================================
*/

#include "max6675.h"

// ---- Shared SPI bus pins ----
int thermoSO  = 4;   // SO  - shared by all boards
int thermoCLK = 7;   // SCK - shared by all boards

// ---- Individual CS pins ----
int thermoCS1  = 2;
int thermoCS2  = 3;
int thermoCS3  = 5;
int thermoCS4  = 8;
int thermoCS5  = 10;
int thermoCS6  = A2;
int thermoCS7  = A3;
int thermoCS8  = A4;
int thermoCS9  = A0;
int thermoCS10 = A1;

MAX6675 thermocouple1(thermoCLK, thermoCS1, thermoSO);
MAX6675 thermocouple2(thermoCLK, thermoCS2, thermoSO);
MAX6675 thermocouple3(thermoCLK, thermoCS3, thermoSO);
MAX6675 thermocouple4(thermoCLK, thermoCS4, thermoSO);
MAX6675 thermocouple5(thermoCLK, thermoCS5, thermoSO);
MAX6675 thermocouple6(thermoCLK, thermoCS6, thermoSO);
MAX6675 thermocouple7(thermoCLK, thermoCS7, thermoSO);
MAX6675 thermocouple8(thermoCLK, thermoCS8, thermoSO);
MAX6675 thermocouple9(thermoCLK, thermoCS9, thermoSO);
MAX6675 thermocouple10(thermoCLK, thermoCS10, thermoSO);

void setup() {
  Serial.begin(9600);
  Serial.println("10 Thermocouple Test (Single Shared Bus)");

  // All CS pins idle HIGH (not selected) before MAX6675 library takes over
  pinMode(thermoCS1, OUTPUT);  digitalWrite(thermoCS1, HIGH);
  pinMode(thermoCS2, OUTPUT);  digitalWrite(thermoCS2, HIGH);
  pinMode(thermoCS3, OUTPUT);  digitalWrite(thermoCS3, HIGH);
  pinMode(thermoCS4, OUTPUT);  digitalWrite(thermoCS4, HIGH);
  pinMode(thermoCS5, OUTPUT);  digitalWrite(thermoCS5, HIGH);
  pinMode(thermoCS6, OUTPUT);  digitalWrite(thermoCS6, HIGH);
  pinMode(thermoCS7, OUTPUT);  digitalWrite(thermoCS7, HIGH);
  pinMode(thermoCS8, OUTPUT);  digitalWrite(thermoCS8, HIGH);
  pinMode(thermoCS9, OUTPUT);  digitalWrite(thermoCS9, HIGH);
  pinMode(thermoCS10, OUTPUT); digitalWrite(thermoCS10, HIGH);

  delay(500);
}

void loop() {
  Serial.print("TC1 F = ");  Serial.println(thermocouple1.readFahrenheit());
  Serial.print("TC2 F = ");  Serial.println(thermocouple2.readFahrenheit());
  Serial.print("TC3 F = ");  Serial.println(thermocouple3.readFahrenheit());
  Serial.print("TC4 F = ");  Serial.println(thermocouple4.readFahrenheit());
  Serial.print("TC5 F = ");  Serial.println(thermocouple5.readFahrenheit());
  Serial.print("TC6 F = ");  Serial.println(thermocouple6.readFahrenheit());
  Serial.print("TC7 F = ");  Serial.println(thermocouple7.readFahrenheit());
  Serial.print("TC8 F = ");  Serial.println(thermocouple8.readFahrenheit());
  Serial.print("TC9 F = ");  Serial.println(thermocouple9.readFahrenheit());
  Serial.print("TC10 F = "); Serial.println(thermocouple10.readFahrenheit());
  Serial.println("==========");

  delay(1000);
}
