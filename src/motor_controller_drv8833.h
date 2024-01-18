#ifndef MOTOR_CONTROLLER_DRV8833
#define MOTOR_CONTROLLER_DRV8833

#include "motor_controller.h"
#include "Servo.h"


class MotorControllerDRV8833 : public MotorController
{
    public:
        MotorControllerDRV8833(const uint8_t pinAin1, const uint8_t pinAin2, const uint8_t pinServo);

    protected:
        void doSetThrottle(const int16_t throttle) override;
        void doSetSteer(const int16_t steer) override;
        bool doInit();

    private:
        uint8_t m_ain1Pin;
        uint8_t m_ain2Pin;
        uint8_t m_servoPin;
        Servo   m_servo;
};


#endif /* MOTOR_CONTROLLER_DRV8833 */
