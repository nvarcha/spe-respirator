//
// Created by Nicolas Varchavsky on 3/31/20.
//

#ifndef VENTILATOR_VENTILATOR_H
#define VENTILATOR_VENTILATOR_H

#include "ElectroValve.h"
#include "InputButton.h"
#include "Debug.h"
#include "StartStopInputButton.h"
#include "AnalogInput.h"

/**
 * Main Ventilator class. Represents the ventilator in its
 * entirety
 */
class Ventilator {
public:
    Ventilator(Debug *debug, Board *board);
    void init();

    /**
     * Executes a full diagnostic loop
     * @return true if all ok, false if any error
     */
    bool runDiagnostics();

    /**
     * Main loop called from Arduino's cycle
     */
    void loop();

    bool HasDiagnosticErrors();

    // Parts
    ElectroValve *oxigen_intake;
    AnalogInput *oxigen_intake_sensor;
    StartStopInputButton *start_stop;

private:
    Board *m_board;
    Debug *m_debug;
    bool m_diagnostic_errors;
};


#endif //VENTILATOR_VENTILATOR_H
