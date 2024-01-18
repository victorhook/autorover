#ifndef CONTROLLER_RC_H
#define CONTROLLER_RC_H

#include "main.h"
#include "controller.h"


class ControllerRC : public Controller
{
    protected:
        void control() override;
};


#endif /* CONTROLLER_RC_H */
