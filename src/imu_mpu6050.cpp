#include "imu_mpu6050.h"
#include <Wire.h>


bool IMU_MPU6050::doInit()
{
    // TODO: Set pins?
    //Wire.begin(PIN_SDA, PIN_SCL, 400000);
    Wire.begin();
    return m_mpu.begin();
}


ImuReading IMU_MPU6050::doSample()
{
    m_mpu.getEvent(&m_a, &m_g, &m_temp);
    ImuReading newReading =
    {
        .accX = m_a.acceleration.x,
        .accY = m_a.acceleration.y,
        .accZ = m_a.acceleration.z,
        .gyroX = m_g.gyro.x,
        .gyroY = m_g.gyro.y,
        .gyroZ = m_g.gyro.z,
    };
    return newReading;
}
