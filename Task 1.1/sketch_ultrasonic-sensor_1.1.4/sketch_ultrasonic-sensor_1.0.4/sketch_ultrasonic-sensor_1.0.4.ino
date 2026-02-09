int trig=2;
int echo=3;
void setup()
{
  Serial.begin(9600);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
}
float echo_res;
void loop()
{
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);
  echo_res=pulseIn(echo, HIGH);
  float dist=0.5*echo_res*343*0.0001;
  Serial.println("Distance measured");
  Serial.print(dist);
  Serial.println(" centimeters");
  Serial.println();
  delay(1000);
}