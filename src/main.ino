
#define FASTLED_INTERNAL
#include "D_include.h"
bool setupCheck = false;
void setup() {
   randomSeed(analogRead(0) * micros());
   Serial.begin(115200);
   Serial.println("Starting up...");
   setupLeds();
   String ssid = preferences.getString("ssid", "swiatkiewicz");
   String pass = preferences.getString("pass", "11111123");
   setupWiFi(ssid, pass);
   delay(1000);
   if (connectedToNetwork) {
      setupCheck = true;
      RunWebserver();
      configTzTime(defaultTimezone, ntpServer);  // sets TZ and starts NTP sync
                                                 // updateLocalTime();
                                                 // setupTime();
   }
   setupAudio();
   Serial.println("Setup done");
}
void loop() {
   if (!connectedToNetwork) {
      String ssid = preferences.getString("ssid", "swiatkiewicz");
      String pass = preferences.getString("pass", "11111123");
      if (millis() % 100 == 0) {
         Serial.println("Not connected to network");
      }
      EVERY_N_MINUTES(1) {
         Serial.println("Trying to connect to network");
         setupWiFi(ssid, pass);
      }

   } else if (!setupCheck) {
      setupCheck = true;
      RunWebserver();
      configTzTime(defaultTimezone, ntpServer);
   }
   if (!powerOnOff) {
      FastLED.clear();
      FastLED.show();
   } else {
      EVERY_N_MILLISECONDS(40) {
         nblendPaletteTowardPalette(currentPaletteStripe, targetPaletteStripe, 48);
         nblendPaletteTowardPalette(currentPaletteMatrix, targetPaletteMatrix, 48);
         nblendPaletteTowardPalette(currentPaletteClock, targetPaletteClock, 48);
      }

      DisplaysList_stripe[currentStripePattern].drawFrame();
      DisplaysList_matrix[currentMatrixPattern].drawFrame();
      addClockToOutput();
      MatrtixController->showLeds(matrixBrightness);
      StripeController->showLeds(stripBrightness);
      delay(1);
    
   }
}
