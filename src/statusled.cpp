#include "statusled.h"


StatusLed::StatusLed(const uint8_t pin)
: m_pin(pin),
  m_value(0)
{

}

bool StatusLed::init()
{
    pinMode(m_pin, OUTPUT);
    return true;
}

void StatusLed::set(uint8_t value)
{
    m_value = value;
    digitalWrite(m_pin, m_value == 1 ? 1 : 0);
}

void StatusLed::toggle()
{
    set(!m_value);
}

bool StatusLed::isOn()
{
    return m_value == 1;
}

void StatusLed::blink(const uint16_t duration, const int cycles)
{
    for (int i = 0; i < cycles; i++)
    {
        toggle();
        delay(duration);
        toggle();
        delay(duration);
    }
}
