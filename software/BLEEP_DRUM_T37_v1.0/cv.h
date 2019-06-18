#ifndef __cv_h__
#define __cv_h__
#include <Arduino.h>
// #include <Shifter.h>
#include "BLEEP_DRUM_gpio.h"
#include "triggers.h"
// #include "samples.h"


// #include "menu.h"

extern uint32_t pitches[] ; 
extern uint32_t cvValues[] ; 
extern uint32_t cvValues1; 
extern uint32_t cvValues2; 
extern uint32_t cvValues3; 
extern uint32_t cvValues4; 
extern uint32_t accumulators[] ; 
extern void updateCVs();

#endif
