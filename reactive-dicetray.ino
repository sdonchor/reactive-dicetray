#include <FastLED.h>
#define NUM_LEDS 42

#define LED_DATA 4
#define TRIGGER 9

CRGB leds[NUM_LEDS];

void setup() {
  delay(1000);
  LEDS.addLeds<WS2812, LED_DATA, GRB>(leds, NUM_LEDS);
  LEDS.setBrightness(180);
  pinMode(TRIGGER, INPUT);
  pinMode(LED_DATA, OUTPUT);
}

int trigger = 0;
boolean animationRunning = false;
int animationTime = 3000;
unsigned long animationStart = 0;
int currentAnimation = 0;

void loop() {
  
  if (!animationRunning) {
    trigger = !digitalRead(TRIGGER);
    if (trigger == HIGH) {
      animationRunning=true;
      switch (currentAnimation) {
      case 0:
        runAroundAndFlashFade();
        break;
      case 1:
        generatorTest();
        break;
      }
      allOff();
      animationRunning = false;
    }
  } else {
    allOff();
  }
}

void allOff() {
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CRGB(0, 0, 0);
    FastLED.show();
  }
}
void runAroundAndFlashFade() {
  for (int i = 0; i < 3; i++) {
    runAround(CRGB(120, 120, 120));
  }
  fadeIn(15);
  fadeOut(15);
  delay(500);
}

