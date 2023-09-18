

#pragma once
#define VISUALIZATION_EMULATE_INPUT
#include "D_include.h"
#define DEBUG true
#define ARRAY_SIZE(A) (sizeof(A) / sizeof((A)[0]))
#define CENTER_LED_MATRIX (NUM_LED_MATRIX / 2)
#define PAL_M(val) ColorFromPalette(currentPaletteMatrix, val)
#define PAL_S(val) ColorFromPalette(currentPaletteStripe, val)
#define PAL_C(val) ColorFromPalette(currentPaletteClock, val)
#define FOR_i(from, to) for (int i = (from); i < (to); i++)  // loop for "i" to ascending
#define ARRAYSIZE(a) (sizeof(a) / sizeof(a[0]))
#define qsuba(x, b) ((x > b) ? x - b : 0)
#define RGBW32(r, g, b, w) (uint32_t((byte(w) << 24) | (byte(r) << 16) | (byte(g) << 8) | (byte(b))))
#define SERIAL_BAUD_RATE 115200   // Serial baud rate used for debugging and the virtual matrix
#define TOP (kMATRIX_HEIGHT - 0)  // Don't allow the bars to go offscreen
#define UM_AUDIOREACTIVE_USE_NEW_FFT
#define MATRIX_WIDTH 32  // X-Dimension of the matrix
#define MATRIX_HEIGHT 8  // Y-Dimension of the matrix
#define MATRIX_CENTER_X (MATRIX_WIDTH / 2)
#define MATRIX_CENTER_Y (MATRIX_HEIGHT / 2)
#define MATRIX_DATA_PIN 14
#define STRIP_DATA_PIN 12
#define NUM_LED_MATRIX MATRIX_WIDTH* MATRIX_HEIGHT
#define STRIPE_LED_AMOUNT 114
#define BRIGHTNESS 255  // INITIAL BRIGHNESS OF THE MATRIX.
#define VOLTAGE 5       // THE VOLTAGE OUR SYSTEM USES
#define AMPS 5000       // THE CURRENT THAT YOUR POWERBRICK CAN DELIVER e.g 5 AMP (or 5000 mA)

#define STRIPE_LED_AMOUNT 114
#define NUM_LED_STRIPE STRIPE_LED_AMOUNT
#define SEGLEN STRIPE_LED_AMOUNT
#define FRAMETIME 20
#define FRAMES_PER_SECOND 120
#define SEGCOLOR(x) CRGB::Red
#define NUM_COLORS 3

#ifdef SR_DEBUG
#   define DEBUGSR_PRINT(x) DEBUGOUT.print(x)
#   define DEBUGSR_PRINTLN(x) DEBUGOUT.println(x)
#   define DEBUGSR_PRINTF(x...) DEBUGOUT.printf(x)
#else
#   define DEBUGSR_PRINT(x)
#   define DEBUGSR_PRINTLN(x)
#   define DEBUGSR_PRINTF(x...)
#endif

#if defined(MIC_LOGGER) || defined(FFT_SAMPLING_LOG)
#   define PLOT_PRINT(x) DEBUGOUT.print(x)
#   define PLOT_PRINTLN(x) DEBUGOUT.println(x)
#   define PLOT_PRINTF(x...) DEBUGOUT.printf(x)
#else
#   define PLOT_PRINT(x)
#   define PLOT_PRINTLN(x)
#   define PLOT_PRINTF(x...)
#endif
uint16_t mXY(uint16_t x, uint16_t y);
bool showMessage;

bool kMatrixSerpentineLayout = true;
bool kMatrixVertical = true;
uint8_t kMATRIX_HEIGHT = 8;  // 64;                   // Matrix height -->
                             // number of matrix_Array per column
uint8_t kMATRIX_WIDTH = 32;  // 64;                   // Matrix width

CRGB clock_array[NUM_LED_MATRIX];
CRGB matrix_Array[NUM_LED_MATRIX];
CRGB stripe_Array[NUM_LED_STRIPE];
CRGB output_array[NUM_LED_MATRIX];
CRGB clock_effect_Array[NUM_LED_MATRIX];

CLEDController* MatrtixController;
CLEDController* StripeController;

