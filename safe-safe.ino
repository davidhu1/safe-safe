#include <boarddefs.h>
#include <IRremote.h>
#include <IRremoteInt.h>
#include <ir_Lego_PF_BitStreamEncoder.h>

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


const int RECV_PIN = 13;
IRrecv irrecv(RECV_PIN);
decode_results results;

// the setup routine runs once when you press reset:
void setup() {
  
  Serial.begin(9600);
  irrecv.enableIRIn();
  irrecv.blink13(true);

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
void set_digit(int segment, int digit) {
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
  
  if (segment == 1) {
    digitalWrite(D1, LOW);
  }
  else if (segment == 2) {
    digitalWrite(D2, LOW);
  }
  else if (segment == 3) {
    digitalWrite(D3, LOW);
  }
  else if (segment == 4) {
    digitalWrite(D4, LOW);
  }

  if (digit == 0) {
    digitalWrite(pinA, HIGH);
    digitalWrite(pinB, HIGH);
    digitalWrite(pinC, HIGH);
    digitalWrite(pinD, HIGH);
    digitalWrite(pinE, HIGH);
    digitalWrite(pinF, HIGH);
  }
  else if (digit == 1) {
    digitalWrite(pinB, HIGH);
    digitalWrite(pinC, HIGH);
  }
  else if (digit == 2) {
    digitalWrite(pinA, HIGH);
    digitalWrite(pinB, HIGH);
    digitalWrite(pinD, HIGH);
    digitalWrite(pinE, HIGH);
    digitalWrite(pinG, HIGH);
  }
  else if (digit == 3) {
    digitalWrite(pinB, HIGH);
    digitalWrite(pinC, HIGH);
    digitalWrite(pinF, HIGH);
    digitalWrite(pinG, HIGH);
  }
  else if (digit == 4) {
    digitalWrite(pinA, HIGH);
    digitalWrite(pinC, HIGH);
    digitalWrite(pinD, HIGH);
    digitalWrite(pinF, HIGH);
    digitalWrite(pinG, HIGH);
  }
  else if (digit == 5) {
    digitalWrite(pinA, HIGH);
    digitalWrite(pinC, HIGH);
    digitalWrite(pinD, HIGH);
    digitalWrite(pinF, HIGH);
    digitalWrite(pinG, HIGH);
  }
  else if (digit == 6) {
    digitalWrite(pinA, HIGH);
    digitalWrite(pinC, HIGH);
    digitalWrite(pinD, HIGH);
    digitalWrite(pinE, HIGH);
    digitalWrite(pinF, HIGH);
    digitalWrite(pinG, HIGH);
  }
  else if (digit == 7) {
    digitalWrite(pinA, HIGH);
    digitalWrite(pinB, HIGH);
    digitalWrite(pinC, HIGH);
    digitalWrite(pinF, HIGH);
  }
  else if (digit == 8) {
    digitalWrite(pinA, HIGH);
    digitalWrite(pinB, HIGH);
    digitalWrite(pinC, HIGH);
    digitalWrite(pinD, HIGH);
    digitalWrite(pinE, HIGH);
    digitalWrite(pinF, HIGH);
    digitalWrite(pinG, HIGH);
  }
  else if (digit == 9) {
    digitalWrite(pinA, HIGH);
    digitalWrite(pinB, HIGH);
    digitalWrite(pinC, HIGH);
    digitalWrite(pinD, HIGH);
    digitalWrite(pinF, HIGH);
    digitalWrite(pinG, HIGH);
  }
  delay(1);
}

// the loop routine runs over and over again forever:
void loop() {

  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);
    irrecv.resume();
  }
  
  set_digit(1, 6);
  set_digit(3, 0);
}
