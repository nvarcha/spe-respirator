//
// Created by Nicolas Varchavsky on 3/31/20.
//

#include "Arduino.h"
#include "Debug.h"

/**
 * Initializes the class
 */
void Debug::init() {
#ifdef DEBUG
    // Initialize serial object
    Serial.begin(9600);
#endif
}

/**
 * Logs with a bool
 * @param value
 */
void Debug::log(bool value) {
#ifdef DEBUG
    Serial.println(value);
#endif
}

/**
 * Logs an int value
 * @param value
 */
void Debug::log(int value) {
#ifdef DEBUG
    Serial.println(value);
#endif
}

/**
 * Logs with a printf format style
 * @param format
 * @param ...
 */
void Debug::log(const char *format, ...) {
    char formatted_string[1000];

    va_list argptr;
    va_start(argptr, format);
    vsprintf(formatted_string, format, argptr);
    va_end(argptr);

#ifdef DEBUG
    Serial.println(formatted_string);
#endif
}
