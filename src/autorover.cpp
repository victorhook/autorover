#include "autorover.h"
#include "controller_rc.h"
#include "imu_mpu6050.h"
#include "mavlink_serial.h"
#include "receiver_ppm.h"
#include "config.h"
#include "main.h"

#if defined(LINUX)

#else
    #include "motor_controller_drv8833.h"
#endif


AutoRover::AutoRover()
{
    controller      = new ControllerRC();
    receiver        = new ReceiverPPM(PIN_RC_PPM);
    imu             = new IMU_MPU6050();
    battery         = new Battery(PIN_VBAT);
    statusled       = new StatusLed(PIN_STATUS);
    rgbLed          = new RGB_Led();
    motorController = new MotorControllerDRV8833(PIN_AIN1, PIN_AIN2, PIN_STEER_SERVO);

    state.is_armed  = false;
    //mavlink =      new MavlinkSerial();
}

bool AutoRover::init()
{
    // Initialize LED and perform startup blink
    statusled->init();
    statusled->blink(150, 3);

    config.init();
    motorController->init();
    battery->init();
    receiver->init();
    rgbLed->init();

    if (!imu->init())
    {
        // TODO
        Serial.println("Failed to initialize IMU!");
        return false;
    }

    controller->init();

    return true;
}


AutoRover AR;
