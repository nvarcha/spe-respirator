//
// Created by Nicolas Varchavsky on 3/31/20.
//

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
ElectroValve::ElectroValve(Debug *debug, Board *board, const char *name, int pin, int mode) : Pin(debug, board, name,
                                                                                                  pin, mode) {
}

/**
 * Initializes the class
 */
void ElectroValve::init() {
    m_debug->log("Initializing Electrovalve %s", m_name);
    Pin::init();
    m_board->setPinMode(m_pin, m_mode);
}

/**
 * Closes the valve
 */
void ElectroValve::close() {
    m_opened = false;
}

/**
 * Opens the valve
 */
void ElectroValve::open() {
    m_opened = true;
}

/**
 * Checks if the valve is open or closed. True if its opened, false if closed.
 * @return
 */
bool ElectroValve::isOpen() {
    return m_opened;
}
