void setup(){
  Serial.begin(9600);
}
float ldr_read;
void loop() {
  ldr_read=analogRead(A0);
  Serial.println("LDR Sensor Reading");
  Serial.println(ldr_read);
}
