// #include <Arduino.h>
// #include <FastLED.h>

// void whiteBreathingChase() {
//   static uint8_t startIndex = 0;
//   startIndex = startIndex + 1; /* motion speed */
//   for (int i = 0; i < NUM_LEDS; i++) {
//     leds[i] = CRGB::White;
//   }
//   FastLED.show();
//   delay(1000 / 600); /* frame rate */
//   // Doesn't seem to work, lights are always white the whole way along the strip, there's no chase effect.
//   // FastLED.clear();
//   // FastLED.show();
  
// }
