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
#else
    #include "Arduino.h"
#endif

// TODO
#define millis() 0
#define micros() 0

#define within(value, min, max) ((value >= min) && (value <= max))



#endif /* MAIN_H */
