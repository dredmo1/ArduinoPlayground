#include <Arduino.h>
#include <FastLED.h>

#define RUNS 20
#define NUM_LEDS 2160
#define NUM_LEDS_PER_STRIP 72
#define NUM_LEDS_PER_SEGMENT 360

// Define the data pins for the LED strips
#define DP_1 7
#define DP_2 8
#define DP_3 9
#define DP_4 10
#define DP_5 11
#define DP_6 12
// Define the LED strip type
#define LED_TYPE WS2812B
// Define the color order of the LED strip
#define COLOR_ORDER GRB

CRGB leds1[NUM_LEDS_PER_SEGMENT];
CRGB leds2[NUM_LEDS_PER_SEGMENT];
CRGB leds3[NUM_LEDS_PER_SEGMENT];
CRGB leds4[NUM_LEDS_PER_SEGMENT];
CRGB leds5[NUM_LEDS_PER_SEGMENT];
CRGB leds6[NUM_LEDS_PER_SEGMENT];

const bool DEBUG_MODE = false;

const int switchPins[] = {6, 5, 4, 3, 2}; // Pins connected to the switches

int mode = 0;

void setup() {
  if (DEBUG_MODE) {
    Serial.begin(9600);
  }
  // Initialize the LED strip
  FastLED.addLeds<LED_TYPE, DP_1, COLOR_ORDER>(leds1, NUM_LEDS_PER_SEGMENT);
  FastLED.addLeds<LED_TYPE, DP_2, COLOR_ORDER>(leds2, NUM_LEDS_PER_SEGMENT);
  FastLED.addLeds<LED_TYPE, DP_3, COLOR_ORDER>(leds3, NUM_LEDS_PER_SEGMENT);
  FastLED.addLeds<LED_TYPE, DP_4, COLOR_ORDER>(leds4, NUM_LEDS_PER_SEGMENT);
  FastLED.addLeds<LED_TYPE, DP_5, COLOR_ORDER>(leds5, NUM_LEDS_PER_SEGMENT);
  FastLED.addLeds<LED_TYPE, DP_6, COLOR_ORDER>(leds6, NUM_LEDS_PER_SEGMENT);
  FastLED.setMaxRefreshRate(0);
  FastLED.clear();

  // Initialize switch pins as inputs
  for (int i = 0; i < 5; i++) {
    pinMode(switchPins[i], INPUT_PULLUP); // Enable internal pull-up resistors
  }
}

// Animate a chase effect with a rainbow pattern.
void rainbowChase() {
  static uint8_t startIndex = 0;
  startIndex += 24; /* motion speed */

  // Iterate all LEDs to create a rainbow chase effect, do the different pins in parralel.
  for (int i = 0; i < NUM_LEDS_PER_SEGMENT; i++) {
    leds1[i] = CHSV((startIndex + (i * 2)), 255, 255);
    leds2[i] = CHSV((startIndex + (i * 2)), 255, 255);
    leds3[i] = CHSV((startIndex + (i * 2)), 255, 255);
    leds4[i] = CHSV((startIndex + (i * 2)), 255, 255);
    leds5[i] = CHSV((startIndex + (i * 2)), 255, 255);
    leds6[i] = CHSV((startIndex + (i * 2)), 255, 255);
  }
  FastLED.show();
  //delay(1); /* frame rate */
}

// Randomise LEDS flying from edge to edge in multiple ares, with a trail behind.
// Optinally pass in a colour value. If left blank, colour will be randomised.
void multipleTrails(CRGB trailColor = CRGB::Black) {
  static int tailLength = 10; // Adjust the length of the tail
  static int shootingSpeed = 50; // Adjust the speed of the shooting effect
  static unsigned long lastUpdateTime = 0;
  static int currentPosition = 0;

  // Update the shooting effect
  if (millis() - lastUpdateTime >= shootingSpeed) {
    // Move the shooting LED position
    currentPosition += 8;

    // If LED reaches the end, reset to start
    if (currentPosition >= NUM_LEDS_PER_SEGMENT) {
      currentPosition = 0;
    }

    CRGB tc = trailColor != CRGB::Black ? trailColor : CHSV(random(255), 255, 255);
    // Turn off the previous tail LEDs
    for (int i = 1; i <= tailLength; i++) {
      int tailPosition = currentPosition - i;
      if (tailPosition >= 0) {
        for (int segment = 0; segment < RUNS; segment++) {
          switch (segment) {
            case 0:
              leds1[tailPosition] = tc;
              break;
            case 1:
              leds2[tailPosition] = tc;
              break;
            case 2:
              leds3[tailPosition] = tc;
              break;
            case 3:
              leds4[tailPosition] = tc;
              break;
            case 4:
              leds5[tailPosition] = tc;
              break;
            default:
              break;
          }
        }
      }
    }

    // Turn on the shooting LED
    for (int segment = 0; segment < RUNS; segment++) {
      switch (segment) {
        case 0:
          leds1[currentPosition] = CRGB::White;
          break;
        case 1:
          leds2[currentPosition] = CRGB::White;
          break;
        case 2:
          leds3[currentPosition] = CRGB::White;
          break;
        case 3:
          leds4[currentPosition] = CRGB::White;
          break;
        case 4:
          leds5[currentPosition] = CRGB::White;
          break;
        default:
          break;
      }
    }

    // Show the updated LEDs
    FastLED.show();

    lastUpdateTime = millis();
  }
}

void loop() {
  FastLED.show();
  selectMode();
}

void selectMode() {
  // Read the state of each switch and calculate the binary value
  int binaryValue = 0;
  for (int i = 0; i < 5; i++) {
    binaryValue |= digitalRead(switchPins[i]) << i;
  }

  // Convert binary value to decimal mode
  mode = binaryValue;

  // Print the mode value to the Serial Monitor
  if (DEBUG_MODE) {
    Serial.print("Mode: ");
    Serial.print(mode);
    Serial.print(" (Binary: ");
    Serial.print(mode, BIN);
    Serial.println(")");
  }

  FastLED.clear();
  switch (mode) {
  case 0:
    rainbowChase();
    break;
  case 1:
    multipleTrails();
    break;
  case 2:
    multipleTrails(CRGB::Red);
    break;
  case 3:
    multipleTrails(CRGB::Green);
    break;
  case 4:
    multipleTrails(CRGB::Blue);
    break;
  // Add the rest 2..31 as needed.
  default:
    break;
  }
}



