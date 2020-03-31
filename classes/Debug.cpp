//
// Created by Nicolas Varchavsky on 3/31/20.
//

#include "Arduino.h"
#include "Debug.h"

void Debug::initialize() {
#ifdef DEBUG
    // Initialize serial object
    Serial.begin(9600);
#endif
}

void Debug::log(const char *text) {
#ifdef DEBUG
    Serial.println(text);
#endif
}

void Debug::log(bool value) {
#ifdef DEBUG
    Serial.println(value);
#endif
}

void Debug::log(int value) {
#ifdef DEBUG
    Serial.println(value);
#endif
}

void Debug::flog(const char *format, ...) {
    char formatted_string[1000];

    va_list argptr;
    va_start(argptr, format);
    sprintf(formatted_string, format, argptr);
    va_end(argptr);

#ifdef DEBUG
    Serial.println(formatted_string);
#endif
}
