#include "motor_controller_drv8833.h"
#include <Arduino.h>
#include "autorover.h"

//#define PWM_MAX_VALUE       255
#define PWM_MAX_VALUE       255

// This value is added to the PWM output when throttle is non-idle.
// The purpose is that we want to get an offset voltage, so that we don't start at 0.
#define PWM_THROTTLE_OFFSET 30

#define STEER_PWM_MAX 1875
#define STEER_PWM_MIN 1175

// Can be any of: [0, PWM_MAX_VALUE]
// If set to PWM_MAX_VALUE, throttle changes will be rapid, otherwise slower
#define FAST_DECAY PWM_MAX_VALUE

/**
 * Converts the input value to the range to output to PWM.
 *
 * @param value        Throttle value between mid and max motor control values, eg: 2000-1500=500, so 0-500
 */
static inline uint16_t mapToPwm(const uint16_t value)
{
    uint16_t pwm = map(value, 0, (MOTOR_CONTROL_MAX_VALUE - MOTOR_CONTROL_MID_VALUE), 0, PWM_MAX_VALUE - PWM_THROTTLE_OFFSET);
    pwm += PWM_THROTTLE_OFFSET;
    pwm = constrain(pwm, PWM_THROTTLE_OFFSET, PWM_MAX_VALUE);

    return pwm;
}


MotorControllerDRV8833::MotorControllerDRV8833(const uint8_t pinAin1, const uint8_t pinAin2, const uint8_t pinServo)
: m_ain1Pin(pinAin1),
  m_ain2Pin(pinAin2),
  m_servoPin(pinServo)
{
}

bool MotorControllerDRV8833::doInit()
{
    pinMode(m_ain1Pin, OUTPUT);
    pinMode(m_ain2Pin, OUTPUT);
    pinMode(m_servoPin, OUTPUT);

    m_servo.attach(m_servoPin);

    // I think: CS20 62.5 kHz, CS21 7.8 kHz, CS22 1kHz
    TCCR2A = _BV(COM2A1) | _BV(COM2B1) | _BV(WGM21) | _BV(WGM20);
    TCCR2B = _BV(CS20);
    return true;
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
    //
    // Seems like putting one of the inX pins HIGH and the other one PWM
    // produces the nice fast movements we want. However, seems like I need to reverse
    // the PWM, so out=255-"throttle-pwm" (probably since if both inX pins are 1, motor is off)

    if (throttle > MOTOR_CONTROL_MID_VALUE)
    {
        // Forward
        uint32_t duty = PWM_MAX_VALUE - mapToPwm(throttle - MOTOR_CONTROL_MID_VALUE);
        AR.state.throttle_out = duty;
        analogWrite(m_ain1Pin, duty);
        analogWrite(m_ain2Pin, FAST_DECAY);
    }
    else if (throttle < MOTOR_CONTROL_MID_VALUE)
    {
        // Reverse
        uint32_t duty = PWM_MAX_VALUE - mapToPwm(MOTOR_CONTROL_MID_VALUE - throttle);
        AR.state.throttle_out = duty;
        analogWrite(m_ain1Pin, FAST_DECAY);
        analogWrite(m_ain2Pin, duty);
    }
    else
    {
        AR.state.throttle_out = 0;
        // Stop, coast/fast decay
        analogWrite(m_ain1Pin, 0);
        analogWrite(m_ain2Pin, 0);
    }
}

void MotorControllerDRV8833::doSetSteer(const int16_t steer)
{
    uint16_t steer_us = map(steer, MOTOR_STEER_MIN_VALUE, MOTOR_STEER_MAX_VALUE, STEER_PWM_MIN, STEER_PWM_MAX);
    AR.state.steer_out = steer_us;
    //digitalWrite(m_servoPin, 1);
    //delayMicroseconds(steer_us-1);
    //digitalWrite(m_servoPin, 0);
    m_servo.writeMicroseconds(steer_us);
}
