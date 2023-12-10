#include "autorover.h"
#include "mavlink/common/mavlink.h"

AutoRover AR;


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
    AR.init();

    vsrtos_create_task(AR.controller, "Controller", 100, 1);
    vsrtos_create_task(AR.receiver, "Receiver", 50, 2);
    vsrtos_create_task(AR.mavlink, "Mavlink", 1, 2);

    vsrtos_scheduler_start();
}

// We never reach this point since scheduler takes over execution in setup()
void loop() {}
