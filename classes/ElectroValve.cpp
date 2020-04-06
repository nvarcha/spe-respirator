//
// Created by Nicolas Varchavsky on 3/31/20.
//

#include "Arduino.h"
#include "ElectroValve.h"
#include "Board.h"
#include "Debug.h"

/**
 * Constructor
 * @param debug
 * @param board
 * @param name
 * @param pin
 * @param mode
 */
ElectroValve::ElectroValve(Debug *debug, Board *board, const char *name, uint8_t pin, uint8_t mode) : Pin(debug, board, name,
                                                                                                          pin, mode) {
}

/**
 * Initializes the class
 */
void ElectroValve::init() {
    m_debug->log("Initializing Electrovalve %s", m_name);
    Pin::init();
    this->close();
}

/**
 * Closes the valve
 */
void ElectroValve::close() {
    m_debug->log("Closing EV %s", m_name);
    m_board->setDigitalWrite(m_pin, LOW);
    m_opened = false;
}

/**
 * Opens the valve
 */
void ElectroValve::open() {
    m_debug->log("Opening EV %s", m_name);
    m_board->setDigitalWrite(m_pin, HIGH);
    m_opened = true;
}

/**
 * Checks if the valve is open or closed. True if its opened, false if closed.
 * @return
 */
bool ElectroValve::isOpen() {
    return m_opened;
}

/**
 * Open the electrovalve for the given amount of milliseconds
 * and then automatically closes it after the given tie
 * @param millis
 */
void ElectroValve::openFor(unsigned long millis) {
    // Attach interrupt on timer to close

    // Open
    this->open();
}
