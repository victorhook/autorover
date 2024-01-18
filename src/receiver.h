#ifndef RECEIVER_H
#define RECEIVER_H

#include "main.h"


#define RADIO_MAX_CHANNELS 18

enum AuxFunction
{
    AUX_FUNCTION_THROTTLE,
    AUX_FUNCTION_YAW,
    AUX_FUNCTION_ROLL,
    AUX_FUNCTION_PITCH,
    AUX_FUNCTION_ARM,
    AUX_FUNCTION_BEEP,
    AUX_FUNCTION_REBOOT
};


struct RadioPacket
{
    uint32_t timestamp;
    uint16_t channels[RADIO_MAX_CHANNELS];
};

class Receiver : public VSRTOS_Task
{
    protected:
        RadioPacket m_lastPacket;
        uint32_t    m_nbr_of_packets;
        uint16_t    m_connectionTimoutMs;
    public:
        Receiver(const uint16_t connectionTimoutMs = 500);
        bool isConnected();
        const RadioPacket* getLastPacket();
        uint32_t getNbrOfReceivedPackets();

        virtual bool init() = 0;
};


#endif /* RECEIVER_H */
