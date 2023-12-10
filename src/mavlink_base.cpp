#include "mavlink_base.h"


void MavlinkBase::send_mavlink_message() {
    write(m_tx_buf, mavlink_msg_to_send_buffer(m_tx_buf, &m_tx_msg));
}

void MavlinkBase::update()
{
    broadcastHeartbeat();
}

void MavlinkBase::broadcastHeartbeat()
{
    // Create a MAVLink message
    mavlink_heartbeat_t heartbeat;

    // Initialize the heartbeat message
    heartbeat.type = MAV_TYPE_GCS; // Set the type to Ground Control Station
    heartbeat.autopilot = MAV_AUTOPILOT_INVALID; // Set autopilot to invalid
    heartbeat.base_mode = 0; // Set base mode to 0 (MAV_MODE_PREFLIGHT)
    heartbeat.system_status = MAV_STATE_STANDBY; // Set system status to standby

    // Pack the heartbeat message into the MAVLink message
    mavlink_msg_heartbeat_encode(255, 0, &m_tx_msg, &heartbeat);

    send_mavlink_message();
}

