//
// Created by Nicolas Varchavsky on 3/31/20.
//

#include "Pin.h"

/**
 * Constructor
 * @param debug
 * @param board
 * @param name
 * @param pin
 * @param mode
 */
Pin::Pin(Debug *debug, Board *board, const char *name, int pin, int mode) {
    m_name = name;
    m_debug = debug;
    m_board = board;
    m_pin = pin;
    m_mode = mode;
}

/**
 * Initializes the pin
 */
void Pin::init() {
    m_debug->log("Initializing Pin %s", m_name);
    m_board->setPinMode(m_pin, m_mode);
}