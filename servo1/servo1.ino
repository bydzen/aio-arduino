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

    pinMode(LED_BUILTIN, OUTPUT);

    digitalWrite(theLED1, LOW);
    digitalWrite(theLED2, LOW);
    digitalWrite(theLED3, LOW);

    digitalWrite(LED_BUILTIN, LOW);

    servo.attach(11);
    servo.write(0);

    delay(2000);

    Serial.begin(9600);
}

void loop()
{
    leftRightPotentiometer = analogRead(A5);

    if (leftRightPotentiometer > 712)
    {
        for (int servoAngle = 0; servoAngle < 180; servoAngle += 1)
        {
            servo.write(servoAngle);
            digitalWrite(theLED1, HIGH);
            digitalWrite(LED_BUILTIN, HIGH);
            delay(50);
            digitalWrite(theLED1, LOW);
            digitalWrite(LED_BUILTIN, LOW);
            delay(50);
            Serial.print("Angle Servo (Left)  : ");
            Serial.println(servoAngle);
        }
        digitalWrite(theLED2, HIGH);
        delay(2000);
        digitalWrite(theLED2, LOW);
        delay(1000);
    }
    else if (leftRightPotentiometer < 312)
    {
        for (int servoAngle = 180; servoAngle > 0; servoAngle -= 1)
        {
            servo.write(servoAngle);
            digitalWrite(theLED3, HIGH);
            digitalWrite(LED_BUILTIN, HIGH);
            delay(50);
            digitalWrite(theLED3, LOW);
            digitalWrite(LED_BUILTIN, LOW);
            delay(50);
            Serial.print("Angle Servo (Right) : ");
            Serial.println(servoAngle);
        }
        digitalWrite(theLED2, HIGH);
        delay(2000);
        digitalWrite(theLED2, LOW);
        delay(1000);
    }
    else
    {
        Serial.print("Potentiometer Value : ");
        Serial.println(leftRightPotentiometer);
        digitalWrite(theLED2, HIGH);
        digitalWrite(LED_BUILTIN, HIGH);
        delay(500);
        digitalWrite(theLED2, LOW);
        digitalWrite(LED_BUILTIN, LOW);
        delay(500);
    }
}
