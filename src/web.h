#pragma once

#include "D_include.h"

String decToHexa(int r, int g, int b) {

   char hexColor[8];
   std::snprintf(hexColor, sizeof hexColor, "#%02x%02x%02x", r, g, b);

   return String(hexColor);
}
String getPaletteString(int palNum, boolean isStripe) {
   CRGBPalette16 TempPal;
   if (isStripe) {
      TempPal = paletteList[palNum].Palette;
   } else {
      TempPal = paletteList[palNum].Palette;
   }
   String gradient = " linear-gradient(90deg,";
   for (int i = 0; i < 16; i++) {

      gradient += decToHexa(TempPal[i].r, TempPal[i].g, TempPal[i].b);
      if (i < 15)
         gradient += ",";
      else
         gradient += ")";
   }
   return gradient;
}
String processor(const String& var) {
   if (var == "clockGradient")  ///
   {
      return String(clockGradient);
   }
   if (var == "SMooTH")  ///
   {
      return String(smoothingValue);
   }
   if (var == "welcomeMessage")  ///
   {
      return welcomeMessage;
   } else if (var == "mBright")  ///
   {
      return String(matrixBrightness);
   } else if (var == "sBright")  ///
   {
      return String(stripBrightness);
   } else if (var == "patternStrName")  //
   {
      // return String(DisplaysList_stripe[currentStripePattern].name);
   } else if (var == "patternMatName")  //
   {
      // return String(DisplaysList_matrix[currentMatrixPattern].name);
   } else if (var == "patternClockName")  //
   {
      // return String(patterns_list_clock[currentClockPattern].name);
   } else if (var == "paletteStripe")  //
   {
      String palette_stripe_name = String(paletteList[currentPaletteStripeIndex].Name);
      palette_stripe_name.replace("_", " ");
      return palette_stripe_name;
   } else if (var == "paletteMatrix")  //
   {
      String palette_matrix_name = String(paletteList[currentPaletteMatrixIndex].Name);
      palette_matrix_name.replace("_", " ");
      return palette_matrix_name;
   } else if (var == "paletteClock")  //
   {
      String palette_clock_name = String(paletteList[currentPaletteClockIndex].Name);
      palette_clock_name.replace("_", " ");
      return palette_clock_name;
   } else if (var == "micSens") {
      return String(micSensytivity);
   } else if (var == "stripeSpeed") {
      return String(stripeSpeed);
   } else if (var == "matrixSpeed") {
      return String(matrixSpeed);
   } else if (var == "currentPatMat") {
      return String(currentMatrixPattern);
   } else if (var == "currentPatStr") {
      return String(currentStripePattern);
   } else if (var == "strPatMax") {
      // return String(StripePatternsAmount);
   } else if (var == "matPatMax") {
      // return String(MatrixPatternsAmount);
   } else if (var == "currentPatClock") {
      return String(currentClockPattern);
   } else if (var == "ClockPatMax") {
      // return String(ClockPatternsAmount);
   } else if (var == "CLOCKONOFF") {
      return clockOnOff ? "checked" : "";
   } else if (var == "ISAUDIOM") {

      return isAudioMatrix ? isAudioReactive : isStaticpattern;
   } else if (var == "ISAUDIOS") {

      return isAudioStripe ? isAudioReactive : isStaticpattern;
   } else if (var == "vuMeterStatus") {
      return vuMeterOnOff ? "The VU Meter is on" : "The VU Meter is off";
   }

   else if (var == "micNoise") {
      return String(micSquelch);
   } else if (var == "POWEROFFON") {
      return powerOnOff ? "checked" : "";
   } else if (var == "gradientMatrix") {

      CRGBPalette16 TempPalMatrix = paletteList[currentPaletteMatrixIndex].Palette;
      String gradient = "background: linear-gradient(90deg,";

      for (int i = 0; i < 16; i++) {

         gradient += decToHexa(TempPalMatrix[i].r, TempPalMatrix[i].g, TempPalMatrix[i].b);
         if (i < 15)
            gradient += ",";
         else
            gradient += ");";
      }

      return gradient;
   } else if (var == "gradientStripe") {
      CRGBPalette16 TempPalStripe = paletteList[currentPaletteStripeIndex].Palette;
      String gradient = "background: linear-gradient(90deg,";

      for (int i = 0; i < 16; i++) {

         gradient += decToHexa(TempPalStripe[i].r, TempPalStripe[i].g, TempPalStripe[i].b);
         if (i < 15)
            gradient += ",";
         else
            gradient += ");";
      }

      return gradient;
   } else if (var == "gradientClock") {
      CRGBPalette16 TempPalClock = paletteList[currentPaletteClockIndex].Palette;
      String gradient = "background: linear-gradient(90deg,";

      for (int i = 0; i < 16; i++) {

         gradient += decToHexa(TempPalClock[i].r, TempPalClock[i].g, TempPalClock[i].b);
         if (i < 15)
            gradient += ",";
         else
            gradient += ");";
      }

      return gradient;
   }

   return String();
}

