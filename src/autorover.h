#ifndef AUTOROVER_H
#define AUTOROVER_H

#include "main.h"
#include "controller.h"
#include "receiver.h"
#include "imu.h"
#include "mavlink_base.h"
#include "motor_controller.h"
#include "battery.h"
#include "statusled.h"
#include "rgbled.h"
#include "state.h"

class AutoRover
{
    public:
        // Controllers
        Controller* controller;
        Receiver* receiver;
        MavlinkBase* mavlink;
        MotorController* motorController;
        IMU* imu;
        Battery* battery;
        StatusLed* statusled;
        RGB_Led* rgbLed;
        State state;

        AutoRover();
        bool init();
};


extern AutoRover AR;


#endif /* AUTOROVER_H */
