//
// Created by Nicolas Varchavsky on 3/31/20.
//

#ifndef VENTILATOR_ELECTROVALVE_H
#define VENTILATOR_ELECTROVALVE_H

#include "Parameters.h"
#include "Board.h"
#include "Debug.h"
#include "Pin.h"

/**
 * Represents an ElectroValve connected to a pin
 */
class ElectroValve : public Pin {
public:
    ElectroValve(Parameters* parameters, Debug *debug, Board *board, const char *name, uint8_t pin, uint8_t mode);
    void init() override;
    void open();
    void update();

    /**
     * Open the electrovalve for the given amount of milliseconds
     * and then automatically closes it after the given tie
     * @param millis
     */
    void openFor(unsigned long millisToOpenFor);

    void close() volatile;
    bool isOpen();

private:
    bool m_opened{};
    unsigned long m_openFor;
    unsigned long m_openTime;
};


#endif //VENTILATOR_ELECTROVALVE_H
