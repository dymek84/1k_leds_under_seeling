#pragma once

#include "D_include.h"

void fireStripe()
{
    uint8_t speedy = 1;
    uint8_t _scale = 120;
    uint32_t a = millis();
    for (int i = 0; i < STRIPE_LED_AMOUNT / 2; i++)
    {
        stripe_Array[STRIPE_LED_AMOUNT / 2 + i] =
            ColorFromPalette(fire_for_fire,

                             qsub8(inoise8(i * _scale, i * _scale + a - 100, a / speedy),
                                   abs8(i - (STRIPE_LED_AMOUNT / 2 - 1)) * 255 / (STRIPE_LED_AMOUNT / 2 - 1)),
                             255);
        stripe_Array[STRIPE_LED_AMOUNT / 2 - i - 1] =
            ColorFromPalette(fire_for_fire,
                             qsub8(inoise8(i * _scale, i * _scale + a + 100, a / speedy),
                                   abs8(i - (STRIPE_LED_AMOUNT / 2 - 1)) * 255 / (STRIPE_LED_AMOUNT / 2 - 1)),
                             255);
    }
}