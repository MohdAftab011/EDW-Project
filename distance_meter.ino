#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); // Address, columns, rows
#define echoPin 9
#define trigPin 10

long duration, distance;

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  lcd.init();
  lcd.backlight();
}

void loop() {
  delay(200);
  // Triggering the ultrasonic sensor
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Reading the duration of the echo pulse
  duration = pulseIn(echoPin, HIGH);

  // Calculating distance in centimeters
  distance = duration * 0.034 / 2; // Speed of sound in air = 0.034 cm/μs

  // Displaying distance on the LCD
  lcd.clear();
  lcd.print("Distance:");
  lcd.setCursor(0, 1);
  lcd.print(distance);
  lcd.print(" cm");
}


