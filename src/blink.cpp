/*
 Adapted from: ESP8266 Blink by Simon Peter
*/

#include <ESP8266WiFi.h>

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  digitalWrite(LED_BUILTIN, LOW);   // Turn the LED on
  delay(100);
  digitalWrite(LED_BUILTIN, HIGH);  // Turn the LED off
  delay(900);
}