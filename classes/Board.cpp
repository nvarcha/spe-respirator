//
// Created by Nicolas Varchavsky on 3/31/20.
//

#include "Board.h"
#include "Arduino.h"

/**
 * Sets a pin's mode
 * @param pin
 * @param mode
 */
void Board::setPinMode(uint8_t pin, uint8_t mode) {
    pinMode(pin, mode);
}

void Board::setAttachInterrupt(uint8_t pin, void (*callback)(), uint8_t event) {
    attachInterrupt(digitalPinToInterrupt(pin), callback, event);
}

bool Board::isPinLow(uint8_t pin) {
    return (digitalRead(pin) == LOW);
}

/**
 * Delays execution (calls Arduino's delay)
 * @param ms
 */
void Board::sleep(unsigned long ms) {
    delay(ms);
}

void Board::setDigitalWrite(uint8_t pin, uint8_t mode) {
    digitalWrite(pin, mode);
}
