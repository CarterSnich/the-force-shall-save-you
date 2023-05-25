#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <IRremote.h>  //including infrared remote header file


LiquidCrystal_I2C lcd(0x27, 16, 2);
int RECV_PIN = 7;  // the pin where you connect the output pin of IR sensor
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn();
  lcd.init();
  lcd.backlight();
}

void loop() {
  if (irrecv.decode(&results)) {
    unsigned long IRval = results.value;
    if (IRval == 0xffffffff) {
      irrecv.resume();
      return;
    }
    lcd.setCursor(0, 0);
    lcd.println(results.value, HEX);
    Serial.println(results.value, HEX);
  
    irrecv.resume();
  }
}