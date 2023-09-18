/*
 * This code has been taken from the sound reactive fork of WLED by Andrew
 * Tuline, and the analog audio processing has been (mostly) removed as we
 * will only be using the INMP441.
 *
 * The FFT code runs on core 0 while everything else runs on core 1. This
 * means we can make our main code more complex without affecting the FFT
 * processing.
 */
#pragma once

#include "D_include.h"
// #include "ESP_fft.h"
// #include "customFFT.h"
#include <driver/i2s.h>
#include "arduinoFFT.h"

#define I2S_WS 25   // aka LRCL
#define I2S_SD 32   // aka DOUT
#define I2S_SCK 27  // aka BCLK
#define MIN_SHOW_DELAY 15
const i2s_port_t I2S_PORT = I2S_NUM_0;
// int faceType;
#define SAMPLE_RATE 10240
static ArduinoFFT<float> FFT = ArduinoFFT<float>(vReal, vImag, samplesFFT, SAMPLE_RATE, windowWeighingFactors);
// TaskHandle_t FFT_Task;

// int squelch = 10; // Squelch, cuts out low level sounds
// int gain = 60;    // Gain, boosts input level*/
// uint16_t micData; // Analog input for FFT

// const uint16_t samples = 1024; // This value MUST ALWAYS be a power of 2
// const int BLOCK_SIZE = samples / 8;
// const unsigned int sampling_period_us = round(1000000 * (1.0 / SAMPLE_RATE));
// unsigned long microseconds;

// double FFT_MajorPeak = 0;
// double FFT_Magnitude = 0;

// float fft_input[samples];
// float fft_output[samples];
// // float vImag[samples];
// ESP_fft NEWFFT(samples, SAMPLE_RATE, FFT_REAL, FFT_FORWARD1, fft_input, fft_output);
// customFFT FFT = customFFT(fft_input, vImag, samples, SAMPLE_RATE);
// These are the input and output vectors.  Input vectors receive computed
// results from FFT.
// float vReal[samples];
// float vImag[samples];
// float fftBin[samples];

// Try and normalize fftBin values to a max of 4096, so that 4096/16 = 256.
// Oh, and bins 0,1,2 are no good, so we'll zero them out.
#define NUM_BANDS 16

// int fftResult[NUM_BANDS]; // Our calculated result table, which we feed to the

// float spectrumValue[NUM_BANDS];       // holds raw adc values
// float spectrumDecay[NUM_BANDS] = {0}; // holds time-averaged values
// float spectrumPeaks[NUM_BANDS] = {0}; // holds peak values
// float spectrumAvg[NUM_BANDS] = {0};   // holds averaged values
// float audioAvg = 50.0;
// float gainAGC = 0.0;
// uint8_t spectrumByte[NUM_BANDS]; // holds 8-bit adjusted adc values
#define LOG_256 5.54517744f  // log(256)
// Table of linearNoise results to be multiplied by squelch in order to reduce squelch across fftResult bins.
int linearNoise[16] = {34, 28, 26, 25, 20, 12, 9, 6, 4, 4, 3, 2, 2, 2, 2, 2};

// Table of multiplication factors so that we can even out the frequency response.
static PROGMEM const byte spectrumFactors[16] = {171, 171, 173, 178, 168, 156, 155, 163, 179, 162, 180, 206, 247, 248, 250, 254};

double fftAdd(int from, int to) {
   int i = from;
   double result = 0;
   while (i <= to) {
      result += fftBin[i++];
   }
   return result;
}

// uint8_t avgVol;
// uint8_t maxVol;
#define SPECTRUMSMOOTH 0.08
#define PEAKDECAY 0.01
#define NOISEFLOOR 60
unsigned int peakToPeak = 0;
// uint8_t volume;
// uint8_t last;
// uint8_t avgBump;
#define AGCSMOOTH 0.004
#define GAINUPPERLIMIT 40.0
#define GAINLOWERLIMIT 1
int cc_counter;
// FFT main code

// float version of map()
static float mapf(float x, float in_min, float in_max, float out_min, float out_max) {
   return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}
