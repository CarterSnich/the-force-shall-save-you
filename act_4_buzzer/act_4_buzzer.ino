
// contants
const int buzzPin = 12;
const int ledPin = 13;


void setup () {
    pinMode(buzzPin, OUTPUT);
    pinMode(ledPin, OUTPUT);
}

void loop() {
    digitalWrite(ledPin, HIGH);
    tone(buzzPin, 523.25); // C5 note
    delay(500);

    digitalWrite(ledPin, LOW);
    noTone(buzzPin);
    delay(500);
}
