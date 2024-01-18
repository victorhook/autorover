#ifndef PPM_H
#define PPM_H


#include "stdint.h"


#define PPM_CHANNELS 8

#define PPM_MIN_VALUE ((uint16_t) 588)
#define PPM_MAX_VALUE ((uint16_t) 1612)

#define PPM_OUT_MIN_VALUE ((uint16_t) 1000)
#define PPM_OUT_MAX_VALUE ((uint16_t) 2000)

class PPM
{
    public:
        bool init();
        PPM(const uint8_t pin);
        uint16_t ch(uint8_t channel);
        uint32_t getLastFrameReceivedTimestamp();
};


#endif /* PPM_H */
