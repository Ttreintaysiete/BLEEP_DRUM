#ifndef __triggers_h__
#define __triggers_h__
#include <Arduino.h>
// #include <Shifter.h>
#include "BLEEP_DRUM_gpio.h"
#include "samples.h"
#include "cv.h"
#include "sequencer.h"
#include <Bounce2.h>

// #include "menu.h"

extern Bounce debouncer1 ; 
extern Bounce debouncer2 ; 
extern Bounce debouncer3 ; 
extern Bounce debouncer4 ; 
extern Bounce debouncerPlay ; 
extern Bounce debouncerRec ; 
extern Bounce debouncerTap ; 
extern Bounce debouncerShift  ; 
extern unsigned long clockMillis ; 

extern void setupTriggers();
extern void triggerSound(byte sound, bool state);
extern void playSound(byte sound, bool state);

extern void updateTriggers();
extern void clockIn();
extern int indexes[];
extern int indexKick, indexSnare,  indexHat, indexNoise, indexClap;
extern int indexKickR , indexSnareR ,  indexHatR , indexNoiseR , indexClapR ;

extern uint32_t accKick, accSnare,accHat,accClap;

extern bool isPlaying[];
extern bool states[];
extern bool state1,state2,state3,state4;
extern bool statePlay,stateRec,stateTap,stateShift;
extern bool isTriggered1,isTriggered2,isTriggered3,isTriggered4;
extern bool push[];
extern bool push1,push2,push3,push4;

extern bool triggered[];
extern bool playmode;
extern bool mode;
extern bool recmode;
extern bool clkState;
extern bool stepTriggered[4];




#endif
