//
// Created by Nicolas Varchavsky on 3/31/20.
//

#ifndef VENTILATOR_INPUTBUTTON_H
#define VENTILATOR_INPUTBUTTON_H

#include "Board.h"
#include "Debug.h"
#include "Pin.h"

/**
 * Represents an Input button type of pin
 */
class InputButton : public Pin {
public:
    InputButton(Debug *debug, Board *board, const char *name, uint8_t pin, uint8_t mode);
    virtual void init(void (*callback)());

protected:
    void (*m_callback)(){};
};


#endif //VENTILATOR_INPUTBUTTON_H
