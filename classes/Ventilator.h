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
#include "Alarm.h"

/**
 * Main Ventilator class. Represents the ventilator in its
 * entirety
 */
class Ventilator {
public:
    Ventilator(Debug *debug, Board *board);
    void init();

    /**
     * Executes a full diagnostic run
     * @return true if all ok, false if any error
     */
    bool runDiagnostics();

    /**
     * Main update called from Arduino's cycle
     */
    void update();

    bool HasDiagnosticErrors();

    // Parts
    ElectroValve *oxigen_intake;
    AnalogInput *oxigen_intake_sensor;
    StartStopInputButton *start_stop;

private:
    Board *m_board;
    Debug *m_debug;
    Alarm *m_alarm;
    bool m_diagnostic_errors;

    int m_breaths_per_minute;

    // Indicates if this is the first run of the update
    bool m_first_run;
};


#endif //VENTILATOR_VENTILATOR_H
