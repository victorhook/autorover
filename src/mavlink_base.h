#ifndef MAVLINK_BASE_H
#define MAVLINK_BASE_H


#include "main.h"
#include "mavlink/common/mavlink.h"


class MavlinkBase : public VSRTOS_Task
{
    private:
        uint8_t m_systemId;
        uint8_t m_componentId;
        uint8_t m_tx_buf[MAVLINK_MAX_PACKET_LEN];
        mavlink_message_t m_tx_msg;
        void broadcastHeartbeat();
        void send_mavlink_message();
    protected:
        virtual uint16_t write(const uint8_t* data, const uint16_t len) = 0;
    public:
        void update() override;
};


#endif /* MAVLINK_BASE_H */
