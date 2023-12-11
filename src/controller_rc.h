#ifndef CONTROLLER_RC_H
#define CONTROLLER_RC_H

#include "main.h"
#include "controller.h"


class ControllerRC : public Controller
{
    protected:
        void control() override;
    public:


        void setThrottle(const int16_t throttle);


        void setSteer(const int16_t steer);

        int16_t getThrottle();
        int16_t getSteer();
};


#endif /* CONTROLLER_RC_H */
