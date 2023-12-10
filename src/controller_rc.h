#ifndef CONTROLLER_RC_H
#define CONTROLLER_RC_H

#include "main.h"
#include "controller.h"


class ControllerRC : public Controller
{
    protected:
        void control() override;
    public:

        /**
         * @brief Set the throttle of the car.
         *
         * @param throttle Value between 1000-2000, where:
         * - 1000: full throttle backwards
         * - 1500: stand still
         * - 2000: full throttle forward
         */
        void setThrottle(const int16_t throttle);

        /**
         * @brief Set the steering of the car
         *
         * @param steer value between 1000-2000, where:
         * - 1000: Full steer to the left
         * - 2000: Full steer to the right
         */
        void setSteer(const int16_t steer);

        int16_t getThrottle();
        int16_t getSteer();
};


#endif /* CONTROLLER_RC_H */
