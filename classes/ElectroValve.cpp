//
// Created by Nicolas Varchavsky on 3/31/20.
//

#include "ElectroValve.h"
#include "Board.h"
#include "Debug.h"

void ElectroValve::close() {
    m_opened = false;
}

void ElectroValve::open() {
    m_opened = true;
}

bool ElectroValve::isOpen() {
    return m_opened;
}

void ElectroValve::init() {
    m_debug->log(m_name);
    m_debug->flog("Initializing Electrovalve %s", m_name);
    Pin::m_board->setPinMode(m_pin, m_mode);
}

ElectroValve::ElectroValve(Debug *debug, Board *board, const char *name, int pin, int mode) : Pin(debug, board, name,
                                                                                                  pin, mode) {

}
