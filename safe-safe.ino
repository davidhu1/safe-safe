#include <Servo.h>

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
int pin [4] = {1, 5, 2, 1};

// 7 Seg digits
int values [4] = {0, 0, 0, 0};

int current_position = 0;

//Servo Motor
//Servo pin declaration
int servoPin = A3;
//Servo Object
Servo Servo1; 

bool locked = true;

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

// Look Up Table for Seven Seg display digits
void set_digit(int place, int value) {
  // Write to the appropriate position:
  if (place == 0) {
    digitalWrite(D1, LOW);
    digitalWrite(D2, HIGH);
    digitalWrite(D3, HIGH);
    digitalWrite(D4, HIGH);
  }
  else if (place == 1) {
    digitalWrite(D1, HIGH);
    digitalWrite(D2, LOW);
    digitalWrite(D3, HIGH);
    digitalWrite(D4, HIGH);
  }
  else if (place == 2) {
    digitalWrite(D1, HIGH);
    digitalWrite(D2, HIGH);
    digitalWrite(D3, LOW);
    digitalWrite(D4, HIGH);
  }
  else if (place == 3) {
    digitalWrite(D1, HIGH);
    digitalWrite(D2, HIGH);    
    digitalWrite(D3, HIGH);
    digitalWrite(D4, LOW);
  }

  if (value == 0) {
    digitalWrite(pinA, HIGH);
    digitalWrite(pinB, HIGH);
    digitalWrite(pinC, HIGH);
    digitalWrite(pinD, HIGH);
    digitalWrite(pinE, HIGH);
    digitalWrite(pinF, HIGH);
    digitalWrite(pinG, LOW);
  }
  else if (value == 1) {
    digitalWrite(pinA, LOW);
    digitalWrite(pinB, HIGH);
    digitalWrite(pinC, HIGH);
    digitalWrite(pinD, LOW);
    digitalWrite(pinE, LOW);
    digitalWrite(pinF, LOW);
    digitalWrite(pinG, LOW);
  }
  else if (value == 2) {
    digitalWrite(pinA, HIGH);
    digitalWrite(pinB, HIGH);
    digitalWrite(pinC, LOW);
    digitalWrite(pinD, HIGH);
    digitalWrite(pinE, HIGH);
    digitalWrite(pinF, LOW);
    digitalWrite(pinG, HIGH);
  }
  else if (value == 3) {
    digitalWrite(pinA, HIGH);
    digitalWrite(pinB, HIGH);
    digitalWrite(pinC, HIGH);
    digitalWrite(pinD, HIGH);
    digitalWrite(pinE, LOW);
    digitalWrite(pinF, LOW);
    digitalWrite(pinG, HIGH);
  }
  else if (value == 4) {
    digitalWrite(pinA, LOW);
    digitalWrite(pinB, HIGH);
    digitalWrite(pinC, HIGH);
    digitalWrite(pinD, LOW);
    digitalWrite(pinE, LOW);
    digitalWrite(pinF, HIGH);
    digitalWrite(pinG, HIGH);
  }
  else if (value == 5) {
    digitalWrite(pinA, HIGH);
    digitalWrite(pinB, LOW);
    digitalWrite(pinC, HIGH);
    digitalWrite(pinD, HIGH);
    digitalWrite(pinE, LOW);
    digitalWrite(pinF, HIGH);
    digitalWrite(pinG, HIGH);
  }
  else if (value == 6) {
    digitalWrite(pinA, HIGH);
    digitalWrite(pinB, LOW);
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
    digitalWrite(pinD, LOW);
    digitalWrite(pinE, LOW);
    digitalWrite(pinF, HIGH);
    digitalWrite(pinG, LOW);
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
    digitalWrite(pinE, LOW);
    digitalWrite(pinF, HIGH);
    digitalWrite(pinG, HIGH);
  }
  else if (value == -1) {
    digitalWrite(pinA, LOW);
    digitalWrite(pinB, LOW);
    digitalWrite(pinC, LOW);
    digitalWrite(pinD, LOW);
    digitalWrite(pinE, LOW);
    digitalWrite(pinF, LOW);
    digitalWrite(pinG, LOW);
  }
  delay(1);
}


// Displays the word "PASS" on the seven segment display for 0.5 seconds
void display_pass() {
  for(int i=0; i < 175; i++) {
    delay(1);
    // Position 1
    digitalWrite(D1, LOW);
    digitalWrite(D2, HIGH);
    digitalWrite(D3, HIGH);
    digitalWrite(D4, HIGH);
    // "P"
    digitalWrite(pinA, HIGH);
    digitalWrite(pinB, HIGH);
    digitalWrite(pinC, LOW);
    digitalWrite(pinD, LOW);
    digitalWrite(pinE, HIGH);
    digitalWrite(pinF, HIGH);
    digitalWrite(pinG, HIGH);
    delay(1);
    // Position 2
    digitalWrite(D1, HIGH);
    digitalWrite(D2, LOW);
    digitalWrite(D3, HIGH);
    digitalWrite(D4, HIGH);
    // "A"
    digitalWrite(pinA, HIGH);
    digitalWrite(pinB, HIGH);
    digitalWrite(pinC, HIGH);
    digitalWrite(pinD, LOW);
    digitalWrite(pinE, HIGH);
    digitalWrite(pinF, HIGH);
    digitalWrite(pinG, HIGH);
    delay(1);
    // Position 3 & 4
    digitalWrite(D1, HIGH);
    digitalWrite(D2, HIGH);
    digitalWrite(D3, LOW);
    digitalWrite(D4, LOW);
    // "S"
    digitalWrite(pinA, HIGH);
    digitalWrite(pinB, LOW);
    digitalWrite(pinC, HIGH);
    digitalWrite(pinD, HIGH);
    digitalWrite(pinE, LOW);
    digitalWrite(pinF, HIGH);
    digitalWrite(pinG, HIGH);
    delay(1);
  }
}

