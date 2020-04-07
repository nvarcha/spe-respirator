//
// Created by Nicolas Varchavsky on 4/6/20.
//

#include "Arduino.h"
#include "Alarm.h"

void Alarm::warning(const char *format, ...) {
    char formatted_string[1000];

    va_list argptr;
    va_start(argptr, format);
    vsprintf(formatted_string, format, argptr);
    va_end(argptr);

    this->raise(formatted_string);
}

/**
 *
 * @param format
 * @param ...
 */
void Alarm::critical(const char *format, ...) {
    char formatted_string[1000];

    va_list argptr;
    va_start(argptr, format);
    vsprintf(formatted_string, format, argptr);
    va_end(argptr);

    this->raise(formatted_string);
}

/**
 * Raises an alarm
 * TODO: Implement whatever alarm type we want
 * @param text
 */
void Alarm::raise(const char *text) {
    // TODO: For now, debug
    m_debug->log(text);
}

Alarm::Alarm(Debug *debug) {
    m_debug = debug;
}
