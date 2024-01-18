#include "receiver.h"
#include "main.h"


Receiver::Receiver(const uint16_t connectionTimoutMs)
: m_connectionTimoutMs(connectionTimoutMs),
  m_nbr_of_packets(0)
{

}

bool Receiver::isConnected()
{
    return (millis() - m_lastPacket.timestamp) > m_connectionTimoutMs;
}

const RadioPacket* Receiver::getLastPacket()
{
    //Serial.println("LAST PACKET!");
    //for (int i = 0; i < RADIO_MAX_CHANNELS; i++)
    //{
    //    Serial.println(String(i) + ": " + String(m_lastPacket.channels[i]));
    //}
    //Serial.print("\n");
    return &m_lastPacket;
}

uint32_t Receiver::getNbrOfReceivedPackets()
{
    return m_nbr_of_packets;
}

