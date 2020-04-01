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
    debug.log("Initializing Project - Ventilator - v0.1.0");
    debug.log("https://nvarcha@bitbucket.org/nvarcha/ventilator.git");
    debug.log("******************************************************************");
    debug.log("******************************************************************");

    // Initialize
    ventilator.init();

    // Run diagnostics
    ventilator.runDiagnostics();
}

/**
 * Arduino main loop, called repeatedly
 */
void loop() {
    ventilator.loop();
}

