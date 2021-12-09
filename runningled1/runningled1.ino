int theLED1 = 2;
int theLED2 = 3;
int theLED3 = 4;

int theLED4 = 5;
int theLED5 = 6;
int theLED6 = 7;

int theLED7 = 8;

void setup() {
  pinMode(theLED1, OUTPUT);
  pinMode(theLED2, OUTPUT);
  pinMode(theLED3, OUTPUT);
 
  pinMode(theLED4, OUTPUT);
  pinMode(theLED5, OUTPUT);
  pinMode(theLED6, OUTPUT);

  pinMode(theLED7, OUTPUT);

  digitalWrite(theLED1, LOW);
  digitalWrite(theLED2, LOW);
  digitalWrite(theLED3, LOW);

  digitalWrite(theLED4, LOW);
  digitalWrite(theLED5, LOW);
  digitalWrite(theLED6, LOW);

  digitalWrite(theLED7, LOW);

  Serial.begin(9600);
}

void loop() {
  int speedLED = analogRead(A5);
  
//  // Blink 
//  for (int i = 2; i < 9; i++) {
//    int speedLED = analogRead(A5);
//    digitalWrite(i, HIGH);
//    delay(speedLED);
//    digitalWrite(i, LOW);
//    delay(speedLED);
//  }
//
//  for (int i = 7; i > 2; i--) {
//    int speedLED = analogRead(A5);
//    digitalWrite(i, HIGH);
//    delay(speedLED);
//    digitalWrite(i, LOW);
//    delay(speedLED);
//  }

//  // Hold
//  for (int i = 2; i < 9; i++) {
//    int speedLED = analogRead(A5);
//    digitalWrite(i, HIGH);
//    delay(speedLED*2);
//  }
//
//  for (int i = 8; i > 1; i--) {
//    int speedLED = analogRead(A5);
//    digitalWrite(i, LOW);
//    delay(speedLED*2);
//  }
//
//  // Hold reverse
//  for (int i = 8; i > 1; i--) {
//    int speedLED = analogRead(A5);
//    digitalWrite(i, HIGH);
//    delay(speedLED*2);
//  }
//
//  for (int i = 2; i < 9; i++) {
//    int speedLED = analogRead(A5);
//    digitalWrite(i, LOW);
//    delay(speedLED*2);
//  }

  // Snake start to end
  for (int i = 2; i < 9; i++) {
    int speedLED = analogRead(A5);
    digitalWrite(i, HIGH);
    if (i == 8) {
      delay(350);
      break;
    }
    delay(speedLED);
  }

  for (int i = 2; i < 9; i++) {
    int speedLED = analogRead(A5);
    digitalWrite(i, LOW);
    if (i == 8) {
      delay(350);
      break;
    }
    delay(speedLED/2);
  }

//  // Snake back reverse start
//  for (int i = 7; i > 1; i--) {
//    int speedLED = analogRead(A5);
//    digitalWrite(i, HIGH);
//    delay(speedLED/4);
//    digitalWrite(i, LOW);
//  }
//
//  // Snake next end
//  for (int i = 2; i < 9; i++) {
//    int speedLED = analogRead(A5);
//    digitalWrite(i, HIGH);
//    delay(speedLED/4);
//    digitalWrite(i, LOW);
//  }
//
//  // Snake reverse
//  for (int i = 8; i > 1; i--) {
//    int speedLED = analogRead(A5);
//    digitalWrite(i, HIGH);
//    if (i == 2) {
//      break;
//    }
//    delay(speedLED);
//  }
//
//  for (int i = 8; i > 1; i--) {
//    int speedLED = analogRead(A5);
//    digitalWrite(i, LOW);
//    if (i == 2) {
//      break;
//    }
//    delay(speedLED);
//  }
//
//  // Snake back reverse end
//  for (int i = 2; i < 9; i++) {
//    int speedLED = analogRead(A5);
//    digitalWrite(i, HIGH);
//    delay(speedLED/4);
//    digitalWrite(i, LOW);
//  }
//
//  // Snake next start
//  for (int i = 7; i > 1; i--) {
//    int speedLED = analogRead(A5);
//    digitalWrite(i, HIGH);
//    delay(speedLED/4);
//    digitalWrite(i, LOW);
//  }
}
