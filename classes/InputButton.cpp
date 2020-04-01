//
// Created by Nicolas Varchavsky on 3/31/20.
//

#include "InputButton.h"

/**
 * Constructor
 * @param debug
 * @param board
 * @param name
 * @param pin
 * @param mode
 */
InputButton::InputButton(Debug *debug, Board *board, const char *name, int pin, int mode) : Pin(debug, board, name,
                                                                                                  pin, mode) {
}

/**
 * Initializes the class
 */
void InputButton::init() {
    m_debug->log("Initializing InputButton %s", m_name);
    Pin::init();
    m_board->setPinMode(m_pin, m_mode);
}

