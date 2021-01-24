#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

// Define digital pin for LED Signal
#define LED_PIN 8

// Number of LEDs in series
#define LED_COUNT 19

// Declare our NeoPixel strip object:
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

const int ledPin = 13;      // LED connected to digital pin 13
const int knockSensor = A0; // the piezo is connected to analog pin 0
const int threshold = 50;   // threshold value to decide when the detected sound is a knock or not
int sensorReading = 0;      // variablet to store knock sensor reading

void setup()
{
// These lines are specifically to support the Adafruit Trinket 5V 16 MHz.
// Any other board, you can remove this part (but no harm leaving it):
#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
#endif
  // END of Trinket-specific code.

  pinMode(ledPin, OUTPUT); // declare the ledPin as as OUTPUT
  strip.begin();           // INITIALIZE NeoPixel strip object (REQUIRED)
  strip.show();            // Turn OFF all pixels ASAP
  strip.setBrightness(30); // Set BRIGHTNESS
}

void loop()
{
  // put your main code here, to run repeatedly:
  // read the sensor and store it in the variable sensorReading:
  sensorReading = analogRead(knockSensor);
  Serial.println(sensorReading);

  // if the sensor reading is greater than the threshold alaternate LEDs between red and blue five times
  if (sensorReading >= threshold)
  {
    strip.setBrightness(100);
    for (int i = 0; i < 5; i++)
    {
      for (int i = 0; i < 9; i++)
      {
        strip.setPixelColor(i, 255, 0, 0);
      };
      for (int i = 10; i < 20; i++)
      {
        strip.setPixelColor(i, 0, 0, 255);
      }
      strip.show();
      delay(300);
      for (int i = 0; i < 5; i++)
      {
        for (int i = 0; i < 9; i++)
        {
          strip.setPixelColor(i, 0, 0, 255);
        };
        for (int i = 10; i < 20; i++)
        {
          strip.setPixelColor(i, 255, 0, 0);
        }
      }
      strip.show();
      delay(300);
    };
    // reset LEDs to a dim white rest state
    strip.setBrightness(25);

    for (int i = 0; i < 20; i++)
    {
      strip.setPixelColor(i, 255, 255, 255);
    }
    strip.show();
  }
}