// FastLED_NeoMatrix *Fast_led_matrix =
//     new FastLED_NeoMatrix(clock_array, MATRIX_WIDTH, MATRIX_HEIGHT,
//     NEO_MATRIX_TOP + NEO_MATRIX_LEFT + NEO_MATRIX_COLUMNS +
//     NEO_MATRIX_ZIGZAG);

Preferences preferences;
BarHeightsA audioLevels;
///////////////
/// i2s FFT ///
///////////////

#define I2S_WS 25   // aka LRCL
#define I2S_SD 32   // aka DOUT
#define I2S_SCK 27  // aka BCLK
#define numBands 16
// int fftResult[16]; // Our calculated result table, which we feed to the
// animations.
uint8_t fftData;
const uint16_t samples = 1024;  // This value MUST ALWAYS be a power of 2
double fftBin[samples];
const int BLOCK_SIZE = samples / 8;
float fft_input[samples];
float fft_output[samples];
#define MIN_SHOW_DELAY 15

int faceType;

#define NUM_BANDS 16

float spectrumValue[NUM_BANDS];        // holds raw adc values
float spectrumDecay[NUM_BANDS] = {0};  // holds time-averaged values
float spectrumPeaks[NUM_BANDS] = {0};  // holds peak values
float spectrumAvg[NUM_BANDS] = {0};    // holds averaged values
float audioAvg = 50.0;
float gainAGC = 0.0;
uint8_t spectrumByte[NUM_BANDS];  // holds 8-bit adjusted adc values
#define ARDUINO_ARCH_ESP32 1
int16_t micIn = 0;                // Current sample starts with negative values and large
                                  // values, which is why it's 16 bit signed
static float micDataReal = 0.0f;  // MicIn data with full 24bit resolution -
                                  // lowest 8bit after decimal point
double micLev = 0.0;              // Used to convert returned value to have '0' as minimum. A leveller
float expAdjF = 0.0f;             // Used for exponential filter.
uint8_t soundSquelch = 10;        // squelch value for volume reactive routines (config value)
uint8_t sampleGain = 60;          // sample gain (config value)
static uint8_t inputLevel = 128;  // UI slider value
double sampleMax = 0.0;           // Max sample over a few seconds. Needed for AGC controler.
static bool samplePeak2 = false;  // Boolean flag for peak. Set at the same tiem as samplePeak, but
                                  // reset by transmitAudioData
static float multAgc = 1.0f;      // sample * multAgc = sampleAgc. Our AGC multiplier

#define FFT_MIN_CYCLE 21                              // minimum time before FFT task is repeated. Use with 22Khz sampling
static volatile bool disableSoundProcessing = false;  // if true, sound processing (FFT, filters, AGC) will be suspended.
                                                      // "volatile" as its shared between tasks.
static uint8_t audioSyncEnabled = 0;                  // bit field: bit 0 - send, bit 1 - receive (config value)

#define MIN_SHOW_DELAY 15

int squelch = 5;     // Squelch, cuts out low level sounds
int gain = 25;       // Gain, boosts input level*/
uint16_t micData;    // Analog input for FFT
uint16_t micDataSm;  // Smoothed mic data, as it's a bit twitchy

unsigned int sampling_period_us;
unsigned long microseconds;
int vMax = 0, vMin = 100;
// float FFT_MajorPeak = 0;
// float FFT_Magnitude = 0;
uint16_t mAvg = 0;

// These are the input and output vectors.  Input vectors receive computed
// results from FFT. float vReal[samples]; float vImag[samples];

// Try and normalize fftBin values to a max of 4096, so that 4096/16 = 256.
// Oh, and bins 0,1,2 are no good, so we'll zero them out.
// double fftCalc[32];
float oldFftCalc[32];
// Table of linearNoise results to be multiplied by squelch in order to reduce
// squelch across fftResult bins. int linearNoise[32] = {34, 28, 26, 25, 20, 12,
// 9, 6, 4, 4, 3, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2};
volatile float gVU = 0;    // Instantaneous read of VU value
volatile float oldVU = 0;  // Previous read of VU value

