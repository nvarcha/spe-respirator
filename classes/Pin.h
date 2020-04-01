//
// Created by Nicolas Varchavsky on 3/31/20.
//

#ifndef VENTILATOR_PIN_H
#define VENTILATOR_PIN_H

#include "Board.h"
#include "Debug.h"

/**
 * Main class representing each Board's pin
 * Most importantly, a pin number and a mode
 */
class Pin {
public:
    Pin(Debug *debug, Board *board, const char *name, uint8_t pin, uint8_t mode);
    virtual void init();

protected:
    Board *m_board;
    Debug *m_debug;
    const char *m_name;
    int m_pin;
    int m_mode;

private:
};

#endif //VENTILATOR_PIN_H
