#ifndef BATTERY_H
#define BATTERY_H

#include "main.h"


class Battery : public VSRTOS_Task
{
    public:
        Battery(const uint8_t pin);
        bool init();
        void update() override;
        float getVoltage();

    private:
        const uint8_t m_pin;
        float         m_scaler;
        float         m_vbat_raw;
};


#endif /* BATTERY_H */
