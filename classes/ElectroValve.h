//
// Created by Nicolas Varchavsky on 3/31/20.
//

#ifndef VENTILATOR_ELECTROVALVE_H
#define VENTILATOR_ELECTROVALVE_H


class ElectroValve {
public:
    void open();
    void close();
    bool isOpen();
private:
    bool m_opened;
};


#endif //VENTILATOR_ELECTROVALVE_H
