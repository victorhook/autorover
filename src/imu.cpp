#include "imu.h"


void IMU::update()
{
    ImuReading newReading = doSample();
    newReading.timestamp = millis();
}

bool IMU::init()
{
    return doInit();
}


const ImuReading& IMU::getLastReading()
{
    return lastReading;
}
