#ifndef WIFI_HANDLER_J
#define WIFI_HANDLER_J

#include "main.h"


class WFiHandler
{
    public:
        WFiHandler();
        void init();

    private:
        void initAP();
        void initSTA();
};

extern WFiHandler wifiHandler;


#endif /* WIFI_HANDLER_J */
