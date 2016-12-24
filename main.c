#include <Arduino.h>

#include "GFRotary.h"

GFRotary rotaryInstance;

void setup() {
	rotaryInstance = GFRotary( EncoderA, EncoderB, ButtonPin, debounceDelay, Displayname );

	 attachInterrupt( 0, doEncoderWrapper, CHANGE );
}