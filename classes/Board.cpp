//
// Created by Nicolas Varchavsky on 3/31/20.
//

#include "Board.h"
#include "Arduino.h"

/**
 * Sets a pin's mode
 * @param pin
 * @param mode
 */
void Board::setPinMode(int pin, int mode) {
    pinMode(pin, mode);
}
