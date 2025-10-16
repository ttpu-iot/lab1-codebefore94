
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


// Exercise 5: Solution

void flash_yellow(int duration_ms);

/****************************************************/
void setup(void) {
    Serial.begin(115200);

    pinMode(YLW, OUTPUT);

    pinMode(BTN, INPUT);
}

/****************************************************/
void loop(void) {

    // detect button press
    static int prev_btn = LOW;

    int btn = digitalRead(BTN);

    if (prev_btn == LOW && btn == HIGH){
        // button press detected
        int val = analogRead(LSR);

        Serial.print("snapshot=");
        Serial.println(val);

        flash_yellow(1000);
    }

    prev_btn = btn;
}

// flash yellow led for a given duration
void flash_yellow(int duration_ms)
{
    uint32_t starttime = millis();
    uint32_t timediff = 0;

    while(timediff < duration_ms){
        digitalWrite(YLW, HIGH);
        delay(100);
        digitalWrite(YLW, LOW);
        delay(300);

        timediff = millis() - starttime;
    }
}
