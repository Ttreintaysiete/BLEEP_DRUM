int kick_sample, snare_sample, hat_sample, noise_sample, bass_sample;
int freq = 2;
int sample_sum;

const char noise_table[] PROGMEM = {};


void playSamples() {

  // if (playmode == 0) { //reverse
  //   kick_sample = (pgm_read_byte(&kick_table[indexKickR])) - 127;
  //   snare_sample = (pgm_read_byte(&snare_table[indexSnareR])) - 127;
  //   hat_sample = (pgm_read_byte(&hat_table[(indexHatR)])) - 127;
  //   bass_sample = (((pgm_read_byte(&bass_table[indexClapR])))) - 127;

  //   // B1_freq_sample = pgm_read_byte(&hat_table[(index2vr)]) - 127;
  //   // B2_freq_sample = (pgm_read_byte(&bass_table[(index4vr)])) - 127;
  // }
   kick_sample = (pgm_read_byte(&kick_table[indexKick])) - 127;
    snare_sample = (pgm_read_byte(&snare_table[indexSnare])) - 127;
    hat_sample = (pgm_read_byte(&hat_table[indexHat])) - 127;
    bass_sample = (((pgm_read_byte(&bass_table[indexClap])))) - 127;
  if (playmode == 0) {
   
    
    // B1_freq_sample = pgm_read_byte(&hat_table[(index_freq_1)]) - 127;
    // B2_freq_sample = (pgm_read_byte(&bass_table[(index_freq_2)])) - 127;

    // noise_sample = (((pgm_read_byte(&noise_table[(indexNoise)])))) - 127;

  }
}

ISR(TIMER2_COMPA_vect) {
  OCR2A = 40;

   if (playmode == 0) {
    indexKick = (indexKick - kick_length) * -1;
    indexSnare = (indexSnare - snare_length) * -1;
    indexHat = (indexHat - hat_length) * -1;
    indexClap = (indexClap - bass_length) * -1;

    // indexSnare = (index3 - snare_length) * -1;
    // indexHat = (index - hat_length) * -1;
    // indexClap = (index2 - bass_length) * -1;
    // index2vr = (index_freq_1 - tick_length) * -1;
    // index4vr = (index_freq_2 - bass_length) * -1;

  }

  playSamples();


  // accumulators[0]+=cvValues[0];
  // indexes[0] = (accumulators[0] >> (6));
 

  if (isTriggered1 )
  {
    accKick+=cvValues1;
    indexKick = (accKick >> (6));

    if (indexKick>kick_length)
    { 
        isTriggered1=0;
        indexKick=0;
        accKick=0;
    }

  }
  if (isTriggered2 )
  {
    accSnare+=cvValues2;
    indexSnare = (accSnare >> (6));

    if (indexSnare>snare_length)
    { 
        isTriggered2=0;
        indexSnare=0;
        accSnare=0;
    }

  }
 if (isTriggered3 )
  {
    accHat+=cvValues3;
    indexHat = (accHat >> (6));

    if (indexHat>hat_length)
    { 
        isTriggered3=0;
        indexHat=0;
        accHat=0;
    }

  }
  if (isTriggered4 )
  {
    accClap+=cvValues4;
    indexClap = (accClap >> (6));

    if (indexClap>bass_length)
    { 
        isTriggered4=0;
        indexClap=0;
        accClap=0;
    }

  }


  sample_sum = snare_sample + kick_sample + hat_sample + bass_sample  ;
  byte sample_out = constrain(sample_sum, 0, 255);


  uint16_t dac_out = (0 << 15) | (1 << 14) | (1 << 13) | (1 << 12) | ( sample_out << 4 );
  digitalWrite(10, LOW);
  SPI.transfer(dac_out >> 8);
  SPI.transfer(dac_out & 255);
  digitalWrite(10, HIGH);

  ///////////////////////////////////////////////////////////////////////////////

  // if (playmode == 0) {
  //   indexSnare = (index3 - snare_length) * -1;
  //   indexkick = (index4 - kick_length) * -1;
  //   indexHat = (index - hat_length) * -1;
  //   indexClap = (index2 - bass_length) * -1;
  //   index2vr = (index_freq_1 - tick_length) * -1;
  //   index4vr = (index_freq_2 - bass_length) * -1;

  // }

  // if (B1_latch == 1) {
  //   accumulator += pot1;

  //   index = (accumulator >> (6));
  //   if (index > tick_length) {

  //     index = 0;
  //     accumulator = 0;
  //     B1_latch = 0;
  //   }
  // }

  // if (B2_latch == 1) {

  //   accumulator2 += pot2;
  //   index2 = (accumulator2 >> (6));
  //   if (index2 > bass_length) {

  //     index2 = 0;
  //     accumulator2 = 0;
  //     B2_latch = 0;
  //   }
  // }

  // if (B3_latch == 1) {

  //   index3 = (accumulator3 >> 6);
  //   if (index3 > snare_length) {

  //     index3 = 0;
  //     accumulator3 += pot3;
  //     B3_latch = 0;
  //   }
  // }

  // if (B4_latch == 1) {

  //   // index4b=(accumulator4 >> (6));
  //   index4 = (accumulator4 >> (6));
  //   if (index4 > kick_length) {

  //     index4 = 0;
  //     accumulator4 += pot4;
  //     B4_latch = 0;
  //   }
  // }

  // accu_freq_1 += kf;
  // index_freq_1 = (accu_freq_1 >> (6));
  // if (B1_seq_trigger == 1 && tiggertempo == 0) {
  //   kf = B1_freq_sequence[loopstepf + banko];
  //   kfe = kf;
  // }

  // if (B1_seq_trigger == 1 && tiggertempo == 1) {
  //   kf = B1_freq_sequence[loopstep + banko];
  //   kfe = kf;
  // }

  // if (index_freq_1 > tick_length) {
  //   kf = 0;
  //   index_freq_1 = 0;
  //   accu_freq_1 = 0;
  //   B1_seq_latch = 0;
  // }


  // accu_freq_2 += pf;
  // index_freq_2 = (accu_freq_2 >> (6));

  // if (B2_seq_trigger == 1 && tiggertempo == 0) {
  //   pf = B2_freq_sequence[loopstepf + banko];
  // }

  // if (B2_seq_trigger == 1 && tiggertempo == 1) {
  //   pf = B2_freq_sequence[loopstep + banko];
  // }
  // if (index_freq_2 > bass_length) {
  //   pf = 0;
  //   index_freq_2 = 0;
  //   accu_freq_2 = 0;
  //   B2_seq_latch = 0;
  // }


  // if (noise_mode == 1) {
  //   accumulator5 += (pot3);
  //   // index4b=(accumulator4 >> (6));
  //   index5 = (accumulator5 >> (6));
  //   if (index5 > pot4) {
  //     index5 = 0;
  //     accumulator5 = 0;
  //   }
  // }
}


