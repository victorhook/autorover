#ifndef STATE_H
#define STATE_H

#include "main.h"


struct State
{
    vec3     localPosNed;
    vec3     locaLVelNed;
    bool     is_armed;
    bool     is_rc_connected;
    bool     battery_low;
    uint16_t throttle_scaled;
    uint16_t throttle_unscaled;
    uint16_t throttle_out;
    uint16_t steer_scaled;
    uint16_t steer_unscaled;
    uint16_t steer_out;
};

extern State state;


#endif /* STATE_H */
