//
// Created by Nicolas Varchavsky on 3/31/20.
//

#ifndef VENTILATOR_VENTILATOR_H
#define VENTILATOR_VENTILATOR_H

#include "ElectroValve.h"
#include "Debug.h"

/**
 * Main Ventilator class. Represents the ventilator in its
 * entirety
 */
class Ventilator {
public:
    Ventilator(Debug *debug, Board *board);
    void init();
    ElectroValve *oxigen_intake;
private:
    Board *m_board;
    Debug *m_debug;
};


#endif //VENTILATOR_VENTILATOR_H
