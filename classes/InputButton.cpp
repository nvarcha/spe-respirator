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
InputButton::InputButton(Debug *debug, Board *board, const char *name, uint8_t pin, uint8_t mode) : Pin(debug, board, name,
                                                                                                        pin, mode) {
}

/**
 * Initializes the class
 */
void InputButton::init(void (*func)()) {
    m_debug->log("Initializing InputButton %s", m_name);
    m_callback = func;
    Pin::init();
    m_board->setAttachInterrupt(m_pin, m_callback, CHANGE);
}

//void InputButton::init() {
//    m_debug->log("Initializing InputButton %s", m_name);
//    Pin::init();
//}

