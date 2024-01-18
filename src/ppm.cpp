#include "ppm.h"

#include "Arduino.h"


uint8_t pin;
uint32_t lastLow;
uint32_t lastHigh;
uint8_t current_ppm_channel = 0;
uint16_t channels[PPM_CHANNELS];
uint32_t last_frame_received = 0;

#define PPM_MID_VALUE ( (uint16_t) (PPM_MIN_VALUE + (uint16_t) ((float) PPM_MAX_VALUE - (float) PPM_MIN_VALUE) / 2.0) )
#define PPM_OUT_MID_VALUE ( (uint16_t) (PPM_OUT_MIN_VALUE + (uint16_t) ((float) PPM_OUT_MAX_VALUE - (float) PPM_OUT_MIN_VALUE) / 2.0) )


void cb()
{
    uint8_t val = digitalRead(pin);
    if (val == 1)
    {
        lastHigh = micros();

    }
    else
    {
        lastLow = micros();

        uint32_t high_pulse = lastLow - lastHigh;
        if (high_pulse > 5000)
        {
            // Most likely sync pulse
            current_ppm_channel = 0;
        }
        else
        {
            if (current_ppm_channel < PPM_CHANNELS)
            {
                channels[current_ppm_channel] = high_pulse;
                current_ppm_channel++;

                if (current_ppm_channel == PPM_CHANNELS)
                {
                    last_frame_received = millis();
                }
            }
        }
    }
}

PPM::PPM(const uint8_t io_pin)
{
    pin = io_pin;
    memset(channels, 0, sizeof(uint16_t) * PPM_CHANNELS);
}

bool PPM::init()
{
    pinMode(pin, INPUT);
    attachInterrupt(digitalPinToInterrupt(pin), cb, CHANGE);
    return true;
}

uint16_t PPM::ch(uint8_t channel)
{
    uint16_t channel_raw = channels[channel];
    uint16_t channel_constrained = constrain(channel_raw, PPM_MIN_VALUE, PPM_MAX_VALUE);
    uint16_t channel_scaled = map(channel_constrained, PPM_MIN_VALUE, PPM_MAX_VALUE, PPM_OUT_MIN_VALUE, PPM_OUT_MAX_VALUE);
    return channel_scaled;
}

uint32_t PPM::getLastFrameReceivedTimestamp()
{
    return last_frame_received;
}
