#include "receiver.h"
#include "main.h"


Receiver::Receiver(const uint16_t connectionTimoutMs)
: m_connectionTimoutMs(connectionTimoutMs)
{

}

bool Receiver::isConnected()
{
    return (millis() - m_lastPacket.timestamp) > m_connectionTimoutMs;
}

const RadioPacket* Receiver::getLastPacket()
{
    return &m_lastPacket;
}