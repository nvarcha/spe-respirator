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
    void setPinMode(uint8_t pin, uint8_t mode);
    void setAttachInterrupt(uint8_t pin, void (*callback)(), uint8_t event);
    bool isPinLow(uint8_t pin);
    void setDigitalWrite(uint8_t pin, uint8_t mode);
    int getAnalogRead(uint8_t pin);

    /**
     * Delays execution (calls Arduino's delay)
     * @param ms
     */
    void sleep(unsigned long ms);
};


#endif //VENTILATOR_BOARD_H
