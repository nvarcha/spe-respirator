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

ElectroValve::ElectroValve(Debug *debug, Board *board, const char *name, int pin, int mode) {
    m_name = name;
    m_pin = pin;
    m_mode = mode;
    m_board = board;
    m_debug = debug;
}

void ElectroValve::init() {
    m_debug->log("Initializing Electrovalve");
    m_board->setPinMode(m_pin, m_mode);
}
