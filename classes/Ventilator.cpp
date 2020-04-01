//
// Created by Nicolas Varchavsky on 3/31/20.
//

#include "Ventilator.h"

/**
 * Constructor
 * @param debug
 * @param board
 */
Ventilator::Ventilator(Debug *debug, Board *board) {
    m_debug = debug;
    m_board = board;
}

/**
 * Initializes the ventilator class
 */
void Ventilator::init() {
    m_debug->log("Initializing Ventilator Class");
    oxigen_intake = new ElectroValve(m_debug, m_board, "O2 intake", 11, OUTPUT);
    oxigen_intake->init();
}