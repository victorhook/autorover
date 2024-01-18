#include "autorover.h"


#ifdef LINUX
void setup();
void loop();

int main()
{
    setup();

    while (1)
    {
        loop();
    }

    return 0;
}

#elif defined(ARDUINO)

#endif



void setup()
{
    Serial.begin(115200);
    if (!AR.init())
    {
        while (1)
        {
            Serial.println("AutoRover failed during initialization!");
            delay(1000);
        }
    }

    vsrtos_create_task(AR.controller, "Controller", 100, 1);
    vsrtos_create_task(AR.receiver,   "Receiver",   100, 2);
    vsrtos_create_task(AR.imu,        "IMU",        100, 2);
    vsrtos_create_task(AR.battery,    "Battery",    20,  2);
    //vsrtos_create_task(AR.mavlink, "Mavlink", 100, 2);

    vsrtos_scheduler_start();
}

// We never reach this point since scheduler takes over execution in setup()
void loop() {}
