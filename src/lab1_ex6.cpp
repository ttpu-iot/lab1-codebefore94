
// RED - D15
// Green - D4
// Blue - D22
// Yellow - D23

// button - D14
// light sensor - D33

#include "Arduino.h"

#define RED 15
#define GRN 4
#define BLU 22
#define YLW 23

#define BTN 14  // button port
#define LSR 33  // light sensor port


// Exercise 6: Solution

/****************************************************/
void setup(void) {
    Serial.begin(115200);

    pinMode(BLU, OUTPUT);
    pinMode(GRN, OUTPUT);
    pinMode(YLW, OUTPUT);
    pinMode(RED, OUTPUT);
}

/****************************************************/
void loop(void) {

    char msg = 0;

    if (Serial.available() > 0){
        msg = Serial.read();

        Serial.write(msg);
    }

    if (msg == 'B') {
        digitalWrite(BLU, HIGH);
    }
    else if (msg == 'b') {
        digitalWrite(BLU, LOW);
    }
    else if (msg == 'G') {
        digitalWrite(GRN, HIGH);
    }
    else if (msg == 'g') {
        digitalWrite(GRN, LOW);
    }
    else if (msg == 'Y') {
        digitalWrite(YLW, HIGH);
    }
    else if (msg == 'y') {
        digitalWrite(YLW, LOW);
    }
    else if (msg == 'R') {
        digitalWrite(RED, HIGH);
    }
    else if (msg == 'r') {
        digitalWrite(RED, LOW);
    }

}