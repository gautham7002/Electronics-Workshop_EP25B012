const int LED=3;
void setup()
{
  pinMode(LED, OUTPUT);
}
void loop()
{
  for(int i=0; i<=255; i++){
    analogWrite(LED,i);
    delay(10);
  }
  delay(500);
  for(int j=255;j>=0;j--){
    analogWrite(LED,j);
    delay(10);
  } 
  delay(500);
}