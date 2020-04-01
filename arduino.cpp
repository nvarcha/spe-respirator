#include <Arduino.h>
#include "classes/Ventilator.h"
#include "classes/ElectroValve.h"
#include "classes/Debug.h"

Debug debug;
Board board;
Ventilator ventilator(&debug, &board);
//ElectroValve electroValve(&board, "O2 intake", 11, OUTPUT);

/**
 * Arduino setup - runs only once
 * This is where everything begins, like the `main` function
 */
void setup() {
    debug.init();
    debug.log("******************************************************************");
    debug.log("******************************************************************");
    debug.log("Initializing Project - Ventilator - v0.1.0");
    debug.log("https://nvarcha@bitbucket.org/nvarcha/ventilator.git");
    debug.log("******************************************************************");
    debug.log("******************************************************************");

    // Initialize
    ventilator.init();

    // Run diagnostics
    ventilator.runDiagnostics();

    //ventilator.oxigen_intake = ElectroValve(&debug, &board, "O2 intake", 11, OUTPUT);
    // Configure the following pins as output pins
    //pinMode(ev1_o2_in, OUTPUT);

    // Configure the following pins as input pins
    // INPUT_PULLUP inverts the behaviour so HIGH means off and LOW means on
    //pinMode(pin_start_stop_button, INPUT_PULLUP);

    // Configure interrupt to read on/off button
    //attachInterrupt(digitalPinToInterrupt(pin_start_stop_button), togglePower, CHANGE);
}

/**
 * Arduino main loop, called repeatedly
 */
void loop() {
    ventilator.loop();
}

