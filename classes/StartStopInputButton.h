//
// Created by Nicolas Varchavsky on 3/31/20.
//

#ifndef VENTILATOR_STARTSTOPINPUTBUTTON_H
#define VENTILATOR_STARTSTOPINPUTBUTTON_H

#include "InputButton.h"
#include "Debug.h"

class StartStopInputButton : public InputButton {
public:
    StartStopInputButton(Debug *debug, Board *board, const char *name, uint8_t pin, uint8_t mode);
    void init();
    void interruptMethod();
    bool IsOn();

protected:
    bool m_poweredOn = false;
};


#endif //VENTILATOR_STARTSTOPINPUTBUTTON_H
