#include "config.h"


#if defined(LINUX)
    #define CONFIG_FILE_PATH "/config.json"
#else
    //#include "ArduinoJson.h"
    //#include "SPIFFS.h"
    //#include <SD.h>
    #define CONFIG_FILE_PATH "/config.json"
#endif

void ConfigHandler::init()
{
    #if defined(LINUX)
    #else
        //SPIFFS.begin();
    #endif
}

void ConfigHandler::loadConfig()
{
    #if defined(LINUX)
    #else
    /*
        File f = SPIFFS.open(CONFIG_FILE_PATH);
        if (!f)
        {
            //printf("Failed to open SPIFFS at %s\n", CONFIG_FILE_PATH);
            return;
        }
        StaticJsonDocument<512> doc;
        if (deserializeJson(doc, f))
        {
            // ERRPR!
            return;
        }

        config.serverPort = doc["serverPort"] | 8989;
        strlcpy(config.wifiSSID, doc["wifiSSID"] | "", sizeof(config.wifiSSID));
        strlcpy(config.wifiPASS, doc["wifiPASS"] | "", sizeof(config.wifiPASS));
        strlcpy(config.apSSID, doc["apSSID"] | "AutoRover", sizeof(config.apSSID));
        strlcpy(config.apPASS, doc["apPASS"] | "AutoRover", sizeof(config.apPASS));

        f.close();
    */
    #endif
}

void ConfigHandler::saveConfig()
{

}

ConfigHandler config;
