#include "motor_controller.h"
#include "autorover.h"




bool MotorController::setThrottle(const int16_t throttle)
{
    bool valid_throttle = true;

    if (!within(throttle, MOTOR_CONTROL_MIN_VALUE, MOTOR_CONTROL_MAX_VALUE))
    {
        // Invalid throttle setpoint, we'll set to mid value (should be idle)
        AR.state.throttle_scaled = MOTOR_CONTROL_MID_VALUE;
        valid_throttle = false;
    }
    else
    {
        if (within(throttle, MOTOR_PWM_IDLE_THRESHOLD_LOW, MOTOR_PWM_IDLE_THRESHOLD_HIGH))
        {
            // We're close to the idle throttle, we'll do idle to so we're not too sensitive.
            AR.state.throttle_scaled = MOTOR_CONTROL_MID_VALUE;
        }
        else
        {
            AR.state.throttle_scaled = throttle;
        }
    }

    // First we'll check if we're armed or not
    // TODO: Clearify reason for not running forward, or ARM obvious?
    if (!AR.state.is_armed)
    {
        AR.state.throttle_scaled = MOTOR_CONTROL_MID_VALUE;
    }

    doSetThrottle(AR.state.throttle_scaled);
    return valid_throttle;
}

bool MotorController::setSteer(const int16_t steer)
{
    bool valid_steer = true;

    if (!within(steer, MOTOR_STEER_MIN_VALUE, MOTOR_STEER_MAX_VALUE))
    {
        AR.state.steer_scaled = MOTOR_STEER_MID_VALUE;
        valid_steer = false;
    }
    else
    {
        AR.state.steer_scaled = steer;
    }

    doSetSteer(steer);
    return valid_steer;
}

bool MotorController::init()
{
    return doInit();
}
