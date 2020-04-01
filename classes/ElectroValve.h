//
// Created by Nicolas Varchavsky on 3/31/20.
//

#ifndef VENTILATOR_ELECTROVALVE_H
#define VENTILATOR_ELECTROVALVE_H

#include "Board.h"
#include "Debug.h"
#include "Pin.h"

/**
 * Represents an ElectroValve connected to a pin
 */
class ElectroValve : public Pin {
public:
    ElectroValve(Debug *debug, Board *board, const char *name, int pin, int mode);
    void init() override;
    void open();
    void close();
    bool isOpen();
private:
    bool m_opened;
};


#endif //VENTILATOR_ELECTROVALVE_H
