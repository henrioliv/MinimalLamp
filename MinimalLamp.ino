#include <Adafruit_NeoPixel.h>

#define LED_PIN    4
#define LED_COUNT 37

// Declare our NeoPixel strip object:
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);
// Argument 1 = Number of pixels in NeoPixel strip
// Argument 2 = Arduino pin number (most are valid)
// Argument 3 = Pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
//   NEO_RGBW    Pixels are wired for RGBW bitstream (NeoPixel RGBW products)

int duration = 80;
int brightness = 25;
int red = 0;
int green = 0;
int blue = 0;

//////  MENU SERIAL   //////////
int msg = 0;

//// Animation variables

enum animation_modes {
  OFF = 0,
  COLORWIPE = 1,
  CURTAINS = 2 ,
  DIAMONDS = 3 ,
  RANDOM_DIAMONDS = 4,
  THEATER = 5
};

typedef enum animation_modes animation_modes;
animation_modes animation_mode = OFF;
uint8_t number_of_modes = 6; // plus off mode

//// Palletes variables

enum palettes_modes {
  RETROWAVE = 0,
  RAINBOW   = 1,
  PINK      = 2,
  RED       = 3,
  ORANGE    = 4,
  YELLOW    = 5,
  BROWN     = 6,
  GREEN     = 7,
  CYAN      = 8,
  BLUE      = 9,
  PURPLE    = 10,
  WHITE     = 11,
  BLACK     = 12
};

typedef enum palettes_modes palettes_modes;
palettes_modes palettes_mode = RETROWAVE;
uint8_t number_of_palettes = 13; // plus off mode
int line = 0;  // Pallete line global counter

void setup() {
  strip.begin();           // INITIALIZE NeoPixel strip object (REQUIRED)
  strip.show();            // Turn OFF all pixels ASAP
  strip.setBrightness(brightness); // Set BRIGHTNESS (max = 255)
  Serial.begin(115200);
  Serial.println("Minimalist Lamp v0\n");
  Serial.println("Press x for help\n");

  Serial.println("Starting the lamp with a random configuration");
  animation_mode = animation_modes(random(0, number_of_modes));
  duration = 200;
  palettes_mode = palettes_modes(random(0, number_of_palettes));
  Serial.println("\nCurrent setup is\n");
  Serial.print("Brigthness \t\t");
  Serial.print(brightness);
  Serial.println("/255");
  Serial.print("Update period \t\t");
  Serial.print(duration);
  Serial.println(" ms");
  Serial.print("Selected Pallet \t");
  Serial.println(palettes_modes(palettes_mode));
  Serial.print("Selected animation \t");
  Serial.println(animation_mode);
}
