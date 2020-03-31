//
// Created by Nicolas Varchavsky on 3/31/20.
//

#ifndef VENTILATOR_INPUTBUTTON_H
#define VENTILATOR_INPUTBUTTON_H

#include "Pin.h"
#include "Debug.h"
#include "Board.h"

class InputButton : public Pin {
public:
    InputButton(Debug *, Board *, const char *name, int pin, int mode);
};


#endif //VENTILATOR_INPUTBUTTON_H
