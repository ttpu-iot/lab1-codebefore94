
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


// Exercise 3: Solution

/****************************************************/
void setup(void) {
    Serial.begin(115200);

    // no need to configure analog pins
}

/****************************************************/
void loop(void) {
    int val = analogRead(LSR); // this function will return 12-bit integer (unsigned) -> max 4095

    // print "raw = XXXX"
    static int counter = 0;

    Serial.print(counter++);
    Serial.print(") raw=");
    Serial.print(val);

    // convert to voltage (0 mV - 3300 mV)  (original raw value = 0 - 4095)

    // mapping
    int volt = map(val, 0, 4095, 0, 3300);

    Serial.print("; Volt=");
    Serial.print(volt);
    Serial.println(" mV");


    delay(500);
}

