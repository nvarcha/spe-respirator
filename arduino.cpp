#include <Arduino.h>
#include "classes/ElectroValve.h"
#include "classes/Debug.h"

Debug debug;
ElectroValve electroValve;

/**
 * Arduino setup - run only once
 * This is where everything begins, like the `main` function
 */
void setup() {
    debug.initialize();
    debug.log("Initializing Ventilator Project - v0.1.0");
    debug.log("https://github.com/nvarcha/respirator");

    // Configure the following pins as output pins
    pinMode(ev1_o2_in, OUTPUT);

    // Configure the following pins as input pins
    // INPUT_PULLUP inverts the behaviour so HIGH means off and LOW means on
    pinMode(pin_start_stop_button, INPUT_PULLUP);

    // Configure interrupt to read on/off button
    attachInterrupt(digitalPinToInterrupt(pin_start_stop_button), togglePower, CHANGE);
}

/**
 * Arduino main loop, called repeatedly
 */
void loop() {

}
