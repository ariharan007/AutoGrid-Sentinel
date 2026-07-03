#include <LiquidCrystal.h>

LiquidCrystal lcd(13, 12, 11, 10, 9, 8);

const int Main_Check = A0;
const int Main_Relay = A1;
const int Gen_Relay  = A2;

void setup()
{
  pinMode(Main_Relay, OUTPUT);
  pinMode(Gen_Relay, OUTPUT);

  lcd.begin(20, 4);

  lcd.setCursor(0, 0);
  lcd.print("   AUTO TRANSFER ");
  lcd.setCursor(0, 1);
  lcd.print("      SWITCH  ");
}

void loop()
{
  int sensorValue = analogRead(Main_Check);

  float arduinoVoltage = sensorValue * 5.0 / 1023.0;
  float mainVoltage = arduinoVoltage * 5.0;

  if (mainVoltage >= 8.0)
  {
    // MAIN AVAILABLE
    digitalWrite(Main_Relay, HIGH);
    digitalWrite(Gen_Relay, LOW);

    lcd.setCursor(0, 2);
    lcd.print("MAIN SUPPLY: ON   ");
    lcd.setCursor(0, 3);
    lcd.print("GENERATOR : OFF   ");
  }
  else
  {
    // MAIN FAILED
    digitalWrite(Main_Relay, LOW);
    digitalWrite(Gen_Relay, HIGH);

    lcd.setCursor(0, 2);
    lcd.print("MAIN SUPPLY: OFF  ");
    lcd.setCursor(0, 3);
    lcd.print("GENERATOR : ON    ");
  }

  delay(200);
}
