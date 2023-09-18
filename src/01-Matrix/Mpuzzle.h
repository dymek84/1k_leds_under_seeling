#pragma once

#include "D_include.h"
bool puzzleFlag = true;
byte PSizeX = 4;
byte PSizeY = 4;
float Ecols = (MATRIX_WIDTH / PSizeX);
float Erows = (MATRIX_HEIGHT / PSizeY);
bool Ca = (MATRIX_WIDTH % PSizeX) ? 1 : 0;
bool Ra = (MATRIX_HEIGHT % PSizeY) ? 1 : 0;
uint8_t PCols = round(Ecols) + Ca;
uint8_t PRows = round(Erows) + Ra;
float speedFactor = 0.1;
std::vector<std::vector<uint8_t>> puzzle;
byte puzzle_color;
byte z_dot[2];
byte step;
int8_t move[2];
float shift[2] = {0, 0};
bool XorY;
void puzzle_regen()
{

      puzzle.resize(PCols, std::vector<uint8_t>(PRows, 0));

      byte n = 0;
      for (byte x = 0; x < PCols; x++)
      {
            for (byte y = 0; y < PRows; y++)
            {
                  n++;
                  puzzle[x][y] = (255 / (PCols * PRows)) * n;
            }
      }
      z_dot[0] = random(0, PCols);
      z_dot[1] = random(0, PRows);
}

void puzzle_draw_square(byte x1, byte y1, byte x2, byte y2, byte col)
{
      for (byte x = x1; x < x2; x++)
      {
            for (byte y = y1; y < y2; y++)
            {
                  if (col == 0)
                  {
                        matrix_C.setPixelColorXY(x, y, CRGB(0, 0, 0));
                  }
                  else if ((x == x1 || x == x2 - 1) || (y == y1 || y == y2 - 1))
                        matrix_C.setPixelColorXYPalette(x, y, col);
                  else
                        matrix_C.setPixelColorXY(x, y, CHSV(0, 0, 96));
            }
      }
}

void puzzle_draw_squareF(float x1, float y1, float x2, float y2, byte col)
{
      for (float x = x1; x < x2; x++)
      {
            for (float y = y1; y < y2; y++)
            {
                  if ((x == x1 || x == x2 - 1) || (y == y1 || y == y2 - 1))
                        matrix_C.setPixelColorXYPalette(x, y, col);
                  else
                        matrix_C.setPixelColorXY(x, y, CHSV(0, 0, 96));
            }
      }
}

void puzzleEffect()
{
      if (puzzleFlag)
      {
            puzzle_regen();
            puzzleFlag = false;
      }
      for (byte x = 0; x < PCols; x++)
      {
            for (byte y = 0; y < PRows; y++)
            {
                  puzzle_draw_square(x * PSizeX, y * PSizeY, (x + 1) * PSizeX, (y + 1) * PSizeY, puzzle[x][y]);
            }
      }
      switch (step)
      {
      case 0:
            XorY = !XorY;
            if (XorY)
            {
                  if (z_dot[0] == PCols - 1)
                        move[0] = -1;
                  else if (z_dot[0] == 0)
                        move[0] = 1;
                  else
                        move[0] = (move[0] == 0) ? (random8() % 2) * 2 - 1 : move[0];
            }
            else
            {
                  if (z_dot[1] == PRows - 1)
                        move[1] = -1;
                  else if (z_dot[1] == 0)
                        move[1] = 1;
                  else
                        move[1] = (move[1] == 0) ? (random8() % 2) * 2 - 1 : move[1];
            }
            move[(XorY) ? 1 : 0] = 0;
            step = 1;
            break;
      case 1:
            puzzle_color = puzzle[z_dot[0] + move[0]][z_dot[1] + move[1]];
            puzzle[z_dot[0] + move[0]][z_dot[1] + move[1]] = 0;
            step = 2;
            break;
      case 2:
            puzzle_draw_squareF(((z_dot[0] + move[0]) * PSizeX) + shift[0], ((z_dot[1] + move[1]) * PSizeY) + shift[1],
                                ((z_dot[0] + move[0] + 1) * PSizeX) + shift[0],
                                (z_dot[1] + move[1] + 1) * PSizeY + shift[1], puzzle_color);
            shift[0] -= (move[0] * speedFactor);
            shift[1] -= (move[1] * speedFactor);
            if ((fabs(shift[0]) >= MATRIX_WIDTH / PCols) || (fabs(shift[1]) >= MATRIX_HEIGHT / PRows))
            {
                  shift[0] = 0;
                  shift[1] = 0;
                  puzzle[z_dot[0]][z_dot[1]] = puzzle_color;
                  step = 3;
            }
            break;
      case 3:
            z_dot[0] += move[0];
            z_dot[1] += move[1];
            step = 0;
            break;
      }
}
