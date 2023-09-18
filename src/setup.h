#pragma once

#include "D_include.h"

void setupLeds() {
   MatrtixController = &FastLED.addLeds<WS2812B, MATRIX_DATA_PIN, GRB>(matrix_Array, NUM_LED_MATRIX);
   StripeController = &FastLED.addLeds<WS2812B, STRIP_DATA_PIN, GRB>(stripe_Array, STRIPE_LED_AMOUNT);
   MatrtixController->showLeds();
   StripeController->showLeds();
   FastLED.setMaxPowerInVoltsAndMilliamps(VOLTAGE, AMPS);  // set limit to aamount of AMPs we use..
   FastLED.setBrightness(BRIGHTNESS);                      // set the initial brightness off the whole matrix.
   FastLED.setCorrection(TypicalSMD5050);                  // correction for colors
}

void loadPreferences() {
   preferences.begin("settings");
   smoothingValue = preferences.getFloat("smoothing");
   Serial.println("smoothingValue: ");
   Serial.println(smoothingValue);
   // matrix
   currentMatrixPattern = preferences.getInt("matrixPattern");
   Serial.print("Last selected animation Matrix: ");
   Serial.println(currentMatrixPattern);
   currentPaletteMatrixIndex = preferences.getInt("matrixPalette");
   Serial.print("Last selected palette Matrix: ");
   Serial.println(paletteList[currentPaletteMatrixIndex].Name);
   currentPaletteMatrix = paletteList[currentPaletteMatrixIndex].Palette;
   targetPaletteMatrix = currentPaletteMatrix;
   // stripe
   currentStripePattern = preferences.getInt("stripePattern");
   Serial.print("Last selected animation Stripe: ");
   Serial.println(currentStripePattern);
   currentPaletteStripeIndex = preferences.getInt("stripePalette");
   Serial.print("Last selected palette Stripe: ");
   Serial.println(paletteList[currentPaletteStripeIndex].Name);
   currentPaletteStripe = paletteList[currentPaletteStripeIndex].Palette;
   targetPaletteStripe = currentPaletteStripe;
   // clock
   currentClockPattern = preferences.getInt("clockPattern");
   Serial.print("Last selected animation Clock: ");
   Serial.println(currentClockPattern);
   currentPaletteClockIndex = preferences.getInt("clockPalette");
   Serial.print("Last selected palette Clock: ");
   Serial.println(paletteList[currentPaletteClockIndex].Name);
   currentPaletteClock = paletteList[currentPaletteClockIndex].Palette;
   targetPaletteClock = currentPaletteClock;
   //
   micSensytivity = preferences.getInt("micSensytivity", 10);
   Serial.print("Microphone sesitivity: ");
   Serial.println(micSensytivity);
   micSquelch = preferences.getInt("micNoise", 10);
   Serial.print("micSquelch: ");
   Serial.println(micSquelch);
   matrixSpeed = preferences.getInt("matrixSpeed", 100);
   Serial.print("matrixSpeed: ");
   Serial.println(matrixSpeed);
   stripeSpeed = preferences.getInt("stripeSpeed", 100);
   Serial.print("stripeSpeed: ");
   Serial.println(stripeSpeed);
   matrixBrightness = preferences.getInt("mBrightness", 255);
   Serial.print("matrixBrightness: ");
   Serial.println(matrixBrightness);
   stripBrightness = preferences.getInt("sBrightness", 255);
   Serial.print("stripBrightness: ");
   Serial.println(stripBrightness);
   welcomeMessage = preferences.getString("WMessage", "");
   Serial.print("welcomeMessage: ");
   Serial.println(welcomeMessage);
   vuMeterOnOff = preferences.getBool("vuMeterOnOff", true);
   Serial.print("vuMeterOnOff: ");
   Serial.println(vuMeterOnOff);
   clockOnOff = preferences.getBool("clockOnOff", false);
   Serial.print("clockOnOff: ");
   Serial.println(clockOnOff);
   clockColor = stringToCRGB(preferences.getString("clockColor", "55"));
   Serial.print("clockColor: ");
   Serial.println(preferences.getString("clockColor", "55"));

   preferences.end();
}

boolean connectToNetwork(String s, String p) {
   const char* ssid = s.c_str();
   const char* password = p.c_str();

   Serial.print("ACCESSING WIFI: -");

   Serial.print(ssid);
   Serial.print("- with password: -");
   Serial.print(password);
   Serial.print("- .");
   WiFi.begin(ssid, password);
   Serial.println("");

   // Wait for connection
   while (WiFi.status() != WL_CONNECTED) {
      timerWiFi++;
      delay(500);
      Serial.print(".");
      // matrix[15 + timerWiFi] = CRGB::Blue;
      FastLED.show();
      if (timerWiFi == 16) {
         return false;
      }
   }

   Serial.println("");
   Serial.print("Connected to ");
   Serial.println(ssid);
   Serial.print("IP address: ");
   Serial.println(WiFi.localIP());

   Serial.println("HTTP server started");

   return true;
}  // network()
void setupWiFi(String ssid, String password) {
   if (connectToNetwork(ssid, password)) {
      if (!SPIFFS.begin(true)) {
         Serial.println("An Error has occurred while mounting SPIFFS");
         return;
      } else {
         listDir(SPIFFS, "/", 2);
      }
      delay(1000);  // to allow to start the 2nd processor.

      if (!MDNS.begin("led")) {
         Serial.println("Error starting mDNS");
         // matrix[1] = CRGB::Red;
         // FastLED.show();
         return;
      } else {
         Serial.println("mDNS started LED.LOCAL");
         MDNS.addService("http", "tcp", 80);
      }
      connectedToNetwork = true;

   } else {
      return;
   }
}