#include "receiver_ppm.h"


ReceiverPPM::ReceiverPPM(const uint8_t pin)
: Receiver(),
  m_pin(pin),
  m_ppm(pin)
{

}


bool ReceiverPPM::init()
{
    m_ppm.init();
    return true;
}

void ReceiverPPM::update()
{
    for (int i = 0; i < PPM_CHANNELS; i++)
    {
        m_lastPacket.channels[i] = m_ppm.ch(i);
    }
    uint32_t last_timestamp = m_ppm.getLastFrameReceivedTimestamp();

    if ((last_timestamp != 0) && (m_lastPacket.timestamp != last_timestamp))
    {
        m_nbr_of_packets++;
    }

    m_lastPacket.timestamp = last_timestamp;

}
