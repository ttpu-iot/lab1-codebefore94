
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


// Exercise 4: Solution

void printLedColor(String color);

void turn_on_led(int ledcolor);

/****************************************************/
void setup(void) {
    Serial.begin(115200);

    pinMode(RED, OUTPUT);
    pinMode(GRN, OUTPUT);
    pinMode(BLU, OUTPUT);
    pinMode(YLW, OUTPUT);
}

/****************************************************/
void loop(void) {

    // read analog sensor
    int val = analogRead(LSR);

    if (val >= 0 && val <= 1023){
        // turn ON - BLUE led
        turn_on_led(2);

        printLedColor("BLUE");
    }
    else if (val >= 1024 && val <= 2047){
        // turn ON - GREEN led
        turn_on_led(3);

        printLedColor("GREEN");
    }
    else if (val >= 2048 && val <= 3071){
        // turn ON - YELLOW led
        turn_on_led(4);

        printLedColor("YELLOW");
    }
    else if (val >= 3072 && val <= 4095){
        // turn ON - RED led
        turn_on_led(1);

        printLedColor("RED");
    }
    else {
        // turn OFF all
        turn_on_led(0);
    }

    delay(500);
}

// Print Color String (only ONCE)
void printLedColor(String color)
{
    static String prevColor = "";

    if (color != prevColor){
        Serial.println(color);
        prevColor = color;
    }
}

// Turn on specific color LED only
void turn_on_led(int ledcolor)
{
    // red=1, blue=2, green=3, yellow=4
    int stateRed=LOW, stateBlu=LOW, stateGrn=LOW, stateYlw=LOW;

    if (ledcolor == 1){
        stateRed = HIGH;
    }
    else if (ledcolor == 2){
        stateBlu = HIGH;
    }
    else if (ledcolor == 3){
        stateGrn = HIGH;
    }
    else if (ledcolor == 4){
        stateYlw = HIGH;
    }

    digitalWrite(RED, stateRed);
    digitalWrite(BLU, stateBlu);
    digitalWrite(GRN, stateGrn);
    digitalWrite(YLW, stateYlw);
}

