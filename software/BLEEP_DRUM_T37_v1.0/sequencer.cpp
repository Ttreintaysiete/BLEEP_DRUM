#include <Arduino.h>

#include "sequencer.h"

#include "BLEEP_DRUM_gpio.h"



int cvSequenceA[]={255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255};
int cvSequenceB[]={255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255};
int cvSequenceC[]={255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255};
int cvSequenceD[]={255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255};
bool triggerSequenceA[]={1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0};
bool triggerSequenceB[]={0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0};
bool triggerSequenceC[]={0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0};
bool triggerSequenceD[]={1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0};
int step=0;
void saveStepCv(){

	cvSequenceA[step]=cvValues1;
	cvSequenceB[step]=cvValues2;
	cvSequenceC[step]=cvValues3;
	cvSequenceD[step]=cvValues4;
	// triggerSequence[step]=!triggerSequence[step];

}
void saveStepGate(byte chan){
	if (mode)
	{
			switch(chan){
		case 0:
			triggerSequenceA[step]=1;
		break;
		case 1:
			triggerSequenceB[step]=1;
		break;
		case 2:
			triggerSequenceC[step]=1;
		break;
		case 3:
			triggerSequenceD[step]=1;
		break;


	}
	}

	
	// triggerSequence[step]=!triggerSequence[step];

}
void stopSound(byte chan){

	switch(chan){
			case 0:
				accKick+=cvSequenceA[step];
    			indexKick = (accKick >> (6));
			break;
			case 1:
				accSnare+=cvSequenceB[step];
   				indexSnare = (accSnare >> (6));
			break;
			case 2:
				 accHat+=cvSequenceC[step];
    			indexHat = (accHat >> (6));
			break;
			case 3:
				 accHat+=cvSequenceC[step];
   			     indexHat = (accHat >> (6));
			break;
	}
}
void saveStepCv(byte chan){
	if (mode && recmode)
	{
		switch(chan){
			case 0:
				cvSequenceA[step]=cvValues1;
			break;
			case 1:
				cvSequenceB[step]=cvValues2;
			break;
			case 2:
				cvSequenceC[step]=cvValues3;
			break;
			case 3:
				cvSequenceD[step]=cvValues4;
			break;


		}
	}
	
	// triggerSequence[step]=!triggerSequence[step];

}

void clear(byte step){
		cvSequenceA[step]=cvValues1;
		cvSequenceB[step]=cvValues2;
		cvSequenceC[step]=cvValues3;
		cvSequenceD[step]=cvValues4;
		triggerSequenceA[step]=0;
		triggerSequenceB[step]=0;
		triggerSequenceC[step]=0;
		triggerSequenceD[step]=0;

}