#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>

Adafruit_MPU6050 mpu;

float angleX, angleY; 

void setup(void) {
  Serial.begin(9600);

  if (!mpu.begin()) {
    Serial.println("Failed to find MPU6050 chip");
    while (1) {
      delay(10);
    }
  }
  Serial.println("MPU6050 Found!");
}

void loop() {
  
  sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp);


  angleX = atan2(a.acceleration.y, a.acceleration.z) * 180 / PI;
  
  angleY = atan2(-a.acceleration.x, sqrt(a.acceleration.y * a.acceleration.y + a.acceleration.z * a.acceleration.z)) * 180 / PI;

  Serial.print("Roll (X-Angle): ");
  Serial.print(angleX);
  Serial.print("  |  ");
  Serial.print("Pitch (Y-Angle): ");
  Serial.println(angleY);

  delay(1); 
}
