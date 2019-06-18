#ifndef __sequencer_h__
#define __sequencer_h__
#include <Arduino.h>
// #include <Shifter.h>
#include "BLEEP_DRUM_gpio.h"

#include "cv.h"
#include "triggers.h"
#include <Bounce2.h>

// #include "menu.h"



extern int cvSequenceA[16];
extern int cvSequenceB[16];
extern int cvSequenceC[16];
extern int cvSequenceD[16];
extern bool triggerSequenceA[16];
extern bool triggerSequenceB[16];
extern bool triggerSequenceC[16];
extern bool triggerSequenceD[16];
extern int step;

extern void saveStepGate(byte chan);
extern void clear(byte step);
extern void saveStepCv(byte chan);

#endif
