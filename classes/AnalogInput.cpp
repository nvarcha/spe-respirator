//
// Created by Nicolas Varchavsky on 4/1/20.
//

#include "AnalogInput.h"

/**
 * Constructor
 * @param debug
 * @param board
 * @param name
 * @param pin
 * @param mode
 */
AnalogInput::AnalogInput(Debug *debug, Board *board, const char *name, uint8_t pin, uint8_t mode) : Pin(debug, board, name, pin, mode) {

}

void AnalogInput::init() {
    m_debug->log("Initializing Analog Input %s", m_name);
    Pin::init();
}

/**
 * Reads the value of the input
 * @return
 */
int AnalogInput::getValue() {
    m_value = m_board->getAnalogRead(m_pin);
    return m_value;
}
