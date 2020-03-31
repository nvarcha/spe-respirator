//
// Created by Nicolas Varchavsky on 3/31/20.
//

#include "Board.h"
#include "Arduino.h"

void Board::setPinMode(int pin, int mode) {
    pinMode(pin, mode);
}
