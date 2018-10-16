// use a mometary switch as a toggle, or maintained switch
// An LED is wired in series to a 220ohm-1kohm resistor on pin 3
// a momentary switch is connected to pin 2 with a 10k pulldown resistor

const int switchPin = 2; // the pin that the switch is attached to
const int ledPin = 3; // the pin that the LED is attached to

int switchVal = 0; // current switch state
int prevSwitchVal = 0; // previous switch state
int toggleState = 0;

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

  // compare the current state to the previous state
  if(switchVal!=prevSwitchVal && switchVal==HIGH){
    // if the state has changed and it's currently HIGH
    toggleState++; // increment the toggle
  }

  if(toggleState%2 == 1){ // every other press
    digitalWrite(ledPin, HIGH); // turn the LED on
  }else{ // otherwise
    digitalWrite(ledPin, LOW); // turn the LED off
  }
}
