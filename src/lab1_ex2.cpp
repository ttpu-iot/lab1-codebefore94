
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



// Exercise 2: Solution

/****************************************************/

void setup(void) {
    Serial.begin(115200);

    pinMode(GRN, OUTPUT);
    pinMode(BTN, INPUT);
}


/****************************************************/
void loop(void) {

    // Press BUTTON (D14) to toggle GREEN (D4).
    // Serial: Print GREEN=1 or GREEN=0 only when the state changes.

    static int prev_btn = LOW;
    static int state = LOW;

    int btn = digitalRead(BTN);  // reading CURRENT STATE of the BUTTON

    if (prev_btn == LOW && btn == HIGH){
        // Detected BUTTON PRESS event
        // this works only once when you press the button (until you release and press it again)

        state =! state;

        digitalWrite(GRN, state);

        if (state == HIGH){
            Serial.println("GREEN=1");
        }
        else{
            Serial.println("GREEN=0");
        }

        delay(200);
    }

    prev_btn = btn;
}

