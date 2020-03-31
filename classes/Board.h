//
// Created by Nicolas Varchavsky on 3/31/20.
//

#ifndef VENTILATOR_BOARD_H
#define VENTILATOR_BOARD_H

#include "Arduino.h"

class Board {
public:
    void setPinMode(int pin, int mode);
};


#endif //VENTILATOR_BOARD_H
