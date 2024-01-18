#include "mavlink_base.h"
#include "state.h"


MavlinkBase::MavlinkBase()
: m_last_sent_heartbeat(0),
  m_last_sent_local_pos(0)
{
    Serial.begin(115200);
}



void MavlinkBase::update()
{
    uint32_t now = millis();

    if (time_to_update(now - m_last_sent_heartbeat, MAVLINK_SEND_FREQUENCY_HZ_HEARTBEAT))
    {
        broadcastHeartbeat();
        m_last_sent_heartbeat = millis();
    }

    if (time_to_update(now - m_last_sent_local_pos, MAVLINK_SEND_FREQUENCY_HZ_LOCAL_POS))
    {
        broadcastLocalPosition();
        m_last_sent_local_pos = millis();
    }

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
    mavlink_msg_heartbeat_encode(255, 0, &m_txMsg, &heartbeat);

    sendMavlinkMessage();
}

void MavlinkBase::broadcastLocalPosition()
{
    mavlink_local_position_ned_t pos =
    {
        .time_boot_ms = millis(),
        .x = state.localPosNed.x,
        .y = state.localPosNed.y,
        .z = state.localPosNed.z,
        .vx = state.locaLVelNed.x,
        .vy = state.locaLVelNed.y,
        .vz = state.locaLVelNed.z
    };
    mavlink_msg_local_position_ned_encode(255, 0, &m_txMsg, &pos);

    sendMavlinkMessage();
}

void MavlinkBase::sendMavlinkMessage() {
    write(m_txBuf, mavlink_msg_to_send_buffer(m_txBuf, &m_txMsg));
}
