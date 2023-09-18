#pragma once

#include "D_include.h"

struct storedPixels {
   enum Direction { UP, DOWN, LEFT, RIGHT };
   int heighty = 8;
   int widthx = 32;
   CRGB color;
   uint8_t posX, posY;
   uint8_t speed;
   bool exist;
   Direction indexer;
   void move() {
      if (indexer == UP) {
         posY++;
         if (posY > heighty - 1) {
            exist = false;
            posY = 0;
         }
      } else if (indexer == DOWN) {
         posY--;
         if (posY < 0) {
            exist = false;
            posY = heighty - 1;
         }
      } else if (indexer == LEFT) {
         posX--;
         if (posX < 0) {
            exist = false;
            posX = widthx - 1;
         }
      } else if (indexer == RIGHT) {
         posX++;
         if (posX > widthx - 1) {
            exist = false;
            posX = 0;
         }
      }
   }

   void init(float band) {
      randomSeed(analogRead(0));
      int rand = random(4);

      switch (rand) {
         case 0:
            indexer = UP;
            posX = random8(0, widthx - 1);
            posY = 0;
            break;
         case 1:
            indexer = LEFT;
            posX = widthx - 1;
            posY = random8(0, heighty - 1);
            break;
         case 2:
            indexer = DOWN;
            posX = random8(0, widthx - 1);
            posY = heighty - 1;
            break;
         case 3:
            indexer = RIGHT;
            posX = 0;
            posY = random8(0, heighty - 1);
            break;
      }
      exist = true;

      color = CHSV(band * 8, 255, 255);
   }
};
const int numbanders = 16;
// #define numbanders 10
struct BarHeightsA {
   uint8_t vol;
   uint8_t b8[numbanders];
   uint8_t b16[numbanders];
   uint8_t b32[numbanders];
   uint8_t b64[numbanders];
   uint8_t b128[numbanders];
   uint8_t b256[numbanders];
   float p8[numbanders];
   float p16[numbanders];
   float p32[numbanders];
   float p64[numbanders];
   float p128[numbanders];
   float p256[numbanders];
   float decay = 0.6;

   uint8_t low, mid, high;
   void addFreq(float l, float m, float h) {
      low = l;
      mid = m;
      high = h;
      // Serial.print("Low: ");
      // Serial.print(low);
      // Serial.print(" Mid: ");
      // Serial.print(mid);
      // Serial.print(" High: ");
      // Serial.println(high);
   }
   uint8_t getLow() {
      return low;
   }
   uint8_t getMid() {
      return mid;
   }
   uint8_t getHigh() {
      return high;
   }
   void addVolume(uint8_t volumen) {

      if (volumen > 255) {
         volumen = 255;
      }
      if (volumen < 0) {
         volumen = 0;
      }
      this->vol = volumen;
   }

   uint8_t getVolume8() {
      return map(vol, 0, 255, 0, 8);
   }
   uint8_t getVolume16() {
      return map(vol, 0, 255, 0, 16);
   }
   uint8_t getVolume32() {
      return map(vol, 0, 255, 0, 32);
   }
   uint8_t getVolume64() {
      return map(vol, 0, 255, 0, 64);
   }
   uint8_t getVolume128() {
      return map(vol, 0, 255, 0, 128);
   }
   uint8_t getVolume256() {
      return vol;
   }
   void updatePeaks() {
      for (uint8_t i = 0; i < numbanders; i++) {
         if (b8[i] > p8[i]) {
            p8[i] = b8[i];
         }
         if (b16[i] > p16[i]) {
            p16[i] = b16[i];
         }
         if (b32[i] > p32[i]) {
            p32[i] = b32[i];
         }
         if (b64[i] > p64[i]) {
            p64[i] = b64[i];
         }
         if (b128[i] > p128[i]) {
            p128[i] = b128[i];
         }
         if (b256[i] > p256[i]) {
            p256[i] = b256[i];
         }
      }
   }
   void decayPeaks() {
      EVERY_N_MILLIS(180) {

         for (uint8_t i = 0; i < numbanders; i++) {
            if (p8[i] > 0) {
               p8[i] -= decay;
            } else {
               p8[i] = 0;
            }
            if (p16[i] > 0) {
               p16[i] -= decay * 2;
            } else {
               p16[i] = 0;
            }
            if (p32[i] > 0) {
               p32[i] -= decay * 4;
            } else {
               p32[i] = 0;
            }
            if (p64[i] > 0) {
               p64[i] -= decay * 8;
            } else {
               p64[i] = 0;
            }
            if (p128[i] > 0) {
               p128[i] -= decay * 16;
            } else {
               p128[i] = 0;
            }
            if (p256[i] > 0) {
               p256[i] -= decay * 32;
            } else {
               p256[i] = 0;
            }
         }
      }
   }
   void addBarHeight(uint8_t band, uint8_t height) {
      b8[band] = map(height, 0, 256, 0, 8);
      b16[band] = map(height, 0, 256, 0, 16);
      b32[band] = map(height, 0, 256, 0, 32);
      b64[band] = map(height, 0, 256, 0, 64);
      b128[band] = map(height, 0, 256, 0, 128);
      b256[band] = height;
   }
   void addPeakHeight(uint8_t band, uint8_t height) {
      p8[band] = map(height, 0, 256, 0, 8);
      p16[band] = map(height, 0, 256, 0, 16);
      p32[band] = map(height, 0, 256, 0, 32);
      p64[band] = map(height, 0, 256, 0, 64);
      p128[band] = map(height, 0, 256, 0, 128);
      p256[band] = height;
   }
   uint8_t getBarHeight8(uint8_t band) {
      return b8[band];
   }
   uint8_t getPeakHeight8(uint8_t band) {
      return p8[band];
   }
   uint8_t getBarHeight16(uint8_t band) {
      return b16[band];
   }
   uint8_t getPeakHeight16(uint8_t band) {
      return p16[band];
   }
   uint8_t getBarHeight32(uint8_t band) {
      return b32[band];
   }
   uint8_t getPeakHeight32(uint8_t band) {
      return p32[band];
   }
   uint8_t getBarHeight64(uint8_t band) {
      return b64[band];
   }
   uint8_t getPeakHeight64(uint8_t band) {
      return p64[band];
   }
   uint8_t getBarHeight128(uint8_t band) {
      return b128[band];
   }
   uint8_t getPeakHeight128(uint8_t band) {
      return p128[band];
   }
   uint8_t getBarHeight256(uint8_t band) {
      return b256[band];
   }
   uint8_t getPeakHeight256(uint8_t band) {
      return p256[band];
   }
};

/// bitmap font structure
typedef struct bitmap_font {
   unsigned char Width;          ///< max. character width
   unsigned char Height;         ///< character height
   unsigned short Chars;         ///< number of characters in font
   const unsigned char* Widths;  ///< width of each character
   const unsigned short* Index;  ///< encoding to character index
   const unsigned char* Bitmap;  ///< bitmap of all characters
} bitmap_font;