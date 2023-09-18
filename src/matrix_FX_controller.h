#pragma once

#include "D_include.h"
#define swap(a, b)                                                    \
  {                                                                            \
    int16_t t = a;                                                             \
    a = b;                                                                     \
    b = t;                                                                     \
  }

struct mamtrix
{

    private:
      void blur2d_com(CRGB *leds, uint8_t width, uint8_t height, fract8 blur_amount)
      {
            blurRows_com(leds, width, height, blur_amount);
            blurColumns_com(leds, width, height, blur_amount);
      }
      void blurRows_com(CRGB *leds, uint8_t width, uint8_t height, fract8 blur_amount)
      {
            /*    for( uint8_t row = 0; row < height; row++) {
                    CRGB* rowbase = leds + (row * width);
                    blur1d( rowbase, width, blur_amount);
                }
            */
            // blur rows same as columns, for irregular matrix
            uint8_t keep = 255 - blur_amount;
            uint8_t seep = blur_amount >> 1;
            for (uint8_t row = 0; row < height; row++)
            {
                  CRGB carryover = CRGB::Black;
                  for (uint8_t i = 0; i < width; i++)
                  {
                        CRGB cur = leds[mXY(i, row)];
                        CRGB part = cur;
                        part.nscale8(seep);
                        cur.nscale8(keep);
                        cur += carryover;
                        if (i)
                              leds[mXY(i - 1, row)] += part;
                        leds[mXY(i, row)] = cur;
                        carryover = part;
                  }
            }
      }

      // blurColumns: perform a blur1d on each column of a rectangular matrix
      void blurColumns_com(CRGB *leds, uint8_t width, uint8_t height, fract8 blur_amount)
      {
            // blur columns
            uint8_t keep = 255 - blur_amount;
            uint8_t seep = blur_amount >> 1;
            for (uint8_t col = 0; col < width; ++col)
            {
                  CRGB carryover = CRGB::Black;
                  for (uint8_t i = 0; i < height; ++i)
                  {
                        CRGB cur = leds[mXY(col, i)];
                        CRGB part = cur;
                        part.nscale8(seep);
                        cur.nscale8(keep);
                        cur += carryover;
                        if (i)
                              leds[mXY(col, i - 1)] += part;
                        leds[mXY(col, i)] = cur;
                        carryover = part;
                  }
            }
      }
      void moveX(int8_t delta, bool wrap)
      {

            const uint16_t cols = width;
            const uint16_t rows = height;
            if (!delta || abs(delta) >= cols)
                  return;
            CRGB newPxCol[cols];
            for (int y = 0; y < rows; y++)
            {
                  if (delta > 0)
                  {
                        for (int x = 0; x < cols - delta; x++)
                              newPxCol[x] = getPixelColorXY((x + delta), y);
                        for (int x = cols - delta; x < cols; x++)
                              newPxCol[x] = getPixelColorXY(wrap ? (x + delta) - cols : x, y);
                  }
                  else
                  {
                        for (int x = cols - 1; x >= -delta; x--)
                              newPxCol[x] = getPixelColorXY((x + delta), y);
                        for (int x = -delta - 1; x >= 0; x--)
                              newPxCol[x] = getPixelColorXY(wrap ? (x + delta) + cols : x, y);
                  }
                  for (int x = 0; x < cols; x++)
                        setPixelColorXY(x, y, newPxCol[x]);
            }
      }

      void moveY(int8_t delta, bool wrap)
      {
            const uint16_t cols = width;
            const uint16_t rows = height;
            if (!delta || abs(delta) >= rows)
                  return;
            CRGB newPxCol[rows];
            for (int x = 0; x < cols; x++)
            {
                  if (delta > 0)
                  {
                        for (int y = 0; y < rows - delta; y++)
                              newPxCol[y] = getPixelColorXY(x, (y + delta));
                        for (int y = rows - delta; y < rows; y++)
                              newPxCol[y] = getPixelColorXY(x, wrap ? (y + delta) - rows : y);
                  }
                  else
                  {
                        for (int y = rows - 1; y >= -delta; y--)
                              newPxCol[y] = getPixelColorXY(x, (y + delta));
                        for (int y = -delta - 1; y >= 0; y--)
                              newPxCol[y] = getPixelColorXY(x, wrap ? (y + delta) + rows : y);
                  }
                  for (int y = 0; y < rows; y++)
                        setPixelColorXY(x, y, newPxCol[y]);
            }
      }

    public:
      int height = 8;
      int width = 32;
      int lenght = 256;
      String name;
      int speed;
      uint32_t loop_call = 0;
      int aux0, aux1;
      int now = millis() / FRAMETIME;
      int step = 0;
      bool isMatrix = true;

      int intensity;
      void setPixelColor(int index, CRGB color)
      {
            matrix_Array[index] = color;
      }
      void setPixelColorXY(int x, int y, CRGB color)
      {
            matrix_Array[mXY(x, y)] = color;
      }
      void setPixelColorXYPalette(int x, int y, uint8_t index)
      {
            matrix_Array[mXY(x, y)] = ColorFromPalette(currentPaletteMatrix, index);
      }
      void setPixelColorXYPalette(int x, int y, uint8_t index, uint8_t bri)
      {
            matrix_Array[mXY(x, y)] = ColorFromPalette(currentPaletteMatrix, index, bri);
      }
      void setPixelColorPalette(int index, uint8_t bri)
      {
            matrix_Array[index] = ColorFromPalette(currentPaletteMatrix, index, bri);
      }
      void setPixelColorPalette(int index)
      {
            matrix_Array[index] = ColorFromPalette(currentPaletteMatrix, index);
      }

