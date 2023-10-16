#include "SoftwareSerial.h"
SoftwareSerial Bluetooth (9, 8); //RX TX
int val;
boolean state = 1;
void stop() {
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(16, LOW);
  digitalWrite(17, LOW);
  digitalWrite(14, LOW);
  digitalWrite(15, LOW);
}
void forward() {
  digitalWrite(2, LOW);
  digitalWrite(3, HIGH);
  digitalWrite(4, LOW);
  digitalWrite(5, HIGH);
  digitalWrite(16, HIGH);
  digitalWrite(17, LOW);
  digitalWrite(14, HIGH);
  digitalWrite(15, LOW);
}
void back() {
  digitalWrite(2, HIGH);
  digitalWrite(3, LOW);
  digitalWrite(4, HIGH);
  digitalWrite(5, LOW);
  digitalWrite(16, LOW);
  digitalWrite(17, HIGH);
  digitalWrite(14, LOW);
  digitalWrite(15, HIGH);
}
void right() {
  digitalWrite(2, HIGH);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, HIGH);
  digitalWrite(16, LOW);
  digitalWrite(17, HIGH);
  digitalWrite(14, HIGH);
  digitalWrite(15, LOW);
}
void left() {
  digitalWrite(2, LOW);
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(5, LOW);
  digitalWrite(16, HIGH);
  digitalWrite(17, LOW);
  digitalWrite(14, LOW);
  digitalWrite(15, HIGH);
}
void superright () {
  digitalWrite(2, LOW);
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(5, LOW);
  digitalWrite(16, LOW);
  digitalWrite(17, HIGH);
  digitalWrite(14, HIGH);
  digitalWrite(15, LOW);
}
void superleft () {
  digitalWrite(2, HIGH);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, HIGH);
  digitalWrite(16, HIGH);
  digitalWrite(17, LOW);
  digitalWrite(14, LOW);
  digitalWrite(15, HIGH);
}
void forwardright () {
  digitalWrite(2, LOW);
  digitalWrite(3, HIGH);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(16, LOW);
  digitalWrite(17, LOW);
  digitalWrite(14, HIGH);
  digitalWrite(15, LOW);
}
void forwardleft () {
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, HIGH);
  digitalWrite(16, HIGH);
  digitalWrite(17, LOW);
  digitalWrite(14, LOW);
  digitalWrite(15, LOW);
}
void backright () {
  digitalWrite(2, HIGH);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(16, LOW);
  digitalWrite(17, LOW);
  digitalWrite(14, LOW);
  digitalWrite(15, HIGH);
}
void backleft () {
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, HIGH);
  digitalWrite(5, LOW);
  digitalWrite(16, LOW);
  digitalWrite(17, HIGH);
  digitalWrite(14, LOW);
  digitalWrite(15, LOW);
}
void setup() {
  Serial.begin (9600);
  Bluetooth.begin(9600);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);

  pinMode(14, OUTPUT);
  pinMode(15, OUTPUT);
  pinMode(16, OUTPUT);
  pinMode(17, OUTPUT);
}
void loop() {
  if (Bluetooth.available()) {
    val = Bluetooth.read();
    if (val == 'W') {
      state = 1;
    } else if (val == 'w') {
      state = 0;
    }
    if (val == 'B') {
      back();
    } else if (val == 'F') {
      forward();
    } else if (val == 'R' && state == 1) {
      superright ();
    } else if (val == 'L' && state == 1) {
      superleft ();
    } else if (val == 'R' && state == 0) {
      right ();
    } else if (val == 'L' && state == 0) {
      left ();
    } else if (val == 'G') {
      forwardleft ();
    } else if (val == 'I') {
      forwardright ();
    } else if (val == 'H') {
      backright ();
    } else if (val == 'J') {
      backleft ();
    }  else {
      stop();
    }
  }
}
