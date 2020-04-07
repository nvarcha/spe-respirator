//
// Created by Nicolas Varchavsky on 4/6/20.
//

#ifndef VENTILATOR_PARAMETERS_H
#define VENTILATOR_PARAMETERS_H

/**
 * Handles all selectable parameters such as bpm, pressure, etc.
 */
class Parameters {
public:

    /**
     * Breaths per minute
     */
     float m_bpm = 12;
     float getBPM();
     void setBPM(float bpm);

};


#endif //VENTILATOR_PARAMETERS_H
