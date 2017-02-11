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
     int var = (Serial.read() - '`');  // convert the character '1'-'9' to decimal 1-9

     switch(var)
     {
        case 1:
          bidding();
          break;
        case 2:
          breath();
          break;
        case 3:
          darkside();
          break;
        case 4:
          DarthLsbr();
          break;
        case 5:
          dontfail();
          break;
        case 6:
          failed();
          break;
        case 7:
          father();
          break;
        case 8:
          haveyou();
          break;
        case 9:
          noescape();
          break;
        case 10:
          power();
          break;
        case 11:
          theforce();
          break;
        case 12:
          vader();
          break;
        case 13:
          waiting();
          break;
        case 14:
          imperial();
          break;
        case 15:
          impossible();
          break;
        case 16:
          LukeLsbr();
          break;
        case 17:
          yoda();
          break;
        case 18:
          disturb();
          break;
        case 19:
          force1();
          break;
        case 20:
          force2();
          break;
        case 21:
          strongam();
          break;
        case 22:
          try_not();
          break;
        case 23:
          mainthemeshort();
          break;
        case 24:
          c3po();
          break;
        case 25:
          helpme();
          break;
        case 26:
          r2d2_1();
          break;
        case 27:
          r2d2_2();
          break;
        case 28:
          roar();
          break;
        case 29:
          stuck_up();
          break;
        case 30:
          thankme();
          break; 
     }
  }
  else {
    steady();
  }
  delay(100);

  //colorWipe(strip.Color(255, 0, 0), 50); // Red
  //colorWipe(strip.Color(0, 255, 0), 50); // Green
  //clearRing();
  //strip.show();
  //delay(1000);
  //clearColor(0,0,0,35);
  //rainbow(20);
  //rainbowCycle(20);
}

void steady() {
  for(uint16_t i=0; i<strip.numPixels(); i++) {
    strip.setPixelColor(i, strip.Color(255, 255, 255));
  }
  strip.show();
}

void bidding() {
  //1
  colorPulse(255, 0, 0, 100, 120);
  clearRing();
  strip.show();
  delay(100);
}

void breath() {
  //2
  colorPulse(255, 0, 0, 100, 250);
  clearRing();
  strip.show();
  delay(100); 
}

void darkside() {
  //3
  colorPulse(255, 0, 0, 100, 220);
  clearRing();
  strip.show();
  delay(100);
}

void DarthLsbr() {
  //4
  colorPulse(255, 0, 0, 100, 220);
  clearRing();
  strip.show();
  delay(100);
}

void dontfail() {
  //5
  colorPulse(255, 0, 0, 100, 100);
  clearRing();
  strip.show();
  delay(100);
}

void failed() {
  //6
  colorPulse(255, 0, 0, 100, 220);
  clearRing();
  strip.show();
  delay(100);
}

void father() {
  //7
  colorPulse(255, 0, 0, 100, 100);
  clearRing();
  strip.show();
  delay(100);
}

void haveyou() {
  //8
  colorPulse(255, 0, 0, 100, 65);
  clearRing();
  strip.show();
  delay(100);
}

void noescape() {
  //9
  colorPulse(255, 0, 0, 100, 300);
  clearRing();
  strip.show();
  delay(100);
}

void power() {
  //10
  colorPulse(255, 0, 0, 100, 220);
  clearRing();
  strip.show();
  delay(100);
}

void theforce() {
  //11
  colorPulse(255, 0, 0, 100, 550);
  clearRing();
  strip.show();
  delay(100);
}

void vader() {
  //12
  colorPulse(255, 0, 0, 100, 100);
  clearRing();
  strip.show();
  delay(100);
}

void waiting() {
  //13
  colorPulse(255, 0, 0, 100, 120);
  clearRing();
  strip.show();
  delay(100);
}

void imperial() {
  //14
  colorPulse(255, 0, 0, 100, 2420);
  clearRing();
  strip.show();
  delay(100);
}

void impossible() {
  //15
  colorPulse(0, 255, 0, 100, 550);
  clearRing();
  strip.show();
  delay(100);
}

void LukeLsbr() {
  //16
  colorPulse(0, 255, 0, 100, 160);
  clearRing();
  strip.show();
  delay(100);
}

void yoda() {
  //17
  colorPulse(0, 255, 0, 100, 85);
  clearRing();
  strip.show();
  delay(100);
}

void disturb() {
  //18
  colorPulse(0, 0, 255, 100, 100);
  clearRing();
  strip.show();
  delay(100);
}

void force1() {
  //19
  colorPulse(0, 0, 255, 100, 100);
  clearRing();
  strip.show();
  delay(100);
}

void force2() {
  //20
  colorPulse(0, 0, 255, 100, 65);
  clearRing();
  strip.show();
  delay(100);
}

void strongam() {
  //21
  colorPulse(0, 255, 0, 100, 100);
  clearRing();
  strip.show();
  delay(100);
}

void try_not() {
  //22
  colorPulse(0, 255, 0, 100, 420);
  clearRing();
  strip.show();
  delay(100);
}

void mainthemeshort() {
  //23
  colorPulse(255, 255, 5, 100, 1100);
  clearRing();
  strip.show();
  delay(100);  
}

void c3po() {
  //24
  colorPulse(255, 255, 5, 100, 200);
  clearRing();
  strip.show();
  delay(100);
}

void helpme() {
  //25
  colorPulse(255, 255, 255, 100, 180);
  clearRing();
  strip.show();
  delay(100);
}

void r2d2_1() {
  //26
  colorPulse(0, 0, 255, 100, 85);
  clearRing();
  strip.show();
  delay(100);
}

void r2d2_2() {
  //27
  colorPulse(0, 0, 255, 100, 100);
  clearRing();
  strip.show();
  delay(100);
}

void roar() {
  //28
  colorPulse(0, 255, 0, 100, 100);
  clearRing();
  strip.show();
  delay(100);
}

void stuck_up() {
  //29
  colorPulse(255, 255, 255, 100, 300);
  clearRing();
  strip.show();
  delay(100);
}

void thankme() {
  //30
  colorPulse(0, 255, 0, 100, 85);
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

void colorPulse(int r, int g, int b, uint16_t wait, uint16_t waitExtra) {
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