String handleMatrix(uint8_t* data, size_t len) {
   data[len] = '\0';
   String json = (char*)data;

   DynamicJsonDocument doc(JSON_OBJECT_SIZE(2) + 350);
   DeserializationError error = deserializeJson(doc, json);  // Deserialize the JSON document

   if (error) {
      Serial.print(F("deserializeJson() failed: "));
      Serial.println(error.f_str());
      return "deserializeJson error";
   }

   StaticJsonDocument<512> respond;
   JsonObject rootObj = doc.as<JsonObject>();
   if (rootObj.containsKey("pattern")) {
      if (rootObj["pattern"] == "next") {
         nextPatternMatrix();
      } else if (rootObj["pattern"] == "prev") {
         prevPatternMatrix();
      }
      respond["patternMatrixName"] = DisplaysList_matrix[currentMatrixPattern].name;
      respond["curPatMat"] = currentMatrixPattern;
      respond["maxPatMat"] = MatrixPatternsAmount;
      respond["isAudio"] = isAudioMatrix ? isAudioReactive : isStaticpattern;
   }
   if (rootObj.containsKey("palette")) {

      if (rootObj["palette"] == "next") {

         nextPaletteMatrix();
      } else if (rootObj["palette"] == "prev") {

         prevPaletteMatrix();
      }
      respond["paletteMatrixName"] = paletteList[currentPaletteMatrixIndex].Name;
      respond["paletteMatrixGradient"] = getPaletteString(currentPaletteMatrixIndex, false);
   }
   if (rootObj.containsKey("brightness")) {
      preferences.begin("settings", false);
      matrixBrightness = rootObj["brightness"];
      preferences.putInt("mBrightness", matrixBrightness);
      preferences.end();
   }
   if (rootObj.containsKey("speed")) {
      preferences.begin("settings", false);
      matrixSpeed = rootObj["speed"];
      preferences.putInt("matrixSpeed", matrixSpeed);
      preferences.end();
   }

   respond["status"] = "ok";

   if (respond.overflowed()) {
      Serial.println("respond overflowed memory pool is to small");
   }

   return respond.as<String>();
}
String handleStripe(uint8_t* data, size_t len) {
   data[len] = '\0';
   String json = (char*)data;

   DynamicJsonDocument doc(JSON_OBJECT_SIZE(2) + 350);
   DeserializationError error = deserializeJson(doc, json);  // Deserialize the JSON document

   if (error) {
      Serial.print(F("deserializeJson() failed: "));
      Serial.println(error.f_str());
      return "deserializeJson error";
   }
   StaticJsonDocument<512> respond;

   JsonObject rootObj = doc.as<JsonObject>();
   if (rootObj.containsKey("pattern")) {
      if (rootObj["pattern"] == "next") {
         nextPatternStripe();
      } else if (rootObj["pattern"] == "prev") {
         prevPatternStripe();
      }
      respond["patternStripeName"] = DisplaysList_stripe[currentStripePattern].name;
      respond["curPatStr"] = currentStripePattern;
      respond["maxPatStr"] = StripePatternsAmount;
   }
   if (rootObj.containsKey("palette")) {
      if (rootObj["palette"] == "next") {
         nextPaletteStripe();
      } else if (rootObj["palette"] == "prev") {
         prevPaletteStripe();
      }
      respond["isAudio"] = isAudioStripe ? isAudioReactive : isStaticpattern;
      respond["paletteStripeName"] = paletteList[currentPaletteStripeIndex].Name;
   }
   if (rootObj.containsKey("brightness")) {
      stripBrightness = rootObj["brightness"];
      Serial.println(stripBrightness);
   }
   if (rootObj.containsKey("speed")) {
      stripeSpeed = rootObj["speed"];
      Serial.println(stripeSpeed);
   }
   int patterns;
   String status = "Ok";


   respond["status"] = status;

   respond["paletteStripeGradient"] = getPaletteString(currentPaletteStripeIndex, true);

   return respond.as<String>();
}
String handleClock(uint8_t* data, size_t len) {
   data[len] = '\0';
   String json = (char*)data;

   DynamicJsonDocument doc(JSON_OBJECT_SIZE(2) + 350);
   DeserializationError error = deserializeJson(doc, json);  // Deserialize the JSON document

   if (error) {
      Serial.print(F("deserializeJson() failed: "));
      Serial.println(error.f_str());
      return "deserializeJson error";
   }
   StaticJsonDocument<512> respond;
   preferences.begin("settings", false);

   JsonObject rootObj = doc.as<JsonObject>();
   if (rootObj.containsKey("pattern")) {
      ClockMode = PATTERN;
      if (rootObj["pattern"] == "next") {
         nextPatternClock();
      } else if (rootObj["pattern"] == "prev") {
         prevPatternClock();
      }
      respond["patternClockName"] = patterns_list_clock[currentClockPattern].name;
      respond["curPatClock"] = currentClockPattern;
      respond["maxPatClock"] = ClockPatternsAmount;
      preferences.putInt("clockPattern", currentClockPattern);
   }
   if (rootObj.containsKey("palette")) {
      ClockMode = PALETTE;
      if (rootObj["palette"] == "next") {
         nextPaletteClock();
      } else if (rootObj["palette"] == "prev") {
         prevPaletteClock();
      }
      respond["paletteClockName"] = paletteList[currentPaletteClockIndex].Name;
      respond["paletteClockGradient"] = getPaletteString(currentPaletteClockIndex, false);
      preferences.putInt("clockPalette", currentPaletteClockIndex);
   }
   if (rootObj.containsKey("clockOnOff")) {
      Serial.println("clockOnOff");
      if (clockOnOff) {
         clockOnOff = false;
      } else {
         clockOnOff = true;
      }
      preferences.putBool("clockOnOff", clockOnOff);
       respond["onOffClock"] = clockOnOff ? "checked" : "";
   }
   if (rootObj.containsKey("color")) {
      clockColor = stringToCRGB(rootObj["color"].as<String>());
      preferences.putString("clockColor", rootObj["color"].as<String>());
      Serial.println(rootObj["color"].as<String>());
      ClockMode = COLOR;
   }

   preferences.end();
   int patterns;
   String status = "Ok";

   respond["status"] = status;

   //  respond["clockOnOff"] = clockOnOff;
   return respond.as<String>();
}
String handleSettings(uint8_t* data, size_t len) {
   data[len] = '\0';
   String json = (char*)data;

   DynamicJsonDocument doc(JSON_OBJECT_SIZE(2) + 350);
   DeserializationError error = deserializeJson(doc, json);  // Deserialize the JSON document

   if (error) {
      Serial.print(F("deserializeJson() failed: "));
      Serial.println(error.f_str());
      return "deserializeJson error";
   }
   Serial.println();
   serializeJsonPretty(doc, Serial);
   Serial.println();
   Serial.println();

   String status = "Ok";
   JsonObject root = doc.as<JsonObject>();
   StaticJsonDocument<256> respond;
   if (root.containsKey("brightness")) {
   }
   return respond.as<String>();
}
void notFound(AsyncWebServerRequest* request) {
   request->send(404, "text/plain", "Not found");
}
void RunWebserver() {
   Serial.print("The wifi server runs on core: ");
   Serial.println(xPortGetCoreID());  // Webserver should run on second core (0)

   server.on("/", HTTP_GET, [](AsyncWebServerRequest* request) { request->send(SPIFFS, "/index.html", String(), false, processor); });

   server.on("/main.css", HTTP_GET, [](AsyncWebServerRequest* request) { request->send(SPIFFS, "/main.css", "text/css"); });

   server.on("/main.js", HTTP_GET, [](AsyncWebServerRequest* request) { request->send(SPIFFS, "/main.js", "text/css"); });
   server.on("/fft.js", HTTP_GET, [](AsyncWebServerRequest* request) { request->send(SPIFFS, "/fft.js", "text/css"); });
   server.on("/style.css", HTTP_GET, [](AsyncWebServerRequest* request) { request->send(SPIFFS, "/style.css", "text/css"); });
   server.on(
       "/matrix", HTTP_POST, [](AsyncWebServerRequest* request) {}, NULL,
       [](AsyncWebServerRequest* request, uint8_t* data, size_t len, size_t index, size_t total) {
          String myResponse = handleMatrix(data, len);
          request->send(200, "text/plain", myResponse);
       });
   server.on(
       "/stripe", HTTP_POST, [](AsyncWebServerRequest* request) {}, NULL,
       [](AsyncWebServerRequest* request, uint8_t* data, size_t len, size_t index, size_t total) {
          String myResponse = handleStripe(data, len);
          request->send(200, "text/plain", myResponse);
       });

   server.on(
       "/clock", HTTP_POST, [](AsyncWebServerRequest* request) {}, NULL,
       [](AsyncWebServerRequest* request, uint8_t* data, size_t len, size_t index, size_t total) {
          String myResponse = handleClock(data, len);
          request->send(200, "text/plain", myResponse);
       });
   server.onNotFound(notFound);

   server.on("/favicon.ico", HTTP_GET, [](AsyncWebServerRequest* request) { request->send(SPIFFS, "/favicon.png", "image/png"); });

   server.begin();
}