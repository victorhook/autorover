#include "mavlink_serial.h"
#include "main.h"


MavlinkSerial::MavlinkSerial()
{
    Serial.begin(115200);
}


MavlinkSerial::~MavlinkSerial()
{

}


uint16_t MavlinkSerial::write(const uint8_t* data, const uint16_t len)
{
    return Serial.write(data, len);
}
