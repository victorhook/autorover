#include "imu.h"


void IMU::update()
{
    lastReading = doSample();
    lastReading.timestamp = millis();
}

bool IMU::init()
{
    return doInit();
}


const ImuReading& IMU::getLastReading()
{
    return lastReading;
}