// Table of multiplication factors so that we can even out the frequency
// response. double fftResultPink[32] =
// {1.70, 1.71, 1.73, 1.78, 1.68, 1.56, 1.55, 1.63, 1.79, 1.62, 1.80,
//                             2.06, 2.47, 3.35, 6.83, 9.55, 1.70, 1.71, 1.73, 1.78,
//                             1.68, 1.56,
//                             1.55, 1.63, 1.79, 1.62, 1.80, 2.06, 2.47, 3.35, 6.83,
//                             9.55};
static float windowWeighingFactors[samples] = {0.0f};
// Create FFT object
// arduinoFFT FFT = arduinoFFT(vReal, vImag, samples, SAMPLE_RATE);

bool useBandPassFilter = true;

bool bump = false;

uint8_t volume = 0;  // Holds the volume level read from the sound detector.
float avgBump = 0;   // Holds the "average" volume-change to trigger a "bump."
float avgVol = 0;    // Holds the "average" volume-level to proportionally adjust
                     // the visual experience.
uint8_t last = 0;    // Holds the value of volume from the previous loop() pass.
float timeBump = 0;  // Holds the time (in runtime seconds) the last "bump" occurred.
float avgTime = 0;   // Holds the "average" amount of time between each "bump"
                     // (used for pacing the dot's movement).
////////////////////////////////////////////////////////////////////////////////////////////////////////
static float sampleAvg = 0.0f;  // Smoothed Average sample - sampleAvg < 1 means
                                // "quiet" (simple noise gate)
float sampleReal = 0.0f;        // "sampleRaw" as float, to provide bits that are lost
                                // otherwise (before amplification by sampleGain or
                                // inputLevel). Needed for AGC.
int16_t sampleRaw = 0;          // Current sample. Must only be updated ONCE!!!
                                // (amplified mic value by sampleGain and inputLevel)
float volumeSmth = 0.0f;        // either sampleAvg or sampleAgc depending on
                                // soundAgc; smoothed sample
int16_t volumeRaw = 0;          // either sampleRaw or rawSampleAgc depending on soundAgc
float my_magnitude = 0.0f;      // FFT_Magnitude, scaled by multAgc
static float sampleAgc = 0.0f;  // Smoothed AGC sample
int16_t rawSampleAgc = 0;       // not smoothed AGC sample

// static uint8_t binNum = 8;           // Used to select the bin for FFT based
// beat detection  (deprecated) static unsigned long timeOfPeak = 0; // time of
// last sample peak detection. static bool samplePeak = false;      // Boolean
// flag for peak - used in effects. Responding routine may reset this flag.
// Auto-reset after strip.getMinShowDelay()
float beatSample;
uint8_t soundAgc = 1;
#define MAX(a, b) ((a) > (b) ? (a) : (b))
static float FFT_MajPeakSmth = 1.0f;  // FFT: (peak) frequency, smooth

/*
 * Usermods allow you to add own functionality to WLED more easily
 * See: https://github.com/Aircoookie/WLED/wiki/Add-own-functionality
 *
 * This is an audioreactive v2 usermod.
 * ....
 */

// Comment/Uncomment to toggle usb serial debugging
// #define MIC_LOGGER                   // MIC sampling & sound input debugging
// (serial plotter) #define FFT_SAMPLING_LOG             // FFT result debugging
// #define SR_DEBUG                     // generic SR DEBUG messages

#ifdef SR_DEBUG
#   define DEBUGSR_PRINT(x) DEBUGOUT.print(x)
#   define DEBUGSR_PRINTLN(x) DEBUGOUT.println(x)
#   define DEBUGSR_PRINTF(x...) DEBUGOUT.printf(x)
#else
#   define DEBUGSR_PRINT(x)
#   define DEBUGSR_PRINTLN(x)
#   define DEBUGSR_PRINTF(x...)
#endif

#if defined(MIC_LOGGER) || defined(FFT_SAMPLING_LOG)
#   define PLOT_PRINT(x) DEBUGOUT.print(x)
#   define PLOT_PRINTLN(x) DEBUGOUT.println(x)
#   define PLOT_PRINTF(x...) DEBUGOUT.printf(x)
#else
#   define PLOT_PRINT(x)
#   define PLOT_PRINTLN(x)
#   define PLOT_PRINTF(x...)
#endif

// use audio source class (ESP32 specific)