// Displays the word "FAIL" on the seven segment display for 0.5 seconds
void display_fail() {
  for(int i=0; i < 175; i++) {
    delay(1);
    // Position 1
    digitalWrite(D1, LOW);
    digitalWrite(D2, HIGH);
    digitalWrite(D3, HIGH);
    digitalWrite(D4, HIGH);
    // "F"
    digitalWrite(pinA, HIGH);
    digitalWrite(pinB, LOW);
    digitalWrite(pinC, LOW);
    digitalWrite(pinD, LOW);
    digitalWrite(pinE, HIGH);
    digitalWrite(pinF, HIGH);
    digitalWrite(pinG, HIGH);
    delay(1);

    // Position 2
    digitalWrite(D1, HIGH);
    digitalWrite(D2, LOW);
    digitalWrite(D3, HIGH);
    digitalWrite(D4, HIGH);
    // "A"
    digitalWrite(pinA, HIGH);
    digitalWrite(pinB, HIGH);
    digitalWrite(pinC, HIGH);
    digitalWrite(pinD, LOW);
    digitalWrite(pinE, HIGH);
    digitalWrite(pinF, HIGH);
    digitalWrite(pinG, HIGH);
    delay(1);

    // Position 3
    digitalWrite(D1, HIGH);
    digitalWrite(D2, HIGH);
    digitalWrite(D3, LOW);
    digitalWrite(D4, HIGH);
    // "I"
    digitalWrite(pinA, LOW);
    digitalWrite(pinB, HIGH);
    digitalWrite(pinC, HIGH);
    digitalWrite(pinD, LOW);
    digitalWrite(pinE, LOW);
    digitalWrite(pinF, LOW);
    digitalWrite(pinG, LOW);
    delay(1);

    // Position 4
    digitalWrite(D1, HIGH);
    digitalWrite(D2, HIGH);
    digitalWrite(D3, HIGH);
    digitalWrite(D4, LOW);
    // "L"
    digitalWrite(pinA, LOW);
    digitalWrite(pinB, LOW);
    digitalWrite(pinC, LOW);
    digitalWrite(pinD, HIGH);
    digitalWrite(pinE, HIGH);
    digitalWrite(pinF, HIGH);
    digitalWrite(pinG, LOW);
    delay(1);
  }
}

// A blink is 1 on and off cycle
void blink (int position, int value) {
  delay(250);
  set_digit(position, 0);
  delay(250);
  set_digit(position, value);
}

/**
 * @author Serena He
 * Flashes display on and off rapidly.
*/
void flash_display() {
  for (int i=0; i < 3; i++) {
    for (int dig=0; dig < 4; dig++) {
      (i % 2 == 0) ? set_digit(dig, -1) : set_digit(dig, values[dig]);
    }
    delay(100);
  }
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

/**
 * @author Serena He
 * Check if SW_pin is being held down; returns true for a hold of more than 2 seconds.
 * @return if enter is held longer than 2 seconds
*/
bool is_enter_held() {
  bool enter_held = true;

  for(int i=0; i < 20; i++) {
    delay(100);
    enter_held = ! digitalRead(SW_pin);
    if (!enter_held) {
      return false;
    }
  }
  return true;
}

void reset_pin() {
  for(int i=0; i < 4; i++) {
    pin[i] = values[i];
  }
}

/**
 * @author Serena He
 * Loops on Arduino infinitely, checking for joystick inputs.
 */
void loop() {
  // Read from joystick
  bool enter = ! digitalRead(SW_pin); // joystick button; true when pressed
  int x_current = analogRead(X_pin); // (back) 0 -> 1023 (forward)
  int y_current = analogRead(Y_pin); // (increment) 0 -> 1023 (decrement)

  // Joystick must return to center position after each movements
  if(!waiting_on_center) {
    if(enter) {
      /*
        Joystick pressed to open/close safe
      */
      // Safe is currently open
      if(!locked) {
        close_safe();
        locked = true;
        delay(10);
      }  
      // PIN match
      else if(pass_fail()) {
        display_pass(); 
        reset_display();
        open_safe();
        locked = false;
        delay(10);
      }
      // PIN mismatch
      else {
        flash_display();
      }
    }
    else if(x_current < low_threshold || x_current > high_threshold) {
      /* 
        Go back and forth between digits
        x < low : go back
        x > high : go forward
      */

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
      /* 
        Increment/decrement digit display
        y < low : increment
        y > high : increment
      */

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
    // Check if joystick has been recentered
    if(x_current > low_threshold && x_current < high_threshold && y_current > low_threshold && y_current < high_threshold) {
      waiting_on_center = false;
    }
  }
  // Update values of display
  for (int i=0; i < 4; i++) {
    set_digit(i, values[i]);
  }
}
