/*
StopLight version 1.0

Imitates a traffic light in its most basic functions. Led is always green, and then when button is pressed,
the green led stays on for a random amount of time longer, and then turns off. The yellow led turns on for
a fixed amount of time, and then the red led turns on. A fixed amount of time after, the blue, or 'walking'
led turns on, and stays on for a random amount of time. After this it turns off. A fixed amount of time later, 
the red led turns off, and the green led turns back on. This is supposed to imitate a traffic light when you
are crossing.

The circuit: Pretty basic, just have an understanding of momentary switches (pushbuttons) and leds.

Created in 2017
by Preston M
Version: 1.0

Find me on GitHub: prestonrm03
Link to GitHub repository: https://github.com/prestonrm03/prestonarduino

This code is free to use in hobby projects, but please give credit if you use a part of it. Contact me on GitHub
if you have any problems with the software.


 */


const int button = 2; // pin of push button
int buttonState = 0; // variable for reding pushbutton status - this variable WILL change
const int red = 13; // red led
const int yellow = 12; // yellow led
const int green = 11; // green led
const int walk = 10; // blue, or 'free to walk' led
long int randOn = 0; // random time on

 
void setup() {
  pinMode(red, OUTPUT); // initialize led pin as output
  pinMode(yellow, OUTPUT); // initialize led pin as output
  pinMode(green, OUTPUT); // initialize led pin as output
  randomSeed (analogRead (0)); // randomize
  pinMode(button, INPUT); // initialize button as an input

  Serial.begin(9600);  // start the serial monitor
  Serial.println("Starting Serial Montor"); // send text to serial monitor
}

void loop() {
buttonState = digitalRead(button); // reads button to see if it is pressed
randOn = random (4000,10000); // sets up random variable
 digitalWrite(green, HIGH); // turns on green led, 
 if (buttonState == HIGH) { // checks to see if button is pressed. If it is, then loop initiates
  delay(randOn); // delays for random amount of time (between whatever parameters are set for the randOn variable.
  digitalWrite(green, LOW); // turns off the green led
  Serial.println("Button was pressed"); // prints to serial monitor (mainly for debugging)
  digitalWrite(yellow, HIGH); // turns on yellow led 
  delay(2000);
  digitalWrite(yellow, LOW);
  digitalWrite(red, HIGH); // turns on red led
  delay(1000);
  digitalWrite(walk, HIGH); // turns on blue led
  randOn = random (7000,10000); // randomizes again
  delay(randOn);
  digitalWrite(walk, LOW); // at this time, the walking light starts to blink, and you have 3 seconds to get across
  delay(500);
  digitalWrite(walk, HIGH);
  delay(500);
  digitalWrite(walk, LOW);
  delay(500);
  digitalWrite(walk, HIGH);
  delay(500);
  digitalWrite(walk, LOW);
  delay(500);
  digitalWrite(walk, HIGH);
  delay(500);
  digitalWrite(walk, LOW); // last blue led blink
  delay(3000);
  digitalWrite(red, LOW); // turns red led off and ends loop. Green led turns on after this
 }

}