// constexpr i2s_port_t I2S_PORT = I2S_NUM_0; // I2S port to use (do not change
// !)

// globals

#ifndef SR_SQUELCH

#else
uint8_t soundSquelch = SR_SQUELCH;     // squelch value for volume reactive routines (config value)
#endif
#ifndef SR_GAIN

#else
uint8_t sampleGain = SR_GAIN;          // sample gain (config value)
#endif

static bool udpSyncConnected = false;  // UDP connection status -> true if connected to multicast group

// user settable parameters for limitSoundDynamics()
static bool limiterOn = true;      // bool: enable / disable dynamics limiter
static uint16_t attackTime = 80;   // int: attack time in milliseconds. Default 0.08sec
static uint16_t decayTime = 1400;  // int: decay time in milliseconds.  Default 1.40sec
// user settable options for FFTResult scaling
static uint8_t FFTScalingMode = 3;  // 0 none; 1 optimized logarithmic; 2
                                    // optimized linear; 3 optimized sqare root

//
// AGC presets
//  Note: in C++, "const" implies "static" - no need to explicitly declare
//  everything as "static const"
//
#define AGC_NUM_PRESETS 3                                                            // AGC presets:          normal,   vivid,    lazy
const double agcSampleDecay[AGC_NUM_PRESETS] = {0.9994f, 0.9985f, 0.9997f};          // decay factor for sampleMax, in case the
                                                                                     // current sample is below sampleMax
const float agcZoneLow[AGC_NUM_PRESETS] = {32, 28, 36};                              // low volume emergency zone
const float agcZoneHigh[AGC_NUM_PRESETS] = {240, 240, 248};                          // high volume emergency zone
const float agcZoneStop[AGC_NUM_PRESETS] = {336, 448, 304};                          // disable AGC integrator if we get above this level
const float agcTarget0[AGC_NUM_PRESETS] = {112, 144, 164};                           // first AGC setPoint -> between 40% and 65%
const float agcTarget0Up[AGC_NUM_PRESETS] = {88, 64, 116};                           // setpoint switching value (a poor man's bang-bang)
const float agcTarget1[AGC_NUM_PRESETS] = {220, 224, 216};                           // second AGC setPoint -> around 85%
const double agcFollowFast[AGC_NUM_PRESETS] = {1 / 192.f, 1 / 128.f, 1 / 256.f};     // quickly follow setpoint - ~0.15 sec
const double agcFollowSlow[AGC_NUM_PRESETS] = {1 / 6144.f, 1 / 4096.f, 1 / 8192.f};  // slowly follow setpoint  - ~2-15 secs
const double agcControlKp[AGC_NUM_PRESETS] = {0.6f, 1.5f, 0.65f};                    // AGC - PI control, proportional gain parameter
const double agcControlKi[AGC_NUM_PRESETS] = {1.7f, 1.85f, 1.2f};                    // AGC - PI control, integral gain parameter
const float agcSampleSmooth[AGC_NUM_PRESETS] = {1 / 12.f, 1 / 6.f, 1 / 16.f};        // smoothing factor for sampleAgc (use rawSampleAgc if you
                                                                                     // want the non-smoothed value)
// AGC presets end

// peak detection
static bool samplePeak = false;  // Boolean flag for peak - used in effects. Responding routine may
                                 // reset this flag. Auto-reset after strip.getMinShowDelay()
static uint8_t maxVol = 10;      // Reasonable value for constant volume for 'peak detector', as it
                                 // won't always trigger (deprecated)
static uint8_t binNum = 8;       // Used to select the bin for FFT based beat detection  (deprecated)

static unsigned long timeOfPeak = 0;  // time of last sample peak detection.
static void detectSamplePeak(void);   // peak detection function (needs scaled FFT reasults in vReal[])
static void autoResetPeak(void);      // peak auto-reset function

////////////////////
// Begin FFT Code //
////////////////////

#define NUM_GEQ_CHANNELS 16  // number of frequency channels. Don't change !!

TaskHandle_t FFT_Task;

// Table of multiplication factors so that we can even out the frequency
// response.
static float fftResultPink[NUM_GEQ_CHANNELS] = {1.70f, 1.71f, 1.73f, 1.78f, 1.68f, 1.56f, 1.55f, 1.63f, 1.79f, 1.62f, 1.80f, 2.06f, 2.47f, 3.35f, 6.83f, 9.55f};

