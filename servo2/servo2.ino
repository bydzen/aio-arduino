#include <Servo.h>

Servo servo;

int theLED1 = 2;
int theLED2 = 3;
int theLED3 = 4;

int leftRightPotentiometer;

void setup()
{
    pinMode(theLED1, OUTPUT);
    pinMode(theLED2, OUTPUT);
    pinMode(theLED3, OUTPUT);

    digitalWrite(theLED1, LOW);
    digitalWrite(theLED2, LOW);
    digitalWrite(theLED3, LOW);

    servo.attach(11);
    servo.write(0);

    delay(2000);

    Serial.begin(9600);
}

void loop()
{
    leftRightPotentiometer = analogRead(A5);

    if (leftRightPotentiometer > 562)
    {
        servo.write(180);
        Serial.print("Rotate (Left)  : ");
        Serial.println(leftRightPotentiometer);
        digitalWrite(theLED2, LOW);
        digitalWrite(theLED1, HIGH);
        digitalWrite(theLED3, LOW);
        delay(250);
    }
    else if (leftRightPotentiometer < 462)
    {
        servo.write(0);
        Serial.print("Rotate (Right) : ");
        Serial.println(leftRightPotentiometer);
        digitalWrite(theLED2, LOW);
        digitalWrite(theLED1, LOW);
        digitalWrite(theLED3, HIGH);
        delay(250);
    }
    else
    {
        servo.write(90);
        digitalWrite(theLED2, HIGH);
        digitalWrite(theLED1, LOW);
        digitalWrite(theLED3, LOW);
        delay(250);
    }
}
