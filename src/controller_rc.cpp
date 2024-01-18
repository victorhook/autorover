#include "controller_rc.h"
#include "autorover.h"

#define AUX_ARMED_THRESSHOLD 1550


void ControllerRC::control()
{
    const RadioPacket* lastPacket = AR.receiver->getLastPacket();
    float voltage = AR.battery->getVoltage();
    ImuReading imuReading = AR.imu->getLastReading();

    uint16_t throttle = lastPacket->channels[2];
    uint16_t steer = lastPacket->channels[0];
    uint16_t armed = lastPacket->channels[4] > 1550;

    AR.state.throttle_unscaled = throttle;
    AR.state.steer_unscaled = steer;

    // Arm/Disarm
    handle_arm_or_disarm(armed);

    // RC connect/disconnect
    handle_connect_or_disconnect(lastPacket->timestamp);

    // TODO: Move this to Controller?
    handle_battery_warning(AR.battery->getVoltage());

    if (!AR.state.is_rc_connected)
    {
        // We'll set throttle to 0, and let steer be where it was
        throttle = MOTOR_CONTROL_MID_VALUE;
        steer = MOTOR_CONTROL_MID_VALUE;
    }

    // Set motor throttle and srgteer
    AR.motorController->setThrottle(throttle);
    AR.motorController->setSteer(steer);

    return;
    Serial.print("Accx: " + String(imuReading.accX));
    Serial.print("\tThrottle: " + String(AR.state.throttle_unscaled) + " -> " + String(AR.state.throttle_scaled) + " -> " + String(AR.state.throttle_out));
    Serial.print("\tSteer: " + String(AR.state.steer_unscaled) + " -> " + String(AR.state.steer_scaled) + " -> " + String(AR.state.steer_out));
    Serial.print("\tBattery: " + String(voltage));
    Serial.print("\n");
}
