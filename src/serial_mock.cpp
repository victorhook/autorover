#include "serial_mock.h"

SerialMock::SerialMock()
{

}

void SerialMock::begin(uint32_t baudrate)
{

}

uint16_t SerialMock::write(const uint8_t* data, const uint16_t len)
{
    return 0;
}

uint16_t SerialMock::read(uint8_t* buf, uint16_t len)
{
    return 0;
}


// Create an instance
SerialMock SerialMockInst;
