//
// Created by Nicolas Varchavsky on 4/1/20.
//

#ifndef VENTILATOR_ANALOGINPUT_H
#define VENTILATOR_ANALOGINPUT_H

#include "Pin.h"

/**
 * Represents any peripheral connected that reads
 * an analog value, such as a Flowmeter
 */
class AnalogInput : public Pin {
public:
    AnalogInput(Debug *debug, Board *board, const char *name, uint8_t pin, uint8_t mode);
    void init() override;

    /**
     * Reads the value of the input
     * @return
     */
    int getValue();

private:
    int m_value;
};


#endif //VENTILATOR_ANALOGINPUT_H
