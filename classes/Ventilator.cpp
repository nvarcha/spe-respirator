//
// Created by Nicolas Varchavsky on 3/31/20.
//

#include "Ventilator.h"

/**
 * Constructor
 * @param debug
 * @param board
 */
Ventilator::Ventilator(Debug *debug, Board *board) {
    m_debug = debug;
    m_board = board;
    oxigen_intake = nullptr;
    start_stop = nullptr;
    oxigen_intake_sensor = nullptr;
    m_diagnostic_errors = false;
}

/**
 * Initializes the ventilator class
 */
void Ventilator::init() {
    m_debug->log("Initializing Ventilator Class");
    oxigen_intake = new ElectroValve(m_debug, m_board, "O2 intake", 11, OUTPUT);
    oxigen_intake->init();

    start_stop = new StartStopInputButton(m_debug, m_board, "Start/Stop", 2, INPUT_PULLUP);
    start_stop->init();

    oxigen_intake_sensor = new AnalogInput(m_debug, m_board, "O2 intake Sensor", A5, INPUT);
    oxigen_intake_sensor->init();

    m_debug->log("Ventilator initialization done");
}

/**
 * Main loop called from Arduino's cycle
 */
void Ventilator::loop() {
    if (m_diagnostic_errors) {
        return;
    }

    if (!start_stop->IsOn()) {
        return;
    }

    m_debug->log("Start stop? %d", start_stop->IsOn());

    // TEMP
    oxigen_intake->open();
    m_board->sleep(1000);
    oxigen_intake->close();
    m_board->sleep(1000);
    m_debug->log("Intake: %d", oxigen_intake_sensor->getValue());
}

/**
 * Executes a full diagnostic loop
 * @return true if all ok, false if any error
 */
bool Ventilator::runDiagnostics() {
    m_debug->log("Starting diagnostics");
    m_diagnostic_errors = false;

    // TEST O2 intake
    // Open O2 valve and wait
    oxigen_intake->open();
    m_board->sleep(1000);

    // Check O2 flowmeter
    if (oxigen_intake_sensor->getValue() >= 300) {
        // If not, alert (sound, email, whatever)
        m_debug->log("****** ERROR: O2 FLOW CONTROL NOT POSITIVE ******");
        m_diagnostic_errors = true;
    }

    // Close O2 valve
    oxigen_intake->close();

    // TODO: For whatever reason, calling m_debug->log inside the `if` breaks everything... WTF?
    if (m_diagnostic_errors) {
//        m_debug->log("Diagnostic errors detected. Cannot start. Read the log and fix");
    }

    m_debug->log("Diagnostics finished. Result: %d", m_diagnostic_errors);
    return m_diagnostic_errors;
}

/**
 * Returns whether there were diagnostic errors during the diagnostic tests
 * @return
 */
bool Ventilator::HasDiagnosticErrors() {
    return m_diagnostic_errors;
}
