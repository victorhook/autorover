#include "rgbled.h"



RGB_Led::RGB_Led()
: m_pin(PIN_RGB_LED)
{

}

bool RGB_Led::init()
{
    FastLED.addLeds<NEOPIXEL, PIN_RGB_LED>(m_leds, NBR_OF_RGB_LEDS);  // GRB ordering is assumed
    return true;
}

void RGB_Led::setFront(const uint32_t color)
{
    m_leds[2] = color;
    m_leds[3] = color;
    FastLED.show();
}

void RGB_Led::setBack(const uint32_t color)
{
    m_leds[0] = color;
    m_leds[1] = color;
    FastLED.show();
}

void RGB_Led::setBrightness(const float brightness)
{
    FastLED.setBrightness((constrain(brightness, 0, 100) / 100.0) * 255);
    FastLED.show();
}