void fadeIn(int speed) {
  for (int brightness = 0; brightness < 255; brightness += speed) {
    for (int i = 0; i < NUM_LEDS; i++) {
      leds[i] = CRGB(brightness, brightness, brightness);
    }
    FastLED.show();
    delay(20);
  }
}
void fadeOut(int speed) {
  for (int brightness = 255; brightness > 0; brightness -= speed) {
    for (int i = 0; i < NUM_LEDS; i++) {
      leds[i] = CRGB(brightness, brightness, brightness);
    }
    FastLED.show();
    delay(20);
  }
  // turn off everything for safety
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CRGB(0, 0, 0);
  }
  FastLED.show();
  delay(20);
}
void runAround(CRGB color) {
  for (int i = 0; i < NUM_LEDS; i++) {
    if (i != 0) {
      leds[i - 1] = CRGB(0, 0, 0);
    }
    leds[i] = color;
    FastLED.show();
    delay(5);
  }
  leds[NUM_LEDS - 1] = CRGB(0, 0, 0);
  FastLED.show();
}
void generatorTest(){
  allOff();
//FRAME 1 (10ms)
leds[0]=CRGB(0, 0, 0);
leds[1]=CRGB(0, 0, 0);
leds[2]=CRGB(0, 0, 0);
leds[3]=CRGB(0, 0, 0);
leds[4]=CRGB(0, 0, 0);
leds[5]=CRGB(0, 0, 0);
leds[6]=CRGB(0, 0, 0);
leds[7]=CRGB(0, 0, 0);
leds[8]=CRGB(0, 0, 0);
leds[9]=CRGB(0, 0, 0);
leds[10]=CRGB(0, 0, 0);
leds[11]=CRGB(0, 0, 0);
leds[12]=CRGB(0, 0, 0);
leds[13]=CRGB(0, 0, 0);
leds[14]=CRGB(0, 0, 0);
leds[15]=CRGB(0, 0, 0);
leds[16]=CRGB(0, 0, 0);
leds[17]=CRGB(0, 0, 0);
leds[18]=CRGB(0, 0, 0);
leds[19]=CRGB(0, 0, 0);
leds[20]=CRGB(0, 0, 0);
leds[21]=CRGB(0, 0, 0);
leds[22]=CRGB(0, 0, 0);
leds[23]=CRGB(0, 0, 0);
leds[24]=CRGB(0, 0, 0);
leds[25]=CRGB(0, 0, 0);
leds[26]=CRGB(0, 0, 0);
leds[27]=CRGB(0, 0, 0);
leds[28]=CRGB(0, 0, 0);
leds[29]=CRGB(0, 0, 0);
leds[30]=CRGB(0, 0, 0);
leds[31]=CRGB(0, 0, 0);
leds[32]=CRGB(0, 0, 0);
leds[33]=CRGB(0, 0, 0);
leds[34]=CRGB(0, 0, 0);
leds[35]=CRGB(0, 0, 0);
leds[36]=CRGB(0, 0, 0);
leds[37]=CRGB(0, 0, 0);
leds[38]=CRGB(0, 0, 0);
leds[39]=CRGB(0, 0, 0);
leds[40]=CRGB(0, 0, 0);
leds[41]=CRGB(0, 0, 0);
FastLED.show();
delay(100);
//FRAME 2 (10ms)
leds[0]=CRGB(62, 39, 35);
leds[1]=CRGB(0, 0, 0);
leds[2]=CRGB(0, 0, 0);
leds[3]=CRGB(0, 0, 0);
leds[4]=CRGB(0, 0, 0);
leds[5]=CRGB(0, 0, 0);
leds[6]=CRGB(0, 0, 0);
leds[7]=CRGB(0, 0, 0);
leds[8]=CRGB(62, 39, 35);
leds[9]=CRGB(62, 39, 35);
leds[10]=CRGB(0, 0, 0);
leds[11]=CRGB(0, 0, 0);
leds[12]=CRGB(0, 0, 0);
leds[13]=CRGB(0, 0, 0);
leds[14]=CRGB(0, 0, 0);
leds[15]=CRGB(0, 0, 0);
leds[16]=CRGB(0, 0, 0);
leds[17]=CRGB(0, 0, 0);
leds[18]=CRGB(0, 0, 0);
leds[19]=CRGB(0, 0, 0);
leds[20]=CRGB(62, 39, 35);
leds[21]=CRGB(62, 39, 35);
leds[22]=CRGB(0, 0, 0);
leds[23]=CRGB(0, 0, 0);
leds[24]=CRGB(0, 0, 0);
leds[25]=CRGB(0, 0, 0);
leds[26]=CRGB(0, 0, 0);
leds[27]=CRGB(0, 0, 0);
leds[28]=CRGB(0, 0, 0);
leds[29]=CRGB(62, 39, 35);
leds[30]=CRGB(62, 39, 35);
leds[31]=CRGB(0, 0, 0);
leds[32]=CRGB(0, 0, 0);
leds[33]=CRGB(0, 0, 0);
leds[34]=CRGB(0, 0, 0);
leds[35]=CRGB(0, 0, 0);
leds[36]=CRGB(0, 0, 0);
leds[37]=CRGB(0, 0, 0);
leds[38]=CRGB(0, 0, 0);
leds[39]=CRGB(0, 0, 0);
leds[40]=CRGB(0, 0, 0);
leds[41]=CRGB(62, 39, 35);
FastLED.show();
delay(100);
//FRAME 3 (10ms)
leds[0]=CRGB(78, 52, 46);
leds[1]=CRGB(62, 39, 35);
leds[2]=CRGB(0, 0, 0);
leds[3]=CRGB(0, 0, 0);
leds[4]=CRGB(0, 0, 0);
leds[5]=CRGB(0, 0, 0);
leds[6]=CRGB(0, 0, 0);
leds[7]=CRGB(62, 39, 35);
leds[8]=CRGB(78, 52, 46);
leds[9]=CRGB(78, 52, 46);
leds[10]=CRGB(62, 39, 35);
leds[11]=CRGB(0, 0, 0);
leds[12]=CRGB(0, 0, 0);
leds[13]=CRGB(0, 0, 0);
leds[14]=CRGB(0, 0, 0);
leds[15]=CRGB(0, 0, 0);
leds[16]=CRGB(0, 0, 0);
leds[17]=CRGB(0, 0, 0);
leds[18]=CRGB(0, 0, 0);
leds[19]=CRGB(62, 39, 35);
leds[20]=CRGB(78, 52, 46);
leds[21]=CRGB(78, 52, 46);
leds[22]=CRGB(62, 39, 35);
leds[23]=CRGB(0, 0, 0);
leds[24]=CRGB(0, 0, 0);
leds[25]=CRGB(0, 0, 0);
leds[26]=CRGB(0, 0, 0);
leds[27]=CRGB(0, 0, 0);
leds[28]=CRGB(62, 39, 35);
leds[29]=CRGB(78, 52, 46);
leds[30]=CRGB(78, 52, 46);
leds[31]=CRGB(62, 39, 35);
leds[32]=CRGB(0, 0, 0);
leds[33]=CRGB(0, 0, 0);
leds[34]=CRGB(0, 0, 0);
leds[35]=CRGB(0, 0, 0);
leds[36]=CRGB(0, 0, 0);
leds[37]=CRGB(0, 0, 0);
leds[38]=CRGB(0, 0, 0);
leds[39]=CRGB(0, 0, 0);
leds[40]=CRGB(62, 39, 35);
leds[41]=CRGB(78, 52, 46);
FastLED.show();
delay(100);
//FRAME 4 (10ms)
leds[0]=CRGB(141, 110, 99);
leds[1]=CRGB(78, 52, 46);
leds[2]=CRGB(62, 39, 35);
leds[3]=CRGB(0, 0, 0);
leds[4]=CRGB(0, 0, 0);
leds[5]=CRGB(0, 0, 0);
leds[6]=CRGB(62, 39, 35);
leds[7]=CRGB(78, 52, 46);
leds[8]=CRGB(141, 110, 99);
leds[9]=CRGB(141, 110, 99);
leds[10]=CRGB(78, 52, 46);
leds[11]=CRGB(62, 39, 35);
leds[12]=CRGB(0, 0, 0);
leds[13]=CRGB(0, 0, 0);
leds[14]=CRGB(0, 0, 0);
leds[15]=CRGB(0, 0, 0);
leds[16]=CRGB(0, 0, 0);
leds[17]=CRGB(0, 0, 0);
leds[18]=CRGB(62, 39, 35);
leds[19]=CRGB(78, 52, 46);
leds[20]=CRGB(141, 110, 99);
leds[21]=CRGB(141, 110, 99);
leds[22]=CRGB(78, 52, 46);
leds[23]=CRGB(62, 39, 35);
leds[24]=CRGB(0, 0, 0);
leds[25]=CRGB(0, 0, 0);
leds[26]=CRGB(0, 0, 0);
leds[27]=CRGB(62, 39, 35);
leds[28]=CRGB(78, 52, 46);
leds[29]=CRGB(141, 110, 99);
leds[30]=CRGB(141, 110, 99);
leds[31]=CRGB(78, 52, 46);
leds[32]=CRGB(62, 39, 35);
leds[33]=CRGB(0, 0, 0);
leds[34]=CRGB(0, 0, 0);
leds[35]=CRGB(0, 0, 0);
leds[36]=CRGB(0, 0, 0);
leds[37]=CRGB(0, 0, 0);
leds[38]=CRGB(0, 0, 0);
leds[39]=CRGB(62, 39, 35);
leds[40]=CRGB(78, 52, 46);
leds[41]=CRGB(141, 110, 99);
FastLED.show();
delay(100);
//FRAME 5 (10ms)
leds[0]=CRGB(188, 170, 164);
leds[1]=CRGB(141, 110, 99);
leds[2]=CRGB(78, 52, 46);
leds[3]=CRGB(62, 39, 35);
leds[4]=CRGB(0, 0, 0);
leds[5]=CRGB(62, 39, 35);
leds[6]=CRGB(78, 52, 46);
leds[7]=CRGB(141, 110, 99);
leds[8]=CRGB(188, 170, 164);
leds[9]=CRGB(188, 170, 164);
leds[10]=CRGB(141, 110, 99);
leds[11]=CRGB(78, 52, 46);
leds[12]=CRGB(62, 39, 35);
leds[13]=CRGB(0, 0, 0);
leds[14]=CRGB(0, 0, 0);
leds[15]=CRGB(0, 0, 0);
leds[16]=CRGB(0, 0, 0);
leds[17]=CRGB(62, 39, 35);
leds[18]=CRGB(78, 52, 46);
leds[19]=CRGB(141, 110, 99);
leds[20]=CRGB(188, 170, 164);
leds[21]=CRGB(188, 170, 164);
leds[22]=CRGB(141, 110, 99);
leds[23]=CRGB(78, 52, 46);
leds[24]=CRGB(62, 39, 35);
leds[25]=CRGB(0, 0, 0);
leds[26]=CRGB(62, 39, 35);
leds[27]=CRGB(78, 52, 46);
leds[28]=CRGB(141, 110, 99);
leds[29]=CRGB(188, 170, 164);
leds[30]=CRGB(188, 170, 164);
leds[31]=CRGB(141, 110, 99);
leds[32]=CRGB(78, 52, 46);
leds[33]=CRGB(62, 39, 35);
leds[34]=CRGB(0, 0, 0);
leds[35]=CRGB(0, 0, 0);
leds[36]=CRGB(0, 0, 0);
leds[37]=CRGB(0, 0, 0);
leds[38]=CRGB(62, 39, 35);
leds[39]=CRGB(78, 52, 46);
leds[40]=CRGB(141, 110, 99);
leds[41]=CRGB(188, 170, 164);
FastLED.show();
delay(100);
//FRAME 6 (10ms)
leds[0]=CRGB(191, 54, 12);
leds[1]=CRGB(188, 170, 164);
leds[2]=CRGB(141, 110, 99);
leds[3]=CRGB(109, 76, 65);
leds[4]=CRGB(62, 39, 35);
leds[5]=CRGB(109, 76, 65);
leds[6]=CRGB(141, 110, 99);
leds[7]=CRGB(188, 170, 164);
leds[8]=CRGB(191, 54, 12);
leds[9]=CRGB(191, 54, 12);
leds[10]=CRGB(188, 170, 164);
leds[11]=CRGB(141, 110, 99);
leds[12]=CRGB(109, 76, 65);
leds[13]=CRGB(62, 39, 35);
leds[14]=CRGB(0, 0, 0);
leds[15]=CRGB(0, 0, 0);
leds[16]=CRGB(62, 39, 35);
leds[17]=CRGB(109, 76, 65);
leds[18]=CRGB(141, 110, 99);
leds[19]=CRGB(188, 170, 164);
leds[20]=CRGB(191, 54, 12);
leds[21]=CRGB(191, 54, 12);
leds[22]=CRGB(188, 170, 164);
leds[23]=CRGB(141, 110, 99);
leds[24]=CRGB(109, 76, 65);
leds[25]=CRGB(62, 39, 35);
leds[26]=CRGB(109, 76, 65);
leds[27]=CRGB(141, 110, 99);
leds[28]=CRGB(188, 170, 164);
leds[29]=CRGB(191, 54, 12);
leds[30]=CRGB(191, 54, 12);
leds[31]=CRGB(188, 170, 164);
leds[32]=CRGB(141, 110, 99);
leds[33]=CRGB(109, 76, 65);
leds[34]=CRGB(62, 39, 35);
leds[35]=CRGB(0, 0, 0);
leds[36]=CRGB(0, 0, 0);
leds[37]=CRGB(62, 39, 35);
leds[38]=CRGB(109, 76, 65);
leds[39]=CRGB(141, 110, 99);
leds[40]=CRGB(188, 170, 164);
leds[41]=CRGB(191, 54, 12);
FastLED.show();
delay(100);
//FRAME 7 (10ms)
leds[0]=CRGB(188, 170, 164);
leds[1]=CRGB(188, 170, 164);
leds[2]=CRGB(141, 110, 99);
leds[3]=CRGB(109, 76, 65);
leds[4]=CRGB(109, 76, 65);
leds[5]=CRGB(109, 76, 65);
leds[6]=CRGB(141, 110, 99);
leds[7]=CRGB(188, 170, 164);
leds[8]=CRGB(188, 170, 164);
leds[9]=CRGB(188, 170, 164);
leds[10]=CRGB(188, 170, 164);
leds[11]=CRGB(141, 110, 99);
leds[12]=CRGB(109, 76, 65);
leds[13]=CRGB(62, 39, 35);
leds[14]=CRGB(62, 39, 35);
leds[15]=CRGB(62, 39, 35);
leds[16]=CRGB(62, 39, 35);
leds[17]=CRGB(109, 76, 65);
leds[18]=CRGB(141, 110, 99);
leds[19]=CRGB(188, 170, 164);
leds[20]=CRGB(188, 170, 164);
leds[21]=CRGB(188, 170, 164);
leds[22]=CRGB(188, 170, 164);
leds[23]=CRGB(141, 110, 99);
leds[24]=CRGB(109, 76, 65);
leds[25]=CRGB(109, 76, 65);
leds[26]=CRGB(109, 76, 65);
leds[27]=CRGB(141, 110, 99);
leds[28]=CRGB(188, 170, 164);
leds[29]=CRGB(188, 170, 164);
leds[30]=CRGB(188, 170, 164);
leds[31]=CRGB(188, 170, 164);
leds[32]=CRGB(141, 110, 99);
leds[33]=CRGB(109, 76, 65);
leds[34]=CRGB(62, 39, 35);
leds[35]=CRGB(62, 39, 35);
leds[36]=CRGB(62, 39, 35);
leds[37]=CRGB(62, 39, 35);
leds[38]=CRGB(109, 76, 65);
leds[39]=CRGB(141, 110, 99);
leds[40]=CRGB(188, 170, 164);
leds[41]=CRGB(188, 170, 164);
FastLED.show();
delay(100);
//FRAME 8 (10ms)
leds[0]=CRGB(255, 138, 101);
leds[1]=CRGB(244, 81, 30);
leds[2]=CRGB(141, 110, 99);
leds[3]=CRGB(109, 76, 65);
leds[4]=CRGB(109, 76, 65);
leds[5]=CRGB(109, 76, 65);
leds[6]=CRGB(141, 110, 99);
leds[7]=CRGB(244, 81, 30);
leds[8]=CRGB(255, 138, 101);
leds[9]=CRGB(255, 138, 101);
leds[10]=CRGB(244, 81, 30);
leds[11]=CRGB(141, 110, 99);
leds[12]=CRGB(109, 76, 65);
leds[13]=CRGB(62, 39, 35);
leds[14]=CRGB(62, 39, 35);
leds[15]=CRGB(62, 39, 35);
leds[16]=CRGB(62, 39, 35);
leds[17]=CRGB(109, 76, 65);
leds[18]=CRGB(141, 110, 99);
leds[19]=CRGB(244, 81, 30);
leds[20]=CRGB(255, 138, 101);
leds[21]=CRGB(255, 138, 101);
leds[22]=CRGB(244, 81, 30);
leds[23]=CRGB(141, 110, 99);
leds[24]=CRGB(109, 76, 65);
leds[25]=CRGB(109, 76, 65);
leds[26]=CRGB(109, 76, 65);
leds[27]=CRGB(141, 110, 99);
leds[28]=CRGB(244, 81, 30);
leds[29]=CRGB(255, 138, 101);
leds[30]=CRGB(255, 138, 101);
leds[31]=CRGB(244, 81, 30);
leds[32]=CRGB(141, 110, 99);
leds[33]=CRGB(109, 76, 65);
leds[34]=CRGB(62, 39, 35);
leds[35]=CRGB(62, 39, 35);
leds[36]=CRGB(62, 39, 35);
leds[37]=CRGB(62, 39, 35);
leds[38]=CRGB(109, 76, 65);
leds[39]=CRGB(141, 110, 99);
leds[40]=CRGB(244, 81, 30);
leds[41]=CRGB(255, 138, 101);
FastLED.show();
delay(100);
//FRAME 9 (10ms)
leds[0]=CRGB(255, 138, 101);
leds[1]=CRGB(244, 81, 30);
leds[2]=CRGB(141, 110, 99);
leds[3]=CRGB(244, 81, 30);
leds[4]=CRGB(191, 54, 12);
leds[5]=CRGB(244, 81, 30);
leds[6]=CRGB(141, 110, 99);
leds[7]=CRGB(244, 81, 30);
leds[8]=CRGB(255, 138, 101);
leds[9]=CRGB(255, 138, 101);
leds[10]=CRGB(244, 81, 30);
leds[11]=CRGB(141, 110, 99);
leds[12]=CRGB(244, 81, 30);
leds[13]=CRGB(62, 39, 35);
leds[14]=CRGB(191, 54, 12);
leds[15]=CRGB(191, 54, 12);
leds[16]=CRGB(62, 39, 35);
leds[17]=CRGB(244, 81, 30);
leds[18]=CRGB(141, 110, 99);
leds[19]=CRGB(244, 81, 30);
leds[20]=CRGB(255, 138, 101);
leds[21]=CRGB(255, 138, 101);
leds[22]=CRGB(244, 81, 30);
leds[23]=CRGB(141, 110, 99);
leds[24]=CRGB(244, 81, 30);
leds[25]=CRGB(191, 54, 12);
leds[26]=CRGB(244, 81, 30);
leds[27]=CRGB(141, 110, 99);
leds[28]=CRGB(244, 81, 30);
leds[29]=CRGB(255, 138, 101);
leds[30]=CRGB(255, 138, 101);
leds[31]=CRGB(244, 81, 30);
leds[32]=CRGB(141, 110, 99);
leds[33]=CRGB(244, 81, 30);
leds[34]=CRGB(62, 39, 35);
leds[35]=CRGB(191, 54, 12);
leds[36]=CRGB(191, 54, 12);
leds[37]=CRGB(62, 39, 35);
leds[38]=CRGB(244, 81, 30);
leds[39]=CRGB(141, 110, 99);
leds[40]=CRGB(244, 81, 30);
leds[41]=CRGB(255, 138, 101);
FastLED.show();
delay(100);
//FRAME 10 (10ms)
leds[0]=CRGB(255, 255, 255);
leds[1]=CRGB(255, 255, 255);
leds[2]=CRGB(255, 112, 67);
leds[3]=CRGB(244, 81, 30);
leds[4]=CRGB(191, 54, 12);
leds[5]=CRGB(244, 81, 30);
leds[6]=CRGB(255, 112, 67);
leds[7]=CRGB(255, 255, 255);
leds[8]=CRGB(255, 255, 255);
leds[9]=CRGB(255, 255, 255);
leds[10]=CRGB(255, 255, 255);
leds[11]=CRGB(255, 112, 67);
leds[12]=CRGB(244, 81, 30);
leds[13]=CRGB(255, 112, 67);
leds[14]=CRGB(191, 54, 12);
leds[15]=CRGB(255, 112, 67);
leds[16]=CRGB(255, 112, 67);
leds[17]=CRGB(244, 81, 30);
leds[18]=CRGB(141, 110, 99);
leds[19]=CRGB(255, 255, 255);
leds[20]=CRGB(255, 255, 255);
leds[21]=CRGB(255, 255, 255);
leds[22]=CRGB(255, 255, 255);
leds[23]=CRGB(255, 112, 67);
leds[24]=CRGB(244, 81, 30);
leds[25]=CRGB(191, 54, 12);
leds[26]=CRGB(244, 81, 30);
leds[27]=CRGB(255, 112, 67);
leds[28]=CRGB(255, 255, 255);
leds[29]=CRGB(255, 255, 255);
leds[30]=CRGB(255, 255, 255);
leds[31]=CRGB(255, 255, 255);
leds[32]=CRGB(255, 112, 67);
leds[33]=CRGB(255, 112, 67);
leds[34]=CRGB(255, 112, 67);
leds[35]=CRGB(191, 54, 12);
leds[36]=CRGB(191, 54, 12);
leds[37]=CRGB(255, 112, 67);
leds[38]=CRGB(244, 81, 30);
leds[39]=CRGB(141, 110, 99);
leds[40]=CRGB(255, 255, 255);
leds[41]=CRGB(255, 255, 255);
FastLED.show();
delay(100);

}
