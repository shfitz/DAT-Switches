// How to use a photocell as a switch
// An LED is wired in series to a 220ohm-1kohm resistor on pin 3
// a Photocell is connected to A0 in parallel with a 10k resistor
// the circuit soends the first 5 seconnds after being powered on or reset
// in a calibration mode. During this time, cover and uncover the sensor
// the onboard LED stays on during the calibratin period

const int sensePin = A0;
const int ledPin = 3;

int senseVal = 0;
int minVal = 1023;
int hiVal = 0;

int thresh = 512;

void setup() {
  // put your setup code here, to run once:
  // set the pins as inputs / outputs
  pinMode(ledPin, OUTPUT);
  calibrateSensor();  // calibrate the sensors
  thresh = (hiVal-minVal)/2 + minVal; // get the middle of the sensor's range to determine the on/off threshold
}

void loop() {

  // read the value on the sensor pin and store it in a variable
  senseVal = analogRead(sensePin);

  if(senseVal>thresh){ // if the threshold is passed
    digitalWrite(ledPin, HIGH); // turn the LED on
  }else{ // otherwise
    digitalWrite(ledPin, LOW); // turn the LED off
  }
}

void calibrateSensor(){
  // turn a builtin led on
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(13, LED_BUILTIN);
  // calibrate for five seconds
  while (millis() < 5000) {
    senseVal = analogRead(sensePin);

    // record the maximum sensor value
    if (senseVal > hiVal) {
      hiVal = senseVal;
    }

    // record the minimum sensor value
    if (senseVal < minVal) {
      minVal = senseVal;
    }
  }

  // signal the end of the calibration period
    digitalWrite(13, LOW);
}
