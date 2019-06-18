#include <Arduino.h>
#include "led.h"
#include "triggers.h"
#include "sequencer.h"


int interval=1000;
void setupLed(){
	  pinMode(RED_LED_PIN, OUTPUT);
	  pinMode(GREEN_LED_PIN, OUTPUT);
	  pinMode(BLUE_LED_PIN, OUTPUT);
}

void updateLed(){

	unsigned long currentMillis = millis();
	    // digitalWrite(RED_LED_PIN, HIGH);  
	    // digitalWrite(GREEN_LED_PIN, HIGH);  
	    // digitalWrite(BLUE_LED_PIN, HIGH);  
	    // delay(2000);
	    //  digitalWrite(RED_LED_PIN, LOW);  
	    // digitalWrite(GREEN_LED_PIN, LOW);  
	    // digitalWrite(BLUE_LED_PIN, LOW);  
	    // delay(2000);


	
	if (!statePlay)
	{
		    // digitalWrite(BLUE_LED_PIN, HIGH);  
		
		    clockMillis=currentMillis+interval;

	}else{
		     if (currentMillis  >=  clockMillis) {
		     	// clockMillis = currentMillis;
			    // save the last time you blinked the LED
			    // digitalWrite(BLUE_LED_PIN, LOW);
			     // digitalWrite(BLUE_LED_PIN, LOW);

				}
			   

	}
	
	if (!recmode)
	{
		    digitalWrite(RED_LED_PIN, HIGH);  
		   
	}else{
		    digitalWrite(RED_LED_PIN, LOW);  
		  

	}
	if (!mode)
	{
		   
		    digitalWrite(BLUE_LED_PIN, HIGH);  

	}else{
		    
		    digitalWrite(BLUE_LED_PIN, LOW);  

	}
	if (!stateShift)
	{
		   
		    digitalWrite(GREEN_LED_PIN, HIGH);  
		    digitalWrite(RED_LED_PIN, HIGH);  

	}else{
		    
		    digitalWrite(GREEN_LED_PIN, LOW);  
		    digitalWrite(RED_LED_PIN, LOW);  

	}
	
	if (clkState) {
		step++;
		step=step%16;
		clkState=false;
		for (int i = 0; i < 4; ++i)
		{
			stepTriggered[i]=0;
		}
		if (mode==1)
		{
			// saveStepCv();
		}
	
	}
}