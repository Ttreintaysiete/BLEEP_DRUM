#include <Arduino.h>
#include "cv.h"
#include "BLEEP_DRUM_gpio.h"
// #include "samples.h"


extern uint32_t cvValues[]={0,0,0,0} ; 
extern uint32_t cvValues1=0; 
extern uint32_t cvValues2=0; 
extern uint32_t cvValues3=0; 
extern uint32_t cvValues4=0; 
extern uint32_t accumulators[]={0,0,0,0} ; 


void updateCVs(){
 	
	cvValues1 = ((analogRead(CV_1_PIN)) >> 1) + 1;
	cvValues2 = ((analogRead(CV_2_PIN)) >> 1) + 1;
	cvValues3 = ((analogRead(CV_3_PIN)) >> 1) + 1;
	cvValues4 = ((analogRead(CV_4_PIN)) >> 1) + 1;

	for (int i = 0; i < 4; ++i)
	{
		// accumulators[i]+=cvValues[i];
	}

	

}