#ifndef RECEIVER_H
#define RECEIVER_H

#include "main.h"


#define RADIO_MAX_CHANNELS 18


struct RadioPacket
{
    uint32_t timestamp;
    uint16_t channels[RADIO_MAX_CHANNELS];
};

class Receiver : public VSRTOS_Task
{
    protected:
        RadioPacket m_lastPacket;
        uint16_t m_connectionTimoutMs;
    public:
        Receiver(const uint16_t connectionTimoutMs = 500);
        bool isConnected();
        const RadioPacket* getLastPacket();
};


#endif /* RECEIVER_H */
