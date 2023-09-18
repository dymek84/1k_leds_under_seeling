#pragma once

#include "D_include.h"
typedef struct Ripple {
  uint8_t state;
  uint8_t color;
  uint16_t pos;
} ripple;
uint16_t mode_ripplepeak(void) {                // * Ripple peak. By Andrew Tuline.
                                                          // This currently has no controls.
  #define maxsteps 16                                     // Case statement wouldn't allow a variable.

  uint16_t maxRipples = 16;
  uint16_t dataSize = sizeof(Ripple) * maxRipples;
  if (!SEGENV.allocateData(dataSize)) return mode_static(); //allocation failed
  Ripple* ripples = reinterpret_cast<Ripple*>(SEGENV.data);


  uint8_t samplePeak    = *(uint8_t*)um_data->u_data[3];
  #ifdef ESP32
  float   FFT_MajorPeak = *(float*)  um_data->u_data[4];
  #endif
  uint8_t *maxVol       =  (uint8_t*)um_data->u_data[6];
  uint8_t *binNum       =  (uint8_t*)um_data->u_data[7];

  // printUmData();

  if (SEGENV.call_counter == 0) {
    SEGENV.aux0 = 255;
    SEGMENT.custom1 = *binNum;
    SEGMENT.custom2 = *maxVol * 2;
  }

  *binNum = SEGMENT.custom1;                              // Select a bin.
  *maxVol = SEGMENT.custom2 / 2;                          // Our volume comparator.

  SEGMENT.fade_out(240);                                  // Lower frame rate means less effective fading than FastLED
  SEGMENT.fade_out(240);

  for (int i = 0; i < SEGMENT.intensity/16; i++) {   // Limit the number of ripples.
    if (samplePeak) ripples[i].state = 255;

    switch (ripples[i].state) {
      case 254:     // Inactive mode
        break;

      case 255:                                           // Initialize ripple variables.
        ripples[i].pos = random16(SEGLEN);
        #ifdef ESP32
          if (FFT_MajorPeak > 1)                          // log10(0) is "forbidden" (throws exception)
          ripples[i].color = (int)(log10f(FFT_MajorPeak)*128);
          else ripples[i].color = 0;
        #else
          ripples[i].color = random8();
        #endif
        ripples[i].state = 0;
        break;

      case 0:
        SEGMENT.setPixelColor(ripples[i].pos, color_blend(SEGCOLOR(1), SEGMENT.color_from_palette(ripples[i].color, false, PALETTE_SOLID_WRAP, 0), SEGENV.aux0));
        ripples[i].state++;
        break;

      case maxsteps:                                      // At the end of the ripples. 254 is an inactive mode.
        ripples[i].state = 254;
        break;

      default:                                            // Middle of the ripples.
        SEGMENT.setPixelColor((ripples[i].pos + ripples[i].state + SEGLEN) % SEGLEN, color_blend(SEGCOLOR(1), SEGMENT.color_from_palette(ripples[i].color, false, PALETTE_SOLID_WRAP, 0), SEGENV.aux0/ripples[i].state*2));
        SEGMENT.setPixelColor((ripples[i].pos - ripples[i].state + SEGLEN) % SEGLEN, color_blend(SEGCOLOR(1), SEGMENT.color_from_palette(ripples[i].color, false, PALETTE_SOLID_WRAP, 0), SEGENV.aux0/ripples[i].state*2));
        ripples[i].state++;                               // Next step.
        break;
    } // switch step
  } // for i

  return FRAMETIME;
} // mode_ripplepeak()