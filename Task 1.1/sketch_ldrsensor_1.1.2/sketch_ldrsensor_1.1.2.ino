void setup(){
  Serial.begin(9600);
  pinMode(13,OUTPUT);
}
float ldr_read;
void loop() {
  ldr_read=analogRead(A0);
  Serial.println("LDR Sensor Reading");
  Serial.println(ldr_read);
  digitalWrite(13,HIGH);
  delay(1000);
  digitalWrite(13,LOW);
  delay(1000);
}
