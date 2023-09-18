#pragma once

#include "D_include.h"

patterns_vis DisplaysList_stripe = {
    //

    {fireStripe, "Fire", 0, true},

};
uint8_t StripePatternsAmount = ARRAY_SIZE(DisplaysList_stripe) - 1;

void nextPatternStripe() {
   preferences.begin("settings", false);
   currentStripePattern >= StripePatternsAmount ? currentStripePattern = 0 : currentStripePattern++;
   isAudioStripe = DisplaysList_stripe[currentStripePattern].isAudio;
   preferences.putInt("stripePattern", currentStripePattern);
   preferences.end();
}
void prevPatternStripe() {
   preferences.begin("settings", false);
   currentStripePattern <= 0 ? currentStripePattern = StripePatternsAmount : currentStripePattern--;
   isAudioStripe = DisplaysList_stripe[currentStripePattern].isAudio;
   preferences.putInt("stripePattern", currentStripePattern);
   preferences.end();
}

void nextPaletteStripe() {
   preferences.begin("settings", false);
   currentPaletteStripeIndex >= NUMpalettes ? currentPaletteStripeIndex = 0 : currentPaletteStripeIndex++;
   targetPaletteStripe = paletteList[currentPaletteStripeIndex].Palette;
   preferences.putInt("stripePalette", currentPaletteStripeIndex);
   preferences.end();
}
void prevPaletteStripe() {
   preferences.begin("settings", false);
   currentPaletteStripeIndex <= 0 ? currentPaletteStripeIndex = NUMpalettes : currentPaletteStripeIndex--;
   targetPaletteStripe = paletteList[currentPaletteStripeIndex].Palette;
   preferences.putInt("stripePalette", currentPaletteStripeIndex);
   preferences.end();
}
