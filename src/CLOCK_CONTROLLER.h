#pragma once

#include "D_include.h"
void clock_juggle() {
   resetClockArray = false;
   fadeToBlackBy(clock_effect_Array, NUM_LED_MATRIX, 3);
   static uint8_t dothue = 0;
   for (int i = 0; i < 8; i++) {
      clock_effect_Array[beatsin16(i + 7, 0, NUM_LED_MATRIX - 1)] |= CHSV(dothue, 200, 255);
      dothue += 11;
      clock_effect_Array[beatsin16(i + 11, 0, NUM_LED_MATRIX - 1)] |= CHSV(dothue, 255, 200);
      dothue += 11;
   }
}
typedef enum { PATTERN, PALETTE, COLOR } clockMode;
clockMode ClockMode = PATTERN;
patterns_vis patterns_list_clock = {

    {clock_juggle, "clock_juggle", 0, true},

};

uint8_t ClockPatternsAmount = ARRAY_SIZE(patterns_list_clock) - 1;

void nextPatternClock()
{

      preferences.begin("settings");
      currentClockPattern >= ClockPatternsAmount ? currentClockPattern = 0 : currentClockPattern++;
      preferences.putInt("clockPattern", currentClockPattern);
      preferences.end();
}
void prevPatternClock()
{


      preferences.begin("settings");
      currentClockPattern <= 0 ? currentClockPattern = ClockPatternsAmount : currentClockPattern--;
      preferences.putInt("clockPattern", currentClockPattern);
      preferences.end();
}
void nextPaletteClock()
{

      preferences.begin("settings");
      currentPaletteClockIndex <= 0 ? currentPaletteClockIndex = NUMpalettes : currentPaletteClockIndex--;
      targetPaletteClock = paletteList[currentPaletteClockIndex].Palette;
      preferences.putInt("clockPalette", currentPaletteClockIndex);
      preferences.end();
}

void prevPaletteClock()
{

      preferences.begin("settings");
      currentPaletteClockIndex >= NUMpalettes - 1 ? currentPaletteClockIndex = 0 : currentPaletteClockIndex++;
      targetPaletteClock = paletteList[currentPaletteClockIndex].Palette;
      preferences.putInt("clockPalette", currentPaletteClockIndex);
      preferences.end();
}

void addClockToOutput() {
   if (ClockMode == PATTERN) {
      clockColor = CHSV(color_hue, 1, 1);
      patterns_list_clock[currentClockPattern].drawFrame();
   } else if (ClockMode == PALETTE) {
      clockColor = CHSV(color_hue, 1, 1);
      addGradientToClock();
      resetClockArray = false;
   } else if (ClockMode == COLOR) {
      memset(clock_effect_Array, 0, sizeof(clock_effect_Array));
   }

   for (uint16_t i = 0; i < NUM_LED_MATRIX; i++) {
      output_array[i] = matrix_Array[i];
      if (clockOnOff) {
         if (clock_array[i] > 0) {
            if (clock_effect_Array[i] > 0) {
               // int pos = mXY(Seconde * MATRIX_WIDTH / 60, MATRIX_HEIGHT - 1);

               // if (clock_array[pos] == CRGB::Black)
               // {
               //       clock_array[pos] = clock_effect_Array[pos];
               // }
               // else
               // {
               //       clock_array[pos] = invert(clock_array[pos]);
               // }
               clock_array[i] = clock_effect_Array[i];
            }
            nblend(output_array[i], clock_array[i], 80);
         }
         if (resetClockArray) {
            memset(clock_effect_Array, 0, sizeof(clock_effect_Array));
         }
      }
   }
}
