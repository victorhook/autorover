#ifndef SERIAL_MOCK_H
#define SERIAL_MOCK_H

#include "main.h"


class SerialMock
{
    public:
        SerialMock();
        void begin(uint32_t baudrate);
        uint16_t write(const uint8_t* data, const uint16_t len);
        uint16_t read(uint8_t* buf, uint16_t len);
};


extern SerialMock SerialMockInst;


#endif /* SERIAL_MOCK_H */
