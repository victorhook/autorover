#include "battery.h"


Battery::Battery(const uint8_t pin)
: m_pin(pin),
  m_scaler(0.01514792899408284) // Found experimentally
{

}

bool Battery::init()
{
    pinMode(m_pin, INPUT);
    return true;
}


void Battery::update()
{
    m_vbat_raw = analogRead(m_pin);
}

float Battery::getVoltage()
{
    return (float) m_vbat_raw * m_scaler;
}
