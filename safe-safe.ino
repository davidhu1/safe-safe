/*
  Showing number 0-9 on a Common Anode 7-segment LED display
  Displays the numbers 0-9 on the display, with one second inbetween.
    A
   ---
  F |   | B
  | G |
   ---
  E |   | C
  |   |
   ---
    D
  This example code is in the public domain.
*/

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

// Joystick tolerance
const int low_threshold = 400;
const int high_threshold = 600;

bool centered = true;

// PIN
int pin1 = 0;
int pin2 = 0;
int pin3 = 0;
int pin4 = 0;

// 7 Segs
int value1 = 0;
int value2 = 0;
int value3 = 0;
int value4 = 0;

int current_position = 1;

// the setup routine runs once when you press reset:
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
}

// Takes in which the seg to 
void set_digit(int position, int value) {
  //Initialize
  digitalWrite(D1, HIGH);
  digitalWrite(D2, HIGH);
  digitalWrite(D3, HIGH);
  digitalWrite(D4, HIGH);

  //Initialize
  digitalWrite(pinA, LOW);
  digitalWrite(pinB, LOW);
  digitalWrite(pinC, LOW);
  digitalWrite(pinD, LOW);
  digitalWrite(pinE, LOW);
  digitalWrite(pinF, LOW);
  digitalWrite(pinG, LOW);
  
  if (position == 1) {
    digitalWrite(D1, LOW);
  }
  else if (position == 2) {
    digitalWrite(D2, LOW);
  }
  else if (position == 3) {
    digitalWrite(D3, LOW);
  }
  else if (position == 4) {
    digitalWrite(D4, LOW);
  }

  if (value == 0) {
    digitalWrite(pinA, HIGH);
    digitalWrite(pinB, HIGH);
    digitalWrite(pinC, HIGH);
    digitalWrite(pinD, HIGH);
    digitalWrite(pinE, HIGH);
    digitalWrite(pinF, HIGH);
  }
  else if (value == 1) {
    digitalWrite(pinB, HIGH);
    digitalWrite(pinC, HIGH);
  }
  else if (value == 2) {
    digitalWrite(pinA, HIGH);
    digitalWrite(pinB, HIGH);
    digitalWrite(pinD, HIGH);
    digitalWrite(pinE, HIGH);
    digitalWrite(pinG, HIGH);
  }
  else if (value == 3) {
    digitalWrite(pinB, HIGH);
    digitalWrite(pinC, HIGH);
    digitalWrite(pinF, HIGH);
    digitalWrite(pinG, HIGH);
  }
  else if (value == 4) {
    digitalWrite(pinA, HIGH);
    digitalWrite(pinC, HIGH);
    digitalWrite(pinD, HIGH);
    digitalWrite(pinF, HIGH);
    digitalWrite(pinG, HIGH);
  }
  else if (value == 5) {
    digitalWrite(pinA, HIGH);
    digitalWrite(pinC, HIGH);
    digitalWrite(pinD, HIGH);
    digitalWrite(pinF, HIGH);
    digitalWrite(pinG, HIGH);
  }
  else if (value == 6) {
    digitalWrite(pinA, HIGH);
    digitalWrite(pinC, HIGH);
    digitalWrite(pinD, HIGH);
    digitalWrite(pinE, HIGH);
    digitalWrite(pinF, HIGH);
    digitalWrite(pinG, HIGH);
  }
  else if (value == 7) {
    digitalWrite(pinA, HIGH);
    digitalWrite(pinB, HIGH);
    digitalWrite(pinC, HIGH);
    digitalWrite(pinF, HIGH);
  }
  else if (value == 8) {
    digitalWrite(pinA, HIGH);
    digitalWrite(pinB, HIGH);
    digitalWrite(pinC, HIGH);
    digitalWrite(pinD, HIGH);
    digitalWrite(pinE, HIGH);
    digitalWrite(pinF, HIGH);
    digitalWrite(pinG, HIGH);
  }
  else if (value == 9) {
    digitalWrite(pinA, HIGH);
    digitalWrite(pinB, HIGH);
    digitalWrite(pinC, HIGH);
    digitalWrite(pinD, HIGH);
    digitalWrite(pinF, HIGH);
    digitalWrite(pinG, HIGH);
  }
  delay(1);
}

// A blink is 3 off and on cycles
void blink (int position, int value) {

}

// Checks if the pin on the display matches the correct pin stored and returns a boolean accordingly. 
bool pass_fail () {
  if (pin1 != value1) return false;
  if (pin2 != value2) return false;
  if (pin3 != value3) return false;
  if (pin4 != value4) return false;
  return true;
}

void reset_display () {
  set_digit(1, 0);
  set_digit()
  current_position = 1;
  blink(1, value1)
}

