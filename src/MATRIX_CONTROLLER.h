#pragma once

#include "D_include.h"

patterns_vis DisplaysList_matrix = {

    {cometsStartm, "Comets", 0, true},

};

uint8_t MatrixPatternsAmount = ARRAY_SIZE(DisplaysList_matrix) - 1;

void nextPatternMatrix()
{
      preferences.begin("settings", false);
      currentMatrixPattern >= MatrixPatternsAmount ? currentMatrixPattern = 0 : currentMatrixPattern++;
      isAudioMatrix = DisplaysList_matrix[currentMatrixPattern].isAudio;
      Serial.print(currentMatrixPattern);
      Serial.print(" / ");
      Serial.println(MatrixPatternsAmount);
      preferences.putInt("matrixPattern", currentMatrixPattern);
      preferences.end();
}
void prevPatternMatrix()
{
      preferences.begin("settings", false);
      currentMatrixPattern <= 0 ? currentMatrixPattern = MatrixPatternsAmount : currentMatrixPattern--;
      isAudioMatrix = DisplaysList_matrix[currentMatrixPattern].isAudio;
      Serial.print(currentMatrixPattern);
      Serial.print(" / ");
      Serial.println(MatrixPatternsAmount);
      preferences.putInt("matrixPattern", currentMatrixPattern);
      preferences.end();
}

void nextPaletteMatrix()
{
      preferences.begin("settings", false);
      currentPaletteMatrixIndex >= NUMpalettes ? currentPaletteMatrixIndex = 0 : currentPaletteMatrixIndex++;
      targetPaletteMatrix = paletteList[currentPaletteMatrixIndex].Palette;
      preferences.putInt("matrixPalette", currentPaletteMatrixIndex);
      preferences.end();


}
void prevPaletteMatrix()
{
      preferences.begin("settings", false);
      currentPaletteMatrixIndex <= 0 ? currentPaletteMatrixIndex = NUMpalettes : currentPaletteMatrixIndex--;
      targetPaletteMatrix = paletteList[currentPaletteMatrixIndex].Palette;
      preferences.putInt("matrixPalette", currentPaletteMatrixIndex);
      preferences.end();

}