#include <Arduino.h>
#include "triggers.h"
#include "BLEEP_DRUM_gpio.h"
bool clkState;
Bounce debouncer1 = Bounce(); 
Bounce debouncer2 = Bounce(); 
Bounce debouncer3 = Bounce(); 
Bounce debouncer4 = Bounce(); 
Bounce debouncerShift= Bounce(); 
Bounce debouncerTap= Bounce(); 
Bounce debouncerRec= Bounce(); 
Bounce debouncerPlay= Bounce(); 

bool states[]={0,0,0,0,0,0,0,0};
bool isPlaying[]={0,0,0,0};
bool triggered[]={0,0,0,0};
bool push[]={0,0,0,0};
int indexes[]={0,0,0,0};
int indexKick = 0, indexSnare = 0,  indexHat = 0, indexNoise = 0, indexClap = 0;
int indexKickR = 0, indexSnareR = 0,  indexHatR = 0, indexNoiseR = 0, indexClapR = 0;
uint32_t accKick=0, accSnare=0,accHat=0,accClap=0;
bool push1=0, push2=0,push3=0,push4=0;
bool state1=0, state2=0,state3=0,state4=0;
bool statePlay=0, stateRec=0,stateTap=0,stateShift=0;
bool isTriggered1=0, isTriggered2=0,isTriggered3=0,isTriggered4=0;
bool playmode = 1;
bool mode = 0;
bool recmode = 1;
bool stepTriggered[]={0,0,0,0};
unsigned long clockMillis = 0;

void updateTriggers(){
	// Update the Bounce instance :
	debouncer1.update();
	// Get the updated value :
	state1 = debouncer1.read();
	// Update the Bounce instance :
	debouncer2.update();
	// Get the updated value :
	state2 = debouncer2.read();
	// Update the Bounce instance :
	debouncer3.update();
	// Get the updated value :
	state3 = debouncer3.read();
	// Update the Bounce instance :
	debouncer4.update();
	// Get the updated value :
	state4 = debouncer4.read();
	// Update the Bounce instance :
	debouncerRec.update();
	// Get the updated value :
	stateRec = debouncerRec.read();
	// Update the Bounce instance :
	debouncerTap.update();
	// Get the updated value :
	stateTap = debouncerTap.read();
	// Update the Bounce instance :
	debouncerPlay.update();
	// Get the updated value :
	statePlay = debouncerPlay.read();

	debouncerShift.update();
	// Get the updated value :
	stateShift = debouncerShift.read();

	if (!stateRec)
	{
		
		recmode=!recmode;
	}
	if (!stateTap)
	{
		clear(step);
		// recmode=!recmode;
	}

	if (!statePlay)
	{ 
		
		mode=!mode;
	}

	if (stateShift)
	{
		playmode=1;
	}else{
		playmode=0;
	}

	if (mode && recmode)
	{
     	

	}
		saveStepCv(0);
     	saveStepCv(1);
     	saveStepCv(2);
     	saveStepCv(3);

	if (triggerSequenceA[step])
	{
		if (!stepTriggered[0])
		{
			isTriggered1=1;
			indexKick=0;
			triggerSound(0, 0);
			stepTriggered[0]=1;
		}

		

		
	}
	if (triggerSequenceB[step])
	{
		if (!stepTriggered[1])
		{
			isTriggered2=1;
		indexSnare=0;

			triggerSound(1, 0);
			stepTriggered[1]=1;
		}
	}
	if (triggerSequenceC[step])
	{
		if (!stepTriggered[2])
		{
		isTriggered3=1;
		indexHat=0;

		triggerSound(2, 0);
			stepTriggered[2]=1;
		}
	}
	if (triggerSequenceD[step])
	{
		if (!stepTriggered[3])
		{
		isTriggered4=1;

		indexClap=0;

		triggerSound(3, 0);
		stepTriggered[03]=1;
		}
	}

	triggerSound(0, state1);
	triggerSound(1, state2);
	triggerSound(2, state3);
	triggerSound(3, state4);
}

void setupTriggers(){
	
	pinMode(RED_BUTTON,INPUT_PULLUP);
	pinMode(GREEN_BUTTON,INPUT_PULLUP);
	pinMode(YELLOW_BUTTON,INPUT_PULLUP);
	pinMode(BLUE_BUTTON,INPUT_PULLUP);
	pinMode(PLAY_BUTTON,INPUT_PULLUP);
	pinMode(REC_BUTTON,INPUT_PULLUP);
	pinMode(TAP_BUTTON,INPUT_PULLUP);
	pinMode(SHIFT_BUTTON,INPUT_PULLUP);
	pinMode(CLOCK_IN_PIN,INPUT_PULLUP);
	attachInterrupt(0, clockIn, CHANGE);
	debouncer1.attach(GREEN_BUTTON);
	debouncer1.interval(5); // interval in ms
	debouncer2.attach(RED_BUTTON);
	debouncer2.interval(5); // interval in ms
	debouncer3.attach(YELLOW_BUTTON);
	debouncer3.interval(5); // interval in ms
	debouncer4.attach(BLUE_BUTTON);
	debouncer4.interval(5); // interval in ms
	debouncerShift.attach(SHIFT_BUTTON);
	debouncerShift.interval(5); // interval in ms
	debouncerTap.attach(TAP_BUTTON);
	debouncerTap.interval(5); // interval in ms
	debouncerRec.attach(REC_BUTTON);
	debouncerRec.interval(5); // interval in ms
	debouncerPlay.attach(PLAY_BUTTON);
	debouncerPlay.interval(5); // interval in ms

}

void triggerSound( byte sound, bool state){

	if (!state)
	{
		if (!push[sound])
		{
				// isPlaying[sound]=1;
			switch(sound){
				case 0:
				indexKick=0;
				accKick=0;
				isTriggered1=1;
				saveStepGate(0);
				saveStepCv(0);
     					// isPlaying[0]=1;
				break;
				case 1:
				indexSnare=0;
				accSnare=0;
				isTriggered2=1;
				saveStepGate(1);
				saveStepCv(1);

     					// isPlaying[1]=1;

				break;
				case 2:
				indexHat=0;
				accHat=0;
				isTriggered3=1;
				saveStepGate(2);
				saveStepCv(2);

     					// isPlaying[1]=1;

				break;
				case 3:
				indexClap=0;
				accClap=0;
				isTriggered4=1;
				saveStepGate(3);
				saveStepCv(3);

     					// isPlaying[1]=1;

				break;
			}
				// indexes[sound]=0;
    //  			accumulators[sound]=0;
     			// isPlaying[sound]=1;
		}
		push[sound]=1;

     		// isPlaying[sound]=1;


	}else{
		push[sound]=0;
	}
	
}

void playSound( byte sound, bool state){

	

				// isPlaying[sound]=1;
	switch(sound){
		case 0:
		indexKick=0;
		accKick=0;
		isTriggered1=1;

     					// isPlaying[0]=1;
		break;
		case 1:
		indexSnare=0;
		accSnare=0;
		isTriggered2=1;


     					// isPlaying[1]=1;

		break;
		case 2:
		indexHat=0;
		accHat=0;
		isTriggered3=1;


     					// isPlaying[1]=1;

		break;
		case 3:
		indexClap=0;
		accClap=0;
		isTriggered4=1;


     					// isPlaying[1]=1;

		break;
	}
				// indexes[sound]=0;
    //  			accumulators[sound]=0;
     			// isPlaying[sound]=1;


     		// isPlaying[sound]=1;


	
}


void clockIn()
{
	clkState = true;
}