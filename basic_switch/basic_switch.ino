// basic momentary switch code to turn on an LED
// An LED is wired in series to a 220ohm-1kohm resistor on pin 3
// a momentary switch is connected to pin 2 with a 10k pulldown resistor

const int switchPin = 2;
const int ledPin = 3;

int switchVal =0;

void setup() {
  // put your setup code here, to run once:
  // set the pins as inputs / outputs
  pinMode(switchPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  // read the value on the switch pin and store it in a variable
  switchVal = digitalRead(switchPin);

  if(switchVal==HIGH){ // if the switch is pressed
    digitalWrite(ledPin, HIGH); // turn the LED on
  }else{ // otherwise
    digitalWrite(ledPin, LOW); // turn the LED off
  }
}
