#ifndef MAVLINK_BASE_H
#define MAVLINK_BASE_H


#include "main.h"
#include "mavlink/common/mavlink.h"


#define MAVLINK_SEND_FREQUENCY_HZ_HEARTBEAT 1
#define MAVLINK_SEND_FREQUENCY_HZ_LOCAL_POS 1


class MavlinkBase : public VSRTOS_Task
{
    public:
        MavlinkBase();
        void update() override;

    protected:
        virtual uint16_t write(const uint8_t* data, const uint16_t len) = 0;

    private:
        uint8_t m_systemId;
        uint8_t m_componentId;
        uint8_t m_txBuf[MAVLINK_MAX_PACKET_LEN];
        mavlink_message_t m_txMsg;
        // Timers
        uint32_t m_last_sent_heartbeat = 0;
        uint32_t m_last_sent_local_pos =0;
        void broadcastHeartbeat();
        void broadcastLocalPosition();
        void sendMavlinkMessage();
};


#endif /* MAVLINK_BASE_H */
