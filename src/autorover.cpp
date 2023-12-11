#include "autorover.h"
#include "controller_rc.h"
#include "receiver_crsf.h"
#include "mavlink_serial.h"
#include "main.h"

#if defined(LINUX)

#else
    #include "motor_controller_drv8833.h"
#endif


AutoRover::AutoRover()
{
    controller = new ControllerRC();
    receiver = new ReceiverCRSF();
    mavlink = new MavlinkSerial();

    #if defined(LINUX)

    #else
        motorController = new MotorControllerDRV8833(PIN_AIN1, PIN_AIN2, PIN_STEER_SERVO);
    #endif
}

void AutoRover::init()
{

}

void AutoRover::update()
{

}

