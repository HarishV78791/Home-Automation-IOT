#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// WiFi credentials
char auth[] = "Your_Blynk_Auth_Token";
char ssid[] = "Your_WiFi_SSID";
char pass[] = "Your_WiFi_Password";


// Pin connected to the LED
const int ledPin = D2;

BlynkTimer timer;

void setup() {
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);
  
  pinMode(ledPin, OUTPUT);
  
  timer.setInterval(1000L, blinkLed); // Blink LED every second
}

void loop() {
  Blynk.run();
  timer.run();
}

void blinkLed() {
  static bool ledState = LOW;
  ledState = !ledState; // Toggle LED state
  digitalWrite(ledPin, ledState);
}

BLYNK_WRITE(V1) {
  int ledState = param.asInt();
  digitalWrite(ledPin, ledState);
}
