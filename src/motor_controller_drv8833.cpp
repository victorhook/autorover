#include "motor_controller_drv8833.h"


#define THROTTLE_CONTROL_PWM_FREQUENCY_HZ 1000
#define SERVO_CONTROL_PWM_FREQUENCY_HZ    50
#define PWM_RESOLUTION_BITS 10
#define PWM_MAX_VALUE       1024


/**
 * @brief Converts the input value to the range to output to PWM
 */
#define mapToPwm(value) map(value, 0, (MOTOR_CONTROL_MAX_VALUE - MOTOR_CONTROL_MID_VALUE), 0, PWM_MAX_VALUE)


MotorControllerDRV8833::MotorControllerDRV8833(const uint8_t pinAin1, const uint8_t pinAin2, const uint8_t pinServo)
: m_ain1(pinAin1),
  m_ain2(pinAin2),
  m_servo(pinServo),
  m_ain1Channel(0),
  m_ain2Channel(1),
  m_servoChannel(2)
{
    pinMode(m_ain1, OUTPUT);
    pinMode(m_ain2, OUTPUT);
    pinMode(m_servo, OUTPUT);
    ledcSetup(m_ain1Channel, THROTTLE_CONTROL_PWM_FREQUENCY_HZ, PWM_RESOLUTION_BITS);
    ledcSetup(m_ain2Channel, THROTTLE_CONTROL_PWM_FREQUENCY_HZ, PWM_RESOLUTION_BITS);
    ledcSetup(m_servoChannel, SERVO_CONTROL_PWM_FREQUENCY_HZ, PWM_RESOLUTION_BITS);
    ledcAttachPin(m_ain1, m_ain1Channel);
    ledcAttachPin(m_ain2, m_ain2Channel);
    ledcAttachPin(m_servo, m_servoChannel);
}

void MotorControllerDRV8833::doSetThrottle(const int16_t throttle)
{
    // From DRV8833 datasheet:
    //
    // xIN1 xIN2 xOUT1 xOUT2 Function
    // 0    0    Z     Z     Coast/fast decay
    // 0    1    L     H     Reverse
    // 1    0    H     L     Forward
    // 1    1    L     L     Brake/slow decay

    if (throttle > MOTOR_CONTROL_MID_VALUE)
    {
        // Forward
        ledcWrite(m_ain1Channel, mapToPwm(throttle - MOTOR_CONTROL_MID_VALUE));
        ledcWrite(m_ain2Channel, 0);
    }
    else if (throttle < MOTOR_CONTROL_MID_VALUE)
    {
        // Reverse
        ledcWrite(m_ain1Channel, 0);
        ledcWrite(m_ain2Channel, mapToPwm(MOTOR_CONTROL_MID_VALUE - throttle));
    }
    else
    {
        // Stop, coast/fast decay
        ledcWrite(m_ain1Channel, 0);
        ledcWrite(m_ain2Channel, 0);
    }
}

void MotorControllerDRV8833::doSetSteer(const int16_t steer)
{
    if (steer > MOTOR_CONTROL_MID_VALUE)
    {
        // Turning right
        ledcWrite(m_servoChannel, steer - MOTOR_CONTROL_MID_VALUE);
    }
    else if (steer < MOTOR_CONTROL_MID_VALUE)
    {
        // Turning left
        ledcWrite(m_servoChannel, MOTOR_CONTROL_MID_VALUE - steer);
    }
    else
    {
        // No turn!
        ledcWrite(m_servoChannel, MOTOR_CONTROL_MID_VALUE);
    }
}