// Attempt at beat detection
byte beatTriggered = 0;
#define beatLevel 30.0
#define beatDeadzone 40.0
#define beatDelay 250
float lastBeatVal = 0;
unsigned long currentMillis;  // store current loop's millis value
unsigned long audioMillis;    // store time of last audio update
byte beatDetect() {
   static float bbb = 0.01;
   static float beatAvg = 0;
   static unsigned long lastBeatMillis;
   float specCombo = (spectrumDecay[0] + spectrumDecay[1]) / 2.0;
   beatAvg = (1.0 - AGCSMOOTH) * beatAvg + AGCSMOOTH * specCombo;

   if (lastBeatVal < beatAvg)
      lastBeatVal = beatAvg;
   if ((specCombo - beatAvg) > beatLevel && beatTriggered == 0 && currentMillis - lastBeatMillis > beatDelay) {
      beatTriggered = 1;
      beatAvg /= 2;
      lastBeatVal = specCombo;
      lastBeatMillis = currentMillis;
      return 1;
   } else if ((lastBeatVal - specCombo) > beatDeadzone) {
      beatTriggered = 0;
      return 0;
   } else {
      return 0;
   }
}

void FFTcode(void* parameter) {
   (void)parameter;
   delay(1000);
   Serial.println("FFTcode() running on core " + String(xPortGetCoreID()));
   for (;;) {
      //     currentMillis = millis(); // save the current timer value
      delay(1);
      audioLevels.decayPeaks();
      float avgVol;
      float averagedata;
      for (int i = 0; i < samplesFFT; i++) {
         microseconds = micros();
         int32_t digitalSample = 0;
         size_t bytes_read = 0;
         esp_err_t result = i2s_read(I2S_PORT, &digitalSample, sizeof(digitalSample), &bytes_read, 10);

         if (bytes_read > 0)
            micData = abs(digitalSample >> 16);
         averagedata = averagedata + micData;

         vReal[i] = (float)micData;
         vImag[i] = 0;
         delayMicroseconds(20);
      }

      FFT.dcRemoval();  // remove DC offset
      FFT.windowing(FFTWindow::Flat_top,
                    FFTDirection::Forward);  // Weigh data using "Flat Top" function - better amplitude accuracy
      // FFT.windowing(FFTWindow::Blackman_Harris, FFTDirection::Forward);  // Weigh data using "Blackman- Harris"
      // window - sharp peaks due to excellent sideband rejection
      FFT.compute(FFTDirection::Forward);                        // Compute FFT
      FFT.complexToMagnitude();                                  // Compute magnitudes
      FFT.majorPeak(FFT_MajorPeak, FFT_Magnitude);               // let the effects know which freq was most dominant
                                                                 //    FFT.MajorPeak(&FFT_MajorPeak, &FFT_Magnitude);
      FFT_MajorPeak = constrain(FFT_MajorPeak, 1.0f, 11025.0f);  // restrict value to range expected by effects

      for (int i = 0; i < samples; i++) {
         double t = 0.0;
         t = vReal[i];
         t = t / 16.0;
         fftBin[i] = t;
      }
             // Range
      spectrumValue[0] = (fftAdd(3, 4)) / 2;        // 60 - 100
      spectrumValue[1] = (fftAdd(4, 5)) / 2;        // 80 - 120
      spectrumValue[2] = (fftAdd(5, 7)) / 3;        // 100 - 160
      spectrumValue[3] = (fftAdd(7, 9)) / 3;        // 140 - 200
      spectrumValue[4] = (fftAdd(9, 12)) / 4;       // 180 - 260
      spectrumValue[5] = (fftAdd(12, 16)) / 5;      // 240 - 340
      spectrumValue[6] = (fftAdd(16, 21)) / 6;      // 320 - 440
      spectrumValue[7] = (fftAdd(21, 28)) / 8;      // 420 - 600
      spectrumValue[8] = (fftAdd(29, 37)) / 10;     // 580 - 760
      spectrumValue[9] = (fftAdd(37, 48)) / 12;     // 740 - 980
      spectrumValue[10] = (fftAdd(48, 64)) / 17;    // 960 - 1300
      spectrumValue[11] = (fftAdd(64, 84)) / 21;    // 1280 - 1700
      spectrumValue[12] = (fftAdd(84, 111)) / 28;   // 1680 - 2240
      spectrumValue[13] = (fftAdd(111, 147)) / 37;  // 2220 - 2960
      spectrumValue[14] = (fftAdd(147, 194)) / 48;  // 2940 - 3900
      spectrumValue[15] = (fftAdd(194, 255)) / 62;  // 3880 - 5120
      float mid = 0.0f, high = 0.0f, low = 0.0f;
      for (int i = 0; i < 5; i++) {
         low += spectrumValue[i];
         mid += spectrumValue[i + 5];
         high += spectrumValue[i + 10];
      }
      low /= 5;
      mid /= 5;
      high /= 5;
      audioLevels.addFreq(low, mid, high);
      int analogsum = 0;
      for (int i = 0; i < NUM_BANDS; i++) {

         // noise floor filter
         if (spectrumValue[i] < NOISEFLOOR) {
            spectrumValue[i] = 0;
         } else {
            spectrumValue[i] -= NOISEFLOOR;
         }

         // apply correction factor per frequency bin
         spectrumValue[i] = (spectrumValue[i] * (pgm_read_byte_near(spectrumFactors + i)) / 100);

         // prepare average for AGC

         spectrumValue[i] /= 2;
         // apply current gain value
         spectrumValue[i] *= gainAGC;

         // process time-averaged values
         spectrumDecay[i] = (1.0 - SPECTRUMSMOOTH) * spectrumDecay[i] + SPECTRUMSMOOTH * spectrumValue[i];

         // process peak values
         if (spectrumPeaks[i] < spectrumDecay[i])
            spectrumPeaks[i] = spectrumDecay[i];
         spectrumPeaks[i] = spectrumPeaks[i] * (1.0 - PEAKDECAY);
         int decayTime = 4000;
         spectrumByte[i] = spectrumValue[i] / 4;
         // smooth results - rise fast, fall slower
         if (spectrumValue[i] > spectrumAvg[i])                                  // rise fast
            spectrumAvg[i] = spectrumValue[i] * 0.95f + 0.05f * spectrumAvg[i];  // will need approx 2 cycles (50ms) for converging against spectrumValue[i]
         else {                                                                  // fall slow
            if (decayTime < 1000)
               spectrumAvg[i] = spectrumValue[i] * 0.22f + 0.78f * spectrumAvg[i];  // approx  5 cycles (225ms) for falling to zero
            else if (decayTime < 2000)
               spectrumAvg[i] = spectrumValue[i] * 0.17f + 0.83f * spectrumAvg[i];  // default - approx  9 cycles (225ms) for falling to zero
            else if (decayTime < 3000)
               spectrumAvg[i] = spectrumValue[i] * 0.14f + 0.86f * spectrumAvg[i];  // approx 14 cycles (350ms) for falling to zero
            else
               spectrumAvg[i] = spectrumValue[i] * 0.1f + 0.9f * spectrumAvg[i];  // approx 20 cycles (500ms) for falling to zero
            analogsum += spectrumValue[i];
         }
         float currentResult;
         currentResult = spectrumAvg[i];  // use spectrumAvg[] for smoothing
         // Logarithmic scaling
         currentResult *= 0.42f;  // 42 is the answer ;-)
         currentResult -= 8.0f;   // this skips the lowest row, giving some room for peaks
         if (currentResult > 1.0f)
            currentResult = logf(currentResult);  // log to base "e", which is the fastest log() function
         else
            currentResult = 0.0f;                                  // special handling, because log(1) = 0; log(0) = undefined
         currentResult *= 0.85f + (float(i) / 18.0f);              // extra up-scaling for high frequencies
         currentResult = mapf(currentResult, 0, LOG_256, 0, 255);  // map [log(1) ... log(255)] to [0 ... 255]
         spectrumValue[i] = constrain((int)currentResult, 0, 1023);
         spectrumDecay[i] = constrain((int)spectrumDecay[i], 0, 1023);
         spectrumPeaks[i] = constrain((int)spectrumPeaks[i], 0, 1023);
         audioLevels.addBarHeight(i, constrain((int)currentResult, 0, 254));
         audioLevels.updatePeaks();
         avgVol += spectrumValue[i];
      }
      float signalMax = 0;
      float signalMin = 1024;
      avgVol /= 16;
      if (avgVol < 1024) {  // toss out spurious readings
         if (avgVol > signalMax) {
            signalMax = avgVol;  // save just the max levels
         } else if (avgVol < signalMin) {
            signalMin = avgVol;  // save just the min levels
         }
      }
      peakToPeak = signalMax - signalMin;  // max - min = peak-peak amplitude
      volume = map(peakToPeak, 0, 1024, 0, 255);

      audioLevels.addVolume(volume);

      if (volume > 100) {
         faceType = 4;
      } else if (volume < 100 && volume > 80) {
         faceType = 3;
      } else if (volume < 80 && volume > 60) {
         faceType = 2;
      } else if (volume < 60 && volume > 30) {
         faceType = 1;
      } else if (volume <= 30) {
         faceType = 0;
      }

      audioAvg = (1.0 - AGCSMOOTH) * audioAvg + AGCSMOOTH * (analogsum / NUM_BANDS);
      gainAGC = 40.0 / audioAvg;

      if (gainAGC > GAINUPPERLIMIT)
         gainAGC = GAINUPPERLIMIT;
      if (gainAGC < GAINLOWERLIMIT)
         gainAGC = GAINLOWERLIMIT;

      // if (beatDetect())
      // {
      //    cc_counter++;
      //    Serial.println(" beatDetect() triggered " + String(cc_counter) + " times.");

      vTaskDelay(microsecsToTicks(4));
   }  // for(;;)
}  // FFTcode()