// the loop routine runs over and over again forever:
void loop() {

  delay(1000); // input delay 
  bool enter = ! digitalRead(SW_pin); // joystick button; true when pressed
  int x_current = digitalRead(X_pin); // (back) 0 -> 1023 (forward)
  int y_current = digitalRead(Y_pin; // (increment) 0 -> 1023 (decrement)

  if(enter) {    
    // Compare PINs

  }
  else if(x_current < low_threshold || x_current > high_threshold) {
    // Go back and forth depending on x
    // x < low : go back
    // x > high : go forward
  }
  else if(y_current < low_threshold || y_current > high_threshold) {
    // Increment/decrement depending on y
    // y < low : increment
    // y > high : increment
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

#include <Servo.h>
/*
  Showing number 0-9 on a Common Anode 7-segment LED display
  Displays the numbers 0-9 on the display, with one second inbetween.
    A
   ---
  F |   | B
  | G |
   ---
  E |   | C
  |   |
   ---
    D
  This example code is in the public domain.
*/

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

// Joystick tolerance
const int low_threshold = 400;
const int high_threshold = 600;

bool centered = true;

// PIN
int pin = 0;

// 7 Segs
int value1 = 0;
int value2 = 0;
int value3 = 0;
int value4 = 0;

int current_position = 1;

//Servo Motor
//Servo pin declaration
int servoPin = A2;
//Servo Object
Servo Servo1; 

// the setup routine runs once when you press reset:
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

// Takes in which the seg to 
void set_digit(int position, int value) {
  //Initialize
  digitalWrite(D1, HIGH);
  digitalWrite(D2, HIGH);
  digitalWrite(D3, HIGH);
  digitalWrite(D4, HIGH);

  //Initialize
  digitalWrite(pinA, LOW);
  digitalWrite(pinB, LOW);
  digitalWrite(pinC, LOW);
  digitalWrite(pinD, LOW);
  digitalWrite(pinE, LOW);
  digitalWrite(pinF, LOW);
  digitalWrite(pinG, LOW);
  
  if (position == 1) {
    digitalWrite(D1, LOW);
  }
  else if (position == 2) {
    digitalWrite(D2, LOW);
  }
  else if (position == 3) {
    digitalWrite(D3, LOW);
  }
  else if (position == 4) {
    digitalWrite(D4, LOW);
  }

  if (value == 0) {
    digitalWrite(pinA, HIGH);
    digitalWrite(pinB, HIGH);
    digitalWrite(pinC, HIGH);
    digitalWrite(pinD, HIGH);
    digitalWrite(pinE, HIGH);
    digitalWrite(pinF, HIGH);
  }
  else if (value == 1) {
    digitalWrite(pinB, HIGH);
    digitalWrite(pinC, HIGH);
  }
  else if (value == 2) {
    digitalWrite(pinA, HIGH);
    digitalWrite(pinB, HIGH);
    digitalWrite(pinD, HIGH);
    digitalWrite(pinE, HIGH);
    digitalWrite(pinG, HIGH);
  }
  else if (value == 3) {
    digitalWrite(pinB, HIGH);
    digitalWrite(pinC, HIGH);
    digitalWrite(pinF, HIGH);
    digitalWrite(pinG, HIGH);
  }
  else if (value == 4) {
    digitalWrite(pinA, HIGH);
    digitalWrite(pinC, HIGH);
    digitalWrite(pinD, HIGH);
    digitalWrite(pinF, HIGH);
    digitalWrite(pinG, HIGH);
  }
  else if (value == 5) {
    digitalWrite(pinA, HIGH);
    digitalWrite(pinC, HIGH);
    digitalWrite(pinD, HIGH);
    digitalWrite(pinF, HIGH);
    digitalWrite(pinG, HIGH);
  }
  else if (value == 6) {
    digitalWrite(pinA, HIGH);
    digitalWrite(pinC, HIGH);
    digitalWrite(pinD, HIGH);
    digitalWrite(pinE, HIGH);
    digitalWrite(pinF, HIGH);
    digitalWrite(pinG, HIGH);
  }
  else if (value == 7) {
    digitalWrite(pinA, HIGH);
    digitalWrite(pinB, HIGH);
    digitalWrite(pinC, HIGH);
    digitalWrite(pinF, HIGH);
  }
  else if (value == 8) {
    digitalWrite(pinA, HIGH);
    digitalWrite(pinB, HIGH);
    digitalWrite(pinC, HIGH);
    digitalWrite(pinD, HIGH);
    digitalWrite(pinE, HIGH);
    digitalWrite(pinF, HIGH);
    digitalWrite(pinG, HIGH);
  }
  else if (value == 9) {
    digitalWrite(pinA, HIGH);
    digitalWrite(pinB, HIGH);
    digitalWrite(pinC, HIGH);
    digitalWrite(pinD, HIGH);
    digitalWrite(pinF, HIGH);
    digitalWrite(pinG, HIGH);
  }
  delay(1);
}

void blink (int position, int value) {
  
}

// the loop routine runs over and over again forever:
void loop() {

  delay(1000); // input delay 
  bool enter = ! digitalRead(SW_pin); // joystick button; true when pressed
  int x_current = digitalRead(X_pin); // (back) 0 -> 1023 (forward)
  int y_current = digitalRead(Y_pin; // (increment) 0 -> 1023 (decrement)

  if(enter) {    
    // Compare PINs

  }
  else if(x_current < low_threshold || x_current > high_threshold) {
    // Go back and forth depending on x
    // x < low : go back
    // x > high : go forward
  }
  else if(y_current < low_threshold || y_current > high_threshold) {
    // Increment/decrement depending on y
    // y < low : increment
    // y > high : increment
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

//servo motor at 0 degrees
  Servo1.write(0); 
  delay(1000); 

//servo motor at 90 degrees
  Servo1.write(90); 
  delay(1000); 

//servo motor at 180 degrees
  Servo1.write(180); 
  delay(1000); 

  
}
