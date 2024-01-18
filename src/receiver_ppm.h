#ifndef RECEIVER_PPM_H
#define RECEIVER_PPM_H


#include "receiver.h"
#include "ppm.h"


class ReceiverPPM : public Receiver
{
    public:
        ReceiverPPM(const uint8_t pin);
        void update() override;
        bool init() override;

    private:
        const uint8_t m_pin;
        PPM           m_ppm;
};


#endif /* RECEIVER_PPM_H */
