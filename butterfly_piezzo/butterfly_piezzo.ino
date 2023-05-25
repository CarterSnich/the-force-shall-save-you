
// contants
const int buzzPin = 7;
const int ledPin = 5;

// notes
const float C4sharpM = 277.18;
const float E4M = 329.63;
const float F4sharpM = 369.99;
const float G4sharpM = 415.30;
const float B4M = 493.88;
const float C5sharpM = 554.37;
const float E5M = 659.26;

void setup () {
    pinMode(buzzPin, OUTPUT);
    pinMode(ledPin, OUTPUT);
}

void loop() {
    addMelody(G4sharpM, 500, 100);

    addMelody(G4sharpM, 200, 50);

    addMelody(B4M, 200, 50);

    addMelody(C5sharpM, 500, 50);


    addMelody(G4sharpM, 200, 50);

    addMelody(B4M, 200, 50);

    addMelody(C5sharpM, 200, 50);

    addMelody(E5M, 200, 50);


    addMelody(C5sharpM, 200, 50);

    addMelody(B4M, 200, 50);

    addMelody(G4sharpM, 800, 50);


    addMelody(F4sharpM, 500, 100);

    addMelody(F4sharpM, 200, 50);

    addMelody(G4sharpM, 200, 50);

    addMelody(B4M, 500, 100);


    addMelody(F4sharpM, 200, 50);

    addMelody(E4M, 200, 50);

    addMelody(F4sharpM, 200, 50);

    addMelody(G4sharpM, 200, 50);


    addMelody(F4sharpM, 200, 50);

    addMelody(E4M, 200, 50);

    addMelody(C4sharpM, 1000, 0);

    delay(1000);
}
/*
 * float note The frequency passed to `tone()` function.
 * int duration Duration of the tone.
 * int delayAfter Duration of mute after the tone.
 */
void addMelody(float note, int duration, int delayAfter) {
    digitalWrite(ledPin, HIGH);
    tone(buzzPin, note);
    delay(duration);

    digitalWrite(ledPin, LOW);
    noTone(buzzPin);
    if (delayAfter > 0) delay(delayAfter);
}
