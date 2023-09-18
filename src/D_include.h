#pragma once

#include <Arduino.h>
#include <ArduinoJson.h>
#include <ESPmDNS.h>
#include <FS.h>
#include <FastLED.h>
#include <Preferences.h>
#include <SPIFFS.h>
#include <WiFi.h>
#include <arduinoFFT.h>
#include <String>
#include "ESPAsyncWebServer.h"
#include "Time.h"

#include "D_struct.h"

#include "D_define.h"
#include "D_palette.h"
#include "D_utils.h"
#include "fftMic.h"
#include "setup.h"

#include "matrix_FX_controller.h"

#include "01-Matrix/Mcomet.h"
#include "01-Matrix/Mpuzzle.h"
#include "01-Matrix/MrandomSpectrum.h"
#include "02-Stripe/Sfire.h"

// #include "stripe_FX_controller.h"
#include "CLOCK_CONTROLLER.h"
#include "MATRIX_CONTROLLER.h"
#include "STRIPE_CONTROLLER.h"

#include "web.h"