#include "autorover.h"
#include "controller_rc.h"
#include "receiver_crsf.h"
#include "mavlink_serial.h"
#include "main.h"


AutoRover::AutoRover()
{
    controller = new ControllerRC();
    receiver = new ReceiverCRSF();
    mavlink = new MavlinkSerial();
}

void AutoRover::init()
{

}

void AutoRover::update()
{

}

