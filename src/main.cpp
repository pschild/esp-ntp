#include <NTPClient.h>
#include <ESP8266WiFi.h>
#include <WiFiUdp.h>

#ifndef WIFI_SSID
  #error "Missing WIFI_SSID"
#endif

#ifdef WIFI_SSID
  #error STRING(WIFI_SSID)
#endif

#ifndef WIFI_PASSWORD
  #error "Missing WIFI_PASSWORD"
#endif

WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP);

void setup() {
  Serial.begin(9600);

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  timeClient.begin();
}

void loop() {
  timeClient.update();
  Serial.println(timeClient.getFormattedTime());
  delay(1000);
}
