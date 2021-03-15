#include <arduino.h>

#include <adder.h>

#include "pins.h"


void toggleButton()
{
	if (digitalRead(PIN_BUTTON) == LOW) {
		digitalWrite(PIN_LED, HIGH);
		digitalWrite(PIN_LED_BOARD, HIGH);

	} else {
		digitalWrite(PIN_LED, LOW);
		digitalWrite(PIN_LED_BOARD, LOW);
	}
}

void setup()
{
	Serial.begin(115200);

	// Inputs
	pinMode(PIN_BUTTON, INPUT_PULLUP);

	// Outputs
	pinMode(PIN_LED, OUTPUT);
	pinMode(PIN_LED_BOARD, OUTPUT);

	attachInterrupt(digitalPinToInterrupt(PIN_BUTTON), toggleButton, CHANGE);
}

void loop()
{
	Adder adder;
	int result = adder.add(1, 2);

	delay(1000);
}
