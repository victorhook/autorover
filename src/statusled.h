#ifndef STATUS_LED_H
#define STATUS_LED_H


#include "main.h"


class StatusLed
{
    public:
        StatusLed(const uint8_t pin);
        bool init();
        void toggle();
        void set(uint8_t value);
        void blink(const uint16_t duration, const int cycles);
        bool isOn();

    private:
        const uint8_t m_pin;
        uint8_t       m_value;
};


#endif /* STATUS_LED_H */
