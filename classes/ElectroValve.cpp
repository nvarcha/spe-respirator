//
// Created by Nicolas Varchavsky on 3/31/20.
//

#include "ElectroValve.h"

bool m_opened = false;

void ElectroValve::close() {
    m_opened = false;
}

void ElectroValve::open() {
    m_opened = true;
}

bool ElectroValve::isOpen() {
    return m_opened;
}