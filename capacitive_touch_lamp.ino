#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#define PIN 6
#define NUM_LEDS 16
#define BRIGHTNESS 100
#define ledPin 13

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  pinMode(ledPin, OUTPUT);
  strip.begin();
  strip.setBrightness(BRIGHTNESS);
  strip.show(); // Initialize all pixels to 'off'
  Serial.begin(9600);
}

void loop() {

  if (Serial.available())  
  {
     int var = (Serial.read() - '0');  // convert the character '1'-'9' to decimal 1-9

     switch(var)
     {
        case 1:
          yoda();
          break;
        case 2:
          luke();
          break;
        case 3:
          vader();
          break;
        case 4:
          vaderBreathing();
          break; 
     }
  }
  delay(500);

  //colorWipe(strip.Color(255, 0, 0), 50); // Red
  //colorWipe(strip.Color(0, 255, 0), 50); // Green
  //clearRing();
  //strip.show();
  //delay(1000);
  //clearColor(0,0,0,35);
  //rainbow(20);
  //rainbowCycle(20);
}

void yoda() {
  //blink(1);
  colorPulse(0, 255, 0, 100, 100);
  clearRing();
  strip.show();
  delay(100);
}

void luke() {
  //blink(2);
  colorPulse(0, 255, 0, 100, 100);
  clearRing();
  strip.show();
  delay(100); 
}

void vader() {
  //blink(3);
  colorPulse(255, 0, 0, 100, 100);
  clearRing();
  strip.show();
  delay(100);
}

void vaderBreathing() {
  //blink(4);
  colorPulse(255, 0, 0, 100, 100);
  clearRing();
  strip.show();
  delay(100);
}

// Fill the dots one after the other with a color
void colorWipe(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<strip.numPixels(); i++) {
    strip.setPixelColor(i, c);
    strip.show();
    delay(wait);
  }
}

void rainbow(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256; j++) {
    for(i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel((i+j) & 255));
    }
    strip.show();
    delay(wait);
  }
}

// Slightly different, this makes the rainbow equally distributed throughout
void rainbowCycle(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256*5; j++) { // 5 cycles of all colors on wheel
    for(i=0; i< strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel(((i * 256 / strip.numPixels()) + j) & 255));
    }
    strip.show();
    delay(wait);
  }
}

// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) {
    return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if(WheelPos < 170) {
    WheelPos -= 85;
    return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}

void colorPulse(int r, int g, int b, uint8_t wait, uint8_t waitExtra) {
  clearRing();
  strip.show();
  delay(wait);
  for(int i=NUM_LEDS-1;i>=0;i--) {
    strip.setPixelColor(i, strip.Color(r/4, g/4, b/4));
    strip.show();
  }
  delay(wait);
  for(int i=NUM_LEDS-1;i>=0;i--) {
    strip.setPixelColor(i, strip.Color(r/3, g/3, b/3));
    strip.show();
  }
  delay(wait);
  for(int i=NUM_LEDS-1;i>=0;i--) {
    strip.setPixelColor(i, strip.Color(r/2, g/2, b/2));
    strip.show();
  }
  delay(wait);
  for(int i=NUM_LEDS-1;i>=0;i--) {
    strip.setPixelColor(i, strip.Color(r, g, b));
    strip.show();
  }
  delay(waitExtra*15);
  for(int i=NUM_LEDS-1;i>=0;i--) {
    strip.setPixelColor(i, strip.Color(r/2, g/2, b/2));
    strip.show();
  }
  delay(wait);
  for(int i=NUM_LEDS-1;i>=0;i--) {
    strip.setPixelColor(i, strip.Color(r/3, g/3, b/3));
    strip.show();
  }
  delay(wait);
  for(int i=NUM_LEDS-1;i>=0;i--) {
    strip.setPixelColor(i, strip.Color(r/4, g/4, b/4));
    strip.show();
  }
  delay(wait);
}

void clearRing(){
  for(int i=0;i<NUM_LEDS;i++){
      strip.setPixelColor(i, strip.Color(0, 0, 0)); //change RGB color value here
   }
}

void clearColor(int r, int g, int b, uint8_t wait) {
  for(int i=NUM_LEDS-1;i>=0;i--){
      strip.setPixelColor(i, strip.Color(r, g, b)); //change RGB color value here
      strip.show();
      delay(wait);
   }
}

void blink(int numberOfTimes){
  for (int i = 0; i < numberOfTimes; i++)  {
    digitalWrite(ledPin, HIGH);
    delay(1000);
    digitalWrite(ledPin, LOW);
    delay(1000);
  }
}
