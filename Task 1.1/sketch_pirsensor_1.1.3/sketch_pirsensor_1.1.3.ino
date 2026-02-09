int LED=2;
int pir=3;
void setup()
{
  pinMode(pir,INPUT);
  pinMode(LED,OUTPUT);
}
void loop()
{
  int pir_read=digitalRead(pir);
  digitalWrite(LED,pir_read);
 
}