/*
  Dimmer

  created 2006
  by David A. Mellis
  modified 14 Apr 2009
  by Tom Igoe and Scott Fitzgerald
 
  This example code is in the public domain.
  http://www.arduino.cc/en/Tutorial/Dimmer

  Derived from example code in public domain for Home Watchdog demo
  modified 2011
  by T.J. Telan
  http://www.tjtelan.com
  */

const int ledPin = 9;      // the pin that the LED is attached to

void setup() {
    // initialize the serial communication:
    Serial.begin(9600);
    // initialize the ledPin as an output:
    pinMode(ledPin, OUTPUT);
}

void loop() {
    byte brightness;

    // check if data has been sent from the computer:
    if (Serial.available()) {
        // read the most recent byte (which will be from 0 to 255):
        brightness = Serial.read();
        // set the brightness of the LED:
        analogWrite(ledPin, brightness);
    }
}

