//
// Created by Nicolas Varchavsky on 3/31/20.
//

#include "StartStopInputButton.h"

volatile StartStopInputButton* startStopInputButton;

/**
 * This is a wrapper to be able to use the class' member method
 * as function pointer
 */
void interruptWrapper() {
    startStopInputButton->interruptMethod();
}

void StartStopInputButton::init() {
    m_debug->log("Initializing Start/Stop button");
    InputButton::init(interruptWrapper);
}

void StartStopInputButton::interruptMethod() volatile {
    m_debug->log("Calling interrupt method. Is Powered before? %d", m_poweredOn);
    m_poweredOn = m_board->isPinLow(m_pin);
    m_debug->log("Is Powered after? %d", m_poweredOn);
}

StartStopInputButton::StartStopInputButton(Debug *debug, Board *board, const char *name, uint8_t pin, uint8_t mode)
        : InputButton(debug, board, name, pin, mode) {
    startStopInputButton = this;
}

bool StartStopInputButton::IsOn() {
    return m_poweredOn;
}