// globals and FFT Output variables shared with animations
static float FFT_MajorPeak = 1.0f;                 // FFT: strongest (peak) frequency
static float FFT_Magnitude = 0.0f;                 // FFT: volume (magnitude) of peak frequency
static uint8_t fftResult[NUM_GEQ_CHANNELS] = {0};  // Our calculated freq. channel result table to be used by effects
#if defined(WLED_DEBUG) || defined(SR_DEBUG)
static uint64_t fftTime = 0;
static uint64_t sampleTime = 0;
#endif

// FFT Task variables (filtering and post-processing)
static float fftCalc[NUM_GEQ_CHANNELS] = {0.0f};  // Try and normalize fftBin values to a max of 4096, so that 4096/16
                                                  // = 256.
static float fftAvg[NUM_GEQ_CHANNELS] = {0.0f};   // Calculated frequency channel results, with smoothing (used if
                                                  // dynamics limiter is ON)
#ifdef SR_DEBUG
static float fftResultMax[NUM_GEQ_CHANNELS] = {0.0f};  // A table used for testing to determine how our post-processing
                                                       // is working.
#endif
#define microsecsToTicks(us) ((us)*configTICK_RATE_HZ / 1000000L)
// audio source parameters and constant
// constexpr SRate_t SAMPLE_RATE =
//     22050; // Base sample rate in Hz - 22Khz is a standard rate. Physical
//     sample time -> 23ms
// constexpr SRate_t SAMPLE_RATE = 16000;        // 16kHz - use if FFTtask takes
// more than 20ms. Physical sample time -> 32ms constexpr SRate_t SAMPLE_RATE =
// 20480;        // Base sample rate in Hz - 20Khz is experimental.    Physical
// sample time -> 25ms constexpr SRate_t SAMPLE_RATE = 10240;        // Base
// sample rate in Hz - previous default. Physical sample time -> 50ms
#define FFT_MIN_CYCLE 21  // minimum time before FFT task is repeated. Use with 22Khz sampling
// #define FFT_MIN_CYCLE 30                      // Use with 16Khz sampling
// #define FFT_MIN_CYCLE 23                      // minimum time before FFT task
// is repeated. Use with 20Khz sampling #define FFT_MIN_CYCLE 46 // minimum time
// before FFT task is repeated. Use with 10Khz sampling

// FFT Constants
constexpr uint16_t samplesFFT = 512;    // Samples in an FFT batch - This value MUST ALWAYS be a power of 2
constexpr uint16_t samplesFFT_2 = 256;  // meaningfull part of FFT results - only the "lower half" contains
                                        // useful information.
// the following are observed values, supported by a bit of "educated guessing"
// #define FFT_DOWNSCALE 0.65f                             // 20kHz -
// downscaling factor for FFT results - "Flat-Top" window @20Khz, old freq
// channels
#define FFT_DOWNSCALE \
   0.46f                     // downscaling factor for FFT results - for "Flat-Top" window @22Khz,
                             // new freq channels
#define LOG_256 5.54517744f  // log(256)

// These are the input and output vectors.  Input vectors receive computed
// results from FFT.
static float vReal[samples] = {0.0f};  // FFT sample inputs / freq output -  these are our raw result bins
static float vImag[samples] = {0.0f};  // imaginary parts
#ifdef UM_AUDIOREACTIVE_USE_NEW_FFT
// static float windowWeighingFactors[samplesFFT] = {0.0f};
#endif
// #define SAMPLE_RATE 44100  //
// Create FFT object
#ifdef UM_AUDIOREACTIVE_USE_NEW_FFT
// lib_deps += https://github.com/kosme/arduinoFFT#develop @ 1.9.2
#   define FFT_SPEED_OVER_PRECISION  // enables use of reciprocals (1/x etc), and
                                     // an a few other speedups
#   define FFT_SQRT_APPROXIMATION    // enables "quake3" style inverse sqrt
#   define sqrt(x) \
      sqrtf(x)  // little hack that reduces FFT time by 50% on ESP32 (as
                // alternative to FFT_SQRT_APPROXIMATION)
