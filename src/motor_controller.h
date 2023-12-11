#ifndef MOTOR_CONTROLLER_H
#define MOTOR_CONTROLLER_H

#include "main.h"


#define MOTOR_CONTROL_MIN_VALUE 1000
#define MOTOR_CONTROL_MAX_VALUE 2000
#define MOTOR_CONTROL_MID_VALUE (MOTOR_CONTROL_MIN_VALUE + ((MOTOR_CONTROL_MAX_VALUE - MOTOR_CONTROL_MIN_VALUE) / 2))


class MotorController
{
    public:
        /**
         * @brief Set the throttle of the car.
         *
         * @param throttle Value between 1000-2000, where:
         * - 1000: full throttle backwards
         * - 1500: stand still
         * - 2000: full throttle forward
         *
         * @return true if throttle successfully set
         */

        bool setThrottle(const int16_t throttle);

        /**
         * @brief Set the steering of the car
         *
         * @param steer value between 1000-2000, where:
         * - 1000: Full steer to the left
         * - 2000: Full steer to the right
         *
         * @return true if steer successfully set
         */
        bool setSteer(const int16_t steer);

    protected:
        int16_t m_currentTargetThrottle;
        int16_t m_currentTargetSteer;
        virtual void doSetThrottle(const int16_t throttle) = 0;
        virtual void doSetSteer(const int16_t steer) = 0;

};


#endif /* MOTOR_CONTROLLER_H */
