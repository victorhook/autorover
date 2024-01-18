#include "controller.h"
#include "autorover.h"


#define MAX_BATTERY_WARNINGS 10
#define VOLTAGE_WARNING_THRESSHOLD 7


void Controller::update()
{
    control();
}

bool Controller::init()
{
    disarm();
    disconnect();
    return true;
}

void Controller::handle_arm_or_disarm(const bool shouldArm)
{
    if (AR.state.is_armed != shouldArm)
    {
        if (shouldArm)
        {
            arm();
        }
        else
        {
            disarm();
        }
        AR.state.is_armed = shouldArm;
    }
}

static int warnings = 0;

void Controller::handle_battery_warning(const float batteryVoltage)
{
    // Above 5 is just so that we're not only on USB
    bool battery_low = ((batteryVoltage > 5) && (batteryVoltage < VOLTAGE_WARNING_THRESSHOLD));

    if (battery_low != AR.state.battery_low)
    {
        if (battery_low && (warnings < MAX_BATTERY_WARNINGS))
        {
            warnings++;

            if (warnings >= MAX_BATTERY_WARNINGS)
            {
                Serial.println("BATTERY LOW!!");
                AR.rgbLed->setFront(COLOR_RED);
                AR.rgbLed->setBack(COLOR_RED);
                AR.rgbLed->setBrightness(100);
                AR.state.battery_low = battery_low;
            }

        }
    }
}

void Controller::handle_connect_or_disconnect(const uint32_t lastPacket)
{
    uint32_t now = millis();

    if (AR.state.is_rc_connected)
    {
        if ((now - lastPacket) > RC_CONNECTED_TIMEOUT_MS)
        {
            AR.state.is_rc_connected = false;
            disconnect();
        }
    }
    else
    {
        if ((AR.receiver->getNbrOfReceivedPackets() > 0) && (now - lastPacket) < RC_CONNECTED_TIMEOUT_MS)
        {
            AR.state.is_rc_connected = true;
            connect();
        }
    }

}

void Controller::arm()
{
    Serial.println("ARM!");
    AR.rgbLed->setFront(COLOR_RED);
    AR.rgbLed->setBack(COLOR_WHITE);
    AR.rgbLed->setBrightness(100);
}

void Controller::disarm()
{
    Serial.println("DISARM!");
    AR.rgbLed->setFront(COLOR_BLUE);
    AR.rgbLed->setBack(COLOR_BLUE);
    AR.rgbLed->setBrightness(40);
}

void Controller::connect()
{
    Serial.println("CONNECT!");
    AR.rgbLed->setFront(COLOR_BLUE);
    AR.rgbLed->setBack(COLOR_BLUE);
    AR.rgbLed->setBrightness(40);
    AR.statusled->set(HIGH);
}

void Controller::disconnect()
{
    Serial.println("DISCONNECT!");
    AR.rgbLed->setFront(COLOR_GREEN);
    AR.rgbLed->setBack(COLOR_GREEN);
    AR.rgbLed->setBrightness(20);
    AR.statusled->set(LOW);
}
