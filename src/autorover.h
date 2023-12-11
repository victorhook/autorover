#ifndef AUTOROVER_H
#define AUTOROVER_H

#include "main.h"
#include "controller.h"
#include "receiver.h"
#include "mavlink_base.h"
#include "motor_controller.h"


class AutoRover : VSRTOS_Task
{
    public:
        // Controllers
        Controller* controller;
        Receiver* receiver;
        MavlinkBase* mavlink;
        MotorController* motorController;

        AutoRover();
        void init();

        void update() override;
};


#endif /* AUTOROVER_H */
