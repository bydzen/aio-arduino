int theLED1 = 2;
int theLED2 = 3;
int theLED3 = 4;

int theLED4 = 5;
int theLED5 = 6;
int theLED6 = 7;

int theLED7 = 8;

int randomLED;
int delayTime;

void setup()
{
    pinMode(theLED1, OUTPUT);
    pinMode(theLED2, OUTPUT);
    pinMode(theLED3, OUTPUT);

    pinMode(theLED4, OUTPUT);
    pinMode(theLED5, OUTPUT);
    pinMode(theLED6, OUTPUT);

    pinMode(theLED7, OUTPUT);

    pinMode(LED_BUILTIN, OUTPUT);

    digitalWrite(theLED1, LOW);
    digitalWrite(theLED2, LOW);
    digitalWrite(theLED3, LOW);

    digitalWrite(theLED4, LOW);
    digitalWrite(theLED5, LOW);
    digitalWrite(theLED6, LOW);

    digitalWrite(theLED7, LOW);

    digitalWrite(LED_BUILTIN, LOW);

    delay(2000);

    Serial.begin(9600);
}

void loop()
{
    delayTime = analogRead(A5);
    randomLED = random(2, 9);

    if (delayTime <= 50)
    {
        delayTime = 50;
    }
    else if (delayTime >= 1000)
    {
        delayTime = 1000;
    }

    digitalWrite(randomLED, HIGH);
    digitalWrite(LED_BUILTIN, HIGH);
    delay(50);
    digitalWrite(randomLED, LOW);
    digitalWrite(LED_BUILTIN, LOW);
    delay(delayTime);

    Serial.println(randomLED);
    Serial.println(delayTime);
    Serial.println();
}
