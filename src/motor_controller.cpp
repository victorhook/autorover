#include "motor_controller.h"




bool MotorController::setThrottle(const int16_t throttle)
{
    if (!within(throttle, MOTOR_CONTROL_MIN_VALUE, MOTOR_CONTROL_MAX_VALUE))
    {
        return false;
    }

    m_currentTargetThrottle = throttle;
    doSetThrottle(throttle);
    return true;
}

bool MotorController::setSteer(const int16_t steer)
{
    if (!within(steer, MOTOR_CONTROL_MIN_VALUE, MOTOR_CONTROL_MAX_VALUE))
    {
        return false;
    }

    m_currentTargetSteer = steer;
    doSetSteer(steer);
    return true;
}