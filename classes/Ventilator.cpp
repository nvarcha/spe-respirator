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
}

/**
 * Main loop called from Arduino's cycle
 */
void Ventilator::loop() {
    if (!start_stop->IsOn()) {
        return;
    }

    // TEMP
    oxigen_intake->open();
    m_board->sleep(1000);
    oxigen_intake->close();
    m_board->sleep(1000);
    m_debug->log("Intake: %d", oxigen_intake_sensor->getValue());
}
