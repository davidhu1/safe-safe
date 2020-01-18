#include <Servo.h>
#include "seven_seg_display.h"

// Pin 2-8 is connected to the 7 segments of the display.
int pinA = 2;
int pinB = 3;
int pinC = 4;
int pinD = 5;
int pinE = 6;
int pinF = 7;
int pinG = 8;
int D1 = 9;
int D2 = 10;
int D3 = 11;
int D4 = 12;

// Joystick
const int SW_pin = 13;
const int X_pin = 0;
const int Y_pin = 1;
bool waiting_on_center = false;

// Joystick tolerance
const int low_threshold = 400;
const int high_threshold = 600;

// PIN
int pin [4] = {0, 0, 0, 0};
int pin1 = 0;
int pin2 = 0;
int pin3 = 0;
int pin4 = 0;

// 7 Seg digits
int values [4] = {0, 0, 0, 0};
int value1 = 0;
int value2 = 0;
int value3 = 0;
int value4 = 0;

int current_position = 0;

//Servo Motor
//Servo pin declaration
int servoPin = A2;
//Servo Object
Servo Servo1; 

// Setup routine
void setup() {

  // Set up joystick
  pinMode(SW_pin, INPUT);
  digitalWrite(SW_pin, HIGH);
  Serial.begin(9600);

  // initialize the digital pins as outputs.
  pinMode(pinA, OUTPUT);
  pinMode(pinB, OUTPUT);
  pinMode(pinC, OUTPUT);
  pinMode(pinD, OUTPUT);
  pinMode(pinE, OUTPUT);
  pinMode(pinF, OUTPUT);
  pinMode(pinG, OUTPUT);
  pinMode(D1, OUTPUT);
  pinMode(D2, OUTPUT);
  pinMode(D3, OUTPUT);
  pinMode(D4, OUTPUT);

  // Attach the servo to the used pin number 
  Servo1.attach(servoPin); 
}

// A blink is 1 on and off cycle
void blink (int position, int value) {
  delay(250);
  set_digit(position, 0);
  delay(250);
  set_digit(position, value);
}

// Checks if the pin on the display matches the correct pin stored and returns a boolean accordingly. 
bool pass_fail () {
  for (int i=0; i < 4; i++) {
    if (pin[i] != values[i]) {
      return false;
    }
  }
  return true;
}

// Resets the display back to all 0. Resets current position back to 1. 
void reset_display () {
  values[0] = 0;
  values[1] = 0;
  values[2] = 0;
  values[3] = 0;

  set_digit(1, 0);
  set_digit(2, 0);
  set_digit(3, 0);
  set_digit(4, 0);

  current_position = 0;
}

void open_safe(){
  //servo motor at 90 degrees 
  Servo1.write(90); 
}


void close_safe(){
  //servo motor at 0 degrees
  Servo1.write(0); 
}

// the loop routine runs over and over again forever:
void loop() {

  delay(10); // input delay 

  // Read from joystick
  bool enter = ! digitalRead(SW_pin); // joystick button; true when pressed
  int x_current = analogRead(X_pin); // (back) 0 -> 1023 (forward)
  int y_current = analogRead(Y_pin); // (increment) 0 -> 1023 (decrement)

  if(!waiting_on_center) {
    if(enter) {    
      // Compare PINs
      
    }
    else if(x_current < low_threshold || x_current > high_threshold) {
      // Go back and forth depending on x
      // x < low : go back
      // x > high : go forward

      // Go back one digit
      if (x_current < low_threshold && current_position != 0) {
        current_position--;

      }
      // Go forward one digit
      else if(current_position != 3) {
        current_position++;

      }
      waiting_on_center = true;
    }
    else if(y_current < low_threshold || y_current > high_threshold) {
      // Increment/decrement depending on y
      // y < low : increment
      // y > high : increment

      // Increment value
      if(y_current < low_threshold) {
        if(values[current_position] == 9) {
          values[current_position] = 0;
        }
        else {
          values[current_position]++;
        }
      }
      // Decrement value
      else {
        if(values[current_position] == 0) {
          values[current_position] = 9;
        }
        else {
          values[current_position]--;
        }
      }
      set_digit(current_position, values[current_position]);
      waiting_on_center = true;
    }
  }
  else {
    if(x_current > low_threshold && x_current < high_threshold && y_current > low_threshold && y_current < high_threshold) {
      waiting_on_center = false;
    }
  }

  // Prints for debugging :))
  Serial.print("Switch:  ");
  Serial.print(enter);
  Serial.print("\n");
  Serial.print("X-axis: ");
  Serial.print(x_current);
  Serial.print("\n");
  Serial.print("Y-axis: ");
  Serial.println(y_current);
  Serial.print("\n\n");

//  set_digit(1, 6);
//  delay(1);
//  set_digit(3, 0);
//  delay(1);


  
}
