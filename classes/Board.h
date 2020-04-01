//
// Created by Nicolas Varchavsky on 3/31/20.
//

#ifndef VENTILATOR_BOARD_H
#define VENTILATOR_BOARD_H

#include "Arduino.h"

/**
 * Represents the Arduino board interface
 */
class Board {
public:
    void setPinMode(int pin, int mode);
};


#endif //VENTILATOR_BOARD_H
