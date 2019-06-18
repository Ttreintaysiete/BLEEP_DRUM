  #include <SPI.h>
#include <Bounce2.h>
#include "samples.h"
#include "BLEEP_DRUM_gpio.h"
#include "sequencer.h"
#include "triggers.h"
#include "cv.h"
#include "led.h"


void setup() {
  initDac();
  setupLed();
  setupTriggers();
  // pinMode(PLAY_BUTTON,INPUT_PULLUP);
  // pinMode(REC_BUTTON,INPUT_PULLUP);
  // pinMode(TAP_BUTTON,INPUT_PULLUP);
  // pinMode(SHIFT_BUTTON,INPUT_PULLUP);

  // //SW4 19; INPUT_PULLUP
  // //SW3 18; INPUT_PULLUP

  // //RESET 12; DANGER INPUT_PULLUP
  // //CLOCK IN 2;INPUT_PULLUP

  // //REC 4; INPUT_PULLUP
  // //PLAY 3; INPUT_PULLUP
  // //SHIFT 8; INPUT_PULLUP
  // //TAP 7; INPUT_PULLUP


  // //cambiar ADC2 y ADC3 por ADC6 y ADC7

  pinMode(CV_1_PIN, INPUT);
  pinMode(CV_2_PIN, INPUT);
  pinMode(CV_3_PIN, INPUT);
  pinMode(CV_4_PIN, INPUT);
}


void loop() {

  updateCVs();
  updateTriggers();
  updateLed();
  
}

void initDac() {

  pinMode (SPI_PIN, OUTPUT);

  delay(100);

  digitalWrite(SPI_PIN, HIGH);
  SPI.begin();
  SPI.setBitOrder(MSBFIRST);
  /* Enable interrupt on timer2 == 127, with clk/8 prescaler. At 16MHz,
    this gives a timer interrupt at 15625Hz. */
  TIMSK2 = (1 << OCIE2A);
  OCR2A = 128;
  //OCR2B = 127;

  /* clear/reset timer on match */
  TCCR2A = 1 << WGM21 | 0 << WGM20; /* CTC mode, reset on match */
  TCCR2B = 0 << CS22 | 1 << CS21 | 1 << CS20; /* clk, /8 prescaler */

  TCCR0B = B0000001;
  TCCR1B = B0000001;

}
