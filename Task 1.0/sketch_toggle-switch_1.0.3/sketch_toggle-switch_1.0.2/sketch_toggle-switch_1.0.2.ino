const int LED=3;
const int push_button =2;
void setup()
{
  pinMode(LED, OUTPUT);
  pinMode(push_button,INPUT_PULLUP);
}
int prev=1;
int glow=0;
int pb_read;
void loop()
{
  pb_read=digitalRead(push_button);
  
  if(pb_read==0 and prev==1 and glow==0){
    glow=1;
  }
  if(pb_read==0 and prev==0 and glow==1){
    glow=0;
  }
  if(pb_read){
    if(glow){
      prev=0;
    }
    if(not glow){
      prev=1;
    }
    digitalWrite(LED,glow);
  }
  

  
}