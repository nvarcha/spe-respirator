//
// Created by Nicolas Varchavsky on 3/31/20.
//

#ifndef VENTILATOR_ELECTROVALVE_H
#define VENTILATOR_ELECTROVALVE_H

#include "Parameters.h"
#include "Board.h"
#include "Debug.h"
#include "Pin.h"
#include "../modules/TimerOne-master/TimerOne.h"

/**
 * Represents an ElectroValve connected to a pin
 */
class ElectroValve : public Pin {
public:
    ElectroValve(Parameters* parameters, Debug *debug, Board *board, const char *name, uint8_t pin, uint8_t mode);
    void init() override;
    void open();

    /**
     * Open the electrovalve for the given amount of milliseconds
     * and then automatically closes it after the given tie
     * @param millis
     */
    void openFor(unsigned long millis);

    void close();
    bool isOpen();
private:
    bool m_opened;
    TimerOne m_timer1;
};


#endif //VENTILATOR_ELECTROVALVE_H
