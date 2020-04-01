//
// Created by Nicolas Varchavsky on 3/31/20.
//

#ifndef VENTILATOR_VENTILATOR_H
#define VENTILATOR_VENTILATOR_H

#include "ElectroValve.h"
#include "InputButton.h"
#include "Debug.h"
#include "StartStopInputButton.h"

/**
 * Main Ventilator class. Represents the ventilator in its
 * entirety
 */
class Ventilator {
public:
    Ventilator(Debug *debug, Board *board);
    void init();

    /**
     * Main loop called from Arduino's cycle
     */
    void loop();

    // Parts
    ElectroValve *oxigen_intake;
    StartStopInputButton *start_stop;

private:
    Board *m_board;
    Debug *m_debug;
};


#endif //VENTILATOR_VENTILATOR_H
