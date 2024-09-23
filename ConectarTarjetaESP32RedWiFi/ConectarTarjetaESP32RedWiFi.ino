/*
  Asignatura: Sistemas Informáticos en IoT
  Práctica 2 - Conectar tarjeta ESP32 a una red WiFi con usuario y contraseña
  Funcionamiento: conexión básica a una red WiFi utilizando un usuario y una contraseña
  David Martín Gómez
  dmgomez@ing.uc3m.es
*/

#include <WiFi.h>

const char* ssid = "UC3M-IoT";
const char* password =  "xxxxxxxxxxxxxxxx";

void setup()
{
  int i = 0;
  Serial.begin(230400);
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("Connecting to WiFi..");
  }
  Serial.println("Connected to the WiFi network");
}

void loop()

{
	
}
