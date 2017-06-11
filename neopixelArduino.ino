// requires https://github.com/kroimon/Arduino-SerialCommand

#include <SerialCommand.h>

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif

#define PIN            6

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS      16

SerialCommand sCmd;     // The demo SerialCommand object

// When we setup the NeoPixel library, we tell it how many pixels, and which pin to use to send signals.
// Note that for older NeoPixel strips you might need to change the third parameter--see the strandtest
// example for more information on possible values.
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int delayval = 500; // delay for half a second

void setup() {
  // This is for Trinket 5V 16MHz, you can remove these three lines if you are not using a Trinket
#if defined (__AVR_ATtiny85__)
  if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
#endif
  // End of trinket special code

  Serial.begin(115200);
  sCmd.addCommand("setColor",    setColor);          // Turns LED on

  pixels.begin(); // This initializes the NeoPixel library.
}

void loop() {
  sCmd.readSerial();
}

void setColor() {
  char *arg;
  arg = sCmd.next();
  uint32_t c = pixels.Color(0, 0, 0);
  switch (arg[0]) {
    case 'r':
      c = pixels.Color(250, 0, 0);
      break;
    case 'g':
      c = pixels.Color(0, 250, 0);
      break;
    case 'b':
      c = pixels.Color(0, 0, 250);
      break;
  }
  for (int i = 0; i < 3; i++)
    pixels.setPixelColor(i, c);
  //pixels.setPixelColor(arg[0], pixels.Color(0, 150, 0));
  pixels.show();
}
