int flame_sensor=A0;
void setup() {
  Serial.begin(9600);
}
int read_fs;
void loop() {
  read_fs=analogRead(flame_sensor);
  Serial.println("Flame sensor readings:");
  Serial.println(read_fs);
}
