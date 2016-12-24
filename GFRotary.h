/*
  GFRotary.h - Library for a Rotary Encoder as part of the GeekFrog System.
  Created by Kevin MacDonald, December 2016.
  Released into the public domain.
  Based on Limor Fried's version of debounce,
  but the logic is inverted from her example
*/

#ifndef GFRotary_h
#define GFRotary_h

#include "Arduino.h"

class GFRotary
{
  public:
    GFRotary(int EncoderA, int EncoderB, int ButtonPin, unsigned long debounceDelay, String Displayname);
    void tick();
    void doEncoder();
    bool isButtonPressed;
    String DeviceName;
    volatile unsigned int encoder0Pos;
    volatile int encoder0PinA;
    volatile int encoder0PinB;

  private:
    int _buttonPin;
    int _buttonState;
    int _lastButtonState;
    unsigned long _lastDebounceTime;
    unsigned long _debounceDelay;
};

#endif