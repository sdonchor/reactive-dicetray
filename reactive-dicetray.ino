#include <FastLED.h>
#define NUM_LEDS 42

#define LED_DATA 4
#define TRIGGER 9
#define CONST_OUT 7
#define BUTTON 2

CRGB leds[NUM_LEDS];

void setup() {
  delay(1000);
  LEDS.addLeds<WS2812, LED_DATA, GRB>(leds, NUM_LEDS);
  LEDS.setBrightness(180);
  pinMode(TRIGGER, INPUT);
  pinMode(LED_DATA, OUTPUT);
  pinMode(CONST_OUT, OUTPUT);
  digitalWrite(CONST_OUT, HIGH);
  Serial.begin(38400);

}

//mic
int trigger = 0;

//animation
boolean animationRunning = false;
int animationTime = 3000;
unsigned long animationStart = 0;
int currentAnimation = 1;

//button
unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 1000;


//general
boolean settingsMode = false;
unsigned long settingsStartTime = 0;
unsigned long settingsOffDelay = 3000;
int setting = 0; //0 - reactive, 1 - reactive low brightness, 2 - ambient

boolean buttonPressed() {
  int reading = digitalRead(BUTTON);

  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (reading == HIGH) {
      lastDebounceTime = millis();
      return true;
    }
  }
  return false;
}

void showIndicator() {
  allOff();
  if (setting == 0) {
    plainColor(0, 8, CRGB(255, 255, 255));
  } else if (setting == 1) {
    plainColor(9, 20, CRGB(0, 0, 255));
  } else if (setting == 2) {
    plainColor(21, 29, CRGB(255, 0, 255));
  } else {
    return;
  }
}

void loop() {
  //  if (!settingsMode) {
  //    if (buttonPressed()) {
  //      settingsMode = true;
  //      settingsStartTime = millis();
  //      return;
  //    }
  //  } else {
  //    if ((millis() - settingsStartTime) > settingsOffDelay) {
  //      settingsMode = false;
  //      return;
  //    } else {
  //
  //      if (buttonPressed()) {
  //
  //
  //        setting++;
  //        if (setting > 2) {
  //          setting = 0;
  //        }
  //                Serial.println(setting);
  //
  //      }
  //    }
  //    return;
  //  }

  if (!animationRunning) {
    trigger = !digitalRead(TRIGGER);
    if (trigger == HIGH) {
      animationRunning = true;
      switch (currentAnimation) {
        case 0:
          runAroundAndFlashFade();
          break;
        case 1:
          runAroundAndFlashFadeMulticolor();
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
void plainColor(int startIdx, int endIdx, CRGB color) {
  for (int i = startIdx; i <= endIdx; i++) {
    leds[i] = color;
  }
  FastLED.show();
}
void runAroundAndFlashFadeMulticolor() {


  runAround(CRGB(255, 0, 0),2);
  runAround(CRGB(255, 0, 255),2);
  runAround(CRGB(0, 0, 255),2);
  runAround(CRGB(0, 255, 255),2);
  runAround(CRGB(0, 255, 0),2);
  runAround(CRGB(255, 255, 0),2);

  fadeIn(10);
  fadeOut(10);
  delay(500);
}

void runAroundAndFlashFade() {

  for (int i = 0; i < 3; i++) {
    runAround(CRGB(120, 120, 120),5);
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
void runAround(CRGB color, int ledDelay) {
  for (int i = 0; i < NUM_LEDS; i++) {
    if (i != 0) {
      leds[i - 1] = CRGB(0, 0, 0);
    }
    leds[i] = color;
    FastLED.show();
    delay(ledDelay);
  }
  leds[NUM_LEDS - 1] = CRGB(0, 0, 0);
  FastLED.show();
}
