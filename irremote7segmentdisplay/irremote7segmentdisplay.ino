#include <IRremote.h>

int irPIN = 10;

IRrecv recv(irPIN);
decode_results clickButton;

int G = 2;
int F = 3;
int E = 4;
int D = 5;
int C = 6;
int B = 7;
int A = 8;
int DP = 9;

void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);

  recv.enableIRIn();
  
  pinMode(G, OUTPUT);
  pinMode(F, OUTPUT);
  pinMode(E, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(A, OUTPUT);
  pinMode(DP, OUTPUT);
  
  Serial.begin(9600);
}

void loop()
{
//  List of value button pressed on variabel numPressed
//  Remote type: Remote Control Audio Mp3 Player RD-002 by RAYDEN
//  12495   = 1
//  6375    = 2
//  31365   = 3
//  4335    = 4
//  14535   = 5
//  23205   = 6
//  17085   = 7
//  19125   = 8
//  21165   = 9
//  -20401  = 0
  
  if(recv.decode(&clickButton)) {
    int numPressed = clickButton.value;
    // Serial.println(recv.decode(&clickButton));
    // Serial.println(clickButton.value);
    Serial.println(numPressed);
    if(numPressed == 12495) {
      numOne();
    } else if(numPressed == 6375) {
      numTwo();
    } else if (numPressed == 31365) {
      numThree();
    } else if (numPressed == 4335) {
      numFour();
    } else if (numPressed == 14535) {
      numFive();
    } else if (numPressed == 23205) {
      numSix();
    } else if (numPressed == 17085) {
      numSeven();
    } else if (numPressed == 19125) {
      numEight();
    } else if (numPressed == 21165) {
      numNine();
    } else if (numPressed == -20401) {
      numZero();
    }
    digitalWrite(LED_BUILTIN, HIGH);
    turnOffAll();
    recv.resume();
  }
}

void numOne() {
  digitalWrite(G, LOW);
  digitalWrite(F, LOW);
  digitalWrite(E, LOW);
  digitalWrite(D, LOW);
  digitalWrite(C, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(A, LOW);
  digitalWrite(DP, HIGH);
}

void numTwo() {
  digitalWrite(G, HIGH);
  digitalWrite(F, LOW);
  digitalWrite(E, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(C, LOW);
  digitalWrite(B, HIGH);
  digitalWrite(A, HIGH);
  digitalWrite(DP, HIGH);
}

void numThree() {
  digitalWrite(G, HIGH);
  digitalWrite(F, LOW);
  digitalWrite(E, LOW);
  digitalWrite(D, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(A, HIGH);
  digitalWrite(DP, HIGH);
}

void numFour() {
  digitalWrite(G, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(E, LOW);
  digitalWrite(D, LOW);
  digitalWrite(C, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(A, LOW);
  digitalWrite(DP, HIGH);
}

void numFive()
{
  digitalWrite(G, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(E, LOW);
  digitalWrite(D, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(B, LOW);
  digitalWrite(A, HIGH);
  digitalWrite(DP, HIGH);
}

void numSix() {
  digitalWrite(G, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(B, LOW);
  digitalWrite(A, HIGH);
  digitalWrite(DP, HIGH);
}

void numSeven() {
  digitalWrite(G, LOW);
  digitalWrite(F, LOW);
  digitalWrite(E, LOW);
  digitalWrite(D, LOW);
  digitalWrite(C, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(A, HIGH);
  digitalWrite(DP, HIGH);
}

void numEight() {
  digitalWrite(G, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(A, HIGH);
  digitalWrite(DP, HIGH);
}

void numNine() {
  digitalWrite(G, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(E, LOW);
  digitalWrite(D, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(A, HIGH);
  digitalWrite(DP, HIGH);
}

void numZero() {
  digitalWrite(G, LOW);
  digitalWrite(F, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(A, HIGH);
  digitalWrite(DP, HIGH);
}

void turnOffAll() {
  delay(1000);
  digitalWrite(LED_BUILTIN, LOW);
  digitalWrite(G, LOW);
  digitalWrite(F, LOW);
  digitalWrite(E, LOW);
  digitalWrite(D, LOW);
  digitalWrite(C, LOW);
  digitalWrite(B, LOW);
  digitalWrite(A, LOW);
  digitalWrite(DP, LOW);
}
