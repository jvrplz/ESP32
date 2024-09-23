#include <ESP32Servo.h>

// Definimos el pin donde conectaremos el servo
int servoPin = 15; // Cambia este número si tu servo está conectado a otro pin

// Creamos un objeto de tipo Servo
Servo myServo;

// Variables de control

int pos = 0;           // Posición actual del servo

void setup() {
  // Iniciamos la comunicación serial
  Serial.begin(115200);

  // Asociamos el servo con el pin definido
  myServo.attach(servoPin);

  // Movemos el servo a la posición inicial (0 grados)
  myServo.write(pos);
  
}

void loop() {
  
  for (int pos = 0; pos <= 180; pos += 1) {
    myServo.write(pos);          // Ajusta el servo a la posición actual
    delay(15);                   // Esperamos un poco para que el servo se mueva
  }

  // Hacemos un barrido de 180 a 0 grados
  for (int pos = 180; pos >= 0; pos -= 1) {
    myServo.write(pos);          
    delay(15);                   
  }
  
}
