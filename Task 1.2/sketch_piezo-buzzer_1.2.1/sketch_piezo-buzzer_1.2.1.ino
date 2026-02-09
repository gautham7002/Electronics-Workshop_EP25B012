int piezo_pin=4;
void setup()
{
  pinMode(piezo_pin, OUTPUT);
}

void loop()
{
  
  tone(piezo_pin, 5,1000);
  delay(1000);
  
}
