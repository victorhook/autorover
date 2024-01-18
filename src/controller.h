#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "vsrtos.h"


#define RC_CONNECTED_TIMEOUT_MS 500


class Controller : public VSRTOS_Task
{
    public:
        void update() override;
        bool init();

    protected:
        virtual void control() = 0;
        void handle_arm_or_disarm(const bool shouldArm);
        void handle_connect_or_disconnect(const uint32_t lastPacket);
        void handle_battery_warning(const float batteryVoltage);
        void arm();
        void disarm();
        void connect();
        void disconnect();
};


#endif /* CONTROLLER_H */
