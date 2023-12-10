#ifndef MAVLINK_SERIAL_H
#define MAVLINK_SERIAL_H

#include "mavlink_base.h"


class MavlinkSerial : public MavlinkBase
{
    protected:
        uint16_t write(const uint8_t* data, const uint16_t len);
    public:
        MavlinkSerial();
        ~MavlinkSerial();
};


#endif /* MAVLINK_SERIAL_H */
