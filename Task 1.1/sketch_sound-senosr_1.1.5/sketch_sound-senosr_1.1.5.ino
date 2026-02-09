//using digital pin only
int sound_detect=A0;
int led=2;
int low=50;
void setup() {
  pinMode(sound_detect, INPUT);
  pinMode(led,OUTPUT);

}

int read_ss;
void loop() {
  read_ss=analogRead(sound_detect);
  if (read_ss > low){
    digitalWrite(led, HIGH);
    delay(2000);
    digitalWrite(led,LOW);
  }
}
