void setup() {
  Serial.begin(9600);
}
int ir_read;
void loop() {
  ir_read=analogRead(A0);
  Serial.println("IR Sensor Reading:");
  Serial.println(ir_read);
}
