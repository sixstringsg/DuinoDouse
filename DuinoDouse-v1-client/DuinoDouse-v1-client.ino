/*
DuinoDouse v1 - Client

Hardware Connections for Servo1:
  Connect the RED wire (power) to 5 Volts (5V)
  Connect the WHITE wire (signal) to digital pin 9
  Connect the BLACK wire (ground) to ground (GND)
*/
#include <Servo.h> //include servo library

//Constants that won't change
const int buttonPin = 2;        //Digital Pushbutton connected to pin 2

Servo servo1;  // servo control object setup

//Variables that will change
int buttonPushCounter = 0;      //counter for the number of button presses
int buttonState = 0;            //current state of the button
int lastButtonState = 0;        //previous state of the button

void setup()
{
  // Initialize the button pin as an input
  pinMode(buttonPin, INPUT);
  // Initialize serial communication
  Serial.begin(9600);
  // Attach servo1 to pin 9
  servo1.attach(9);
}

void loop()
{
  // Read the pushbutton input pin;
  buttonState = digitalRead(buttonPin);
  // Compare button state to it's previous state
  if (buttonState != lastButtonState) {
    // If the state has changed, increment the counter
    if (buttonState == HIGH) {
      //If the current state is HIGH then the
      //button went from of to on
      buttonPushCounter++;
      Serial.println("on");
      Serial.println("number of button presses:");
      Serial.println(buttonPushCounter);
    }
    else {
      //if the current state is LOW then the button
      // went from on to off;
      Serial.println("off");
    }
  }
  //Save the current state as the last state,
  //for next time through the loop
  lastButtonState = buttonState;

  //Moves the servo from open to closed every other button press
  if (buttonPushCounter % 2 == 0) {
    servo1.write(90);   // move the servo to 90º to cover lens
    delay(1000);        // Prevent servo from moving before complete
  }
  else {
    servo1.write(0);    // move the servo to 0º to uncover lens
    delay(1000);        // Prevent servo from moving before complete
  }
}
