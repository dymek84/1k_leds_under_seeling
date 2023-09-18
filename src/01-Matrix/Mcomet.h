#pragma once

#include "D_include.h"

struct comet_t
{
      float posX, posY;
      int dir;
      float speed;
      uint16_t color;
      bool inited = false;
      void init()
      {
            if (!random(NUM_LED_MATRIX))
            {
                  dir = random16(2);
                  posY = random16(MATRIX_HEIGHT);
                  if (dir)
                        posX = 0;
                  else
                        posX = 31;
                  speed = random16(10, 80) / 100.0f;
                  color = random16(255);
                  inited = true;
                  // Serial.println("dir " + String(dir) + "\tposX " + String(posX) + "\tposY " + String(posY) +
                  // "\tspeed " +
                  //                String(speed) + "\tcolor " + String(color));
            }
      }
      void update()
      {
            for (int i = 0; i < NUM_LED_MATRIX; i++)
            {
                  if (random(100) > 90)
                        matrix_C.fadeToBlackOne(i, 10);
            }

            if (!inited)
                  init();

            if (dir && posX < MATRIX_WIDTH && posX >= 0)
            {

                  matrix_C.setPixelColorXYPalette(posX, posY, color);

                  posX += speed;
            }
            else if (!dir && posX >= 0 && posX < MATRIX_WIDTH)
            {
                  matrix_C.setPixelColorXYPalette(posX, posY, color);

                  posX -= speed;
            }
            else
            {

                  init();
            }
      }
};

comet_t cometsm[8];
void cometsStartm()
{
      for (int i = 0; i < 8; i++)
      {

            cometsm[i].update();
      }
}