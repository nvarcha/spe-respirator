//
// Created by Nicolas Varchavsky on 3/31/20.
//

#ifndef VENTILATOR_DEBUG_H
#define VENTILATOR_DEBUG_H

// Comment to completely remove debug output log
#define DEBUG 1

/**
 * Debug class
 * Simple debug using Serial.println
 * It's wrapped inside an #ifdef DEBUG to easily remove outputs
 */
class Debug {
    public:
        void initialize();
        void log(const char *format);
        void flog(const char *format, ...);
        void log(bool);
        void log(int);
};

#endif //VENTILATOR_DEBUG_H
