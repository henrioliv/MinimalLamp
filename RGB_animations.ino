void colorWipe(uint32_t color, int wait) {
  for (unsigned int i = 0; i < strip.numPixels(); i++) { // For each pixel in strip...
    strip.setPixelColor(i, color);         //  Set pixel's color (in RAM)
    strip.show();                          //  Update strip to match
    delay(wait);                           //  Pause for a moment
  }
}


void colorCurtains(uint32_t color, int wait) {
  for (int i = 0; i <= int(strip.numPixels() / 2); i++) { // For each pixel in strip...
    strip.setPixelColor(i, color);         //  Set pixel's color (in RAM)
    strip.setPixelColor(strip.numPixels() - i, color);       //  Set pixel's color (in RAM)
    strip.show();                          //  Update strip to match
    delay(wait);                           //  Pause for a moment
  }
}


void colorDiamonds(uint32_t color, int wait) {
  int number_of_pixels_4 = strip.numPixels() / 4;

  for (int i = 0; i <= int(strip.numPixels() / 4); i++) { // For each pixel in strip...
    strip.setPixelColor(number_of_pixels_4 - i, color);      //  Set pixel's color (in RAM)
    strip.setPixelColor(number_of_pixels_4 + i, color);      //  Set pixel's color (in RAM)
    strip.setPixelColor((number_of_pixels_4 * 3) - i, color);      //  Set pixel's color (in RAM)
    strip.setPixelColor((number_of_pixels_4 * 3) + i, color);      //  Set pixel's color (in RAM)
    strip.show();                          //  Update strip to match
    delay(wait);                           //  Pause for a moment
  }
}


void colorRandomDiamonds(uint32_t color, int wait) {
  int number_of_pixels_4 = random(strip.numPixels() / 3, strip.numPixels());
  int number_of_pixels_to_updade = random(1, 5);

  for (int i = 0; i <= int(strip.numPixels() / number_of_pixels_to_updade); i++) { // For each pixel in strip...
    strip.setPixelColor(number_of_pixels_4 - i, color);      //  Set pixel's color (in RAM)
    strip.setPixelColor(number_of_pixels_4 + i, color);      //  Set pixel's color (in RAM)
    strip.setPixelColor(number_of_pixels_4 * 3 - i, color);      //  Set pixel's color (in RAM)
    strip.setPixelColor(number_of_pixels_4 * 3 + i, color);      //  Set pixel's color (in RAM)
    strip.show();                          //  Update strip to match
    delay(wait);                           //  Pause for a moment
  }
}


// Theater-marquee-style chasing lights. Pass in a color (32-bit value,
// a la strip.Color(r,g,b) as mentioned above), and a delay time (in ms)
// between frames.
void theaterChase(uint32_t color, int wait) {
  for (int a = 0; a < 10; a++) { // Repeat 10 times...
    for (int b = 0; b < 3; b++) { //  'b' counts from 0 to 2...
      strip.clear();         //   Set all pixels in RAM to 0 (off)
      // 'c' counts up from 'b' to end of strip in steps of 3...
      for (unsigned int c = b; c < strip.numPixels(); c += 3) {
        strip.setPixelColor(c, color); // Set pixel 'c' to value 'color'
      }
      strip.show(); // Update strip with new contents
      delay(wait);  // Pause for a moment
    }
  }
}


void turn_off() {
  strip.clear();
  strip.show();
}
