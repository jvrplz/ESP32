
byte incomingByte = 0;

void setup() {
  Serial.begin(115200);
}

void loop() {
  if (Serial.available() > 0 )
  {
    // read the incoming Byte
    incomingByte = Serial.read();
    Serial.print("Value: ");
    Serial.println(incomingByte, DEC);
  }
}