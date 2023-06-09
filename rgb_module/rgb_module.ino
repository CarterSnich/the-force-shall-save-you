#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  // put your setup code here, to run once:
  
  Serial.begin(115200);
  Serial.setTimeout(0);

  lcd.init();
  lcd.backlight();
}

void loop() {
  // put your main code here, to run repeatedly:
  while (Serial.available() == 0) {}

  String teststr = Serial.readString();  //read until timeout
  teststr.trim(); // remove any \r \n whitespace at the end of the String
  lcdPrint(teststr);

  char color = teststr.charAt(0);
  int val = teststr.substring(1).toInt();
  lcdPrintInt(val);
  
  switch (color) {
    case 'r':
      analogWrite(3, val);
      break;

    case 'g':
      analogWrite(5, val);
      break;

    case 'b':
      analogWrite(6, val);
      break;
  }
}


void lcdPrint(String str) {
  lcd.setCursor(0, 0);
  lcd.print("                ");
  lcd.setCursor(0, 0);
  lcd.print(str);
}


void lcdPrintChar(char* str) {
  lcd.setCursor(0, 0);
  lcd.print("                ");
  lcd.setCursor(0, 0);
  lcd.print(str);
}

void lcdPrintInt(int str) {
  lcd.setCursor(0, 0);
  lcd.print("                ");
  lcd.setCursor(0, 0);
  lcd.print(str);
}
