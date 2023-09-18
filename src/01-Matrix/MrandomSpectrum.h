#pragma once

#include "D_include.h"

void randomSpectrum() {

   for (int x = 0; x < MATRIX_WIDTH; x++) {
      for (int y = 0; y < MATRIX_HEIGHT; y++) {
         int index = x % 2 == 0 ? (MATRIX_HEIGHT * (x + 1)) - y - 1 : (MATRIX_HEIGHT * x) + y;
         int bbb = x % 2 == 0 ? 255 - ((MATRIX_HEIGHT * (x + 1)) - y - 1) : 255 - ((MATRIX_HEIGHT * x) + y);
         if (x < audioLevels.getBarHeight16(y)) {
            // matrix_Array[bbb] = PAL_M(index - bbb);
            matrix_C.setPixelColorPalette(bbb, index - bbb);
            // matrix_Array[index] = PAL_M(index - bbb);
            matrix_C.setPixelColorPalette(index, index - bbb);
         } else {
            if (random(0, 100) < 20) {
               int a = x / 2;
               int b = 15 - x / 2;
               // matrix_Array[mXY(x, y)].fadeToBlackBy(random8(a * 8));
               matrix_C.fadeToBlackXY(x, y, random8(a * 8));
               // matrix_Array[mXY(x, y, true)].fadeToBlackBy(random8(b * 8));
               matrix_C.fadeToBlackXY(x, y, random8(b * 8));
            }
         }
      }
   }
}
