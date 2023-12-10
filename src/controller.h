#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "vsrtos.h"


class Controller : public VSRTOS_Task
{
    protected:
        virtual void control() = 0;
    public:
        void update() override;
};


#endif /* CONTROLLER_H */
