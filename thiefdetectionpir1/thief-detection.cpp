// Memanggil library SoftwareSerial yang digunakan oleh
// modul SIM800L untuk mengirim dan menerima pesan SMS.
#include <SoftwareSerial.h>

// Mendefinisikan SIM800L dengan pin RX = 10, TX = 11.
SoftwareSerial SIM800L(10, 11);

// Mendefinisikan pin LED, buzzer, dan sensor PIR.
int ledPIN = 3;
int buzzerPIN = 4;
int pirSensorPIN = 2;

// Mendefinisikan variabel untuk mendeteksi status sensor PIR.
int motionDetected = LOW;

void setup()
{
    // Mendefinisikan pin LED, buzzer, dan sensor PIR
    // sebagai output.
    pinMode(ledPIN, OUTPUT);
    pinMode(PIRsensorPIN, INPUT);
    pinMode(buzzerPIN, OUTPUT);

    Serial.begin(9600);

    // Memulai koneksi ke SIM800L.
    SIM800L.begin(9600);
    SIM800L.println("AT+CMGF=1");
    Serial.println("SIM800L started at 9600");
    delay(1000);
    Serial.println("Setup Complete! SIM800L is Ready!");
    SIM800L.println("AT+CNMI=2,2,0,0,0");

    SIM800L.println("AT+CMGF=1");
    delay(1000);
    // Mengatur nomor ponsel yang akan dikirimkan SMS.
    SIM800L.println("AT+CMGS=\"081287931296\"\r");
    delay(5000);
}

void loop()
{
    // Mendefinisikan motionDetected sebagai hasil bacaan
    // sensor PIR.
    motionDetected = digitalRead(PIRsensorPIN);

    // Jika sensor PIR menemukan pergerakan, maka
    if (motionDetected == HIGH)
    {
        // Menyalakan LED.
        digitalWrite(ledPIN, HIGH);
        // Menyalakan buzzer.
        analogWrite(buzzerPIN, 200);
        // Mengirimkan SMS ke nomor ponsel yang telah didefinisikan.
        SIM800L.println("Ada pergerakan di ruangan!");
        delay(100);
        SIM800L.println((char)26);
        analogWrite(ledPIN, LOW);
        analogWrite(buzzerPIN, 50);
        delay(900);
    }
    // Jika sensor PIR tidak menemukan gerakan, maka
    else
    {
        // led mati, dan buzzer mati.
        digitalWrite(ledPIN, LOW);
        analogWrite(buzzerPIN, LOW);
    }
}