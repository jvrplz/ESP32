#include <WiFi.h>

void setup() {
  // put your setup code here, to run once:

}

void loop() {
// put your main code here, to run repeatedly:

  Serial.begin(230400);
  WiFi.mode(WIFI_MODE_STA);
  Serial.print("Mac Address: ");
  Serial.println(WiFi.macAddress());
  IPAddress ip = WiFi.localIP();

}
