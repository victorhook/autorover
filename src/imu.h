#ifndef IMU_H
#define IMU_H

#include "main.h"


struct ImuReading
{
    float accX;
    float accY;
    float accZ;
    float gyroX;
    float gyroY;
    float gyroZ;
    uint32_t timestamp;
};


class IMU : public VSRTOS_Task
{
    public:
        void update() override;
        bool init();
        const ImuReading& getLastReading();

    protected:
        virtual bool doInit() = 0;
        virtual ImuReading doSample() = 0;

    private:
        ImuReading lastReading;
};


#endif /* IMU_H */
