#include <Arduino.h>
#include <FastLED.h>

#define RUNS 20
#define NUM_LEDS 2160
#define NUM_LEDS_PER_STRIP 72
#define NUM_LEDS_PER_SEGMENT 360

// Define the data pins for the LED strips
#define DP_1 7
// Define the LED strip type
#define LED_TYPE WS2812B
// Define the color order of the LED strip
#define COLOR_ORDER GRB

CRGB leds[NUM_LEDS];

const bool DEBUG_MODE = false;

const int switchPins[] = {2, 3, 4, 5, 6}; // Pins connected to the switches

int mode = 0;

void setup() {
  if (DEBUG_MODE) {
    Serial.begin(9600);
  }
  // Initialize the LED strip
  FastLED.addLeds<LED_TYPE, DP_1, COLOR_ORDER>(leds, NUM_LEDS);
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
  startIndex += 10; /* motion speed */

  // Iterate all LEDs to create a rainbow chase effect, do the different pins in parralel.
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CHSV((startIndex + (i * 2)), 255, 255);
  }

  delay(1); /* frame rate */
}

void whiteBreathingChase() {
  static int position = 0;
  static int direction = 1;

  // Move the position of the chase effect
  position += direction;

  // Change direction if the chase reaches the end of the strip
  if (position == NUM_LEDS - 1 || position == 0) {
    direction *= -1;
  }

  // Update LED colors
  for (int i = 0; i < NUM_LEDS; i++) {
    // Set all LEDs to off
    leds[i] = CRGB::Black;
  }

  // Set the position of the chase effect to white
  leds[position] = CRGB::White;

  // Set tail effect
  for (int i = 1; i <= 3; i++) {
    int tailPosition = position - i;
    if (tailPosition >= 0) {
      leds[tailPosition] = CRGB(255 / (i + 1), 255 / (i + 1), 255 / (i + 1)); // Dim the tail effect
    }
  }

  // Show the updated LED colors
  FastLED.show();

  // Pause for the chase speed
  delay(50);
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
    whiteBreathingChase();
    break;
  // Add the rest 2..31 as needed.
  default:
    break;
  }
}
