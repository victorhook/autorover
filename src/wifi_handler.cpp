#include "wifi_handler.h"
#include "config.h"

#if defined(LINUX)
#else
    //#include "WiFi.h"
    //#include "WiFiServer.h"
#endif

WFiHandler::WFiHandler()
{

}

void WFiHandler::init()
{
    // Let's check if we have a SSID in config and try to connect to it
    if (!empty_string(config.config.wifiSSID) && !empty_string(config.config.wifiPASS))
    {
        int attempts = 0;
    }
    else
    {

    }
}

void WFiHandler::initAP()
{
}

void WFiHandler::initSTA()
{
}

WFiHandler wifiHandler;
