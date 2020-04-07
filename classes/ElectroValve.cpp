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
ElectroValve::ElectroValve(Parameters* parameters, Debug *debug, Board *board, const char *name, uint8_t pin, uint8_t mode) : Pin(debug, board, name,
                                                                                                          pin, mode) {
}

/**
 * Initializes the class
 */
void ElectroValve::init() {
    m_debug->log("Initializing Electrovalve %s", m_name);
    Pin::init();
    this->close();
    m_openFor = 0;
}

/**
 * Closes the valve
 */
void ElectroValve::close() volatile {
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
void ElectroValve::openFor(unsigned long millisToOpenFor) {

    m_openFor = millisToOpenFor;
    m_openTime = millis();

    // Open
    this->open();
}

void ElectroValve::update() {
    // If this is running with `openFor`, check if we should close
    if (m_openFor > 0) {
        if (millis() - m_openTime >= m_openFor) {
            // Unflag
            m_openFor = 0;

            // Close
            this->close();
        }
    }
}
