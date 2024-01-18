#ifndef RGB_LED_H
#define RGB_LED_H

#include "main.h"
#include <FastLED.h>


#define NBR_OF_RGB_LEDS 4

#define COLOR_RED   0xFF0000
#define COLOR_GREEN 0x00FF00
#define COLOR_BLUE  0x0000FF
#define COLOR_WHITE 0xFFFFFF


class RGB_Led
{
    public:
        RGB_Led();
        bool init();
        void setFront(const uint32_t color);
        void setBack(const uint32_t color);
        void setBrightness(const float brightness);

    private:
        const uint8_t   m_pin;
        CRGB            m_leds[NBR_OF_RGB_LEDS];

};


#endif /* RGB_LED_H */
