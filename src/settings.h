#ifndef SETTINGS_H
#define SETTINGS_H


typedef struct
{

} Settings;

class SettingsHandler
{
    public:
        SettingsHandler();
        Settings settings;
        void readFromStorage();
        void saveToStorage();
};


#endif /* SETTINGS_H */
