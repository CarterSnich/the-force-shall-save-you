#include <NewPing.h>

const int trig_pin = 14;
const int echo_pin = 12;
NewPing sonar(trig_pin, echo_pin, 200);  // sensor function

void setup() {
  Serial.begin(115200);
}

void loop() {
  Serial.println(sonar.ping_cm());
  delay(1000);
}
