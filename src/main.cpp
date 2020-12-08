#include <Arduino.h>
#include <Wire.h>
#define LED_PIN PC13

byte x = 0;
#define I2C_ADDR 8

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(115200);

  Wire.begin();

}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("Hello world");
  digitalWrite(LED_PIN, HIGH);
  delay(500);
  digitalWrite(LED_PIN, LOW);
  delay(500);

  Wire.beginTransmission(I2C_ADDR); // transmit to device
  //Wire.write("x is ");              // sends five bytes
  Wire.write(x);                    // sends one byte
  Wire.endTransmission();           // stop transmitting
  x++;
}