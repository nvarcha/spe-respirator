//
// Created by Nicolas Varchavsky on 3/31/20.
//

#ifndef VENTILATOR_ELECTROVALVE_H
#define VENTILATOR_ELECTROVALVE_H

#include "Board.h"
#include "Debug.h"

class ElectroValve {
public:
    ElectroValve(Debug *, Board *, const char *name, int pin, int mode);
    void init();
    void open();
    void close();
    bool isOpen();
private:
    Board *m_board;
    Debug *m_debug;
    bool m_opened;
    const char *m_name;
    int m_pin;
    int m_mode;
};


#endif //VENTILATOR_ELECTROVALVE_H
