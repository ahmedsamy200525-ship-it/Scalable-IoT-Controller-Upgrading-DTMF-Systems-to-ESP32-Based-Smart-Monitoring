#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include "BluetoothSerial.h"

LiquidCrystal_I2C lcd(0x27, 16, 2);
BluetoothSerial ESP_BT;

const int relay1 = 16; 
const int relay2 = 17;
const int btn1 = 14;   
const int btn2 = 27;   
const int buzzer = 26; 

String status1 = "OFF";
String status2 = "OFF";

void beep(int duration, int repeats) {
  for (int i = 0; i < repeats; i++) {
    digitalWrite(buzzer, HIGH);
    delay(duration);
    digitalWrite(buzzer, LOW);
    if (repeats > 1) delay(50); 
  }
}

void updateDisplay() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("LED 1: " + status1);
  lcd.setCursor(0, 1);
  lcd.print("LED 2: " + status2);

  ESP_BT.println("-----------------------");
  ESP_BT.print("System Status -> ");
  ESP_BT.print("L1:" + status1);
  ESP_BT.println(" | L2:" + status2);
  ESP_BT.println("-----------------------");
}

void setup() {
  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(btn1, INPUT_PULLUP);
  pinMode(btn2, INPUT_PULLUP);

  digitalWrite(relay1, HIGH); 
  digitalWrite(relay2, HIGH);
  digitalWrite(buzzer, LOW);

  lcd.init();
  lcd.backlight();
  ESP_BT.begin("Ahmed_Smart_Home"); 
  
  beep(150, 2); 
  updateDisplay();
}

void loop() {
  if (digitalRead(btn1) == LOW) {
    if (status1 == "OFF") {
      digitalWrite(relay1, LOW); 
      status1 = "ON ";
      beep(100, 1);
    } else {
      digitalWrite(relay1, HIGH); 
      status1 = "OFF";
      beep(300, 1);
    }
    updateDisplay();
    delay(300); // 
  }

  if (digitalRead(btn2) == LOW) {
    if (status2 == "OFF") {
      digitalWrite(relay2, LOW); 
      status2 = "ON ";
      beep(100, 1);
    } else {
      digitalWrite(relay2, HIGH); 
      status2 = "OFF";
      beep(300, 1);
    }
    updateDisplay();
    delay(300);
  }

  if (ESP_BT.available()) {
    char cmd = ESP_BT.read();
    
    if (cmd == '8') { 
      digitalWrite(relay1, LOW); digitalWrite(relay2, LOW); 
      status1="ON "; status2="ON "; beep(200, 3); 
    }
    else if (cmd == '0') { 
      digitalWrite(relay1, HIGH); digitalWrite(relay2, HIGH); 
      status1="OFF"; status2="OFF"; beep(800, 1); 
    }
    else if (cmd == '1') { 
      digitalWrite(relay1, LOW); status1="ON "; beep(100, 1); 
    }
    else if (cmd == '4') { 
      digitalWrite(relay1, HIGH); status1="OFF"; beep(400, 1); 
    }
    else if (cmd == '2') { 
      digitalWrite(relay2, LOW); status2="ON "; beep(100, 1); 
    }
    else if (cmd == '5') { 
      digitalWrite(relay2, HIGH); status2="OFF"; beep(400, 1); 
    }
    
    updateDisplay();
  }
}