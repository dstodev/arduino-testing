#include <arduino.h>

#include <adder.h>

const int PIN_LED = 11;
const int PIN_BUTTON = 2;

void toggleButton()
{
	if (digitalRead(PIN_BUTTON) == LOW) {
		digitalWrite(PIN_LED, HIGH);
	} else {
		digitalWrite(PIN_LED, LOW);
	}
}

void setup()
{
	Serial.begin(115200);

	pinMode(PIN_LED, OUTPUT);
	pinMode(PIN_BUTTON, INPUT_PULLUP);

	attachInterrupt(digitalPinToInterrupt(PIN_BUTTON), toggleButton, CHANGE);
}

void loop()
{
	Adder adder;
	int result = adder.add(1, 2);

	delay(1000);
}