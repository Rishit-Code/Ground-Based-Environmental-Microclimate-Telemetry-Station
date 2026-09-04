#include <Wire.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include "DHT.h"
#include "RTClib.h"


int dhtPin = 4;         // DHT Sensor on Pin 4
int shockPin = 3;       // Shock Sensor on Pin 3
int gasPin = A0;        // Gas Sensor on Analog A0
int statusLedPin = 13;  // Onboard LED

DHT dht(dhtPin, DHT11);
Adafruit_MPU6050 mpu;
RTC_DS1307 rtc;

int packetCount = 0;

void setup() {
  
  Serial.begin(115200);

  
  pinMode(statusLedPin, OUTPUT);
  pinMode(shockPin, INPUT);
  Wire.begin();
  dht.begin();
  rtc.begin();
  mpu.begin();

  
  Serial.println("Packet,Time,Temp_C,Humidity,Gas_Raw,AccX,AccY,AccZ,Shock");
}

void loop() {
  // Increment packet number
  packetCount = packetCount + 1;

  // 1. Read Weather & Gas Sensors
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();
  int gasValue = analogRead(gasPin);
  int shockValue = digitalRead(shockPin);

  // 2. Read Accelerometer Motion Data
  sensors_event_t accel, gyro, temp;
  mpu.getEvent(&accel, &gyro, &temp);

  // 3. Read Real-Time Clock
  DateTime now = rtc.now();

  // 4. Print Data to Serial Monitor (CSV Format)
  Serial.print(packetCount);
  Serial.print(",");
  
  // Print Timestamp (HH:MM:SS)
  Serial.print(now.hour());
  Serial.print(":");
  Serial.print(now.minute());
  Serial.print(":");
  Serial.print(now.second());
  Serial.print(",");

  // Print Environmental Values
  Serial.print(temperature);
  Serial.print(",");
  Serial.print(humidity);
  Serial.print(",");
  Serial.print(gasValue);
  Serial.print(",");

  // Print Motion Values
  Serial.print(accel.acceleration.x);
  Serial.print(",");
  Serial.print(accel.acceleration.y);
  Serial.print(",");
  Serial.print(accel.acceleration.z);
  Serial.print(",");

  // Print Shock Sensor Status
  Serial.println(shockValue);

  
  digitalWrite(statusLedPin, HIGH);
  delay(100);
  digitalWrite(statusLedPin, LOW);

 
  delay(900); 
}
