#include <ESP32Servo.h>

Servo servo1, servo2, servo3;

int lastPos1 = 0; 
int lastPos2 = 0; 
int lastPos3 = 0;
int targetPos1 = 0; 
int targetPos2 = 0; 
int targetPos3 = 0;

void setup() {
  Serial.begin(115200);
  servo1.attach(21);
  servo2.attach(22);
  servo3.attach(19);

  servo1.write(lastPos1);
  servo2.write(lastPos2);
  servo3.write(lastPos3);
}

void loop() {
  if (Serial.available() > 0) {
    String input = Serial.readStringUntil('\n'); 
    input.trim(); 

    int spaceIndex = input.indexOf(' ');
    if (spaceIndex != -1) {
      String pos1Str = input.substring(0, spaceIndex);
      String pos2Str = input.substring(spaceIndex + 1, input.lastIndexOf(' '));
      String pos3Str = input.substring(input.lastIndexOf(' ') + 1);

      int pos1 = pos1Str.toInt();
      int pos2 = pos2Str.toInt();
      int pos3 = pos3Str.toInt();

      if (pos1 >= 0 && pos1 <= 180 && pos2 >= 0 && pos2 <= 180 && pos3 >= 0 && pos3 <= 180) {
        targetPos1 = pos1; 
        targetPos2 = pos2; 
        targetPos3 = pos3; // Update target position for servo3
      } else {
        Serial.println("Invalid input. Please enter values between 0 and 180.");
      }
    } else {
      Serial.println("Invalid format. Please input three values separated by spaces.");
    }
  }

  if (lastPos1 < targetPos1) {
    lastPos1++;
  } else if (lastPos1 > targetPos1) {
    lastPos1--;
  }
  servo1.write(lastPos1);

  if (lastPos2 < targetPos2) {
    lastPos2++;
  } else if (lastPos2 > targetPos2) {
    lastPos2--;
  }
  servo2.write(lastPos2);

  if (lastPos3 < targetPos3) {
    lastPos3++;
  } else if (lastPos3 > targetPos3) {
    lastPos3--;
  }
  servo3.write(lastPos3);

  delay(15);
}