void setupAudio() {
   //  vTaskDelayUntil(&xLastWakeTime, xFrequency);
   //  xLastWakeTime = xTaskGetTickCount();
   //    vTaskDelayUntil( &xLastWakeTime, xFrequency);
   // Attempt to configure INMP441 Microphone
   esp_err_t err;
   const i2s_config_t i2s_config = {

       .mode = (i2s_mode_t)(I2S_MODE_MASTER | I2S_MODE_RX),  // Receive, not transfer.
       .sample_rate = SAMPLE_RATE * 2,                       // Set the I2S sampling rate.
       .bits_per_sample = I2S_BITS_PER_SAMPLE_32BIT,         // Fixed 12-bit stereo MSB.
       .channel_format = I2S_CHANNEL_FMT_ONLY_RIGHT,         // Set the channel format.
       .communication_format = I2S_COMM_FORMAT_STAND_I2S,    // Set the format of
                                                             // the communication.
       .intr_alloc_flags = ESP_INTR_FLAG_LEVEL1,             // Set the interrupt flag.
       .dma_buf_count = 8,                                   // DMA buffer count.
       .dma_buf_len = BLOCK_SIZE,                            // DMA buffer length.
   };
   const i2s_pin_config_t pin_config = {
       .bck_io_num = I2S_SCK,  // BCLK aka SCK
       .ws_io_num = I2S_WS,    // LRCL aka WS
       .data_out_num = -1,     // not used (only for speakers)
       .data_in_num = I2S_SD   // DOUT aka SD
   };

   // Configuring the I2S driver and pins.
   // This function must be called before any I2S driver read/write
   // operations.
   err = i2s_driver_install(I2S_PORT, &i2s_config, 0, NULL);
   if (err != ESP_OK) {
      Serial.printf("Failed installing driver: %d\n", err);
      while (true)
         ;
   }
   Serial.println("I2S driver installed.");
   err = i2s_set_pin(I2S_PORT, &pin_config);
   if (err != ESP_OK) {
      Serial.printf("Failed setting pin: %d\n", err);
      while (true)
         ;
   }

   Serial.println("I2S pins OK.");
   delay(100);

   // Test to see if we have a digital microphone installed or not.
   float mean = 0.0;
   int32_t samples[BLOCK_SIZE];
   size_t num_bytes_read = 0;

   esp_err_t result = i2s_read(I2S_PORT, &samples, BLOCK_SIZE, &num_bytes_read, portMAX_DELAY);

   int samples_read = num_bytes_read / 8;
   if (samples_read > 0) {
      for (int i = 0; i < samples_read; ++i) {
         mean += samples[i];
      }
      mean = mean / BLOCK_SIZE / 16384;
      if (mean != 0.0) {
         Serial.println("Digital microphone is present.");
      } else {
         Serial.println("Digital microphone is NOT present.");
      }
   }

   //  sampling_period_us = round(1000000 * (1.0 / SAMPLE_RATE));

   xTaskCreateUniversal(  // xTaskCreateUniversal also works on -S2 and -C3 with single core
       FFTcode,           // Function to implement the task
       "FFT",             // Name of the task
       3592,              // Stack size in words // 3592 leaves 800-1024 bytes of task stack free
       NULL,              // Task input parameter
       1,                 // Priority of the task
       &FFT_Task,         // Task handle
       0                  // Core where the task should run
   );
}  // setupAudio()