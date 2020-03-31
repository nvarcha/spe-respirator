//
// Created by Nicolas Varchavsky on 3/31/20.
//

#include "Ventilator.h"

Ventilator::Ventilator(Debug *debug, Board *board) {
    m_debug = debug;
    m_board = board;
}

void Ventilator::init() {
    m_debug->log("Initializing Class Ventilator");
    oxigen_intake = new ElectroValve(m_debug, m_board, "O2 intake", 11, OUTPUT);
    oxigen_intake->init();
}