#include <Arduino.h>
const int LED1_PIN = 12;
const int LED2_PIN = 13;

// 提前声明函数原型
void toggleLED(int pin, const String &ledName);

void setup() {
  pinMode(LED1_PIN, OUTPUT);
  pinMode(LED2_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    String command = Serial.readString();
    command.trim();

    if (command == "1") {
      toggleLED(LED1_PIN, "LED1");
    } else if (command == "2") {
      toggleLED(LED2_PIN, "LED2");
    }
  }
}

// 函数定义放在主循环下方
void toggleLED(int pin, const String &ledName) {
  int currentState = digitalRead(pin);
  digitalWrite(pin, !currentState);
  Serial.print(ledName);
  Serial.println(currentState ? " OFF" : " ON");
}