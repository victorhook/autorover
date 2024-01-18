#ifndef CONFIG_H
#define CONFIG_H

struct Config {
  char wifiSSID[32];
  char wifiPASS[32];
  char apSSID[32];
  char apPASS[32];
  int serverPort;
};

class ConfigHandler
{
    public:
        Config config;
        void init();
        void loadConfig();
        void saveConfig();
};

extern ConfigHandler config;


#endif /* CONFIG_H */
