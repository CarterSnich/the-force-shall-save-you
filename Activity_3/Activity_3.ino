#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
const int _delay = 500;

void setup()
{
  lcd.begin();
  lcd.backlight();
  lcd.print("Aia Jhernnie Daño");
  lcd.setCursor(0, 1);
  lcd.print("     BSIT AI-21  ");
  delay(1000);
}

void loop()
{
  for (int pos = 0; pos < 27; pos++) {
    lcd.scrollDisplayLeft();
    delay(_delay);
  }
}
