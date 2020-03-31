//
// Created by Nicolas Varchavsky on 3/31/20.
//

#include "Ventilator.h"

Ventilator::Ventilator(Debug *debug, Board *board) {
    m_debug = debug;
    m_board = board;
    oxigen_intake = new ElectroValve(debug, board, "O2 intake", 11, OUTPUT);
}
