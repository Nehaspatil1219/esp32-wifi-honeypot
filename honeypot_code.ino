#include <WiFi.h>

// Fake WiFi name and password
const char* ssid = "Free_Public_WiFi";   // You might have used this or a similar name
const char* password = "12345678";       // Or maybe left blank ""

void setup() {
  Serial.begin(115200);

  // Start fake WiFi Access Point
  WiFi.softAP(ssid, password);

  Serial.println("🚨 ESP32 Wi-Fi Honeypot Started 🚨");
  Serial.print("SSID: ");
  Serial.println(ssid);
  Serial.print("IP Address: ");
  Serial.println(WiFi.softAPIP());
}

void loop() {
  // Check number of devices connected
  int clients = WiFi.softAPgetStationNum();

  Serial.print("Connected devices: ");
  Serial.println(clients);

  delay(3000); // update every 3 seconds
}