      CRGB getPixelColor(int index)
      {
            return matrix_Array[index];
      }
      CRGB getPixelColorXY(int x, int y)
      {
            return matrix_Array[mXY(x, y)];
      }
      void fill(CRGB color)
      {
            fill_solid(matrix_Array, NUM_LED_MATRIX, color);
      }

      // 1 = left, 0 = right
      void shiftLeftRight(int left)
      {
            if (left)
            {
                  for (int i = 0; i < NUM_LED_MATRIX - 1; i++)
                        matrix_Array[i] = matrix_Array[i + 1];
            }
            else
            {
                  for (int i = NUM_LED_MATRIX - 1; i > 0; i--)
                        matrix_Array[i] = matrix_Array[i - 1];
            }
      }
      void shiftLeftRight(int left, int amount)
      {
            if (left)
            {
                  for (int i = 0; i < NUM_LED_MATRIX - amount; i++)
                        matrix_Array[i] = matrix_Array[i + amount];
            }
            else
            {
                  for (int i = NUM_LED_MATRIX - 1; i > amount; i--)
                        matrix_Array[i] = matrix_Array[i - amount];
            }
      }
      void drawCircle(int x0, int y0, int r, CRGB color)
      {
            int16_t f = 1 - r;
            int16_t ddF_x = 1;
            int16_t ddF_y = -2 * r;
            int16_t x = 0;
            int16_t y = r;

            setPixelColorXY(x0, y0 + r, color);
            setPixelColorXY(x0, y0 - r, color);
            setPixelColorXY(x0 + r, y0, color);
            setPixelColorXY(x0 - r, y0, color);

            while (x < y)
            {
                  if (f >= 0)
                  {
                        y--;
                        ddF_y += 2;
                        f += ddF_y;
                  }
                  x++;
                  ddF_x += 2;
                  f += ddF_x;

                  setPixelColorXY(x0 + x, y0 + y, color);
                  setPixelColorXY(x0 - x, y0 + y, color);
                  setPixelColorXY(x0 + x, y0 - y, color);
                  setPixelColorXY(x0 - x, y0 - y, color);
                  setPixelColorXY(x0 + y, y0 + x, color);
                  setPixelColorXY(x0 - y, y0 + x, color);
                  setPixelColorXY(x0 + y, y0 - x, color);
                  setPixelColorXY(x0 - y, y0 - x, color);
            }
      }
      void drawLine(int x0, int y0, int x1, int y1, CRGB color)
      {
            int16_t steep = abs(y1 - y0) > abs(x1 - x0);
            if (steep)
            {
                  swap(x0, y0);
                  swap(x1, y1);
            }

            if (x0 > x1)
            {
                  swap(x0, x1);
                  swap(y0, y1);
            }

            int16_t dx, dy;
            dx = x1 - x0;
            dy = abs(y1 - y0);

            int16_t err = dx / 2;
            int16_t ystep;

            if (y0 < y1)
            {
                  ystep = 1;
            }
            else
            {
                  ystep = -1;
            }

            for (; x0 <= x1; x0++)
            {
                  if (steep)
                  {
                        setPixelColorXY(y0, x0, color);
                  }
                  else
                  {
                        setPixelColorXY(x0, y0, color);
                  }
                  err -= dy;
                  if (err < 0)
                  {
                        y0 += ystep;
                        err += dx;
                  }
            }
      }
      CRGB colorFromPalette(uint8_t index)
      {
            return ColorFromPalette(currentPaletteMatrix, index);
      }
      void fadeToBlackAll(uint8_t fade)
      {
            fadeToBlackBy(matrix_Array, NUM_LED_MATRIX, fade);
      }
      void fadeToBlackOne(uint16_t index, uint8_t fade)
      {
            matrix_Array[index].fadeToBlackBy(fade);
      }
      void fadeToBlackXY(uint8_t x, uint8_t y, uint8_t fade)
      {
            matrix_Array[mXY(x, y)].fadeToBlackBy(fade);
      }
      void blur(int blur_amount)
      {
            blur2d_com(matrix_Array, width, height, blur_amount);
      }
      bool is2D()
      {
            return true;
      }
      void fillRect(int x, int y, int w, int h, CRGB color)
      {
            for (int i = x; i < x + w; i++)
            {
                  for (int j = y; j < y + h; j++)
                  {
                        setPixelColorXY(i, j, color);
                  }
            }
      }
      void move(uint8_t dir, uint8_t delta, bool wrap)
      {
            if (delta == 0)
                  return;
            switch (dir)
            {
            case 0:
                  moveX(delta, wrap);
                  break;
            case 1:
                  moveX(delta, wrap);
                  moveY(delta, wrap);
                  break;
            case 2:
                  moveY(delta, wrap);
                  break;
            case 3:
                  moveX(-delta, wrap);
                  moveY(delta, wrap);
                  break;
            case 4:
                  moveX(-delta, wrap);
                  break;
            case 5:
                  moveX(-delta, wrap);
                  moveY(-delta, wrap);
                  break;
            case 6:
                  moveY(-delta, wrap);
                  break;
            case 7:
                  moveX(delta, wrap);
                  moveY(-delta, wrap);
                  break;
            }
      }
};

mamtrix matrix_C;