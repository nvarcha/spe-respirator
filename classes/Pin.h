//
// Created by Nicolas Varchavsky on 3/31/20.
//

#ifndef VENTILATOR_PIN_H
#define VENTILATOR_PIN_H

#include "Debug.h"
#include "Board.h"

class Pin {
public:
    Pin(Debug *debug, Board *board, const char *name, int pin, int mode);

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
