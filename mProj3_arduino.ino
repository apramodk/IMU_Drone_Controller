#include <Arduino_LSM6DS3.h>

float x, y, z;
int forward = 0;
int backward = 0;
int left_movement = 0;
int right_movement = 0;
int frontLeft = 2;
int frontRight = 21;
int backLeft = 8;
int backRight = 14;

void setup() {
  Serial.begin(115200);
  while (!Serial);
  Serial.println("Started");

  if (!IMU.begin()) {
    Serial.println("Failed to initialize IMU!");
    while (1);
  }

  Serial.print("Accelerometer sample rate = ");
  Serial.print(IMU.accelerationSampleRate());
  Serial.println("Hz");
  pinMode(frontLeft, OUTPUT);
  pinMode(frontRight, OUTPUT);
  pinMode(backLeft, OUTPUT);
  pinMode(backRight, OUTPUT);
}


void loop() {
  if (IMU.accelerationAvailable()) {
    IMU.readAcceleration(x, y, z);
    
    if (x > 0.1) {
      x = 100 * x;
      backward = map(x, 0, 97, 0, 4);
      Serial.print("Moving forward at speed setting ");
      Serial.println(backward);
      digitalWrite(frontLeft, LOW);
      digitalWrite(frontRight, LOW);
      digitalWrite(backLeft, HIGH);
      digitalWrite(backRight, HIGH);


    }
    if (x < -0.1) {
      x = 100 * x;
      forward = map(x, 0, -100, 0, 4);
      Serial.print("Moving backward at speed setting ");
      Serial.println(forward);
      digitalWrite(frontLeft, HIGH);
      digitalWrite(frontRight, HIGH);
      digitalWrite(backLeft, LOW);
      digitalWrite(backRight, LOW);
    }
    if (y > 0.1) {
      y = 100 * y;
      left_movement = map(y, 0, 97, 0, 4);
      Serial.print("Moving left at speed setting ");
      Serial.println(left_movement);
      digitalWrite(frontLeft, LOW);
      digitalWrite(frontRight, HIGH);
      digitalWrite(backLeft, LOW);
      digitalWrite(backRight, HIGH);
    }
    if (y < -0.1) {
      y = 100 * y;
      right_movement = map(y, 0, -100, 0, 4);
      Serial.print("Moving right at speed setting ");
      Serial.println(right_movement);
      digitalWrite(frontLeft, HIGH);
      digitalWrite(frontRight, LOW);
      digitalWrite(backLeft, HIGH);
      digitalWrite(backRight, LOW);
    }
  }

  delay(2000);
}
