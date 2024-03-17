// Include the library files
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

#define BLYNK_TEMPLATE_ID "TMPL6luzrGYle"
#define BLYNK_TEMPLATE_NAME "RoboCar"
#define BLYNK_AUTH_TOKEN "kEWWVgAJQwODWRuq-bUq3Zyo5LVoB7F6"

// Define the motor pins
#define ENA D0
#define IN1 D1
#define IN2 D2
#define IN3 D3
#define IN4 D4
#define ENB D7

// Variables for motor speed and direction
int speed = 0;
bool forward = false;
bool backward = false;
bool left = false;
bool right = false;

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "Chacha302";  // Enter your WIFI name
char pass[] = "khanafaaq";    // Enter your WIFI password

void setup() {
  Serial.begin(9600);

  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENB, OUTPUT);

  Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);
}

void loop() {
  Blynk.run();
}

BLYNK_WRITE(V0) {
  int buttonState = param.asInt();
  if (buttonState == 1) {
    forward = true;
    backward = false;
    left = false;
    right = false;
    carForward(speed);
  } else {
    forward = false;
    carStop();
  }
}

BLYNK_WRITE(V1) {
  int buttonState = param.asInt();
  if (buttonState == 1) {
    backward = true;
    forward = false;
    left = false;
    right = false;
    carBackward(speed);
  } else {
    backward = false;
    carStop();
  }
}

BLYNK_WRITE(V2) {
  int buttonState = param.asInt();
  if (buttonState == 1) {
    left = true;
    forward = false;
    backward = false;
    right = false;
    carLeft(speed / 2);
  } else {
    left = false;
    carStop();
  }
}

BLYNK_WRITE(V3) {
  int buttonState = param.asInt();
  if (buttonState == 1) {
    right = true;
    forward = false;
    backward = false;
    left = false;
    carRight(speed / 2);
  } else {
    right = false;
    carStop();
  }
}

BLYNK_WRITE(V4) {
  speed = param.asInt();
  if (forward) {
    carForward(speed);
  } else if (backward) {
    carBackward(speed);
  } else if (left) {
    carLeft(speed / 2);
  } else if (right) {
    carRight(speed / 2);
  }
}

/**************Motor movement functions*****************/
void carForward(int speed) {
  analogWrite(ENA, speed);
  analogWrite(ENB, speed);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void carBackward(int speed) {
  analogWrite(ENA, speed);
  analogWrite(ENB, speed);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void carLeft(int speed) {
  analogWrite(ENA, speed);
  analogWrite(ENB, speed);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void carRight(int speed) {
  analogWrite(ENA, speed);
  analogWrite(ENB, speed);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void carStop() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}