#include <Arduino.h>
#include "classes/Ventilator.h"
#include "classes/ElectroValve.h"
#include "classes/Debug.h"

Debug debug;
Board board;
Ventilator ventilator(&debug, &board);

/**
 * Arduino setup - runs only once
 * This is where everything begins, like the `main` function
 */
void setup() {
    debug.init();
    debug.log("******************************************************************");
    debug.log("******************************************************************");
    debug.log("Initializing Project - SPE Ventilator - v0.1.0");
    debug.log("https://github.com/nvarcha/spe-respirator");
    debug.log("******************************************************************");
    debug.log("******************************************************************");

    // Initialize
    ventilator.init();

    // Run diagnostics
    ventilator.runDiagnostics();
}

/**
 * Arduino main update, called repeatedly
 */
void loop() {
    ventilator.update();
}

