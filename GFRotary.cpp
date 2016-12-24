/*
  GFRotary.cpp - Library for a Rotary Encoder as part of the GeekFrog System.
  Created by Kevin MacDonald, December 2016.
  Released into the public domain.
  Based on Limor Fried's version of debounce,
  but the logic is inverted from her example
*/

#include "Arduino.h"
#include "GFRotary.h"


GFRotary::GFRotary(int EncoderA, int EncoderB, int ButtonPin, unsigned long debounceDelay, String Displayname)
{
  pinMode(ButtonPin, INPUT_PULLUP);
  encoder0PinA = EncoderA;
  encoder0PinB  = EncoderB;
  _buttonPin = ButtonPin;
  _debounceDelay = debounceDelay;
  DeviceName = Displayname;
  //encoder0Pos = 0;

  pinMode(encoder0PinA , INPUT);
  digitalWrite(encoder0PinA , HIGH);       // turn on pull-up resistor
  pinMode(encoder0PinB, INPUT);
  digitalWrite(encoder0PinB, HIGH);       // turn on pull-up resistor

  attachInterrupt(0, GFRotary::doEncoder, CHANGE);  // encoder pin on interrupt 0 - pin 2

}

void GFRotary::doEncoder()
{

  /* If pinA and pinB are both high or both low, it is spinning
       forward. If they're different, it's going backward.

       For more information on speeding up this process, see
       [Reference/PortManipulation], specifically the PIND register.
  */
  //if (digitalRead(encoder0PinA) == digitalRead(encoder0PinB)) {
  //encoder0Pos++;
  //} else {
  // encoder0Pos--;
  //}
  Serial.println("encoder0Pos:");
  //Serial.println (GFRotary::encoder0Pos, DEC);
}

void GFRotary::tick()
{

  //-----------------Encoders -----------------


  //-----------------DEBOUNCER -----------------
  // read the state of the switch into a local variable:
  int reading = digitalRead(_buttonPin);

  // check to see if you just pressed the button
  // (i.e. the input went from LOW to HIGH),  and you've waited
  // long enough since the last press to ignore any noise:

  // If the switch changed, due to noise or pressing:
  if (reading != _lastButtonState) {
    // reset the debouncing timer
    _lastDebounceTime = millis();
  }

  if ((millis() - _lastDebounceTime) > _debounceDelay) {
    // whatever the reading is at, it's been there for longer
    // than the debounce delay, so take it as the actual current state:

    // if the button state has changed:
    if (reading != _buttonState) {
      _buttonState = reading;
      if (_buttonState == HIGH)
      {
        isButtonPressed = false;
      } else
      {
        isButtonPressed = true;
      }
    }
  }

  // save the reading.  Next time through the loop,
  // it'll be the lastButtonState:
  _lastButtonState = reading;
}

void doEncoderWrapper()
{
	if( rotaryInstance )
		rotaryInstance.doEncoder();
	
}