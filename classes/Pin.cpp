//
// Created by Nicolas Varchavsky on 3/31/20.
//

#include "Pin.h"

Pin::Pin(Debug *debug, Board *board, const char *name, int pin, int mode) {

}

void Pin::init() {
    m_debug->log("Initializing Pin");
    m_board->setPinMode(m_pin, m_mode);
}