//
// Created by Nicolas Varchavsky on 4/6/20.
//

#ifndef VENTILATOR_ALARM_H
#define VENTILATOR_ALARM_H

#include "Debug.h"

/**
 * Handles all methods to send out alarms
 */
class Alarm {
public:
    Alarm(Debug *debug);
    void warning(const char *format, ...);
    void critical(const char *format, ...);

private:
    void raise(const char *text);
    Debug *m_debug;
};


#endif //VENTILATOR_ALARM_H