#else
                                       // lib_deps +=
                                       // https://github.com/blazoncek/arduinoFFT.git
#endif
// #include <arduinoFFT.h>

#ifdef UM_AUDIOREACTIVE_USE_NEW_FFT
// static ArduinoFFT<float> FFT = ArduinoFFT<float>(vReal, vImag, samplesFFT, SAMPLE_RATE);
#else
                                       // static arduinoFFT FFT =
                                       // arduinoFFT(vReal, vImag,
                                       // samplesFFT, SAMPLE_RATE);
#endif
// static ArduinoFFT<float> FFT = ArduinoFFT<float>(vReal, vImag, samples,
// SAMPLE_RATE, windowWeighingFactors);
////////////////
/// PATTERNS ///
////////////////

uint8_t currentMatrixPattern = 0;
uint8_t currentStripePattern = 0;
uint8_t currentClockPattern = 0;
uint8_t currentPaletteStripeIndex = 0;
uint8_t currentPaletteMatrixIndex = 0;
uint8_t currentPaletteClockIndex = 0;

uint8_t color_hue = 0;
uint8_t color_hue_fast = 0;
uint8_t color_hue_slow = 0;
float temp_hue = 0;
///////////////
/// PALETTE ///
///////////////

CRGBPalette16 currentPaletteStripe;
CRGBPalette16 targetPaletteStripe;

CRGBPalette16 currentPaletteMatrix;
CRGBPalette16 targetPaletteMatrix;

CRGBPalette16 currentPaletteClock;
CRGBPalette16 targetPaletteClock;

/////////////
/// NOISE ///
/////////////

uint32_t noise_x;
uint32_t noise_y;
uint32_t noise_z;
uint32_t noise_scale_x;
uint32_t noise_scale_y;
uint8_t noise[MATRIX_WIDTH][MATRIX_HEIGHT];
// uint8_t **noise = nullptr;  // we will allocate mem later
uint8_t noisesmoothing;

/////////////////
/// WEBSERVER ///
/////////////////

AsyncWebServer server(80);
int timerWiFi;
boolean connectedToNetwork;
// user settings /
bool isAudioMatrix;
bool isAudioStripe;
bool powerOnOff = true;
bool clockOnOff;
bool vuMeterOnOff;
CRGB clockColor;
int micSquelch;
int micSensytivity;
float smoothingValue;
int matrixSpeed;
int stripeSpeed;
String welcomeMessage;
String isAudioReactive =
    "<div class=' bg-gray-300 text-danger' id='isAudio' style='font-weight: "
    "900;display: "
    "inline-block;text-decoration: underline red;'> AUDIO REACTIVE</div>";
String isStaticpattern =
    "<div class=' bg-gray-600 text-warning' id='isAudio' style='font-weight: "
    "900;display: "
    "inline-block;text-decoration: underline #f6c23e;'> STATIC</div>";
int matrixBrightness;
int stripBrightness = 255;
bool detectedBeat = false;
bool clockGradient = false;
////////////////////////////
/// CLOCK & TIME SETTING ///
////////////////////////////
// ESP32Time rtc;
// ESP32Time rtc(0);                            // offset in seconds GMT+1
const char* ntpServer = "0.nl.pool.ntp.org";  // THIS IS THE WEB ADDRESS OF THE
                                              // EUROPEAN NETWORK TIME SERVER
const long gmtOffset_sec = 3600;              // WE LIVE IN THE NETHERLANDS => UTC+1H
const int daylightOffset_sec = 3600;          // YES THE NETHERLANDS IS STILL ON DAYLIGHT SAVINGS
const char* defaultTimezone = "CET-1CEST-2,M3.5.0/02:00:00,M10.5.0/03:00:00";
struct tm timeinfo;  // TIME OBJECT
int Seconde;
int OldSeconde;
int Minute;
int OldMinute;
int Hour;
int OldHour;
bool timeNTPFailed;
// int Day;
// int Month;
// int Year;

bool resetClockArray = false;
typedef void (*SimplePatterna)();
typedef struct {
   SimplePatterna drawFrame;
   String name;
   uint16_t speed;
   bool isAudio;

} PatternAndName;
typedef PatternAndName patterns_vis[];
