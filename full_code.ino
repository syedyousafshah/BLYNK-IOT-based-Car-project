#define BLYNK_PRINT Serial
#include<ESP8266WiFi.h>
#include<BlynkSimpleEsp8266.h>

#define BLYNK_AUTH_TOKEN "UbGwb7V5ba6gaFSHA3UNsRmYvYUNATUp"

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "Linkup1";         //Wifi name
char pass[] = "hostel@321@home";   //Password

BLYNK_WRITE(V0){
  digitalWrite(D0, LOW);
  digitalWrite(D1, HIGH);
  digitalWrite(D2, HIGH);
  digitalWrite(D3, LOW);
}

BLYNK_WRITE(V1){
  digitalWrite(D0, LOW);
  digitalWrite(D1, HIGH);
  digitalWrite(D2, LOW);
  digitalWrite(D3, LOW);
}

BLYNK_WRITE(V2){
  digitalWrite(D0, LOW);
  digitalWrite(D1, LOW);
  digitalWrite(D2, HIGH);
  digitalWrite(D3, LOW);
}

BLYNK_WRITE(V3){
  digitalWrite(D0, HIGH);
  digitalWrite(D1, LOW);
  digitalWrite(D2, LOW);
  digitalWrite(D3, HIGH);
}

BLYNK_WRITE(V4){
  digitalWrite(D0, LOW);
  digitalWrite(D1, LOW);
  digitalWrite(D2, LOW);
  digitalWrite(D3, LOW);
}

void setup() {
  // put your setup code here, to run once:

pinMode(D1, OUTPUT);
pinMode(D2, OUTPUT);
pinMode(D0, OUTPUT);
pinMode(D3, OUTPUT);
Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);
}

void loop() {
Blynk.run();
}