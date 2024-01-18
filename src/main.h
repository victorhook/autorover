#ifndef MAIN_H
#define MAIN_H

#include "vsrtos.h"
#include "string.h"
#include "stdint.h"
#include "stdio.h"
#include "machine.h"


#if defined(LINUX)
    #include "serial_mock.h"
    #define Serial SerialMockInst

    #define millis() 0
    #define micros() 0
#else
    #include "Arduino.h"
#endif

// TODO


#define within(value, min, max) ((value >= min) && (value <= max))

#define time_to_update(dt, duration_frequency_hz) (dt > (1000 / duration_frequency_hz))

#define empty_string(str) (str == NULL || str[0] == '\0')

typedef struct
{
    float x;
    float y;
    float z;
}__attribute__((packed)) vec3;

typedef struct
{
    float x;
    float y;
}__attribute__((packed)) vec2;



#endif /* MAIN_H */
