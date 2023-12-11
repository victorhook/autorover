#ifndef IMU_MPU6050_H
#define IMU_MPU6050_H

#include "imu.h"
#include "Adafruit_MPU6050.h"


class IMU_MPU6050 : public IMU
{
    protected:
        bool doInit() override;
        ImuReading doSample() override;

    private:
        Adafruit_MPU6050 m_mpu;
        sensors_event_t m_a, m_g, m_temp;
};


#endif /* IMU_MPU6050_H */
